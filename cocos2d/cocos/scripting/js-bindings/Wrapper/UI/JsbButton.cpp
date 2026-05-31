#include "JsbButton.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "ScriptEngine.hpp"
#include "ui/UIButton.h"
#include "ui/UIScale9Sprite.h"
#include "2d/CCLabel.h"
#include "editor-support/cocostudio/CocosStudioExtension.h"

// JSClass  *jsb_cocos2d_ui_Button_class;
// JSObject *jsb_cocos2d_ui_Button_prototype;

// bool js_cocos2dx_ui_Button_getNormalTextureSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getNormalTextureSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getNormalTextureSize : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getNormalTextureSize : Invalid Native Object");
    //     if (argc == 0) {
    //         cocos2d::Size ret = cobj->getNormalTextureSize();
    //         JS::RootedValue jsret(cx);
    //         jsret = ccsize_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 0)
    {
        cocos2d::Size ret = cBtn->getNormalTextureSize();
        args.GetReturnValue().Set(JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret));
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getNormalTextureSize : wrong number of arguments: %d, was expecting %d", argc, 0);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getNormalTextureSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getTitleText(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleText(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getTitleText : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleText : Invalid Native Object");
    //     if (argc == 0) {
    //         std::string ret = cobj->getTitleText();
    //         JS::RootedValue jsret(cx);
    //         jsret = std_string_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 0)
    {
        std::string ret = cBtn->getTitleText();
        args.GetReturnValue().Set(JsbUtils::ToV8String(args.GetIsolate(), ret));
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getTitleText : wrong number of arguments: %d, was expecting %d", argc, 0);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleText : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleLabel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleLabel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleLabel : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleLabel : Invalid Native Object");
    //     if (argc == 1) {
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleLabel : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    //         cocos2d::Label* arg0 = nullptr;
    cocos2d::Label *titleLabel = nullptr;
    //         do {
    //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
    //             if (!args.get(0).isObject()) { ok = false; break; }
    //             js_proxy_t *jsProxy;
    //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //             jsProxy = jsb_get_js_proxy(tmpObj);
    //             arg0 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
    //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
    //         } while (0);
    if (!args[0]->IsObject() && !args[0]->IsNull())
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleLabel : Error processing arguments");
        return;
    }
    else if (args[0]->IsObject())
    {
        v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
        titleLabel = (cocos2d::Label *)tmpObj->GetAlignedPointerFromInternalField(0);
        SE_PRECONDITION2(titleLabel, "js_cocos2dx_ui_Button_setTitleLabel : Invalid Native Object");
    }
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setTitleLabel : Error processing arguments");
    //         cobj->setTitleLabel(arg0);
    cBtn->setTitleLabel(titleLabel);
    //         args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //         return true;

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setTitleLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleFontSize : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleFontSize : Invalid Native Object");
    //     if (argc == 1) {
    //         double arg0 = 0;
    //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setTitleFontSize : Error processing arguments");
    //         cobj->setTitleFontSize(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleFontSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    if (!args[0]->IsNumber())
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleFontSize : Error processing arguments");
        return;
    }
    double fontSize = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    cBtn->setTitleFontSize(fontSize);
    args.GetReturnValue().SetUndefined();

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setTitleFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_resetPressedRender(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_resetPressedRender(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_resetPressedRender : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_resetPressedRender : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_resetPressedRender : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         cobj->resetPressedRender();
    cBtn->resetPressedRender();
    //         args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_resetPressedRender : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setScale9Enabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setScale9Enabled : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setScale9Enabled : Invalid Native Object");
    //     if (argc == 1) {
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setScale9Enabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    bool enable = args[0]->BooleanValue(isolate);
    cBtn->setScale9Enabled(enable);
    args.GetReturnValue().SetUndefined();
    //         bool arg0;
    //         arg0 = JS::ToBoolean(args.get(0));
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setScale9Enabled : Error processing arguments");
    //         cobj->setScale9Enabled(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_resetDisabledRender(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_resetDisabledRender(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_resetDisabledRender : Invalid Native Object");
    //     if (argc == 0) {
    //         cobj->resetDisabledRender();
    //         args.rval().setUndefined();
    //         return true;
    //     }

    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_resetDisabledRender : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    cBtn->resetDisabledRender();
    args.GetReturnValue().SetUndefined();
    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_resetDisabledRender : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getTitleRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleRenderer : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //         cocos2d::Label* ret = cobj->getTitleRenderer();
    cocos2d::Label *ret = cBtn->getTitleRenderer();
    //         JS::RootedValue jsret(cx);
    if (ret)
    {
        v8::Local<v8::Object> jsObj;
        JsbUtils::NativePtrToObject(typeid(cocos2d::Label).name(), ret, &jsObj);
        args.GetReturnValue().Set(jsObj);
    }
    else
    {
        args.GetReturnValue().SetNull();
    }
    //         if (ret) {
    //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Label>(cx, (cocos2d::Label*)ret));
    //         } else {
    //             jsret = JSVAL_NULL;
    //         };
    //         args.rval().set(jsret);
    //         return true;

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getTitleRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getRendererClicked(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getRendererClicked(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getRendererClicked : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getRendererClicked : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //         cocos2d::ui::Scale9Sprite* ret = cobj->getRendererClicked();
    cocos2d::ui::Scale9Sprite *ret = cBtn->getRendererClicked();
    if (ret)
    {
        v8::Local<v8::Object> jsObj;
        JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Scale9Sprite).name(), ret, &jsObj);
        args.GetReturnValue().Set(jsObj);
    }
    else
    {
        args.GetReturnValue().SetNull();
    }
}

// bool js_cocos2dx_ui_Button_getDisabledFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getDisabledFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getDisabledFile : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getDisabledFile : Invalid Native Object");
    //     if (argc == 0) {
    //         cocos2d::ResourceData ret = cobj->getDisabledFile();
    //         JS::RootedValue jsret(cx);
    //         jsret = resourcedata_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 0)
    {
        cocos2d::ResourceData ret = cBtn->getDisabledFile();
        args.GetReturnValue().Set(JsbUtils::resourcedata_to_jsval(args.GetIsolate(), ret));
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getDisabledFile : wrong number of arguments: %d, was expecting %d", argc, 0);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getDisabledFile : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getZoomScale(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getZoomScale : Invalid Native Object");
    if (args.Length() == 0)
    {
        double ret = cBtn->getZoomScale();
        args.GetReturnValue().Set(v8::Number::New(isolate, ret));
        return;
    }
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getZoomScale : Invalid Native Object");
    //     if (argc == 0) {
    //         double ret = cobj->getZoomScale();
    //         JS::RootedValue jsret(cx);
    //         jsret = DOUBLE_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }

    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getZoomScale : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

    //     return false;
}

