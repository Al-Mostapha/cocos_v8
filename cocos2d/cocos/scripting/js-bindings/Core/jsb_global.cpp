/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "jsb_global.hpp"
#include "JsbConfig.h"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "base/CCData.h"
#include <sstream>
// #include "jsb_conversions.hpp"
#include "xxtea/xxtea.h"

#include "base/CCScheduler.h"
#include "base/CCThreadPool.h"
#include "network/HttpClient.h"
#include "platform/CCApplication.h"
#include "network/CCDownloader.h"
#include <map>
#include "UIEditBox/UIEditBox.h"

// #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
// #include "platform/android/jni/JniImp.h"
// #endif
// #if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY && (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8 || SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_JSVM)
// // #include "platform/openharmony/napi/NapiHelper.h"
// #endif
#include "CCFileUtils.h"
#include "ZipUtils.h"
#include <regex>
#include "HelperMacros.h"
#include "jsb_conversions.hpp"
#include "platform/CCGL.h"
#include "platform/CCImage.h"
#include "platform/CCApplication.h"

using namespace cocos2d;

v8::Object *__jsbObj = nullptr;
v8::Object *__glObj = nullptr;

static std::shared_ptr<ThreadPool> g_threadPool;

static std::shared_ptr<cocos2d::network::Downloader> g_localDownloader = nullptr;
static std::map<std::string, std::function<void(const std::string &, unsigned char *, int, const std::string &)>> g_localDownloaderHandlers;
static uint64_t g_localDownloaderTaskId = 1000000;
static std::string xxteaKey = "";
void jsb_set_xxtea_key(const std::string &key)
{
    xxteaKey = key;
}

static cocos2d::network::Downloader *localDownloader()
{
    if (!g_localDownloader)
    {
        g_localDownloader = std::make_shared<cocos2d::network::Downloader>();
        g_localDownloader->onDataTaskSuccess = [=](const cocos2d::network::DownloadTask &task,
                                                   std::vector<unsigned char> &data)
        {
            if (data.empty())
            {
                SE_REPORT_ERROR("Getting image from (%s) failed!", task.requestURL.c_str());
                return;
            }

            auto callback = g_localDownloaderHandlers.find(task.identifier);
            if (callback == g_localDownloaderHandlers.end())
            {
                SE_REPORT_ERROR("Getting image from (%s), callback not found!!", task.requestURL.c_str());
                return;
            }
            size_t imageBytes = data.size();
            unsigned char *imageData = (unsigned char *)malloc(imageBytes);
            memcpy(imageData, data.data(), imageBytes);

            (callback->second)("", imageData, imageBytes, "");
            // initImageFunc("", imageData, imageBytes);
            g_localDownloaderHandlers.erase(callback);
        };
        g_localDownloader->onTaskError = [=](const cocos2d::network::DownloadTask &task,
                                             int errorCode,
                                             int errorCodeInternal,
                                             const std::string &errorStr)
        {
            SE_REPORT_ERROR("Getting image from (%s) failed!", task.requestURL.c_str());
            auto callback = g_localDownloaderHandlers.find(task.identifier);
            if (callback == g_localDownloaderHandlers.end())
            {
                SE_REPORT_ERROR("Getting image from (%s), callback not found!!", task.requestURL.c_str());
                return;
            }

            (callback->second)("", nullptr, 0, errorStr);
            g_localDownloaderHandlers.erase(task.identifier);
        };
    }
    return g_localDownloader.get();
}

static void localDownloaderCreateTask(const std::string &url, std::function<void(const std::string &, unsigned char *, int, const std::string &)> callback)
{
    std::stringstream ss;
    ss << "jsb_loadimage_" << (g_localDownloaderTaskId++);
    std::string key = ss.str();
    auto task = localDownloader()->createDownloadDataTask(url, key);
    g_localDownloaderHandlers.emplace(std::make_pair(task->identifier, callback));
}

static const char *BYTE_CODE_FILE_EXT = ".jsc";

static std::string removeFileExt(const std::string &filePath)
{
    size_t pos = filePath.rfind('.');
    if (0 < pos)
    {
        return filePath.substr(0, pos);
    }
    return filePath;
}

void jsb_init_file_operation_delegate()
{
    static ScriptEngine::FileOperationDelegate delegate;
    if (!delegate.isValid())
    {
        delegate.onGetDataFromFile = [](const std::string &path, const std::function<void(const uint8_t *, size_t)> &readCallback) -> void
        {
            assert(!path.empty());

            cocos2d::Data fileData;

            std::string byteCodePath = removeFileExt(path) + BYTE_CODE_FILE_EXT;
            if (cocos2d::FileUtils::getInstance()->isFileExist(byteCodePath))
            {
                fileData = cocos2d::FileUtils::getInstance()->getDataFromFile(byteCodePath);

                size_t dataLen = 0;
                uint8_t *data = xxtea_decrypt((unsigned char *)fileData.getBytes(), (uint32_t)fileData.getSize(), (unsigned char *)xxteaKey.c_str(), (uint32_t)xxteaKey.size(), (uint32_t *)&dataLen);

                if (data == nullptr)
                {
                    SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                    return;
                }

                if (ZipUtils::isGZipBuffer(data, dataLen))
                {
                    uint8_t *unpackedData;
                    ssize_t unpackedLen = ZipUtils::inflateMemory(data, dataLen, &unpackedData);

                    if (unpackedData == nullptr)
                    {
                        SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                        return;
                    }

                    readCallback(unpackedData, unpackedLen);
                    free(data);
                    free(unpackedData);
                }
                else
                {
                    readCallback(data, dataLen);
                    free(data);
                }

                return;
            }

            fileData = FileUtils::getInstance()->getDataFromFile(path);
            readCallback(fileData.getBytes(), fileData.getSize());
        };

        delegate.onGetStringFromFile = [](const std::string &path) -> std::string
        {
            assert(!path.empty());

            std::string byteCodePath = removeFileExt(path) + BYTE_CODE_FILE_EXT;
            if (FileUtils::getInstance()->isFileExist(byteCodePath))
            {
                Data fileData = FileUtils::getInstance()->getDataFromFile(byteCodePath);

                uint32_t dataLen;
                uint8_t *data = xxtea_decrypt((uint8_t *)fileData.getBytes(), (uint32_t)fileData.getSize(), (uint8_t *)xxteaKey.c_str(), (uint32_t)xxteaKey.size(), &dataLen);

                if (data == nullptr)
                {
                    SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                    return "";
                }

                if (ZipUtils::isGZipBuffer(data, dataLen))
                {
                    uint8_t *unpackedData;
                    ssize_t unpackedLen = ZipUtils::inflateMemory(data, dataLen, &unpackedData);
                    if (unpackedData == nullptr)
                    {
                        SE_REPORT_ERROR("Can't decrypt code for %s", byteCodePath.c_str());
                        return "";
                    }

                    std::string ret(reinterpret_cast<const char *>(unpackedData), unpackedLen);
                    free(unpackedData);
                    free(data);

                    return ret;
                }
                else
                {
                    std::string ret(reinterpret_cast<const char *>(data), dataLen);
                    free(data);
                    return ret;
                }
            }

            if (FileUtils::getInstance()->isFileExist(path))
            {
                return FileUtils::getInstance()->getStringFromFile(path);
            }
            else
            {
                SE_LOGE("ScriptEngine::onGetStringFromFile %s not found, possible missing file.\n", path.c_str());
            }
            return "";
        };

        delegate.onGetFullPath = [](const std::string &path) -> std::string
        {
            assert(!path.empty());
            std::string byteCodePath = removeFileExt(path) + BYTE_CODE_FILE_EXT;
            if (FileUtils::getInstance()->isFileExist(byteCodePath))
            {
                return FileUtils::getInstance()->fullPathForFilename(byteCodePath);
            }
            return FileUtils::getInstance()->fullPathForFilename(path);
        };

        delegate.onCheckFileExist = [](const std::string &path) -> bool
        {
            assert(!path.empty());
            return FileUtils::getInstance()->isFileExist(path);
        };

        assert(delegate.isValid());
    }

    ScriptEngine::getInstance()->setFileOperationDelegate(delegate);
}

