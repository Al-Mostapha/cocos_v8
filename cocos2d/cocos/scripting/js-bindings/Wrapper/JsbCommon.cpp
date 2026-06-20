#include "JsbConfig.h"
#include "HelperMacros.h"
#include "JsbUtils.h"
#include "JsbCommon.hpp"
#include "base/CCConfiguration.h"
#include "platform/CCDevice.h"
#include "platform/CCSAXParser.h"
#include "platform/CCFileUtils.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"

using CocosDenshion::SimpleAudioEngine;

// JSClass  *jsb_cocos2d_Configuration_class;
// JSObject *jsb_cocos2d_Configuration_prototype;

// bool js_cocos2dx_Configuration_supportsPVRTC(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsPVRTC(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();

  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsPVRTC : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsPVRTC : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsPVRTC();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsPVRTC();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsPVRTC : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsPVRTC : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
  return;
}

// }
// bool js_cocos2dx_Configuration_supportsOESDepth24(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsOESDepth24(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsOESDepth24 : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsOESDepth24 : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsOESDepth24();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsOESDepth24();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsOESDepth24 : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsOESDepth24 : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
  return;
}

// bool js_cocos2dx_Configuration_getMaxModelviewStackDepth(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxModelviewStackDepth(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getMaxModelviewStackDepth : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getMaxModelviewStackDepth : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getMaxModelviewStackDepth();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getMaxModelviewStackDepth();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getMaxModelviewStackDepth : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxModelviewStackDepth : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_supportsShareableVAO(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsShareableVAO(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsShareableVAO : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsShareableVAO : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsShareableVAO();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsShareableVAO();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsShareableVAO : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsShareableVAO : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
  // }
}
// bool js_cocos2dx_Configuration_supportsBGRA8888(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsBGRA8888(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  //
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsBGRA8888 : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsBGRA8888 : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsBGRA8888();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsBGRA8888();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsBGRA8888 : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsBGRA8888 : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_checkForGLExtension(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_checkForGLExtension(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_checkForGLExtension : Invalid Native Object");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_checkForGLExtension : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_checkForGLExtension : Error processing arguments");
  //         bool ret = cobj->checkForGLExtension(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    SE_PRECONDITION2(!arg0.empty(), "js_cocos2dx_Configuration_checkForGLExtension : Error processing arguments");
    bool ret = cobj->checkForGLExtension(arg0);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_checkForGLExtension : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_checkForGLExtension : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}
