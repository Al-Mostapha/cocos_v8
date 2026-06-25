#include "ScriptEngine.hpp"
#include <cstdio>

#define EXPOSE_GC "__jsb_gc__"
#include "JsbUtils.h"
#include <sstream>
#include "Utils/MappingUtils.hpp"
#include "platform/CCFileUtils.h"

ScriptEngine *ScriptEngine::_instance = nullptr;
int __jsbInvocationCount = 0;
uint32_t __jsbStackFrameLimit = 20;
Class *__jsb_CCPrivateData_class = nullptr;

std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>> ScriptEngine::_registeredClasses = {};

ScriptEngine *ScriptEngine::getInstance()
{
    if (!_instance)
        _instance = new ScriptEngine();
    return _instance;
}

ScriptEngine::ScriptEngine()
    : _platform(nullptr), _isolate(nullptr), _handleScope(nullptr)
#if SE_ENABLE_INSPECTOR
      ,
      _env(nullptr), _isolateData(nullptr)
#endif
      ,
      _debuggerServerPort(0), _vmId(0), _isValid(false), _isGarbageCollecting(false), _isInCleanup(false), _isErrorHandleWorking(false)
{
    SE_LOGD("ScriptEngine::ScriptEngine()");
    _startTime = std::chrono::steady_clock::now();
    _platform = v8::platform::NewDefaultPlatform().release();
    v8::V8::InitializePlatform(_platform);

    std::string flags;
    // NOTICE: spaces are required between flags
    flags.append(" --expose-gc-as=" EXPOSE_GC);
    // flags.append(" --trace-gc"); // v8 trace gc
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
// TODO
// if(!jitSupported()) {
//     flags.append(" --jitless");
// }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY)
    flags.append(" --jitless");
#endif
    if (!flags.empty())
    {
        v8::V8::SetFlagsFromString(flags.c_str(), (int)flags.length());
    }
    bool ok = v8::V8::Initialize();
    assert(ok);
}

void ScriptEngine::destroyInstance()
{
    delete _instance;
    _instance = nullptr;
}

ScriptEngine::~ScriptEngine()
{
    cleanup();
    v8::V8::Dispose();
    // TODO
    v8::V8::DisposePlatform();
    delete _platform;
}

void ScriptEngine::callExceptionCallback(const char *location, const char *message, const char *stack)
{
    if (_nativeExceptionCallback)
    {
        _nativeExceptionCallback(location, message, stack);
    }
    if (_jsExceptionCallback)
    {
        _jsExceptionCallback(location, message, stack);
    }
}

void ScriptEngine::onFatalErrorCallback(const char *location, const char *message)
{
    std::string errorStr = "[FATAL ERROR] location: ";
    errorStr += location;
    errorStr += ", message: ";
    errorStr += message;

    SE_LOGE("%s\n", errorStr.c_str());

    getInstance()->callExceptionCallback(location, message, "(no stack information)");
}

void ScriptEngine::onOOMErrorCallback(const char *location,
                                      const v8::OOMDetails &details)
{
    std::string errorStr = "[OOM ERROR] location: ";
    errorStr += location;
    std::string message;
    message = "is heap out of memory: ";
    if (details.is_heap_oom)
        message += "true";
    else
        message += "false";

    errorStr += ", " + message;
    SE_LOGE("%s\n", errorStr.c_str());
    getInstance()->callExceptionCallback(location, message.c_str(), "(no stack information)");
}