bool jsb_enable_debugger(const std::string &debuggerServerAddr, uint32_t port, bool isWaitForConnect)
{
    if (debuggerServerAddr.empty() || port == 0)
        return false;

    auto se = ScriptEngine::getInstance();
    se->enableDebugger(debuggerServerAddr.c_str(), port, isWaitForConnect);

    // For debugger main loop
    class SimpleRunLoop
    {
    public:
        void update(float dt)
        {
            ScriptEngine::getInstance()->mainLoopUpdate();
        }
    };
    //    static SimpleRunLoop runLoop;
    // cjh IDEA:    Director::getInstance()->getScheduler()->scheduleUpdate(&runLoop, 0, false);
    return true;
}

bool jsb_set_extend_property(const char *ns, const char *clsName)
{
    v8::Isolate *isolate = ScriptEngine::getInstance()->getIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Object> globalObj = ScriptEngine::getInstance()->getGlobalObject();
    v8::Local<v8::String> nsKey = JsbUtils::ToV8String(isolate, ns);

    // v8::Value nsVal;
    v8::Local<v8::Value> nsVal;

    // if (globalObj->getProperty(ns, &nsVal) && nsVal.isObject())
    // {
    if (globalObj->Get(context, nsKey).ToLocal(&nsVal) && nsVal->IsObject())
    {
        //     se::Value ccVal;
        v8::Local<v8::Value> ccVal;
        //     if (globalObj->getProperty("cc", &ccVal) && ccVal.isObject())
        //     {
        if (globalObj->Get(context, JsbUtils::ToV8String(isolate, "cc")).ToLocal(&ccVal) && ccVal->IsObject())
        {

            //         se::Value ccClassVal;
            v8::Local<v8::Value> ccClassVal;
            //         if (ccVal.toObject()->getProperty("Class", &ccClassVal) && ccClassVal.isObject())
            //         {
            if (ccVal->ToObject(context).ToLocalChecked()->Get(context, JsbUtils::ToV8String(isolate, "Class")).ToLocal(&ccClassVal) && ccClassVal->IsObject())
            {
                //             se::Value extendVal;
                v8::Local<v8::Value> extendVal;
                //             if (ccClassVal.toObject()->getProperty("extend", &extendVal) && extendVal.isObject() && extendVal.toObject()->isFunction())
                //             {
                if (ccClassVal->ToObject(context).ToLocalChecked()->Get(context, JsbUtils::ToV8String(isolate, "extend")).ToLocal(&extendVal) && extendVal->IsObject() && extendVal->ToObject(context).ToLocalChecked()->IsFunction())
                {
                    //                 se::Value targetClsVal;
                    v8::Local<v8::Value> targetClsVal;
                    //                 if (nsVal.toObject()->getProperty(clsName, &targetClsVal) && targetClsVal.isObject())
                    //                 {
                    if (nsVal->ToObject(context).ToLocalChecked()->Get(context, JsbUtils::ToV8String(isolate, clsName)).ToLocal(&targetClsVal) && targetClsVal->IsObject())
                    {

                        //                     return targetClsVal.toObject()->setProperty("extend", extendVal);
                        return targetClsVal->ToObject(context).ToLocalChecked()->Set(context, JsbUtils::ToV8String(isolate, "extend"), extendVal).FromJust();
                    }
                    //                 }
                    //             }
                    //         }
                    //     }
                }
            }
        }
    }

    // }
    // return false;
    return false;
}

namespace
{

    std::unordered_map<std::string, v8::Global<v8::Value>> __moduleCache;