// bool js_cocos2dx_Configuration_supportsATITC(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsATITC(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsATITC : Invalid Native Object");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsATITC : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsATITC();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsATITC();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsATITC : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsATITC : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}
// bool js_cocos2dx_Configuration_supportsNPOT(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsNPOT(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Local<v8::Object> obj = args.This();
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)obj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsNPOT : Invalid Native Object");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsNPOT : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsNPOT();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsNPOT();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsNPOT : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_init : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_init : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->init();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->init();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_init : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_init : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}
// bool js_cocos2dx_Configuration_getAnimate3DQuality(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getAnimate3DQuality(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getAnimate3DQuality : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getAnimate3DQuality : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getAnimate3DQuality();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getAnimate3DQuality();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_getAnimate3DQuality : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_getMaxSupportPointLightInShader(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxSupportPointLightInShader(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getMaxSupportPointLightInShader : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getMaxSupportPointLightInShader();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getMaxSupportPointLightInShader();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getMaxSupportPointLightInShader : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxSupportPointLightInShader : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_getMaxTextureSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxTextureSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getMaxTextureSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getMaxTextureSize : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getMaxTextureSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getMaxTextureSize();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getMaxTextureSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxTextureSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_setValue(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_setValue(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_setValue : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_setValue : Invalid Native Object");
  //     if (argc == 2) {
  //         std::string arg0;
  //         cocos2d::Value arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ccvalue(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_setValue : Error processing arguments");
  //         cobj->setValue(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    cocos2d::Value arg1;
    bool ok = JsbUtils::jsval_to_ccvalue(args.GetIsolate(), args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Configuration_setValue : Error processing arguments");
    cobj->setValue(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_setValue : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_setValue : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_Configuration_getMaxSupportSpotLightInShader(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxSupportSpotLightInShader(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getMaxSupportSpotLightInShader : Invalid Native Object");
  if (args.Length() == 0)
  {
    int ret = cobj->getMaxSupportSpotLightInShader();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getMaxSupportSpotLightInShader : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getMaxSupportSpotLightInShader();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxSupportSpotLightInShader : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_supportsETC(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsETC(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsETC : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsETC : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsETC();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsETC();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsETC : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_getMaxSupportDirLightInShader(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxSupportDirLightInShader(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getMaxSupportDirLightInShader : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getMaxSupportDirLightInShader : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getMaxSupportDirLightInShader();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getMaxSupportDirLightInShader();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxSupportDirLightInShader : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getMaxSupportDirLightInShader : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_loadConfigFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_loadConfigFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_loadConfigFile : Invalid Native Object");
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    SE_PRECONDITION2(!arg0.empty(), "js_cocos2dx_Configuration_loadConfigFile : Error processing arguments");
    cobj->loadConfigFile(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_loadConfigFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_loadConfigFile : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_loadConfigFile : Error processing arguments");
  //         cobj->loadConfigFile(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_loadConfigFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Configuration_supportsDiscardFramebuffer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsDiscardFramebuffer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsDiscardFramebuffer : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsDiscardFramebuffer : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsDiscardFramebuffer();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsDiscardFramebuffer();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsDiscardFramebuffer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsDiscardFramebuffer : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_supportsOESPackedDepthStencil(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsOESPackedDepthStencil(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsOESPackedDepthStencil : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsOESPackedDepthStencil();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsOESPackedDepthStencil();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsOESPackedDepthStencil : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsOESPackedDepthStencil : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_supportsS3TC(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsS3TC(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsS3TC : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsS3TC : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsS3TC();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsS3TC();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsS3TC : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsS3TC : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// }
// bool js_cocos2dx_Configuration_getInfo(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getInfo(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getInfo : Invalid Native Object");
  if (args.Length() == 0)
  {
    std::string ret = cobj->getInfo();
    args.GetReturnValue().Set(JsbUtils::ToV8String(args.GetIsolate(), ret));
    return;
  }
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getInfo : Invalid Native Object");
  //     if (argc == 0) {
  //         std::string ret = cobj->getInfo();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getInfo : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getInfo : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_getMaxTextureUnits(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getMaxTextureUnits(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, false, "js_cocos2dx_Configuration_getMaxTextureUnits : Invalid Native Object");
  //     if (argc == 0) {

  //     }
  if (args.Length() == 0)
  {
    //         int ret = cobj->getMaxTextureUnits();
    int ret = cobj->getMaxTextureUnits();
    //         JS::RootedValue jsret(cx);
    //         jsret = int32_to_jsval(cx, ret);
    v8::Local<v8::Integer> jsret = v8::Integer::New(args.GetIsolate(), ret);
    //         args.rval().set(jsret);
    args.GetReturnValue().Set(jsret);
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getMaxTextureUnits : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getMaxTextureUnits : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// }
// bool js_cocos2dx_Configuration_getValue(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getValue(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *iso = args.GetIsolate();
  v8::HandleScope handle_scope(iso);
  v8::Local<v8::Context> ctx = iso->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getValue : Invalid Native Object");
  //     if (argc == 1) {

  //     }
  if (args.Length() == 1)
  {
    //         std::string arg0;
    std::string arg0 = JsbUtils::FromV8String(iso, args[0]);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_getValue : Error processing arguments");
    //         const cocos2d::Value& ret = cobj->getValue(arg0);
    const cocos2d::Value &ret = cobj->getValue(arg0);
    //         JS::RootedValue jsret(cx);
    //         jsret = ccvalue_to_jsval(cx, ret);
    v8::Local<v8::Value> jsret = JsbUtils::ccvalue_to_jsval(iso, ret);
    //         args.rval().set(jsret);
    args.GetReturnValue().Set(jsret);
    //         return true;
    return;
  }
  else if (args.Length() == 2)
  {
    //         std::string arg0;
    //         cocos2d::Value arg1;
    cocos2d::Value arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string arg0 = JsbUtils::FromV8String(iso, args[0]);
    //         ok &= jsval_to_ccvalue(cx, args.get(1), &arg1);
    bool ok = JsbUtils::jsval_to_ccvalue(iso, args[1], &arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_getValue : Error processing arguments");
    SE_PRECONDITION2(ok, "js_cocos2dx_Configuration_getValue : Error processing arguments");
    //         const cocos2d::Value& ret = cobj->getValue(arg0, arg1);
    const cocos2d::Value &ret = cobj->getValue(arg0, arg1);
    //         JS::RootedValue jsret(cx);
    const v8::Local<v8::Value> jsret = JsbUtils::ccvalue_to_jsval(iso, ret);
    //         jsret = ccvalue_to_jsval(cx, ret);
    args.GetReturnValue().Set(jsret);
    //         args.rval().set(jsret);
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getValue : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_getValue : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Configuration_gatherGPUInfo(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_gatherGPUInfo(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_gatherGPUInfo : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_gatherGPUInfo : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->gatherGPUInfo();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->gatherGPUInfo();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_gatherGPUInfo : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_gatherGPUInfo : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_supportsMapBuffer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_supportsMapBuffer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsMapBuffer : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_supportsMapBuffer : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->supportsMapBuffer();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->supportsMapBuffer();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsMapBuffer : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Configuration_supportsMapBuffer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_getInfoAsMap(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getInfoAsMap(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
  cocos2d::Configuration *cobj = (cocos2d::Configuration *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getInfoAsMap : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Configuration_getInfoAsMap : Invalid Native Object");
  assert(false);
  //     if (argc == 0) {
  //         const cocos2d::ValueMap& ret = cobj->getInfoAsMap();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccvaluemap_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getInfoAsMap : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Configuration_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_destroyInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {
  //         cocos2d::Configuration::destroyInstance();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_Configuration_destroyInstance : wrong number of arguments");
  //     return false;
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  if (args.Length() == 0)
  {
    cocos2d::Configuration::destroyInstance();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_destroyInstance : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Configuration_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Configuration_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  if (args.Length() == 0)
  {
    cocos2d::Configuration *ret = cocos2d::Configuration::getInstance();
    if (ret)
    {
      v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(isolate));
    }
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Configuration_getInstance : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// void js_register_cocos2dx_Configuration(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_Configuration(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  //     jsb_cocos2d_Configuration_class = (JSClass *)calloc(1, sizeof(JSClass));
  v8::Local<v8::FunctionTemplate> tpl = JsbUtils::CreateClass(isolate, "Configuration", nullptr);

  //     jsb_cocos2d_Configuration_class->name = "Configuration";
  //     jsb_cocos2d_Configuration_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Configuration_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Configuration_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Configuration_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Configuration_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Configuration_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Configuration_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Configuration_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  tpl->PrototypeTemplate()->Set(isolate, "supportsPVRTC", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsPVRTC));
  tpl->PrototypeTemplate()->Set(isolate, "supportsATITC", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsATITC));
  tpl->PrototypeTemplate()->Set(isolate, "supportsNPOT", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsNPOT));
  tpl->PrototypeTemplate()->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_init));
  tpl->PrototypeTemplate()->Set(isolate, "getAnimate3DQuality", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getAnimate3DQuality));
  tpl->PrototypeTemplate()->Set(isolate, "getMaxSupportPointLightInShader", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxSupportPointLightInShader));
  tpl->PrototypeTemplate()->Set(isolate, "getMaxTextureSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxTextureSize));
  tpl->PrototypeTemplate()->Set(isolate, "setValue", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_setValue));
  tpl->PrototypeTemplate()->Set(isolate, "getMaxSupportSpotLightInShader", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxSupportSpotLightInShader));
  tpl->PrototypeTemplate()->Set(isolate, "supportsETC", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsETC));
  tpl->PrototypeTemplate()->Set(isolate, "getMaxSupportDirLightInShader", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxSupportDirLightInShader));
  tpl->PrototypeTemplate()->Set(isolate, "loadConfigFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_loadConfigFile));
  tpl->PrototypeTemplate()->Set(isolate, "supportsDiscardFramebuffer", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsDiscardFramebuffer));
  tpl->PrototypeTemplate()->Set(isolate, "supportsOESPackedDepthStencil", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsOESPackedDepthStencil));
  tpl->PrototypeTemplate()->Set(isolate, "supportsS3TC", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsS3TC));
  tpl->PrototypeTemplate()->Set(isolate, "getInfo", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInfo));
  tpl->PrototypeTemplate()->Set(isolate, "getMaxTextureUnits", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxTextureUnits));
  tpl->PrototypeTemplate()->Set(isolate, "getValue", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getValue));
  tpl->PrototypeTemplate()->Set(isolate, "gatherGPUInfo", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_gatherGPUInfo));
  tpl->PrototypeTemplate()->Set(isolate, "supportsMapBuffer", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsMapBuffer));
  tpl->PrototypeTemplate()->Set(isolate, "getInfoAsMap", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInfoAsMap));
  tpl->Set(isolate, "destroyInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_destroyInstance));
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInstance));

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END
  //     };

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("supportsPVRTC", js_cocos2dx_Configuration_supportsPVRTC, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsOESDepth24", js_cocos2dx_Configuration_supportsOESDepth24, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxModelviewStackDepth", js_cocos2dx_Configuration_getMaxModelviewStackDepth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsShareableVAO", js_cocos2dx_Configuration_supportsShareableVAO, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsBGRA8888", js_cocos2dx_Configuration_supportsBGRA8888, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("checkForGLExtension", js_cocos2dx_Configuration_checkForGLExtension, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsATITC", js_cocos2dx_Configuration_supportsATITC, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsNPOT", js_cocos2dx_Configuration_supportsNPOT, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("init", js_cocos2dx_Configuration_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getAnimate3DQuality", js_cocos2dx_Configuration_getAnimate3DQuality, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxSupportPointLightInShader", js_cocos2dx_Configuration_getMaxSupportPointLightInShader, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxTextureSize", js_cocos2dx_Configuration_getMaxTextureSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("setValue", js_cocos2dx_Configuration_setValue, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxSupportSpotLightInShader", js_cocos2dx_Configuration_getMaxSupportSpotLightInShader, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsETC", js_cocos2dx_Configuration_supportsETC, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxSupportDirLightInShader", js_cocos2dx_Configuration_getMaxSupportDirLightInShader, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("loadConfigFile", js_cocos2dx_Configuration_loadConfigFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsDiscardFramebuffer", js_cocos2dx_Configuration_supportsDiscardFramebuffer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsOESPackedDepthStencil", js_cocos2dx_Configuration_supportsOESPackedDepthStencil, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsS3TC", js_cocos2dx_Configuration_supportsS3TC, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("dumpInfo", js_cocos2dx_Configuration_getInfo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getMaxTextureUnits", js_cocos2dx_Configuration_getMaxTextureUnits, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getValue", js_cocos2dx_Configuration_getValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("gatherGPUInfo", js_cocos2dx_Configuration_gatherGPUInfo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("supportsMapBuffer", js_cocos2dx_Configuration_supportsMapBuffer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getInfoAsMap", js_cocos2dx_Configuration_getInfoAsMap, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FS_END
  //     };

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("destroyInstance", js_cocos2dx_Configuration_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getInstance", js_cocos2dx_Configuration_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FS_END
  //     };

  //     jsb_cocos2d_Configuration_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_Configuration_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Configuration_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Configuration"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "Configuration"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Configuration>(cx, jsb_cocos2d_Configuration_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::Configuration).name(), &tpl);
  JsbUtils::BindJsClass("Configuration", global, tpl);
}

// bool js_cocos2dx_Device_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Device_finalize(JSContext *cx, JSObject *obj);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Device_setAccelerometerEnabled(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_setAccelerometerInterval(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_setKeepScreenOn(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_vibrate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Device_getDPI(JSContext *cx, uint32_t argc, jsval *vp);
// void js_register_cocos2dx_Device(JSContext *cx, JS::HandleObject global);

// bool js_cocos2dx_Device_setAccelerometerEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Device_setAccelerometerEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Device_setAccelerometerEnabled : Error processing arguments");
  //         cocos2d::Device::setAccelerometerEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cocos2d::Device::setAccelerometerEnabled(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Device_setAccelerometerEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     JS_ReportError(cx, "js_cocos2dx_Device_setAccelerometerEnabled : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Device_setAccelerometerInterval(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Device_setAccelerometerInterval(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Device_setAccelerometerInterval : Error processing arguments");
  //         cocos2d::Device::setAccelerometerInterval(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cocos2d::Device::setAccelerometerInterval(arg0);
      args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
      return;
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Device_setAccelerometerInterval : Error processing arguments");
    }
  }
  //     JS_ReportError(cx, "js_cocos2dx_Device_setAccelerometerInterval : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Device_setAccelerometerInterval : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Device_setKeepScreenOn(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Device_setKeepScreenOn(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Device_setKeepScreenOn : Error processing arguments");
  //         cocos2d::Device::setKeepScreenOn(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    v8::Isolate *isolate = args.GetIsolate();
    bool arg0 = args[0]->BooleanValue(isolate);
    cocos2d::Device::setKeepScreenOn(arg0);
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Device_setKeepScreenOn : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     JS_ReportError(cx, "js_cocos2dx_Device_setKeepScreenOn : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Device_vibrate(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Device_vibrate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Device_vibrate : Error processing arguments");
  //         cocos2d::Device::vibrate(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cocos2d::Device::vibrate(arg0);
      args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
      return;
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Device_vibrate : Error processing arguments");
    }
  }
  //     JS_ReportError(cx, "js_cocos2dx_Device_vibrate : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Device_getDPI(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Device_getDPI(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {

  //         int ret = cocos2d::Device::getDPI();
  //         jsval jsret = JSVAL_NULL;
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cocos2d::Device::getDPI();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Device_getDPI : wrong number of arguments");
}

