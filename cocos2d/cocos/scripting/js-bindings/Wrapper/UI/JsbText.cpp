#include "JsbText.hpp"
#include "ui/UIText.h"
#include "JsbCtor.hpp"
#include "JsbUtils.h"
#include "2d/CCSprite.h"

// JSClass  *jsb_cocos2d_ui_Text_class;
// JSObject *jsb_cocos2d_ui_Text_prototype;

// bool js_cocos2dx_ui_Text_enableShadow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_enableShadow : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_constructor : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->enableShadow();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cText->enableShadow();
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 1) {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  else if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    bool ok = JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
    cText->enableShadow(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 2) {
  //         cocos2d::Color4B arg0;
  //         cocos2d::Size arg1;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ccsize(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  else if (args.Length() == 2)
  {
    cocos2d::Color4B arg0;
    cocos2d::Size arg1;
    bool ok = true;
    ok &= JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0);
    ok &= JsbUtils::jsval_to_ccsize(isolate, args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
    cText->enableShadow(arg0, arg1);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 3) {
  //         cocos2d::Color4B arg0;
  //         cocos2d::Size arg1;
  //         int arg2 = 0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ccsize(cx, args.get(1), &arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0, arg1, arg2);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  else if (args.Length() == 3)
  {
    cocos2d::Color4B arg0;
    cocos2d::Size arg1;
    int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
    bool ok = true;
    ok &= JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0);
    ok &= JsbUtils::jsval_to_ccsize(isolate, args[1], &arg1);

    SE_PRECONDITION2(ok, "js_cocos2dx_ui_Text_enableShadow : Error processing arguments");
    cText->enableShadow(arg0, arg1, arg2);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_enableShadow : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_enableShadow : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getFontSize : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getFontSize : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getFontSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cText->getFontSize();
    args.GetReturnValue().Set(v8::Number::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getFontSize : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getString(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getString(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getString : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getString : Invalid Native Object");
  //     if (argc == 0) {
  //         const std::string& ret = cobj->getString();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::string &ret = cText->getString();
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getString : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getString : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_disableEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_disableEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::ui::Text* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : nullptr);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_disableEffect : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_disableEffect : Invalid Native Object");
  //     do {
  //         if (argc == 1) {
  //             cocos2d::LabelEffect arg0;
  //             ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //             if (!ok) { ok = true; break; }
  //             cobj->disableEffect(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    cocos2d::LabelEffect arg0 = (cocos2d::LabelEffect)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cText->disableEffect(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     } while(0);

  //     do {
  //         if (argc == 0) {
  //             cobj->disableEffect();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cText->disableEffect();
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     } while(0);

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_disableEffect : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_disableEffect : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getLabelEffectType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getLabelEffectType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getLabelEffectType : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getLabelEffectType : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getLabelEffectType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cText->getLabelEffectType();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getLabelEffectType : wrong number of arguments: %d", args.Length());
}

// bool js_cocos2dx_ui_Text_getTextColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getTextColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getTextColor : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getTextColor : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Color4B& ret = cobj->getTextColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Color4B &ret = cText->getTextColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4b_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getTextColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getTextColor : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getBlendFunc : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::BlendFunc& ret = cobj->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::BlendFunc &ret = cText->getBlendFunc();
    args.GetReturnValue().Set(JsbUtils::blendfunc_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getBlendFunc : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setTextVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setTextVerticalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setTextVerticalAlignment : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setTextVerticalAlignment : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::TextVAlignment arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setTextVerticalAlignment : Error processing arguments");
  //         cobj->setTextVerticalAlignment(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::TextVAlignment arg0 = (cocos2d::TextVAlignment)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cText->setTextVerticalAlignment(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setTextVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setTextVerticalAlignment : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setFontName : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setFontName : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setFontName : Error processing arguments");
  //         cobj->setFontName(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    cText->setFontName(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setFontName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_Text_setTouchScaleChangeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setTouchScaleChangeEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setTouchScaleChangeEnabled : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setTouchScaleChangeEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setTouchScaleChangeEnabled : Error processing arguments");
  //         cobj->setTouchScaleChangeEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(isolate);
    cText->setTouchScaleChangeEnabled(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setTouchScaleChangeEnabled : wrong number of arguments: %d", args.Length());

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setTouchScaleChangeEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Text_getShadowOffset(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getShadowOffset(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getShadowOffset : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getShadowOffset : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Size ret = cobj->getShadowOffset();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Size ret = cText->getShadowOffset();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getShadowOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getShadowOffset : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setString(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setString(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setString : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setString : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setString : Error processing arguments");
  //         cobj->setString(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    cText->setString(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setString : wrong number of arguments: %d", args.Length());

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setString : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Text_getOutlineSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getOutlineSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getOutlineSize : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getOutlineSize : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getOutlineSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cText->getOutlineSize();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getOutlineSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getOutlineSize : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_init : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_init : Invalid Native Object");
  //     if (argc == 3) {
  //         std::string arg0;
  //         std::string arg1;
  //         double arg2 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_init : Error processing arguments");
  //         bool ret = cobj->init(arg0, arg1, arg2);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    double arg2 = args[2]->NumberValue(isolate->GetCurrentContext()).FromJust();
    bool ret = cText->init(arg0, arg1, arg2);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_init : wrong number of arguments: %d", args.Length());

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_init : wrong number of arguments: %d, was expecting %d", argc, 3);
  //     return false;
}

// bool js_cocos2dx_ui_Text_getShadowBlurRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getShadowBlurRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getShadowBlurRadius : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getShadowBlurRadius : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getShadowBlurRadius();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cText->getShadowBlurRadius();
    args.GetReturnValue().Set(v8::Number::New(isolate, ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getShadowBlurRadius : wrong number of arguments: %d", args.Length());
}

// bool js_cocos2dx_ui_Text_isTouchScaleChangeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_isTouchScaleChangeEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_isTouchScaleChangeEnabled : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_isTouchScaleChangeEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isTouchScaleChangeEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cText->isTouchScaleChangeEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_isTouchScaleChangeEnabled : wrong number of arguments: %d", args.Length());
}

// bool js_cocos2dx_ui_Text_getFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getFontName : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getFontName : Invalid Native Object");
  //     if (argc == 0) {
  //         const std::string& ret = cobj->getFontName();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::string &ret = cText->getFontName();
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getFontName : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getFontName : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setTextAreaSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setTextAreaSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setTextAreaSize : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setTextAreaSize : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Size arg0;
  //         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setTextAreaSize : Error processing arguments");
  //         cobj->setTextAreaSize(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Size arg0;
    if (JsbUtils::jsval_to_ccsize(isolate, args[0], &arg0))
    {
      cText->setTextAreaSize(arg0);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setTextAreaSize : wrong number of arguments: %d", args.Length());
}

// bool js_cocos2dx_ui_Text_getStringLength(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getStringLength(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getStringLength : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getStringLength : Invalid Native Object");
  //     if (argc == 0) {
  //         ssize_t ret = cobj->getStringLength();
  //         JS::RootedValue jsret(cx);
  //         jsret = ssize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    ssize_t ret = cText->getStringLength();
    args.GetReturnValue().Set(JsbUtils::ssize_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getStringLength : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getStringLength : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getAutoRenderSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getAutoRenderSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getAutoRenderSize : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getAutoRenderSize : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Size ret = cobj->getAutoRenderSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Size ret = cText->getAutoRenderSize();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getAutoRenderSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getAutoRenderSize : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_enableOutline(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_enableOutline(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_enableOutline : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_enableOutline : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableOutline : Error processing arguments");
  //         cobj->enableOutline(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    if (JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0))
    {
      cText->enableOutline(arg0);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }
  //     if (argc == 2) {
  //         cocos2d::Color4B arg0;
  //         int arg1 = 0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableOutline : Error processing arguments");
  //         cobj->enableOutline(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    cocos2d::Color4B arg0;
    int arg1 = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    if (JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0))
    {
      cText->enableOutline(arg0, arg1);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_enableOutline : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_enableOutline : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getEffectColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getEffectColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getEffectColor : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getEffectColor : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Color4B ret = cobj->getEffectColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Color4B ret = cText->getEffectColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4b_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getEffectColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getEffectColor : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getType : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getType : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cText->getType();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getType : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getType : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getTextHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getTextHorizontalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getTextHorizontalAlignment : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getTextHorizontalAlignment : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getTextHorizontalAlignment();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cText->getTextHorizontalAlignment();
    args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getTextHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getTextHorizontalAlignment : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_isShadowEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_isShadowEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_isShadowEnabled : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_isShadowEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isShadowEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cText->isShadowEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_isShadowEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_isShadowEnabled : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setFontSize : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setFontSize : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setFontSize : Error processing arguments");
  //         cobj->setFontSize(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    cText->setFontSize(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setFontSize : wrong number of arguments: %d", args.Length());
}

// bool js_cocos2dx_ui_Text_getShadowColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getShadowColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getShadowColor : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getShadowColor : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Color4B ret = cobj->getShadowColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Color4B ret = cText->getShadowColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4b_to_jsval(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getShadowColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getShadowColor : wrong number of arguments: %d ", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_setTextColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setTextColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setTextColor : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setTextColor : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setTextColor : Error processing arguments");
  //         cobj->setTextColor(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    if (JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0))
    {
      cText->setTextColor(arg0);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setTextColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setTextColor : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_enableGlow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_enableGlow(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_enableGlow : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_enableGlow : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_enableGlow : Error processing arguments");
  //         cobj->enableGlow(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    if (JsbUtils::jsval_to_cccolor4b(isolate, args[0], &arg0))
    {
      cText->enableGlow(arg0);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_enableGlow : wrong number of arguments: %d", args.Length());

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_enableGlow : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Text_getLetter(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_getLetter(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getLetter : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_getLetter : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_getLetter : Error processing arguments");
  //         cocos2d::Sprite* ret = cobj->getLetter(arg0);
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::Sprite *ret = cText->getLetter(arg0);
    if (ret)
    {
      v8::Local<v8::Object> jsret;
      JsbUtils::NativePtrToObject(typeid(cocos2d::Sprite).name(), ret, &jsret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(isolate));
    }
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_ui_Text_getLetter : wrong number of arguments: %d", args.Length());

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_getLetter : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ui_Text_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Text_setBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Text *cText = (cocos2d::ui::Text *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cText, "js_cocos2dx_ui_Text_setBlendFunc : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::BlendFunc arg0;
  //         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setBlendFunc : Error processing arguments");
  //         cobj->setBlendFunc(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::BlendFunc arg0;
    if (JsbUtils::jsval_to_blendfunc(isolate, args[0], &arg0))
    {
      cText->setBlendFunc(arg0);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Text_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_Text_setBlendFunc : wrong number of arguments: %d", args.Length());
  //     return false;
}

// bool js_cocos2dx_ui_Text_getTextVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getTextVerticalAlignment : Invalid Native Object");
//     if (argc == 0) {
//         int ret = (int)cobj->getTextVerticalAlignment();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Text_getTextVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Text_getTextAreaSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_getTextAreaSize : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Size& ret = cobj->getTextAreaSize();
//         JS::RootedValue jsret(cx);
//         jsret = ccsize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Text_getTextAreaSize : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Text_setTextHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Text* cobj = (cocos2d::ui::Text *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Text_setTextHorizontalAlignment : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::TextHAlignment arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Text_setTextHorizontalAlignment : Error processing arguments");
//         cobj->setTextHorizontalAlignment(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Text_setTextHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Text_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;

//     do {
//         if (argc == 3) {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok) { ok = true; break; }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok) { ok = true; break; }
//             double arg2 = 0;
//             ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok) { ok = true; break; }
//             cocos2d::ui::Text* ret = cocos2d::ui::Text::create(arg0, arg1, arg2);
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Text>(cx, (cocos2d::ui::Text*)ret));
//             } else {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do {
//         if (argc == 0) {
//             cocos2d::ui::Text* ret = cocos2d::ui::Text::create();
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Text>(cx, (cocos2d::ui::Text*)ret));
//             } else {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     JS_ReportError(cx, "js_cocos2dx_ui_Text_create : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_ui_Text_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ui::Text* cobj = new (std::nothrow) cocos2d::ui::Text();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Text>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::Text"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_ui_Text_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::ui::Text *nobj = new (std::nothrow) cocos2d::ui::Text();
//     js_proxy_t* p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::Text");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_ui_Widget_prototype;

// void js_register_cocos2dx_ui_Text(JSContext *cx, JS::HandleObject global) {
//     jsb_cocos2d_ui_Text_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ui_Text_class->name = "Text";
//     jsb_cocos2d_ui_Text_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_Text_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ui_Text_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_Text_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ui_Text_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ui_Text_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ui_Text_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ui_Text_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END
//     };

//     static JSFunctionSpec funcs[] = {
//         JS_FN("enableShadow", js_cocos2dx_ui_Text_enableShadow, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFontSize", js_cocos2dx_ui_Text_getFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getString", js_cocos2dx_ui_Text_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("disableEffect", js_cocos2dx_ui_Text_disableEffect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLabelEffectType", js_cocos2dx_ui_Text_getLabelEffectType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextColor", js_cocos2dx_ui_Text_getTextColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBlendFunc", js_cocos2dx_ui_Text_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextVerticalAlignment", js_cocos2dx_ui_Text_setTextVerticalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFontName", js_cocos2dx_ui_Text_setFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTouchScaleChangeEnabled", js_cocos2dx_ui_Text_setTouchScaleChangeEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getShadowOffset", js_cocos2dx_ui_Text_getShadowOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setString", js_cocos2dx_ui_Text_setString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getOutlineSize", js_cocos2dx_ui_Text_getOutlineSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("init", js_cocos2dx_ui_Text_init, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getShadowBlurRadius", js_cocos2dx_ui_Text_getShadowBlurRadius, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isTouchScaleChangeEnabled", js_cocos2dx_ui_Text_isTouchScaleChangeEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFontName", js_cocos2dx_ui_Text_getFontName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextAreaSize", js_cocos2dx_ui_Text_setTextAreaSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStringLength", js_cocos2dx_ui_Text_getStringLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getAutoRenderSize", js_cocos2dx_ui_Text_getAutoRenderSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("enableOutline", js_cocos2dx_ui_Text_enableOutline, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEffectColor", js_cocos2dx_ui_Text_getEffectColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getType", js_cocos2dx_ui_Text_getType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextHorizontalAlignment", js_cocos2dx_ui_Text_getTextHorizontalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isShadowEnabled", js_cocos2dx_ui_Text_isShadowEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFontSize", js_cocos2dx_ui_Text_setFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getShadowColor", js_cocos2dx_ui_Text_getShadowColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextColor", js_cocos2dx_ui_Text_setTextColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("enableGlow", js_cocos2dx_ui_Text_enableGlow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLetter", js_cocos2dx_ui_Text_getLetter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendFunc", js_cocos2dx_ui_Text_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextVerticalAlignment", js_cocos2dx_ui_Text_getTextVerticalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextAreaSize", js_cocos2dx_ui_Text_getTextAreaSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextHorizontalAlignment", js_cocos2dx_ui_Text_setTextHorizontalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_ui_Text_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ui_Text_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ui_Widget_prototype);
//     jsb_cocos2d_ui_Text_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ui_Text_class,
//         js_cocos2dx_ui_Text_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ui_Text_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "Text"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ui::Text>(cx, jsb_cocos2d_ui_Text_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { ccui.Text.extend = cc.Class.extend; })()");
// }