    static void require(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
    {
        ++__jsbInvocationCount;
        bool ret = false;
        v8::Isolate *_isolate = _v8args.GetIsolate();
        v8::HandleScope _hs(_isolate);
        SE_UNUSED unsigned argc = (unsigned)_v8args.Length();
        // se::ValueArray args;
        // args.reserve(10);
        // se::internal::jsToSeArgs(_v8args, &args);
        void *nativeThisObject = JsbUtils::GetPrivate(_isolate, _v8args.This());
        // se::State state(nativeThisObject, args);
        // ret = funcName(state); \
        // const auto &args = s.args();
        // int argc = (int)args.size();

        // assert(argc >= 1);
        assert(argc >= 1 && _v8args[0]->IsString());
        // assert(args[0].isString());
        assert(_v8args[0]->IsString());
        // return jsb_run_script(args[0].toString(), &s.GetReturnValue());
        bool ret = jsb_run_script(JsbUtils::FromV8String(_isolate, _v8args[0]), &_v8args.GetReturnValue());
        if (!ret)
        {
            SE_LOGE("[ERROR] Failed to invoke %s, location: %s:%d\n", #funcName, __FILE__, __LINE__);
        }
        // se::internal::setReturnValue(state.rval(), _v8args);
        // return ret;
    }
    // SE_BIND_FUNC(require)

    static bool doModuleRequire(const std::string &path, v8::Local<v8::Value> *ret, const std::string &prevScriptFileDir)
    {
        v8::Isolate *isolate = ScriptEngine::getInstance()->getIsolate();
        v8::EscapableHandleScope handleScope(isolate);
        assert(!path.empty());

        const auto &fileOperationDelegate = ScriptEngine::getInstance()->getFileOperationDelegate();
        assert(fileOperationDelegate.isValid());

        std::string fullPath;

        std::string pathWithSuffix = path;
        if (pathWithSuffix.rfind(".js") != (pathWithSuffix.length() - 3))
            pathWithSuffix += ".js";
        std::string scriptBuffer = fileOperationDelegate.onGetStringFromFile(pathWithSuffix);

        if (scriptBuffer.empty() && !prevScriptFileDir.empty())
        {
            std::string secondPath = prevScriptFileDir;
            if (secondPath[secondPath.length() - 1] != '/')
                secondPath += "/";

            secondPath += path;

            if (FileUtils::getInstance()->isDirectoryExist(secondPath))
            {
                if (secondPath[secondPath.length() - 1] != '/')
                    secondPath += "/";
                secondPath += "index.js";
            }
            else
            {
                if (path.rfind(".js") != (path.length() - 3))
                    secondPath += ".js";
            }

            fullPath = fileOperationDelegate.onGetFullPath(secondPath);
            scriptBuffer = fileOperationDelegate.onGetStringFromFile(fullPath);
        }
        else
        {
            fullPath = fileOperationDelegate.onGetFullPath(pathWithSuffix);
        }

        if (!scriptBuffer.empty())
        {
            const auto &iter = __moduleCache.find(fullPath);
            if (iter != __moduleCache.end())
            {
                *ret = iter->second;
                //                printf("Found cache: %s, value: %d\n", fullPath.c_str(), (int)ret->getType());
                return true;
            }
            std::string currentScriptFileDir = FileUtils::getInstance()->getFileDir(fullPath);

            // Add closure for evalutate the script
            char prefix[] = "(function(currentScriptDir){ window.module = window.module || {}; var exports = window.module.exports = {}; ";
            char suffix[512] = {0};
            snprintf(suffix, sizeof(suffix), "\nwindow.module.exports = window.module.exports || exports;\n})('%s'); ", currentScriptFileDir.c_str());

            // Add current script path to require function invocation
            scriptBuffer = prefix + std::regex_replace(scriptBuffer, std::regex("([^A-Za-z0-9]|^)requireModule\\((.*?)\\)"), "$1requireModule($2, currentScriptDir)") + suffix;

            //            FILE* fp = fopen("/Users/james/Downloads/test.txt", "wb");
            //            fwrite(scriptBuffer.c_str(), scriptBuffer.length(), 1, fp);
            //            fclose(fp);

            std::string reletivePath = fullPath;
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
            const std::string reletivePathKey = "/Contents/Resources";
#else
            const std::string reletivePathKey = ".app";
#endif

            size_t pos = reletivePath.find(reletivePathKey);
            if (pos != std::string::npos)
            {
                reletivePath = reletivePath.substr(pos + reletivePathKey.length() + 1);
            }
#endif

            //            RENDERER_LOGD("Evaluate: %s", fullPath.c_str());

            auto se = ScriptEngine::getInstance();
            bool succeed = se->evalString(scriptBuffer.c_str(), scriptBuffer.length(), nullptr, reletivePath.c_str());
            v8::Local<v8::Value> moduleVal;
            ;
            if (succeed && JsbUtils::GetProperty(isolate, se->getGlobalObject(), "module", &moduleVal) && moduleVal->IsObject())
            {
                v8::Local<v8::Value> exportsVal;
                if (moduleVal->ToObject(isolate->GetCurrentContext()).ToLocalChecked()->Get(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked()).ToLocal(&exportsVal))
                {
                    if (ret != nullptr)
                        *ret = handleScope.Escape(exportsVal);
                    v8::Global<v8::Value> persistent(isolate, exportsVal);
                    __moduleCache[fullPath] = std::move(persistent);
                }
                else
                {
                    v8::Global<v8::Value> persistent(isolate, se::Value::Undefined);
                    __moduleCache[fullPath] = std::move(persistent);
                }
                // clear module.exports
                // moduleVal.toObject()->setProperty("exports", se::Value::Undefined);
                moduleVal->ToObject(isolate->GetCurrentContext()).ToLocalChecked()->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked(), v8::Undefined(isolate)).FromJust();
            }
            else
            {
                v8::Global<v8::Value> persistent(isolate, se::Value::Undefined);
                __moduleCache[fullPath] = std::move(persistent);
            }
            assert(succeed);
            return succeed;
        }

        SE_LOGE("doModuleRequire %s, buffer is empty!\n", path.c_str());
        assert(false);
        return false;
    }

    static void moduleRequire(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
    {
        ++__jsbInvocationCount;
        bool ret = false;
        v8::Isolate *_isolate = _v8args.GetIsolate();
        v8::HandleScope _hs(_isolate);
        SE_UNUSED unsigned argc = (unsigned)_v8args.Length();

        void *nativeThisObject = JsbUtils::GetPrivate(_isolate, _v8args.This());
        // void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This());
        // se::State state(nativeThisObject, args);
        // ret = funcName(state);

        assert(argc >= 2);
        assert(_v8args[0]->IsString());
        assert(_v8args[1]->IsString());
        v8::Local<v8::Value> retVal;
        bool ret = doModuleRequire(JsbUtils::FromV8String(_isolate, _v8args[0]), &retVal, JsbUtils::FromV8String(_isolate, _v8args[1]));
        _v8args.GetReturnValue().Set(retVal);
        if (!ret)
        {
            SE_LOGE("[ERROR] Failed to invoke %s, location: %s:%d\n", #funcName, __FILE__, __LINE__);
        }
        // se::internal::setReturnValue(state.rval(), _v8args);
        // return ret;
    }
    // SE_BIND_FUNC(moduleRequire)

} // namespace {

bool jsb_run_script(const std::string &filePath, v8::Local<v8::Value> *rval /* = nullptr */)
{
    v8::Isolate *isolate = ScriptEngine::getInstance()->getIsolate();
    v8::HandleScope handleScope(isolate);
    return ScriptEngine::getInstance()->runScript(filePath, rval);
}

bool jsb_run_script_module(const std::string &filePath, v8::Local<v8::Value> *rval /* = nullptr */)
{
    return doModuleRequire(filePath, rval, "");
}

static bool jsc_garbageCollect(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    ++__jsbInvocationCount;
    bool ret = false;
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);
    SE_UNUSED unsigned argc = (unsigned)_v8args.Length();
    void *nativeThisObject = JsbUtils::GetPrivate(_isolate, _v8args.This());
    // se::State state(nativeThisObject, args);
    // ret = funcName(state);
    ret = ScriptEngine::getInstance()->garbageCollect();
    if (!ret)
    {
        SE_LOGE("[ERROR] Failed to invoke %s, location: %s:%d\n", #funcName, __FILE__, __LINE__);
    }
    // se::internal::setReturnValue(state.rval(), _v8args);
    _v8args.GetReturnValue().Set(v8::Boolean::New(_isolate, ret));
    return true;
}
// SE_BIND_FUNC(jsc_garbageCollect)

static bool jsc_dumpNativePtrToSeObjectMap(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    // cocos2d::log(">>> total: %d, Dump (native -> jsobj) map begin", (int)se::NativePtrToObjectMap::size());

    // struct NamePtrStruct
    // {
    //     const char *name;
    //     void *ptr;
    // };

    // std::vector<NamePtrStruct> namePtrArray;

    // for (const auto &e : se::NativePtrToObjectMap::instance())
    // {
    //     se::Object *jsobj = e.second;
    //     assert(jsobj->_getClass() != nullptr);
    //     NamePtrStruct tmp;
    //     tmp.name = jsobj->_getClass()->getName();
    //     tmp.ptr = e.first;
    //     namePtrArray.push_back(tmp);
    // }

    // std::sort(namePtrArray.begin(), namePtrArray.end(), [](const NamePtrStruct &a, const NamePtrStruct &b) -> bool
    //           {
    //     std::string left = a.name;
    //     std::string right = b.name;
    //     for( std::string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
    //         if( ::tolower( *lit ) < ::tolower( *rit ) )
    //             return true;
    //         else if( ::tolower( *lit ) > ::tolower( *rit ) )
    //             return false;
    //     if( left.size() < right.size() )
    //         return true;
    //     return false; });

    // for (const auto &e : namePtrArray)
    // {
    //     cocos2d::log("%s: %p", e.name, e.ptr);
    // }
    // cocos2d::log(">>> total: %d, nonRefMap: %d, Dump (native -> jsobj) map end", (int)se::NativePtrToObjectMap::size(), (int)se::NonRefNativePtrCreatedByCtorMap::size());
    return true;
}
// SE_BIND_FUNC(jsc_dumpNativePtrToSeObjectMap)

static bool jsc_dumpRoot(const v8::FunctionCallbackInfo<v8::Value> &s)
{
    assert(false);
    return true;
}
// SE_BIND_FUNC(jsc_dumpRoot)

static bool JSBCore_platform(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    ++__jsbInvocationCount;
    bool ret = false;
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);
    SE_UNUSED unsigned argc = (unsigned)_v8args.Length();
    Application::Platform platform = Application::getInstance()->getPlatform();
    _v8args.GetReturnValue().Set(v8::Int32::New(_v8args.GetIsolate(), (int32_t)platform));
    return true;
}
// SE_BIND_FUNC(JSBCore_platform)

static bool JSBCore_version(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    // cjh    char version[256];
    //     snprintf(version, sizeof(version)-1, "%s", cocos2dVersion());
    //
    //     s.rval().setString(version);
    return true;
}
// SE_BIND_FUNC(JSBCore_version)

static bool JSBCore_os(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    // se::Value os;
    v8::Local<v8::String> os;
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);
    SE_UNUSED unsigned argc = (unsigned)_v8args.Length();

    // osx, ios, android, windows, linux, etc..
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    os = JsbUtils::ToV8String(_isolate, "iOS");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    os = JsbUtils::ToV8String(_isolate, "Android");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    os = JsbUtils::ToV8String(_isolate, "Windows");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
    os = JsbUtils::ToV8String(_isolate, "Marmalade");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    os = JsbUtils::ToV8String(_isolate, "Linux");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BADA)
    os = JsbUtils::ToV8String(_isolate, "Bada");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
    os = JsbUtils::ToV8String(_isolate, "Blackberry");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    os = JsbUtils::ToV8String(_isolate, "OS X");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    os = JsbUtils::ToV8String(_isolate, "WINRT");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY)
    os = JsbUtils::ToV8String(_isolate, "OpenHarmony");
