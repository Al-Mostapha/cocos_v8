#include "JsbLabel.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "2d/CCLabel.h"
#include "ScriptEngine.hpp"
#include "2d/CCSprite.h"

// JSClass *jsb_cocos2d_Label_class;
// JSObject *jsb_cocos2d_Label_prototype;

// bool js_cocos2dx_Label_isClipMarginEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_isClipMarginEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_isClipMarginEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_isClipMarginEnabled : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isClipMarginEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->isClipMarginEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_isClipMarginEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_isClipMarginEnabled : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_enableShadow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableShadow(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_enableShadow : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableShadow : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->enableShadow();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->enableShadow();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  cocos2d::Color4B arg0;
  cocos2d::Size arg1;
  int arg2 = 0;
  //     if (argc == 1)
  //     {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableShadow : Error processing arguments");
    cobj->enableShadow(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     if (argc == 2)
  //     {
  //         cocos2d::Color4B arg0;
  //         cocos2d::Size arg1;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ccsize(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    bool ok = JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    ok = ok && JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableShadow : Error processing arguments");
    cobj->enableShadow(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     if (argc == 3)
  //     {
  //         cocos2d::Color4B arg0;
  //         cocos2d::Size arg1;
  //         int arg2 = 0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ccsize(cx, args.get(1), &arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableShadow : Error processing arguments");
  //         cobj->enableShadow(arg0, arg1, arg2);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    bool ok = JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    ok = ok && JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[1], &arg1);
    arg2 = args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableShadow : Error processing arguments");
    cobj->enableShadow(arg0, arg1, arg2);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_enableShadow : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_enableShadow : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setDimensions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setDimensions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setDimensions : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setDimensions : Invalid Native Object");
  //     if (argc == 2)
  //     {
  //         double arg0 = 0;
  //         double arg1 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setDimensions : Error processing arguments");
  //         cobj->setDimensions(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    bool ok = true;
    double arg0 = 0;
    double arg1 = 0;
    ok = ok && args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg0) && !std::isnan(arg0);
    ok = ok && args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg1) && !std::isnan(arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setDimensions : Error processing arguments");
    cobj->setDimensions(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setDimensions : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Label_setDimensions : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_Label_getWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getWidth(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getWidth : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getWidth : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getWidth();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getWidth();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getWidth : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getWidth : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getString(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getString(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getString : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getString : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const std::string &ret = cobj->getString();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::string &ret = cobj->getString();
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), ret.c_str()).ToLocalChecked());
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getString : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getHeight(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getHeight(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getHeight : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getHeight : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getHeight();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getHeight();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getHeight : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_disableEffect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_disableEffect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Label *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Label *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_disableEffect : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_disableEffect : Invalid Native Object");

  //         if (argc == 1)
  //         {
  //             cocos2d::LabelEffect arg0;
  //             ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cobj->disableEffect(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
    cobj->disableEffect((cocos2d::LabelEffect)arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //         if (argc == 0)
  //         {
  //             cobj->disableEffect();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cobj->disableEffect();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_disableEffect : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_getLabelType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getLabelType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getLabelType : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getLabelType : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         int ret = (int)cobj->getLabelType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getLabelType();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Label_getLabelType : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getLabelType : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getTextColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getTextColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getTextColor : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getTextColor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const cocos2d::Color4B &ret = cobj->getTextColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Color4B &ret = cobj->getTextColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4b_to_jsval(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getTextColor : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getBlendFunc : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
    args.GetReturnValue().Set(JsbUtils::blendfunc_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getBlendFunc : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_enableWrap(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableWrap(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_enableWrap : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableWrap : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableWrap : Error processing arguments");
  //         cobj->enableWrap(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cobj->enableWrap(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableWrap : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Label_enableWrap : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Label_setWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setWidth(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setWidth : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setWidth : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setWidth : Error processing arguments");
  //         cobj->setWidth(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = 0;
    ok = ok && args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg0) && !std::isnan(arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setWidth : Error processing arguments");
    cobj->setWidth(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setWidth : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setWidth : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_getAdditionalKerning(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getAdditionalKerning(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getAdditionalKerning : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getAdditionalKerning();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getAdditionalKerning();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getAdditionalKerning : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Label_getAdditionalKerning : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Label_getBMFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getBMFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getBMFontSize : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getBMFontSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getBMFontSize();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getBMFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getBMFontSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getMaxLineWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getMaxLineWidth(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getMaxLineWidth : Invalid Native Object");
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getMaxLineWidth : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getMaxLineWidth();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getMaxLineWidth();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getMaxLineWidth : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getMaxLineWidth : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getHorizontalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getHorizontalAlignment : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getHorizontalAlignment : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         int ret = (int)cobj->getHorizontalAlignment();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getHorizontalAlignment();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getHorizontalAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getShadowOffset(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getShadowOffset(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getShadowOffset : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getShadowOffset : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cocos2d::Size ret = cobj->getShadowOffset();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Size ret = cobj->getShadowOffset();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getShadowOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getShadowOffset : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getLineSpacing(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getLineSpacing(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getLineSpacing : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getLineSpacing : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getLineSpacing();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getLineSpacing();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getLineSpacing : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getLineSpacing : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setClipMarginEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setClipMarginEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setClipMarginEnabled : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setClipMarginEnabled : Error processing arguments");
  //         cobj->setClipMarginEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setClipMarginEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Label_setString(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setString(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setString : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setString : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setString : Error processing arguments");
  //         cobj->setString(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setString : Error processing arguments");
    cobj->setString(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setString : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setString : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_setSystemFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setSystemFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setSystemFontName : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setSystemFontName : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setSystemFontName : Error processing arguments");
  //         cobj->setSystemFontName(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setSystemFontName : Error processing arguments");
    cobj->setSystemFontName(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setSystemFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setSystemFontName : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_isWrapEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_isWrapEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_isWrapEnabled : Invalid Native Object");
  if (args.Length() == 0)
  {
    bool ret = cobj->isWrapEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_isWrapEnabled : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isWrapEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Label_isWrapEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_isWrapEnabled : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getOutlineSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getOutlineSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getOutlineSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getOutlineSize : Invalid Native Object");
  if (args.Length() == 0)
  {
    double ret = cobj->getOutlineSize();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getOutlineSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getOutlineSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getOutlineSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Label_setBMFontFilePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setBMFontFilePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setBMFontFilePath : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setBMFontFilePath : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
  //         bool ret = cobj->setBMFontFilePath(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
    bool ret = cobj->setBMFontFilePath(arg0);
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }
  //     if (argc == 2)
  //     {
  //         std::string arg0;
  //         cocos2d::Vec2 arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_vector2(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
  //         bool ret = cobj->setBMFontFilePath(arg0, arg1);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    cocos2d::Vec2 arg1;
    ok = ok && JsbUtils::jsval_to_vector2(args.GetIsolate(), args[1], &arg1);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
    bool ret = cobj->setBMFontFilePath(arg0, arg1);
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }
  //     if (argc == 3)
  //     {
  //         std::string arg0;
  //         cocos2d::Vec2 arg1;
  //         double arg2 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_vector2(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
  //         bool ret = cobj->setBMFontFilePath(arg0, arg1, arg2);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    cocos2d::Vec2 arg1;
    double arg2 = 0;
    ok = ok && JsbUtils::jsval_to_vector2(args.GetIsolate(), args[1], &arg1) && args[2]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg2) && !std::isnan(arg2);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setBMFontFilePath : Error processing arguments");
    bool ret = cobj->setBMFontFilePath(arg0, arg1, arg2);
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setBMFontFilePath : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Label_setBMFontFilePath : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Label_initWithTTF(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_initWithTTF(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Label *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Label *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_initWithTTF : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_initWithTTF : Invalid Native Object");

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::_ttfConfig arg0;
    // #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig
    //             ok = false;
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithTTF(arg0, arg1);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
  }

  //     do
  //     {
  //         if (argc == 3)
  //         {
  //             cocos2d::_ttfConfig arg0;
  // #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig
  //             ok = false;
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::TextHAlignment arg2;
  //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 4)
  //         {
  //             cocos2d::_ttfConfig arg0;
  // #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig
  //             ok = false;
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::TextHAlignment arg2;
  //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             int arg3 = 0;
  //             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2, arg3);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 3)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             double arg2 = 0;
  //             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 4)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             double arg2 = 0;
  //             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::Size arg3;
  //             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2, arg3);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 5)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             double arg2 = 0;
  //             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::Size arg3;
  //             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::TextHAlignment arg4;
  //             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2, arg3, arg4);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 6)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string arg1;
  //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             double arg2 = 0;
  //             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::Size arg3;
  //             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::TextHAlignment arg4;
  //             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::TextVAlignment arg5;
  //             ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->initWithTTF(arg0, arg1, arg2, arg3, arg4, arg5);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_Label_initWithTTF : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Label_setLineHeight(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setLineHeight(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setLineHeight : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setLineHeight : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setLineHeight : Error processing arguments");
  //         cobj->setLineHeight(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = 0;
    ok = ok && args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg0) && !std::isnan(arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setLineHeight : Error processing arguments");
    cobj->setLineHeight(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setLineHeight : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Label_setLineHeight : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Label_setSystemFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setSystemFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setSystemFontSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setSystemFontSize : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setSystemFontSize : Error processing arguments");
  //         cobj->setSystemFontSize(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = 0;
    ok = ok && args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).To(&arg0) && !std::isnan(arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setSystemFontSize : Error processing arguments");
    cobj->setSystemFontSize(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setSystemFontSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Label_setSystemFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Label_setOverflow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setOverflow(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setOverflow : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setOverflow : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         cocos2d::Label::Overflow arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setOverflow : Error processing arguments");
  //         cobj->setOverflow(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    cocos2d::Label::Overflow arg0 = (cocos2d::Label::Overflow)args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setOverflow : Error processing arguments");
    cobj->setOverflow(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setOverflow : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setOverflow : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_enableStrikethrough(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableStrikethrough(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_enableStrikethrough : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableStrikethrough : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->enableStrikethrough();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->enableStrikethrough();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_enableStrikethrough : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_enableStrikethrough : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_updateContent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_updateContent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_updateContent : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_updateContent : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->updateContent();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->updateContent();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_updateContent : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_updateContent : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getStringLength(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getStringLength(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getStringLength : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getStringLength : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         int ret = cobj->getStringLength();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getStringLength();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getStringLength : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getStringLength : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setLineBreakWithoutSpace(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setLineBreakWithoutSpace(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setLineBreakWithoutSpace : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setLineBreakWithoutSpace : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setLineBreakWithoutSpace : Error processing arguments");
  //         cobj->setLineBreakWithoutSpace(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cobj->setLineBreakWithoutSpace(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setLineBreakWithoutSpace : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_getStringNumLines(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getStringNumLines(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getStringNumLines : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getStringNumLines : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         int ret = cobj->getStringNumLines();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getStringNumLines();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getStringNumLines : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_enableOutline(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableOutline(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_enableOutline : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableOutline : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         cocos2d::Color4B arg0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableOutline : Error processing arguments");
  //         cobj->enableOutline(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    cocos2d::Color4B arg0;
    ok = ok && JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableOutline : Error processing arguments");
    cobj->enableOutline(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     if (argc == 2)
  //     {
  //         cocos2d::Color4B arg0;
  //         int arg1 = 0;
  //         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableOutline : Error processing arguments");
  //         cobj->enableOutline(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    bool ok = true;
    cocos2d::Color4B arg0;
    int arg1 = args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    ok = ok && JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableOutline : Error processing arguments");
    cobj->enableOutline(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableOutline : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_getShadowBlurRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getShadowBlurRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getShadowBlurRadius : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getShadowBlurRadius : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getShadowBlurRadius();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getShadowBlurRadius();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getShadowBlurRadius : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getEffectColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getEffectColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getEffectColor : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getEffectColor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cocos2d::Color4F ret = cobj->getEffectColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4f_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Color4F ret = cobj->getEffectColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4f_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getEffectColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getEffectColor : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_removeAllChildrenWithCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_removeAllChildrenWithCleanup : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_removeAllChildrenWithCleanup : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_removeAllChildrenWithCleanup : Error processing arguments");
  //         cobj->removeAllChildrenWithCleanup(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cobj->removeAllChildrenWithCleanup(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_removeAllChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_setCharMap(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setCharMap(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Label *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Label *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setCharMap : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setCharMap : Invalid Native Object");
  //     do
  //     {
  //         if (argc == 4)
  //         {
  //             cocos2d::Texture2D *arg0 = nullptr;
  //             do
  //             {
  //                 if (args.get(0).isNull())
  //                 {
  //                     arg0 = nullptr;
  //                     break;
  //                 }
  //                 if (!args.get(0).isObject())
  //                 {
  //                     ok = false;
  //                     break;
  //                 }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             int arg1 = 0;
  //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             int arg2 = 0;
  //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             int arg3 = 0;
  //             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->setCharMap(arg0, arg1, arg2, arg3);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  if (args.Length() == 4)
  {
    bool ok = true;
    if (args[0]->IsString())
    {
      std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
      int arg1 = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
      int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
      int arg3 = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
      bool ret = cobj->setCharMap(arg0, arg1, arg2, arg3);
      args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    }
    else if (args[0]->IsObject())
    {
      cocos2d::Texture2D *arg0 = (cocos2d::Texture2D *)args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked()->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "Invalid Native Object");
      int arg1 = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
      int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
      int arg3 = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
      bool ret = cobj->setCharMap(arg0, arg1, arg2, arg3);
      args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Label_setCharMap : Error processing arguments");
      return;
    }
    return;
  }

  //         if (argc == 1)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->setCharMap(arg0);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    bool ok = true;
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setCharMap : Error processing arguments");
    bool ret = cobj->setCharMap(arg0);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setCharMap : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Label_setCharMap : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_getDimensions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getDimensions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getDimensions : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getDimensions : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const cocos2d::Size &ret = cobj->getDimensions();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Size &ret = cobj->getDimensions();
    args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getDimensions : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getDimensions : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setMaxLineWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setMaxLineWidth(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setMaxLineWidth : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setMaxLineWidth : Error processing arguments");
  //         cobj->setMaxLineWidth(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setMaxLineWidth : Error processing arguments");
    cobj->setMaxLineWidth(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setMaxLineWidth : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setMaxLineWidth : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_getSystemFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getSystemFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getSystemFontName : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getSystemFontName : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const std::string &ret = cobj->getSystemFontName();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::string &ret = cobj->getSystemFontName();
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getSystemFontName : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getSystemFontName : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setVerticalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setVerticalAlignment : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setVerticalAlignment : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         cocos2d::TextVAlignment arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setVerticalAlignment : Error processing arguments");
  //         cobj->setVerticalAlignment(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    int32_t arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setVerticalAlignment : Error processing arguments");
    cobj->setVerticalAlignment((cocos2d::TextVAlignment)arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setVerticalAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_setLineSpacing(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setLineSpacing(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_setLineSpacing : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setLineSpacing : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setLineSpacing : Error processing arguments");
  //         cobj->setLineSpacing(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setLineSpacing : Error processing arguments");
    cobj->setLineSpacing(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_setLineSpacing : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Label_setLineSpacing : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Label_getRenderingFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getRenderingFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getRenderingFontSize : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getRenderingFontSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getRenderingFontSize();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getRenderingFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getRenderingFontSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getLineHeight(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getLineHeight(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getLineHeight : Invalid Native Object");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getLineHeight : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getLineHeight();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cobj->getLineHeight();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getLineHeight : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Label_getLineHeight : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Label_getShadowColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getShadowColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getShadowColor : Invalid Native Object");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getShadowColor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cocos2d::Color4F ret = cobj->getShadowColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4f_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Color4F ret = cobj->getShadowColor();
    args.GetReturnValue().Set(JsbUtils::cccolor4f_to_jsval(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getShadowColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getShadowColor : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_getTTFConfig(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getTTFConfig(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label *cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Label_getTTFConfig : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         const cocos2d::_ttfConfig &ret = cobj->getTTFConfig();
  //         JS::RootedValue jsret(cx);
  // #pragma warning NO CONVERSION FROM NATIVE FOR _ttfConfig;
  //         args.rval().set(jsret);
  //         return true;
  CCASSERT(false, "js_cocos2dx_Label_getTTFConfig : Not supported to return _ttfConfig");
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getTTFConfig : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}
// bool js_cocos2dx_Label_enableItalics(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableItalics(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableItalics : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->enableItalics();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableItalics : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

void js_cocos2dx_Label_setTextColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setTextColor : Invalid Native Object");
  if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    bool ok = JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setTextColor : Error processing arguments");
    cobj->setTextColor(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setTextColor : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
// bool js_cocos2dx_Label_getLetter(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getLetter(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getLetter : Invalid Native Object");
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::Sprite *ret = cobj->getLetter(arg0);
    if (ret)
    {
      v8::Local<v8::Object> jsObj;
      JsbUtils::NativePtrToObject(typeid(cocos2d::Sprite).name(), ret, &jsObj);
      args.GetReturnValue().Set(jsObj);
    }
    else
      args.GetReturnValue().Set(v8::Null(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getLetter : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_getLetter : Invalid Native Object");
//     if (argc == 1) {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_getLetter : Error processing arguments");
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

//     JS_ReportError(cx, "js_cocos2dx_Label_getLetter : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_setHeight(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setHeight(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setHeight : Invalid Native Object");
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    cobj->setHeight(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setHeight : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_setHeight : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setHeight : Error processing arguments");
//         cobj->setHeight(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_setHeight : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_isShadowEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_isShadowEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_isShadowEnabled : Invalid Native Object");
  if (args.Length() == 0)
  {
    bool ret = cobj->isShadowEnabled();
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_isShadowEnabled : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_isShadowEnabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isShadowEnabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_isShadowEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Label_enableGlow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableGlow(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableGlow : Invalid Native Object");
  if (args.Length() == 1)
  {
    cocos2d::Color4B arg0;
    bool ok = JsbUtils::jsval_to_cccolor4b(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_enableGlow : Error processing arguments");
    cobj->enableGlow(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableGlow : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_enableGlow : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Color4B arg0;
//         ok &= jsval_to_cccolor4b(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_enableGlow : Error processing arguments");
//         cobj->enableGlow(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_enableGlow : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_getOverflow(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getOverflow(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getOverflow : Invalid Native Object");
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getOverflow();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getOverflow : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_getOverflow : Invalid Native Object");
//     if (argc == 0) {
//         int ret = (int)cobj->getOverflow();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_getOverflow : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Label_getVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getVerticalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getVerticalAlignment : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_getVerticalAlignment : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getVerticalAlignment();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getVerticalAlignment();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getVerticalAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Label_setAdditionalKerning(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setAdditionalKerning(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setAdditionalKerning : Invalid Native Object");
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setAdditionalKerning : Error processing arguments");
    cobj->setAdditionalKerning(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setAdditionalKerning : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_setAdditionalKerning : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setAdditionalKerning : Error processing arguments");
//         cobj->setAdditionalKerning(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_setAdditionalKerning : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_getSystemFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getSystemFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getSystemFontSize : Invalid Native Object");
  if (args.Length() == 0)
  {
    double ret = cobj->getSystemFontSize();
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getSystemFontSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_getSystemFontSize : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getSystemFontSize();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_getSystemFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Label_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setBlendFunc : Invalid Native Object");
  if (args.Length() == 1)
  {
    cocos2d::BlendFunc arg0;
    bool ok = JsbUtils::jsval_to_blendfunc(args.GetIsolate(), args[0], &arg0);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setBlendFunc : Error processing arguments");
    cobj->setBlendFunc(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setBlendFunc : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_setBlendFunc : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::BlendFunc arg0;
//         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setBlendFunc : Error processing arguments");
//         cobj->setBlendFunc(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_getTextAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getTextAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getTextAlignment : Invalid Native Object");
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_getTextAlignment : Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = (int)cobj->getTextAlignment();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getTextAlignment();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Label_getTextAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Label_getTextAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getBMFontFilePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getBMFontFilePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getBMFontFilePath : Invalid Native Object");
  if (args.Length() == 0)
  {
    const std::string &ret = cobj->getBMFontFilePath();
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), ret.c_str()).ToLocalChecked());
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getBMFontFilePath : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_setHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setHorizontalAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setHorizontalAlignment : Invalid Native Object");
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cobj->setHorizontalAlignment((cocos2d::TextHAlignment)arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setHorizontalAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_enableBold(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableBold(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableBold : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->enableBold();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableBold : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_enableUnderline(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_enableUnderline(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_enableUnderline : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->enableUnderline();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_enableUnderline : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_getLabelEffectType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_getLabelEffectType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_getLabelEffectType : Invalid Native Object");
  if (args.Length() == 0)
  {
    int ret = (int)cobj->getLabelEffectType();
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), ret));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_getLabelEffectType : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}

// bool js_cocos2dx_Label_setAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Label* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Label *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_setAlignment : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setAlignment : Invalid Native Object");

  //         if (argc == 2) {
  //             cocos2d::TextHAlignment arg0;
  //             ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::TextVAlignment arg1;
  //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //             if (!ok) { ok = true; break; }
  //             cobj->setAlignment(arg0, arg1);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 2)
  {
    int arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    int arg1 = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cobj->setAlignment((cocos2d::TextHAlignment)arg0, (cocos2d::TextVAlignment)arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //         if (argc == 1) {
  //             cocos2d::TextHAlignment arg0;
  //             ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //             if (!ok) { ok = true; break; }
  //             cobj->setAlignment(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cobj->setAlignment((cocos2d::TextHAlignment)arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setAlignment : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}

// bool js_cocos2dx_Label_requestSystemFontRefresh(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_requestSystemFontRefresh(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_requestSystemFontRefresh : Invalid Native Object");
  if (args.Length() == 0)
  {
    cobj->requestSystemFontRefresh();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_requestSystemFontRefresh : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_requestSystemFontRefresh : Invalid Native Object");
//     if (argc == 0) {
//         cobj->requestSystemFontRefresh();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_requestSystemFontRefresh : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Label_setBMFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_setBMFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Label *cobj = (cocos2d::Label *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cobj, "js_cocos2dx_Label_setBMFontSize : Invalid Native Object");
  if (args.Length() == 1)
  {
    bool ok = true;
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_setBMFontSize : Error processing arguments");
    cobj->setBMFontSize(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Label_setBMFontSize : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Label* cobj = (cocos2d::Label *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Label_setBMFontSize : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_setBMFontSize : Error processing arguments");
//         cobj->setBMFontSize(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Label_setBMFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Label_createWithBMFont(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_createWithBMFont(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 2) {
  //         std::string arg0;
  //         std::string arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithBMFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithBMFont(arg0, arg1);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);

    auto ret = cocos2d::Label::createWithBMFont(arg0, arg1);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 3) {
  //         std::string arg0;
  //         std::string arg1;
  //         cocos2d::TextHAlignment arg2;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithBMFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, arg2);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();

    auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, (cocos2d::TextHAlignment)arg2);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 4) {
  //         std::string arg0;
  //         std::string arg1;
  //         cocos2d::TextHAlignment arg2;
  //         int arg3 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithBMFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, arg2, arg3);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 4)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
    int arg3 = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();

    auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, (cocos2d::TextHAlignment)arg2, arg3);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 5) {
  //         std::string arg0;
  //         std::string arg1;
  //         cocos2d::TextHAlignment arg2;
  //         int arg3 = 0;
  //         cocos2d::Vec2 arg4;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //         ok &= jsval_to_vector2(cx, args.get(4), &arg4);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithBMFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, arg2, arg3, arg4);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 5)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    int arg2 = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
    int arg3 = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::Vec2 arg4;
    bool ok = JsbUtils::jsval_to_vector2(args.GetIsolate(), args[4], &arg4);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_createWithBMFont : Error processing arguments");

    auto ret = cocos2d::Label::createWithBMFont(arg0, arg1, (cocos2d::TextHAlignment)arg2, arg3, arg4);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Label_createWithBMFont : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Label_createWithBMFont : wrong number of arguments: %d", (int)args.Length());
  //     return false;
}

// bool js_cocos2dx_Label_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {

  //         auto ret = cocos2d::Label::create();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    auto ret = cocos2d::Label::create();
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Label_create : wrong number of arguments: %d", (int)args.Length());
}

// bool js_cocos2dx_Label_createWithCharMap(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_createWithCharMap(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;

  //     do {
  //         if (argc == 4) {
  //             cocos2d::Texture2D* arg0 = nullptr;
  //             do {
  //                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //                 if (!args.get(0).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg0 = (cocos2d::Texture2D*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             int arg1 = 0;
  //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //             if (!ok) { ok = true; break; }
  //             int arg2 = 0;
  //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //             if (!ok) { ok = true; break; }
  //             int arg3 = 0;
  //             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::Label* ret = cocos2d::Label::createWithCharMap(arg0, arg1, arg2, arg3);
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Label>(cx, (cocos2d::Label*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do {
  //         if (argc == 4) {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok) { ok = true; break; }
  //             int arg1 = 0;
  //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //             if (!ok) { ok = true; break; }
  //             int arg2 = 0;
  //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
  //             if (!ok) { ok = true; break; }
  //             int arg3 = 0;
  //             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::Label* ret = cocos2d::Label::createWithCharMap(arg0, arg1, arg2, arg3);
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Label>(cx, (cocos2d::Label*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);

  //     do {
  //         if (argc == 1) {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::Label* ret = cocos2d::Label::createWithCharMap(arg0);
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Label>(cx, (cocos2d::Label*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while (0);
  //     JS_ReportError(cx, "js_cocos2dx_Label_createWithCharMap : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Label_createWithSystemFont(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_createWithSystemFont(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 3) {
  //         std::string arg0;
  //         std::string arg1;
  //         double arg2 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 3)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    double arg2 = args[2]->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 4) {
  //         std::string arg0;
  //         std::string arg1;
  //         double arg2 = 0;
  //         cocos2d::Size arg3;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 4)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    double arg2 = args[2]->NumberValue(isolate->GetCurrentContext()).FromJust();
    cocos2d::Size arg3;
    bool ok = JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[3], &arg3);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");

    auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 5) {
  //         std::string arg0;
  //         std::string arg1;
  //         double arg2 = 0;
  //         cocos2d::Size arg3;
  //         cocos2d::TextHAlignment arg4;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //         ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3, arg4);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 5)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    double arg2 = args[2]->NumberValue(isolate->GetCurrentContext()).FromJust();
    cocos2d::Size arg3;
    bool ok = JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[3], &arg3);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");
    int arg4 = args[4]->Int32Value(isolate->GetCurrentContext()).FromJust();

    auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3, (cocos2d::TextHAlignment)arg4);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     if (argc == 6) {
  //         std::string arg0;
  //         std::string arg1;
  //         double arg2 = 0;
  //         cocos2d::Size arg3;
  //         cocos2d::TextHAlignment arg4;
  //         cocos2d::TextVAlignment arg5;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
  //         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
  //         ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
  //         ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");

  //         auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3, arg4, arg5);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Label"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 6)
  {
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
    double arg2 = args[2]->NumberValue(isolate->GetCurrentContext()).FromJust();
    cocos2d::Size arg3;
    bool ok = JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[3], &arg3);
    SE_PRECONDITION2(ok, "js_cocos2dx_Label_createWithSystemFont : Error processing arguments");
    int arg4 = args[4]->Int32Value(isolate->GetCurrentContext()).FromJust();
    int arg5 = args[5]->Int32Value(isolate->GetCurrentContext()).FromJust();

    auto ret = cocos2d::Label::createWithSystemFont(arg0, arg1, arg2, arg3, (cocos2d::TextHAlignment)arg4, (cocos2d::TextVAlignment)arg5);
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Label_createWithSystemFont : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Label_createWithSystemFont : wrong number of arguments: %d", (int)args.Length());
  //     return false;
}

// bool js_cocos2dx_Label_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::Label *cobj = new (std::nothrow) cocos2d::Label();
  cocos2d::Label *cobj = new (std::nothrow) cocos2d::Label();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Label>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::Label"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(cobj);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  args.GetReturnValue().Set(jsobj);
  //     return true;
}

// static bool js_cocos2dx_Label_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Label_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::Label *nobj = new (std::nothrow) cocos2d::Label();
  cocos2d::Label *nobj = new (std::nothrow) cocos2d::Label();
  //     js_proxy_t *p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::Label");
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(nobj);
  CallCustomConstructor(args, jsobj);
  //     bool isFound = false;
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  //     args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //     return true;
}

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_Label(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_Label(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_Label_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_Label_class->name = "Label";
  //     jsb_cocos2d_Label_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Label_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Label_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Label_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Label_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Label_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Label_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Label_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "Label"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();
  JsbUtils::RegisterV8Class(typeid(cocos2d::Label).name(), &tpl);
  v8::Local<v8::FunctionTemplate> parentClass = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::Node).name());
  tpl->Inherit(parentClass);
  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("isClipMarginEnabled", js_cocos2dx_Label_isClipMarginEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isClipMarginEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_isClipMarginEnabled));
  //         JS_FN("enableShadow", js_cocos2dx_Label_enableShadow, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableShadow", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableShadow));
  //         JS_FN("setDimensions", js_cocos2dx_Label_setDimensions, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setDimensions", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setDimensions));
  //         JS_FN("getWidth", js_cocos2dx_Label_getWidth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getWidth", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getWidth));
  //         JS_FN("getString", js_cocos2dx_Label_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getString", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getString));
  //         JS_FN("getHeight", js_cocos2dx_Label_getHeight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getHeight", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getHeight));
  //         JS_FN("disableEffect", js_cocos2dx_Label_disableEffect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "disableEffect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_disableEffect));
  //         JS_FN("getLabelType", js_cocos2dx_Label_getLabelType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLabelType", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getLabelType));
  //         JS_FN("getTextColor", js_cocos2dx_Label_getTextColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTextColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getTextColor));
  //         JS_FN("getBlendFunc", js_cocos2dx_Label_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getBlendFunc));
  //         JS_FN("enableWrap", js_cocos2dx_Label_enableWrap, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableWrap", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableWrap));
  //         JS_FN("setWidth", js_cocos2dx_Label_setWidth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setWidth", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setWidth));
  //         JS_FN("getAdditionalKerning", js_cocos2dx_Label_getAdditionalKerning, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getAdditionalKerning", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getAdditionalKerning));
  //         JS_FN("getBMFontSize", js_cocos2dx_Label_getBMFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBMFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getBMFontSize));
  //         JS_FN("getMaxLineWidth", js_cocos2dx_Label_getMaxLineWidth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getMaxLineWidth", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getMaxLineWidth));
  //         JS_FN("getHorizontalAlignment", js_cocos2dx_Label_getHorizontalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getHorizontalAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getHorizontalAlignment));
  //         JS_FN("getShadowOffset", js_cocos2dx_Label_getShadowOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getShadowOffset", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getShadowOffset));
  //         JS_FN("getLineSpacing", js_cocos2dx_Label_getLineSpacing, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLineSpacing", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getLineSpacing));
  //         JS_FN("setClipMarginEnabled", js_cocos2dx_Label_setClipMarginEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setClipMarginEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setClipMarginEnabled));
  //         JS_FN("setString", js_cocos2dx_Label_setString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setString", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setString));
  //         JS_FN("setSystemFontName", js_cocos2dx_Label_setSystemFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSystemFontName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setSystemFontName));
  //         JS_FN("isWrapEnabled", js_cocos2dx_Label_isWrapEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isWrapEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_isWrapEnabled));
  //         JS_FN("getOutlineSize", js_cocos2dx_Label_getOutlineSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getOutlineSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getOutlineSize));
  //         JS_FN("setBMFontFilePath", js_cocos2dx_Label_setBMFontFilePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBMFontFilePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setBMFontFilePath));
  //         JS_FN("initWithTTF", js_cocos2dx_Label_initWithTTF, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "initWithTTF", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_initWithTTF));
  //         JS_FN("setLineHeight", js_cocos2dx_Label_setLineHeight, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setLineHeight", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setLineHeight));
  //         JS_FN("setSystemFontSize", js_cocos2dx_Label_setSystemFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSystemFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setSystemFontSize));
  //         JS_FN("setOverflow", js_cocos2dx_Label_setOverflow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setOverflow", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setOverflow));
  //         JS_FN("enableStrikethrough", js_cocos2dx_Label_enableStrikethrough, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableStrikethrough", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableStrikethrough));
  //         JS_FN("updateContent", js_cocos2dx_Label_updateContent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "updateContent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_updateContent));
  //         JS_FN("getStringLength", js_cocos2dx_Label_getStringLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getStringLength", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getStringLength));
  //         JS_FN("setLineBreakWithoutSpace", js_cocos2dx_Label_setLineBreakWithoutSpace, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setLineBreakWithoutSpace", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setLineBreakWithoutSpace));
  //         JS_FN("getStringNumLines", js_cocos2dx_Label_getStringNumLines, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getStringNumLines", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getStringNumLines));
  //         JS_FN("enableOutline", js_cocos2dx_Label_enableOutline, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableOutline", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableOutline));
  //         JS_FN("getShadowBlurRadius", js_cocos2dx_Label_getShadowBlurRadius, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getShadowBlurRadius", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getShadowBlurRadius));
  //         JS_FN("getEffectColor", js_cocos2dx_Label_getEffectColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getEffectColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getEffectColor));
  //         JS_FN("removeAllChildrenWithCleanup", js_cocos2dx_Label_removeAllChildrenWithCleanup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAllChildrenWithCleanup", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_removeAllChildrenWithCleanup));
  //         JS_FN("setCharMap", js_cocos2dx_Label_setCharMap, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCharMap", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setCharMap));
  //         JS_FN("getDimensions", js_cocos2dx_Label_getDimensions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getDimensions", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getDimensions));
  //         JS_FN("setMaxLineWidth", js_cocos2dx_Label_setMaxLineWidth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setMaxLineWidth", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setMaxLineWidth));
  //         JS_FN("getSystemFontName", js_cocos2dx_Label_getSystemFontName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSystemFontName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getSystemFontName));
  //         JS_FN("setVerticalAlignment", js_cocos2dx_Label_setVerticalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setVerticalAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setVerticalAlignment));
  //         JS_FN("setLineSpacing", js_cocos2dx_Label_setLineSpacing, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setLineSpacing", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setLineSpacing));
  //         JS_FN("getRenderingFontSize", js_cocos2dx_Label_getRenderingFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getRenderingFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getRenderingFontSize));
  //         JS_FN("getLineHeight", js_cocos2dx_Label_getLineHeight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLineHeight", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getLineHeight));
  //         JS_FN("getShadowColor", js_cocos2dx_Label_getShadowColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getShadowColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getShadowColor));
  //         JS_FN("getTTFConfig", js_cocos2dx_Label_getTTFConfig, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTTFConfig", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getTTFConfig));
  //         JS_FN("enableItalics", js_cocos2dx_Label_enableItalics, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableItalics", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableItalics));
  //         JS_FN("setTextColor", js_cocos2dx_Label_setTextColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTextColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setTextColor));
  //         JS_FN("getLetter", js_cocos2dx_Label_getLetter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLetter", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getLetter));
  //         JS_FN("setHeight", js_cocos2dx_Label_setHeight, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setHeight", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setHeight));
  //         JS_FN("isShadowEnabled", js_cocos2dx_Label_isShadowEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isShadowEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_isShadowEnabled));
  //         JS_FN("enableGlow", js_cocos2dx_Label_enableGlow, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableGlow", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableGlow));
  //         JS_FN("getOverflow", js_cocos2dx_Label_getOverflow, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getOverflow", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getOverflow));
  //         JS_FN("getVerticalAlignment", js_cocos2dx_Label_getVerticalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getVerticalAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getVerticalAlignment));
  //         JS_FN("setAdditionalKerning", js_cocos2dx_Label_setAdditionalKerning, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setAdditionalKerning", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setAdditionalKerning));
  //         JS_FN("getSystemFontSize", js_cocos2dx_Label_getSystemFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSystemFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getSystemFontSize));
  //         JS_FN("setBlendFunc", js_cocos2dx_Label_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setBlendFunc));
  //         JS_FN("getTextAlignment", js_cocos2dx_Label_getTextAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTextAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getTextAlignment));
  //         JS_FN("getBMFontFilePath", js_cocos2dx_Label_getBMFontFilePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBMFontFilePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getBMFontFilePath));
  //         JS_FN("setHorizontalAlignment", js_cocos2dx_Label_setHorizontalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setHorizontalAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setHorizontalAlignment));
  //         JS_FN("enableBold", js_cocos2dx_Label_enableBold, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableBold", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableBold));
  //         JS_FN("enableUnderline", js_cocos2dx_Label_enableUnderline, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "enableUnderline", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_enableUnderline));
  //         JS_FN("getLabelEffectType", js_cocos2dx_Label_getLabelEffectType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getLabelEffectType", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_getLabelEffectType));
  //         JS_FN("setAlignment", js_cocos2dx_Label_setAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setAlignment));
  //         JS_FN("requestSystemFontRefresh", js_cocos2dx_Label_requestSystemFontRefresh, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "requestSystemFontRefresh", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_requestSystemFontRefresh));
  //         JS_FN("setBMFontSize", js_cocos2dx_Label_setBMFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBMFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_setBMFontSize));
  //         JS_FN("ctor", js_cocos2dx_Label_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_ctor));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("createWithBMFont", js_cocos2dx_Label_createWithBMFont, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "createWithBMFont", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_createWithBMFont));
  //         JS_FN("create", js_cocos2dx_Label_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_create));
  //         JS_FN("createWithCharMap", js_cocos2dx_Label_createWithCharMap, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "createWithCharMap", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_createWithCharMap));
  //         JS_FN("createWithSystemFont", js_cocos2dx_Label_createWithSystemFont, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "createWithSystemFont", v8::FunctionTemplate::New(isolate, js_cocos2dx_Label_createWithSystemFont));
  //         JS_FS_END};

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
  //     jsb_cocos2d_Label_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_Label_class,
  //         js_cocos2dx_Label_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Label_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Label"));
  //     JS_SetProperty(cx, proto, "_className", className);
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Label>(cx, jsb_cocos2d_Label_class, proto, parent_proto);
  //     anonEvaluate(cx, global, "(function () { cc.Label.extend = cc.Class.extend; })()");
}

// JSClass *jsb_cocos2d_LabelAtlas_class;
// JSObject *jsb_cocos2d_LabelAtlas_prototype;

// bool js_cocos2dx_LabelAtlas_setString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelAtlas *cobj = (cocos2d::LabelAtlas *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelAtlas_setString : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelAtlas_setString : Error processing arguments");
//         cobj->setString(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelAtlas_setString : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelAtlas_initWithString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::LabelAtlas *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::LabelAtlas *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelAtlas_initWithString : Invalid Native Object");
//     do
//     {
//         if (argc == 2)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->initWithString(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 5)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg2 = 0;
//             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg3 = 0;
//             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg4 = 0;
//             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->initWithString(arg0, arg1, arg2, arg3, arg4);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 5)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::Texture2D *arg1 = nullptr;
//             do
//             {
//                 if (args.get(1).isNull())
//                 {
//                     arg1 = nullptr;
//                     break;
//                 }
//                 if (!args.get(1).isObject())
//                 {
//                     ok = false;
//                     break;
//                 }
//                 js_proxy_t *jsProxy;
//                 JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
//                 jsProxy = jsb_get_js_proxy(tmpObj);
//                 arg1 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
//                 JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
//             } while (0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg2 = 0;
//             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg3 = 0;
//             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg4 = 0;
//             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->initWithString(arg0, arg1, arg2, arg3, arg4);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_LabelAtlas_initWithString : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_LabelAtlas_getString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelAtlas *cobj = (cocos2d::LabelAtlas *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelAtlas_getString : Invalid Native Object");
//     if (argc == 0)
//     {
//         const std::string &ret = cobj->getString();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelAtlas_getString : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelAtlas_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;

//     do
//     {
//         if (argc == 5)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg2 = 0;
//             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg3 = 0;
//             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             int arg4 = 0;
//             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelAtlas *ret = cocos2d::LabelAtlas::create(arg0, arg1, arg2, arg3, arg4);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelAtlas>(cx, (cocos2d::LabelAtlas *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 0)
//         {
//             cocos2d::LabelAtlas *ret = cocos2d::LabelAtlas::create();
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelAtlas>(cx, (cocos2d::LabelAtlas *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 2)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelAtlas *ret = cocos2d::LabelAtlas::create(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelAtlas>(cx, (cocos2d::LabelAtlas *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     JS_ReportError(cx, "js_cocos2dx_LabelAtlas_create : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_LabelAtlas_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::LabelAtlas *cobj = new (std::nothrow) cocos2d::LabelAtlas();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::LabelAtlas>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::LabelAtlas"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_LabelAtlas_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::LabelAtlas *nobj = new (std::nothrow) cocos2d::LabelAtlas();
//     js_proxy_t *p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::LabelAtlas");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_AtlasNode_prototype;

// void js_register_cocos2dx_LabelAtlas(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_LabelAtlas_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_LabelAtlas_class->name = "LabelAtlas";
//     jsb_cocos2d_LabelAtlas_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelAtlas_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_LabelAtlas_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelAtlas_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_LabelAtlas_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_LabelAtlas_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_LabelAtlas_class->convert = JS_ConvertStub;
//     jsb_cocos2d_LabelAtlas_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("setString", js_cocos2dx_LabelAtlas_setString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithString", js_cocos2dx_LabelAtlas_initWithString, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getString", js_cocos2dx_LabelAtlas_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_LabelAtlas_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("_create", js_cocos2dx_LabelAtlas_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_AtlasNode_prototype);
//     jsb_cocos2d_LabelAtlas_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_LabelAtlas_class,
//         js_cocos2dx_LabelAtlas_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_LabelAtlas_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "LabelAtlas"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::LabelAtlas>(cx, jsb_cocos2d_LabelAtlas_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { cc.LabelAtlas.extend = cc.Class.extend; })()");
// }

// JSClass *jsb_cocos2d_LabelBMFont_class;
// JSObject *jsb_cocos2d_LabelBMFont_prototype;

// bool js_cocos2dx_LabelBMFont_setLineBreakWithoutSpace(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setLineBreakWithoutSpace : Invalid Native Object");
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setLineBreakWithoutSpace : Error processing arguments");
//         cobj->setLineBreakWithoutSpace(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setLineBreakWithoutSpace : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_getBlendFunc : Invalid Native Object");
//     if (argc == 0)
//     {
//         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
//         JS::RootedValue jsret(cx);
//         jsret = blendfunc_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_getLetter(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_getLetter : Invalid Native Object");
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_getLetter : Error processing arguments");
//         cocos2d::Sprite *ret = cobj->getLetter(arg0);
//         JS::RootedValue jsret(cx);
//         if (ret)
//         {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Sprite>(cx, (cocos2d::Sprite *)ret));
//         }
//         else
//         {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_getLetter : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_getString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_getString : Invalid Native Object");
//     if (argc == 0)
//     {
//         const std::string &ret = cobj->getString();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_getString : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setBlendFunc : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::BlendFunc arg0;
//         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setBlendFunc : Error processing arguments");
//         cobj->setBlendFunc(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_setString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setString : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setString : Error processing arguments");
//         cobj->setString(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setString : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_initWithString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_initWithString : Invalid Native Object");
//     if (argc == 2)
//     {
//         std::string arg0;
//         std::string arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 3)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 4)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         cocos2d::TextHAlignment arg3;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2, arg3);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 5)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         cocos2d::TextHAlignment arg3;
//         cocos2d::Vec2 arg4;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//         ok &= jsval_to_vector2(cx, args.get(4), &arg4);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2, arg3, arg4);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_initWithString : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_getFntFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_getFntFile : Invalid Native Object");
//     if (argc == 0)
//     {
//         const std::string &ret = cobj->getFntFile();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_getFntFile : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_LabelBMFont_setFntFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setFntFile : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setFntFile : Error processing arguments");
//         cobj->setFntFile(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2)
//     {
//         std::string arg0;
//         cocos2d::Vec2 arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_vector2(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setFntFile : Error processing arguments");
//         cobj->setFntFile(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setFntFile : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_setAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setAlignment : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::TextHAlignment arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setAlignment : Error processing arguments");
//         cobj->setAlignment(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_setWidth(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelBMFont *cobj = (cocos2d::LabelBMFont *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelBMFont_setWidth : Invalid Native Object");
//     if (argc == 1)
//     {
//         double arg0 = 0;
//         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelBMFont_setWidth : Error processing arguments");
//         cobj->setWidth(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_setWidth : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;

//     do
//     {
//         if (argc == 0)
//         {
//             cocos2d::LabelBMFont *ret = cocos2d::LabelBMFont::create();
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelBMFont>(cx, (cocos2d::LabelBMFont *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 2)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelBMFont *ret = cocos2d::LabelBMFont::create(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelBMFont>(cx, (cocos2d::LabelBMFont *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 3)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelBMFont *ret = cocos2d::LabelBMFont::create(arg0, arg1, arg2);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelBMFont>(cx, (cocos2d::LabelBMFont *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 4)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::TextHAlignment arg3;
//             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelBMFont *ret = cocos2d::LabelBMFont::create(arg0, arg1, arg2, arg3);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelBMFont>(cx, (cocos2d::LabelBMFont *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 5)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::TextHAlignment arg3;
//             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::Vec2 arg4;
//             ok &= jsval_to_vector2(cx, args.get(4), &arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelBMFont *ret = cocos2d::LabelBMFont::create(arg0, arg1, arg2, arg3, arg4);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelBMFont>(cx, (cocos2d::LabelBMFont *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     JS_ReportError(cx, "js_cocos2dx_LabelBMFont_create : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_LabelBMFont_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::LabelBMFont *cobj = new (std::nothrow) cocos2d::LabelBMFont();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::LabelBMFont>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::LabelBMFont"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_LabelBMFont_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::LabelBMFont *nobj = new (std::nothrow) cocos2d::LabelBMFont();
//     js_proxy_t *p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::LabelBMFont");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_LabelBMFont(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_LabelBMFont_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_LabelBMFont_class->name = "LabelBMFont";
//     jsb_cocos2d_LabelBMFont_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelBMFont_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_LabelBMFont_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelBMFont_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_LabelBMFont_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_LabelBMFont_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_LabelBMFont_class->convert = JS_ConvertStub;
//     jsb_cocos2d_LabelBMFont_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("setLineBreakWithoutSpace", js_cocos2dx_LabelBMFont_setLineBreakWithoutSpace, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBlendFunc", js_cocos2dx_LabelBMFont_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLetter", js_cocos2dx_LabelBMFont_getLetter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getString", js_cocos2dx_LabelBMFont_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendFunc", js_cocos2dx_LabelBMFont_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setString", js_cocos2dx_LabelBMFont_setString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithString", js_cocos2dx_LabelBMFont_initWithString, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFntFile", js_cocos2dx_LabelBMFont_getFntFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFntFile", js_cocos2dx_LabelBMFont_setFntFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setAlignment", js_cocos2dx_LabelBMFont_setAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setWidth", js_cocos2dx_LabelBMFont_setWidth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_LabelBMFont_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_LabelBMFont_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
//     jsb_cocos2d_LabelBMFont_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_LabelBMFont_class,
//         js_cocos2dx_LabelBMFont_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_LabelBMFont_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "LabelBMFont"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::LabelBMFont>(cx, jsb_cocos2d_LabelBMFont_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { cc.LabelBMFont.extend = cc.Class.extend; })()");
// }

// JSClass *jsb_cocos2d_LabelTTF_class;
// JSObject *jsb_cocos2d_LabelTTF_prototype;

// bool js_cocos2dx_LabelTTF_enableShadow(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_enableShadow : Invalid Native Object");
//     if (argc == 3)
//     {
//         cocos2d::Size arg0;
//         double arg1 = 0;
//         double arg2 = 0;
//         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
//         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_enableShadow : Error processing arguments");
//         cobj->enableShadow(arg0, arg1, arg2);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 4)
//     {
//         cocos2d::Size arg0;
//         double arg1 = 0;
//         double arg2 = 0;
//         bool arg3;
//         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
//         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         arg3 = JS::ToBoolean(args.get(3));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_enableShadow : Error processing arguments");
//         cobj->enableShadow(arg0, arg1, arg2, arg3);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_enableShadow : wrong number of arguments: %d, was expecting %d", argc, 3);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setDimensions(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setDimensions : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::Size arg0;
//         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setDimensions : Error processing arguments");
//         cobj->setDimensions(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setDimensions : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getFontSize : Invalid Native Object");
//     if (argc == 0)
//     {
//         double ret = cobj->getFontSize();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getString : Invalid Native Object");
//     if (argc == 0)
//     {
//         const std::string &ret = cobj->getString();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getString : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setFlippedY(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setFlippedY : Invalid Native Object");
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFlippedY : Error processing arguments");
//         cobj->setFlippedY(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setFlippedY : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setFlippedX(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setFlippedX : Invalid Native Object");
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFlippedX : Error processing arguments");
//         cobj->setFlippedX(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setFlippedX : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setTextDefinition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setTextDefinition : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::FontDefinition arg0;
//         ok &= jsval_to_FontDefinition(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setTextDefinition : Error processing arguments");
//         cobj->setTextDefinition(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setTextDefinition : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setFontName : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFontName : Error processing arguments");
//         cobj->setFontName(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getHorizontalAlignment : Invalid Native Object");
//     if (argc == 0)
//     {
//         int ret = (int)cobj->getHorizontalAlignment();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_initWithStringAndTextDefinition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_initWithStringAndTextDefinition : Invalid Native Object");
//     if (argc == 2)
//     {
//         std::string arg0;
//         cocos2d::FontDefinition arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_FontDefinition(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_initWithStringAndTextDefinition : Error processing arguments");
//         bool ret = cobj->initWithStringAndTextDefinition(arg0, arg1);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_initWithStringAndTextDefinition : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setString : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setString : Error processing arguments");
//         cobj->setString(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setString : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_initWithString(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_initWithString : Invalid Native Object");
//     if (argc == 3)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 4)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         cocos2d::Size arg3;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2, arg3);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 5)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         cocos2d::Size arg3;
//         cocos2d::TextHAlignment arg4;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//         ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2, arg3, arg4);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     if (argc == 6)
//     {
//         std::string arg0;
//         std::string arg1;
//         double arg2 = 0;
//         cocos2d::Size arg3;
//         cocos2d::TextHAlignment arg4;
//         cocos2d::TextVAlignment arg5;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//         ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//         ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//         ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_initWithString : Error processing arguments");
//         bool ret = cobj->initWithString(arg0, arg1, arg2, arg3, arg4, arg5);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_initWithString : wrong number of arguments: %d, was expecting %d", argc, 3);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setFontFillColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setFontFillColor : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::Color3B arg0;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFontFillColor : Error processing arguments");
//         cobj->setFontFillColor(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2)
//     {
//         cocos2d::Color3B arg0;
//         bool arg1;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFontFillColor : Error processing arguments");
//         cobj->setFontFillColor(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setFontFillColor : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getBlendFunc : Invalid Native Object");
//     if (argc == 0)
//     {
//         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
//         JS::RootedValue jsret(cx);
//         jsret = blendfunc_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_enableStroke(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_enableStroke : Invalid Native Object");
//     if (argc == 2)
//     {
//         cocos2d::Color3B arg0;
//         double arg1 = 0;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_enableStroke : Error processing arguments");
//         cobj->enableStroke(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 3)
//     {
//         cocos2d::Color3B arg0;
//         double arg1 = 0;
//         bool arg2;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         ok &= JS::ToNumber(cx, args.get(1), &arg1) && !std::isnan(arg1);
//         arg2 = JS::ToBoolean(args.get(2));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_enableStroke : Error processing arguments");
//         cobj->enableStroke(arg0, arg1, arg2);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_enableStroke : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getDimensions(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getDimensions : Invalid Native Object");
//     if (argc == 0)
//     {
//         const cocos2d::Size &ret = cobj->getDimensions();
//         JS::RootedValue jsret(cx);
//         jsret = ccsize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getDimensions : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setVerticalAlignment : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::TextVAlignment arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setVerticalAlignment : Error processing arguments");
//         cobj->setVerticalAlignment(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setFontSize : Invalid Native Object");
//     if (argc == 1)
//     {
//         double arg0 = 0;
//         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setFontSize : Error processing arguments");
//         cobj->setFontSize(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getVerticalAlignment : Invalid Native Object");
//     if (argc == 0)
//     {
//         int ret = (int)cobj->getVerticalAlignment();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getTextDefinition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getTextDefinition : Invalid Native Object");
//     if (argc == 0)
//     {
//         const cocos2d::FontDefinition &ret = cobj->getTextDefinition();
//         JS::RootedValue jsret(cx);
//         jsret = FontDefinition_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getTextDefinition : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setBlendFunc : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::BlendFunc arg0;
//         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setBlendFunc : Error processing arguments");
//         cobj->setBlendFunc(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_getFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_getFontName : Invalid Native Object");
//     if (argc == 0)
//     {
//         const std::string &ret = cobj->getFontName();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_getFontName : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_LabelTTF_setHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_setHorizontalAlignment : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::TextHAlignment arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_setHorizontalAlignment : Error processing arguments");
//         cobj->setHorizontalAlignment(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_setHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_disableShadow(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_disableShadow : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->disableShadow();
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_disableShadow : Error processing arguments");
//         cobj->disableShadow(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_disableShadow : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_disableStroke(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::LabelTTF *cobj = (cocos2d::LabelTTF *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_LabelTTF_disableStroke : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->disableStroke();
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_disableStroke : Error processing arguments");
//         cobj->disableStroke(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_disableStroke : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_LabelTTF_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;

//     do
//     {
//         if (argc == 0)
//         {
//             cocos2d::LabelTTF *ret = cocos2d::LabelTTF::create();
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelTTF>(cx, (cocos2d::LabelTTF *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 3)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelTTF *ret = cocos2d::LabelTTF::create(arg0, arg1, arg2);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelTTF>(cx, (cocos2d::LabelTTF *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 4)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::Size arg3;
//             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelTTF *ret = cocos2d::LabelTTF::create(arg0, arg1, arg2, arg3);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelTTF>(cx, (cocos2d::LabelTTF *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 5)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::Size arg3;
//             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::TextHAlignment arg4;
//             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelTTF *ret = cocos2d::LabelTTF::create(arg0, arg1, arg2, arg3, arg4);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelTTF>(cx, (cocos2d::LabelTTF *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     do
//     {
//         if (argc == 6)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             double arg2 = 0;
//             ok &= JS::ToNumber(cx, args.get(2), &arg2) && !std::isnan(arg2);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::Size arg3;
//             ok &= jsval_to_ccsize(cx, args.get(3), &arg3);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::TextHAlignment arg4;
//             ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::TextVAlignment arg5;
//             ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::LabelTTF *ret = cocos2d::LabelTTF::create(arg0, arg1, arg2, arg3, arg4, arg5);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::LabelTTF>(cx, (cocos2d::LabelTTF *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_create : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_LabelTTF_createWithFontDefinition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 2)
//     {
//         std::string arg0;
//         cocos2d::FontDefinition arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_FontDefinition(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_LabelTTF_createWithFontDefinition : Error processing arguments");

//         auto ret = cocos2d::LabelTTF::createWithFontDefinition(arg0, arg1);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::LabelTTF>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::LabelTTF"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_LabelTTF_createWithFontDefinition : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_LabelTTF_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::LabelTTF *cobj = new (std::nothrow) cocos2d::LabelTTF();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::LabelTTF>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::LabelTTF"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_LabelTTF_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::LabelTTF *nobj = new (std::nothrow) cocos2d::LabelTTF();
//     js_proxy_t *p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::LabelTTF");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_LabelTTF(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_LabelTTF_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_LabelTTF_class->name = "LabelTTF";
//     jsb_cocos2d_LabelTTF_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelTTF_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_LabelTTF_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_LabelTTF_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_LabelTTF_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_LabelTTF_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_LabelTTF_class->convert = JS_ConvertStub;
//     jsb_cocos2d_LabelTTF_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("enableShadow", js_cocos2dx_LabelTTF_enableShadow, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setDimensions", js_cocos2dx_LabelTTF_setDimensions, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFontSize", js_cocos2dx_LabelTTF_getFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getString", js_cocos2dx_LabelTTF_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFlippedY", js_cocos2dx_LabelTTF_setFlippedY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFlippedX", js_cocos2dx_LabelTTF_setFlippedX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextDefinition", js_cocos2dx_LabelTTF_setTextDefinition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFontName", js_cocos2dx_LabelTTF_setFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getHorizontalAlignment", js_cocos2dx_LabelTTF_getHorizontalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithStringAndTextDefinition", js_cocos2dx_LabelTTF_initWithStringAndTextDefinition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setString", js_cocos2dx_LabelTTF_setString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithString", js_cocos2dx_LabelTTF_initWithString, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFontFillColor", js_cocos2dx_LabelTTF_setFontFillColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBlendFunc", js_cocos2dx_LabelTTF_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("enableStroke", js_cocos2dx_LabelTTF_enableStroke, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getDimensions", js_cocos2dx_LabelTTF_getDimensions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setVerticalAlignment", js_cocos2dx_LabelTTF_setVerticalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setFontSize", js_cocos2dx_LabelTTF_setFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getVerticalAlignment", js_cocos2dx_LabelTTF_getVerticalAlignment, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextDefinition", js_cocos2dx_LabelTTF_getTextDefinition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendFunc", js_cocos2dx_LabelTTF_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFontName", js_cocos2dx_LabelTTF_getFontName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setHorizontalAlignment", js_cocos2dx_LabelTTF_setHorizontalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("disableShadow", js_cocos2dx_LabelTTF_disableShadow, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("disableStroke", js_cocos2dx_LabelTTF_disableStroke, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_LabelTTF_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_LabelTTF_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithFontDefinition", js_cocos2dx_LabelTTF_createWithFontDefinition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
//     jsb_cocos2d_LabelTTF_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_LabelTTF_class,
//         js_cocos2dx_LabelTTF_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_LabelTTF_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "LabelTTF"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::LabelTTF>(cx, jsb_cocos2d_LabelTTF_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { cc.LabelTTF.extend = cc.Class.extend; })()");
// }