std::string stackTraceToString(v8::Local<v8::StackTrace> stackTrace)
{
    std::string stackStr;
    if (stackTrace.IsEmpty())
        return stackStr;

    char tmp[100] = {0};
    for (int i = 0, e = stackTrace->GetFrameCount(); i < e; ++i)
    {
        v8::Local<v8::StackFrame> frame = stackTrace->GetFrame(v8::Isolate::GetCurrent(), i);
        v8::Local<v8::String> script = frame->GetScriptName();
        std::string scriptName;
        if (!script.IsEmpty())
        {
            scriptName = *v8::String::Utf8Value(v8::Isolate::GetCurrent(), script);
        }

        v8::Local<v8::String> func = frame->GetFunctionName();
        std::string funcName;
        if (!func.IsEmpty())
        {
            funcName = *v8::String::Utf8Value(v8::Isolate::GetCurrent(), func);
        }

        stackStr += "[";
        snprintf(tmp, sizeof(tmp), "%d", i);
        stackStr += tmp;
        stackStr += "]";
        stackStr += (funcName.empty() ? "anonymous" : funcName.c_str());
        stackStr += "@";
        stackStr += (scriptName.empty() ? "(no filename)" : scriptName.c_str());
        stackStr += ":";
        snprintf(tmp, sizeof(tmp), "%d", frame->GetLineNumber());
        stackStr += tmp;

        if (i < (e - 1))
        {
            stackStr += "\n";
        }
    }

    return stackStr;
}

void ScriptEngine::onMessageCallback(v8::Local<v8::Message> message, v8::Local<v8::Value> data)
{
    ScriptEngine *thiz = getInstance();
    v8::Local<v8::String> msg = message->Get();

    v8::Isolate *isolate = v8::Isolate::GetCurrent();

    v8::HandleScope handle_scope(isolate);
    assert(msg->IsString());
    v8::String::Utf8Value utf8(isolate, msg);
    std::string msgStr(*utf8, utf8.length());

    v8::ScriptOrigin origin = message->GetScriptOrigin();
    std::string resouceNameVal = JsbUtils::FromV8String(isolate, origin.ResourceName());
    int line = origin.LineOffset();

    int column = origin.ColumnOffset();

    std::string location = resouceNameVal + ":" + std::to_string(line) + ":" + std::to_string(column);

    std::string errorStr = msgStr + ", location: " + location;
    std::string stackStr = stackTraceToString(message->GetStackTrace());
    if (!stackStr.empty())
    {
        if (line == 0)
        {
            location = "(see stack)";
        }
        errorStr += "\nSTACK:\n" + stackStr;
    }
    SE_LOGE("ERROR: %s\n", errorStr.c_str());

    thiz->callExceptionCallback(location.c_str(), msgStr.c_str(), stackStr.c_str());

    if (!thiz->_isErrorHandleWorking)
    {
        thiz->_isErrorHandleWorking = true;

        // TODO: call __errorHandler in JS, and pass error message, location and stack info to it.
        // Value errorHandler;
        // if (thiz->_globalObj && thiz->_globalObj->getProperty("__errorHandler", &errorHandler) && errorHandler.isObject() && errorHandler.toObject()->isFunction())
        // {
        //     ValueArray args;
        //     args.push_back(resouceNameVal);
        //     args.push_back(line);
        //     args.push_back(msgVal);
        //     args.push_back(Value(stackStr));
        //     errorHandler.toObject()->call(args, thiz->_globalObj);
        // }

        thiz->_isErrorHandleWorking = false;
    }
    else
    {
        SE_LOGE("ERROR: __errorHandler has exception\n");
    }
}

std::string ScriptEngine::getCurrentStackTrace()
{
    v8::HandleScope scope(_isolate);
    v8::Local<v8::StackTrace> stackTrace = v8::StackTrace::CurrentStackTrace(_isolate, __jsbStackFrameLimit, v8::StackTrace::kOverview);
    return stackTraceToString(stackTrace);
}

void ScriptEngine::onPromiseRejectCallback(v8::PromiseRejectMessage msg)
{
    v8::Isolate *isolate = getInstance()->_isolate;
    v8::HandleScope scope(isolate);
    std::stringstream ss;
    auto event = msg.GetEvent();
    auto value = msg.GetValue();
    const char *eventName = "[invalidatePromiseEvent]";

    if (event == v8::kPromiseRejectWithNoHandler)
    {
        eventName = "unhandledRejectedPromise";
    }
    else if (event == v8::kPromiseHandlerAddedAfterReject)
    {
        eventName = "handlerAddedAfterPromiseRejected";
    }
    else if (event == v8::kPromiseRejectAfterResolved)
    {
        eventName = "rejectAfterPromiseResolved";
    }
    else if (event == v8::kPromiseResolveAfterResolved)
    {
        eventName = "resolveAfterPromiseResolved";
    }

    if (!value.IsEmpty())
    {
        // prepend error object to stack message
        v8::Local<v8::String> str = value->ToString(isolate->GetCurrentContext()).ToLocalChecked();
        v8::String::Utf8Value valueUtf8(isolate, str);
        ss << *valueUtf8 << std::endl;
    }

    auto stackStr = getInstance()->getCurrentStackTrace();
    ss << "stacktrace: " << std::endl;
    ss << stackStr << std::endl;
    getInstance()->callExceptionCallback("", eventName, ss.str().c_str());
}