#else
    os = JsbUtils::ToV8String(_isolate, "Unknown");
#endif

    _v8args.GetReturnValue().Set(os);
    return true;
}
// SE_BIND_FUNC(JSBCore_os)

static bool JSBCore_getCurrentLanguage(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    ++__jsbInvocationCount;
    bool ret = false;
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);
    SE_UNUSED unsigned argc = (unsigned)_v8args.Length();

    std::string languageStr;
    Application::LanguageType language = Application::getInstance()->getCurrentLanguage();
    switch (language)
    {
    case Application::LanguageType::ENGLISH:
        languageStr = "en";
        break;
    case Application::LanguageType::CHINESE:
        languageStr = "zh";
        break;
    case Application::LanguageType::FRENCH:
        languageStr = "fr";
        break;
    case Application::LanguageType::ITALIAN:
        languageStr = "it";
        break;
    case Application::LanguageType::GERMAN:
        languageStr = "de";
        break;
    case Application::LanguageType::SPANISH:
        languageStr = "es";
        break;
    case Application::LanguageType::DUTCH:
        languageStr = "du";
        break;
    case Application::LanguageType::RUSSIAN:
        languageStr = "ru";
        break;
    case Application::LanguageType::KOREAN:
        languageStr = "ko";
        break;
    case Application::LanguageType::JAPANESE:
        languageStr = "ja";
        break;
    case Application::LanguageType::HUNGARIAN:
        languageStr = "hu";
        break;
    case Application::LanguageType::PORTUGUESE:
        languageStr = "pt";
        break;
    case Application::LanguageType::ARABIC:
        languageStr = "ar";
        break;
    case Application::LanguageType::NORWEGIAN:
        languageStr = "no";
        break;
    case Application::LanguageType::POLISH:
        languageStr = "pl";
        break;
    case Application::LanguageType::TURKISH:
        languageStr = "tr";
        break;
    case Application::LanguageType::UKRAINIAN:
        languageStr = "uk";
        break;
    case Application::LanguageType::ROMANIAN:
        languageStr = "ro";
        break;
    case Application::LanguageType::BULGARIAN:
        languageStr = "bg";
        break;
    default:
        languageStr = "unknown";
        break;
    }

    if (!ret)
    {
        SE_LOGE("[ERROR] Failed to invoke %s, location: %s:%d\n", #funcName, __FILE__, __LINE__);
    }

    _v8args.GetReturnValue().Set(JsbUtils::ToV8String(_isolate, languageStr));
    return true;
}
// SE_BIND_FUNC(JSBCore_getCurrentLanguage)

static bool JSBCore_getCurrentLanguageCode(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    ++__jsbInvocationCount;
    bool ret = false;
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);
    SE_UNUSED unsigned argc = (unsigned)_v8args.Length();
    // se::ValueArray args;
    // args.reserve(10);
    // se::internal::jsToSeArgs(_v8args, &args);
    // void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This());
    // se::State state(nativeThisObject, args);
    // ret = funcName(state);

    // se::internal::setReturnValue(state.rval(), _v8args); \


    std::string language = Application::getInstance()->getCurrentLanguageCode();
    _v8args.GetReturnValue().Set(JsbUtils::ToV8String(_isolate, language));
    return true;
}
// SE_BIND_FUNC(JSBCore_getCurrentLanguageCode)

static bool JSB_getOSVersion(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    std::string systemVersion = Application::getInstance()->getSystemVersion();
    _v8args.GetReturnValue().Set(JsbUtils::ToV8String(_isolate, systemVersion));
    return true;
}
// SE_BIND_FUNC(JSB_getOSVersion)

static bool JSB_cleanScript(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    assert(false); // IDEA:
    return true;
}
// SE_BIND_FUNC(JSB_cleanScript)

static bool JSB_core_restartVM(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    // REFINE: release AudioEngine, waiting HttpClient & WebSocket threads to exit.
    Application::getInstance()->restart();
    return true;
}
// SE_BIND_FUNC(JSB_core_restartVM)

static bool JSB_closeWindow(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    Application::getInstance()->end();
    return true;
}
// SE_BIND_FUNC(JSB_closeWindow)