// bool js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer : Invalid Native Object");
    if (args.Length() == 0)
    {
        const cocos2d::Rect &ret = cBtn->getCapInsetsDisabledRenderer();
        args.GetReturnValue().Set(JsbUtils::ccrect_to_jsval(args.GetIsolate(), ret));
        return;
    }

    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleColor : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleColor : Invalid Native Object");
    //     if (argc == 1) {
    //         cocos2d::Color3B arg0;
    //         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setTitleColor : Error processing arguments");
    //         cobj->setTitleColor(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleColor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    cocos2d::Color3B color;
    if (!JsbUtils::jsval_to_cccolor3b(args.GetIsolate(),
                                      args[0], &color))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleColor : Error processing arguments");
        return;
    }
    cBtn->setTitleColor(color);
    args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_ui_Button_getNormalFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getNormalFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getNormalFile : Invalid Native Object");
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getNormalFile : Invalid Native Object");
    if (args.Length() == 0)
    {
        cocos2d::ResourceData ret = cBtn->getNormalFile();
        args.GetReturnValue().Set(JsbUtils::resourcedata_to_jsval(args.GetIsolate(), ret));
        return;
    }
    //     if (argc == 0) {
    //         cocos2d::ResourceData ret = cobj->getNormalFile();
    //         JS::RootedValue jsret(cx);
    //         jsret = resourcedata_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getNormalFile : wrong number of arguments: %d, was expecting %d", argc, 0);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_getNormalFile : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_resetNormalRender(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_resetNormalRender(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_resetNormalRender : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_resetNormalRender : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_resetNormalRender : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         cobj->resetNormalRender();
    cBtn->resetNormalRender();
    //         args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_resetNormalRender : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getRendererDisabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getRendererDisabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getRendererDisabled : Invalid Native Object");
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getRendererDisabled : Invalid Native Object");
    //     if (argc == 0) {
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getRendererDisabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //         cocos2d::ui::Scale9Sprite* ret = cobj->getRendererDisabled();
    cocos2d::ui::Scale9Sprite *ret = cBtn->getRendererDisabled();
    if (ret)
    {
        v8::Local<v8::Object> jsObj;
        JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Scale9Sprite).name(), ret, &jsObj);
        args.GetReturnValue().Set(jsObj);
    }
    else
    {
        args.GetReturnValue().SetNull();
    }
    //         JS::RootedValue jsret(cx);
    //         if (ret) {
    //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Scale9Sprite>(cx, (cocos2d::ui::Scale9Sprite*)ret));
    //         } else {
    //             jsret = JSVAL_NULL;
    //         };
    //         args.rval().set(jsret);
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getRendererDisabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    cocos2d::Rect rect;
    if (!JsbUtils::jsval_to_ccrect(args.GetIsolate(), args[0], &rect))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer : Error processing arguments");
        return;
    }
    cBtn->setCapInsetsDisabledRenderer(rect);
    args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_ui_Button_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setCapInsets(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setCapInsets : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsets : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    cocos2d::Rect rect;
    if (!JsbUtils::jsval_to_ccrect(args.GetIsolate(), args[0], &rect))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsets : Error processing arguments");
        return;
    }
    cBtn->setCapInsets(rect);
    args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_ui_Button_loadTextureDisabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_loadTextureDisabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_loadTextureDisabled : Invalid Native Object");
    if (args.Length() == 1)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        cBtn->loadTextureDisabled(arg0);
        args.GetReturnValue().SetUndefined();
        return;
    }
    if (args.Length() == 2)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        int plistType = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cocos2d::ui::Widget::TextureResType arg1 = (cocos2d::ui::Widget::TextureResType)plistType;

        cBtn->loadTextureDisabled(arg0, arg1);
        args.GetReturnValue().SetUndefined();
        return;
    }

    SE_REPORT_ERROR("js_cocos2dx_ui_Button_loadTextureDisabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_ui_Button_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_init : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_init : Invalid Native Object");
    //     if (argc == 1) {
    //         std::string arg0;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_init : Error processing arguments");
    //         bool ret = cobj->init(arg0);
    //         JS::RootedValue jsret(cx);
    //         jsret = BOOLEAN_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 1)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        bool ret = cBtn->init(arg0);
        args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
        return;
    }
    //     if (argc == 2) {
    //         std::string arg0;
    //         std::string arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_init : Error processing arguments");
    //         bool ret = cobj->init(arg0, arg1);
    //         JS::RootedValue jsret(cx);
    //         jsret = BOOLEAN_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 2)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        bool ret = cBtn->init(arg0, arg1);
        args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
        return;
    }
    //     if (argc == 3) {
    //         std::string arg0;
    //         std::string arg1;
    //         std::string arg2;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         ok &= jsval_to_std_string(cx, args.get(2), &arg2);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_init : Error processing arguments");
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
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        bool ret = cBtn->init(arg0, arg1, arg2);
        args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
        return;
    }
    //     if (argc == 4) {
    //         std::string arg0;
    //         std::string arg1;
    //         std::string arg2;
    //         cocos2d::ui::Widget::TextureResType arg3;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         ok &= jsval_to_std_string(cx, args.get(2), &arg2);
    //         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_init : Error processing arguments");
    //         bool ret = cobj->init(arg0, arg1, arg2, arg3);
    //         JS::RootedValue jsret(cx);
    //         jsret = BOOLEAN_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    if (args.Length() == 4)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        int plistType = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)plistType;

        bool ret = cBtn->init(arg0, arg1, arg2, arg3);
        args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_init : wrong number of arguments: %d, was expecting %d", argc, 1);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_init : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleText(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleText(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleText : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleText : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleText : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    cBtn->setTitleText(arg0);
    args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_ui_Button_setCapInsetsNormalRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setCapInsetsNormalRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    //     if (argc == 1) {
    //         cocos2d::Rect arg0;
    //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : Error processing arguments");
    //         cobj->setCapInsetsNormalRenderer(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    cocos2d::Rect rect;
    if (!JsbUtils::jsval_to_ccrect(args.GetIsolate(), args[0], &rect))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : Error processing arguments");
        return;
    }
    cBtn->setCapInsetsNormalRenderer(rect);
    args.GetReturnValue().SetUndefined();

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setCapInsetsNormalRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_loadTexturePressed(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_loadTexturePressed(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_loadTexturePressed : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_loadTexturePressed : Invalid Native Object");
    //     if (argc == 1) {
    //         std::string arg0;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTexturePressed : Error processing arguments");
    //         cobj->loadTexturePressed(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() == 1)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        cBtn->loadTexturePressed(arg0);
        args.GetReturnValue().SetUndefined();
        return;
    }
    //     if (argc == 2) {
    //         std::string arg0;
    //         cocos2d::ui::Widget::TextureResType arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTexturePressed : Error processing arguments");
    //         cobj->loadTexturePressed(arg0, arg1);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() == 2)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        int plistType = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cocos2d::ui::Widget::TextureResType arg1 = (cocos2d::ui::Widget::TextureResType)plistType;

        cBtn->loadTexturePressed(arg0, arg1);
        args.GetReturnValue().SetUndefined();
        return;
    }

    SE_REPORT_ERROR("js_cocos2dx_ui_Button_loadTexturePressed : wrong number of arguments: %d, was expecting %d", args.Length(), 1);

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_loadTexturePressed : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleFontName : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleFontName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
    cBtn->setTitleFontName(arg0);
    args.GetReturnValue().SetUndefined();
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleFontName : Invalid Native Object");
    //     if (argc == 1) {
    //         std::string arg0;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setTitleFontName : Error processing arguments");
    //         cobj->setTitleFontName(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setTitleFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getCapInsetsNormalRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getCapInsetsNormalRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getCapInsetsNormalRenderer : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getCapInsetsNormalRenderer : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getCapInsetsNormalRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         const cocos2d::Rect& ret = cobj->getCapInsetsNormalRenderer();
    //         JS::RootedValue jsret(cx);
    //         jsret = ccrect_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }
    const cocos2d::Rect &ret = cBtn->getCapInsetsNormalRenderer();
    v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getCapInsetsNormalRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setTitleAlignment(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setTitleAlignment(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     bool ok = true;
    //     cocos2d::ui::Button* cobj = nullptr;

    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx);
    //     obj.set(args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : nullptr);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setTitleAlignment : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setTitleAlignment : Invalid Native Object");

    //         if (argc == 2) {
    //             cocos2d::TextHAlignment arg0;
    //             ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
    //             if (!ok) { ok = true; break; }
    //             cocos2d::TextVAlignment arg1;
    //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
    //             if (!ok) { ok = true; break; }
    //             cobj->setTitleAlignment(arg0, arg1);
    //             args.rval().setUndefined();
    //             return true;
    //         }
    if (args.Length() == 2)
    {
        int hAlign = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
        int vAlign = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cBtn->setTitleAlignment((cocos2d::TextHAlignment)hAlign, (cocos2d::TextVAlignment)vAlign);
        args.GetReturnValue().SetUndefined();
        return;
    }

    if (args.Length() == 1)
    {
        int hAlign = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cBtn->setTitleAlignment((cocos2d::TextHAlignment)hAlign);
        args.GetReturnValue().SetUndefined();
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setTitleAlignment : wrong number of arguments");
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_setTitleAlignment : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getCapInsetsPressedRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getCapInsetsPressedRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getCapInsetsPressedRenderer : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getCapInsetsPressedRenderer : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getCapInsetsPressedRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         const cocos2d::Rect& ret = cobj->getCapInsetsPressedRenderer();
    cocos2d::Rect ret = cBtn->getCapInsetsPressedRenderer();
    //         JS::RootedValue jsret(cx);
    //         jsret = ccrect_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getCapInsetsPressedRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_loadTextures(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_loadTextures(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_loadTextures : Invalid Native Object");
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_loadTextures : Invalid Native Object");
    //     if (argc == 2) {
    if (args.Length() == 2)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        cBtn->loadTextures(arg0, arg1);
        args.GetReturnValue().SetUndefined();
        return;
    }
    if (args.Length() == 3)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        cBtn->loadTextures(arg0, arg1, arg2);
        args.GetReturnValue().SetUndefined();
        return;
    }
    if (args.Length() == 4)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        int plistType = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)plistType;

        cBtn->loadTextures(arg0, arg1, arg2, arg3);
        args.GetReturnValue().SetUndefined();
        return;
    }
    //         std::string arg0;
    //         std::string arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTextures : Error processing arguments");
    //         cobj->loadTextures(arg0, arg1);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    //     if (argc == 3) {
    //         std::string arg0;
    //         std::string arg1;
    //         std::string arg2;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         ok &= jsval_to_std_string(cx, args.get(2), &arg2);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTextures : Error processing arguments");
    //         cobj->loadTextures(arg0, arg1, arg2);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    //     if (argc == 4) {
    //         std::string arg0;
    //         std::string arg1;
    //         std::string arg2;
    //         cocos2d::ui::Widget::TextureResType arg3;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //         ok &= jsval_to_std_string(cx, args.get(2), &arg2);
    //         ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTextures : Error processing arguments");
    //         cobj->loadTextures(arg0, arg1, arg2, arg3);
    //         args.rval().setUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_loadTextures : wrong number of arguments: %d, was expecting %d", argc, 2);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_loadTextures : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    //     return false;
}

