#pragma once
#include "JsbBase.h"
#include "JsbConfig.h"
#include <memory>
#include <string>
#include <thread>
#include <unordered_map>

#include "ui/CocosGUI.h"
#include "base/CCEventMouse.h"

class Class;

extern Class *__jsb_CCPrivateData_class;

class ScriptEngine : public cocos2d::ScriptEngineProtocol
{
public:
  static std::unordered_map<std::string, v8::Global<v8::FunctionTemplate>> _registeredClasses;

  v8::Local<v8::FunctionTemplate> getClassByName(const std::string &className)
  {
    v8::Isolate *isolate = getIsolate();
    v8::EscapableHandleScope handleScope(isolate);
    auto iter = _registeredClasses.find(className);
    if (iter != _registeredClasses.end())
      return handleScope.Escape(iter->second.Get(_isolate));

    assert(false);
    return v8::Local<v8::FunctionTemplate>();
  }
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

  void addRegisterCallback(const std::function<bool(v8::Local<v8::Object>)> &callback)
  {
    _registerCallbackArray.push_back(callback);
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
  bool _callFromScript;

  static ScriptEngine *_instance;
  FileOperationDelegate _fileOperationDelegate;
  std::function<void(const char *, const char *, const char *)> _nativeExceptionCallback = nullptr;
  std::function<void(const char *, const char *, const char *)> _jsExceptionCallback = nullptr;

  /// Overrides
public:
  /**@~english
   * Gets the script type, for ScriptingCore, it will return `cocos2d::kScriptTypeJavascript`
   * @return `cocos2d::kScriptTypeJavascript`
   */
  virtual cocos2d::ccScriptType getScriptType() override { return cocos2d::kScriptTypeJavascript; };

  /**
   * Reflect the retain relationship to script scope
   */
  virtual void retainScriptObject(cocos2d::Ref *owner, cocos2d::Ref *target) override;

  /**
   * Add the script object to root object
   */
  virtual void rootScriptObject(cocos2d::Ref *target) override;

  /**
   * Reflect the release relationship to script scope
   */
  virtual void releaseScriptObject(cocos2d::Ref *owner, cocos2d::Ref *target) override;

  /**
   * Remove the script object from root object
   */
  virtual void unrootScriptObject(cocos2d::Ref *target) override;

  /**
   * Release all children in script scope
   */
  virtual void releaseAllChildrenRecursive(cocos2d::Node *node) override;

  /**
   * Release all native refs for the given owner in script scope
   */
  virtual void releaseAllNativeRefs(cocos2d::Ref *owner) override;

  /**
   * @brief @~english Removes the C++ object's linked JavaScript proxy object from JavaScript context
   * @param obj @~english Object to be removed
   */
  virtual void removeScriptObjectByObject(cocos2d::Ref *obj) override;

  /**
   * @brief @~english Useless in ScriptingCore, please use evalString
   * @see evalString
   */
  virtual int executeString(const char *codes) override { return 0; }

  /**
   @brief Useless in ScriptingCore, please use runScript
   @param filename String object holding the filename of the script file that is to be executed
   */
  virtual int executeScriptFile(const char *filename) override { return 0; }

  /**
   @brief @~english Useless in ScriptingCore, please use executeFunctionWithOwner
   @param functionName String object holding the name of the function, in the global script environment, that is to be executed.
   @return The integer value returned from the script function.
   */
  virtual int executeGlobalFunction(const char *functionName) override;

  virtual int sendEvent(cocos2d::ScriptEvent *message) override;

  virtual bool parseConfig(ConfigType type, const std::string &str) override;

  /**
   * @brief @~english Useless in ScriptingCore
   * @return @~english false
   */
  virtual bool handleAssert(const char *msg) override { return false; }

  virtual void setCalledFromScript(bool callFromScript) override { _callFromScript = callFromScript; };
  virtual bool isCalledFromScript() override { return _callFromScript; };

  /**
   * Roots the associated JSObj.
   * The GC won't collected rooted objects. This function is only called
   * when compiled with CC_ENABLE_GC_FOR_NATIVE_OBJECTS=1
   */
  virtual void rootObject(cocos2d::Ref *ref) override;
  /**
   * Unroots the associated JSObj.
   * The GC will collect this object the next time the GC
   * is called.
   * This function is only called when compiled with CC_ENABLE_GC_FOR_NATIVE_OBJECTS=1
   */
  virtual void unrootObject(cocos2d::Ref *ref) override;

  /** Remove proxy for a native object
   */
  virtual void removeObjectProxy(cocos2d::Ref *obj) override;

  /**
   * Calls the Garbage Collector
   */
  virtual bool garbageCollect() override;

  bool executeFunctionWithOwner(v8::Local<v8::Object> owner, const char *name, int argc, v8::Local<v8::Value> args[], v8::Local<v8::Value> *retVal);
  void restartVM();

  int handleNodeEvent(void *data);
  int handleActionEvent(void *data);
  int handleComponentEvent(void *data);

  bool handleTouchesEvent(void *nativeObj, cocos2d::EventTouch::EventCode eventCode, const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
  bool handleTouchesEvent(void *nativeObj, cocos2d::EventTouch::EventCode eventCode, const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event, v8::Local<v8::Value> jsvalRet);

  bool handleTouchEvent(void *nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch *touch, cocos2d::Event *event);
  bool handleTouchEvent(void *nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch *touch, cocos2d::Event *event, v8::Local<v8::Value> jsvalRet);

  bool handleMouseEvent(void *nativeObj, cocos2d::EventMouse::MouseEventType eventType, cocos2d::Event *event);
  bool handleMouseEvent(void *nativeObj, cocos2d::EventMouse::MouseEventType eventType, cocos2d::Event *event, v8::Local<v8::Value> jsvalRet);

  bool handleKeyboardEvent(void *nativeObj, cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed, cocos2d::Event *event);
  bool handleFocusEvent(void *nativeObj, cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus);


  bool isFunctionOverridedInJS(v8::Local<v8::Object> jsObj, const char *functionName);

    /**
   * @brief @~english Pause scheduled tasks and actions for an object proxy.
   * @param p @~english The object proxy
   */
  void pauseSchedulesAndActions(v8::Local<v8::Value> p);
  /**
   * @brief @~english Resume scheduled tasks and actions for an object proxy.
   * @param p @~english The object proxy
   */
  void resumeSchedulesAndActions(v8::Local<v8::Value> p);
  /**
   * @brief @~english Cleanup scheduled tasks and actions for an object proxy.
   * @param p @~english The object proxy
   */
  void cleanupSchedulesAndActions(v8::Local<v8::Value> p);
};