static bool JSB_isObjectValid(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    int argc = (int)_v8args.Length();
    if (argc == 1)
    {
        void *nativePtr = nullptr;
        seval_to_native_ptr(_v8args[0], &nativePtr);
        _v8args.GetReturnValue().Set(v8::Boolean::New(_v8args.GetIsolate(), nativePtr != nullptr));
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments: %d. Expecting: 1", argc);
    return false;
}
// SE_BIND_FUNC(JSB_isObjectValid)

// static bool getOrCreatePlainObject_r(const char *name, se::Object *parent, se::Object **outObj)
// {
//     assert(parent != nullptr);
//     assert(outObj != nullptr);
//     se::Value tmp;

//     if (parent->getProperty(name, &tmp) && tmp.isObject())
//     {
//         *outObj = tmp.toObject();
//         (*outObj)->incRef();
//     }
//     else
//     {
//         *outObj = se::Object::createPlainObject();
//         parent->setProperty(name, se::Value(*outObj));
//     }

//     return true;
// }

static bool js_performance_now(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    auto now = std::chrono::steady_clock::now();
    auto micro = std::chrono::duration_cast<std::chrono::microseconds>(now - ScriptEngine::getInstance()->getStartTime()).count();
    _v8args.GetReturnValue().Set(v8::Number::New(_isolate, (double)micro * 0.001));
    return true;
}
// SE_BIND_FUNC(js_performance_now)

namespace
{
    struct ImageInfo
    {
        ~ImageInfo()
        {
            if (freeData)
                delete[] data;
        }

        uint32_t length = 0;
        uint32_t width = 0;
        uint32_t height = 0;
        uint8_t *data = nullptr;
        GLenum glFormat = GL_RGBA;
        GLenum glInternalFormat = GL_RGBA;
        GLenum type = GL_UNSIGNED_BYTE;
        uint8_t bpp = 0;
        uint8_t numberOfMipmaps = 0;
        bool hasAlpha = false;
        bool hasPremultipliedAlpha = false;
        bool compressed = false;

        bool freeData = false;
    };

    uint8_t *convertRGB2RGBA(uint32_t length, uint8_t *src)
    {
        uint8_t *dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4)
        {
            dst[i] = *src++;
            dst[i + 1] = *src++;
            dst[i + 2] = *src++;
            dst[i + 3] = 255;
        }
        return dst;
    }

    uint8_t *convertIA2RGBA(uint32_t length, uint8_t *src)
    {
        uint8_t *dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4)
        {
            dst[i] = *src;
            dst[i + 1] = *src;
            dst[i + 2] = *src++;
            dst[i + 3] = *src++;
        }
        return dst;
    }

    uint8_t *convertI2RGBA(uint32_t length, uint8_t *src)
    {
        uint8_t *dst = new uint8_t[length];
        for (uint32_t i = 0; i < length; i += 4)
        {
            dst[i] = *src;
            dst[i + 1] = *src;
            dst[i + 2] = *src++;
            dst[i + 3] = 255;
        }
        return dst;
    }

    struct ImageInfo *createImageInfo(const Image *img)
    {
        struct ImageInfo *imgInfo = new struct ImageInfo();
        imgInfo->length = (uint32_t)img->getDataLen();
        imgInfo->width = img->getWidth();
        imgInfo->height = img->getHeight();
        imgInfo->data = img->getData();

        const auto &pixelFormatInfo = img->getPixelFormatInfo();
        imgInfo->glFormat = pixelFormatInfo.format;
        imgInfo->glInternalFormat = pixelFormatInfo.internalFormat;
        imgInfo->type = pixelFormatInfo.type;

        imgInfo->bpp = img->getBitPerPixel();
        imgInfo->numberOfMipmaps = img->getNumberOfMipmaps();
        imgInfo->hasAlpha = img->hasAlpha();
        imgInfo->hasPremultipliedAlpha = img->hasPremultipliedAlpha();
        imgInfo->compressed = img->isCompressed();

        // Convert to RGBA888 because standard web api will return only RGBA888.
        // If not, then it may have issue in glTexSubImage. For example, engine
        // will create a big texture, and update its content with small pictures.
        // The big texture is RGBA888, then the small picture should be the same
        // format, or it will cause 0x502 error on OpenGL ES 2.
        if (!imgInfo->compressed && imgInfo->glFormat != GL_RGBA)
        {
            imgInfo->length = img->getWidth() * img->getHeight() * 4;
            uint8_t *dst = nullptr;
            uint32_t length = imgInfo->length;
            uint8_t *src = imgInfo->data;
            switch (imgInfo->glFormat)
            {
            case GL_LUMINANCE_ALPHA:
                dst = convertIA2RGBA(length, src);
                break;
            case GL_ALPHA:
            case GL_LUMINANCE:
                dst = convertI2RGBA(length, src);
                break;
            case GL_RGB:
                dst = convertRGB2RGBA(length, src);
                break;
            default:
                SE_LOGE("unknown image format");
                break;
            }

            imgInfo->data = dst;
            imgInfo->hasAlpha = true;
            imgInfo->bpp = 32;
            imgInfo->glFormat = GL_RGBA;
            imgInfo->glInternalFormat = GL_RGBA;
            imgInfo->freeData = true;
        }

        return imgInfo;
    }
}
bool jsb_global_load_image(const std::string &path, const v8::Local<v8::Function> &callbackVal)
{
    // TODO
    assert(false);
    // if (path.empty())
    // {
    //     v8::Isolate *isolate = ScriptEngine::getInstance()->getIsolate();
    //     v8::HandleScope handleScope(isolate);

    //     // se::ValueArray seArgs;
    //     callbackVal->Call(isolate->GetCurrentContext(), v8::Undefined(isolate), 0, nullptr).ToLocalChecked();
    //     return true;
    // }

    // // std::shared_ptr<se::Value> callbackPtr = std::make_shared<se::Value>(callbackVal);

    // auto initImageFunc = [path, callbackPtr](const std::string &fullPath, unsigned char *imageData, int imageBytes, const std::string &errorMsg)
    // {
    //     std::shared_ptr<uint8_t> imageDataGuard(imageData, free);

    //     auto pool = g_threadPool;
    //     if (!pool)
    //         return;
    //     pool->pushTask([=](int tid) mutable
    //                    {
    //                        // NOTE: FileUtils::getInstance()->fullPathForFilename isn't a threadsafe method,
    //                        // Image::initWithImageFile will call fullPathForFilename internally which may
    //                        // cause thread race issues. Therefore, we get the full path of file before
    //                        // going into task callback.
    //                        // Be careful of invoking any Cocos2d-x interface in a sub-thread.
    //                        bool loadSucceed = false;
    //                        std::shared_ptr<Image> img(new Image(), [](Image *image)
    //                                                   { image->release(); });

    //                        if (!errorMsg.empty())
    //                        {
    //                            loadSucceed = false;
    //                        }
    //                        else if (fullPath.empty())
    //                        {
    //                            loadSucceed = img->initWithImageData(imageDataGuard.get(), imageBytes);
    //                            imageDataGuard = nullptr;
    //                        }
    //                        else
    //                        {
    //                            loadSucceed = img->initWithImageFile(fullPath);
    //                        }

    //                        std::shared_ptr<ImageInfo> imgInfo;
    //                        if (loadSucceed)
    //                        {
    //                            imgInfo.reset(createImageInfo(img.get()));
    //                        }

    //                        Application::getInstance()->getScheduler()->performFunctionInCocosThread([=]() mutable
    //                                                                                                 {
    //             se::AutoHandleScope hs;
    //             se::ValueArray seArgs;
    //             se::Value dataVal;

    //             std::vector< se::Object* > refs;
    //             if (loadSucceed)
    //             {
    //                 se::Object* retObj = se::Object::createPlainObject();
    //                 retObj->root();
    //                 refs.push_back(retObj);

    //                 Data data;
    //                 data.fastSet(imgInfo->data, imgInfo->length);
    //                 Data_to_seval(data, &dataVal);
    //                 data.takeBuffer();
    //                 retObj->setProperty("data", dataVal);
    //                 retObj->setProperty("width", se::Value(imgInfo->width));
    //                 retObj->setProperty("height", se::Value(imgInfo->height));
    //                 retObj->setProperty("premultiplyAlpha", se::Value(imgInfo->hasPremultipliedAlpha));
    //                 retObj->setProperty("bpp", se::Value(imgInfo->bpp));
    //                 retObj->setProperty("hasAlpha", se::Value(imgInfo->hasAlpha));
    //                 retObj->setProperty("compressed", se::Value(imgInfo->compressed));
    //                 retObj->setProperty("numberOfMipmaps", se::Value(imgInfo->numberOfMipmaps));
    //                 if (imgInfo->numberOfMipmaps > 0)
    //                 {
    //                     se::Object* mipmapArray = se::Object::createArrayObject(imgInfo->numberOfMipmaps);
    //                     mipmapArray->root();
    //                     refs.push_back(mipmapArray);

    //                     retObj->setProperty("mipmaps", se::Value(mipmapArray));
    //                     auto mipmapInfo = img->getMipmaps();
    //                     for (int i = 0; i < imgInfo->numberOfMipmaps; ++i)
    //                     {
    //                         se::Object* info = se::Object::createPlainObject();
    //                         info->root();
    //                         refs.push_back(info);

    //                         info->setProperty("offset", se::Value(mipmapInfo[i].offset));
    //                         info->setProperty("length", se::Value(mipmapInfo[i].len));
    //                         mipmapArray->setArrayElement(i, se::Value(info));
    //                     }
    //                 }

    //                 retObj->setProperty("glFormat", se::Value(imgInfo->glFormat));
    //                 retObj->setProperty("glInternalFormat", se::Value(imgInfo->glInternalFormat));
    //                 retObj->setProperty("glType", se::Value(imgInfo->type));

    //                 seArgs.push_back(se::Value(retObj));

    //                 imgInfo = nullptr;
    //             }
    //             else
    //             {
    //                 SE_REPORT_ERROR("initWithImageFile: %s failed!", path.c_str());
    //             }

    //             if (!errorMsg.empty()) {
    //                 se::Object* retObj = se::Object::createPlainObject();
    //                 retObj->root();
    //                 refs.push_back(retObj);

    //                 retObj->setProperty("errorMsg", se::Value(errorMsg));
    //                 seArgs.push_back(se::Value(retObj));
    //             }

    //             callbackPtr->toObject()->call(seArgs, nullptr);
    //             img = nullptr;

    //             for (auto obj : refs) {
    //                 obj->unroot();
    //                 obj->decRef();
    //             } }); });
    // };

    // size_t pos = std::string::npos;
    // if (path.find("http://") == 0 || path.find("https://") == 0)
    // {
    //     localDownloaderCreateTask(path, initImageFunc);
    // }
    // else if (path.find("data:") == 0 && (pos = path.find("base64,")) != std::string::npos)
    // {
    //     int imageBytes = 0;
    //     unsigned char *imageData = nullptr;
    //     size_t dataStartPos = pos + strlen("base64,");
    //     const char *base64Data = path.data() + dataStartPos;
    //     size_t dataLen = path.length() - dataStartPos;
    //     imageBytes = base64Decode((const unsigned char *)base64Data, (unsigned int)dataLen, &imageData);
    //     if (imageBytes <= 0 || imageData == nullptr)
    //     {
    //         SE_REPORT_ERROR("Decode base64 image data failed!");
    //         return false;
    //     }
    //     initImageFunc("", imageData, imageBytes, "");
    // }
    // else
    // {
    //     std::string fullPath(FileUtils::getInstance()->fullPathForFilename(path));
    //     if (0 == path.find("file://"))
    //         fullPath = FileUtils::getInstance()->fullPathForFilename(path.substr(strlen("file://")));

    //     if (fullPath.empty())
    //     {
    //         SE_REPORT_ERROR("File (%s) doesn't exist!", path.c_str());
    //         return false;
    //     }
    //     initImageFunc(fullPath, nullptr, 0, "");
    // }
    return true;
}