// bool js_cocos2dx_ui_Button_isScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_isScale9Enabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_isScale9Enabled : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_isScale9Enabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    bool ret = cBtn->isScale9Enabled();
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_isScale9Enabled : Invalid Native Object");
    //     if (argc == 0) {
    //         bool ret = cobj->isScale9Enabled();
    //         JS::RootedValue jsret(cx);
    //         jsret = BOOLEAN_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_isScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_loadTextureNormal(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_loadTextureNormal(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_loadTextureNormal : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_loadTextureNormal : Invalid Native Object");
    //     if (argc == 1) {
    //         std::string arg0;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTextureNormal : Error processing arguments");
    //         cobj->loadTextureNormal(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() == 1)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        cBtn->loadTextureNormal(arg0);
        args.GetReturnValue().SetUndefined();
        return;
    }
    //     if (argc == 2) {
    //         std::string arg0;
    //         cocos2d::ui::Widget::TextureResType arg1;
    //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_loadTextureNormal : Error processing arguments");
    //         cobj->loadTextureNormal(arg0, arg1);
    //         args.rval().setUndefined();
    //         return true;
    //     }
    if (args.Length() == 2)
    {
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        int plistType = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
        cocos2d::ui::Widget::TextureResType arg1 = (cocos2d::ui::Widget::TextureResType)plistType;

        cBtn->loadTextureNormal(arg0, arg1);
        args.GetReturnValue().SetUndefined();
        return;
    }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_loadTextureNormal : wrong number of arguments: %d, was expecting %d", argc, 1);
    SE_REPORT_ERROR("js_cocos2dx_ui_Button_loadTextureNormal : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setCapInsetsPressedRenderer(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setCapInsetsPressedRenderer(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    cocos2d::Rect rect;
    if (!JsbUtils::jsval_to_ccrect(args.GetIsolate(), args[0], &rect))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : Error processing arguments");
        return;
    }
    cBtn->setCapInsetsPressedRenderer(rect);
    args.GetReturnValue().SetUndefined();
    return;
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : Invalid Native Object");
    //     if (argc == 1) {
    //         cocos2d::Rect arg0;
    //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : Error processing arguments");
    //         cobj->setCapInsetsPressedRenderer(arg0);
    //         args.rval().setUndefined();
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_setCapInsetsPressedRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getPressedFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getPressedFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getPressedFile : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getPressedFile : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getPressedFile : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    cocos2d::ResourceData ret = cBtn->getPressedFile();
    v8::Local<v8::Value> jsret = JsbUtils::resourcedata_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
    //     if (argc == 0) {
    //         cocos2d::ResourceData ret = cobj->getPressedFile();
    //         JS::RootedValue jsret(cx);
    //         jsret = resourcedata_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getPressedFile : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getTitleLabel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleLabel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getTitleLabel : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleLabel : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleLabel : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    cocos2d::Label *ret = cBtn->getTitleLabel();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
        v8::Local<v8::Object> jsObj;
        JsbUtils::NativePtrToObject(typeid(cocos2d::Label).name(), ret, &jsObj);
        jsret = jsObj;
    }
    else
    {
        jsret = v8::Null(args.GetIsolate());
    };
    args.GetReturnValue().Set(jsret);
    return;
}