static void printArgs(const char *prefix,
                      const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);

    std::string out(prefix);
    for (int i = 0; i < args.Length(); ++i)
    {
        if (i > 0)
            out += ' ';

        v8::Local<v8::Value> val = args[i];

        // Stringify objects with JSON.stringify, primitives with ToString
        if (val->IsObject() && !val->IsFunction())
        {
            v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
            v8::Local<v8::String> json;
            if (v8::JSON::Stringify(ctx, val).ToLocal(&json))
            {
                v8::String::Utf8Value str(isolate, json);
                out += *str ? *str : "[object]";
            }
        }
        else
        {
            v8::String::Utf8Value str(isolate, val);
            out += *str ? *str : "";
        }
    }

    // Route to your engine's logger — swap with CCLOG if preferred
    SE_LOGD("%s\n", out.c_str());
}

void ScriptEngine::_InstallConsole()
{
    v8::Isolate::Scope isolateScope(_isolate);
    v8::HandleScope handleScope(_isolate);

    v8::Local<v8::Context> ctx = _context.Get(_isolate);
    v8::Context::Scope ctxScope(ctx);
    v8::Local<v8::Object> global = _globalObj.Get(_isolate);

    v8::Local<v8::String> consoleKey =
        v8::String::NewFromUtf8(_isolate, "console").ToLocalChecked();

    // Check if console already exists
    v8::Local<v8::Value> existing;
    if (global->Get(ctx, consoleKey).ToLocal(&existing) &&
        existing->IsObject())
    {
        v8::Local<v8::Object> existingConsole = existing.As<v8::Object>();
        v8::Local<v8::String> logKey =
            v8::String::NewFromUtf8(_isolate, "log").ToLocalChecked();
        v8::Local<v8::Value> logFn;
        if (!existingConsole->Get(ctx, logKey).ToLocal(&logFn) || !logFn->IsFunction())
        {
            // log is missing or not a function — fall through and redefine
            SE_LOGD("console exists but .log is not a function, redefining...");
        }
        else
        {
            SE_LOGD("Console object already exists, skip installing console.\n");
            // TODO
            // return; // genuinely healthy, skip
        }
        // TODO
        // return; // already defined, nothing to do
    }

    // Build the console object
    v8::Local<v8::Object> console = v8::Object::New(_isolate);

    // Helper: create a function and bind it to a name on console
    auto addMethod = [&](const char *name, v8::FunctionCallback cb)
    {
        v8::Local<v8::String> key =
            v8::String::NewFromUtf8(_isolate, name).ToLocalChecked();
        v8::Local<v8::Function> fn =
            v8::Function::New(ctx, cb).ToLocalChecked();
        console->Set(ctx, key, fn).Check();
    };

    addMethod("log", [](const v8::FunctionCallbackInfo<v8::Value> &args)
              { printArgs("[LOG]  ", args); });
    addMethod("warn", [](const v8::FunctionCallbackInfo<v8::Value> &args)
              { printArgs("[WARN] ", args); });
    addMethod("error", [](const v8::FunctionCallbackInfo<v8::Value> &args)
              { printArgs("[ERR]  ", args); });
    addMethod("info", [](const v8::FunctionCallbackInfo<v8::Value> &args)
              { printArgs("[INFO] ", args); });

    // Set console on the global object
    global->Set(ctx, consoleKey, console).Check();
}

