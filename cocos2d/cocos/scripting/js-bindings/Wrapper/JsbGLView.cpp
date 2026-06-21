#include "JsbGLView.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "JsbCtor.hpp"
#include "platform/CCGLView.h"

// JSClass *jsb_cocos2d_GLView_class;
// JSObject *jsb_cocos2d_GLView_prototype;

// bool js_cocos2dx_GLView_setFrameSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setFrameSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setFrameSize : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setFrameSize : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setFrameSize : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         double arg0 = 0;
  //         double arg1 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double width = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double height = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  //         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setFrameSize : Error processing arguments");
  //         cobj->setFrameSize(arg0, arg1);
  cView->setFrameSize(width, height);
  //         args.rval().setUndefined();
  //         return true;
}

// bool js_cocos2dx_GLView_getViewPortRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getViewPortRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getViewPortRect : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getViewPortRect : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getViewPortRect : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Rect &ret = cobj->getViewPortRect();
  const cocos2d::Rect &ret = cView->getViewPortRect();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccrect_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getViewPortRect : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getScaleY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getScaleY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getScaleY : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getScaleY : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getScaleY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getScaleY();
  double ret = cView->getScaleY();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getScaleY : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setContentScaleFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setContentScaleFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setContentScaleFactor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setContentScaleFactor : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setContentScaleFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double scaleFactor = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  bool ret = cView->setContentScaleFactor(scaleFactor);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setContentScaleFactor : Error processing arguments");
  //         bool ret = cobj->setContentScaleFactor(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setContentScaleFactor : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getVR(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getVR(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getVR : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getVR : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getVR : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::VRIRenderer *ret = cobj->getVR();
  CCASSERT(false, "cocos2d::GLView::getVR is not implemented");
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::VRIRenderer>(cx, (cocos2d::VRIRenderer *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getVR : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getContentScaleFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getContentScaleFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getContentScaleFactor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getContentScaleFactor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getContentScaleFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getContentScaleFactor();
  double ret = cView->getContentScaleFactor();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getContentScaleFactor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setIMEKeyboardState(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setIMEKeyboardState(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setIMEKeyboardState : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setIMEKeyboardState : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setIMEKeyboardState : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool set = args[0]->BooleanValue(args.GetIsolate());
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setIMEKeyboardState : Error processing arguments");
  //         cobj->setIMEKeyboardState(arg0);
  cView->setIMEKeyboardState(set);
  //         args.rval().setUndefined();

  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setIMEKeyboardState : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getSafeAreaRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getSafeAreaRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getSafeAreaRect : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getSafeAreaRect : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getSafeAreaRect : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Rect ret = cobj->getSafeAreaRect();
  cocos2d::Rect ret = cView->getSafeAreaRect();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccrect_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getSafeAreaRect : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setViewPortInPoints(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setViewPortInPoints(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setViewPortInPoints : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setViewPortInPoints : Invalid Native Object");
  //     if (argc == 4)
  //     {
  if (args.Length() != 4)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setViewPortInPoints : wrong number of arguments: %d, was expecting %d", args.Length(), 4);
    return;
  }
  //         double arg0 = 0;
  //         double arg1 = 0;
  //         double arg2 = 0;
  //         double arg3 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         ok &= JS::ToNumber(cx, args.get(3), &arg3) && !std::isnan(arg3);
  double x = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double y = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double width = args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double height = args[3]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setViewPortInPoints : Error processing arguments");
  //         cobj->setViewPortInPoints(arg0, arg1, arg2, arg3);
  cView->setViewPortInPoints(x, y, width, height);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setViewPortInPoints : wrong number of arguments: %d, was expecting %d", argc, 4);
  //     return false;
}

// bool js_cocos2dx_GLView_setScissorInPoints(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setScissorInPoints(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setScissorInPoints : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setScissorInPoints : Invalid Native Object");
  //     if (argc == 4)
  //     {
  if (args.Length() != 4)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setScissorInPoints : wrong number of arguments: %d, was expecting %d", args.Length(), 4);
    return;
  }
  double x = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double y = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double width = args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double height = args[3]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  cView->setScissorInPoints(x, y, width, height);

  //         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         ok &= JS::ToNumber(cx, args.get(3), &arg3) && !std::isnan(arg3);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setScissorInPoints : Error processing arguments");
  //         cobj->setScissorInPoints(arg0, arg1, arg2, arg3);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setScissorInPoints : wrong number of arguments: %d, was expecting %d", argc, 4);
  //     return false;
}

// bool js_cocos2dx_GLView_getViewName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getViewName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getViewName : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getViewName : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getViewName : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const std::string &ret = cobj->getViewName();
  const std::string &ret = cView->getViewName();
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getViewName : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_isOpenGLReady(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_isOpenGLReady(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_isOpenGLReady : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_isOpenGLReady : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isOpenGLReady();
  bool ret = cView->isOpenGLReady();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_isOpenGLReady : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setCursorVisible(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setCursorVisible(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setCursorVisible : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setCursorVisible : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setCursorVisible : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool visible = args[0]->BooleanValue(args.GetIsolate());
  cView->setCursorVisible(visible);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setCursorVisible : Error processing arguments");
  //         cobj->setCursorVisible(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setCursorVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_setDefaultIcon(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setDefaultIcon(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setDefaultIcon : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setDefaultIcon : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setDefaultIcon : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->setDefaultIcon();
  cView->setDefaultIcon();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setDefaultIcon : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getScaleX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getScaleX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getScaleX : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getScaleX : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getScaleX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getScaleX();
  double ret = cView->getScaleX();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getScaleX : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getVisibleOrigin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getVisibleOrigin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getVisibleOrigin : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getVisibleOrigin : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getVisibleOrigin : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Vec2 ret = cobj->getVisibleOrigin();
  cocos2d::Vec2 ret = cView->getVisibleOrigin();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  auto jsret = JsbUtils::vector2_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getVisibleOrigin : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setFrameZoomFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setFrameZoomFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setFrameZoomFactor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setFrameZoomFactor : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setFrameZoomFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double zoomFactor = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setFrameZoomFactor : Error processing arguments");
  cView->setFrameZoomFactor(zoomFactor);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setFrameZoomFactor : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getFrameZoomFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getFrameZoomFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getFrameZoomFactor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getFrameZoomFactor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getFrameZoomFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getFrameZoomFactor();
  double ret = cView->getFrameZoomFactor();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getFrameZoomFactor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getDesignResolutionSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getDesignResolutionSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getDesignResolutionSize : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getDesignResolutionSize : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getDesignResolutionSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Size &ret = cobj->getDesignResolutionSize();
  const cocos2d::Size &ret = cView->getDesignResolutionSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccsize_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getDesignResolutionSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setIcon(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setIcon(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     bool ok = true;
  //     cocos2d::GLView *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : nullptr);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setIcon : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setIcon : Invalid Native Object");
  //     do
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setIcon : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         if (argc == 1)
  //         {
  if (args[0]->IsArray())
  {
    //             std::vector<std::string> arg0;
    //             ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->setIcon(arg0);
    //             args.rval().setUndefined();
    //             return true;
  }
  else if (args[0]->IsString())
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->setIcon(arg0);
    //             args.rval().setUndefined();
    //             return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setIcon : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_GLView_setIcon : invalid argument");
  //     return false;
}

// bool js_cocos2dx_GLView_setDefaultCursor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setDefaultCursor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setDefaultCursor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setDefaultCursor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setDefaultCursor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->setDefaultCursor();
  CCASSERT(false, "js_cocos2dx_GLView_setDefaultCursor : not implemented yet");
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setDefaultCursor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_windowShouldClose(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_windowShouldClose(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_windowShouldClose : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_windowShouldClose : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_windowShouldClose : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->windowShouldClose();
  bool ret = cView->windowShouldClose();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_windowShouldClose : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setDesignResolutionSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setDesignResolutionSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setDesignResolutionSize : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setDesignResolutionSize : Invalid Native Object");
  //     if (argc == 3)
  //     {
  if (args.Length() != 3)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setDesignResolutionSize : wrong number of arguments: %d, was expecting %d", args.Length(), 3);
    return;
  }
  //         double arg0 = 0;
  //         double arg1 = 0;
  //         ResolutionPolicy arg2;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  double width = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  double height = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  int policyInt = args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setDesignResolutionSize : Error processing arguments");
  //         cobj->setDesignResolutionSize(arg0, arg1, arg2);
  cView->setDesignResolutionSize(width, height, (ResolutionPolicy)policyInt);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setDesignResolutionSize : wrong number of arguments: %d, was expecting %d", argc, 3);
  //     return false;
}

// bool js_cocos2dx_GLView_getResolutionPolicy(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getResolutionPolicy(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getResolutionPolicy : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getResolutionPolicy : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getResolutionPolicy : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         int ret = (int)cobj->getResolutionPolicy();
  int ret = (int)cView->getResolutionPolicy();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getResolutionPolicy : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_isRetinaDisplay(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_isRetinaDisplay(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_isRetinaDisplay : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_isRetinaDisplay : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_isRetinaDisplay : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isRetinaDisplay();
  bool ret = cView->isRetinaDisplay();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_isRetinaDisplay : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_renderScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_renderScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_renderScene : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_renderScene : Invalid Native Object");

  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_renderScene : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::Scene *arg0 = nullptr;
  cocos2d::Scene *scene = nullptr;
  if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(context).ToLocalChecked();
    scene = (cocos2d::Scene *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(scene, "Invalid Native Object");
  }

  cocos2d::Renderer *renderer = nullptr;
  if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(context).ToLocalChecked();
    renderer = (cocos2d::Renderer *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(renderer, "Invalid Native Object");
  }
  cView->renderScene(scene, renderer);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_renderScene : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_GLView_setVR(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setVR(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setVR : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setVR : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setVR : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }

  CCASSERT(false, "js_cocos2dx_GLView_setVR : not implemented yet");
  //         cocos2d::VRIRenderer *arg0 = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::VRIRenderer *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setVR : Error processing arguments");
  //         cobj->setVR(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setVR : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getFrameSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getFrameSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getFrameSize : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getFrameSize : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getFrameSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Size ret = cobj->getFrameSize();
  cocos2d::Size ret = cView->getFrameSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccsize_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getFrameSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getScissorRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getScissorRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getScissorRect : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getScissorRect : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getScissorRect : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Rect ret = cobj->getScissorRect();
  cocos2d::Rect ret = cView->getScissorRect();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccrect_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getScissorRect : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setCursor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setCursor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setCursor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setCursor : Invalid Native Object");

  CCASSERT(false, "js_cocos2dx_GLView_setCursor : not implemented yet");
  //     if (argc == 1)
  //     {

  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setCursor : Error processing arguments");
  //         cobj->setCursor(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     if (argc == 2)
  //     {
  //         std::string arg0;
  //         cocos2d::Vec2 arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_vector2(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setCursor : Error processing arguments");
  //         cobj->setCursor(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setCursor : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getRetinaFactor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getRetinaFactor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getRetinaFactor : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getRetinaFactor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getRetinaFactor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         int ret = cobj->getRetinaFactor();
  int ret = cView->getRetinaFactor();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getRetinaFactor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setViewName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setViewName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_setViewName : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_setViewName : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_setViewName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string viewName = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setViewName : Error processing arguments");
  //         cobj->setViewName(arg0);
  cView->setViewName(viewName);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_setViewName : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLView_getVisibleRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getVisibleRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getVisibleRect : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getVisibleRect : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getVisibleRect : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Rect ret = cobj->getVisibleRect();
  cocos2d::Rect ret = cView->getVisibleRect();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccrect_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getVisibleRect : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_getVisibleSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getVisibleSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_getVisibleSize : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_getVisibleSize : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_getVisibleSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cocos2d::Size ret = cView->getVisibleSize();
  auto jsret = JsbUtils::ccsize_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_getVisibleSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_isScissorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_isScissorEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_isScissorEnabled : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_isScissorEnabled : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_isScissorEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isScissorEnabled();
  bool ret = cView->isScissorEnabled();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_isScissorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_pollEvents(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_pollEvents(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLView *cobj = (cocos2d::GLView *)(proxy ? proxy->ptr : NULL);
  cocos2d::GLView *cView = (cocos2d::GLView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLView_pollEvents : Invalid Native Object");
  SE_PRECONDITION2(cView, "js_cocos2dx_GLView_pollEvents : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLView_pollEvents : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->pollEvents();
  cView->pollEvents();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLView_pollEvents : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLView_setGLContextAttrs(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_setGLContextAttrs(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  CCASSERT(false, "js_cocos2dx_GLView_setGLContextAttrs : not implemented yet");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1)
  //     {
  //         GLContextAttrs arg0;
  // #pragma warning NO CONVERSION TO NATIVE FOR GLContextAttrs
  //         ok = false;
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLView_setGLContextAttrs : Error processing arguments");
  //         cocos2d::GLView::setGLContextAttrs(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_GLView_setGLContextAttrs : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_GLView_getGLContextAttrs(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLView_getGLContextAttrs(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  CCASSERT(false, "js_cocos2dx_GLView_getGLContextAttrs : not implemented yet");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {

  //         GLContextAttrs ret = cocos2d::GLView::getGLContextAttrs();
  //         jsval jsret = JSVAL_NULL;
  // #pragma warning NO CONVERSION FROM NATIVE FOR GLContextAttrs;
  //         args.rval().set(jsret);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_GLView_getGLContextAttrs : wrong number of arguments");
  //     return false;
}

// void js_register_cocos2dx_GLView(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_GLView(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_GLView_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_GLView_class->name = "GLView";
  //     jsb_cocos2d_GLView_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_GLView_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_GLView_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_GLView_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_GLView_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_GLView_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_GLView_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_GLView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, nullptr);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "GLView").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setFrameSize", js_cocos2dx_GLView_setFrameSize, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setFrameSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setFrameSize));
  //         JS_FN("getViewPortRect", js_cocos2dx_GLView_getViewPortRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getViewPortRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getViewPortRect));
  //         JS_FN("getScaleY", js_cocos2dx_GLView_getScaleY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScaleY", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getScaleY));
  //         JS_FN("setContentScaleFactor", js_cocos2dx_GLView_setContentScaleFactor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setContentScaleFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setContentScaleFactor));
  //         JS_FN("getVR", js_cocos2dx_GLView_getVR, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVR", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getVR));
  //         JS_FN("getContentScaleFactor", js_cocos2dx_GLView_getContentScaleFactor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getContentScaleFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getContentScaleFactor));
  //         JS_FN("setIMEKeyboardState", js_cocos2dx_GLView_setIMEKeyboardState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setIMEKeyboardState", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setIMEKeyboardState));
  //         JS_FN("getSafeAreaRect", js_cocos2dx_GLView_getSafeAreaRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getSafeAreaRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getSafeAreaRect));
  //         JS_FN("setViewPortInPoints", js_cocos2dx_GLView_setViewPortInPoints, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setViewPortInPoints", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setViewPortInPoints));
  //         JS_FN("setScissorInPoints", js_cocos2dx_GLView_setScissorInPoints, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScissorInPoints", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setScissorInPoints));
  //         JS_FN("getViewName", js_cocos2dx_GLView_getViewName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getViewName", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getViewName));
  //         JS_FN("isOpenGLReady", js_cocos2dx_GLView_isOpenGLReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isOpenGLReady", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_isOpenGLReady));
  //         JS_FN("setCursorVisible", js_cocos2dx_GLView_setCursorVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setCursorVisible", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setCursorVisible));
  //         JS_FN("setDefaultIcon", js_cocos2dx_GLView_setDefaultIcon, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDefaultIcon", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setDefaultIcon));
  //         JS_FN("getScaleX", js_cocos2dx_GLView_getScaleX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScaleX", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getScaleX));
  //         JS_FN("getVisibleOrigin", js_cocos2dx_GLView_getVisibleOrigin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVisibleOrigin", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getVisibleOrigin));
  //         JS_FN("setFrameZoomFactor", js_cocos2dx_GLView_setFrameZoomFactor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setFrameZoomFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setFrameZoomFactor));
  //         JS_FN("getFrameZoomFactor", js_cocos2dx_GLView_getFrameZoomFactor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getFrameZoomFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getFrameZoomFactor));
  //         JS_FN("getDesignResolutionSize", js_cocos2dx_GLView_getDesignResolutionSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDesignResolutionSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getDesignResolutionSize));
  //         JS_FN("setIcon", js_cocos2dx_GLView_setIcon, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setIcon", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setIcon));
  //         JS_FN("setDefaultCursor", js_cocos2dx_GLView_setDefaultCursor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDefaultCursor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setDefaultCursor));
  //         JS_FN("windowShouldClose", js_cocos2dx_GLView_windowShouldClose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "windowShouldClose", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_windowShouldClose));
  //         JS_FN("setDesignResolutionSize", js_cocos2dx_GLView_setDesignResolutionSize, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setDesignResolutionSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setDesignResolutionSize));
  //         JS_FN("getResolutionPolicy", js_cocos2dx_GLView_getResolutionPolicy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getResolutionPolicy", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getResolutionPolicy));
  //         JS_FN("isRetinaDisplay", js_cocos2dx_GLView_isRetinaDisplay, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isRetinaDisplay", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_isRetinaDisplay));
  //         JS_FN("renderScene", js_cocos2dx_GLView_renderScene, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "renderScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_renderScene));
  //         JS_FN("setVR", js_cocos2dx_GLView_setVR, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setVR", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setVR));
  //         JS_FN("getFrameSize", js_cocos2dx_GLView_getFrameSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getFrameSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getFrameSize));
  //         JS_FN("getScissorRect", js_cocos2dx_GLView_getScissorRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScissorRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getScissorRect));
  //         JS_FN("setCursor", js_cocos2dx_GLView_setCursor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setCursor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setCursor));
  //         JS_FN("getRetinaFactor", js_cocos2dx_GLView_getRetinaFactor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRetinaFactor", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getRetinaFactor));
  //         JS_FN("setViewName", js_cocos2dx_GLView_setViewName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setViewName", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setViewName));
  //         JS_FN("getVisibleRect", js_cocos2dx_GLView_getVisibleRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVisibleRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getVisibleRect));
  //         JS_FN("getVisibleSize", js_cocos2dx_GLView_getVisibleSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVisibleSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getVisibleSize));
  //         JS_FN("isScissorEnabled", js_cocos2dx_GLView_isScissorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isScissorEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_isScissorEnabled));
  //         JS_FN("pollEvents", js_cocos2dx_GLView_pollEvents, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "pollEvents", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_pollEvents));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("setGLContextAttrs", js_cocos2dx_GLView_setGLContextAttrs, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "setGLContextAttrs", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_setGLContextAttrs));
  //         JS_FN("getGLContextAttrs", js_cocos2dx_GLView_getGLContextAttrs, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),

  tpl->Set(isolate, "getGLContextAttrs", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLView_getGLContextAttrs));
  //         JS_FS_END};

  //     jsb_cocos2d_GLView_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_GLView_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_GLView_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "GLView"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", v8::String::NewFromUtf8(isolate, "GLView").ToLocalChecked());
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::True(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::GLView>(cx, jsb_cocos2d_GLView_class, proto, JS::NullPtr());

  JsbUtils::RegisterV8Class(typeid(cocos2d::GLView).name(), &tpl);
  JsbUtils::BindJsClass("GLView", global, tpl);
}