// bool js_cocos2dx_ui_Button_getTitleFontSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleFontSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getTitleFontSize : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleFontSize : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleFontSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    double ret = cBtn->getTitleFontSize();
    args.GetReturnValue().Set(v8::Number::New(isolate, ret));
    return;
};

// bool js_cocos2dx_ui_Button_getRendererNormal(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getRendererNormal(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getRendererNormal : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getRendererNormal : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getRendererNormal : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }

    //         cocos2d::ui::Scale9Sprite* ret = cobj->getRendererNormal();
    cocos2d::ui::Scale9Sprite *ret = cBtn->getRendererNormal();
    //         JS::RootedValue jsret(cx);
    //         if (ret) {
    //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Scale9Sprite>(cx, (cocos2d::ui::Scale9Sprite*)ret));
    //         } else {
    //             jsret = JSVAL_NULL;
    //         };
    v8::Local<v8::Value> jsret;
    if (ret)
    {
        v8::Local<v8::Object> jsObj;
        JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Scale9Sprite).name(), ret, &jsObj);
        jsret = jsObj;
    }
    else
    {
        jsret = v8::Null(args.GetIsolate());
    };
    args.GetReturnValue().Set(jsret);
    return;
    //         args.rval().set(jsret);
    //         return true;
}

// bool js_cocos2dx_ui_Button_getTitleFontName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleFontName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getTitleFontName : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleFontName : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleFontName : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         std::string ret = cobj->getTitleFontName();
    std::string ret = cBtn->getTitleFontName();
    //         JS::RootedValue jsret(cx);
    //         jsret = std_string_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    v8::Local<v8::Value> jsret = JsbUtils::ToV8String(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getTitleFontName : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_getTitleColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_getTitleColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_getTitleColor : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_getTitleColor : Invalid Native Object");
    if (args.Length() != 0)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_getTitleColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
        return;
    }
    //     if (argc == 0) {
    //         cocos2d::Color3B ret = cobj->getTitleColor();
    cocos2d::Color3B ret = cBtn->getTitleColor();
    //         JS::RootedValue jsret(cx);
    //         jsret = cccolor3b_to_jsval(cx, ret);
    //         args.rval().set(jsret);
    v8::Local<v8::Value> jsret = JsbUtils::cccolor3b_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
    //         return true;
    //     }

    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_getTitleColor : wrong number of arguments: %d, was expecting %d", argc, 0);
    //     return false;
}

