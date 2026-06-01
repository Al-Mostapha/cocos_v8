#include "JsbUIScrollView.hpp"
#include "JsbCtor.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "ui/UIScrollView.h"
// JSClass  *jsb_cocos2d_ui_ScrollView_class;
// JSObject *jsb_cocos2d_ui_ScrollView_prototype;

// bool js_cocos2dx_ui_ScrollView_scrollToTop(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_scrollToTop(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTop : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_scrollToTop : Invalid Native Object");

  //     if (argc == 2) {
  //         double arg0 = 0;
  //         bool arg1;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTop : Error processing arguments");
  //         cobj->scrollToTop(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(isolate);
    cobj->scrollToTop(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToTop : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_scrollToTop : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal : Invalid Native Object");
  //     if (argc == 3) {
  //         double arg0 = 0;
  //         double arg1 = 0;
  //         bool arg2;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         arg2 = JS::ToBoolean(args.get(2));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal : Error processing arguments");
  //         cobj->scrollToPercentHorizontal(arg0, arg1, arg2);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    double arg1 = args[1]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool arg2 = args[2]->BooleanValue(isolate);
    cobj->scrollToPercentHorizontal(arg0, arg1, arg2);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal : wrong number of arguments: %d, was expecting %d", argc, 3);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 3);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_setScrollBarOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_setScrollBarOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarOpacity : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_setScrollBarOpacity : Invalid Native Object");
  //     if (argc == 1) {
  //         uint16_t arg0;
  //         ok &= jsval_to_uint16(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarOpacity : Error processing arguments");
  //         cobj->setScrollBarOpacity(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    uint16_t arg0 = (uint16_t)args[0]->Uint32Value(isolate->GetCurrentContext()).FromJust();
    cobj->setScrollBarOpacity(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_setScrollBarOpacity : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_setScrollBarEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_setScrollBarEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_setScrollBarEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarEnabled : Error processing arguments");
  //         cobj->setScrollBarEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(isolate);
    cobj->setScrollBarEnabled(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_setScrollBarEnabled : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isInertiaScrollEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->isInertiaScrollEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_scrollToBottom(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_scrollToBottom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottom : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_scrollToBottom : Invalid Native Object");
  //     if (argc == 2) {
  //         double arg0 = 0;
  //         bool arg1;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottom : Error processing arguments");
  //         cobj->scrollToBottom(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(isolate);
    cobj->scrollToBottom(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToBottom : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_scrollToBottom : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Vec2 ret = cobj->getScrolledPercentBothDirection();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Vec2 ret = cobj->getScrolledPercentBothDirection();
    args.GetReturnValue().Set(JsbUtils::vector2_to_jsval(isolate, ret));
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_getDirection(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_getDirection(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getDirection : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_getDirection : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getDirection();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getDirection();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getDirection : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_getDirection : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_setScrollBarColor(JSContext *cx, uint32_t argc, jsval *vp)
// {.
void js_cocos2dx_ui_ScrollView_setScrollBarColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarColor : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_setScrollBarColor : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Color3B arg0;
  //         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarColor : Error processing arguments");
  //         cobj->setScrollBarColor(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Color3B arg0;
    JsbUtils::jsval_to_cccolor3b(isolate, args[0], &arg0);
    cobj->setScrollBarColor(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_setScrollBarColor : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_scrollToBottomLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_scrollToBottomLeft(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : Invalid Native Object");
  //     if (argc == 2) {
  //         double arg0 = 0;
  //         bool arg1;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : Error processing arguments");
  //         cobj->scrollToBottomLeft(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(isolate);
    cobj->scrollToBottomLeft(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : Invalid Native Object");
  //     if (argc == 2) {
  //         double arg0 = 0;
  //         bool arg1;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : Error processing arguments");
  //         cobj->scrollToBottomLeft(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToBottomLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_scrollToBottomLeft : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_getInnerContainer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_getInnerContainer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getInnerContainer : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_getInnerContainer : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::ui::Layout* ret = cobj->getInnerContainer();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Layout>(cx, (cocos2d::ui::Layout*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::ui::Layout *ret = cobj->getInnerContainer();
    if (ret)
    {
      args.GetReturnValue().Set(JsbUtils::NativePtrToObject(ret));
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getInnerContainer : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_getInnerContainer : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_jumpToBottom(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_jumpToBottom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToBottom : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_jumpToBottom : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->jumpToBottom();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->jumpToBottom();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToBottom : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_jumpToBottom : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_setInnerContainerPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_setInnerContainerPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setInnerContainerPosition : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_setInnerContainerPosition : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setInnerContainerPosition : Error processing arguments");
  //         cobj->setInnerContainerPosition(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    JsbUtils::jsval_to_vector2(isolate, args[0], &arg0);
    cobj->setInnerContainerPosition(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setInnerContainerPosition : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_setInnerContainerPosition : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_setDirection(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setDirection : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_setDirection : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::ui::ScrollView::Direction arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setDirection : Error processing arguments");
  //         cobj->setDirection(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int32_t arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cobj->setDirection((cocos2d::ui::ScrollView::Direction)arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_setDirection : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);

  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_scrollToTopLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_scrollToTopLeft(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTopLeft : Invalid Native Object");

  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_scrollToTopLeft : Invalid Native Object");
  //     if (argc == 2) {
  //         double arg0 = 0;
  //         bool arg1;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTopLeft : Error processing arguments");
  //         cobj->scrollToTopLeft(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(isolate);
    cobj->scrollToTopLeft(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToTopLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_scrollToTopLeft : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_jumpToTopRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ScrollView_jumpToTopRight(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ScrollView *cobj = (cocos2d::ui::ScrollView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToTopRight : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ScrollView_jumpToTopRight : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->jumpToTopRight();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->jumpToTopRight();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToTopRight : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ScrollView_jumpToTopRight : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ScrollView_scrollToPercentBothDirection(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentBothDirection : Invalid Native Object");
//     if (argc == 3) {
//         cocos2d::Vec2 arg0;
//         double arg1 = 0;
//         bool arg2;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
//         arg2 = JS::ToBoolean(args.get(2));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentBothDirection : Error processing arguments");
//         cobj->scrollToPercentBothDirection(arg0, arg1, arg2);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToPercentBothDirection : wrong number of arguments: %d, was expecting %d", argc, 3);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setInnerContainerSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setInnerContainerSize : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Size arg0;
//         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setInnerContainerSize : Error processing arguments");
//         cobj->setInnerContainerSize(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setInnerContainerSize : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getInnerContainerPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getInnerContainerPosition : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Vec2& ret = cobj->getInnerContainerPosition();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getInnerContainerPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToTop(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToTop : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToTop();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToTop : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrolledPercentVertical(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrolledPercentVertical : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getScrolledPercentVertical();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrolledPercentVertical : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_isBounceEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isBounceEnabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isBounceEnabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isBounceEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToPercentVertical(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentVertical : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentVertical : Error processing arguments");
//         cobj->jumpToPercentVertical(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToPercentVertical : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
//

// bool js_cocos2dx_ui_ScrollView_addEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_addEventListener : Invalid Native Object");
//     if (argc == 1) {
//         std::function<void (cocos2d::Ref *, cocos2d::ui::ScrollView::EventType)> arg0;
//         do {
// 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
// 		    {
// 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
// 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
// 		        auto lambda = [=](cocos2d::Ref* larg0, cocos2d::ui::ScrollView::EventType larg1) -> void {
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
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_addEventListener : Error processing arguments");
//         cobj->addEventListener(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_addEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarAutoHideTime(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideTime : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideTime : Error processing arguments");
//         cobj->setScrollBarAutoHideTime(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideTime : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_stopScroll(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_stopScroll : Invalid Native Object");
//     if (argc == 0) {
//         cobj->stopScroll();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_stopScroll : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec2 arg0;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal : Error processing arguments");
//         cobj->setScrollBarPositionFromCornerForHorizontal(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setInertiaScrollEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setInertiaScrollEnabled : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setInertiaScrollEnabled : Error processing arguments");
//         cobj->setInertiaScrollEnabled(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setInertiaScrollEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarAutoHideEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideEnabled : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideEnabled : Error processing arguments");
//         cobj->setScrollBarAutoHideEnabled(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarAutoHideEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getScrollBarColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToTopLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToTopLeft : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToTopLeft();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToTopLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_isScrollBarEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isScrollBarEnabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isScrollBarEnabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isScrollBarEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_isAutoScrolling(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isAutoScrolling : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isAutoScrolling();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isAutoScrolling : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToBottomRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToBottomRight : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToBottomRight();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToBottomRight : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setTouchTotalTimeThreshold(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setTouchTotalTimeThreshold : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setTouchTotalTimeThreshold : Error processing arguments");
//         cobj->setTouchTotalTimeThreshold(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setTouchTotalTimeThreshold : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getTouchTotalTimeThreshold(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getTouchTotalTimeThreshold : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getTouchTotalTimeThreshold();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getTouchTotalTimeThreshold : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::Vec2 ret = cobj->getScrollBarPositionFromCornerForHorizontal();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrolledPercentHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrolledPercentHorizontal : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getScrolledPercentHorizontal();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrolledPercentHorizontal : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setBounceEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setBounceEnabled : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setBounceEnabled : Error processing arguments");
//         cobj->setBounceEnabled(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setBounceEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_stopAutoScroll(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_stopAutoScroll : Invalid Native Object");
//     if (argc == 0) {
//         cobj->stopAutoScroll();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_stopAutoScroll : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_scrollToTopRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTopRight : Invalid Native Object");
//     if (argc == 2) {
//         double arg0 = 0;
//         bool arg1;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToTopRight : Error processing arguments");
//         cobj->scrollToTopRight(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToTopRight : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_isScrolling(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isScrolling : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isScrolling();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isScrolling : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_scrollToLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToLeft : Invalid Native Object");
//     if (argc == 2) {
//         double arg0 = 0;
//         bool arg1;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToLeft : Error processing arguments");
//         cobj->scrollToLeft(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToPercentBothDirection(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentBothDirection : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec2 arg0;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentBothDirection : Error processing arguments");
//         cobj->jumpToPercentBothDirection(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToPercentBothDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_stopOverallScroll(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_stopOverallScroll : Invalid Native Object");
//     if (argc == 0) {
//         cobj->stopOverallScroll();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_stopOverallScroll : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_scrollToPercentVertical(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentVertical : Invalid Native Object");
//     if (argc == 3) {
//         double arg0 = 0;
//         double arg1 = 0;
//         bool arg2;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
//         arg2 = JS::ToBoolean(args.get(2));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToPercentVertical : Error processing arguments");
//         cobj->scrollToPercentVertical(arg0, arg1, arg2);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToPercentVertical : wrong number of arguments: %d, was expecting %d", argc, 3);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarWidth : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarWidth : Error processing arguments");
//         cobj->setScrollBarWidth(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarWidth : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarOpacity : Invalid Native Object");
//     if (argc == 0) {
//         uint16_t ret = cobj->getScrollBarOpacity();
//         JS::RootedValue jsret(cx);
//         jsret = uint32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_scrollToBottomRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomRight : Invalid Native Object");
//     if (argc == 2) {
//         double arg0 = 0;
//         bool arg1;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToBottomRight : Error processing arguments");
//         cobj->scrollToBottomRight(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToBottomRight : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCorner(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCorner : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec2 arg0;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCorner : Error processing arguments");
//         cobj->setScrollBarPositionFromCorner(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCorner : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForVertical(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForVertical : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec2 arg0;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForVertical : Error processing arguments");
//         cobj->setScrollBarPositionFromCornerForVertical(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForVertical : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarAutoHideTime(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarAutoHideTime : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getScrollBarAutoHideTime();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarAutoHideTime : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToLeft : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToLeft();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_scrollToRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_scrollToRight : Invalid Native Object");
//     if (argc == 2) {
//         double arg0 = 0;
//         bool arg1;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_scrollToRight : Error processing arguments");
//         cobj->scrollToRight(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_scrollToRight : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForVertical(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForVertical : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::Vec2 ret = cobj->getScrollBarPositionFromCornerForVertical();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForVertical : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getScrollBarWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getScrollBarWidth : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getScrollBarWidth();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getScrollBarWidth : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_isScrollBarAutoHideEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_isScrollBarAutoHideEnabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isScrollBarAutoHideEnabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_isScrollBarAutoHideEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToBottomLeft(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToBottomLeft : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToBottomLeft();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToBottomLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToRight(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToRight : Invalid Native Object");
//     if (argc == 0) {
//         cobj->jumpToRight();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToRight : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_getInnerContainerSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_getInnerContainerSize : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Size& ret = cobj->getInnerContainerSize();
//         JS::RootedValue jsret(cx);
//         jsret = ccsize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_getInnerContainerSize : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_jumpToPercentHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::ScrollView* cobj = (cocos2d::ui::ScrollView *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentHorizontal : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ScrollView_jumpToPercentHorizontal : Error processing arguments");
//         cobj->jumpToPercentHorizontal(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_jumpToPercentHorizontal : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_ScrollView_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0) {

//         auto ret = cocos2d::ui::ScrollView::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::ScrollView>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ui::ScrollView"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ui_ScrollView_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ui_ScrollView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ui::ScrollView* cobj = new (std::nothrow) cocos2d::ui::ScrollView();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::ScrollView>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::ScrollView"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_ui_ScrollView_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::ui::ScrollView *nobj = new (std::nothrow) cocos2d::ui::ScrollView();
//     js_proxy_t* p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::ScrollView");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_ui_Layout_prototype;

// void js_register_cocos2dx_ui_ScrollView(JSContext *cx, JS::HandleObject global) {
//     jsb_cocos2d_ui_ScrollView_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ui_ScrollView_class->name = "ScrollView";
//     jsb_cocos2d_ui_ScrollView_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_ScrollView_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ui_ScrollView_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_ScrollView_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ui_ScrollView_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ui_ScrollView_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ui_ScrollView_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ui_ScrollView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END
//     };

//     static JSFunctionSpec funcs[] = {
//         JS_FN("scrollToTop", js_cocos2dx_ui_ScrollView_scrollToTop, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToPercentHorizontal", js_cocos2dx_ui_ScrollView_scrollToPercentHorizontal, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarOpacity", js_cocos2dx_ui_ScrollView_setScrollBarOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarEnabled", js_cocos2dx_ui_ScrollView_setScrollBarEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isInertiaScrollEnabled", js_cocos2dx_ui_ScrollView_isInertiaScrollEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToBottom", js_cocos2dx_ui_ScrollView_scrollToBottom, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrolledPercentBothDirection", js_cocos2dx_ui_ScrollView_getScrolledPercentBothDirection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getDirection", js_cocos2dx_ui_ScrollView_getDirection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarColor", js_cocos2dx_ui_ScrollView_setScrollBarColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToBottomLeft", js_cocos2dx_ui_ScrollView_scrollToBottomLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getInnerContainer", js_cocos2dx_ui_ScrollView_getInnerContainer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToBottom", js_cocos2dx_ui_ScrollView_jumpToBottom, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setInnerContainerPosition", js_cocos2dx_ui_ScrollView_setInnerContainerPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setDirection", js_cocos2dx_ui_ScrollView_setDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToTopLeft", js_cocos2dx_ui_ScrollView_scrollToTopLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToTopRight", js_cocos2dx_ui_ScrollView_jumpToTopRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToPercentBothDirection", js_cocos2dx_ui_ScrollView_scrollToPercentBothDirection, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setInnerContainerSize", js_cocos2dx_ui_ScrollView_setInnerContainerSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getInnerContainerPosition", js_cocos2dx_ui_ScrollView_getInnerContainerPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToTop", js_cocos2dx_ui_ScrollView_jumpToTop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrolledPercentVertical", js_cocos2dx_ui_ScrollView_getScrolledPercentVertical, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isBounceEnabled", js_cocos2dx_ui_ScrollView_isBounceEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToPercentVertical", js_cocos2dx_ui_ScrollView_jumpToPercentVertical, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addEventListener", js_cocos2dx_ui_ScrollView_addEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarAutoHideTime", js_cocos2dx_ui_ScrollView_setScrollBarAutoHideTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("stopScroll", js_cocos2dx_ui_ScrollView_stopScroll, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarPositionFromCornerForHorizontal", js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setInertiaScrollEnabled", js_cocos2dx_ui_ScrollView_setInertiaScrollEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarAutoHideEnabled", js_cocos2dx_ui_ScrollView_setScrollBarAutoHideEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarColor", js_cocos2dx_ui_ScrollView_getScrollBarColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToTopLeft", js_cocos2dx_ui_ScrollView_jumpToTopLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isScrollBarEnabled", js_cocos2dx_ui_ScrollView_isScrollBarEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isAutoScrolling", js_cocos2dx_ui_ScrollView_isAutoScrolling, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToBottomRight", js_cocos2dx_ui_ScrollView_jumpToBottomRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTouchTotalTimeThreshold", js_cocos2dx_ui_ScrollView_setTouchTotalTimeThreshold, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTouchTotalTimeThreshold", js_cocos2dx_ui_ScrollView_getTouchTotalTimeThreshold, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarPositionFromCornerForHorizontal", js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrolledPercentHorizontal", js_cocos2dx_ui_ScrollView_getScrolledPercentHorizontal, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBounceEnabled", js_cocos2dx_ui_ScrollView_setBounceEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("stopAutoScroll", js_cocos2dx_ui_ScrollView_stopAutoScroll, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToTopRight", js_cocos2dx_ui_ScrollView_scrollToTopRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isScrolling", js_cocos2dx_ui_ScrollView_isScrolling, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToLeft", js_cocos2dx_ui_ScrollView_scrollToLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToPercentBothDirection", js_cocos2dx_ui_ScrollView_jumpToPercentBothDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("stopOverallScroll", js_cocos2dx_ui_ScrollView_stopOverallScroll, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToPercentVertical", js_cocos2dx_ui_ScrollView_scrollToPercentVertical, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarWidth", js_cocos2dx_ui_ScrollView_setScrollBarWidth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarOpacity", js_cocos2dx_ui_ScrollView_getScrollBarOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToBottomRight", js_cocos2dx_ui_ScrollView_scrollToBottomRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarPositionFromCorner", js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCorner, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setScrollBarPositionFromCornerForVertical", js_cocos2dx_ui_ScrollView_setScrollBarPositionFromCornerForVertical, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarAutoHideTime", js_cocos2dx_ui_ScrollView_getScrollBarAutoHideTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToLeft", js_cocos2dx_ui_ScrollView_jumpToLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("scrollToRight", js_cocos2dx_ui_ScrollView_scrollToRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarPositionFromCornerForVertical", js_cocos2dx_ui_ScrollView_getScrollBarPositionFromCornerForVertical, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getScrollBarWidth", js_cocos2dx_ui_ScrollView_getScrollBarWidth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isScrollBarAutoHideEnabled", js_cocos2dx_ui_ScrollView_isScrollBarAutoHideEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToBottomLeft", js_cocos2dx_ui_ScrollView_jumpToBottomLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToRight", js_cocos2dx_ui_ScrollView_jumpToRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getInnerContainerSize", js_cocos2dx_ui_ScrollView_getInnerContainerSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("jumpToPercentHorizontal", js_cocos2dx_ui_ScrollView_jumpToPercentHorizontal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_ui_ScrollView_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ui_ScrollView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ui_Layout_prototype);
//     jsb_cocos2d_ui_ScrollView_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ui_ScrollView_class,
//         js_cocos2dx_ui_ScrollView_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ui_ScrollView_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ScrollView"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ui::ScrollView>(cx, jsb_cocos2d_ui_ScrollView_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { ccui.ScrollView.extend = cc.Class.extend; })()");
// }