bool ScriptEngine::init()
{
    SE_LOGD("ScriptEngine::init() called\n");
    cleanup();
    SE_LOGD("Initializing V8, version: %s\n", v8::V8::GetVersion());
    ++_vmId;

    _engineThreadId = std::this_thread::get_id();
    // callbacks on init
    for (const auto &hook : _beforeInitHookArray)
    {
        hook();
    }
    _beforeInitHookArray.clear();
    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    _isolate = v8::Isolate::New(create_params);

    v8::HandleScope hs(_isolate);
    _isolate->Enter();

    _isolate->SetCaptureStackTraceForUncaughtExceptions(true, __jsbStackFrameLimit, v8::StackTrace::kOverview);

    _isolate->SetFatalErrorHandler(onFatalErrorCallback);
    _isolate->SetOOMErrorHandler(onOOMErrorCallback);
    _isolate->AddMessageListener(onMessageCallback);
    _isolate->SetPromiseRejectCallback(onPromiseRejectCallback);

    _context.Reset(_isolate, v8::Context::New(_isolate));
    _context.Get(_isolate)->Enter();

    NativePtrToObjectMap::init();
    // NonRefNativePtrCreatedByCtorMap::init();

    // Object::setup();
    // Class::setIsolate(_isolate);
    // Object::setIsolate(_isolate);
    v8::Local<v8::Object> global = _context.Get(_isolate)->Global();

    _globalObj.Reset(_isolate, global);
    // _globalObj->root();

    JsbUtils::SetProperty(_isolate, global, "window", _globalObj.Get(_isolate));
    _InstallConsole();
    // _globalObj->setProperty("scriptEngineType", se::Value("V8"));
    JsbUtils::SetProperty(_isolate, global, "scriptEngineType", JsbUtils::ToV8String(_isolate, "V8"));

    // TODO: expose GC function for testing, should be removed in production
    // _globalObj->defineFunction("log", __log);
    // _globalObj->defineFunction("forceGC", __forceGC);

    // _globalObj->getProperty(EXPOSE_GC, &_gcFuncValue);
    // if (_gcFuncValue.isObject() && _gcFuncValue.toObject()->isFunction())
    // {
    //     _gcFunc = _gcFuncValue.toObject();
    // }
    // else
    // {
    //     _gcFunc = nullptr;
    // }

    // __jsb_CCPrivateData_class = Class::create("__PrivateData", _globalObj, nullptr, nullptr);
    // __jsb_CCPrivateData_class->defineFinalizeFunction(privateDataFinalize);
    // __jsb_CCPrivateData_class->setCreateProto(false);
    // __jsb_CCPrivateData_class->install();

    _isValid = true;

    for (const auto &hook : _afterInitHookArray)
    {
        hook(_isolate, _globalObj.Get(_isolate));
    }
    _afterInitHookArray.clear();

    return _isValid;

    return true;
}

bool ScriptEngine::didStart()
{

    // v8::Isolate *isolate = getIsolate();
    // v8::HandleScope handle_scope(isolate);

    // v8::Local<v8::Value> result;
    // std::string script = "'V8 + Cocos2d running! Result: ' + (6 * 7); console.log('Hello from V8'); cc.Configuration.getInstance().setValue('testKey', 'testValue'); cc.log('Config testKey: ' + cc.Configuration.getInstance().getValue('testKey'));";
    // js->evalString(script.c_str(), script.length(), &result);

    // //     se::HandleObject performanceObj(se::Object::createPlainObject());
    // v8::Local<v8::Object> performanceObj = v8::Object::New(isolate);
    // //     performanceObj->defineFunction("now", _SE(js_performance_now));
    // JsbUtils::DefineFunction(performanceObj, "now", [](const v8::FunctionCallbackInfo<v8::Value> &args) -> void
    //                          {
    //         cocos2d::log("[JSB] performance.now() called");
    //         auto isolate = args.GetIsolate();
    //         auto now = std::chrono::high_resolution_clock::now();
    //         auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    //         args.GetReturnValue().Set(v8::Number::New(isolate, static_cast<double>(ms))); });
    // v8::Local<v8::Object> global = isolate->GetCurrentContext()->Global();
    // //     global->setProperty("performance", se::Value(performanceObj));
    // JsbUtils::SetProperty(isolate, global, "performance", performanceObj);

    // // cocos2d::log("[JSB] %s", result.As);

    // cocos2d::log("[JSB] Failed to start V8");

    // v8::Isolate *isolate = js->getIsolate();
    // v8::HandleScope handle_scope(isolate);
    // v8::Local<v8::Context> context = isolate->GetCurrentContext();
    // std::string script2 = "performance.now();";
    // v8::Local<v8::Value> result2;
    // js->evalString(script2.c_str(), script2.length(), &result2);
    // if (result2->IsNumber())
    // {
    //     double now = result2.As<v8::Number>()->Value();
    //     cocos2d::log("[JSB] performance.now() returned: %f", now);
    // }
    // runScript("test.js");
    // runScript("script/jsb_boot.js");

    return true;
}

