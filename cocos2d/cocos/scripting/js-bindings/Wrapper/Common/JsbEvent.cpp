#include "JsbEvent.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "JsbCtor.hpp"
#include "base/CCEventListener.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventCustom.h"
#include "2d/CCNode.h"

// JSClass *jsb_cocos2d_EventListener_class;
// JSObject *jsb_cocos2d_EventListener_prototype;

// bool js_cocos2dx_EventListener_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventListener_setEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventListener *cobj = (cocos2d::EventListener *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventListener *cobj = (cocos2d::EventListener *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventListener_setEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventListener_setEnabled : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventListener_setEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool enabled = args[0]->BooleanValue(isolate);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventListener_setEnabled : Error processing arguments");
  //         cobj->setEnabled(arg0);
  cobj->setEnabled(enabled);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventListener_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventListener_isEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventListener_isEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventListener *cobj = (cocos2d::EventListener *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventListener *cobj = (cocos2d::EventListener *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventListener_isEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventListener_isEnabled : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventListener_isEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isEnabled();
  bool ret = cobj->isEnabled();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventListener_isEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_EventListener_clone(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventListener_clone(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventListener *cobj = (cocos2d::EventListener *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventListener *cobj = (cocos2d::EventListener *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventListener_clone : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventListener_clone : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventListener_clone : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::EventListener *ret = cobj->clone();
  cocos2d::EventListener *ret = cobj->clone();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::EventListener>(cx, (cocos2d::EventListener *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  auto jsRet = JsbUtils::NativePtrToObject(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsRet);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventListener_clone : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_EventListener_checkAvailable(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventListener_checkAvailable(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventListener *cobj = (cocos2d::EventListener *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventListener *cobj = (cocos2d::EventListener *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventListener_checkAvailable : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventListener_checkAvailable : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventListener_checkAvailable : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->checkAvailable();
  bool ret = cobj->checkAvailable();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventListener_checkAvailable : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// void js_register_cocos2dx_EventListener(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_EventListener(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_EventListener_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_EventListener_class->name = "EventListener";
  //     jsb_cocos2d_EventListener_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventListener_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_EventListener_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventListener_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_EventListener_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_EventListener_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_EventListener_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_EventListener_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "EventListener").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setEnabled", js_cocos2dx_EventListener_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventListener_setEnabled));
  //         JS_FN("isEnabled", js_cocos2dx_EventListener_isEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventListener_isEnabled));
  //         JS_FN("clone", js_cocos2dx_EventListener_clone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "clone", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventListener_clone));
  //         JS_FN("checkAvailable", js_cocos2dx_EventListener_checkAvailable, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "checkAvailable", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventListener_checkAvailable));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     jsb_cocos2d_EventListener_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_EventListener_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_EventListener_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "EventListener"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "EventListener"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::EventListener>(cx, jsb_cocos2d_EventListener_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::EventListener).name(), &tpl);
  JsbUtils::BindJsClass("EventListener", global, tpl);
}
// JSClass *jsb_cocos2d_EventDispatcher_class;
// JSObject *jsb_cocos2d_EventDispatcher_prototype;

// bool js_cocos2dx_EventDispatcher_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_setEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_setEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_setEnabled : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_setEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_setEnabled : Error processing arguments");
  bool enabled = args[0]->BooleanValue(isolate);
  //         cobj->setEnabled(arg0);
  cobj->setEnabled(enabled);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_removeAllEventListeners(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_removeAllEventListeners(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_removeAllEventListeners : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_removeAllEventListeners : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeAllEventListeners : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->removeAllEventListeners();
  cobj->removeAllEventListeners();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_removeAllEventListeners : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::EventListener *arg0 = nullptr;
  cocos2d::EventListener *eventListener = nullptr;
  //         cocos2d::Node *arg1 = nullptr;
  cocos2d::Node *node = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : argument 0 should be an object");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  auto jsEventListenerObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  eventListener = (cocos2d::EventListener *)jsEventListenerObj->GetAlignedPointerFromInternalField(0);
  //             arg0 = (cocos2d::EventListener *)(jsProxy ? jsProxy->ptr : NULL);
  SE_PRECONDITION2(eventListener, "js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         do
  //         {
  //             if (args.get(1).isNull())
  //             {
  //                 arg1 = nullptr;
  //                 break;
  //             }
  if (args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : argument 1 should be non-null");
    return;
  }
  else if (!args[1]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : argument 1 should be an object");
    return;
  }
  //             if (!args.get(1).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsNodeObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  node = (cocos2d::Node *)jsNodeObj->GetAlignedPointerFromInternalField(0);
  //             JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : Error processing arguments");
  //         cobj->addEventListenerWithSceneGraphPriority(arg0, arg1);
  cobj->addEventListenerWithSceneGraphPriority(eventListener, node);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::EventListener *arg0 = nullptr;
  cocos2d::EventListener *eventListener = nullptr;
  //         int arg1 = 0;
  int priority = 0;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : argument 0 should be an object");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  auto jsEventListenerObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  //             arg0 = (cocos2d::EventListener *)(jsProxy ? jsProxy->ptr : NULL);
  eventListener = (cocos2d::EventListener *)jsEventListenerObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(eventListener, "js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  priority = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : Error processing arguments");
  //         cobj->addEventListenerWithFixedPriority(arg0, arg1);
  cobj->addEventListenerWithFixedPriority(eventListener, priority);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_removeEventListenersForTarget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_removeEventListenersForTarget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::EventDispatcher *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : nullptr);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_removeEventListenersForTarget : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_removeEventListenersForTarget : Invalid Native Object");
  //     do
  //     {
  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             cocos2d::Node *arg0 = nullptr;
    cocos2d::Node *node = nullptr;
    cocos2d::EventListener::Type type;
    //             do
    //             {
    //                 if (args.get(0).isNull())
    //                 {
    //                     arg0 = nullptr;
    //                     break;
    //                 }
    if (args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListenersForTarget : argument 0 should be non-null");
      return;
    }
    if (args[0]->IsInt32())
    {
      type = static_cast<cocos2d::EventListener::Type>(args[0]->Int32Value(isolate->GetCurrentContext()).FromJust());
      cobj->removeEventListenersForType(type);
      args.GetReturnValue().SetUndefined();
      return;
    }
    else if (args[0]->IsObject())
    {
      auto jsObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      node = (cocos2d::Node *)jsObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(node, "js_cocos2dx_EventDispatcher_removeEventListenersForTarget : Invalid Native Object");
      cobj->removeEventListenersForTarget(node);
      args.GetReturnValue().SetUndefined();
      return;
    }
  }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::Node *arg0 = nullptr;
    cocos2d::Node *node = nullptr;
    //             do
    //             {
    //                 if (args.get(0).isNull())
    //                 {
    //                     arg0 = nullptr;
    //                     break;
    //                 }
    if (args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListenersForTarget : argument 0 should be non-null");
      return;
    }
    //                 if (!args.get(0).isObject())
    //                 {
    //                     ok = false;
    //                     break;
    //                 }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListenersForTarget : argument 0 should be an object");
      return;
    }
    //                 js_proxy_t *jsProxy;
    //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    auto jsNodeObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    node = (cocos2d::Node *)jsNodeObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(node, "js_cocos2dx_EventDispatcher_removeEventListenersForTarget : Invalid Native Object");
    //                 jsProxy = jsb_get_js_proxy(tmpObj);
    //                 arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool arg1;
    //             arg1 = JS::ToBoolean(args.get(1));
    bool recursive = args[1]->BooleanValue(isolate);
    //             cobj->removeEventListenersForTarget(arg0, arg1);
    cobj->removeEventListenersForTarget(node, recursive);
    //             args.rval().setUndefined();
    //             return true;
  }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_removeEventListenersForTarget : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListenersForTarget : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_resumeEventListenersForTarget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_resumeEventListenersForTarget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    //         cocos2d::Node *arg0 = nullptr;
    cocos2d::Node *node = nullptr;
    //         do
    //         {
    //             if (args.get(0).isNull())
    //             {
    //                 arg0 = nullptr;
    //                 break;
    //             }
    if (args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : argument 0 should be non-null");
      return;
    }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : argument 0 should be an object");
      return;
    }
    //             if (!args.get(0).isObject())
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //             js_proxy_t *jsProxy;
    //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //             jsProxy = jsb_get_js_proxy(tmpObj);
    //             arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    auto jsNodeObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    node = (cocos2d::Node *)jsNodeObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(node, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Invalid Native Object");
    //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //         } while (0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Error processing arguments");
    //         cobj->resumeEventListenersForTarget(arg0);
    cobj->resumeEventListenersForTarget(node);
    //         args.rval().setUndefined();
    return;
    //         return true;
  }
  //     if (argc == 2)
  //     {
  if (args.Length() == 2)
  {
    //         cocos2d::Node *arg0 = nullptr;
    cocos2d::Node *node = nullptr;
    //         bool arg1;
    bool recursive = args[1]->BooleanValue(isolate);
    //         do
    //         {
    //             if (args.get(0).isNull())
    //             {
    //                 arg0 = nullptr;
    //                 break;
    //             }
    if (args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : argument 0 should be non-null");
      return;
    }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : argument 0 should be an object");
      return;
    }
    auto jsNodeObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    node = (cocos2d::Node *)jsNodeObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(node, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Invalid Native Object");
    //             if (!args.get(0).isObject())
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //             js_proxy_t *jsProxy;
    //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //             jsProxy = jsb_get_js_proxy(tmpObj);
    //             arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //         } while (0);
    //         arg1 = JS::ToBoolean(args.get(1));
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : Error processing arguments");
    //         cobj->resumeEventListenersForTarget(arg0, arg1);
    cobj->resumeEventListenersForTarget(node, recursive);
    //         args.rval().setUndefined();
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_resumeEventListenersForTarget : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_setPriority(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_setPriority(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_setPriority : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_setPriority : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_setPriority : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::EventListener *arg0 = nullptr;
  cocos2d::EventListener *eventListener = nullptr;
  //         int arg1 = 0;
  int priority = 0;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_setPriority : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_setPriority : argument 0 should be an object");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::EventListener *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsEventListenerObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  eventListener = (cocos2d::EventListener *)jsEventListenerObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(eventListener, "js_cocos2dx_EventDispatcher_setPriority : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  priority = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_setPriority : Error processing arguments");
  //         cobj->setPriority(arg0, arg1);
  cobj->setPriority(eventListener, priority);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_setPriority : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}
// bool js_cocos2dx_EventDispatcher_dispatchEvent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_dispatchEvent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_dispatchEvent : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_dispatchEvent : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_dispatchEvent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Event *arg0 = nullptr;
  cocos2d::Event *event = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_dispatchEvent : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_dispatchEvent : argument 0 should be an object");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Event *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsEventObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  event = (cocos2d::Event *)jsEventObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(event, "js_cocos2dx_EventDispatcher_dispatchEvent : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_dispatchEvent : Error processing arguments");
  //         cobj->dispatchEvent(arg0);
  cobj->dispatchEvent(event);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_dispatchEvent : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_hasEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_hasEventListener(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_hasEventListener : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_hasEventListener : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_hasEventListener : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::EventListener::ListenerID arg0;
  cocos2d::EventListener::ListenerID listenerID = JsbUtils::FromV8String(isolate, args[0]);

  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_hasEventListener : Error processing arguments");
  //         bool ret = cobj->hasEventListener(arg0);
  bool ret = cobj->hasEventListener(listenerID);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_hasEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_pauseEventListenersForTarget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_pauseEventListenersForTarget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : Invalid Native Object");
  //     if (argc == 1)
  //     {

  if (args.Length() == 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }

  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : argument 0 should be an object");
    return;
  }
  cocos2d::Node *node = nullptr;
  auto jsNodeObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  node = (cocos2d::Node *)jsNodeObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(node, "js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : Invalid Native Object");

  if (args.Length() == 1)
  {
    //         cocos2d::Node *arg0 = nullptr;
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
    //             arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);

    //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //         } while (0);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : Error processing arguments");
    //         cobj->pauseEventListenersForTarget(arg0);
    cobj->pauseEventListenersForTarget(node);
    //         args.rval().setUndefined();
    //         return true;
    return;
  }
  //     if (argc == 2)
  //     {
  if (args.Length() == 2)
  {

    //         arg1 = JS::ToBoolean(args.get(1));
    bool recursive = args[1]->BooleanValue(isolate);
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_pauseEventListenersForTarget : Error processing arguments");
    //         cobj->pauseEventListenersForTarget(arg0, arg1);
    cobj->pauseEventListenersForTarget(node, recursive);
    //         args.rval().setUndefined();
    //         return true;
  }
}

// bool js_cocos2dx_EventDispatcher_removeCustomEventListeners(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_removeCustomEventListeners(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_removeCustomEventListeners : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_removeCustomEventListeners : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeCustomEventListeners : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string eventName = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_removeCustomEventListeners : Error processing arguments");
  //         cobj->removeCustomEventListeners(arg0);
  cobj->removeCustomEventListeners(eventName);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_removeCustomEventListeners : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_removeEventListener(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_removeEventListener(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_removeEventListener : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_removeEventListener : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListener : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::EventListener *arg0 = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args.Length() == 0 || args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListener : argument 0 should be non-null");
    return;
  }
  else if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_removeEventListener : argument 0 should be an object");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::EventListener *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsEventListenerObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  cocos2d::EventListener *eventListener = (cocos2d::EventListener *)jsEventListenerObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(eventListener, "js_cocos2dx_EventDispatcher_removeEventListener : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventDispatcher_removeEventListener : Error processing arguments");
  //         cobj->removeEventListener(arg0);
  cobj->removeEventListener(eventListener);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_removeEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_isEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_isEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventDispatcher *cobj = (cocos2d::EventDispatcher *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventDispatcher_isEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventDispatcher_isEnabled : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventDispatcher_isEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isEnabled();
  bool ret = cobj->isEnabled();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventDispatcher_isEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_EventDispatcher_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventDispatcher_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::EventDispatcher *cobj = new (std::nothrow) cocos2d::EventDispatcher();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::EventDispatcher>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::EventDispatcher"));
  cocos2d::EventDispatcher *cobj = new (std::nothrow) cocos2d::EventDispatcher();
  auto jsobj = jsb_ref_create_jsobject(cobj);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  args.GetReturnValue().Set(jsobj);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     return true;
}

// void js_register_cocos2dx_EventDispatcher(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_EventDispatcher(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_EventDispatcher_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_EventDispatcher_class->name = "EventDispatcher";
  //     jsb_cocos2d_EventDispatcher_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventDispatcher_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_EventDispatcher_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventDispatcher_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_EventDispatcher_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_EventDispatcher_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_EventDispatcher_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_EventDispatcher_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto jsClass = v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_constructor);
  jsClass->SetClassName(v8::String::NewFromUtf8(isolate, "EventDispatcher").ToLocalChecked());
  jsClass->InstanceTemplate()->SetInternalFieldCount(1);
  auto proto = jsClass->PrototypeTemplate();
  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setEnabled", js_cocos2dx_EventDispatcher_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_setEnabled));
  //         JS_FN("removeAllListeners", js_cocos2dx_EventDispatcher_removeAllEventListeners, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAllListeners", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_removeAllEventListeners));
  //         JS_FN("addEventListenerWithSceneGraphPriority", js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addEventListenerWithSceneGraphPriority", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_addEventListenerWithSceneGraphPriority));
  //         JS_FN("addEventListenerWithFixedPriority", js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addEventListenerWithFixedPriority", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_addEventListenerWithFixedPriority));
  //         JS_FN("removeListeners", js_cocos2dx_EventDispatcher_removeEventListenersForTarget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeListeners", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_removeEventListenersForTarget));
  //         JS_FN("resumeTarget", js_cocos2dx_EventDispatcher_resumeEventListenersForTarget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "resumeTarget", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_resumeEventListenersForTarget));
  //         JS_FN("setPriority", js_cocos2dx_EventDispatcher_setPriority, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setPriority", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_setPriority));
  //         JS_FN("dispatchEvent", js_cocos2dx_EventDispatcher_dispatchEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "dispatchEvent", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_dispatchEvent));
  //         JS_FN("hasEventListener", js_cocos2dx_EventDispatcher_hasEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "hasEventListener", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_hasEventListener));
  //         JS_FN("pauseTarget", js_cocos2dx_EventDispatcher_pauseEventListenersForTarget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "pauseTarget", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_pauseEventListenersForTarget));
  //         JS_FN("removeCustomListeners", js_cocos2dx_EventDispatcher_removeCustomEventListeners, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeCustomListeners", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_removeCustomEventListeners));
  //         JS_FN("removeListener", js_cocos2dx_EventDispatcher_removeEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeListener", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_removeEventListener));
  //         JS_FN("isEnabled", js_cocos2dx_EventDispatcher_isEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventDispatcher_isEnabled));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     jsb_cocos2d_EventDispatcher_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_EventDispatcher_class,
  //         js_cocos2dx_EventDispatcher_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_EventDispatcher_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "EventDispatcher"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "EventDispatcher"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  proto->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::EventDispatcher>(cx, jsb_cocos2d_EventDispatcher_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::EventDispatcher).name(), &jsClass);
  JsbUtils::BindJsClass("EventDispatcher", global, jsClass);
}

// JSClass *jsb_cocos2d_Event_class;
// JSObject *jsb_cocos2d_Event_prototype;

// bool js_cocos2dx_Event_isStopped(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Event_isStopped(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Event *cobj = (cocos2d::Event *)(proxy ? proxy->ptr : NULL);
  cocos2d::Event *cobj = (cocos2d::Event *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Event_isStopped : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Event_isStopped : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Event_isStopped : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isStopped();
  bool ret = cobj->isStopped();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Event_isStopped : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Event_getType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Event_getType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Event *cobj = (cocos2d::Event *)(proxy ? proxy->ptr : NULL);
  cocos2d::Event *cobj = (cocos2d::Event *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Event_getType : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Event_getType : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Event_getType : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         int ret = (int)cobj->getType();
  int ret = (int)cobj->getType();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Event_getType : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Event_getCurrentTarget(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Event_getCurrentTarget(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Event *cobj = (cocos2d::Event *)(proxy ? proxy->ptr : NULL);
  cocos2d::Event *cobj = (cocos2d::Event *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Event_getCurrentTarget : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Event_getCurrentTarget : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Event_getCurrentTarget : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Node *ret = cobj->getCurrentTarget();
  cocos2d::Node *ret = cobj->getCurrentTarget();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  auto jsret = JsbUtils::NativePtrToObject(ret);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Event_getCurrentTarget : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Event_stopPropagation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Event_stopPropagation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Event *cobj = (cocos2d::Event *)(proxy ? proxy->ptr : NULL);
  cocos2d::Event *cobj = (cocos2d::Event *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Event_stopPropagation : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Event_stopPropagation : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Event_stopPropagation : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->stopPropagation();
  cobj->stopPropagation();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Event_stopPropagation : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}
// bool js_cocos2dx_Event_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Event_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::Event::Type arg0;
  if (args.Length() == 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Event_constructor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  cocos2d::Event::Type eventType;
  //     ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  eventType = (cocos2d::Event::Type)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Event_constructor : Error processing arguments");
  //     cocos2d::Event *cobj = new (std::nothrow) cocos2d::Event(arg0);
  cocos2d::Event *cobj = new (std::nothrow) cocos2d::Event(eventType);

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Event>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::Event"));
  auto jsobj = jsb_ref_create_jsobject(cobj);
  args.GetReturnValue().Set(jsobj);
  CallCustomConstructor(args, jsobj);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  //     return true;
}

// void js_register_cocos2dx_Event(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_Event(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_Event_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_Event_class->name = "Event";
  //     jsb_cocos2d_Event_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Event_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Event_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Event_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Event_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Event_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Event_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Event_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_Event_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "Event"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("isStopped", js_cocos2dx_Event_isStopped, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isStopped", v8::FunctionTemplate::New(isolate, js_cocos2dx_Event_isStopped));
  //         JS_FN("getType", js_cocos2dx_Event_getType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getType", v8::FunctionTemplate::New(isolate, js_cocos2dx_Event_getType));
  //         JS_FN("getCurrentTarget", js_cocos2dx_Event_getCurrentTarget, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getCurrentTarget", v8::FunctionTemplate::New(isolate, js_cocos2dx_Event_getCurrentTarget));
  //         JS_FN("stopPropagation", js_cocos2dx_Event_stopPropagation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopPropagation", v8::FunctionTemplate::New(isolate, js_cocos2dx_Event_stopPropagation));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     jsb_cocos2d_Event_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_Event_class,
  //         js_cocos2dx_Event_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Event_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Event"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "Event"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Event>(cx, jsb_cocos2d_Event_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::Event).name(), &tpl);
  JsbUtils::BindJsClass("Event", global, tpl);
}

// JSClass *jsb_cocos2d_EventCustom_class;
// JSObject *jsb_cocos2d_EventCustom_prototype;

// bool js_cocos2dx_EventCustom_getEventName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventCustom_getEventName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::EventCustom *cobj = (cocos2d::EventCustom *)(proxy ? proxy->ptr : NULL);
  cocos2d::EventCustom *cobj = (cocos2d::EventCustom *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_EventCustom_getEventName : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_EventCustom_getEventName : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_EventCustom_getEventName : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const std::string &ret = cobj->getEventName();
  const std::string &ret = cobj->getEventName();
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_EventCustom_getEventName : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_EventCustom_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_EventCustom_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     std::string arg0;
  //     ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string eventName = JsbUtils::FromV8String(isolate, args[0]);
  //     JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_EventCustom_constructor : Error processing arguments");
  //     cocos2d::EventCustom *cobj = new (std::nothrow) cocos2d::EventCustom(arg0);
  cocos2d::EventCustom *cobj = new (std::nothrow) cocos2d::EventCustom(eventName);

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::EventCustom>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::EventCustom"));
  auto jsobj = jsb_ref_create_jsobject(cobj);
  args.GetReturnValue().Set(jsobj);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     return true;
}

// extern JSObject *jsb_cocos2d_Event_prototype;

// void js_register_cocos2dx_EventCustom(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_EventCustom(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_EventCustom_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_EventCustom_class->name = "EventCustom";
  //     jsb_cocos2d_EventCustom_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventCustom_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_EventCustom_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_EventCustom_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_EventCustom_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_EventCustom_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_EventCustom_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_EventCustom_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_EventCustom_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "EventCustom"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  auto event = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::Event).name());
  tpl->Inherit(event);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("getEventName", js_cocos2dx_EventCustom_getEventName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getEventName", v8::FunctionTemplate::New(isolate, js_cocos2dx_EventCustom_getEventName));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_Event_prototype);
  //     jsb_cocos2d_EventCustom_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_EventCustom_class,
  //         js_cocos2dx_EventCustom_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_EventCustom_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "EventCustom"));
  //     JS_SetProperty(cx, proto, "_className", className);
  tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "EventCustom"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::EventCustom>(cx, jsb_cocos2d_EventCustom_class, proto, parent_proto);
  JsbUtils::RegisterV8Class(typeid(cocos2d::EventCustom).name(), &tpl);
  JsbUtils::BindJsClass("EventCustom", global, tpl);
}
