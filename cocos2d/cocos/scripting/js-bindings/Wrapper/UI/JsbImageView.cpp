#include "JsbImageView.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "JsbWidget.hpp"
#include "ScriptEngine.hpp"
#include "ui/UIImageView.h"
#include "editor-support/cocostudio/CocosStudioExtension.h"

// JSClass  *jsb_cocos2d_ui_ImageView_class;
// JSObject *jsb_cocos2d_ui_ImageView_prototype;

// bool js_cocos2dx_ui_ImageView_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cobj = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_ui_ImageView_getBlendFunc : Invalid Native Object");

  //     if (argc == 0) {
  //         const cocos2d::BlendFunc& ret = cobj->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
    v8::Local<v8::Value> jsret = JsbUtils::blendfunc_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_getBlendFunc : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_loadTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_loadTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_loadTexture : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_loadTexture : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_loadTexture : Error processing arguments");
  //         cobj->loadTexture(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cImage->loadTexture(normalPath);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 2) {
  //         std::string arg0;
  //         cocos2d::ui::Widget::TextureResType arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_loadTexture : Error processing arguments");
  //         cobj->loadTexture(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cocos2d::ui::Widget::TextureResType texType = (cocos2d::ui::Widget::TextureResType)args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cImage->loadTexture(normalPath, texType);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_loadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_loadTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_setBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_setBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_setBlendFunc : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::BlendFunc arg0;
  //         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_setBlendFunc : Error processing arguments");
  //         cobj->setBlendFunc(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::BlendFunc blendFunc;
    JsbUtils::jsval_to_blendfunc(isolate, args[0], &blendFunc);
    cImage->setBlendFunc(blendFunc);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_setBlendFunc : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_init : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_init : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_init : Error processing arguments");
  //         bool ret = cobj->init(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    bool ret = cImage->init(normalPath);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }
  //     if (argc == 2) {
  //         std::string arg0;
  //         cocos2d::ui::Widget::TextureResType arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_init : Error processing arguments");
  //         bool ret = cobj->init(arg0, arg1);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cocos2d::ui::Widget::TextureResType texType = (cocos2d::ui::Widget::TextureResType)args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    bool ret = cImage->init(normalPath, texType);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_init : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_init : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_setScale9Enabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_setScale9Enabled : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_setScale9Enabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_setScale9Enabled : Error processing arguments");
  //         cobj->setScale9Enabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(isolate);
    cImage->setScale9Enabled(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_setScale9Enabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_setTextureRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_setTextureRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_setTextureRect : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_setTextureRect : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Rect arg0;
  //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_setTextureRect : Error processing arguments");
  //         cobj->setTextureRect(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Rect rect;
    JsbUtils::jsval_to_ccrect(isolate, args[0], &rect);
    cImage->setTextureRect(rect);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_setTextureRect : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_setTextureRect : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_setCapInsets(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_setCapInsets : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_setCapInsets : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Rect arg0;
  //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_ImageView_setCapInsets : Error processing arguments");
  //         cobj->setCapInsets(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Rect rect;
    JsbUtils::jsval_to_ccrect(isolate, args[0], &rect);
    cImage->setCapInsets(rect);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_setCapInsets : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_getRenderFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_getRenderFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_getRenderFile : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_getRenderFile : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::ResourceData ret = cobj->getRenderFile();
  //         JS::RootedValue jsret(cx);
  //         jsret = resourcedata_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::ResourceData ret = cImage->getRenderFile();
    v8::Local<v8::Value> jsret = JsbUtils::resourcedata_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_getRenderFile : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_getRenderFile : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_getCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_getCapInsets(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_getCapInsets : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_getCapInsets : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Rect& ret = cobj->getCapInsets();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Rect &ret = cImage->getCapInsets();
    v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_getCapInsets : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_getCapInsets : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_isScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_isScale9Enabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::ImageView* cobj = (cocos2d::ui::ImageView *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::ImageView *cImage = (cocos2d::ui::ImageView *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_ImageView_isScale9Enabled : Invalid Native Object");
  SE_PRECONDITION2(cImage, "js_cocos2dx_ui_ImageView_isScale9Enabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isScale9Enabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cImage->isScale9Enabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_isScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_isScale9Enabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     return false;
}

// bool js_cocos2dx_ui_ImageView_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;

  //         if (argc == 1) {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::ui::ImageView* ret = cocos2d::ui::ImageView::create(arg0);
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::ImageView>(cx, (cocos2d::ui::ImageView*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create(normalPath);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      jsret = JsbUtils::NativePtrToObject(ret);
    }
    else
    {
      jsret = v8::Null(isolate);
    };
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     do {
  //         if (argc == 2) {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::ui::Widget::TextureResType arg1;
  //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::ui::ImageView* ret = cocos2d::ui::ImageView::create(arg0, arg1);
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::ImageView>(cx, (cocos2d::ui::ImageView*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 2)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cocos2d::ui::Widget::TextureResType texType = (cocos2d::ui::Widget::TextureResType)args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create(normalPath, texType);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      jsret = JsbUtils::NativePtrToObject(ret);
    }
    else
    {
      jsret = v8::Null(isolate);
    };
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     } while (0);

  //     do {
  //         if (argc == 0) {
  //             cocos2d::ui::ImageView* ret = cocos2d::ui::ImageView::create();
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::ImageView>(cx, (cocos2d::ui::ImageView*)ret));
  //             } else {
  //                 jsret = JSVAL_NULL;
  //             };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      jsret = JsbUtils::NativePtrToObject(ret);
    }
    else
    {
      jsret = v8::Null(isolate);
    };
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     } while (0);
  //     JS_ReportError(cx, "js_cocos2dx_ui_ImageView_create : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_ui_ImageView_create : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ui_ImageView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::ui::ImageView* cobj = new (std::nothrow) cocos2d::ui::ImageView();
  cocos2d::ui::ImageView *cImage = new (std::nothrow) cocos2d::ui::ImageView();

  // ccui.ImageView.prototype._ctor = function(imageFileName, texType){
  //     if(imageFileName !== undefined){
  //         texType = texType || ccui.Widget.LOCAL_TEXTURE;
  //         ccui.ImageView.prototype._init.call(this, imageFileName, texType);
  //     }
  //     else
  //         ccui.Widget.prototype.init.call(this);
  // };
  if (args.Length() == 2)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cocos2d::ui::Widget::TextureResType texType = (cocos2d::ui::Widget::TextureResType)args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cImage->init(normalPath, texType);
  }
  else if (args.Length() == 1)
  {
    std::string normalPath = JsbUtils::FromV8String(isolate, args[0]);
    cImage->init(normalPath);
  }
  else
  {
    cImage->init();
  }

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::ImageView>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::ImageView"));
  auto jsObj = jsb_ref_create_jsobject(cImage);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  args.GetReturnValue().Set(jsObj);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsObj);
  //     return true;
}