static bool js_loadImage(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc == 2)
    {
        std::string path = JsbUtils::FromV8String(_isolate, _v8args[0]);
        // SE_PRECONDITION2(ok, false, "js_loadImage : Error processing arguments");

        v8::Local<v8::Value> callbackVal = _v8args[1];
        assert(callbackVal->IsObject());
        assert(callbackVal->IsFunction());

        return jsb_global_load_image(path, callbackVal);
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
// SE_BIND_FUNC(js_loadImage)

// pixels(RGBA), width, height, fullFilePath(*.png/*.jpg)
static bool js_saveImageData(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc == 4)
    {
        cocos2d::Data data;
        ok &= seval_to_Data(_v8args[0], &data);

        uint32_t width, height;
        // ok &= seval_to_uint32(_v8args[1], &width);
        width = _v8args[1]->Uint32Value(_isolate->GetCurrentContext()).FromJust();
        // ok &= seval_to_uint32(_v8args[2], &height);
        height = _v8args[2]->Uint32Value(_isolate->GetCurrentContext()).FromJust();

        std::string filePath;
        filePath = JsbUtils::FromV8String(_isolate, _v8args[3]);
        // SE_PRECONDITION2(ok, false, "js_saveImageData : Error processing arguments");

        Image *img = new Image();
        img->initWithRawData(data.getBytes(), data.getSize(), width, height, 8);
        // isToRGB = false, to keep alpha channel
        bool ret = img->saveToFile(filePath, false);
        s.rval().setBoolean(ret);

        img->release();
        return ret;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
// SE_BIND_FUNC(js_saveImageData)

static bool js_setDebugViewText(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc == 2)
    {
        int32_t index;
        index = _v8args[0]->Int32Value(_isolate->GetCurrentContext()).FromJust();
        // SE_PRECONDITION2(ok, false, "Convert arg0 index failed!");

        std::string text = JsbUtils::FromV8String(_isolate, _v8args[1]);
        // SE_PRECONDITION2(ok, false, "Convert arg1 text failed!");

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        setGameInfoDebugViewTextJNI(index, text);
#endif
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
// SE_BIND_FUNC(js_setDebugViewText)

static bool js_openDebugView(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    openDebugViewJNI();
#endif
    return true;
}
// SE_BIND_FUNC(js_openDebugView)

static bool js_disableBatchGLCommandsToNative(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    disableBatchGLCommandsToNativeJNI();
#endif
    return true;
}
// SE_BIND_FUNC(js_disableBatchGLCommandsToNative)

static bool JSB_openURL(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc > 0)
    {
        std::string url = JsbUtils::FromV8String(_isolate, _v8args[0]);
        // SE_PRECONDITION2(ok, false, "url is invalid!");
        Application::getInstance()->openURL(url);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
// SE_BIND_FUNC(JSB_openURL)

static bool JSB_copyTextToClipboard(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc > 0)
    {
        std::string text = JsbUtils::FromV8String(_isolate, _v8args[0]);
        // SE_PRECONDITION2(ok, false, "text is invalid!");
        Application::getInstance()->copyTextToClipboard(text);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
// SE_BIND_FUNC(JSB_copyTextToClipboard)

static bool JSB_setPreferredFramesPerSecond(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc > 0)
    {
        int32_t fps = _v8args[0]->Int32Value(_isolate->GetCurrentContext()).FromJust();
        // SE_PRECONDITION2(ok, false, "fps is invalid!");
        Application::getInstance()->setPreferredFramesPerSecond(fps);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
// SE_BIND_FUNC(JSB_setPreferredFramesPerSecond)

static bool JSB_showInputBox(const v8::FunctionCallbackInfo<v8::Value> &_v8args)
{
    v8::Isolate *_isolate = _v8args.GetIsolate();
    v8::HandleScope _hs(_isolate);

    size_t argc = _v8args.Length();
    CC_UNUSED bool ok = true;
    if (argc == 1)
    {
        bool ok;
        v8::Local<v8::Value> tmp;
        const auto &obj = _v8args[0]->ToObject(_isolate->GetCurrentContext()).ToLocalChecked();

        cocos2d::EditBox::ShowInfo showInfo;

        ok = obj->Get(_isolate->GetCurrentContext(), v8::String::NewFromUtf8(_isolate, "defaultValue").ToLocalChecked()).ToLocal(&tmp);

        // SE_PRECONDITION2(ok && tmp.isString(), false, "defaultValue is invalid!");
        showInfo.defaultValue = tmp->ToString(_isolate->GetCurrentContext()).ToLocalChecked();

        ok = obj->Get(_isolate->GetCurrentContext(), v8::String::NewFromUtf8(_isolate, "maxLength").ToLocalChecked()).ToLocal(&tmp);
        // SE_PRECONDITION2(ok && tmp->IsNumber(), false, "maxLength is invalid!");
        showInfo.maxLength = tmp->Int32Value(_isolate->GetCurrentContext()).FromJust();

        ok = obj->Get(_isolate->GetCurrentContext(), v8::String::NewFromUtf8(_isolate, "multiple").ToLocalChecked()).ToLocal(&tmp);
        // SE_PRECONDITION2(ok && tmp.isBoolean(), false, "multiple is invalid!");
        showInfo.isMultiline = tmp->BooleanValue(_isolate);

        if (obj->Get(_isolate->GetCurrentContext(), v8::String::NewFromUtf8(_isolate, "confirmHold").ToLocalChecked()).ToLocal(&tmp))
        {
            // SE_PRECONDITION2(tmp.isBoolean(), false, "confirmHold is invalid!");
            if (!tmp->IsUndefined())
                showInfo.confirmHold = tmp->BooleanValue(_isolate);
        }

        if (obj->Get(_isolate->GetCurrentContext(), v8::String::NewFromUtf8(_isolate, "confirmType").ToLocalChecked()).ToLocal(&tmp))
        {
            // SE_PRECONDITION2(tmp.isString(), false, "confirmType is invalid!");
            if (!tmp->IsUndefined())
                showInfo.confirmType = tmp->ToString(_isolate->GetCurrentContext()).ToLocalChecked();
        };
        if (JsbUtils::GetProperty(obj, "confirmType", &tmp))
        {
            // SE_PRECONDITION2(tmp.isString(), false, "inputType is invalid!");
            if (!tmp->IsUndefined())
                showInfo.inputType = tmp->ToString(_isolate->GetCurrentContext()).ToLocalChecked();
        }

        if (JsbUtils::GetProperty(obj, "originX", &tmp))
        {
            SE_PRECONDITION2(tmp->IsNumber(), false, "originX is invalid!");
            if (!tmp->IsUndefined())
                showInfo.x = tmp->Int32Value(_isolate->GetCurrentContext()).FromJust();
        }

        if (JsbUtils::GetProperty(obj, "originY", &tmp))
        {
            SE_PRECONDITION2(tmp->IsNumber(), false, "originY is invalid!");
            if (!tmp->IsUndefined())
                showInfo.y = tmp->Int32Value(_isolate->GetCurrentContext()).FromJust();
        }

        if (JsbUtils::GetProperty(obj, "width", &tmp))
        {
            SE_PRECONDITION2(tmp->IsNumber(), false, "width is invalid!");
            if (!tmp->IsUndefined())
                showInfo.width = tmp->Int32Value(_isolate->GetCurrentContext()).FromJust();
        }

        if (JsbUtils::GetProperty(obj, "height", &tmp))
        {
            SE_PRECONDITION2(tmp->IsNumber(), false, "height is invalid!");
            if (!tmp->IsUndefined())
                showInfo.height = tmp->Int32Value(_isolate->GetCurrentContext()).FromJust();
        }

        EditBox::show(showInfo);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
// SE_BIND_FUNC(JSB_showInputBox);

static bool JSB_updateInputBoxRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    size_t argc = args.Length();
    if (argc == 4)
    {
        SE_PRECONDITION2(args[0]->IsNumber(), false, "x is invalid!");
        const auto x = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

        SE_PRECONDITION2(args[1]->IsNumber(), false, "y is invalid!");
        const auto y = args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

        SE_PRECONDITION2(args[2]->IsNumber(), false, "width is invalid!");
        const auto width = args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

        SE_PRECONDITION2(args[3]->IsNumber(), false, "height is invalid!");
        const auto height = args[3]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

        EditBox::updateRect(x, y, width, height);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
// SE_BIND_FUNC(JSB_updateInputBoxRect);

static bool JSB_hideInputBox(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    EditBox::hide();
    return true;
}
// SE_BIND_FUNC(JSB_hideInputBox)

// #if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY && (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8 || SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_JSVM)
// static bool sevalue_to_napivalue(const se::Value &seVal, Napi::Value *napiVal, Napi::Env env);

// static bool seobject_to_napivalue(se::Object *seObj, Napi::Value *napiVal, Napi::Env env)
// {
//     auto napiObj = Napi::Object::New(env);
//     std::vector<std::string> allKeys;
//     bool ok = seObj->getAllKeys(&allKeys);
//     if (ok && !allKeys.empty())
//     {
//         for (const auto &key : allKeys)
//         {
//             Napi::Value napiProp;
//             se::Value prop;
//             ok = seObj->getProperty(key.c_str(), &prop);
//             if (ok)
//             {
//                 ok = sevalue_to_napivalue(prop, &napiProp, env);
//                 if (ok)
//                 {
//                     napiObj.Set(key.c_str(), napiProp);
//                 }
//             }
//         }
//     }
//     *napiVal = napiObj;
//     return true;
// }

// static bool sevalue_to_napivalue(const se::Value &seVal, Napi::Value *napiVal, Napi::Env env)
// {
//     // Only supports number or {tag: number, url: string} now
//     if (seVal.isNumber())
//     {
//         *napiVal = Napi::Number::New(env, seVal.toDouble());
//     }
//     else if (seVal.isString())
//     {
//         *napiVal = Napi::String::New(env, seVal.toString().c_str());
//     }
//     else if (seVal.isBoolean())
//     {
//         *napiVal = Napi::Boolean::New(env, seVal.toBoolean());
//     }
//     else if (seVal.isObject())
//     {
//         seobject_to_napivalue(seVal.toObject(), napiVal, env);
//     }
//     else
//     {
//         LOGW("sevalue_to_napivalue, Unsupported type: %d", static_cast<int32_t>(seVal.getType()));
//         return false;
//     }

//     return true;
// }

// static bool JSB_openharmony_postMessage(se::State &s)
// { // NOLINT(readability-identifier-naming)
//     LOGI("[0111] enter JSB_openharmony_postMessage");
//     const auto &args = s.args();
//     size_t argc = args.size();

//     if (argc == 2)
//     {
//         bool ok = false;
//         std::string msgType;
//         ok = seval_to_std_string(args[0], &msgType);
//         SE_PRECONDITION2(ok, false, "Error processing arguments");

//         const auto &arg1 = args[1];
//         auto env = NapiHelper::getWorkerEnv();

//         Napi::Value napiArg1 = env.Undefined();

//         if (arg1.isNumber())
//         {
//             napiArg1 = Napi::Number::New(env, arg1.toDouble());
//         }
//         else if (arg1.isString())
//         {
//             napiArg1 = Napi::String::New(env, arg1.toString());
//         }
//         else if (arg1.isObject())
//         {
//             seobject_to_napivalue(arg1.toObject(), &napiArg1, env);
//         }
//         else
//         {
//             SE_REPORT_ERROR("postMessage, Unsupported type");
//             return false;
//         }

//         NapiHelper::postMessageToUIThread(msgType.c_str(), napiArg1);
//         return true;
//     }

//     SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
//     return false;
// }
// SE_BIND_FUNC(JSB_openharmony_postMessage)

// static bool JSB_empty_promise_then(se::State &s)
// {
//     return true;
// }
// SE_BIND_FUNC(JSB_empty_promise_then)

// static bool JSB_openharmony_postSyncMessage(se::State &s)
// { // NOLINT(readability-identifier-naming)
//     const auto &args = s.args();
//     size_t argc = args.size();

//     if (argc == 2)
//     {
//         bool ok = false;
//         std::string msgType;
//         ok = seval_to_std_string(args[0], &msgType);
//         SE_PRECONDITION2(ok, false, "Error processing arguments");

//         const auto &arg1 = args[1];
//         auto env = NapiHelper::getWorkerEnv();

//         Napi::Value napiArg1 = env.Undefined();

//         if (arg1.isNumber())
//         {
//             napiArg1 = Napi::Number::New(env, arg1.toDouble());
//         }
//         else if (arg1.isString())
//         {
//             napiArg1 = Napi::String::New(env, arg1.toString());
//         }
//         else if (arg1.isObject())
//         {
//             seobject_to_napivalue(arg1.toObject(), &napiArg1, env);
//         }
//         else
//         {
//             SE_REPORT_ERROR("postMessage, Unsupported type");
//             return false;
//         }

//         Napi::Value napiPromise = NapiHelper::postSyncMessageToUIThread(msgType.c_str(), napiArg1);

//         // TODO(cjh): Implement Promise for se
//         se::HandleObject retObj(se::Object::createPlainObject());
//         retObj->defineFunction("then", _SE(JSB_empty_promise_then));
//         s.rval().setObject(retObj);
//         //
//         return true;
//     }

//     SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
//     return false;
// }
// SE_BIND_FUNC(JSB_openharmony_postSyncMessage)
// #endif

bool jsb_register_global_variables(v8::Local<v8::Object> global)
{
    g_threadPool.reset(ThreadPool::newFixedThreadPool(3));

    JsbUtils::DefineFunction(global, "require", require);
    JsbUtils::DefineFunction(global, "requireModule", moduleRequire);

//     getOrCreatePlainObject_r("jsb", global, &__jsbObj);

//     auto glContextCls = se::Class::create("WebGLRenderingContext", global, nullptr, nullptr);
//     glContextCls->install();

//     SAFE_DEC_REF(__glObj);
//     __glObj = se::Object::createObjectWithClass(glContextCls);
//     global->setProperty("__gl", se::Value(__glObj));

//     __jsbObj->defineFunction("garbageCollect", _SE(jsc_garbageCollect));
//     __jsbObj->defineFunction("dumpNativePtrToSeObjectMap", _SE(jsc_dumpNativePtrToSeObjectMap));

//     __jsbObj->defineFunction("loadImage", _SE(js_loadImage));
//     __jsbObj->defineFunction("saveImageData", _SE(js_saveImageData));
//     __jsbObj->defineFunction("setDebugViewText", _SE(js_setDebugViewText));
//     __jsbObj->defineFunction("openDebugView", _SE(js_openDebugView));
//     __jsbObj->defineFunction("disableBatchGLCommandsToNative", _SE(js_disableBatchGLCommandsToNative));
//     __jsbObj->defineFunction("openURL", _SE(JSB_openURL));
//     __jsbObj->defineFunction("copyTextToClipboard", _SE(JSB_copyTextToClipboard));

//     __jsbObj->defineFunction("setPreferredFramesPerSecond", _SE(JSB_setPreferredFramesPerSecond));
//     __jsbObj->defineFunction("showInputBox", _SE(JSB_showInputBox));
//     __jsbObj->defineFunction("hideInputBox", _SE(JSB_hideInputBox));
//     __jsbObj->defineFunction("updateInputBoxRect", _SE(JSB_updateInputBoxRect));

//     global->defineFunction("__getPlatform", _SE(JSBCore_platform));
//     global->defineFunction("__getOS", _SE(JSBCore_os));
//     global->defineFunction("__getOSVersion", _SE(JSB_getOSVersion));
//     global->defineFunction("__getCurrentLanguage", _SE(JSBCore_getCurrentLanguage));
//     global->defineFunction("__getCurrentLanguageCode", _SE(JSBCore_getCurrentLanguageCode));
//     global->defineFunction("__getVersion", _SE(JSBCore_version));
//     global->defineFunction("__restartVM", _SE(JSB_core_restartVM));
//     global->defineFunction("__cleanScript", _SE(JSB_cleanScript));
//     global->defineFunction("__isObjectValid", _SE(JSB_isObjectValid));
//     global->defineFunction("close", _SE(JSB_closeWindow));

//     se::HandleObject performanceObj(se::Object::createPlainObject());
//     performanceObj->defineFunction("now", _SE(js_performance_now));
//     global->setProperty("performance", se::Value(performanceObj));

// #if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY && (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8 || SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_JSVM)
//     se::HandleObject ohObj(se::Object::createPlainObject());
//     global->setProperty("oh", se::Value(ohObj));
//     ohObj->defineFunction("postMessage", _SE(JSB_openharmony_postMessage));
//     ohObj->defineFunction("postSyncMessage", _SE(JSB_openharmony_postSyncMessage));
// #endif
//     se::ScriptEngine::getInstance()->clearException();

//     se::ScriptEngine::getInstance()->addBeforeCleanupHook([]()
//                                                           {
//         g_threadPool = nullptr;

//         PoolManager::getInstance()->getCurrentPool()->clear(); });

//     se::ScriptEngine::getInstance()->addAfterCleanupHook([]()
//                                                          {

//         PoolManager::getInstance()->getCurrentPool()->clear();

//         __moduleCache.clear();

//         SAFE_DEC_REF(__jsbObj);
//         SAFE_DEC_REF(__glObj); });

    return true;
}
