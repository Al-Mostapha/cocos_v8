#pragma once
#include "JsbBase.h"
#include "JsbConfig.h"
#include <memory>
#include <string>
#include <thread>

class ScriptEngine
{
public:
  static ScriptEngine *getInstance();
  static void destroyInstance();

  bool start();

  void cleanup();

  // Evaluate a JS string. Optionally writes the result to *result.
  // Returns false and logs on compile/runtime error.
  bool evalString(const char *script, std::string *result = nullptr);

  v8::Isolate *getIsolate() const { return _isolate; }
  // std::string stackTraceToString(v8::Local<v8::StackTrace> stackTrace);
  std::string getCurrentStackTrace();

private:
  ScriptEngine();
  ~ScriptEngine();
  bool init();

  static void onFatalErrorCallback(const char *location, const char *message);
  static void onOOMErrorCallback(const char *location,
                                 const v8::OOMDetails &details);
  static void onMessageCallback(v8::Local<v8::Message> message, v8::Local<v8::Value> data);
  static void onPromiseRejectCallback(v8::PromiseRejectMessage msg);
  void callExceptionCallback(const char *, const char *, const char *);

  void _InstallConsole();

  v8::Platform *_platform;
  v8::Isolate *_isolate = nullptr;
  v8::Global<v8::Context> _context;
  v8::HandleScope *_handleScope;

  std::chrono::steady_clock::time_point _startTime;
  std::vector<std::function<bool(v8::Local<v8::Object>)>> _registerCallbackArray;
  std::vector<std::function<void()>> _beforeInitHookArray;
  std::vector<std::function<void()>> _afterInitHookArray;
  std::vector<std::function<void()>> _beforeCleanupHookArray;
  std::vector<std::function<void()>> _afterCleanupHookArray;

  std::thread::id _engineThreadId;

  std::string _debuggerServerAddr;
  uint32_t _debuggerServerPort;
  bool _isWaitForConnect;

  uint32_t _vmId;
  v8::Global<v8::Object> _globalObj;

  bool _isValid;
  bool _isGarbageCollecting;
  bool _isInCleanup;
  bool _isErrorHandleWorking;

  static ScriptEngine *_instance;
  std::function<void(const char *, const char *, const char *)> _nativeExceptionCallback = nullptr;
  std::function<void(const char *, const char *, const char *)> _jsExceptionCallback = nullptr;
};