// void js_register_cocos2dx_Device(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_Device(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  //     jsb_cocos2d_Device_class = (JSClass *)calloc(1, sizeof(JSClass));
  v8::Local<v8::FunctionTemplate> tpl = JsbUtils::CreateClass(isolate, "Device", nullptr);
  JsbUtils::RegisterV8Class(typeid(cocos2d::Device).name(), &tpl);
  JsbUtils::BindJsClass("Device", global, tpl);
  //     jsb_cocos2d_Device_class->name = "Device";
  //     jsb_cocos2d_Device_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Device_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Device_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Device_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Device_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Device_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Device_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Device_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END
  //     };

  //     static JSFunctionSpec funcs[] = {
  //         JS_FS_END
  //     };

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("setAccelerometerEnabled", js_cocos2dx_Device_setAccelerometerEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setAccelerometerEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Device_setAccelerometerEnabled));
  //         JS_FN("setAccelerometerInterval", js_cocos2dx_Device_setAccelerometerInterval, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setAccelerometerInterval", v8::FunctionTemplate::New(isolate, js_cocos2dx_Device_setAccelerometerInterval));
  //         JS_FN("setKeepScreenOn", js_cocos2dx_Device_setKeepScreenOn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setKeepScreenOn", v8::FunctionTemplate::New(isolate, js_cocos2dx_Device_setKeepScreenOn));
  //         JS_FN("vibrate", js_cocos2dx_Device_vibrate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "vibrate", v8::FunctionTemplate::New(isolate, js_cocos2dx_Device_vibrate));
  //         JS_FN("getDPI", js_cocos2dx_Device_getDPI, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDPI", v8::FunctionTemplate::New(isolate, js_cocos2dx_Device_getDPI));
  //         JS_FS_END
  //     };

  //     jsb_cocos2d_Device_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_Device_class,
  //         dummy_constructor<cocos2d::Device>, 0, // no constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Device_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Device"));
  //     JS_SetProperty(cx, proto, "_className", className);
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  //     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Device>(cx, jsb_cocos2d_Device_class, proto, JS::NullPtr());
}