bool ScriptEngine::start()
{
    SE_LOGD("ScriptEngine::start() called\n");
    if (!init())
        return false;

    v8::HandleScope hs(_isolate);

    // TODO: debugger
    //     if (isDebuggerEnabled())
    //     {
    // #if SE_ENABLE_INSPECTOR
    //         // V8 inspector stuff, most code are taken from NodeJS.
    //         _isolateData = node::CreateIsolateData(_isolate, uv_default_loop());
    //         _env = node::CreateEnvironment(_isolateData, _context.Get(_isolate), 0, nullptr, 0, nullptr);

    //         node::DebugOptions options;
    //         options.set_wait_for_connect(_isWaitForConnect); // the program will be hung up until debug attach if _isWaitForConnect = true
    //         options.set_inspector_enabled(true);
    //         options.set_port((int)_debuggerServerPort);
    //         options.set_host_name(_debuggerServerAddr.c_str());
    //         bool ok = _env->inspector_agent()->Start(_platform, "", options);
    //         assert(ok);
    // #endif
    //     }
    //
    bool ok = true;
    _startTime = std::chrono::steady_clock::now();

    for (auto cb : _registerCallbackArray)
    {
        ok = cb(_globalObj.Get(_isolate));
        assert(ok);
        if (!ok)
            break;
        cb(_globalObj.Get(_isolate));
    }

    for (auto cb : _afterInitHookArray)
    {
        cb(_isolate, _globalObj.Get(_isolate));
    }

    // After ScriptEngine is started, _registerCallbackArray isn't needed. Therefore, clear it here.
    _registerCallbackArray.clear();
    this->didStart();
    return ok;
}

// v8::Local<v8::Script> ScriptEngine::compileScript(const std::string &path, v8::Local<v8::Object> global, v8::Isolate *isolate)
// {
// }

// v8::Local<v8::Script> ScriptEngine::getScript(const std::string &path) {}

bool ScriptEngine::runScript(const std::string &filePath, v8::Local<v8::Value> *rval)
{
    v8::HandleScope hs(_isolate);
    
    assert(!filePath.empty());

    cocos2d::FileUtils *futil = cocos2d::FileUtils::getInstance();
    std::string scriptBuffer;
    if (futil->isFileExist(filePath))
    {
        scriptBuffer = futil->getStringFromFile(filePath);
    }

    if (!scriptBuffer.empty())
    {
        return evalString(scriptBuffer.c_str(), scriptBuffer.length(), rval, filePath.c_str());
    }

    SE_LOGE("ScriptEngine::runScript script %s, buffer is empty!\n", filePath.c_str());
    return false;
}

