#include "JsbGLProgram.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "JsbCtor.hpp"
#include "renderer/backend/ProgramCache.h"

// bool js_cocos2dx_GLProgramCache_loadDefaultGLPrograms(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_loadDefaultGLPrograms(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLProgramCache *cobj = (cocos2d::GLProgramCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::backend::ProgramCache *cobj = (cocos2d::backend::ProgramCache *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLProgramCache_loadDefaultGLPrograms : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_GLProgramCache_loadDefaultGLPrograms : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLProgramCache_loadDefaultGLPrograms : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
    return;
  }
  //         cobj->loadDefaultGLPrograms();
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a method named loadDefaultGLPrograms");
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_loadDefaultGLPrograms : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLProgramCache *cobj = (cocos2d::GLProgramCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::backend::ProgramCache *cobj = (cocos2d::backend::ProgramCache *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cobj, "js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights : Invalid Native Object");

  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
    return;
  }
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a method named reloadDefaultGLProgramsRelativeToLights");
  //         cobj->reloadDefaultGLProgramsRelativeToLights();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_addGLProgram(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_addGLProgram(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a method named addGLProgram");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLProgramCache *cobj = (cocos2d::GLProgramCache *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLProgramCache_addGLProgram : Invalid Native Object");
  //     if (argc == 2)
  //     {
  //         cocos2d::GLProgram *arg0 = nullptr;
  //         std::string arg1;
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
  //             arg0 = (cocos2d::GLProgram *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLProgramCache_addGLProgram : Error processing arguments");
  //         cobj->addGLProgram(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_addGLProgram : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a method named reloadDefaultGLPrograms");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLProgramCache *cobj = (cocos2d::GLProgramCache *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->reloadDefaultGLPrograms();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_getGLProgram(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_getGLProgram(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::GLProgramCache *cobj = (cocos2d::GLProgramCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::backend::ProgramCache *cobj = (cocos2d::backend::ProgramCache *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_GLProgramCache_getGLProgram : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_GLProgramCache_getGLProgram : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLProgramCache_getGLProgram : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string program = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_GLProgramCache_getGLProgram : Error processing arguments");
  //         cocos2d::GLProgram *ret = cobj->getGLProgram(arg0);
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a method named getGLProgram");
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::GLProgram>(cx, (cocos2d::GLProgram *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_getGLProgram : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_destroyInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLProgramCache_destroyInstance : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
    return;
  }
  //         cocos2d::GLProgramCache::destroyInstance();
  cocos2d::backend::ProgramCache::destroyInstance();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_destroyInstance : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_GLProgramCache_getInstance : wrong number of arguments: %d, was expecting %d", (int)args.Length(), 0);
    return;
  }

  //         auto ret = cocos2d::GLProgramCache::getInstance();
  auto ret = cocos2d::backend::ProgramCache::getInstance();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::GLProgramCache>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_get_or_create_jsobject(cx, ret, typeClass, "cocos2d::GLProgramCache"));
  auto jsObj = JsbUtils::NativePtrToObject(ret);
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  args.GetReturnValue().Set(jsObj);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_GLProgramCache_getInstance : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_GLProgramCache_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_GLProgramCache_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::GLProgramCache *cobj = new (std::nothrow) cocos2d::GLProgramCache();
  CCASSERT(false, "cocos2d::backend::ProgramCache doesn't have a public constructor");

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::GLProgramCache>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::GLProgramCache"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  //     return true;
}

// void js_register_cocos2dx_GLProgramCache(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_GLProgramCache(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_GLProgramCache_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_GLProgramCache_class->name = "ShaderCache";
  //     jsb_cocos2d_GLProgramCache_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_GLProgramCache_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_GLProgramCache_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_GLProgramCache_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_GLProgramCache_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_GLProgramCache_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_GLProgramCache_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_GLProgramCache_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "ShaderCache"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("loadDefaultShaders", js_cocos2dx_GLProgramCache_loadDefaultGLPrograms, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "loadDefaultShaders", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_loadDefaultGLPrograms));
  //         JS_FN("reloadDefaultGLProgramsRelativeToLights", js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "reloadDefaultGLProgramsRelativeToLights", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights));
  //         JS_FN("addProgram", js_cocos2dx_GLProgramCache_addGLProgram, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "addProgram", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_addGLProgram));
  //         JS_FN("reloadDefaultShaders", js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "reloadDefaultShaders", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms));
  //         JS_FN("getProgram", js_cocos2dx_GLProgramCache_getGLProgram, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getProgram", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_getGLProgram));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("destroyInstance", js_cocos2dx_GLProgramCache_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "destroyInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_destroyInstance));
  //         JS_FN("getInstance", js_cocos2dx_GLProgramCache_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_GLProgramCache_getInstance));
  //         JS_FS_END};

  //     jsb_cocos2d_GLProgramCache_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_GLProgramCache_class,
  //         js_cocos2dx_GLProgramCache_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_GLProgramCache_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "GLProgramCache"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "GLProgramCache"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::True(isolate));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::GLProgramCache>(cx, jsb_cocos2d_GLProgramCache_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::backend::ProgramCache).name(), &tpl);
  JsbUtils::BindJsClass("ShaderCache", global, tpl);
}