// JSClass *jsb_CocosDenshion_SimpleAudioEngine_class;
// JSObject *jsb_CocosDenshion_SimpleAudioEngine_prototype;

// bool js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         const char *arg0 = nullptr;
  //         std::string arg0_tmp;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
  std::string musicFile = JsbUtils::FromV8String(isolate, args[0]);
  //         arg0 = arg0_tmp.c_str();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic : Error processing arguments");
  //         cobj->preloadBackgroundMusic(arg0);
  cobj->preloadBackgroundMusic(musicFile.c_str());
  //         args.rval().setUndefined();

  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->stopBackgroundMusic();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->stopBackgroundMusic();
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    bool releaseData = args[0]->BooleanValue(isolate);
    cobj->stopBackgroundMusic(releaseData);
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_stopAllEffects(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_stopAllEffects(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_stopAllEffects : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_stopAllEffects : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() == 0)
  {
    cobj->stopAllEffects();
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }
  //         cobj->stopAllEffects();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_stopAllEffects : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_stopAllEffects : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getBackgroundMusicVolume();
  double ret = cobj->getBackgroundMusicVolume();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->resumeBackgroundMusic();
  cobj->resumeBackgroundMusic();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume : Error processing arguments");
  //         cobj->setBackgroundMusicVolume(arg0);
  cobj->setBackgroundMusicVolume(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_preloadEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_preloadEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_preloadEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_preloadEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_preloadEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         const char *arg0 = nullptr;
  //         std::string arg0_tmp;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
  std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
  //         arg0 = arg0_tmp.c_str();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_preloadEffect : Error processing arguments");
  //         cobj->preloadEffect(arg0);
  cobj->preloadEffect(effectFile.c_str());
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_preloadEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isBackgroundMusicPlaying();
  bool ret = cobj->isBackgroundMusicPlaying();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_getEffectsVolume(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_getEffectsVolume(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_getEffectsVolume : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_getEffectsVolume : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_getEffectsVolume : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getEffectsVolume();
  double ret = cobj->getEffectsVolume();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_getEffectsVolume : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->willPlayBackgroundMusic();
  bool ret = cobj->willPlayBackgroundMusic();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_pauseEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_pauseEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_pauseEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_pauseEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_pauseEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         unsigned int arg0 = 0;
  //         ok &= jsval_to_uint32(cx, args.get(0), &arg0);
  int sec = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_pauseEffect : Error processing arguments");
  //         cobj->pauseEffect(arg0);
  cobj->pauseEffect(sec);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_pauseEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_playEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_playEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_playEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    //         const char *arg0 = nullptr;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Error processing arguments");
    //         unsigned int ret = cobj->playEffect(arg0);
    unsigned int ret = cobj->playEffect(effectFile.c_str());
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    //         JS::RootedValue jsret(cx);
    //         jsret = uint32_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    return;
  }
  else if (args.Length() == 2)
  {
    //         const char *arg0 = nullptr;
    //         bool arg1;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    //         arg1 = JS::ToBoolean(args.get(1));
    bool loop = args[1]->BooleanValue(isolate);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Error processing arguments");
    //         unsigned int ret = cobj->playEffect(arg0, arg1);
    unsigned int ret = cobj->playEffect(effectFile.c_str(), loop);
    //         JS::RootedValue jsret(cx);
    //         jsret = uint32_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    //         return true;
    return;
  }
  else if (args.Length() == 3)
  {
    //         const char *arg0 = nullptr;
    //         bool arg1;
    //         double arg2 = 0;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    bool loop = args[1]->BooleanValue(isolate);
    //         arg1 = JS::ToBoolean(args.get(1));
    float pitch = args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Error processing arguments");
    //         unsigned int ret = cobj->playEffect(arg0, arg1, arg2);
    unsigned int ret = cobj->playEffect(effectFile.c_str(), loop, pitch);
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    //         JS::RootedValue jsret(cx);
    //         jsret = uint32_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
  }
  else if (args.Length() == 4)
  {
    //         const char *arg0 = nullptr;
    //         bool arg1;
    //         double arg2 = 0;
    //         double arg3 = 0;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    //         arg1 = JS::ToBoolean(args.get(1));
    bool loop = args[1]->BooleanValue(isolate);
    float pitch = args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    float pan = args[3]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
    //         ok &= JS::ToNumber(cx, args.get(3), &arg3) && !std::isnan(arg3);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Error processing arguments");
    //         unsigned int ret = cobj->playEffect(arg0, arg1, arg2, arg3);
    unsigned int ret = cobj->playEffect(effectFile.c_str(), loop, pitch, pan);
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    //         JS::RootedValue jsret(cx);
    //         jsret = uint32_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
  }
  else if (args.Length() == 5)
  {
    //         const char *arg0 = nullptr;
    //         bool arg1;
    //         double arg2 = 0;
    //         double arg3 = 0;
    //         double arg4 = 0;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    //         arg1 = JS::ToBoolean(args.get(1));
    bool loop = args[1]->BooleanValue(isolate);
    float pitch = args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    float pan = args[3]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    float gain = args[4]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
    //         ok &= JS::ToNumber(cx, args.get(3), &arg3) && !std::isnan(arg3);
    //         ok &= JS::ToNumber(cx, args.get(4), &arg4) && !std::isnan(arg4);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playEffect : Error processing arguments");
    //         unsigned int ret = cobj->playEffect(arg0, arg1, arg2, arg3, arg4);
    unsigned int ret = cobj->playEffect(effectFile.c_str(), loop, pitch, pan, gain);
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    //         JS::RootedValue jsret(cx);
    //         jsret = uint32_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_playEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_playEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}
// bool js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->rewindBackgroundMusic();
  cobj->rewindBackgroundMusic();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_playBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_playBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {

    //         const char *arg0 = nullptr;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string musicFile = JsbUtils::FromV8String(isolate, args[0]);
    //         arg0 = arg0_tmp.c_str();
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : Error processing arguments");
    //         cobj->playBackgroundMusic(arg0);
    cobj->playBackgroundMusic(musicFile.c_str());
    //         args.rval().setUndefined();
    return;
    //         return true;
  }

  if (args.Length() == 2)
  {
    //         const char *arg0 = nullptr;
    //         bool arg1;
    //         std::string arg0_tmp;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
    std::string musicFile = JsbUtils::FromV8String(isolate, args[0]);
    bool loop = args[1]->BooleanValue(isolate);
    //         arg0 = arg0_tmp.c_str();
    //         arg1 = JS::ToBoolean(args.get(1));
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : Error processing arguments");
    //         cobj->playBackgroundMusic(arg0, arg1);
    cobj->playBackgroundMusic(musicFile.c_str(), loop);
    //         args.rval().setUndefined();
    return;
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_playBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_resumeAllEffects(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_resumeAllEffects(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_resumeAllEffects : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_resumeAllEffects : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_resumeAllEffects : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->resumeAllEffects();
  cobj->resumeAllEffects();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_resumeAllEffects : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_setEffectsVolume(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_setEffectsVolume(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_setEffectsVolume : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_setEffectsVolume : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_setEffectsVolume : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  float volume = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_setEffectsVolume : Error processing arguments");
  //         cobj->setEffectsVolume(arg0);
  cobj->setEffectsVolume(volume);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_setEffectsVolume : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_stopEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_stopEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_stopEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_stopEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_stopEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         unsigned int arg0 = 0;
  //         ok &= jsval_to_uint32(cx, args.get(0), &arg0);
  unsigned int sec = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_stopEffect : Error processing arguments");
  //         cobj->stopEffect(arg0);
  cobj->stopEffect(sec);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_stopEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->pauseBackgroundMusic();
  cobj->pauseBackgroundMusic();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_pauseAllEffects(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_pauseAllEffects(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_pauseAllEffects : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_pauseAllEffects : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_pauseAllEffects : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->pauseAllEffects();
  cobj->pauseAllEffects();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_pauseAllEffects : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_unloadEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_unloadEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_unloadEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_unloadEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_unloadEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         const char *arg0 = nullptr;
  //         std::string arg0_tmp;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
  std::string effectFile = JsbUtils::FromV8String(isolate, args[0]);
  //         arg0 = arg0_tmp.c_str();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_unloadEffect : Error processing arguments");
  //         cobj->unloadEffect(arg0);
  cobj->unloadEffect(effectFile.c_str());
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_unloadEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_resumeEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_resumeEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     CocosDenshion::SimpleAudioEngine *cobj = (CocosDenshion::SimpleAudioEngine *)(proxy ? proxy->ptr : NULL);
  SimpleAudioEngine *cobj = (SimpleAudioEngine *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SimpleAudioEngine_resumeEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SimpleAudioEngine_resumeEffect : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_resumeEffect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         unsigned int arg0 = 0;
  //         ok &= jsval_to_uint32(cx, args.get(0), &arg0);
  unsigned int sec = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SimpleAudioEngine_resumeEffect : Error processing arguments");
  //         cobj->resumeEffect(arg0);
  cobj->resumeEffect(sec);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_resumeEffect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_end(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_end(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_end : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         CocosDenshion::SimpleAudioEngine::end();
  SimpleAudioEngine::end();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_end : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_SimpleAudioEngine_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SimpleAudioEngine_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_getInstance : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }

  //         CocosDenshion::SimpleAudioEngine *ret = CocosDenshion::SimpleAudioEngine::getInstance();
  SimpleAudioEngine *ret = SimpleAudioEngine::getInstance();
  //         jsval jsret = JSVAL_NULL;
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<CocosDenshion::SimpleAudioEngine>(cx, (CocosDenshion::SimpleAudioEngine *)ret));
  if (ret)
  {
    auto jsobj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsobj);
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_SimpleAudioEngine_getInstance : CocosDenshion::SimpleAudioEngine::getInstance() returned nullptr");
    args.GetReturnValue().Set(v8::Null(isolate));
  }
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_SimpleAudioEngine_getInstance : wrong number of arguments");
  //     return false;
}

// void js_register_cocos2dx_SimpleAudioEngine(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_SimpleAudioEngine(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_CocosDenshion_SimpleAudioEngine_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_CocosDenshion_SimpleAudioEngine_class->name = "AudioEngine";
  //     jsb_CocosDenshion_SimpleAudioEngine_class->addProperty = JS_PropertyStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->delProperty = JS_DeletePropertyStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->getProperty = JS_PropertyStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->setProperty = JS_StrictPropertyStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->enumerate = JS_EnumerateStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->resolve = JS_ResolveStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->convert = JS_ConvertStub;
  //     jsb_CocosDenshion_SimpleAudioEngine_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, nullptr);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "AudioEngine").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("preloadMusic", js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "preloadMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_preloadBackgroundMusic));
  //         JS_FN("stopMusic", js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_stopBackgroundMusic));
  //         JS_FN("stopAllEffects", js_cocos2dx_SimpleAudioEngine_stopAllEffects, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopAllEffects", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_stopAllEffects));
  //         JS_FN("getMusicVolume", js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getMusicVolume", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_getBackgroundMusicVolume));
  //         JS_FN("resumeMusic", js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "resumeMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_resumeBackgroundMusic));
  //         JS_FN("setMusicVolume", js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setMusicVolume", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_setBackgroundMusicVolume));
  //         JS_FN("preloadEffect", js_cocos2dx_SimpleAudioEngine_preloadEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "preloadEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_preloadEffect));
  //         JS_FN("isMusicPlaying", js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isMusicPlaying", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_isBackgroundMusicPlaying));
  //         JS_FN("getEffectsVolume", js_cocos2dx_SimpleAudioEngine_getEffectsVolume, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getEffectsVolume", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_getEffectsVolume));
  //         JS_FN("willPlayMusic", js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "willPlayMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_willPlayBackgroundMusic));
  //         JS_FN("pauseEffect", js_cocos2dx_SimpleAudioEngine_pauseEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pauseEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_pauseEffect));
  //         JS_FN("playEffect", js_cocos2dx_SimpleAudioEngine_playEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "playEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_playEffect));
  //         JS_FN("rewindMusic", js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "rewindMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_rewindBackgroundMusic));
  //         JS_FN("playMusic", js_cocos2dx_SimpleAudioEngine_playBackgroundMusic, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "playMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_playBackgroundMusic));
  //         JS_FN("resumeAllEffects", js_cocos2dx_SimpleAudioEngine_resumeAllEffects, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "resumeAllEffects", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_resumeAllEffects));
  //         JS_FN("setEffectsVolume", js_cocos2dx_SimpleAudioEngine_setEffectsVolume, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setEffectsVolume", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_setEffectsVolume));
  //         JS_FN("stopEffect", js_cocos2dx_SimpleAudioEngine_stopEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_stopEffect));
  //         JS_FN("pauseMusic", js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pauseMusic", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_pauseBackgroundMusic));
  //         JS_FN("pauseAllEffects", js_cocos2dx_SimpleAudioEngine_pauseAllEffects, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pauseAllEffects", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_pauseAllEffects));
  //         JS_FN("unloadEffect", js_cocos2dx_SimpleAudioEngine_unloadEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "unloadEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_unloadEffect));
  //         JS_FN("resumeEffect", js_cocos2dx_SimpleAudioEngine_resumeEffect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "resumeEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_resumeEffect));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("end", js_cocos2dx_SimpleAudioEngine_end, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "end", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_end));
  //         JS_FN("getInstance", js_cocos2dx_SimpleAudioEngine_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_SimpleAudioEngine_getInstance));
  //         JS_FS_END};

  //     jsb_CocosDenshion_SimpleAudioEngine_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_CocosDenshion_SimpleAudioEngine_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_CocosDenshion_SimpleAudioEngine_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "SimpleAudioEngine"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "SimpleAudioEngine"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::False(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<CocosDenshion::SimpleAudioEngine>(cx, jsb_CocosDenshion_SimpleAudioEngine_class, proto, JS::NullPtr());

  JsbUtils::RegisterV8Class(typeid(CocosDenshion::SimpleAudioEngine).name(), &tpl);
  JsbUtils::BindJsClass("AudioEngine", global, tpl);
}

// JSClass *jsb_cocos2d_SAXParser_class;
// JSObject *jsb_cocos2d_SAXParser_prototype;

// bool js_cocos2dx_SAXParser_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SAXParser_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SAXParser *cobj = (cocos2d::SAXParser *)(proxy ? proxy->ptr : NULL);
  cocos2d::SAXParser *cobj = (cocos2d::SAXParser *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SAXParser_init : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_SAXParser_init : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SAXParser_init : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         const char *arg0 = nullptr;
  //         std::string arg0_tmp;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         arg0 = arg0_tmp.c_str();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SAXParser_init : Error processing arguments");
  SE_PRECONDITION2(!filename.empty(), "js_cocos2dx_SAXParser_init : Error processing arguments");
  //         bool ret = cobj->init(arg0);
  bool ret = cobj->init(filename.c_str());
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SAXParser_init : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// // cc.PlistParser.getInstance()
// bool js_PlistParser_getInstance(JSContext *cx, unsigned argc, JS::Value *vp)
// {
void js_PlistParser_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  __JSPlistDelegator *delegator = __JSPlistDelegator::getInstance();
  cocos2d::SAXParser *parser = delegator->getParser();

  //     jsval jsret;
  //     if (parser) {
  //         js_proxy_t *p = jsb_get_native_proxy(parser);
  //         if (p) {
  //             jsret = OBJECT_TO_JSVAL(p->obj);
  //         } else {
  //             // create a new js obj of that class
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<SAXParser>(cx, parser));
  //         }
  //     } else {
  //         jsret = JSVAL_NULL;
  //     }
  auto jsobj = JsbUtils::NativePtrToObject(parser);
  args.GetReturnValue().Set(jsobj);
  //     args.rval().set(jsret);

  //     return true;
}

cocos2d::SAXParser *__JSPlistDelegator::getParser()
{
  return &_parser;
}

std::string __JSPlistDelegator::parse(const std::string &path)
{
  _result.clear();

  cocos2d::SAXParser parser;
  if (false != parser.init("UTF-8"))
  {
    parser.setDelegator(this);
    parser.parse(cocos2d::FileUtils::getInstance()->fullPathForFilename(path));
  }

  return _result;
}

__JSPlistDelegator::~__JSPlistDelegator()
{
  CCLOGINFO("deallocing __JSSAXDelegator: %p", this);
}

std::string __JSPlistDelegator::parseText(const std::string &text)
{
  _result.clear();

  cocos2d::SAXParser parser;
  if (false != parser.init("UTF-8"))
  {
    parser.setDelegator(this);
    parser.parse(text.c_str(), text.size());
  }

  return _result;
}

void __JSPlistDelegator::startElement(void *ctx, const char *name, const char **atts)
{
  _isStoringCharacters = true;
  _currentValue.clear();

  std::string elementName = (char *)name;

  int end = (int)_result.size() - 1;
  if (end >= 0 && _result[end] != '{' && _result[end] != '[' && _result[end] != ':')
  {
    _result += ",";
  }

  if (elementName == "dict")
  {
    _result += "{";
  }
  else if (elementName == "array")
  {
    _result += "[";
  }
}

void __JSPlistDelegator::endElement(void *ctx, const char *name)
{
  _isStoringCharacters = false;
  std::string elementName = (char *)name;

  if (elementName == "dict")
  {
    _result += "}";
  }
  else if (elementName == "array")
  {
    _result += "]";
  }
  else if (elementName == "key")
  {
    _result += "\"" + _currentValue + "\":";
  }
  else if (elementName == "string")
  {
    _result += "\"" + _currentValue + "\"";
  }
  else if (elementName == "false" || elementName == "true")
  {
    _result += elementName;
  }
  else if (elementName == "real" || elementName == "integer")
  {
    _result += _currentValue;
  }
}

void __JSPlistDelegator::textHandler(void * /*ctx*/, const char *ch, size_t len)
{
  std::string text((char *)ch, 0, len);

  if (_isStoringCharacters)
  {
    _currentValue += text;
  }
}

// // cc.PlistParser.getInstance().parse(text)
// bool js_PlistParser_parse(JSContext *cx, unsigned argc, JS::Value *vp) {
void js_PlistParser_parse(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  __JSPlistDelegator *delegator = __JSPlistDelegator::getInstance();

  //     bool ok = true;
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 1) {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_PlistParser_parse : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string xml = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "Error processing arguments");

  //         std::string parsedStr = delegator->parseText(arg0);
  std::string parsedStr = delegator->parseText(xml);

  //         std::replace(parsedStr.begin(), parsedStr.end(), '\n', ' ');
  std::replace(parsedStr.begin(), parsedStr.end(), '\n', ' ');

  //         jsval strVal = std_string_to_jsval(cx, parsedStr);
  auto jsstr = JsbUtils::ToV8String(isolate, parsedStr);
  //         // create a new js obj of the parsed string
  //         JS::RootedValue outVal(cx);

  //         //JS_GetStringCharsZ was removed in SpiderMonkey 33
  //         JS::RootedString jsout(cx, strVal.toString());
  //         ok = JS_ParseJSON(cx, jsout, &outVal);
  auto parsedJson = v8::JSON::Parse(isolate->GetCurrentContext(), jsstr).ToLocalChecked();
  if (!parsedJson.IsEmpty())
  {
    args.GetReturnValue().Set(parsedJson);
  }
  else
  {
    SE_REPORT_ERROR("js_PlistParser_parse : parse error std::string: %s", parsedStr.c_str());
    args.GetReturnValue().Set(v8::Undefined(isolate));
  }

  //         if (ok)
  //             args.rval().set(outVal);
  //         else {
  //             args.rval().setUndefined();
  //             JS_ReportError(cx, "js_PlistParser_parse : parse error");
  //         }
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_PlistParser_parse : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// void js_register_cocos2dx_SAXParser(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_SAXParser(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_SAXParser_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_SAXParser_class->name = "PlistParser";
  //     jsb_cocos2d_SAXParser_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_SAXParser_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_SAXParser_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_SAXParser_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_SAXParser_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_SAXParser_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_SAXParser_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_SAXParser_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "PlistParser").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     JS_GetProperty(cx, ccObj, "PlistParser", &tmpVal);
  //     tmpObj = tmpVal.toObjectOrNull();
  //     JS_DefineFunction(cx, tmpObj, "getInstance", js_PlistParser_getInstance, 0, JSPROP_READONLY | JSPROP_PERMANENT);
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_PlistParser_getInstance));
  //     JS::RootedObject proto(cx, jsb_cocos2d_SAXParser_prototype);
  //     JS_DefineFunction(cx, proto, "parse", js_PlistParser_parse, 1, JSPROP_READONLY | JSPROP_PERMANENT);
  tpl->PrototypeTemplate()->Set(isolate, "parse", v8::FunctionTemplate::New(isolate, js_PlistParser_parse));

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("init", js_cocos2dx_SAXParser_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_SAXParser_init));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     jsb_cocos2d_SAXParser_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_SAXParser_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_SAXParser_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "SAXParser"));
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "SAXParser"));
  //     JS_SetProperty(cx, proto, "_className", className);
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::False(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::SAXParser>(cx, jsb_cocos2d_SAXParser_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::SAXParser).name(), &tpl);
  JsbUtils::BindJsClass("PlistParser", global, tpl);
}