void ScriptEngine::cleanup()
{
    SE_LOGD("ScriptEngine::cleanup() called\n");
    if (!_isValid)
        return;

    SE_LOGD("ScriptEngine::cleanup begin ...\n");
    _isInCleanup = true;

    {
        // AutoHandleScope hs;
        // for (const auto& hook : _beforeCleanupHookArray)
        // {
        //     hook();
        // }
        _beforeCleanupHookArray.clear();

        //             SAFE_DEC_REF(_globalObj);
        //             Object::cleanup();
        //             Class::cleanup();
        //             garbageCollect();

        //             __oldConsoleLog.setUndefined();
        //             __oldConsoleDebug.setUndefined();
        //             __oldConsoleInfo.setUndefined();
        //             __oldConsoleWarn.setUndefined();
        //             __oldConsoleError.setUndefined();
        //             __oldConsoleAssert.setUndefined();

        // #if SE_ENABLE_INSPECTOR
        //             if (_isolateData != nullptr)
        //             {
        //                 node::FreeIsolateData(_isolateData);
        //                 _isolateData = nullptr;
        //             }

        //             if (_env != nullptr)
        //             {
        //                 _env->inspector_agent()->Stop();
        //                 _env->CleanupHandles();
        //                 node::FreeEnvironment(_env);
        //                 _env = nullptr;
        //             }
        // #endif

        _context.Get(_isolate)->Exit();
        _context.Reset();
        _isolate->Exit();
    }
    _globalObj.Reset();
    _context.Reset();
    _isolate->Dispose();

    _isolate = nullptr;
    _isValid = false;

    _registerCallbackArray.clear();

    for (const auto &hook : _afterCleanupHookArray)
    {
        hook();
    }
    _afterCleanupHookArray.clear();

    _isInCleanup = false;
    // NativePtrToObjectMap::destroy();
    // NonRefNativePtrCreatedByCtorMap::destroy();
    // _gcFunc = nullptr;
    SE_LOGD("ScriptEngine::cleanup end ...\n");
}

bool ScriptEngine::evalString(const char *script, size_t length /* = -1 */, v8::Local<v8::Value> *ret /* = nullptr */, const char *fileName /* = nullptr */)
{
    if (_engineThreadId != std::this_thread::get_id())
    {
        // `evalString` should run in main thread
        assert(false);
        return false;
    }

    assert(script != nullptr);
    if (length < 0)
        length = strlen(script);

    if (fileName == nullptr)
        fileName = "(no filename)";

    // Fix the source url is too long displayed in Chrome debugger.
    std::string sourceUrl = fileName;
    static const std::string prefixKey = "/temp/quick-scripts/";
    size_t prefixPos = sourceUrl.find(prefixKey);
    if (prefixPos != std::string::npos)
    {
        sourceUrl = sourceUrl.substr(prefixPos + prefixKey.length());
    }

    // It is needed, or will crash if invoked from non C++ context, such as invoked from objective-c context(for example, handler of UIKit).
    v8::EscapableHandleScope handle_scope(_isolate);

    std::string scriptStr(script, length);
    v8::MaybeLocal<v8::String> source = v8::String::NewFromUtf8(_isolate, scriptStr.c_str(), v8::NewStringType::kNormal);
    if (source.IsEmpty())
        return false;

    v8::MaybeLocal<v8::String> originStr = v8::String::NewFromUtf8(_isolate, sourceUrl.c_str(), v8::NewStringType::kNormal);
    if (originStr.IsEmpty())
        return false;

    v8::ScriptOrigin origin(_isolate, originStr.ToLocalChecked());
    v8::MaybeLocal<v8::Script> maybeScript = v8::Script::Compile(_context.Get(_isolate), source.ToLocalChecked(), &origin);

    bool success = false;

    if (!maybeScript.IsEmpty())
    {
        v8::TryCatch block(_isolate);

        v8::Local<v8::Script> v8Script = maybeScript.ToLocalChecked();
        v8::MaybeLocal<v8::Value> maybeResult = v8Script->Run(_context.Get(_isolate));

        if (!maybeResult.IsEmpty())
        {
            v8::Local<v8::Value> result = maybeResult.ToLocalChecked();

            if (!result->IsUndefined() && ret != nullptr)
            {
                *ret = handle_scope.Escape(result);
            }

            success = true;
        }

        if (block.HasCaught())
        {
            v8::Local<v8::Message> message = block.Message();
            SE_LOGE("ScriptEngine::evalString catch exception:\n");
            onMessageCallback(message, v8::Undefined(_isolate));
        }
    }

    if (!success)
    {
        SE_LOGE("ScriptEngine::evalString script %s, failed!\n", fileName);
    }
    return success;
}

v8::Local<v8::Object> ScriptEngine::getGlobalObject() const
{
    return _globalObj.Get(_isolate);
}
