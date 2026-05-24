#include "JsbConfig.h"
#include "HelperMacros.h"
#include "JsbUtils.h"
#include "JsbCommon.hpp"
#include "base/CCConfiguration.h"
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
    //         args.rval().set(jsret);
    //         return true;
  }
  else if (args.Length() == 2)
  {
    //         std::string arg0;
    //         cocos2d::Value arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_ccvalue(cx, args.get(1), &arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Configuration_getValue : Error processing arguments");
    //         const cocos2d::Value& ret = cobj->getValue(arg0, arg1);
    //         JS::RootedValue jsret(cx);
    //         jsret = ccvalue_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Configuration_getValue : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Configuration_gatherGPUInfo(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_gatherGPUInfo : Invalid Native Object");
//     if (argc == 0) {
//         cobj->gatherGPUInfo();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Configuration_gatherGPUInfo : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Configuration_supportsMapBuffer(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_supportsMapBuffer : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->supportsMapBuffer();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Configuration_supportsMapBuffer : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Configuration_getInfoAsMap(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Configuration* cobj = (cocos2d::Configuration *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Configuration_getInfoAsMap : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::ValueMap& ret = cobj->getInfoAsMap();
//         JS::RootedValue jsret(cx);
//         jsret = ccvaluemap_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Configuration_getInfoAsMap : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_Configuration_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0) {
//         cocos2d::Configuration::destroyInstance();
//         args.rval().setUndefined();
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_Configuration_destroyInstance : wrong number of arguments");
//     return false;
// }

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
      assert(false);
      // args.GetReturnValue().Set(OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Configuration>(isolate, ret)));
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
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, nullptr);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Configuration").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  //     jsb_cocos2d_Configuration_class->name = "Configuration";
  //     jsb_cocos2d_Configuration_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Configuration_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Configuration_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Configuration_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Configuration_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Configuration_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Configuration_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Configuration_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
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
  assert(false);
  // tpl->PrototypeTemplate()->Set(isolate, "getInfo", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInfo));
  // tpl->PrototypeTemplate()->Set(isolate, "getMaxTextureUnits", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getMaxTextureUnits));
  // tpl->PrototypeTemplate()->Set(isolate, "getValue", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getValue));
  // tpl->PrototypeTemplate()->Set(isolate, "gatherGPUInfo", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_gatherGPUInfo));
  // tpl->PrototypeTemplate()->Set(isolate, "supportsMapBuffer", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_supportsMapBuffer));
  // tpl->PrototypeTemplate()->Set(isolate, "getInfoAsMap", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInfoAsMap));
  // tpl->Set(isolate, "destroyInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_destroyInstance));
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_Configuration_getInstance));

  v8::Local<v8::Function> constructor = tpl->GetFunction(ctx).ToLocalChecked();
  global->Set(ctx, v8::String::NewFromUtf8(isolate, "Configuration").ToLocalChecked(), constructor).Check();

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
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Configuration>(cx, jsb_cocos2d_Configuration_class, proto, JS::NullPtr());
}
