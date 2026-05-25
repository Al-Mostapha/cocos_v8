#pragma once
#include "JsbBase.h"
#include "JsbConfig.h"
#include <memory>
#include <string>
#include <thread>
#include <unordered_map>
class Class;

extern Class *__jsb_CCPrivateData_class;

class ScriptEngine
{
public:
  static std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>> _registeredClasses;
  class FileOperationDelegate
  {
  public:
    FileOperationDelegate()
        : onGetDataFromFile(nullptr), onGetStringFromFile(nullptr), onCheckFileExist(nullptr), onGetFullPath(nullptr)
    {
    }

    /**
     *  @brief Tests whether delegate is valid.
     */
    bool isValid() const
    {
      return onGetDataFromFile != nullptr && onGetStringFromFile != nullptr && onCheckFileExist != nullptr && onGetFullPath != nullptr;
    }

    // path, buffer, buffer size
    std::function<void(const std::string &, const std::function<void(const uint8_t *, size_t)> &)> onGetDataFromFile;
    // path, return file string content.
    std::function<std::string(const std::string &)> onGetStringFromFile;
    // path
    std::function<bool(const std::string &)> onCheckFileExist;
    // path, return full path
    std::function<std::string(const std::string &)> onGetFullPath;
  };

  /**
   *  @brief Sets the delegate for file operation.
   *  @param delegate[in] The delegate instance for file operation.
   */
  void setFileOperationDelegate(const FileOperationDelegate &delegate);

  v8::Local<v8::Context> _getContext() const
  {
    return _context.Get(_isolate);
  }

  void clearException() {}
  /**
   *  @brief Gets the delegate for file operation.
   *  @return The delegate for file operation
   */
  const FileOperationDelegate &getFileOperationDelegate() const;

  static ScriptEngine *getInstance();
  static void destroyInstance();
  bool garbageCollect();

  bool start();

  bool didStart();

  void cleanup();

  v8::Local<v8::Script> compileScript(const std::string &path, v8::Local<v8::Object> global, v8::Isolate *isolate);

  v8::Local<v8::Script> getScript(const std::string &path);

  /**
   *  @brief Enables JavaScript debugger
   *  @param[in] serverAddr The address of debugger server.
   *  @param[in] isWait Whether wait debugger attach when loading.
   */
  void enableDebugger(const std::string &serverAddr, uint32_t port, bool isWait = false);

  /**
   *  @brief Main loop update trigger, it's need to invoked in main thread every frame.
   */
  void mainLoopUpdate();

  v8::Local<v8::Object> getGlobalObject() const;

  // Evaluate a JS string. Optionally writes the result to *result.
  // Returns false and logs on compile/runtime error.
  bool evalString(const char *scriptStr, size_t length = -1, v8::Local<v8::Value> *rval = nullptr, const char *fileName = nullptr);

  bool runScript(const std::string &filePath, v8::Local<v8::Value> *rval = nullptr);

  v8::Isolate *getIsolate() const { return _isolate; }
  // std::string stackTraceToString(v8::Local<v8::StackTrace> stackTrace);
  std::string getCurrentStackTrace();

  void addBeforeInitHook(const std::function<void()> &hook)
  {
    _beforeInitHookArray.push_back(hook);
  }

  void addAfterInitHook(const std::function<void(v8::Isolate *, v8::Local<v8::Object>)> &hook)
  {
    _afterInitHookArray.push_back(hook);
  }

  void addBeforeCleanupHook(const std::function<void()> &hook)
  {
    _beforeCleanupHookArray.push_back(hook);
  }

  void addAfterCleanupHook(const std::function<void()> &hook)
  {
    _afterCleanupHookArray.push_back(hook);
  }

  std::chrono::steady_clock::time_point getStartTime() const { return _startTime; }

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
  std::vector<std::function<void(v8::Isolate *, v8::Local<v8::Object>)>> _afterInitHookArray;
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
  FileOperationDelegate _fileOperationDelegate;
  std::function<void(const char *, const char *, const char *)> _nativeExceptionCallback = nullptr;
  std::function<void(const char *, const char *, const char *)> _jsExceptionCallback = nullptr;
};
