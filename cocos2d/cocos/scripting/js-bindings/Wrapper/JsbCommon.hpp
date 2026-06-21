#pragma once
#include "v8.h"
#include "platform/CCSAXParser.h"

// extern JSClass  *jsb_cocos2d_Configuration_class;
// extern JSObject *jsb_cocos2d_Configuration_prototype;

// bool js_cocos2dx_Configuration_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Configuration_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Configuration(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_Configuration(v8::Isolate *isolate, v8::Local<v8::Object> global);

// extern JSClass  *jsb_cocos2d_Properties_class;
// extern JSObject *jsb_cocos2d_Properties_prototype;

// bool js_cocos2dx_Properties_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Properties_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Properties(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Properties_getVariable(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getString(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getLong(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getNamespace(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getPath(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getMat4(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_exists(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_setString(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getId(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_rewind(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_setVariable(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getBool(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getType(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getNextNamespace(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getInt(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getVec3(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getVec2(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getVec4(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getNextProperty(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getFloat(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_getQuaternionFromAxisAngle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_parseColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_parseVec3(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_parseAxisAngle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_parseVec2(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_createNonRefCounted(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Properties_parseVec4(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Device_class;
// extern JSObject *jsb_cocos2d_Device_prototype;

// void js_register_cocos2dx_Device(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_Device(v8::Isolate *isolate, v8::Local<v8::Object> global);
// bool js_cocos2dx_Device_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Device_finalize(JSContext *cx, JSObject *obj);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Device_setAccelerometerEnabled(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_setAccelerometerInterval(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_setKeepScreenOn(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_vibrate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_getDPI(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Application_class;
// extern JSObject *jsb_cocos2d_Application_prototype;

// bool js_cocos2dx_Application_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Application_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Application(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_Application(v8::Isolate *isolate, v8::Local<v8::Object> global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Application_getTargetPlatform(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Application_getCurrentLanguage(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Application_openURL(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Application_getVersion(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Application_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_CocosDenshion_SimpleAudioEngine_class;
// extern JSObject *jsb_CocosDenshion_SimpleAudioEngine_prototype;

// bool js_cocos2dx_SimpleAudioEngine_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_SimpleAudioEngine_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_SimpleAudioEngine(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_SimpleAudioEngine(v8::Isolate *isolate, v8::Local<v8::Object> global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_stopAllEffects(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_preloadEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_getEffectsVolume(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_pauseEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_playEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_playBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_resumeAllEffects(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_setEffectsVolume(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_stopEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_pauseAllEffects(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_unloadEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_resumeEffect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_end(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SimpleAudioEngine_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

void js_register_cocos2dx_SAXParser(v8::Isolate *isolate, v8::Local<v8::Object> global);

class __JSPlistDelegator : public cocos2d::SAXDelegator
{
public:
  static __JSPlistDelegator *getInstance()
  {
    static __JSPlistDelegator *pInstance = NULL;
    if (pInstance == NULL)
    {
      pInstance = new (std::nothrow) __JSPlistDelegator();
    }
    return pInstance;
  };

  ~__JSPlistDelegator();

  cocos2d::SAXParser *getParser();

  std::string parse(const std::string &path);
  std::string parseText(const std::string &text);

  // implement pure virtual methods of SAXDelegator
  void startElement(void *ctx, const char *name, const char **atts) override;
  void endElement(void *ctx, const char *name) override;
  void textHandler(void *ctx, const char *ch, size_t len) override;

private:
  cocos2d::SAXParser _parser;
  std::string _result;
  bool _isStoringCharacters;
  std::string _currentValue;
};