// bool js_cocos2dx_ui_Button_setPressedActionEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setPressedActionEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setPressedActionEnabled : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setPressedActionEnabled : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setPressedActionEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    bool arg0 = args[0]->BooleanValue(isolate);
    cBtn->setPressedActionEnabled(arg0);
    args.GetReturnValue().SetUndefined();
    return;
}

// bool js_cocos2dx_ui_Button_setZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_setZoomScale(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
    //     cocos2d::ui::Button* cobj = (cocos2d::ui::Button *)(proxy ? proxy->ptr : NULL);
    cocos2d::ui::Button *cBtn = (cocos2d::ui::Button *)args.This()->GetAlignedPointerFromInternalField(0);
    //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Button_setZoomScale : Invalid Native Object");
    SE_PRECONDITION2(cBtn, "js_cocos2dx_ui_Button_setZoomScale : Invalid Native Object");
    if (args.Length() != 1)
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setZoomScale : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
        return;
    }
    double arg0 = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
    if (std::isnan(arg0))
    {
        SE_REPORT_ERROR("js_cocos2dx_ui_Button_setZoomScale : Error processing arguments");
        return;
    }
    cBtn->setZoomScale(arg0);
    args.GetReturnValue().SetUndefined();
    return;
}

// bool js_cocos2dx_ui_Button_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;

    //         if (argc == 1) {
    if (args.Length() == 1)
    {
        //             std::string arg0;
        //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        //             if (!ok) { ok = true; break; }
        //             cocos2d::ui::Button* ret = cocos2d::ui::Button::create(arg0);
        cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg0);
        //             jsval jsret = JSVAL_NULL;
        //             if (ret) {
        //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Button>(cx, (cocos2d::ui::Button*)ret));
        //             } else {
        //                 jsret = JSVAL_NULL;
        //             };
        if (ret)
        {
            v8::Local<v8::Object> jsObj;
            JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Button).name(), ret, &jsObj);
            args.GetReturnValue().Set(jsObj);
        }
        else
        {
            args.GetReturnValue().SetNull();
        };
        //             args.rval().set(jsret);
        //             return true;+
        return;
    }
    //     do {
    //         if (argc == 2) {
    if (args.Length() == 2)
    {
        //             std::string arg0;
        //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        //             if (!ok) { ok = true; break; }
        //             std::string arg1;
        //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        //             if (!ok) { ok = true; break; }
        //             cocos2d::ui::Button* ret = cocos2d::ui::Button::create(arg0, arg1);
        cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg0, arg1);
        //             jsval jsret = JSVAL_NULL;
        //             if (ret) {
        //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Button>(cx, (cocos2d::ui::Button*)ret));
        //             } else {
        //                 jsret = JSVAL_NULL;
        //             };
        if (ret)
        {
            v8::Local<v8::Object> jsObj;
            JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Button).name(), ret, &jsObj);
            args.GetReturnValue().Set(jsObj);
        }
        else
        {
            args.GetReturnValue().SetNull();
        };
        return;
        //             args.rval().set(jsret);
        //             return true;
    }

    //     } while (0);
    //     do {
    //         if (argc == 3) {
    if (args.Length() == 3)
    {
        //             std::string arg0;
        //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        //             if (!ok) { ok = true; break; }
        //             std::string arg1;
        //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        //             if (!ok) { ok = true; break; }
        //             std::string arg2;
        //             ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        //             if (!ok) { ok = true; break; }
        //             cocos2d::ui::Button* ret = cocos2d::ui::Button::create(arg0, arg1, arg2);
        cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg0, arg1, arg2);
        //             jsval jsret = JSVAL_NULL;
        //             if (ret) {
        //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Button>(cx, (cocos2d::ui::Button*)ret));
        //             } else {
        //                 jsret = JSVAL_NULL;
        //             };
        if (ret)
        {
            v8::Local<v8::Object> jsObj;
            JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Button).name(), ret, &jsObj);
            args.GetReturnValue().Set(jsObj);
        }
        else
        {
            args.GetReturnValue().SetNull();
        };
        return;
        //             args.rval().set(jsret);
        //             return true;
    }
    //     } while (0);
    //     do {
    //         if (argc == 4) {
    if (args.Length() == 4)
    {
        //             std::string arg0;
        //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        std::string arg0 = JsbUtils::FromV8String(isolate, args[0]);
        //             if (!ok) { ok = true; break; }
        //             std::string arg1;
        //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        std::string arg1 = JsbUtils::FromV8String(isolate, args[1]);
        //             if (!ok) { ok = true; break; }
        //             std::string arg2;
        //             ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        std::string arg2 = JsbUtils::FromV8String(isolate, args[2]);
        //             if (!ok) { ok = true; break; }
        //             cocos2d::ui::Widget::TextureResType arg3;
        cocos2d::ui::Widget::TextureResType arg3;
        //             ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        int plistType = args[3]->Int32Value(isolate->GetCurrentContext()).FromJust();
        arg3 = (cocos2d::ui::Widget::TextureResType)plistType;
        //             if (!ok) { ok = true; break; }
        //             cocos2d::ui::Button* ret = cocos2d::ui::Button::create(arg0, arg1, arg2, arg3);
        cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg0, arg1, arg2, arg3);
        //             jsval jsret = JSVAL_NULL;
        //             if (ret) {
        //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Button>(cx, (cocos2d::ui::Button*)ret));
        //             } else {
        //                 jsret = JSVAL_NULL;
        //             };
        if (ret)
        {
            v8::Local<v8::Object> jsObj;
            JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Button).name(), ret, &jsObj);
            args.GetReturnValue().Set(jsObj);
        }
        else
        {
            args.GetReturnValue().SetNull();
        };
        return;
        //             args.rval().set(jsret);
        //             return true;
    }

    //     } while (0);

    //     do {
    //         if (argc == 0) {
    if (args.Length() == 0)
    {
        //             cocos2d::ui::Button* ret = cocos2d::ui::Button::create();
        cocos2d::ui::Button *ret = cocos2d::ui::Button::create();
        //             jsval jsret = JSVAL_NULL;
        //             if (ret) {
        //                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ui::Button>(cx, (cocos2d::ui::Button*)ret));
        //             } else {
        //                 jsret = JSVAL_NULL;
        //             };
        //             args.rval().set(jsret);
        //             return true;
        if (ret)
        {
            v8::Local<v8::Object> jsObj;
            JsbUtils::NativePtrToObject(typeid(cocos2d::ui::Button).name(), ret, &jsObj);
            args.GetReturnValue().Set(jsObj);
        }
        else
        {
            args.GetReturnValue().SetNull();
        };
        return;
    }
    //     } while (0);
    //     JS_ReportError(cx, "js_cocos2dx_ui_Button_create : wrong number of arguments");
    //     return false;
}

