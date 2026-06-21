#include "JsbDirector.hpp"
#include "JsbUtils.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"
#include "base/CCEventDispatcher.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCRenderer.h"
#include "platform/CCGLView.h"
#include "2d/CCActionManager.h"

// JSClass *jsb_cocos2d_Director_class;
// JSObject *jsb_cocos2d_Director_prototype;

// bool js_cocos2dx_Director_pause(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_pause(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_pause : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_pause : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->pause();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->pause();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_pause : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_pause : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_pushProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_pushProjectionMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_pushProjectionMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_pushProjectionMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     size_t arg0 = 0;
  //     ok &= jsval_to_size(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_pushProjectionMatrix : Error processing arguments");
  //     cobj->pushProjectionMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    size_t arg0 = 0;
    bool ok = args[0]->IsUint32() && args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_pushProjectionMatrix : Error processing arguments");
    cobj->pushMatrix((cocos2d::MATRIX_STACK_TYPE)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_pushProjectionMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_pushProjectionMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_popProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_popProjectionMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_popProjectionMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_popProjectionMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     size_t arg0 = 0;
  //     ok &= jsval_to_size(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_popProjectionMatrix : Error processing arguments");
  //     cobj->popProjectionMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    size_t arg0 = 0;
    bool ok = args[0]->IsUint32() && args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_popProjectionMatrix : Error processing arguments");
    cobj->popMatrix((cocos2d::MATRIX_STACK_TYPE)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_popProjectionMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_popProjectionMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_setEventDispatcher(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setEventDispatcher(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setEventDispatcher : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setEventDispatcher : Invalid Native Object");
  assert(false && "js_cocos2dx_Director_setEventDispatcher is deprecated since v3.17, and will be removed in v4.0");
  //   if (argc == 1)
  //   {
  //     cocos2d::EventDispatcher *arg0 = nullptr;
  //     do
  //     {
  //       if (args.get(0).isNull())
  //       {
  //         arg0 = nullptr;
  //         break;
  //       }
  //       if (!args.get(0).isObject())
  //       {
  //         ok = false;
  //         break;
  //       }
  //       js_proxy_t *jsProxy;
  //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //       jsProxy = jsb_get_js_proxy(tmpObj);
  //       arg0 = (cocos2d::EventDispatcher *)(jsProxy ? jsProxy->ptr : NULL);
  //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //     } while (0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setEventDispatcher : Error processing arguments");
  //     cobj->setEventDispatcher(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setEventDispatcher : wrong number of arguments: %d, was expecting %d", argc, 1);
  //   return false;
}

// bool js_cocos2dx_Director_loadProjectionIdentityMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_loadProjectionIdentityMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  CCASSERT(false, "TODO: js_cocos2dx_Director_loadProjectionIdentityMatrix");
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_loadProjectionIdentityMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     size_t arg0 = 0;
  //     ok &= jsval_to_size(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_loadProjectionIdentityMatrix : Error processing arguments");
  //     cobj->loadProjectionIdentityMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_loadProjectionIdentityMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  //   return false;
}

// bool js_cocos2dx_Director_setContentScaleFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setContentScaleFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setContentScaleFactor : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setContentScaleFactor : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     double arg0 = 0;
  //     ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setContentScaleFactor : Error processing arguments");
  //     cobj->setContentScaleFactor(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    double arg0 = 0;
    bool ok = args[0]->IsNumber() && args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg0) && !std::isnan(arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_setContentScaleFactor : Error processing arguments");
    cobj->setContentScaleFactor(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setContentScaleFactor : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setContentScaleFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getDeltaTime(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getDeltaTime(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getDeltaTime : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getDeltaTime : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getDeltaTime();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getDeltaTime();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getDeltaTime : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getDeltaTime : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_getContentScaleFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getContentScaleFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getContentScaleFactor : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getContentScaleFactor : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getContentScaleFactor();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getContentScaleFactor();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getContentScaleFactor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getContentScaleFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_getWinSizeInPixels(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getWinSizeInPixels(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getWinSizeInPixels : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getWinSizeInPixels : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Size ret = cobj->getWinSizeInPixels();
  //     JS::RootedValue jsret(cx);
  //     jsret = ccsize_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Size ret = cobj->getWinSizeInPixels();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getWinSizeInPixels : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getWinSizeInPixels : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_getSafeAreaRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getSafeAreaRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getSafeAreaRect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getSafeAreaRect : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Rect ret = cobj->getSafeAreaRect();
  //     JS::RootedValue jsret(cx);
  //     jsret = ccrect_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Rect ret = cobj->getSafeAreaRect();
    args.GetReturnValue().Set(JsbUtils::ccrect_to_jsval(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_getSafeAreaRect : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_setGLDefaultValues(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setGLDefaultValues(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setGLDefaultValues : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setGLDefaultValues : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->setGLDefaultValues();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->setGLDefaultValues();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_setGLDefaultValues : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //   JS_ReportError(cx, "js_cocos2dx_Director_setGLDefaultValues : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_setActionManager(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setActionManager(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setActionManager : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::ActionManager *arg0 = nullptr;
  //     do
  //     {
  //       if (args.get(0).isNull())
  //       {
  //         arg0 = nullptr;
  //         break;
  //       }
  //       if (!args.get(0).isObject())
  //       {
  //         ok = false;
  //         break;
  //       }
  //       js_proxy_t *jsProxy;
  //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //       jsProxy = jsb_get_js_proxy(tmpObj);
  //       arg0 = (cocos2d::ActionManager *)(jsProxy ? jsProxy->ptr : NULL);
  //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //     } while (0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setActionManager : Error processing arguments");
  //     cobj->setActionManager(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setActionManager : wrong number of arguments: %d, was expecting %d", argc, 1);
  //   return false;
}

// bool js_cocos2dx_Director_setAlphaBlending(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setAlphaBlending(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setAlphaBlending : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setAlphaBlending : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     bool arg0;
  //     arg0 = JS::ToBoolean(args.get(0));
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setAlphaBlending : Error processing arguments");
  //     cobj->setAlphaBlending(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->IsTrue();
    CCASSERT(false, "TODO: js_cocos2dx_Director_setAlphaBlending is deprecated since v3.17, and will be removed in v4.0");
    // cobj->setAlphaBlending(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setAlphaBlending : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setAlphaBlending : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_popToRootScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_popToRootScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_popToRootScene : Invalid Native Object");

  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_popToRootScene : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->popToRootScene();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->popToRootScene();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_popToRootScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //   JS_ReportError(cx, "js_cocos2dx_Director_popToRootScene : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_loadMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_loadMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_loadMatrix : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_loadMatrix : Invalid Native Object");
  //   if (argc == 2)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     cocos2d::Mat4 arg1;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     ok &= jsval_to_matrix(cx, args.get(1), &arg1);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_loadMatrix : Error processing arguments");
  //     cobj->loadMatrix(arg0, arg1);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 2)
  {
    cocos2d::MATRIX_STACK_TYPE arg0;
    cocos2d::Mat4 arg1;
    bool ok = args[0]->IsUint32() && args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To((uint32_t *)&arg0);
    ok = ok && JsbUtils::jsval_to_matrix(args.GetIsolate(), args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_loadMatrix : Error processing arguments");
    cobj->loadMatrix(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_loadMatrix : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Director_loadMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //   return false;
}

// bool js_cocos2dx_Director_getNotificationNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getNotificationNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getNotificationNode : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getNotificationNode : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Node *ret = cobj->getNotificationNode();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Node *ret = cobj->getNotificationNode();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getNotificationNode : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getNotificationNode : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_getWinSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getWinSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getWinSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getWinSize : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     const cocos2d::Size &ret = cobj->getWinSize();
  //     JS::RootedValue jsret(cx);
  //     jsret = ccsize_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    const cocos2d::Size &ret = cobj->getWinSize();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getWinSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getWinSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_end(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_end(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_end : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_end : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->end();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->end();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_end : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_end : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_getTextureCache(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getTextureCache(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getTextureCache : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getTextureCache : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::TextureCache *ret = cobj->getTextureCache();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::TextureCache>(cx, (cocos2d::TextureCache *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::TextureCache *ret = cobj->getTextureCache();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getTextureCache : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getTextureCache : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_isSendCleanupToScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_isSendCleanupToScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_isSendCleanupToScene : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_isSendCleanupToScene : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->isSendCleanupToScene();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    bool ret = cobj->isSendCleanupToScene();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_isSendCleanupToScene : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_isSendCleanupToScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_getVisibleOrigin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getVisibleOrigin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getVisibleOrigin : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getVisibleOrigin : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Vec2 ret = cobj->getVisibleOrigin();
  //     JS::RootedValue jsret(cx);
  //     jsret = vector2_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Vec2 ret = cobj->getVisibleOrigin();
    args.GetReturnValue().Set(JsbUtils::vector2_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getVisibleOrigin : wrong number of arguments: %d, was expecting %d", argc, 0);

  SE_REPORT_ERROR("js_cocos2dx_Director_getVisibleOrigin : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_mainLoop(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_mainLoop(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  CCASSERT(false, "TODO: js_cocos2dx_Director_mainLoop is deprecated since v3.17, and will be removed in v4.0");
  //   bool ok = true;
  //   cocos2d::Director *cobj = nullptr;

  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx);
  //   obj.set(args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cobj = (cocos2d::Director *)(proxy ? proxy->ptr : nullptr);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_mainLoop : Invalid Native Object");
  //   do
  //   {
  //     if (argc == 1)
  //     {
  //       double arg0 = 0;
  //       ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //       if (!ok)
  //       {
  //         ok = true;
  //         break;
  //       }
  //       cobj->mainLoop(arg0);
  //       args.rval().setUndefined();
  //       return true;
  //     }
  //   } while (0);

  //   do
  //   {
  //     if (argc == 0)
  //     {
  //       cobj->mainLoop();
  //       args.rval().setUndefined();
  //       return true;
  //     }
  //   } while (0);

  //   JS_ReportError(cx, "js_cocos2dx_Director_mainLoop : wrong number of arguments");
  //   return false;
}

// bool js_cocos2dx_Director_setDepthTest(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setDepthTest(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setDepthTest : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setDepthTest : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     bool arg0;
  //     arg0 = JS::ToBoolean(args.get(0));
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setDepthTest : Error processing arguments");
  //     cobj->setDepthTest(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->IsTrue();
    if (arg0)
      cobj->getRenderer()->setDepthTest(true);
    else
      cobj->getRenderer()->setDepthTest(false);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setDepthTest : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setDepthTest : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getFrameRate(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getFrameRate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getFrameRate : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getFrameRate : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getFrameRate();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getFrameRate();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getFrameRate : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getFrameRate : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_getSecondsPerFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getSecondsPerFrame(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getSecondsPerFrame : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getSecondsPerFrame : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getSecondsPerFrame();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getSecondsPerFrame();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getSecondsPerFrame : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getSecondsPerFrame : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_resetMatrixStack(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_resetMatrixStack(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_resetMatrixStack : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_resetMatrixStack : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->resetMatrixStack();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->resetMatrixStack();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_resetMatrixStack : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_resetMatrixStack : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_convertToUI(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_convertToUI(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_convertToUI : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_convertToUI : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::Vec2 arg0;
  //     ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_convertToUI : Error processing arguments");
  //     cocos2d::Vec2 ret = cobj->convertToUI(arg0);
  //     JS::RootedValue jsret(cx);
  //     jsret = vector2_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    bool ok = JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_convertToUI : Error processing arguments");
    cocos2d::Vec2 ret = cobj->convertToUI(arg0);
    args.GetReturnValue().Set(JsbUtils::vector2_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_convertToUI : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_convertToUI : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_pushMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_pushMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_pushMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_pushMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_pushMatrix : Error processing arguments");
  //     cobj->pushMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    cocos2d::MATRIX_STACK_TYPE arg0;
    bool ok = args[0]->IsUint32() && args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To((uint32_t *)&arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_pushMatrix : Error processing arguments");
    cobj->pushMatrix(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_pushMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_pushMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_setDefaultValues(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setDefaultValues(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setDefaultValues : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->setDefaultValues();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_setDefaultValues : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_init : Invalid Native Object");
  if (args.Length() == 0)
  {
    bool ret = cobj->init();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_init : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_init : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_init : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->init();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_init : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_setScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setScheduler(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setScheduler : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setScheduler : Invalid Native Object");
  //   if (argc == 1)
  //   {

  //   }
  if (args.Length() == 1)
  {
    //     cocos2d::Scheduler *arg0 = nullptr;
    cocos2d::Scheduler *arg0 = nullptr;
    //       if (args.get(0).isNull())
    //       {
    //         arg0 = nullptr;
    //         break;
    //       }
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else
    {
      if (!args[0]->IsObject())
      {
        SE_REPORT_ERROR("js_cocos2dx_Director_setScheduler : Error processing arguments");
        return;
      }
      arg0 = (cocos2d::Scheduler *)args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked()->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "js_cocos2dx_Director_setScheduler : Invalid Native Object");
      cobj->setScheduler(arg0);
      args.GetReturnValue().SetUndefined();
    }
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setScheduler : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setScheduler : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_multiplyProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_multiplyProjectionMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_multiplyProjectionMatrix : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_multiplyProjectionMatrix : Invalid Native Object");
  //   if (argc == 2)
  //   {
  //     cocos2d::Mat4 arg0;
  //     size_t arg1 = 0;
  //     ok &= jsval_to_matrix(cx, args.get(0), &arg0);
  //     ok &= jsval_to_size(cx, args.get(1), &arg1);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_multiplyProjectionMatrix : Error processing arguments");
  //     cobj->multiplyProjectionMatrix(arg0, arg1);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 2)
  {
    cocos2d::Mat4 arg0;
    size_t arg1 = args[1]->IsUint32() && args[1]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To(&arg1) ? arg1 : 0;
    bool ok = JsbUtils::jsval_to_matrix(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_multiplyProjectionMatrix : Error processing arguments");
    // cobj->multiplyProjectionMatrix(arg0, arg1);
    CCASSERT(false, "TODO: js_cocos2dx_Director_multiplyProjectionMatrix is deprecated since v3.17, and will be removed in v4.0");
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_multiplyProjectionMatrix : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Director_multiplyProjectionMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //   return false;
}

// bool js_cocos2dx_Director_getMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_getMatrix : Error processing arguments");
  //     const cocos2d::Mat4 &ret = cobj->getMatrix(arg0);
  //     JS::RootedValue jsret(cx);
  //     jsret = matrix_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    cocos2d::MATRIX_STACK_TYPE arg0;
    bool ok = args[0]->IsUint32() && args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).To((uint32_t *)&arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_getMatrix : Error processing arguments");
    const cocos2d::Mat4 &ret = cobj->getMatrix(arg0);
    args.GetReturnValue().Set(JsbUtils::matrix_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_getMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_isValid(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_isValid(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_isValid : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_isValid : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->isValid();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    bool ret = cobj->isValid();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_isValid : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_isValid : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_startAnimation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_startAnimation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_startAnimation : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_startAnimation : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->startAnimation();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->startAnimation();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_startAnimation : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //   JS_ReportError(cx, "js_cocos2dx_Director_startAnimation : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_getOpenGLView(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getOpenGLView(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getOpenGLView : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getOpenGLView : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::GLView *ret = cobj->getOpenGLView();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::GLView>(cx, (cocos2d::GLView *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::GLView *ret = cobj->getOpenGLView();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_getOpenGLView : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_getRunningScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getRunningScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getRunningScene : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getRunningScene : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Scene *ret = cobj->getRunningScene();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scene>(cx, (cocos2d::Scene *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Scene *ret = cobj->getRunningScene();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getRunningScene : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getRunningScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_setViewport(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setViewport(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setViewport : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->setViewport();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_setViewport : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setViewport : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->setViewport();
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setViewport : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_stopAnimation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_stopAnimation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_stopAnimation : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_stopAnimation : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->stopAnimation();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->stopAnimation();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_stopAnimation : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_stopAnimation : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_popToSceneStackLevel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_popToSceneStackLevel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_popToSceneStackLevel : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_popToSceneStackLevel : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     int arg0 = 0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_popToSceneStackLevel : Error processing arguments");
  //     cobj->popToSceneStackLevel(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    cobj->popToSceneStackLevel(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_popToSceneStackLevel : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_popToSceneStackLevel : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Director_resume(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_resume(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cObj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cObj, "js_cocos2dx_Director_resume : Invalid Native Object");
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_resume : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->resume();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cObj->resume();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_resume : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_resume : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_isNextDeltaTimeZero(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_isNextDeltaTimeZero(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_isNextDeltaTimeZero : Invalid Native Object");
  if (args.Length() == 0)
  {
    bool ret = cobj->isNextDeltaTimeZero();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_isNextDeltaTimeZero : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->isNextDeltaTimeZero();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_isNextDeltaTimeZero : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_isNextDeltaTimeZero : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_setClearColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setClearColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setClearColor : Invalid Native Object");
  if (args.Length() == 1)
  {
    cocos2d::Color4F arg0;
    bool ok = JsbUtils::jsval_to_cccolor4f(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_setClearColor : Error processing arguments");
    cobj->setClearColor(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setClearColor : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::Color4F arg0;
  //     ok &= jsval_to_cccolor4f(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setClearColor : Error processing arguments");
  //     cobj->setClearColor(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setClearColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setClearColor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_setOpenGLView(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setOpenGLView(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  CCASSERT(false, "js_cocos2dx_Director_setOpenGLView is deprecated since v3.17, and will be removed in v4.0");
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setOpenGLView : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::GLView *arg0 = nullptr;
  //     do
  //     {
  //       if (args.get(0).isNull())
  //       {
  //         arg0 = nullptr;
  //         break;
  //       }
  //       if (!args.get(0).isObject())
  //       {
  //         ok = false;
  //         break;
  //       }
  //       js_proxy_t *jsProxy;
  //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //       jsProxy = jsb_get_js_proxy(tmpObj);
  //       arg0 = (cocos2d::GLView *)(jsProxy ? jsProxy->ptr : NULL);
  //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //     } while (0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setOpenGLView : Error processing arguments");
  //     cobj->setOpenGLView(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setOpenGLView : wrong number of arguments: %d, was expecting %d", argc, 1);
  //   return false;
}

// bool js_cocos2dx_Director_convertToGL(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_convertToGL(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_convertToGL : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_convertToGL : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::Vec2 arg0;
  //     ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_convertToGL : Error processing arguments");
  //     cocos2d::Vec2 ret = cobj->convertToGL(arg0);
  //     JS::RootedValue jsret(cx);
  //     jsret = vector2_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    bool ok = JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_convertToGL : Error processing arguments");
    cocos2d::Vec2 ret = cobj->convertToGL(arg0);
    args.GetReturnValue().Set(JsbUtils::vector2_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_convertToGL : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_convertToGL : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_purgeCachedData(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_purgeCachedData(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_purgeCachedData : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_purgeCachedData : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->purgeCachedData();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->purgeCachedData();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_purgeCachedData : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_purgeCachedData : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_getTotalFrames(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getTotalFrames(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getTotalFrames : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getTotalFrames : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     unsigned int ret = cobj->getTotalFrames();
  //     JS::RootedValue jsret(cx);
  //     jsret = uint32_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    unsigned int ret = cobj->getTotalFrames();
    args.GetReturnValue().Set(v8::Integer::NewFromUnsigned(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getTotalFrames : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getTotalFrames : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Director_runWithScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_runWithScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_runWithScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_runWithScene : Invalid Native Object");
  //   if (argc == 1)
  //   {

  //   }
  if (args.Length() == 1)
  {
    //     cocos2d::Scene *arg0 = nullptr;
    cocos2d::Scene *arg0 = nullptr;

    //       if (args.get(0).isNull())
    //       {
    //         arg0 = nullptr;
    //         break;
    //       }
    //       if (!args.get(0).isObject())
    //       {
    //         ok = false;
    //         break;
    //       }
    //       js_proxy_t *jsProxy;
    //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //       jsProxy = jsb_get_js_proxy(tmpObj);
    //       arg0 = (cocos2d::Scene *)(jsProxy ? jsProxy->ptr : NULL);
    //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

      arg0 = (cocos2d::Scene *)tmpObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_runWithScene : Error processing arguments");
      return;
    }
    //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_runWithScene : Error processing arguments");
    //     cobj->runWithScene(arg0);
    cobj->runWithScene(arg0);
    args.GetReturnValue().SetUndefined();
    return;
    //     args.rval().setUndefined();
    //     return true;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_runWithScene : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_runWithScene : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_setNotificationNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setNotificationNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setNotificationNode : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setNotificationNode : Invalid Native Object");
  //   if (argc == 1)
  //   {

  //   }
  if (args.Length() == 1)
  {
    //     cocos2d::Node *arg0 = nullptr;
    cocos2d::Node *arg0 = nullptr;

    //       if (args.get(0).isNull())
    //       {
    //         arg0 = nullptr;
    //         break;
    //       }
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

      arg0 = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_setNotificationNode : Error processing arguments");
      return;
    }
    //       if (!args.get(0).isObject())
    //       {
    //         ok = false;
    //         break;
    //       }
    //       js_proxy_t *jsProxy;
    //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //       jsProxy = jsb_get_js_proxy(tmpObj);
    //       arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");

    //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setNotificationNode : Error processing arguments");
    //     cobj->setNotificationNode(arg0);
    cobj->setNotificationNode(arg0);
    args.GetReturnValue().SetUndefined();
    //     args.rval().setUndefined();
    //     return true;
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setNotificationNode : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setNotificationNode : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_drawScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_drawScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_drawScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_drawScene : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->drawScene();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->drawScene();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_drawScene : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_drawScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
  return;
}

// bool js_cocos2dx_Director_restart(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_restart(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_restart : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_restart : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->restart();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->restart();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_restart : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_restart : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_popScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_popScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_popScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_popScene : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cobj->popScene();
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cobj->popScene();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_popScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  return;

  //   JS_ReportError(cx, "js_cocos2dx_Director_popScene : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_loadIdentityMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_loadIdentityMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_loadIdentityMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_loadIdentityMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_loadIdentityMatrix : Error processing arguments");
  //     cobj->loadIdentityMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    cobj->loadIdentityMatrix((cocos2d::MATRIX_STACK_TYPE)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_loadIdentityMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  return;

  //   JS_ReportError(cx, "js_cocos2dx_Director_loadIdentityMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  //   return false;
}

// bool js_cocos2dx_Director_isDisplayStats(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_isDisplayStats(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_isDisplayStats : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_isDisplayStats : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->isDisplayStats();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    bool ret = cobj->isDisplayStats();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_isDisplayStats : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_isDisplayStats : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_setProjection(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setProjection(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setProjection : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setProjection : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::Director::Projection arg0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setProjection : Error processing arguments");
  //     cobj->setProjection(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    cobj->setProjection((cocos2d::Director::Projection)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_setProjection : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}
// }

// bool js_cocos2dx_Director_multiplyMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_multiplyMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_multiplyMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_multiplyMatrix : Invalid Native Object");
  //   if (argc == 2)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     cocos2d::Mat4 arg1;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     ok &= jsval_to_matrix(cx, args.get(1), &arg1);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_multiplyMatrix : Error processing arguments");
  //     cobj->multiplyMatrix(arg0, arg1);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 2)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    cocos2d::Mat4 arg1;
    bool ok = JsbUtils::jsval_to_matrix(args.GetIsolate(), args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_multiplyMatrix : Error processing arguments");
    cobj->multiplyMatrix((cocos2d::MATRIX_STACK_TYPE)arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_multiplyMatrix : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Director_multiplyMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //   return false;
}

// bool js_cocos2dx_Director_getZEye(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getZEye(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getZEye : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getZEye : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getZEye();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getZEye();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getZEye : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getZEye : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_setNextDeltaTimeZero(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setNextDeltaTimeZero(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setNextDeltaTimeZero : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setNextDeltaTimeZero : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     bool arg0;
  //     arg0 = JS::ToBoolean(args.get(0));
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setNextDeltaTimeZero : Error processing arguments");
  //     cobj->setNextDeltaTimeZero(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->IsTrue();
    cobj->setNextDeltaTimeZero(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setNextDeltaTimeZero : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setNextDeltaTimeZero : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Director_popMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_popMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_popMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_popMatrix : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     cocos2d::MATRIX_STACK_TYPE arg0;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_popMatrix : Error processing arguments");
  //     cobj->popMatrix(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    cobj->popMatrix((cocos2d::MATRIX_STACK_TYPE)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_popMatrix : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_popMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getVisibleSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getVisibleSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getVisibleSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getVisibleSize : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Size ret = cobj->getVisibleSize();
  //     JS::RootedValue jsret(cx);
  //     jsret = ccsize_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Size ret = cobj->getVisibleSize();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getVisibleSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getVisibleSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_loadProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_loadProjectionMatrix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_loadProjectionMatrix : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_loadProjectionMatrix : Invalid Native Object");
  //   if (argc == 2)
  //   {
  //     cocos2d::Mat4 arg0;
  //     size_t arg1 = 0;
  //     ok &= jsval_to_matrix(cx, args.get(0), &arg0);
  //     ok &= jsval_to_size(cx, args.get(1), &arg1);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_loadProjectionMatrix : Error processing arguments");
  //     cobj->loadProjectionMatrix(arg0, arg1);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 2)
  {
    cocos2d::Mat4 arg0;
    bool ok = JsbUtils::jsval_to_matrix(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Director_loadProjectionMatrix : Error processing arguments");
    int arg1 = args[1]->IsInt32() && args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg1) ? arg1 : 0;
    cobj->loadMatrix((cocos2d::MATRIX_STACK_TYPE)arg1, arg0);

    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_loadProjectionMatrix : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Director_loadProjectionMatrix : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //   return false;
}

// bool js_cocos2dx_Director_initProjectionMatrixStack(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_initProjectionMatrixStack(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_initProjectionMatrixStack : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_initProjectionMatrixStack : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     size_t arg0 = 0;
  //     ok &= jsval_to_size(cx, args.get(0), &arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_initProjectionMatrixStack : Error processing arguments");
  //     cobj->initProjectionMatrixStack(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->IsInt32() && args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).To(&arg0) ? arg0 : 0;
    // cobj->initMatrixStack((cocos2d::MATRIX_STACK_TYPE)arg0);
    // TODO: remove this function since it's deprecated, and use setProjectionMatrixStack instead.
    CCASSERT(false, "cocos2d::Director::initProjectionMatrixStack has been deprecated since v4.0, please use setProjectionMatrixStack instead.");
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_initProjectionMatrixStack : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_initProjectionMatrixStack : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getScheduler(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getScheduler : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getScheduler : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::Scheduler *ret = cobj->getScheduler();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scheduler>(cx, (cocos2d::Scheduler *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::Scheduler *ret = cobj->getScheduler();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(args.GetIsolate()));
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getScheduler : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getScheduler : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_pushScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_pushScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_pushScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_pushScene : Invalid Native Object");
  //   if (argc == 1)
  //   {
  if (args.Length() == 1)
  {
    //     cocos2d::Scene *arg0 = nullptr;
    cocos2d::Scene *arg0 = nullptr;

    //       if (args.get(0).isNull())
    //       {
    //         arg0 = nullptr;
    //         break;
    //       }
    //       if (!args.get(0).isObject())
    //       {
    //         ok = false;
    //         break;
    //       }
    if (!args[0]->IsObject() && !args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_pushScene : Error processing arguments");
      return;
    }
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    arg0 = (cocos2d::Scene *)tmpObj->GetAlignedPointerFromInternalField(0);
    if (!arg0 && !args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_pushScene : Error processing arguments");
      return;
    }
    //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");

    //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_pushScene : Error processing arguments");
    //     cobj->pushScene(arg0);
    cobj->pushScene(arg0);
    //     args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //     return true;
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_pushScene : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_pushScene : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getAnimationInterval(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getAnimationInterval(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getAnimationInterval : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getAnimationInterval : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     double ret = cobj->getAnimationInterval();
  //     JS::RootedValue jsret(cx);
  //     jsret = DOUBLE_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    double ret = cobj->getAnimationInterval();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getAnimationInterval : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getAnimationInterval : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_Director_getClearColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getClearColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getClearColor : Invalid Native Object");
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getClearColor : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     const cocos2d::Color4F &ret = cobj->getClearColor();
  //     JS::RootedValue jsret(cx);
  //     jsret = cccolor4f_to_jsval(cx, ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    const cocos2d::Color4F &ret = cobj->getRenderer()->getClearColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4f_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getClearColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getClearColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_Director_isPaused(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_isPaused(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_isPaused : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_isPaused : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     bool ret = cobj->isPaused();
  //     JS::RootedValue jsret(cx);
  //     jsret = BOOLEAN_TO_JSVAL(ret);
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    bool ret = cobj->isPaused();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Director_isPaused : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  args.GetReturnValue().SetUndefined();

  //   JS_ReportError(cx, "js_cocos2dx_Director_isPaused : wrong number of arguments: %d, was expecting %d", argc, 0);
  //   return false;
}

// bool js_cocos2dx_Director_setDisplayStats(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setDisplayStats(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setDisplayStats : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setDisplayStats : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     bool arg0;
  //     arg0 = JS::ToBoolean(args.get(0));
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setDisplayStats : Error processing arguments");
  //     cobj->setDisplayStats(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->IsTrue();
    cobj->setDisplayStats(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setDisplayStats : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setDisplayStats : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getEventDispatcher(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getEventDispatcher(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getEventDispatcher : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getEventDispatcher : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::EventDispatcher *ret = cobj->getEventDispatcher();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::EventDispatcher>(cx, (cocos2d::EventDispatcher *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::EventDispatcher *ret = cobj->getEventDispatcher();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(args.GetIsolate()));
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getEventDispatcher : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getEventDispatcher : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_replaceScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_replaceScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_replaceScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_replaceScene : Invalid Native Object");
  //   if (argc == 1)
  //   {

  //   }
  if (args.Length() == 1)
  {
    //     cocos2d::Scene *arg0 = nullptr;
    cocos2d::Scene *scene = nullptr;

    //       if (args.get(0).isNull())
    //       {
    //         arg0 = nullptr;
    //         break;
    //       }
    //       if (!args.get(0).isObject())
    //       {
    //         ok = false;
    //         break;
    //       }
    if (!args[0]->IsObject() && args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_replaceScene : Error processing arguments");
      return;
    }
    //       js_proxy_t *jsProxy;
    //       JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //       jsProxy = jsb_get_js_proxy(tmpObj);
    //       arg0 = (cocos2d::Scene *)(jsProxy ? jsProxy->ptr : NULL);
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    scene = (cocos2d::Scene *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(scene, "js_cocos2dx_Director_replaceScene : Invalid Native Object");

    //       JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");

    //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_replaceScene : Error processing arguments");
    //     cobj->replaceScene(arg0);
    cobj->replaceScene(scene);
    //     args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //     return true;
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_replaceScene : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_replaceScene : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_setAnimationInterval(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_setAnimationInterval(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   bool ok = true;
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_setAnimationInterval : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_setAnimationInterval : Invalid Native Object");
  //   if (argc == 1)
  //   {
  //     double arg0 = 0;
  //     ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Director_setAnimationInterval : Error processing arguments");
  //     cobj->setAnimationInterval(arg0);
  //     args.rval().setUndefined();
  //     return true;
  //   }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->IsNumber() ? args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0) : 0;
    if (std::isnan(arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Director_setAnimationInterval : Error processing arguments");
      return;
    }
    cobj->setAnimationInterval(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_setAnimationInterval : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Director_setAnimationInterval : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //   return false;
}

// bool js_cocos2dx_Director_getActionManager(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getActionManager(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //   js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //   cocos2d::Director *cobj = (cocos2d::Director *)(proxy ? proxy->ptr : NULL);
  cocos2d::Director *cobj = (cocos2d::Director *)args.This()->GetAlignedPointerFromInternalField(0);
  //   JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Director_getActionManager : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Director_getActionManager : Invalid Native Object");
  //   if (argc == 0)
  //   {
  //     cocos2d::ActionManager *ret = cobj->getActionManager();
  //     JS::RootedValue jsret(cx);
  //     if (ret)
  //     {
  //       jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ActionManager>(cx, (cocos2d::ActionManager *)ret));
  //     }
  //     else
  //     {
  //       jsret = JSVAL_NULL;
  //     };
  //     args.rval().set(jsret);
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    cocos2d::ActionManager *ret = cobj->getActionManager();
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsObj);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(args.GetIsolate()));
    }
    return;
  }

  //   JS_ReportError(cx, "js_cocos2dx_Director_getActionManager : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Director_getActionManager : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //   return false;
}

// bool js_cocos2dx_Director_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Director_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //   JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //   if (argc == 0)
  //   {

  //     auto ret = cocos2d::Director::getInstance();
  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Director>(ret);
  //     JS::RootedObject jsret(cx, jsb_ref_get_or_create_jsobject(cx, ret, typeClass, "cocos2d::Director"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsret));
  //     return true;
  //   }
  if (args.Length() == 0)
  {
    auto ret = cocos2d::Director::getInstance();
    v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsObj);
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Director_getInstance : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

void js_register_cocos2dx_Director(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  SE_LOGD("Registering JS API for Director");
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //   jsb_cocos2d_Director_class = (JSClass *)calloc(1, sizeof(JSClass));
  // jsb_cocos2d_Director_class->name = "Director";
  // jsb_cocos2d_Director_class->addProperty = JS_PropertyStub;
  // jsb_cocos2d_Director_class->delProperty = JS_DeletePropertyStub;
  // jsb_cocos2d_Director_class->getProperty = JS_PropertyStub;
  // jsb_cocos2d_Director_class->setProperty = JS_StrictPropertyStub;
  // jsb_cocos2d_Director_class->enumerate = JS_EnumerateStub;
  // jsb_cocos2d_Director_class->resolve = JS_ResolveStub;
  // jsb_cocos2d_Director_class->convert = JS_ConvertStub;
  // jsb_cocos2d_Director_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "Director"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // static JSPropertySpec properties[] = {
  //     JS_PS_END}

  // static JSFunctionSpec funcs[] = {
  //     JS_FN("pause", js_cocos2dx_Director_pause, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pause", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_pause));
  //     JS_FN("pushProjectionMatrix", js_cocos2dx_Director_pushProjectionMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pushProjectionMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_pushProjectionMatrix));
  //     JS_FN("popProjectionMatrix", js_cocos2dx_Director_popProjectionMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "popProjectionMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_popProjectionMatrix));
  //     JS_FN("setEventDispatcher", js_cocos2dx_Director_setEventDispatcher, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setEventDispatcher", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setEventDispatcher));
  //     JS_FN("loadProjectionIdentityMatrix", js_cocos2dx_Director_loadProjectionIdentityMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "loadProjectionIdentityMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_loadProjectionIdentityMatrix));
  //     JS_FN("setContentScaleFactor", js_cocos2dx_Director_setContentScaleFactor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setContentScaleFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setContentScaleFactor));
  //     JS_FN("getDeltaTime", js_cocos2dx_Director_getDeltaTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDeltaTime", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getDeltaTime));
  //     JS_FN("getContentScaleFactor", js_cocos2dx_Director_getContentScaleFactor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getContentScaleFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getContentScaleFactor));
  //     JS_FN("getWinSizeInPixels", js_cocos2dx_Director_getWinSizeInPixels, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getWinSizeInPixels", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getWinSizeInPixels));
  //     JS_FN("getSafeAreaRect", js_cocos2dx_Director_getSafeAreaRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getSafeAreaRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getSafeAreaRect));
  //     JS_FN("setGLDefaultValues", js_cocos2dx_Director_setGLDefaultValues, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setGLDefaultValues", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setGLDefaultValues));
  //     JS_FN("setActionManager", js_cocos2dx_Director_setActionManager, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setActionManager", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setActionManager));
  //     JS_FN("setAlphaBlending", js_cocos2dx_Director_setAlphaBlending, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setAlphaBlending", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setAlphaBlending));
  //     JS_FN("popToRootScene", js_cocos2dx_Director_popToRootScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "popToRootScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_popToRootScene));
  //     JS_FN("loadMatrix", js_cocos2dx_Director_loadMatrix, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "loadMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_loadMatrix));
  //     JS_FN("getNotificationNode", js_cocos2dx_Director_getNotificationNode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNotificationNode", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getNotificationNode));
  //     JS_FN("getWinSize", js_cocos2dx_Director_getWinSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getWinSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getWinSize));
  //     JS_FN("end", js_cocos2dx_Director_end, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "end", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_end));
  //     JS_FN("getTextureCache", js_cocos2dx_Director_getTextureCache, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getTextureCache", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getTextureCache));
  //     JS_FN("isSendCleanupToScene", js_cocos2dx_Director_isSendCleanupToScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isSendCleanupToScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_isSendCleanupToScene));
  //     JS_FN("getVisibleOrigin", js_cocos2dx_Director_getVisibleOrigin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVisibleOrigin", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getVisibleOrigin));
  //     JS_FN("mainLoop", js_cocos2dx_Director_mainLoop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "mainLoop", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_mainLoop));
  //     JS_FN("setDepthTest", js_cocos2dx_Director_setDepthTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDepthTest", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setDepthTest));
  //     JS_FN("getFrameRate", js_cocos2dx_Director_getFrameRate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getFrameRate", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getFrameRate));
  //     JS_FN("getSecondsPerFrame", js_cocos2dx_Director_getSecondsPerFrame, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getSecondsPerFrame", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getSecondsPerFrame));
  //     JS_FN("resetMatrixStack", js_cocos2dx_Director_resetMatrixStack, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "resetMatrixStack", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_resetMatrixStack));
  //     JS_FN("convertToUI", js_cocos2dx_Director_convertToUI, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertToUI", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_convertToUI));
  //     JS_FN("pushMatrix", js_cocos2dx_Director_pushMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pushMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_pushMatrix));
  //     JS_FN("setDefaultValues", js_cocos2dx_Director_setDefaultValues, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDefaultValues", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setDefaultValues));
  //     JS_FN("init", js_cocos2dx_Director_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_init));
  //     JS_FN("setScheduler", js_cocos2dx_Director_setScheduler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScheduler", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setScheduler));
  //     JS_FN("multiplyProjectionMatrix", js_cocos2dx_Director_multiplyProjectionMatrix, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "multiplyProjectionMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_multiplyProjectionMatrix));
  //     JS_FN("getMatrix", js_cocos2dx_Director_getMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getMatrix));
  //     JS_FN("isValid", js_cocos2dx_Director_isValid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isValid", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_isValid));
  //     JS_FN("startAnimation", js_cocos2dx_Director_startAnimation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "startAnimation", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_startAnimation));
  //     JS_FN("getOpenGLView", js_cocos2dx_Director_getOpenGLView, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getOpenGLView", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getOpenGLView));
  //     JS_FN("getRunningScene", js_cocos2dx_Director_getRunningScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRunningScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getRunningScene));
  //     JS_FN("setViewport", js_cocos2dx_Director_setViewport, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setViewport", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setViewport));
  //     JS_FN("stopAnimation", js_cocos2dx_Director_stopAnimation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopAnimation", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_stopAnimation));
  //     JS_FN("popToSceneStackLevel", js_cocos2dx_Director_popToSceneStackLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "popToSceneStackLevel", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_popToSceneStackLevel));
  //     JS_FN("resume", js_cocos2dx_Director_resume, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "resume", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_resume));
  //     JS_FN("isNextDeltaTimeZero", js_cocos2dx_Director_isNextDeltaTimeZero, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isNextDeltaTimeZero", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_isNextDeltaTimeZero));
  //     JS_FN("setClearColor", js_cocos2dx_Director_setClearColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setClearColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setClearColor));
  //     JS_FN("setOpenGLView", js_cocos2dx_Director_setOpenGLView, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOpenGLView", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setOpenGLView));
  //     JS_FN("convertToGL", js_cocos2dx_Director_convertToGL, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertToGL", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_convertToGL));
  //     JS_FN("purgeCachedData", js_cocos2dx_Director_purgeCachedData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "purgeCachedData", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_purgeCachedData));
  //     JS_FN("getTotalFrames", js_cocos2dx_Director_getTotalFrames, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getTotalFrames", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getTotalFrames));
  //     JS_FN("runWithScene", js_cocos2dx_Director_runWithScene, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "runWithScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_runWithScene));
  //     JS_FN("setNotificationNode", js_cocos2dx_Director_setNotificationNode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setNotificationNode", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setNotificationNode));
  //     JS_FN("drawScene", js_cocos2dx_Director_drawScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "drawScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_drawScene));
  //     JS_FN("restart", js_cocos2dx_Director_restart, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "restart", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_restart));
  //     JS_FN("popScene", js_cocos2dx_Director_popScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "popScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_popScene));
  //     JS_FN("loadIdentityMatrix", js_cocos2dx_Director_loadIdentityMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "loadIdentityMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_loadIdentityMatrix));
  //     JS_FN("isDisplayStats", js_cocos2dx_Director_isDisplayStats, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isDisplayStats", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_isDisplayStats));
  //     JS_FN("setProjection", js_cocos2dx_Director_setProjection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setProjection", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setProjection));
  //     JS_FN("multiplyMatrix", js_cocos2dx_Director_multiplyMatrix, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "multiplyMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_multiplyMatrix));
  //     JS_FN("getZEye", js_cocos2dx_Director_getZEye, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getZEye", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getZEye));
  //     JS_FN("setNextDeltaTimeZero", js_cocos2dx_Director_setNextDeltaTimeZero, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setNextDeltaTimeZero", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setNextDeltaTimeZero));
  //     JS_FN("popMatrix", js_cocos2dx_Director_popMatrix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "popMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_popMatrix));
  //     JS_FN("getVisibleSize", js_cocos2dx_Director_getVisibleSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVisibleSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getVisibleSize));
  //     JS_FN("loadProjectionMatrix", js_cocos2dx_Director_loadProjectionMatrix, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "loadProjectionMatrix", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_loadProjectionMatrix));
  //     JS_FN("initProjectionMatrixStack", js_cocos2dx_Director_initProjectionMatrixStack, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "initProjectionMatrixStack", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_initProjectionMatrixStack));
  //     JS_FN("getScheduler", js_cocos2dx_Director_getScheduler, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScheduler", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getScheduler));
  //     JS_FN("pushScene", js_cocos2dx_Director_pushScene, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pushScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_pushScene));
  //     JS_FN("getAnimationInterval", js_cocos2dx_Director_getAnimationInterval, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getAnimationInterval", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getAnimationInterval));
  //     JS_FN("getClearColor", js_cocos2dx_Director_getClearColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getClearColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getClearColor));
  //     JS_FN("isPaused", js_cocos2dx_Director_isPaused, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isPaused", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_isPaused));
  //     JS_FN("setDisplayStats", js_cocos2dx_Director_setDisplayStats, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDisplayStats", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setDisplayStats));
  //     JS_FN("getEventDispatcher", js_cocos2dx_Director_getEventDispatcher, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getEventDispatcher", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getEventDispatcher));
  //     JS_FN("replaceScene", js_cocos2dx_Director_replaceScene, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "replaceScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_replaceScene));
  //     JS_FN("setAnimationInterval", js_cocos2dx_Director_setAnimationInterval, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setAnimationInterval", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_setAnimationInterval));
  //     JS_FN("getActionManager", js_cocos2dx_Director_getActionManager, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getActionManager", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getActionManager));
  //     JS_FS_END};

  // static JSFunctionSpec st_funcs[] = {
  //     JS_FN("getInstance", js_cocos2dx_Director_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_Director_getInstance));
  //     JS_FS_END};

  // jsb_cocos2d_Director_prototype = JS_InitClass(
  //     cx, global,
  //     JS::NullPtr(),
  //     jsb_cocos2d_Director_class,
  //     empty_constructor, 0,
  //     properties,
  //     funcs,
  //     NULL, // no static properties
  //     st_funcs);

  // JS::RootedObject proto(cx, jsb_cocos2d_Director_prototype);
  // JS::RootedValue className(cx, std_string_to_jsval(cx, "Director"));
  // JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "Director"));
  // JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  // JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::True(isolate));

  JsbUtils::RegisterV8Class(typeid(cocos2d::Director).name(), &tpl);
  JsbUtils::BindJsClass("Director", global, tpl);
  // // add the proto and JSClass to the type->js info hash table
  // jsb_register_class<cocos2d::Director>(cx, jsb_cocos2d_Director_class, proto, JS::NullPtr());
}