// static bool js_cocos2dx_ui_ImageView_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_ImageView_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::ui::ImageView *nobj = new (std::nothrow) cocos2d::ui::ImageView();
  cocos2d::ui::ImageView *nobj = new (std::nothrow) cocos2d::ui::ImageView();
  //     js_proxy_t* p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::ImageView");
  //     bool isFound = false;
  auto jsObj = jsb_ref_autoreleased_create_jsobject(nobj);
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, jsObj);
  //     args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //     return true;
}

// extern JSObject *jsb_cocos2d_ui_Widget_prototype;

// void js_register_cocos2dx_ui_ImageView(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_ui_ImageView(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_ui_ImageView_class = (JSClass *)calloc(1, sizeof(JSClass));
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_ui_ImageView_class->name = "ImageView";
  //     jsb_cocos2d_ui_ImageView_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_ui_ImageView_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_ui_ImageView_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_ui_ImageView_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_ui_ImageView_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_ui_ImageView_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_ui_ImageView_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_ui_ImageView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "ImageView"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  auto proto = tpl->PrototypeTemplate();
  auto parent = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::ui::Widget).name());
  tpl->Inherit(parent);
  //     static JSPropertySpec properties[] = {
  //         JS_PS_END
  //     };

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("getBlendFunc", js_cocos2dx_ui_ImageView_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_getBlendFunc));
  //         JS_FN("loadTexture", js_cocos2dx_ui_ImageView_loadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "loadTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_loadTexture));
  //         JS_FN("setBlendFunc", js_cocos2dx_ui_ImageView_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_setBlendFunc));
  //         JS_FN("_init", js_cocos2dx_ui_ImageView_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "_init", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_init));
  //         JS_FN("setScale9Enabled", js_cocos2dx_ui_ImageView_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setScale9Enabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_setScale9Enabled));
  //         JS_FN("setTextureRect", js_cocos2dx_ui_ImageView_setTextureRect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTextureRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_setTextureRect));
  //         JS_FN("setCapInsets", js_cocos2dx_ui_ImageView_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCapInsets", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_setCapInsets));
  //         JS_FN("getRenderFile", js_cocos2dx_ui_ImageView_getRenderFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getRenderFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_getRenderFile));
  //         JS_FN("getCapInsets", js_cocos2dx_ui_ImageView_getCapInsets, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCapInsets", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_getCapInsets));
  //         JS_FN("isScale9Enabled", js_cocos2dx_ui_ImageView_isScale9Enabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isScale9Enabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_isScale9Enabled));
  //         JS_FN("ctor", js_cocos2dx_ui_ImageView_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_ctor));
  //         JS_FS_END
  //     };

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("create", js_cocos2dx_ui_ImageView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_ImageView_create));
  //         JS_FS_END
  //     };

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_ui_Widget_prototype);
  //     jsb_cocos2d_ui_ImageView_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_ui_ImageView_class,
  //         js_cocos2dx_ui_ImageView_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_ui_ImageView_prototype);

  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "ImageView"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "ImageView"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  proto->Set(isolate, "__is_ref", v8::True(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::ui::ImageView>(cx, jsb_cocos2d_ui_ImageView_class, proto, parent_proto);
  //     anonEvaluate(cx, global, "(function () { ccui.ImageView.extend = cc.Class.extend; })()");

  JsbUtils::RegisterV8Class(typeid(cocos2d::ui::ImageView).name(), &tpl);
  JsbUtils::BindJsClass("ImageView", global, tpl);
}