// bool js_cocos2dx_ui_Button_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     bool ok = true;
    //     cocos2d::ui::Button* cobj = new (std::nothrow) cocos2d::ui::Button();
    cocos2d::ui::Button *cBtn = new (std::nothrow) cocos2d::ui::Button();

    //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Button>(cobj);

    //     // link the native object with the javascript object
    //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::Button"));
    v8::Local<v8::Object> jsObj = jsb_ref_create_jsobject(cBtn);
    //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
    args.GetReturnValue().Set(jsObj);
    //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
    //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    CallCustomConstructor(args, jsObj);
    //     return true;
}

// static bool js_cocos2dx_ui_Button_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Button_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope handleScope(isolate);
    //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    //     cocos2d::ui::Button *nobj = new (std::nothrow) cocos2d::ui::Button();
    cocos2d::ui::Button *nobj = new (std::nothrow) cocos2d::ui::Button();
    //     js_proxy_t* p = jsb_new_proxy(nobj, obj);
    //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::Button");
    v8::Local<v8::Object> jsObj = jsb_ref_create_jsobject(nobj);
    args.GetReturnValue().SetUndefined();
    CallCustomConstructor(args, jsObj);
    //     bool isFound = false;
    //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
    //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
    //     args.rval().setUndefined();

    //     return true;
}

