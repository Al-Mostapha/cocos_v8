#include "ScriptEngine.hpp"
#include <cstdio>

#define EXPOSE_GC "__jsb_gc__"

ScriptEngine *ScriptEngine::_instance = nullptr;

ScriptEngine *ScriptEngine::getInstance()
{
    if (!_instance)
        _instance = new ScriptEngine();
    return _instance;
}

ScriptEngine::ScriptEngine()
    : _platform(nullptr), _isolate(nullptr), _handleScope(nullptr), _globalObj(nullptr)
#if SE_ENABLE_INSPECTOR
      ,
      _env(nullptr), _isolateData(nullptr)
#endif
      ,
      _debuggerServerPort(0), _vmId(0), _isValid(false), _isGarbageCollecting(false), _isInCleanup(false), _isErrorHandleWorking(false)
{
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

void ScriptEngine::onOOMErrorCallback(const char *location, bool is_heap_oom)
{
    std::string errorStr = "[OOM ERROR] location: ";
    errorStr += location;
    std::string message;
    message = "is heap out of memory: ";
    if (is_heap_oom)
        message += "true";
    else
        message += "false";

    errorStr += ", " + message;
    SE_LOGE("%s\n", errorStr.c_str());
    getInstance()->callExceptionCallback(location, message.c_str(), "(no stack information)");
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
    Value resouceNameVal;
    internal::jsToSeValue(v8::Isolate::GetCurrent(), origin.ResourceName(), &resouceNameVal);
    Value line;
    internal::jsToSeValue(v8::Isolate::GetCurrent(), origin.ResourceLineOffset(), &line);
    Value column;
    internal::jsToSeValue(v8::Isolate::GetCurrent(), origin.ResourceColumnOffset(), &column);

    std::string location = resouceNameVal.toStringForce() + ":" + line.toStringForce() + ":" + column.toStringForce();

    std::string errorStr = msgVal.toString() + ", location: " + location;
    std::string stackStr = stackTraceToString(message->GetStackTrace());
    if (!stackStr.empty())
    {
        if (line.toInt32() == 0)
        {
            location = "(see stack)";
        }
        errorStr += "\nSTACK:\n" + stackStr;
    }
    SE_LOGE("ERROR: %s\n", errorStr.c_str());

    thiz->callExceptionCallback(location.c_str(), msgVal.toString().c_str(), stackStr.c_str());

    if (!thiz->_isErrorHandleWorking)
    {
        thiz->_isErrorHandleWorking = true;

        Value errorHandler;
        if (thiz->_globalObj && thiz->_globalObj->getProperty("__errorHandler", &errorHandler) && errorHandler.isObject() && errorHandler.toObject()->isFunction())
        {
            ValueArray args;
            args.push_back(resouceNameVal);
            args.push_back(line);
            args.push_back(msgVal);
            args.push_back(Value(stackStr));
            errorHandler.toObject()->call(args, thiz->_globalObj);
        }

        thiz->_isErrorHandleWorking = false;
    }
    else
    {
        SE_LOGE("ERROR: __errorHandler has exception\n");
    }
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

bool ScriptEngine::init()
{
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

    return true;
}

void ScriptEngine::cleanup()
{
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
    _isolate->Dispose();

    _isolate = nullptr;
    _globalObj = nullptr;
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

bool ScriptEngine::evalString(const char *script, std::string *result)
{
    if (!_isolate)
    {
        fprintf(stderr, "[JSB] evalString called before init()\n");
        return false;
    }

    v8::Isolate::Scope isolate_scope(_isolate);
    v8::HandleScope handle_scope(_isolate);
    v8::Local<v8::Context> ctx = v8::Local<v8::Context>::New(_isolate, _context);
    v8::Context::Scope context_scope(ctx);

    v8::TryCatch try_catch(_isolate);

    auto maybeSource = v8::String::NewFromUtf8(_isolate, script);
    if (maybeSource.IsEmpty())
    {
        fprintf(stderr, "[JSB] Failed to create source string\n");
        return false;
    }

    auto maybeScript = v8::Script::Compile(ctx, maybeSource.ToLocalChecked());
    if (maybeScript.IsEmpty())
    {
        v8::String::Utf8Value err(_isolate, try_catch.Exception());
        fprintf(stderr, "[JSB] Compile error: %s\n", *err);
        return false;
    }

    auto maybeResult = maybeScript.ToLocalChecked()->Run(ctx);
    if (try_catch.HasCaught())
    {
        v8::String::Utf8Value err(_isolate, try_catch.Exception());
        fprintf(stderr, "[JSB] Runtime error: %s\n", *err);
        return false;
    }

    if (result && !maybeResult.IsEmpty())
    {
        v8::String::Utf8Value utf8(_isolate, maybeResult.ToLocalChecked());
        *result = *utf8;
    }

    return true;
}
