#pragma once
#include "JsbUtils.h"
// JSObject* jsb_ref_create_jsobject(JSContext *cx, cocos2d::Ref *ref, js_type_class_t *typeClass, const char* debug)
// {
//     JS::RootedObject proto(cx, typeClass->proto.ref());
//     JS::RootedObject parent(cx, typeClass->parentProto.ref());
//     JS::RootedObject jsObj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
//     js_proxy_t* newproxy = jsb_new_proxy(ref, jsObj);
//     jsb_ref_init(cx, &newproxy->obj, ref, debug);
//     return jsObj;
// }

template <typename T>
void jsb_ref_init(T *ref)
{
  // //    CCLOG("jsb_ref_init: JSObject address =  %p. %s", obj->get(), debug);
  // #if CC_ENABLE_GC_FOR_NATIVE_OBJECTS
  //     (void)ref;
  //     JS::RootedObject jsObj(cx, *obj);
  //     js_add_FinalizeHook(cx, jsObj, true);
  //     // don't retain it, already retained
  // #if COCOS2D_DEBUG > 1
  //     CCLOG("++++++RETAINED++++++ Cpp(%s): %p - JS: %p", debug, ref, jsObj.get());
  // #endif // COCOS2D_DEBUG
  // #else
  //     // autorelease it
  ref->autorelease();
  //     JS::AddNamedObjectRoot(cx, obj, debug);
  // #endif
}

template <typename T>
v8::Local<v8::Object> jsb_ref_create_jsobject(T *ref)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> obj;

  if (!ref)
  {
    SE_REPORT_ERROR("Failed to create native object");
    return handle_scope.Escape(v8::Local<v8::Object>());
  }
  if (!ref)
  {
    SE_REPORT_ERROR("Failed to create native object");
    return handle_scope.Escape(v8::Local<v8::Object>());
  }

  const char *typeName = typeid(T).name();

  if (!JsbUtils::NativePtrToObject(typeName, ref, &obj))
  {
    SE_REPORT_ERROR("Failed to create js object for native type: %s", typeName);
    delete ref;
    return handle_scope.Escape(v8::Local<v8::Object>());
  }
  jsb_ref_init(ref);
  return handle_scope.Escape(obj);
}

// JSObject* jsb_ref_autoreleased_create_jsobject(JSContext *cx, cocos2d::Ref *ref, js_type_class_t *typeClass, const char* debug)
// {
//     JS::RootedObject proto(cx, typeClass->proto.ref());
//     JS::RootedObject parent(cx, typeClass->parentProto.ref());
//     JS::RootedObject jsObj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
//     js_proxy_t* newproxy = jsb_new_proxy(ref, jsObj);

//     return jsObj;
// }
template <typename T>
v8::Local<v8::Object> jsb_ref_autoreleased_create_jsobject(T *ref)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> obj;
  if (!ref)
  {
    SE_REPORT_ERROR("Failed to create native object");
    return handle_scope.Escape(v8::Local<v8::Object>());
  }
  const char *typeName = typeid(T).name();
  if (!JsbUtils::NativePtrToObject(typeName, ref, &obj))
  {
    SE_REPORT_ERROR("Failed to create js object for native type: %s", typeName);
    delete ref;
    return handle_scope.Escape(v8::Local<v8::Object>());
  }
  //     jsb_ref_autoreleased_init(cx, &newproxy->obj, ref, debug);
  return handle_scope.Escape(obj);
}

// get_or_create
// JSObject* jsb_ref_get_or_create_jsobject(JSContext *cx, cocos2d::Ref *ref, js_type_class_t *typeClass, const char* debug)
// {
//     auto proxy = jsb_get_native_proxy(ref);
//     if (proxy)
//     {
//         JS::RootedObject obj(cx, proxy->obj);
//         return obj;
//     }

//     JS::RootedObject proto(cx, typeClass->proto.ref());
//     JS::RootedObject parent(cx, typeClass->parentProto.ref());
//     JS::RootedObject jsObj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
//     js_proxy_t* newproxy = jsb_new_proxy(ref, jsObj);
// #if CC_ENABLE_GC_FOR_NATIVE_OBJECTS
//     CC_UNUSED_PARAM(newproxy);
//     ref->retain();
//     js_add_FinalizeHook(cx, jsObj, true);
// #if COCOS2D_DEBUG > 1
//     CCLOG("++++++RETAINED++++++ Cpp(%s): %p - JS: %p", debug, ref, jsObj.get());
// #endif // COCOS2D_DEBUG
// #else
//     // don't auto-release, don't retain.
//     JS::AddNamedObjectRoot(cx, &newproxy->obj, debug);
// #endif // CC_ENABLE_GC_FOR_NATIVE_OBJECTS

//     return jsObj;
// }

void CallCustomConstructor(const v8::FunctionCallbackInfo<v8::Value> &args, v8::Local<v8::Object> obj);


v8::Local<v8::FunctionTemplate> CreateFunctionTemplateWithConstructor(const char *className, v8::FunctionCallback constructor);