// extern JSObject *jsb_cocos2d_ui_Widget_prototype;

// void js_register_cocos2dx_ui_Button(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_ui_Button(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
    //     jsb_cocos2d_ui_Button_class = (JSClass *)calloc(1, sizeof(JSClass));
    //     jsb_cocos2d_ui_Button_class->name = "Button";
    //     jsb_cocos2d_ui_Button_class->addProperty = JS_PropertyStub;
    //     jsb_cocos2d_ui_Button_class->delProperty = JS_DeletePropertyStub;
    //     jsb_cocos2d_ui_Button_class->getProperty = JS_PropertyStub;
    //     jsb_cocos2d_ui_Button_class->setProperty = JS_StrictPropertyStub;
    //     jsb_cocos2d_ui_Button_class->enumerate = JS_EnumerateStub;
    //     jsb_cocos2d_ui_Button_class->resolve = JS_ResolveStub;
    //     jsb_cocos2d_ui_Button_class->convert = JS_ConvertStub;
    //     jsb_cocos2d_ui_Button_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
    v8::Local<v8::FunctionTemplate> buttonTpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_constructor);
    buttonTpl->SetClassName(JsbUtils::ToV8String(isolate, "Button"));
    buttonTpl->InstanceTemplate()->SetInternalFieldCount(1);
    JsbUtils::RegisterV8Class(typeid(cocos2d::ui::Button).name(), &buttonTpl);

    auto parentProto = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::ui::Widget).name());
    buttonTpl->Inherit(v8::Local<v8::FunctionTemplate>::New(isolate, parentProto));
    auto proto = buttonTpl->PrototypeTemplate();

    //     static JSPropertySpec properties[] = {
    //         JS_PS_END
    //     };

    //     static JSFunctionSpec funcs[] = {
    //         JS_FN("getNormalTextureSize", js_cocos2dx_ui_Button_getNormalTextureSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getNormalTextureSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getNormalTextureSize));
    //         JS_FN("getTitleText", js_cocos2dx_ui_Button_getTitleText, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleText", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleText));
    //         JS_FN("setTitleLabel", js_cocos2dx_ui_Button_setTitleLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleLabel", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleLabel));
    //         JS_FN("setTitleFontSize", js_cocos2dx_ui_Button_setTitleFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleFontSize));
    //         JS_FN("resetPressedRender", js_cocos2dx_ui_Button_resetPressedRender, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "resetPressedRender", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_resetPressedRender));
    //         JS_FN("setScale9Enabled", js_cocos2dx_ui_Button_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setScale9Enabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setScale9Enabled));
    //         JS_FN("resetDisabledRender", js_cocos2dx_ui_Button_resetDisabledRender, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "resetDisabledRender", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_resetDisabledRender));
    //         JS_FN("getTitleRenderer", js_cocos2dx_ui_Button_getTitleRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleRenderer));
    //         JS_FN("getRendererClicked", js_cocos2dx_ui_Button_getRendererClicked, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getRendererClicked", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getRendererClicked));
    //         JS_FN("getDisabledFile", js_cocos2dx_ui_Button_getDisabledFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getDisabledFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getDisabledFile));
    //         JS_FN("getZoomScale", js_cocos2dx_ui_Button_getZoomScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getZoomScale", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getZoomScale));
    //         JS_FN("getCapInsetsDisabledRenderer", js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getCapInsetsDisabledRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getCapInsetsDisabledRenderer));
    //         JS_FN("setTitleColor", js_cocos2dx_ui_Button_setTitleColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleColor));
    //         JS_FN("getNormalFile", js_cocos2dx_ui_Button_getNormalFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getNormalFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getNormalFile));
    //         JS_FN("resetNormalRender", js_cocos2dx_ui_Button_resetNormalRender, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "resetNormalRender", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_resetNormalRender));
    //         JS_FN("getRendererDisabled", js_cocos2dx_ui_Button_getRendererDisabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getRendererDisabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getRendererDisabled));
    //         JS_FN("setCapInsetsDisabledRenderer", js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setCapInsetsDisabledRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setCapInsetsDisabledRenderer));
    //         JS_FN("setCapInsets", js_cocos2dx_ui_Button_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setCapInsets", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setCapInsets));
    //         JS_FN("loadTextureDisabled", js_cocos2dx_ui_Button_loadTextureDisabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "loadTextureDisabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_loadTextureDisabled));
    //         JS_FN("init", js_cocos2dx_ui_Button_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_init));
    //         JS_FN("setTitleText", js_cocos2dx_ui_Button_setTitleText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleText", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleText));
    //         JS_FN("setCapInsetsNormalRenderer", js_cocos2dx_ui_Button_setCapInsetsNormalRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setCapInsetsNormalRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setCapInsetsNormalRenderer));
    //         JS_FN("loadTexturePressed", js_cocos2dx_ui_Button_loadTexturePressed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "loadTexturePressed", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_loadTexturePressed));
    //         JS_FN("setTitleFontName", js_cocos2dx_ui_Button_setTitleFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleFontName", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleFontName));
    //         JS_FN("getCapInsetsNormalRenderer", js_cocos2dx_ui_Button_getCapInsetsNormalRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getCapInsetsNormalRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getCapInsetsNormalRenderer));
    //         JS_FN("setTitleAlignment", js_cocos2dx_ui_Button_setTitleAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setTitleAlignment", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setTitleAlignment));
    //         JS_FN("getCapInsetsPressedRenderer", js_cocos2dx_ui_Button_getCapInsetsPressedRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getCapInsetsPressedRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getCapInsetsPressedRenderer));
    //         JS_FN("loadTextures", js_cocos2dx_ui_Button_loadTextures, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "loadTextures", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_loadTextures));
    //         JS_FN("isScale9Enabled", js_cocos2dx_ui_Button_isScale9Enabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "isScale9Enabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_isScale9Enabled));
    //         JS_FN("loadTextureNormal", js_cocos2dx_ui_Button_loadTextureNormal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "loadTextureNormal", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_loadTextureNormal));
    //         JS_FN("setCapInsetsPressedRenderer", js_cocos2dx_ui_Button_setCapInsetsPressedRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setCapInsetsPressedRenderer", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setCapInsetsPressedRenderer));
    //         JS_FN("getPressedFile", js_cocos2dx_ui_Button_getPressedFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getPressedFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getPressedFile));
    //         JS_FN("getTitleLabel", js_cocos2dx_ui_Button_getTitleLabel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleLabel", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleLabel));
    //         JS_FN("getTitleFontSize", js_cocos2dx_ui_Button_getTitleFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleFontSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleFontSize));
    //         JS_FN("getRendererNormal", js_cocos2dx_ui_Button_getRendererNormal, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getRendererNormal", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getRendererNormal));
    //         JS_FN("getTitleFontName", js_cocos2dx_ui_Button_getTitleFontName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleFontName", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleFontName));
    //         JS_FN("getTitleColor", js_cocos2dx_ui_Button_getTitleColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "getTitleColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_getTitleColor));
    //         JS_FN("setPressedActionEnabled", js_cocos2dx_ui_Button_setPressedActionEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setPressedActionEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setPressedActionEnabled));
    //         JS_FN("setZoomScale", js_cocos2dx_ui_Button_setZoomScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "setZoomScale", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_setZoomScale));
    //         JS_FN("ctor", js_cocos2dx_ui_Button_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_ctor));
    //         JS_FS_END
    //     };

    //     static JSFunctionSpec st_funcs[] = {
    //         JS_FN("create", js_cocos2dx_ui_Button_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
    buttonTpl->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_ui_Button_create));
    //         JS_FS_END
    //     };

    //     JS::RootedObject parent_proto(cx, jsb_cocos2d_ui_Widget_prototype);
    //     jsb_cocos2d_ui_Button_prototype = JS_InitClass(
    //         cx, global,
    //         parent_proto,
    //         jsb_cocos2d_ui_Button_class,
    //         js_cocos2dx_ui_Button_constructor, 0, // constructor
    //         properties,
    //         funcs,
    //         NULL, // no static properties
    //         st_funcs);

    //     JS::RootedObject proto(cx, jsb_cocos2d_ui_Button_prototype);
    //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Button"));
    //     JS_SetProperty(cx, proto, "_className", className);
    //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    //     // add the proto and JSClass to the type->js info hash table
    //     jsb_register_class<cocos2d::ui::Button>(cx, jsb_cocos2d_ui_Button_class, proto, parent_proto);
    //     anonEvaluate(cx, global, "(function () { ccui.Button.extend = cc.Class.extend; })()");
}
