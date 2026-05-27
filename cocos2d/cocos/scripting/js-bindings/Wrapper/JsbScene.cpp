#include "JsbScene.hpp"
#include "2d/CCScene.h"
#include "2d/CCCamera.h"
#include "JsbCtor.hpp"
// JSClass  *jsb_cocos2d_Scene_class;
// JSObject *jsb_cocos2d_Scene_prototype;

// bool js_cocos2dx_Scene_setCameraOrderDirty(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_setCameraOrderDirty(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Scene* cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : NULL);
  cocos2d::Scene *cobj = (cocos2d::Scene *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_setCameraOrderDirty : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Scene_setCameraOrderDirty : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->setCameraOrderDirty();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->setCameraOrderDirty();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Scene_setCameraOrderDirty : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Scene_setCameraOrderDirty : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Scene_render(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_render(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  CCASSERT(false, "Scene::render is not exposed to JS");
  //     bool ok = true;
  //     cocos2d::Scene* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : nullptr);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_render : Invalid Native Object");
  //     do {
  //         if (argc == 4) {
  //             cocos2d::Renderer* arg0 = nullptr;
  //             do {
  //                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //                 if (!args.get(0).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg0 = (cocos2d::Renderer*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             const cocos2d::Mat4* arg1 = nullptr;
  //             do {
  //                 if (args.get(1).isNull()) { arg1 = nullptr; break; }
  //                 if (!args.get(1).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg1 = (const cocos2d::Mat4*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             const cocos2d::Mat4* arg2 = nullptr;
  //             do {
  //                 if (args.get(2).isNull()) { arg2 = nullptr; break; }
  //                 if (!args.get(2).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(2).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg2 = (const cocos2d::Mat4*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             unsigned int arg3 = 0;
  //             ok &= jsval_to_uint32(cx, args.get(3), &arg3);
  //             if (!ok) { ok = true; break; }
  //             cobj->render(arg0, arg1, arg2, arg3);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);

  //     do {
  //         if (argc == 2) {
  //             cocos2d::Renderer* arg0 = nullptr;
  //             do {
  //                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //                 if (!args.get(0).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg0 = (cocos2d::Renderer*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::Mat4 arg1;
  //             ok &= jsval_to_matrix(cx, args.get(1), &arg1);
  //             if (!ok) { ok = true; break; }
  //             cobj->render(arg0, arg1);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);

  //     do {
  //         if (argc == 3) {
  //             cocos2d::Renderer* arg0 = nullptr;
  //             do {
  //                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //                 if (!args.get(0).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg0 = (cocos2d::Renderer*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             cocos2d::Mat4 arg1;
  //             ok &= jsval_to_matrix(cx, args.get(1), &arg1);
  //             if (!ok) { ok = true; break; }
  //             const cocos2d::Mat4* arg2 = nullptr;
  //             do {
  //                 if (args.get(2).isNull()) { arg2 = nullptr; break; }
  //                 if (!args.get(2).isObject()) { ok = false; break; }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(2).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg2 = (const cocos2d::Mat4*)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok) { ok = true; break; }
  //             cobj->render(arg0, arg1, arg2);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);

  //     JS_ReportError(cx, "js_cocos2dx_Scene_render : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Scene_stepPhysicsAndNavigation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_stepPhysicsAndNavigation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Scene* cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : NULL);
  cocos2d::Scene *cobj = (cocos2d::Scene *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_stepPhysicsAndNavigation : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Scene_stepPhysicsAndNavigation : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Scene_stepPhysicsAndNavigation : Error processing arguments");
  //         cobj->stepPhysicsAndNavigation(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = 0;
    if (!args[0]->IsNumber() || !args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Scene_stepPhysicsAndNavigation : Error processing arguments");
      return;
    }
    arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromMaybe(0);
    cobj->stepPhysicsAndNavigation(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Scene_stepPhysicsAndNavigation : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Scene_stepPhysicsAndNavigation : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Scene_onProjectionChanged(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_onProjectionChanged(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Scene* cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : NULL);
  cocos2d::Scene *cobj = (cocos2d::Scene *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_onProjectionChanged : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Scene_onProjectionChanged : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::EventCustom* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::EventCustom*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Scene_onProjectionChanged : Error processing arguments");
  //         cobj->onProjectionChanged(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::EventCustom *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

      arg0 = (cocos2d::EventCustom *)tmpObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Scene_onProjectionChanged : Error processing arguments");
      return;
    }
    cobj->onProjectionChanged(arg0);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Scene_onProjectionChanged : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Scene_onProjectionChanged : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Scene_initWithSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_initWithSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Scene* cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : NULL);
  cocos2d::Scene *cobj = (cocos2d::Scene *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_initWithSize : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Scene_initWithSize : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Size arg0;
  //         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Scene_initWithSize : Error processing arguments");
  //         bool ret = cobj->initWithSize(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Size arg0;
    if (!JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Scene_initWithSize : Error processing arguments");
      return;
    }
    bool ret = cobj->initWithSize(arg0);
    args.GetReturnValue().Set(v8::Boolean::New(args.GetIsolate(), ret));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Scene_initWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Scene_initWithSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Scene_getDefaultCamera(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_getDefaultCamera(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Scene* cobj = (cocos2d::Scene *)(proxy ? proxy->ptr : NULL);
  cocos2d::Scene *cobj = (cocos2d::Scene *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Scene_getDefaultCamera : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Scene_getDefaultCamera : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Camera* ret = cobj->getDefaultCamera();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Camera>(cx, (cocos2d::Camera*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Camera *ret = cobj->getDefaultCamera();
    if (ret)
    {
      v8::Local<v8::Object> jsret;
      JsbUtils::NativePtrToObject(typeid(cocos2d::Camera).name(), ret, &jsret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      args.GetReturnValue().SetNull();
    }
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Scene_getDefaultCamera : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Scene_getDefaultCamera : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Scene_createWithSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_createWithSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1) {
  //         cocos2d::Size arg0;
  //         ok &= jsval_to_ccsize(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Scene_createWithSize : Error processing arguments");

  //         auto ret = cocos2d::Scene::createWithSize(arg0);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Scene>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Scene"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Size arg0;
    if (!JsbUtils::jsval_to_ccsize(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Scene_createWithSize : Error processing arguments");
      return;
    }

    auto ret = cocos2d::Scene::createWithSize(arg0);
    v8::Local<v8::Object> jsret;
    JsbUtils::NativePtrToObject(typeid(cocos2d::Scene).name(), ret, &jsret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Scene_createWithSize : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Scene_createWithSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Scene_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {

  //         auto ret = cocos2d::Scene::create();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Scene>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Scene"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    auto ret = cocos2d::Scene::create();
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Scene_create : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Scene_create : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Scene_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::Scene* cobj = new (std::nothrow) cocos2d::Scene();
  cocos2d::Scene *cobj = new (std::nothrow) cocos2d::Scene();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Scene>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::Scene"));
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(cobj);
  args.GetReturnValue().Set(jsobj);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     return true;
}

// static bool js_cocos2dx_Scene_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Scene_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::Scene *nobj = new (std::nothrow) cocos2d::Scene();
  cocos2d::Scene *nobj = new (std::nothrow) cocos2d::Scene();
  //     js_proxy_t* p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::Scene");
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(nobj);
  //     bool isFound = false;
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //     return true;
}

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_Scene(JSContext *cx, JS::HandleObject global) {
void js_register_cocos2dx_Scene(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_Scene_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_Scene_class->name = "Scene";
  //     jsb_cocos2d_Scene_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Scene_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Scene_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Scene_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Scene_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Scene_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Scene_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Scene_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_Scene_constructor);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Scene").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  JsbUtils::RegisterV8Class(typeid(cocos2d::Scene).name(), &tpl);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END
  //     };

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setCameraOrderDirty", js_cocos2dx_Scene_setCameraOrderDirty, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("render", js_cocos2dx_Scene_render, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("stepPhysicsAndNavigation", js_cocos2dx_Scene_stepPhysicsAndNavigation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("onProjectionChanged", js_cocos2dx_Scene_onProjectionChanged, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("initWithSize", js_cocos2dx_Scene_initWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("getDefaultCamera", js_cocos2dx_Scene_getDefaultCamera, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("ctor", js_cocos2dx_Scene_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FS_END
  //     };

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("createWithSize", js_cocos2dx_Scene_createWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FN("create", js_cocos2dx_Scene_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  //         JS_FS_END
  //     };

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
  //     jsb_cocos2d_Scene_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_Scene_class,
  //         js_cocos2dx_Scene_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Scene_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Scene"));
  //     JS_SetProperty(cx, proto, "_className", className);
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Scene>(cx, jsb_cocos2d_Scene_class, proto, parent_proto);
  //     anonEvaluate(cx, global, "(function () { cc.Scene.extend = cc.Class.extend; })()");
}
