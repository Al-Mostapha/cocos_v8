
#include "ui/UIWidget.h"
#include "JsbCtor.hpp"
#include "JsbUtils.h"
#include "JsbWidget.hpp"
#include "ScriptEngine.hpp"
#include "../JsbNodeSpecial.hpp"

// JSClass  *jsb_cocos2d_ui_Widget_class;
// JSObject *jsb_cocos2d_ui_Widget_prototype;

// bool js_cocos2dx_ui_Widget_setLayoutComponentEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setLayoutComponentEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setLayoutComponentEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setLayoutComponentEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setLayoutComponentEnabled : Error processing arguments");
  //         cobj->setLayoutComponentEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(isolate);
    cWidget->setLayoutComponentEnabled(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setLayoutComponentEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setLayoutComponentEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setSizePercent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setSizePercent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setSizePercent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setSizePercent : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setSizePercent : Error processing arguments");
  //         cobj->setSizePercent(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 sizePercent;
    bool ok = JsbUtils::jsval_to_vector2(isolate, args[0], &sizePercent);
    SE_PRECONDITION2(ok, "js_cocos2dx_ui_Widget_setSizePercent : Error processing arguments");
    cWidget->setSizePercent(sizePercent);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setSizePercent : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setSizePercent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getCustomSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getCustomSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getCustomSize : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getCustomSize : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Size& ret = cobj->getCustomSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Size &customSize = cWidget->getCustomSize();
    v8::Local<v8::Value> jsret = JsbUtils::ccsize_to_jsval(isolate, customSize);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getCustomSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getCustomSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getLeftBoundary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getLeftBoundary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getLeftBoundary : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getLeftBoundary : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getLeftBoundary();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double leftBoundary = cWidget->getLeftBoundary();
    v8::Local<v8::Value> jsret = v8::Number::New(isolate, leftBoundary);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getLeftBoundary : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getLeftBoundary : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setFlippedX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setFlippedX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setFlippedX : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setFlippedX : Error processing arguments");
  //         cobj->setFlippedX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool bFlipped = args[0]->BooleanValue(isolate);
    cWidget->setFlippedX(bFlipped);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setFlippedX : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setFlippedX : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setCallbackName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setCallbackName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setCallbackName : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setCallbackName : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setCallbackName : Error processing arguments");
  //         cobj->setCallbackName(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string callbackName = JsbUtils::FromV8String(isolate, args[0]);
    cWidget->setCallbackName(callbackName);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setCallbackName : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setCallbackName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getVirtualRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getVirtualRenderer : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getVirtualRenderer : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Node* ret = cobj->getVirtualRenderer();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Node *virtualRenderer = cWidget->getVirtualRenderer();
    v8::Local<v8::Value> jsRet;
    if (virtualRenderer)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(virtualRenderer);
      jsRet = jsObj;
    }
    else
    {
      jsRet = v8::Null(isolate);
    }
    args.GetReturnValue().Set(jsRet);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setPropagateTouchEvents(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setPropagateTouchEvents(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setPropagateTouchEvents : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setPropagateTouchEvents : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setPropagateTouchEvents : Error processing arguments");
  //         cobj->setPropagateTouchEvents(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool propagateTouchEvents = args[0]->BooleanValue(isolate);
    cWidget->setPropagateTouchEvents(propagateTouchEvents);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setPropagateTouchEvents : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setPropagateTouchEvents : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isUnifySizeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isUnifySizeEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isUnifySizeEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isUnifySizeEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isUnifySizeEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool unifySizeEnabled = cWidget->isUnifySizeEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, unifySizeEnabled));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isUnifySizeEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isUnifySizeEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getSizePercent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getSizePercent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getSizePercent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getSizePercent : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getSizePercent();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &sizePercent = cWidget->getSizePercent();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(isolate, sizePercent);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getSizePercent : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_setPositionPercent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setPositionPercent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setPositionPercent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setPositionPercent : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setPositionPercent : Error processing arguments");
  //         cobj->setPositionPercent(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 positionPercent;
    bool ok = JsbUtils::jsval_to_vector2(isolate, args[0], &positionPercent);
    SE_PRECONDITION2(ok, "js_cocos2dx_ui_Widget_setPositionPercent : Error processing arguments");
    cWidget->setPositionPercent(positionPercent);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setPositionPercent : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setPositionPercent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setSwallowTouches(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setSwallowTouches(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setSwallowTouches : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setSwallowTouches : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setSwallowTouches : Error processing arguments");
  //         cobj->setSwallowTouches(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool swallowTouches = args[0]->BooleanValue(isolate);
    cWidget->setSwallowTouches(swallowTouches);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setSwallowTouches : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_ui_Widget_getLayoutSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getLayoutSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getLayoutSize : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getLayoutSize : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Size& ret = cobj->getLayoutSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Size &layoutSize = cWidget->getLayoutSize();
    v8::Local<v8::Value> jsret = JsbUtils::ccsize_to_jsval(isolate, layoutSize);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getLayoutSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_setHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setHighlighted(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setHighlighted : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setHighlighted : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setHighlighted : Error processing arguments");
  //         cobj->setHighlighted(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool highlighted = args[0]->BooleanValue(isolate);
    cWidget->setHighlighted(highlighted);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setHighlighted : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setPositionType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setPositionType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setPositionType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setPositionType : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::ui::Widget::PositionType arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setPositionType : Error processing arguments");
  //         cobj->setPositionType(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int32_t positionTypeInt = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::ui::Widget::PositionType positionType = static_cast<cocos2d::ui::Widget::PositionType>(positionTypeInt);
    cWidget->setPositionType(positionType);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setPositionType : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setPositionType : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isIgnoreContentAdaptWithSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ignoreContentAdaptWithSize = cWidget->isIgnoreContentAdaptWithSize();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ignoreContentAdaptWithSize));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getVirtualRendererSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getVirtualRendererSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getVirtualRendererSize : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getVirtualRendererSize : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Size ret = cobj->getVirtualRendererSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Size virtualRendererSize = cWidget->getVirtualRendererSize();
    v8::Local<v8::Value> jsret = JsbUtils::ccsize_to_jsval(isolate, virtualRendererSize);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getVirtualRendererSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_isHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isHighlighted(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isHighlighted : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isHighlighted : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isHighlighted();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool highlighted = cWidget->isHighlighted();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, highlighted));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isHighlighted : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isHighlighted : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getLayoutParameter(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getLayoutParameter(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getLayoutParameter : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getLayoutParameter : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::ui::LayoutParameter* ret = cobj->getLayoutParameter();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::LayoutParameter>(cx, (cocos2d::ui::LayoutParameter*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::ui::LayoutParameter *layoutParameter = cWidget->getLayoutParameter();
    v8::Local<v8::Value> jsRet;
    if (layoutParameter)
    {
      jsRet = JsbUtils::NativePtrToObject(layoutParameter);
    }
    else
    {
      jsRet = v8::Null(isolate);
    }
    args.GetReturnValue().Set(jsRet);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getLayoutParameter : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getLayoutParameter : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_addCCSEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_addCCSEventListener(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_addCCSEventListener : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_addCCSEventListener : Invalid Native Object");
  CCASSERT(false, "TODO: js_cocos2dx_ui_Widget_addCCSEventListener : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //         std::function<void (cocos2d::Ref *, int)> arg0;
  //         do {
  // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
  // 		    {
  // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
  // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
  // 		        auto lambda = [=](cocos2d::Ref* larg0, int larg1) -> void {
  // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
  // 		            jsval largv[2];
  // 		            if (larg0) {
  // 		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Ref>(cx, (cocos2d::Ref*)larg0));
  // 		        } else {
  // 		            largv[0] = JSVAL_NULL;
  // 		        };
  // 		            largv[1] = int32_to_jsval(cx, larg1);
  // 		            JS::RootedValue rval(cx);
  // 		            bool succeed = func->invoke(2, &largv[0], &rval);
  // 		            if (!succeed && JS_IsExceptionPending(cx)) {
  // 		                JS_ReportPendingException(cx);
  // 		            }
  // 		        };
  // 		        arg0 = lambda;
  // 		    }
  // 		    else
  // 		    {
  // 		        arg0 = nullptr;
  // 		    }

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_addCCSEventListener : Error processing arguments");
  //         cobj->addCCSEventListener(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_addCCSEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getPositionType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getPositionType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getPositionType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getPositionType : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getPositionType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int positionTypeInt = static_cast<int>(cWidget->getPositionType());
    args.GetReturnValue().Set(v8::Integer::New(isolate, positionTypeInt));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getPositionType : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getPositionType : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getTopBoundary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getTopBoundary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getTopBoundary : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getTopBoundary : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getTopBoundary();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double topBoundary = cWidget->getTopBoundary();
    args.GetReturnValue().Set(v8::Number::New(isolate, topBoundary));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getTopBoundary : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize : Error processing arguments");
  //         cobj->ignoreContentAdaptWithSize(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ignore = args[0]->BooleanValue(isolate);
    cWidget->ignoreContentAdaptWithSize(ignore);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_findNextFocusedWidget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_findNextFocusedWidget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_findNextFocusedWidget : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_findNextFocusedWidget : Invalid Native Object");
  //     if (argc == 2) {

  //     }
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_findNextFocusedWidget : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::ui::Widget::FocusDirection arg0;
  cocos2d::ui::Widget::FocusDirection focusDirection = static_cast<cocos2d::ui::Widget::FocusDirection>(args[0]->Int32Value(isolate->GetCurrentContext()).FromJust());
  //         cocos2d::ui::Widget* arg1 = nullptr;
  cocos2d::ui::Widget *currentWidget = nullptr;

  v8::Local<v8::Object> jsCurrentWidget;
  if (args[1]->IsNull())
  {
    jsCurrentWidget = v8::Local<v8::Object>();
  }
  else if (args[1]->IsObject())
  {
    jsCurrentWidget = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    currentWidget = (cocos2d::ui::Widget *)jsCurrentWidget->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(currentWidget, "Invalid Native Object");
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_findNextFocusedWidget : Error processing arguments");
    return;
  }
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         do {
  //             if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //             if (!args.get(1).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_findNextFocusedWidget : Error processing arguments");
  //         cocos2d::ui::Widget* ret = cobj->findNextFocusedWidget(arg0, arg1);
  cocos2d::ui::Widget *nextFocusedWidget = cWidget->findNextFocusedWidget(focusDirection, currentWidget);
  //         JS::RootedValue jsret(cx);
  v8::Local<v8::Value> jsRet;
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Widget>(cx, (cocos2d::ui::Widget*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  if (nextFocusedWidget)
  {
    v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(isolate);
    jsRet = jsObj;
  }
  else
  {
    jsRet = v8::Null(isolate);
  }
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsRet);
  //         return true;
}

// bool js_cocos2dx_ui_Widget_isEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool enabled = cWidget->isEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, enabled));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isFocused(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isFocused(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isFocused : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isFocused : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isFocused();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool focused = cWidget->isFocused();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, focused));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isFocused : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isFocused : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getTouchBeganPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getTouchBeganPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getTouchBeganPosition : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getTouchBeganPosition : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getTouchBeganPosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Vec2 touchBeganPosition = cWidget->getTouchBeganPosition();
    v8::Local<v8::Value> jsRet = JsbUtils::vector2_to_jsval(isolate, touchBeganPosition);
    args.GetReturnValue().Set(jsRet);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getTouchBeganPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_isTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isTouchEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isTouchEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isTouchEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isTouchEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool touchEnabled = cWidget->isTouchEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, touchEnabled));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isTouchEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isTouchEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getCallbackName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getCallbackName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getCallbackName : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getCallbackName : Invalid Native Object");
  //     if (argc == 0) {
  //         const std::string& ret = cobj->getCallbackName();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    std::string callbackName = cWidget->getCallbackName();
    v8::Local<v8::Value> jsRet = v8::String::NewFromUtf8(isolate, callbackName.c_str()).ToLocalChecked();
    args.GetReturnValue().Set(jsRet);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getCallbackName : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getCallbackName : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getActionTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getActionTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getActionTag : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getActionTag : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getActionTag();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int actionTag = cWidget->getActionTag();
    args.GetReturnValue().Set(v8::Integer::New(isolate, actionTag));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getActionTag : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_getWorldPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getWorldPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getWorldPosition : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getWorldPosition : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Vec2 ret = cobj->getWorldPosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Vec2 worldPosition = cWidget->getWorldPosition();
    v8::Local<v8::Value> jsRet = JsbUtils::vector2_to_jsval(isolate, worldPosition);
    args.GetReturnValue().Set(jsRet);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getWorldPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_isFocusEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isFocusEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isFocusEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isFocusEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isFocusEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool focusEnabled = cWidget->isFocusEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, focusEnabled));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isFocusEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isFocusEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setFocused(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setFocused(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setFocused : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setFocused : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setFocused : Error processing arguments");
  //         cobj->setFocused(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool focused = args[0]->BooleanValue(isolate);
    cWidget->setFocused(focused);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setFocused : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setFocused : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setActionTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setActionTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setActionTag : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setActionTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setActionTag : Error processing arguments");
  //         cobj->setActionTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int actionTag = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cWidget->setActionTag(actionTag);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setActionTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setActionTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setTouchEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setTouchEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setTouchEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setTouchEnabled : Error processing arguments");
  //         cobj->setTouchEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool touchEnabled = args[0]->BooleanValue(isolate);
    cWidget->setTouchEnabled(touchEnabled);
    args.GetReturnValue().SetUndefined();
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setTouchEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_ui_Widget_setFlippedY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setFlippedY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setFlippedY : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setFlippedY : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setFlippedY : Error processing arguments");
  //         cobj->setFlippedY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool flippedY = args[0]->BooleanValue(isolate);
    cWidget->setFlippedY(flippedY);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setFlippedY : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setFlippedY : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_init : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_init : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->init();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool initialized = cWidget->init();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, initialized));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_init : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setEnabled : Error processing arguments");
  //         cobj->setEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool enabled = args[0]->BooleanValue(isolate);
    cWidget->setEnabled(enabled);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_ui_Widget_getRightBoundary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getRightBoundary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getRightBoundary : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getRightBoundary : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getRightBoundary();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double rightBoundary = cWidget->getRightBoundary();
    args.GetReturnValue().Set(v8::Number::New(isolate, rightBoundary));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getRightBoundary : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getRightBoundary : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setBrightStyle(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setBrightStyle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setBrightStyle : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setBrightStyle : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::ui::Widget::BrightStyle arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setBrightStyle : Error processing arguments");
  //         cobj->setBrightStyle(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int brightStyleInt = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::ui::Widget::BrightStyle brightStyle = static_cast<cocos2d::ui::Widget::BrightStyle>(brightStyleInt);
    cWidget->setBrightStyle(brightStyle);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setBrightStyle : wrong number of arguments: %d, was expecting %d", args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setBrightStyle : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setLayoutParameter(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setLayoutParameter(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setLayoutParameter : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setLayoutParameter : Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setLayoutParameter : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::ui::LayoutParameter* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ui::LayoutParameter*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setLayoutParameter : Error processing arguments");
    return;
  }
  cocos2d::ui::LayoutParameter *layoutParameter = nullptr;
  if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    layoutParameter = (cocos2d::ui::LayoutParameter *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(layoutParameter, "Invalid Native Object");
  }
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setLayoutParameter : Error processing arguments");
  //         cobj->setLayoutParameter(arg0);
  cWidget->setLayoutParameter(layoutParameter);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setLayoutParameter : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_clone(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_clone(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_clone : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_clone : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::ui::Widget* ret = cobj->clone();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Widget>(cx, (cocos2d::ui::Widget*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::ui::Widget *clonedWidget = cWidget->clone();
    if (clonedWidget)
    {
      v8::Local<v8::Object> jsRet = JsbUtils::NativePtrToObject(clonedWidget);
      args.GetReturnValue().Set(jsRet);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_clone : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_clone : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setFocusEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setFocusEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setFocusEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setFocusEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setFocusEnabled : Error processing arguments");
  //         cobj->setFocusEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool focusEnabled = args[0]->BooleanValue(isolate);
    cWidget->setFocusEnabled(focusEnabled);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setFocusEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_ui_Widget_getBottomBoundary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getBottomBoundary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getBottomBoundary : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getBottomBoundary : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getBottomBoundary();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double bottomBoundary = cWidget->getBottomBoundary();
    args.GetReturnValue().Set(v8::Number::New(isolate, bottomBoundary));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getBottomBoundary : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_isBright(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isBright(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isBright : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isBright : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isBright();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool isBright = cWidget->isBright();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, isBright));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isBright : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_ui_Widget_dispatchFocusEvent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_dispatchFocusEvent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_dispatchFocusEvent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_dispatchFocusEvent : Invalid Native Object");
  //     if (argc == 2) {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_dispatchFocusEvent : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::ui::Widget* arg0 = nullptr;
  //         cocos2d::ui::Widget* arg1 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  cocos2d::ui::Widget *arg0 = nullptr;
  cocos2d::ui::Widget *arg1 = nullptr;

  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_dispatchFocusEvent : Error processing arguments");
    return;
  }
  else if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    arg0 = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(arg0, "Invalid Native Object");
  }
  if (!args[1]->IsObject() && !args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_dispatchFocusEvent : Error processing arguments");
    return;
  }
  else if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    arg1 = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(arg1, "Invalid Native Object");
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_dispatchFocusEvent : Error processing arguments");
  //         cobj->dispatchFocusEvent(arg0, arg1);
  cWidget->dispatchFocusEvent(arg0, arg1);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_dispatchFocusEvent : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setUnifySizeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setUnifySizeEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setUnifySizeEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setUnifySizeEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setUnifySizeEnabled : Error processing arguments");
  //         cobj->setUnifySizeEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool unifySizeEnabled = args[0]->BooleanValue(isolate);
    cWidget->setUnifySizeEnabled(unifySizeEnabled);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setUnifySizeEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setUnifySizeEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isPropagateTouchEvents(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isPropagateTouchEvents(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isPropagateTouchEvents : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isPropagateTouchEvents : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isPropagateTouchEvents();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool propagateTouchEvents = cWidget->isPropagateTouchEvents();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, propagateTouchEvents));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isPropagateTouchEvents : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isPropagateTouchEvents : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_hitTest(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_hitTest(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_hitTest : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_hitTest : Invalid Native Object");
  //     if (argc == 3) {
  if (args.Length() != 3)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_hitTest : wrong number of arguments: %d, was expecting %d", args.Length(), 3);
    return;
  }
  //         cocos2d::Vec2 arg0;
  cocos2d::Vec2 point;
  //         const cocos2d::Camera* arg1 = nullptr;
  cocos2d::Camera *camera = nullptr;
  //         cocos2d::Vec3* arg2 = nullptr;
  cocos2d::Vec3 worldPoint;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  if (!JsbUtils::jsval_to_vector2(isolate, args[0], &point))
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_hitTest : Error processing arguments");
    return;
  }
  else if (!JsbUtils::jsval_to_vector3(isolate, args[0], &worldPoint))
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_hitTest : Error processing arguments");
    return;
  }
  //         do {
  //             if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //             if (!args.get(1).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (const cocos2d::Camera*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  if (!args[1]->IsObject() && !args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_hitTest : Error processing arguments");
    return;
  }
  else if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    camera = (cocos2d::Camera *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(camera, "Invalid Native Object");
  }

  //         } while (0);
  //         do {
  //             if (args.get(2).isNull()) { arg2 = nullptr; break; }
  //             if (!args.get(2).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(2).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg2 = (cocos2d::Vec3*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_hitTest : Error processing arguments");
  //         bool ret = cobj->hitTest(arg0, arg1, arg2);
  bool ret = cWidget->hitTest(point, camera, &worldPoint);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }
}

// bool js_cocos2dx_ui_Widget_isLayoutComponentEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isLayoutComponentEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isLayoutComponentEnabled : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isLayoutComponentEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isLayoutComponentEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool isLayoutComponentEnabled = cWidget->isLayoutComponentEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, isLayoutComponentEnabled));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isLayoutComponentEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_requestFocus(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_requestFocus(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_requestFocus : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_requestFocus : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->requestFocus();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cWidget->requestFocus();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_requestFocus : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_requestFocus : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_updateSizeAndPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_updateSizeAndPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::ui::Widget* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : nullptr);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_updateSizeAndPosition : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_updateSizeAndPosition : Invalid Native Object");
  //     do {
  //         if (argc == 1) {
  //             cocos2d::Size arg0;
  //             ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
  //             if (!ok) { ok = true; break; }
  //             cobj->updateSizeAndPosition(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);

  //     do {
  //         if (argc == 0) {
  //             cobj->updateSizeAndPosition();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);
  if (args.Length() == 1)
  {
    cocos2d::Size size;
    if (!JsbUtils::jsval_to_ccsize(isolate, args[0], &size))
    {
      SE_REPORT_ERROR("js_cocos2dx_ui_Widget_updateSizeAndPosition : Error processing arguments");
      return;
    }
    cWidget->updateSizeAndPosition(size);
    args.GetReturnValue().SetUndefined();
    return;
  }
  else if (args.Length() == 0)
  {
    cWidget->updateSizeAndPosition();
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_updateSizeAndPosition : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 1);

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_updateSizeAndPosition : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ui_Widget_onFocusChange(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_onFocusChange(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_onFocusChange : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_onFocusChange : Invalid Native Object");
  //     if (argc == 2) {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_onFocusChange : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::ui::Widget* arg0 = nullptr;
  cocos2d::ui::Widget *arg0 = nullptr;
  cocos2d::ui::Widget *arg1 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_onFocusChange : Error processing arguments");
    return;
  }
  else if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    arg0 = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(arg0, "Invalid Native Object");
  }

  if (!args[1]->IsObject() && !args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_onFocusChange : Error processing arguments");
    return;
  }
  else if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    arg1 = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(arg1, "Invalid Native Object");
  }
  //         do {
  //             if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //             if (!args.get(1).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_onFocusChange : Error processing arguments");
  //         cobj->onFocusChange(arg0, arg1);
  cWidget->onFocusChange(arg0, arg1);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_onFocusChange : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getTouchMovePosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getTouchMovePosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getTouchMovePosition : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getTouchMovePosition : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getTouchMovePosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &touchMovePosition = cWidget->getTouchMovePosition();
    args.GetReturnValue().Set(JsbUtils::vector2_to_jsval(isolate, touchMovePosition));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getTouchMovePosition : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getTouchMovePosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getSizeType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getSizeType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getSizeType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getSizeType : Invalid Native Object");
  if (args.Length() == 0)
  {
    int sizeType = (int)cWidget->getSizeType();
    args.GetReturnValue().Set(v8::Integer::New(isolate, sizeType));
    return;
  }
  //     if (argc == 0) {
  //         int ret = (int)cobj->getSizeType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getSizeType : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getSizeType : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getCallbackType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getCallbackType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getCallbackType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getCallbackType : Invalid Native Object");
  if (args.Length() == 0)
  {
    const std::string &callbackType = cWidget->getCallbackType();
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, callbackType));
    return;
  }
  //     if (argc == 0) {
  //         const std::string& ret = cobj->getCallbackType();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getCallbackType : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getCallbackType : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_addTouchEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_addTouchEventListener(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_addTouchEventListener : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_addTouchEventListener : Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_addTouchEventListener : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  // TODO: imp js_cocos2dx_ui_Widget_addTouchEventListener by hand
  CCASSERT(false, "TODO js_cocos2dx_ui_Widget_addTouchEventListener : Not supported");
  //         std::function<void (cocos2d::Ref *, cocos2d::ui::Widget::TouchEventType)> arg0;
  //         do {
  // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
  // 		    {
  // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
  // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
  // 		        auto lambda = [=](cocos2d::Ref* larg0, cocos2d::ui::Widget::TouchEventType larg1) -> void {
  // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
  // 		            jsval largv[2];
  // 		            if (larg0) {
  // 		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Ref>(cx, (cocos2d::Ref*)larg0));
  // 		        } else {
  // 		            largv[0] = JSVAL_NULL;
  // 		        };
  // 		            largv[1] = int32_to_jsval(cx, (int)larg1);
  // 		            JS::RootedValue rval(cx);
  // 		            bool succeed = func->invoke(2, &largv[0], &rval);
  // 		            if (!succeed && JS_IsExceptionPending(cx)) {
  // 		                JS_ReportPendingException(cx);
  // 		            }
  // 		        };
  // 		        arg0 = lambda;
  // 		    }
  // 		    else
  // 		    {
  // 		        arg0 = nullptr;
  // 		    }
  // 		} while(0)
  // 		;
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_addTouchEventListener : Error processing arguments");
  //         cobj->addTouchEventListener(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_addTouchEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getTouchEndPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getTouchEndPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getTouchEndPosition : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getTouchEndPosition : Invalid Native Object");
  //     if (argc == 0) {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getTouchEndPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Vec2& ret = cobj->getTouchEndPosition();
  const cocos2d::Vec2 &touchEndPosition = cWidget->getTouchEndPosition();
  //         JS::RootedValue jsret(cx);
  v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(isolate, touchEndPosition);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getTouchEndPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getPositionPercent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getPositionPercent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_getPositionPercent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_getPositionPercent : Invalid Native Object");
  //     if (argc == 0) {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getPositionPercent : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Vec2& ret = cobj->getPositionPercent();
  const cocos2d::Vec2 &positionPercent = cWidget->getPositionPercent();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(isolate, positionPercent);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getPositionPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_propagateTouchEvent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_propagateTouchEvent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_propagateTouchEvent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_propagateTouchEvent : Invalid Native Object");
  //     if (argc == 3) {
  if (args.Length() != 3)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_propagateTouchEvent : wrong number of arguments: %d, was expecting %d", args.Length(), 3);
    return;
  }
  //         cocos2d::ui::Widget::TouchEventType arg0;
  //         cocos2d::ui::Widget* arg1 = nullptr;
  cocos2d::ui::Widget *target = nullptr;
  //         cocos2d::Touch* arg2 = nullptr;
  cocos2d::Touch *event = nullptr;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  cocos2d::ui::Widget::TouchEventType touchEventType = (cocos2d::ui::Widget::TouchEventType)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         do {
  //             if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //             if (!args.get(1).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  if (!args[1]->IsObject() && !args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_propagateTouchEvent : Error processing arguments");
    return;
  }
  else if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    target = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(target, "Invalid Native Object");
  }
  //         do {
  //             if (args.get(2).isNull()) { arg2 = nullptr; break; }
  //             if (!args.get(2).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(2).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg2 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
  //         } while (0);
  if (!args[2]->IsObject() && !args[2]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_propagateTouchEvent : Error processing arguments");
    return;
  }
  else if (args[2]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[2]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    event = (cocos2d::Touch *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(event, "Invalid Native Object");
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_propagateTouchEvent : Error processing arguments");
  //         cobj->propagateTouchEvent(arg0, arg1, arg2);
  cWidget->propagateTouchEvent(touchEventType, target, event);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_propagateTouchEvent : wrong number of arguments: %d, was expecting %d", argc, 3);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_addClickEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_addClickEventListener(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_addClickEventListener : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_addClickEventListener : Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_addClickEventListener : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  // TODO: imp js_cocos2dx_ui_Widget_addClickEventListener by hand
  CCASSERT(false, "TODO js_cocos2dx_ui_Widget_addClickEventListener : Not supported");
  //         std::function<void (cocos2d::Ref *)> arg0;
  //         do {
  // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
  // 		    {
  // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
  // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
  // 		        auto lambda = [=](cocos2d::Ref* larg0) -> void {
  // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
  // 		            jsval largv[1];
  // 		            if (larg0) {
  // 		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Ref>(cx, (cocos2d::Ref*)larg0));
  // 		        } else {
  // 		            largv[0] = JSVAL_NULL;
  // 		        };
  // 		            JS::RootedValue rval(cx);
  // 		            bool succeed = func->invoke(1, &largv[0], &rval);
  // 		            if (!succeed && JS_IsExceptionPending(cx)) {
  // 		                JS_ReportPendingException(cx);
  // 		            }
  // 		        };
  // 		        arg0 = lambda;
  // 		    }
  // 		    else
  // 		    {
  // 		        arg0 = nullptr;
  // 		    }
  // 		} while(0)
  // 		;
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_addClickEventListener : Error processing arguments");
  //         cobj->addClickEventListener(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_addClickEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isFlippedX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isFlippedX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isFlippedX : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isFlippedX : Invalid Native Object");
  if (args.Length() == 0)
  {
    bool flippedX = cWidget->isFlippedX();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, flippedX));
    return;
  }
  //     if (argc == 0) {
  //         bool ret = cobj->isFlippedX();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isFlippedX : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isFlippedX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isFlippedY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isFlippedY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isFlippedY : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isFlippedY : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isFlippedY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0) {
  //         bool ret = cobj->isFlippedY();
  bool flippedY = cWidget->isFlippedY();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, flippedY));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isFlippedY : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isClippingParentContainsPoint(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isClippingParentContainsPoint(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isClippingParentContainsPoint : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isClippingParentContainsPoint : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isClippingParentContainsPoint : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  cocos2d::Vec2 point;
  if (!JsbUtils::jsval_to_vector2(isolate, args[0], &point))
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isClippingParentContainsPoint : Error processing arguments");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_isClippingParentContainsPoint : Error processing arguments");
  //         bool ret = cobj->isClippingParentContainsPoint(arg0);
  bool contains = cWidget->isClippingParentContainsPoint(point);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, contains));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isClippingParentContainsPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setSizeType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setSizeType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setSizeType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setSizeType : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setSizeType : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1) {
  //         cocos2d::ui::Widget::SizeType arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  cocos2d::ui::Widget::SizeType sizeType = (cocos2d::ui::Widget::SizeType)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setSizeType : Error processing arguments");
  //         cobj->setSizeType(arg0);
  cWidget->setSizeType(sizeType);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setSizeType : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_interceptTouchEvent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_interceptTouchEvent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_interceptTouchEvent : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_interceptTouchEvent : Invalid Native Object");
  //     if (argc == 3) {
  if (args.Length() != 3)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_interceptTouchEvent : wrong number of arguments: %d, was expecting %d", args.Length(), 3);
    return;
  }
  //         cocos2d::ui::Widget::TouchEventType arg0;
  cocos2d::ui::Widget::TouchEventType touchEventType = (cocos2d::ui::Widget::TouchEventType)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         cocos2d::ui::Widget* arg1 = nullptr;
  cocos2d::ui::Widget *target = nullptr;
  //         cocos2d::Touch* arg2 = nullptr;
  cocos2d::Touch *event = nullptr;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         do {
  //             if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //             if (!args.get(1).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::ui::Widget*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  if (!args[1]->IsObject() && !args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_interceptTouchEvent : Error processing arguments");
    return;
  }
  else if (args[1]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    target = (cocos2d::ui::Widget *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(target, "Invalid Native Object");
  }
  //         do {
  //             if (args.get(2).isNull()) { arg2 = nullptr; break; }
  //             if (!args.get(2).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(2).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg2 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
  //         } while (0);
  if (!args[2]->IsObject() && !args[2]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_interceptTouchEvent : Error processing arguments");
    return;
  }
  else if (args[2]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[2]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    event = (cocos2d::Touch *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(event, "Invalid Native Object");
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_interceptTouchEvent : Error processing arguments");
  //         cobj->interceptTouchEvent(arg0, arg1, arg2);
  cWidget->interceptTouchEvent(touchEventType, target, event);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_interceptTouchEvent : wrong number of arguments: %d, was expecting %d", argc, 3);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setBright(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setBright(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setBright : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setBright : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setBright : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setBright : Error processing arguments");
  //         cobj->setBright(arg0);
  bool bright = args[0]->BooleanValue(isolate);
  cWidget->setBright(bright);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setBright : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_setCallbackType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_setCallbackType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_setCallbackType : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_setCallbackType : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_setCallbackType : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_setCallbackType : Error processing arguments");
  std::string callbackType = JsbUtils::FromV8String(isolate, args[0]);
  //         cobj->setCallbackType(arg0);
  cWidget->setCallbackType(callbackType);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_setCallbackType : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_isSwallowTouches(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_isSwallowTouches(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Widget* cobj = (cocos2d::ui::Widget *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Widget *cWidget = (cocos2d::ui::Widget *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Widget_isSwallowTouches : Invalid Native Object");
  SE_PRECONDITION2(cWidget, "js_cocos2dx_ui_Widget_isSwallowTouches : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_isSwallowTouches : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0) {
  //         bool ret = cobj->isSwallowTouches();
  bool swallowTouches = cWidget->isSwallowTouches();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, swallowTouches));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_isSwallowTouches : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ui_Widget_enableDpadNavigation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_enableDpadNavigation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_enableDpadNavigation : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Widget_enableDpadNavigation : Error processing arguments");
  //         cocos2d::ui::Widget::enableDpadNavigation(arg0);
  bool enable = args[0]->BooleanValue(isolate);
  cocos2d::ui::Widget::enableDpadNavigation(enable);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_enableDpadNavigation : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ui_Widget_getCurrentFocusedWidget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_getCurrentFocusedWidget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_getCurrentFocusedWidget : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::ui::Widget* ret = cocos2d::ui::Widget::getCurrentFocusedWidget();
  cocos2d::ui::Widget *currentFocusedWidget = cocos2d::ui::Widget::getCurrentFocusedWidget();
  //         jsval jsret = JSVAL_NULL;
  //         if (ret) {
  //         jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Widget>(cx, (cocos2d::ui::Widget*)ret));
  if (currentFocusedWidget)
  {
    v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(currentFocusedWidget);
    args.GetReturnValue().Set(jsret);
  }
  else
  {
    args.GetReturnValue().SetNull();
  }

  //     } else {
  //         jsret = JSVAL_NULL;
  //     };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_getCurrentFocusedWidget : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ui_Widget_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ui_Widget_create : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         auto ret = cocos2d::ui::Widget::create();
  auto widget = cocos2d::ui::Widget::create();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Widget>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ui::Widget"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(widget);
  //         return true;
  //     }
  args.GetReturnValue().Set(jsret);
  //     JS_ReportError(cx, "js_cocos2dx_ui_Widget_create : wrong number of arguments");

  //     return false;
}

// bool js_cocos2dx_ui_Widget_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::ui::Widget* cobj = new (std::nothrow) cocos2d::ui::Widget();
  cocos2d::ui::Widget *cWidget = new (std::nothrow) cocos2d::ui::Widget();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Widget>(cobj);
  v8::Local<v8::Object> jsret = jsb_ref_create_jsobject(cWidget);
  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::Widget"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  args.GetReturnValue().Set(jsret);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsret);
  //     return true;
}

// static bool js_cocos2dx_ui_Widget_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Widget_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::ui::Widget *nobj = new (std::nothrow) cocos2d::ui::Widget();
  cocos2d::ui::Widget *cWidget = new (std::nothrow) cocos2d::ui::Widget();
  //     js_proxy_t* p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::Widget");
  v8::Local<v8::Object> jsobj = jsb_ref_autoreleased_create_jsobject(cWidget);
  //     bool isFound = false;
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //     return true;
}

// extern JSObject *jsb_cocos2d_ProtectedNode_prototype;

// void js_register_cocos2dx_ui_Widget(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_ui_Widget(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_ui_Widget_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_ui_Widget_class->name = "Widget";
  //     jsb_cocos2d_ui_Widget_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_ui_Widget_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_ui_Widget_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_ui_Widget_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_ui_Widget_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_ui_Widget_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_ui_Widget_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_ui_Widget_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::HandleScope handleScope(isolate);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_constructor);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Widget").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  auto parent = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::ProtectedNode).name());
  tpl->Inherit(v8::Local<v8::FunctionTemplate>::New(isolate, parent));
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();
  //     static JSPropertySpec properties[] = {
  //         JS_PS_END
  //     };

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setLayoutComponentEnabled", js_cocos2dx_ui_Widget_setLayoutComponentEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setLayoutComponentEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setLayoutComponentEnabled));
  //         JS_FN("setSizePercent", js_cocos2dx_ui_Widget_setSizePercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSizePercent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setSizePercent));
  //         JS_FN("getCustomSize", js_cocos2dx_ui_Widget_getCustomSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCustomSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getCustomSize));
  //         JS_FN("getLeftBoundary", js_cocos2dx_ui_Widget_getLeftBoundary, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLeftBoundary", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getLeftBoundary));
  //         JS_FN("setFlippedX", js_cocos2dx_ui_Widget_setFlippedX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFlippedX", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setFlippedX));
  //         JS_FN("setCallbackName", js_cocos2dx_ui_Widget_setCallbackName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCallbackName", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setCallbackName));
  //         JS_FN("getVirtualRenderer", js_cocos2dx_ui_Widget_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getVirtualRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getVirtualRenderer));
  //         JS_FN("setPropagateTouchEvents", js_cocos2dx_ui_Widget_setPropagateTouchEvents, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setPropagateTouchEvents", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setPropagateTouchEvents));
  //         JS_FN("isUnifySizeEnabled", js_cocos2dx_ui_Widget_isUnifySizeEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isUnifySizeEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isUnifySizeEnabled));
  //         JS_FN("getSizePercent", js_cocos2dx_ui_Widget_getSizePercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSizePercent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getSizePercent));
  //         JS_FN("setPositionPercent", js_cocos2dx_ui_Widget_setPositionPercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setPositionPercent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setPositionPercent));
  //         JS_FN("setSwallowTouches", js_cocos2dx_ui_Widget_setSwallowTouches, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSwallowTouches", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setSwallowTouches));
  //         JS_FN("getLayoutSize", js_cocos2dx_ui_Widget_getLayoutSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLayoutSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getLayoutSize));
  //         JS_FN("setHighlighted", js_cocos2dx_ui_Widget_setHighlighted, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setHighlighted", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setHighlighted));
  //         JS_FN("setPositionType", js_cocos2dx_ui_Widget_setPositionType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setPositionType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setPositionType));
  //         JS_FN("isIgnoreContentAdaptWithSize", js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isIgnoreContentAdaptWithSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isIgnoreContentAdaptWithSize));
  //         JS_FN("getVirtualRendererSize", js_cocos2dx_ui_Widget_getVirtualRendererSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getVirtualRendererSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getVirtualRendererSize));
  //         JS_FN("isHighlighted", js_cocos2dx_ui_Widget_isHighlighted, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isHighlighted", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isHighlighted));
  //         JS_FN("getLayoutParameter", js_cocos2dx_ui_Widget_getLayoutParameter, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLayoutParameter", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getLayoutParameter));
  //         JS_FN("addCCSEventListener", js_cocos2dx_ui_Widget_addCCSEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addCCSEventListener", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_addCCSEventListener));
  //         JS_FN("getPositionType", js_cocos2dx_ui_Widget_getPositionType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getPositionType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getPositionType));
  //         JS_FN("getTopBoundary", js_cocos2dx_ui_Widget_getTopBoundary, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTopBoundary", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getTopBoundary));
  //         JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ignoreContentAdaptWithSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_ignoreContentAdaptWithSize));
  //         JS_FN("findNextFocusedWidget", js_cocos2dx_ui_Widget_findNextFocusedWidget, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "findNextFocusedWidget", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_findNextFocusedWidget));
  //         JS_FN("isEnabled", js_cocos2dx_ui_Widget_isEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isEnabled));
  //         JS_FN("isFocused", js_cocos2dx_ui_Widget_isFocused, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFocused", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isFocused));
  //         JS_FN("getTouchBeganPosition", js_cocos2dx_ui_Widget_getTouchBeganPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTouchBeganPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getTouchBeganPosition));
  //         JS_FN("isTouchEnabled", js_cocos2dx_ui_Widget_isTouchEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isTouchEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isTouchEnabled));
  //         JS_FN("getCallbackName", js_cocos2dx_ui_Widget_getCallbackName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCallbackName", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getCallbackName));
  //         JS_FN("getActionTag", js_cocos2dx_ui_Widget_getActionTag, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getActionTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getActionTag));
  //         JS_FN("getWorldPosition", js_cocos2dx_ui_Widget_getWorldPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getWorldPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getWorldPosition));
  //         JS_FN("isFocusEnabled", js_cocos2dx_ui_Widget_isFocusEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFocusEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isFocusEnabled));
  //         JS_FN("setFocused", js_cocos2dx_ui_Widget_setFocused, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFocused", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setFocused));
  //         JS_FN("setActionTag", js_cocos2dx_ui_Widget_setActionTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setActionTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setActionTag));
  //         JS_FN("setTouchEnabled", js_cocos2dx_ui_Widget_setTouchEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTouchEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setTouchEnabled));
  //         JS_FN("setFlippedY", js_cocos2dx_ui_Widget_setFlippedY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFlippedY", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setFlippedY));
  //         JS_FN("_init", js_cocos2dx_ui_Widget_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "_init", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_init));
  //         JS_FN("setEnabled", js_cocos2dx_ui_Widget_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setEnabled));
  //         JS_FN("getRightBoundary", js_cocos2dx_ui_Widget_getRightBoundary, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getRightBoundary", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getRightBoundary));
  //         JS_FN("setBrightStyle", js_cocos2dx_ui_Widget_setBrightStyle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBrightStyle", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setBrightStyle));
  //         JS_FN("setLayoutParameter", js_cocos2dx_ui_Widget_setLayoutParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setLayoutParameter", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setLayoutParameter));
  //         JS_FN("clone", js_cocos2dx_ui_Widget_clone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "clone", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_clone));
  //         JS_FN("setFocusEnabled", js_cocos2dx_ui_Widget_setFocusEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFocusEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setFocusEnabled));
  //         JS_FN("getBottomBoundary", js_cocos2dx_ui_Widget_getBottomBoundary, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBottomBoundary", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getBottomBoundary));
  //         JS_FN("isBright", js_cocos2dx_ui_Widget_isBright, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isBright", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isBright));
  //         JS_FN("dispatchFocusEvent", js_cocos2dx_ui_Widget_dispatchFocusEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "dispatchFocusEvent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_dispatchFocusEvent));
  //         JS_FN("setUnifySizeEnabled", js_cocos2dx_ui_Widget_setUnifySizeEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setUnifySizeEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setUnifySizeEnabled));
  //         JS_FN("isPropagateTouchEvents", js_cocos2dx_ui_Widget_isPropagateTouchEvents, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isPropagateTouchEvents", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isPropagateTouchEvents));
  //         JS_FN("hitTest", js_cocos2dx_ui_Widget_hitTest, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "hitTest", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_hitTest));
  //         JS_FN("isLayoutComponentEnabled", js_cocos2dx_ui_Widget_isLayoutComponentEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isLayoutComponentEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isLayoutComponentEnabled));
  //         JS_FN("requestFocus", js_cocos2dx_ui_Widget_requestFocus, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "requestFocus", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_requestFocus));
  //         JS_FN("updateSizeAndPosition", js_cocos2dx_ui_Widget_updateSizeAndPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "updateSizeAndPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_updateSizeAndPosition));
  //         JS_FN("onFocusChange", js_cocos2dx_ui_Widget_onFocusChange, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "onFocusChange", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_onFocusChange));
  //         JS_FN("getTouchMovePosition", js_cocos2dx_ui_Widget_getTouchMovePosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTouchMovePosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getTouchMovePosition));
  //         JS_FN("getSizeType", js_cocos2dx_ui_Widget_getSizeType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSizeType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getSizeType));
  //         JS_FN("getCallbackType", js_cocos2dx_ui_Widget_getCallbackType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCallbackType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getCallbackType));
  //         JS_FN("addTouchEventListener", js_cocos2dx_ui_Widget_addTouchEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addTouchEventListener", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_addTouchEventListener));
  //         JS_FN("getTouchEndPosition", js_cocos2dx_ui_Widget_getTouchEndPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTouchEndPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getTouchEndPosition));
  //         JS_FN("getPositionPercent", js_cocos2dx_ui_Widget_getPositionPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getPositionPercent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getPositionPercent));
  //         JS_FN("propagateTouchEvent", js_cocos2dx_ui_Widget_propagateTouchEvent, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "propagateTouchEvent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_propagateTouchEvent));
  //         JS_FN("addClickEventListener", js_cocos2dx_ui_Widget_addClickEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addClickEventListener", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_addClickEventListener));
  //         JS_FN("isFlippedX", js_cocos2dx_ui_Widget_isFlippedX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFlippedX", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isFlippedX));
  //         JS_FN("isFlippedY", js_cocos2dx_ui_Widget_isFlippedY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFlippedY", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isFlippedY));
  //         JS_FN("isClippingParentContainsPoint", js_cocos2dx_ui_Widget_isClippingParentContainsPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isClippingParentContainsPoint", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isClippingParentContainsPoint));
  //         JS_FN("setSizeType", js_cocos2dx_ui_Widget_setSizeType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSizeType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setSizeType));
  //         JS_FN("interceptTouchEvent", js_cocos2dx_ui_Widget_interceptTouchEvent, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "interceptTouchEvent", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_interceptTouchEvent));
  //         JS_FN("setBright", js_cocos2dx_ui_Widget_setBright, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBright", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setBright));
  //         JS_FN("setCallbackType", js_cocos2dx_ui_Widget_setCallbackType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCallbackType", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_setCallbackType));
  //         JS_FN("isSwallowTouches", js_cocos2dx_ui_Widget_isSwallowTouches, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isSwallowTouches", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_isSwallowTouches));
  //         JS_FN("ctor", js_cocos2dx_ui_Widget_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_ctor));
  //         JS_FS_END
  //     };

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("enableDpadNavigation", js_cocos2dx_ui_Widget_enableDpadNavigation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "enableDpadNavigation", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_enableDpadNavigation));
  //         JS_FN("getCurrentFocusedWidget", js_cocos2dx_ui_Widget_getCurrentFocusedWidget, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getCurrentFocusedWidget", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_getCurrentFocusedWidget));
  //         JS_FN("create", js_cocos2dx_ui_Widget_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Widget_create));
  //         JS_FS_END
  //     };

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_ProtectedNode_prototype);
  //     jsb_cocos2d_ui_Widget_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_ui_Widget_class,
  //         js_cocos2dx_ui_Widget_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_ui_Widget_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Widget"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "Widget"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  proto->Set(isolate, "__is_ref", v8::True(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::ui::Widget>(cx, jsb_cocos2d_ui_Widget_class, proto, parent_proto);
  //     anonEvaluate(cx, global, "(function () { ccui.Widget.extend = cc.Class.extend; })()");
  JsbUtils::RegisterV8Class(typeid(cocos2d::ui::Widget).name(), &tpl);
  JsbUtils::BindJsClass("Widget", global, tpl);
}
