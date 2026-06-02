#include "JsbLayout.hpp"
#include "JsbCtor.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "ui/UILayout.h"

// JSClass  *jsb_cocos2d_ui_Layout_class;
// JSObject *jsb_cocos2d_ui_Layout_prototype;

// bool js_cocos2dx_ui_Layout_setBackGroundColorVector(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ui_Layout_setBackGroundColorVector(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *iso = args.GetIsolate();
  v8::HandleScope handle_scope(iso);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
  cocos2d::ui::Layout *cLayout = (cocos2d::ui::Layout *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorVector : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorVector : Error processing arguments");
  //         cobj->setBackGroundColorVector(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundColorVector : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}
// }
// bool js_cocos2dx_ui_Layout_setClippingType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setClippingType : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::ui::Layout::ClippingType arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setClippingType : Error processing arguments");
//         cobj->setClippingType(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setClippingType : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundColorType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorType : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::ui::Layout::BackGroundColorType arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorType : Error processing arguments");
//         cobj->setBackGroundColorType(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundColorType : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setLoopFocus(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setLoopFocus : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setLoopFocus : Error processing arguments");
//         cobj->setLoopFocus(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setLoopFocus : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundImageColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageColor : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Color3B arg0;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageColor : Error processing arguments");
//         cobj->setBackGroundImageColor(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundImageColor : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundColorVector(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundColorVector : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Vec2& ret = cobj->getBackGroundColorVector();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundColorVector : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getClippingType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getClippingType : Invalid Native Object");
//     if (argc == 0) {
//         int ret = (int)cobj->getClippingType();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getClippingType : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getRenderFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getRenderFile : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::ResourceData ret = cobj->getRenderFile();
//         JS::RootedValue jsret(cx);
//         jsret = resourcedata_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getRenderFile : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_isLoopFocus(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_isLoopFocus : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isLoopFocus();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_isLoopFocus : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_removeBackGroundImage(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_removeBackGroundImage : Invalid Native Object");
//     if (argc == 0) {
//         cobj->removeBackGroundImage();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_removeBackGroundImage : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundColorOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundColorOpacity : Invalid Native Object");
//     if (argc == 0) {
//         uint16_t ret = cobj->getBackGroundColorOpacity();
//         JS::RootedValue jsret(cx);
//         jsret = uint32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundColorOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_isClippingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_isClippingEnabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isClippingEnabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_isClippingEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundImageOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageOpacity : Invalid Native Object");
//     if (argc == 1) {
//         uint16_t arg0;
//         ok &= jsval_to_uint16(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageOpacity : Error processing arguments");
//         cobj->setBackGroundImageOpacity(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundImageOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundImage(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImage : Invalid Native Object");
//     if (argc == 1) {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImage : Error processing arguments");
//         cobj->setBackGroundImage(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2) {
//         std::string arg0;
//         cocos2d::ui::Widget::TextureResType arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImage : Error processing arguments");
//         cobj->setBackGroundImage(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundImage : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::ui::Layout* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColor : Invalid Native Object");
//     do {
//         if (argc == 2) {
//             cocos2d::Color3B arg0;
//             ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//             if (!ok) { ok = true; break; }
//             cocos2d::Color3B arg1;
//             ok &= jsval_to_cccolor3b(cx, args.get(1), &arg1);
//             if (!ok) { ok = true; break; }
//             cobj->setBackGroundColor(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 1) {
//             cocos2d::Color3B arg0;
//             ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//             if (!ok) { ok = true; break; }
//             cobj->setBackGroundColor(arg0);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundColor : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_ui_Layout_requestDoLayout(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_requestDoLayout : Invalid Native Object");
//     if (argc == 0) {
//         cobj->requestDoLayout();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_requestDoLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundImageCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundImageCapInsets : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Rect& ret = cobj->getBackGroundImageCapInsets();
//         JS::RootedValue jsret(cx);
//         jsret = ccrect_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundImageCapInsets : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getBackGroundColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setClippingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setClippingEnabled : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setClippingEnabled : Error processing arguments");
//         cobj->setClippingEnabled(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setClippingEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundImageColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundImageColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getBackGroundImageColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundImageColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_isBackGroundImageScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_isBackGroundImageScale9Enabled : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isBackGroundImageScale9Enabled();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_isBackGroundImageScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundColorType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundColorType : Invalid Native Object");
//     if (argc == 0) {
//         int ret = (int)cobj->getBackGroundColorType();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundColorType : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundEndColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundEndColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getBackGroundEndColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundEndColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundColorOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorOpacity : Invalid Native Object");
//     if (argc == 1) {
//         uint16_t arg0;
//         ok &= jsval_to_uint16(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundColorOpacity : Error processing arguments");
//         cobj->setBackGroundColorOpacity(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundColorOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundImageOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundImageOpacity : Invalid Native Object");
//     if (argc == 0) {
//         uint16_t ret = cobj->getBackGroundImageOpacity();
//         JS::RootedValue jsret(cx);
//         jsret = uint32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundImageOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_isPassFocusToChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_isPassFocusToChild : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isPassFocusToChild();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_isPassFocusToChild : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundImageCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageCapInsets : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Rect arg0;
//         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageCapInsets : Error processing arguments");
//         cobj->setBackGroundImageCapInsets(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundImageCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundImageTextureSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundImageTextureSize : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Size& ret = cobj->getBackGroundImageTextureSize();
//         JS::RootedValue jsret(cx);
//         jsret = ccsize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundImageTextureSize : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_forceDoLayout(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_forceDoLayout : Invalid Native Object");
//     if (argc == 0) {
//         cobj->forceDoLayout();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_forceDoLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_ui_Layout_getLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getLayoutType : Invalid Native Object");
//     if (argc == 0) {
//         int ret = (int)cobj->getLayoutType();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getLayoutType : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setPassFocusToChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setPassFocusToChild : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setPassFocusToChild : Error processing arguments");
//         cobj->setPassFocusToChild(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setPassFocusToChild : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_getBackGroundStartColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_getBackGroundStartColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getBackGroundStartColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_getBackGroundStartColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setBackGroundImageScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageScale9Enabled : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setBackGroundImageScale9Enabled : Error processing arguments");
//         cobj->setBackGroundImageScale9Enabled(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setBackGroundImageScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_setLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ui::Layout* cobj = (cocos2d::ui::Layout *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_ui_Layout_setLayoutType : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::ui::Layout::Type arg0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ui_Layout_setLayoutType : Error processing arguments");
//         cobj->setLayoutType(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_setLayoutType : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ui_Layout_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0) {

//         auto ret = cocos2d::ui::Layout::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Layout>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ui::Layout"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ui_Layout_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ui_Layout_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ui::Layout* cobj = new (std::nothrow) cocos2d::ui::Layout();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ui::Layout>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ui::Layout"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_ui_Layout_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::ui::Layout *nobj = new (std::nothrow) cocos2d::ui::Layout();
//     js_proxy_t* p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ui::Layout");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_ui_Widget_prototype;

// void js_register_cocos2dx_ui_Layout(JSContext *cx, JS::HandleObject global) {
//     jsb_cocos2d_ui_Layout_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ui_Layout_class->name = "Layout";
//     jsb_cocos2d_ui_Layout_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_Layout_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ui_Layout_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ui_Layout_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ui_Layout_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ui_Layout_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ui_Layout_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ui_Layout_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END
//     };

//     static JSFunctionSpec funcs[] = {
//         JS_FN("setBackGroundColorVector", js_cocos2dx_ui_Layout_setBackGroundColorVector, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setClippingType", js_cocos2dx_ui_Layout_setClippingType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundColorType", js_cocos2dx_ui_Layout_setBackGroundColorType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setLoopFocus", js_cocos2dx_ui_Layout_setLoopFocus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundImageColor", js_cocos2dx_ui_Layout_setBackGroundImageColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundColorVector", js_cocos2dx_ui_Layout_getBackGroundColorVector, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getClippingType", js_cocos2dx_ui_Layout_getClippingType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRenderFile", js_cocos2dx_ui_Layout_getRenderFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isLoopFocus", js_cocos2dx_ui_Layout_isLoopFocus, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeBackGroundImage", js_cocos2dx_ui_Layout_removeBackGroundImage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundColorOpacity", js_cocos2dx_ui_Layout_getBackGroundColorOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isClippingEnabled", js_cocos2dx_ui_Layout_isClippingEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundImageOpacity", js_cocos2dx_ui_Layout_setBackGroundImageOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundImage", js_cocos2dx_ui_Layout_setBackGroundImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundColor", js_cocos2dx_ui_Layout_setBackGroundColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("requestDoLayout", js_cocos2dx_ui_Layout_requestDoLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundImageCapInsets", js_cocos2dx_ui_Layout_getBackGroundImageCapInsets, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundColor", js_cocos2dx_ui_Layout_getBackGroundColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setClippingEnabled", js_cocos2dx_ui_Layout_setClippingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundImageColor", js_cocos2dx_ui_Layout_getBackGroundImageColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isBackGroundImageScale9Enabled", js_cocos2dx_ui_Layout_isBackGroundImageScale9Enabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundColorType", js_cocos2dx_ui_Layout_getBackGroundColorType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundEndColor", js_cocos2dx_ui_Layout_getBackGroundEndColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundColorOpacity", js_cocos2dx_ui_Layout_setBackGroundColorOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundImageOpacity", js_cocos2dx_ui_Layout_getBackGroundImageOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isPassFocusToChild", js_cocos2dx_ui_Layout_isPassFocusToChild, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundImageCapInsets", js_cocos2dx_ui_Layout_setBackGroundImageCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundImageTextureSize", js_cocos2dx_ui_Layout_getBackGroundImageTextureSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("forceDoLayout", js_cocos2dx_ui_Layout_forceDoLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLayoutType", js_cocos2dx_ui_Layout_getLayoutType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setPassFocusToChild", js_cocos2dx_ui_Layout_setPassFocusToChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBackGroundStartColor", js_cocos2dx_ui_Layout_getBackGroundStartColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBackGroundImageScale9Enabled", js_cocos2dx_ui_Layout_setBackGroundImageScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setLayoutType", js_cocos2dx_ui_Layout_setLayoutType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_ui_Layout_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ui_Layout_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END
//     };

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ui_Widget_prototype);
//     jsb_cocos2d_ui_Layout_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ui_Layout_class,
//         js_cocos2dx_ui_Layout_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ui_Layout_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "Layout"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ui::Layout>(cx, jsb_cocos2d_ui_Layout_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { ccui.Layout.extend = cc.Class.extend; })()");
// }
