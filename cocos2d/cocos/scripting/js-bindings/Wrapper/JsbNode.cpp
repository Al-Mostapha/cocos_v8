#include "JsbNode.hpp"
#include "2d/CCNode.h"
#include "2d/CCScene.h"
#include "cocos2d.h"
#include "JsbConfig.h"
#include "renderer/backend/opengl/ProgramGL.h"
#include "JsbUtils.h"
// #include "ProgramGL.h"

// bool js_cocos2dx_Node_addChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_addChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  v8::Isolate *isolate = args.GetIsolate();
  v8::Local<v8::Object> obj = args.This();

  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(obj->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_addChild : Invalid Native Object");
  if (!cobj)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_addChild : Invalid Native Object");
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }

  const uint32_t argc = args.Length();

  if (argc == 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_addChild : wrong number of arguments: %d, was expecting %d", argc, 1);
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }

  cocos2d::Node *cChildNode = nullptr;
  v8::Local<v8::Value> childNode = args[0];
  int localZOrder = 0;
  int tag = cocos2d::Node::INVALID_TAG;

  if (childNode->IsNull() || childNode->IsUndefined())
  {
    cChildNode = nullptr;
    SE_PRECONDITION2(cChildNode, "Invalid Native Object");
    return;
  }
  else if (childNode->IsObject())
  {
    v8::Local<v8::Object> tmpObj = childNode->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cChildNode = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));
    SE_PRECONDITION2(cChildNode, "Invalid Native Object");
  }

  if (argc > 1)
  {

    localZOrder = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  }
  else if (argc > 2)
  {
    tag = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
  }

  cobj->addChild(cChildNode, localZOrder, tag);
}

// bool js_cocos2dx_Node_removeComponent(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeComponent : Invalid Native Object");
//     do {
//         if (argc == 1) {
//             cocos2d::Component* arg0 = nullptr;
//             do {
//                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
//                 if (!args.get(0).isObject()) { ok = false; break; }
//                 js_proxy_t *jsProxy;
//                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//                 jsProxy = jsb_get_js_proxy(tmpObj);
//                 arg0 = (cocos2d::Component*)(jsProxy ? jsProxy->ptr : NULL);
//                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//             } while (0);
//             if (!ok) { ok = true; break; }
//             bool ret = cobj->removeComponent(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 1) {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok) { ok = true; break; }
//             bool ret = cobj->removeComponent(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_removeComponent : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_setPhysicsBody(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPhysicsBody(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPhysicsBody : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::PhysicsBody* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::PhysicsBody*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPhysicsBody : Error processing arguments");
  //         cobj->setPhysicsBody(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::PhysicsBody *pBody = nullptr;
    v8::Local<v8::Value> arg0Val = args[0];
    v8::Isolate *isolate = args.GetIsolate();

    if (arg0Val->IsNull() || arg0Val->IsUndefined())
    {
      pBody = nullptr;
      SE_PRECONDITION2(pBody, "Invalid Native Object");
      return;
    }
    else if (arg0Val->IsObject())
    {
      v8::Local<v8::Object> tmpObj = arg0Val->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      pBody = static_cast<cocos2d::PhysicsBody *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(pBody, "Invalid Native Object");
    }
    cobj->setPhysicsBody(pBody);
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setPhysicsBody : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setPhysicsBody : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getGLProgram(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getGLProgram(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  // TODO: change the name of this function to getProgramState, since GLProgram is deprecated in cocos2d-x v4.0
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getGLProgram : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::GLProgram* ret = cobj->getGLProgram();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::GLProgram>(cx, (cocos2d::GLProgram*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::backend::ProgramState *ret = cobj->getProgramState();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Object> jsret;
    if (ret)
    {
      JsbUtils::NativePtrToObject(typeid(cocos2d::backend::ProgramState).name(), ret, &jsret);
    }
    else
    {
      // jsret = v8::Null(isolate);
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getGLProgram : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getGLProgram : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getDescription(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getDescription : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         std::string ret = cobj->getDescription();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    std::string ret = cobj->getDescription();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret;
    jsret = v8::String::NewFromUtf8(isolate, ret.c_str()).ToLocalChecked();
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getDescription : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}
// bool js_cocos2dx_Node_setOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setOpacityModifyRGB(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setOpacityModifyRGB : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setOpacityModifyRGB : Error processing arguments");
  //         cobj->setOpacityModifyRGB(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cobj->setOpacityModifyRGB(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setOpacityModifyRGB : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setOpacityModifyRGB : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setCascadeOpacityEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setCascadeOpacityEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setCascadeOpacityEnabled : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setCascadeOpacityEnabled : Error processing arguments");
  //         cobj->setCascadeOpacityEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());
    cobj->setCascadeOpacityEnabled(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getChildren(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getChildren(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getChildren : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     do {
  //         if (argc == 0) {
  //             const cocos2d::Vector<cocos2d::Node *>& ret = cobj->getChildren();
  //             jsval jsret = JSVAL_NULL;
  //             jsret = ccvector_to_jsval(cx, ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  //     } while(0);
  if (args.Length() == 0)
  {
    const cocos2d::Vector<cocos2d::Node *> &ret = cobj->getChildren();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = JsbUtils::ccvector_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getChildren : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getChildren : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setOnExitCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setOnExitCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope scope(isolate);
  auto context = isolate->GetCurrentContext();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setOnExitCallback : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() == 1)
  {
    //         std::function<void ()> arg0;
    std::function<void()> cFunc;
    v8::Local<v8::Value> jsCallback = args[0];

    // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
    // 		    {
    if (jsCallback->IsFunction())
    {
      v8::Local<v8::Function> jsFunc =
          args[0].As<v8::Function>();

      auto persistentFunc =
          std::make_shared<v8::Global<v8::Function>>(isolate, jsFunc);

      cFunc = [isolate, persistentFunc]()
      {
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
        v8::Local<v8::Function> func = persistentFunc->Get(isolate);
        v8::Context::Scope contextScope(ctx);
        v8::Local<v8::Value> result;
        if (func->Call(ctx, ctx->Global(), 0, nullptr).ToLocal(&result))
        {
          // Handle result if needed
        }
        else
        {
          // Handle exception if needed
          // You can log the exception or handle it as needed
        }
      };

      // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
      // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));

      // 		        auto lambda = [=]() -> void {
      // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
      // 		            JS::RootedValue rval(cx);
      // 		            bool succeed = func->invoke(0, nullptr, &rval);
      // 		            if (!succeed && JS_IsExceptionPending(cx)) {
      // 		                JS_ReportPendingException(cx);
      // 		            }
      // 		        };
      // 		        arg0 = lambda;
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setOnExitCallback : the argument should be a function");
      // 		        arg0 = nullptr;
      cFunc = nullptr;
      return;
    }

    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setOnExitCallback : Error processing arguments");
    //         cobj->setOnExitCallback(arg0);
    cobj->setOnExitCallback(cFunc);
    //         args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(isolate));
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setOnExitCallback : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setOnExitCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
  return;
}

// bool js_cocos2dx_Node_setActionManager(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setActionManager(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setActionManager : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::ActionManager* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ActionManager*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setActionManager : Error processing arguments");
  //         cobj->setActionManager(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::ActionManager *pActionManager = nullptr;
    v8::Local<v8::Value> arg0Val = args[0];
    v8::Isolate *isolate = args.GetIsolate();

    if (arg0Val->IsNull() || arg0Val->IsUndefined())
    {
      pActionManager = nullptr;
      SE_PRECONDITION2(pActionManager, "Invalid Native Object");
      return;
    }
    else if (arg0Val->IsObject())
    {
      v8::Local<v8::Object> tmpObj = arg0Val->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      pActionManager = static_cast<cocos2d::ActionManager *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(pActionManager, "Invalid Native Object");
    }
    cobj->setActionManager(pActionManager);
    args.GetReturnValue().Set(v8::Undefined(isolate));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setActionManager : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setActionManager : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_isIgnoreAnchorPointForPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isIgnoreAnchorPointForPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isIgnoreAnchorPointForPosition : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isIgnoreAnchorPointForPosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->isIgnoreAnchorPointForPosition();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Boolean::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_isIgnoreAnchorPointForPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getChildByName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getChildByName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getChildByName : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_getChildByName : Error processing arguments");
  //         cocos2d::Node* ret = cobj->getChildByName(arg0);
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    v8::Local<v8::Value> jsChildName = args[0];
    v8::Isolate *isolate = args.GetIsolate();
    std::string cChildName = JsbUtils::FromV8String(isolate, jsChildName);

    cocos2d::Node *ret = cobj->getChildByName(cChildName);

    v8::Local<v8::Object> jsret;
    if (ret)
    {
      JsbUtils::NativePtrToObject(typeid(cocos2d::Node).name(), ret, &jsret);
    }
    else
    {
      // jsret = v8::Null(isolate).As;
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getChildByName : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_getChildByName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_updateDisplayedOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_updateDisplayedOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateDisplayedOpacity : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         uint16_t arg0;
  //         ok &= jsval_to_uint16(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_updateDisplayedOpacity : Error processing arguments");
  //         cobj->updateDisplayedOpacity(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    uint16_t arg0 = args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    cobj->updateDisplayedOpacity(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_updateDisplayedOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_updateDisplayedOpacity : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_init : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->init();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cobj->init();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Boolean::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_init : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getCameraMask(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getCameraMask(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getCameraMask : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         unsigned short ret = cobj->getCameraMask();
  //         JS::RootedValue jsret(cx);
  //         jsret = ushort_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    unsigned short ret = cobj->getCameraMask();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Integer::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getCameraMask : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getCameraMask : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_setRotation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setRotation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotation : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotation : Error processing arguments");
  //         cobj->setRotation(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cobj->setRotation(arg0);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setRotation : Error processing arguments");
    }
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Node_setRotation : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setRotation : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setScaleZ(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setScaleZ(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScaleZ : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setScaleZ : Error processing arguments");
  //         cobj->setScaleZ(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cobj->setScaleZ(arg0);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setScaleZ : Error processing arguments");
    }
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setScaleZ : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Node_setScaleY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setScaleY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScaleY : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setScaleY : Error processing arguments");
  //         cobj->setScaleY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cobj->setScaleY(arg0);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setScaleY : Error processing arguments");
    }
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setScaleY : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setScaleY : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setScaleX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setScaleX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScaleX : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setScaleX : Error processing arguments");
  //         cobj->setScaleX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    if (!std::isnan(arg0))
    {
      cobj->setScaleX(arg0);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setScaleX : Error processing arguments");
    }
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setScaleX : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_getColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getColor : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Color3B& ret = cobj->getColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor3b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Color3B &ret = cobj->getColor();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = JsbUtils::cccolor3b_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setonEnterTransitionDidFinishCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setonEnterTransitionDidFinishCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setonEnterTransitionDidFinishCallback : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {

  //     }
  if (args.Length() == 1)
  {
    //         std::function<void ()> arg0;
    std::function<void()> cFunc;
    v8::Local<v8::Value> jsCallback = args[0];
    v8::Isolate *isolate = args.GetIsolate();

    if (jsCallback->IsFunction())
    {
      v8::Local<v8::Function> jsFunc =
          args[0].As<v8::Function>();

      auto persistentFunc =
          std::make_shared<v8::Global<v8::Function>>(isolate, jsFunc);

      cFunc = [isolate, persistentFunc]()
      {
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
        v8::Local<v8::Function> func = persistentFunc->Get(isolate);
        v8::Context::Scope contextScope(ctx);
        v8::Local<v8::Value> result;
        if (func->Call(ctx, ctx->Global(), 0, nullptr).ToLocal(&result))
        {
          // Handle result if needed
        }
        else
        {
          // Handle exception if needed
          // You can log the exception or handle it as needed
        }
      };
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setonEnterTransitionDidFinishCallback : the argument should be a function");
      cFunc = nullptr;
      return;
    }
    // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
    // 		    {
    // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
    // 		        auto lambda = [=]() -> void {
    // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    // 		            JS::RootedValue rval(cx);
    // 		            bool succeed = func->invoke(0, nullptr, &rval);
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

    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setonEnterTransitionDidFinishCallback : Error processing arguments");
    SE_PRECONDITION2(cFunc != nullptr, "Error processing arguments");
    //         cobj->setonEnterTransitionDidFinishCallback(arg0);
    cobj->setOnEnterTransitionDidFinishCallback(cFunc);
    //         args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(isolate));
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setonEnterTransitionDidFinishCallback : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setonEnterTransitionDidFinishCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_removeAllComponents(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeAllComponents(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeAllComponents : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->removeAllComponents();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cobj->removeAllComponents();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeAllComponents : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_removeAllComponents : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node__setLocalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node__setLocalZOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node__setLocalZOrder : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         int32_t arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node__setLocalZOrder : Error processing arguments");
  //         cobj->_setLocalZOrder(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int32_t arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    cobj->_setLocalZOrder(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node__setLocalZOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node__setLocalZOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setCameraMask(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setCameraMask(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setCameraMask : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 1) {
  //         unsigned short arg0 = 0;
  //         ok &= jsval_to_ushort(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setCameraMask : Error processing arguments");
  //         cobj->setCameraMask(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    unsigned short arg0 = args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    cobj->setCameraMask(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     if (argc == 2) {
  //         unsigned short arg0 = 0;
  //         bool arg1;
  //         ok &= jsval_to_ushort(cx, args.get(0), &arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setCameraMask : Error processing arguments");
  //         cobj->setCameraMask(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    unsigned short arg0 = args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(args.GetIsolate());
    cobj->setCameraMask(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setCameraMask : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setCameraMask : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getTag : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         int ret = cobj->getTag();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cobj->getTag();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Integer::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getTag : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getTag : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getonEnterTransitionDidFinishCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getonEnterTransitionDidFinishCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getonEnterTransitionDidFinishCallback : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         const std::function<void ()>& ret = cobj->getonEnterTransitionDidFinishCallback();
  //         JS::RootedValue jsret(cx);
  //         #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::function<void()> &ret = cobj->getOnEnterTransitionDidFinishCallback();
    SE_REPORT_ERROR("js_cocos2dx_Node_getonEnterTransitionDidFinishCallback : Return type std::function<void ()> is not supported");
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getonEnterTransitionDidFinishCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getonEnterTransitionDidFinishCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getNodeToWorldAffineTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNodeToWorldAffineTransform : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::AffineTransform ret = cobj->getNodeToWorldAffineTransform();
//         JS::RootedValue jsret(cx);
//         jsret = ccaffinetransform_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getNodeToWorldAffineTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_Node_getPosition3D(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPosition3D(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPosition3D : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Vec3 ret = cobj->getPosition3D();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector3_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Vec3 ret = cNode->getPosition3D();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = JsbUtils::vector3_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPosition3D : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPosition3D : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_removeChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeChild : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Node* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChild : Error processing arguments");
  //         cobj->removeChild(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Node *cChildNode = nullptr;
    if (args[0]->IsNull())
    {
      cChildNode = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cChildNode = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cChildNode, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_removeChild : Error processing arguments");
      return;
    }
    cNode->removeChild(cChildNode);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //     if (argc == 2) {
  //         cocos2d::Node* arg0 = nullptr;
  //         bool arg1;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChild : Error processing arguments");
  //         cobj->removeChild(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    cocos2d::Node *cChildNode = nullptr;
    if (args[0]->IsNull())
    {
      cChildNode = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cChildNode = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cChildNode, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_removeChild : Error processing arguments");
      return;
    }
    bool cCleanUp = args[1]->BooleanValue(args.GetIsolate());
    cNode->removeChild(cChildNode, cCleanUp);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeChild : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_removeChild : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getScene(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScene(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScene : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Scene* ret = cobj->getScene();
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scene>(cx, (cocos2d::Scene*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Scene *ret = cobj->getScene();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Object> jsret;
    if (ret)
    {
      bool ok = JsbUtils::NativePtrToObject(typeid(cocos2d::Scene).name(), ret, &jsret);
      SE_PRECONDITION2(ok, "js_cocos2dx_Node_getScene : Error processing arguments");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_getScene : getScene returned nullptr");
      // jsret = v8::Null(isolate);
    };
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getScene : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getEventDispatcher(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getEventDispatcher(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getEventDispatcher : Invalid Native Object");
  SE_PRECONDITION2(cobj, "Invalid Native Object");
  //     if (argc == 0) {
  if (args.Length() == 0)
  {
    //         cocos2d::EventDispatcher* ret = cobj->getEventDispatcher();
    cocos2d::EventDispatcher *ret = cobj->getEventDispatcher();
    //         JS::RootedValue jsret(cx);
    //         if (ret) {
    //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::EventDispatcher>(cx, (cocos2d::EventDispatcher*)ret));
    //         } else {
    //             jsret = JSVAL_NULL;
    //         };
    if (ret)
    {
      v8::Local<v8::Object> jsret;
      bool ok = JsbUtils::NativePtrToObject(typeid(cocos2d::EventDispatcher).name(), ret, &jsret);
      SE_PRECONDITION2(ok, "js_cocos2dx_Node_getEventDispatcher : Error processing arguments");
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_getEventDispatcher : getEventDispatcher returned nullptr");
      args.GetReturnValue().Set(v8::Null(args.GetIsolate()));
    };
    //         args.rval().set(jsret);
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getEventDispatcher : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getEventDispatcher : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setSkewX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setSkewX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setSkewX : Error processing arguments");
  //         cobj->setSkewX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    cNode->setSkewX(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setSkewX : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_setGLProgramState(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setGLProgramState(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setGLProgramState : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::GLProgramState* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::GLProgramState*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setGLProgramState : Error processing arguments");
  //         cobj->setGLProgramState(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::backend::ProgramState *cGLProgramState = nullptr;
    if (args[0]->IsNull())
    {
      cGLProgramState = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cGLProgramState = static_cast<cocos2d::backend::ProgramState *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cGLProgramState, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setGLProgramState : Error processing arguments");
      return;
    }
    cNode->setProgramState(cGLProgramState);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setGLProgramState : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setGLProgramState : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setOnEnterCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setOnEnterCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setOnEnterCallback : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  if (args.Length() == 1)
  {
    //         std::function<void ()> arg0;
    std::function<void()> cFunc;

    // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
    // 		    {
    if (args[0]->IsFunction())
    {
      // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
      v8::Local<v8::Object> jstarget = args.This();
      v8::Local<v8::Function> jsFunc = args[0].As<v8::Function>();
      // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
      std::shared_ptr<v8::Global<v8::Function>> func(new v8::Global<v8::Function>(args.GetIsolate(), jsFunc));
      // 		        auto lambda = [=]() -> void {
      // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
      // 		            JS::RootedValue rval(cx);
      // 		            bool succeed = func->invoke(0, nullptr, &rval);
      // 		            if (!succeed && JS_IsExceptionPending(cx)) {
      // 		                JS_ReportPendingException(cx);
      // 		            }
      // 		        };
      auto lambda = [=]() -> void
      {
        v8::Isolate *isolate = args.GetIsolate();
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Function> funcLocal = func->Get(isolate);
        v8::Local<v8::Object> targetLocal = jstarget;

        v8::TryCatch tryCatch(isolate);
        funcLocal->Call(isolate->GetCurrentContext(), targetLocal, 0, nullptr).ToLocalChecked();
        if (tryCatch.HasCaught())
        {
          v8::String::Utf8Value error(isolate, tryCatch.Exception());
          SE_REPORT_ERROR("Exception occurred while invoking callback: %s", *error ? *error : "unknown");
        }
      };
      cFunc = lambda;
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setOnEnterCallback : Error processing arguments, expected a function");
      return;
    }
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setOnEnterCallback : Error processing arguments");
    //         cobj->setOnEnterCallback(arg0);
    cNode->setOnEnterCallback(cFunc);
    //         args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    //         return true;
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Node_setOnEnterCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_stopActionsByFlags(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_stopActionsByFlags(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopActionsByFlags : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  //         unsigned int arg0 = 0;
  //         ok &= jsval_to_uint32(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_stopActionsByFlags : Error processing arguments");
  //         cobj->stopActionsByFlags(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    unsigned int arg0 = args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    cNode->stopActionsByFlags(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_stopActionsByFlags : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_stopActionsByFlags : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setNormalizedPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setNormalizedPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setNormalizedPosition : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setNormalizedPosition : Error processing arguments");
  //         cobj->setNormalizedPosition(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    if (!JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setNormalizedPosition : Error processing arguments");
      return;
    }
    cNode->setNormalizedPosition(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setNormalizedPosition : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setNormalizedPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setonExitTransitionDidStartCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setonExitTransitionDidStartCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setonExitTransitionDidStartCallback : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");

  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_setonExitTransitionDidStartCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::function<void ()> arg0;
  std::function<void()> cFunc;

  // 		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
  // 		    {
  if (args[0]->IsFunction())
  {
    // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
    v8::Local<v8::Object> jstarget = args.This();
    v8::Local<v8::Function> jsFunc = args[0].As<v8::Function>();
    // TODO: Need to manage the lifecycle of func, otherwise it may be released too early if setonExitTransitionDidStartCallback is called multiple times.
    std::shared_ptr<v8::Global<v8::Function>> func(new v8::Global<v8::Function>(args.GetIsolate(), jsFunc));

    // 		        auto lambda = [=]() -> void {
    // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    // 		            JS::RootedValue rval(cx);
    // 		            bool succeed = func->invoke(0, nullptr, &rval);
    // 		            if (!succeed && JS_IsExceptionPending(cx)) {
    // 		                JS_ReportPendingException(cx);
    // 		            }
    // 		        };
    cFunc = [=]() -> void
    {
      v8::Isolate *isolate = args.GetIsolate();
      v8::HandleScope handleScope(isolate);
      v8::Local<v8::Function> funcLocal = func->Get(isolate);
      v8::Local<v8::Object> targetLocal = jstarget;

      v8::TryCatch tryCatch(isolate);
      funcLocal->Call(isolate->GetCurrentContext(), targetLocal, 0, nullptr).ToLocalChecked();
      if (tryCatch.HasCaught())
      {
        v8::String::Utf8Value error(isolate, tryCatch.Exception());
        SE_REPORT_ERROR("Exception occurred while invoking callback: %s", *error ? *error : "unknown");
      }
    };
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_setonExitTransitionDidStartCallback : Error processing arguments, expected a function");
    return;
  }

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setonExitTransitionDidStartCallback : Error processing arguments");
  //         cobj->setonExitTransitionDidStartCallback(arg0);
  cNode->setOnExitTransitionDidStartCallback(cFunc);
  //         args.rval().setUndefined();
  args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
  //         return true;
}

// bool js_cocos2dx_Node_convertTouchToNodeSpace(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_convertTouchToNodeSpace(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_convertTouchToNodeSpace : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_convertTouchToNodeSpace : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }

  //         cocos2d::Touch* arg0 = nullptr;
  cocos2d::Touch *cTouch = nullptr;
  if (args[0]->IsNull())
  {
    cTouch = nullptr;
  }
  else if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    cTouch = static_cast<cocos2d::Touch *>(tmpObj->GetAlignedPointerFromInternalField(0));

    SE_PRECONDITION2(cTouch, "Invalid Native Object");
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_convertTouchToNodeSpace : Error processing arguments");
    return;
  }

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_convertTouchToNodeSpace : Error processing arguments");
  //         cocos2d::Vec2 ret = cobj->convertTouchToNodeSpace(arg0);
  cocos2d::Vec2 ret = cNode->convertTouchToNodeSpace(cTouch);
  //         JS::RootedValue jsret(cx);
  v8::Isolate *isolate = args.GetIsolate();
  v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(isolate, ret);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
}

// bool js_cocos2dx_Node_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeAllChildrenWithCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeAllChildrenWithCleanup : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  if (args.Length() == 1)
  {
    bool cCleanup = args[0]->BooleanValue(args.GetIsolate());
    cNode->removeAllChildrenWithCleanup(cCleanup);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  if (args.Length() == 0)
  {
    cNode->removeAllChildren();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeAllChildrenWithCleanup : wrong number of arguments");
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Node_removeAllChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getRotationSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getRotationSkewX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotationSkewX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  if (args.Length() == 0)
  {
    double ret = cNode->getRotationSkewX();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Number::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getRotationSkewX : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getRotationSkewX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getRotationSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getRotationSkewY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotationSkewY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getRotationSkewY();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getRotationSkewY();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Number::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getRotationSkewY : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getRotationSkewY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getNodeToWorldTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNodeToWorldTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNodeToWorldTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Mat4 ret = cobj->getNodeToWorldTransform();
  //         JS::RootedValue jsret(cx);
  //         jsret = matrix_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Mat4 ret = cNode->getNodeToWorldTransform();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Array> jsret = JsbUtils::matrix_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNodeToWorldTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Node_getNodeToWorldTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_isCascadeOpacityEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isCascadeOpacityEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isCascadeOpacityEnabled : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isCascadeOpacityEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cNode->isCascadeOpacityEnabled();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Boolean::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_isCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_isCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setParent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setParent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setParent : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() == 1)
  {
    //         cocos2d::Node* arg0 = nullptr;
    cocos2d::Node *cNewParent = nullptr;
    //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
    //             if (!args.get(0).isObject()) { ok = false; break; }
    //             js_proxy_t *jsProxy;
    //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    if (args[0]->IsNull())
    {
      cNewParent = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cNewParent = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cNewParent, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setParent : Error processing arguments");
      return;
    }

    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setParent : Error processing arguments");
    //         cobj->setParent(arg0);
    cNode->setParent(cNewParent);
    //         args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setParent : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setParent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getName : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         const std::string& ret = cobj->getName();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::string &ret = cNode->getName();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = JsbUtils::ToV8String(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getName : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getName : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getRotation3D(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getRotation3D(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotation3D : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Vec3 ret = cobj->getRotation3D();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector3_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Vec3 ret = cNode->getRotation3D();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = JsbUtils::vector3_to_jsval(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getRotation3D : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getRotation3D : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getNodeToParentAffineTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNodeToParentAffineTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNodeToParentAffineTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");

  //         if (argc == 1) {
  if (args.Length() == 1)
  {
    //             cocos2d::Node* arg0 = nullptr;
    cocos2d::Node *cArg0 = nullptr;

    //                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
    //                 if (!args.get(0).isObject()) { ok = false; break; }
    //                 js_proxy_t *jsProxy;
    //                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //                 jsProxy = jsb_get_js_proxy(tmpObj);
    //                 arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
    //                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
    if (args[0]->IsNull())
    {
      cArg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cArg0 = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cArg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_getNodeToParentAffineTransform : Error processing arguments");
      return;
    }

    //             if (!ok) { ok = true; break; }
    //             cocos2d::AffineTransform ret = cobj->getNodeToParentAffineTransform(arg0);
    cocos2d::AffineTransform ret = cNode->getNodeToParentAffineTransform(cArg0);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = ccaffinetransform_to_jsval(cx, ret);
    v8::Local<v8::Object> jsret = JsbUtils::ccaffinetransform_to_jsval(args.GetIsolate(), ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(jsret);
    //             return true;
    return;
  }

  //         if (argc == 0) {
  //             cocos2d::AffineTransform ret = cobj->getNodeToParentAffineTransform();
  //             jsval jsret = JSVAL_NULL;
  //             jsret = ccaffinetransform_to_jsval(cx, ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cocos2d::AffineTransform ret = cNode->getNodeToParentAffineTransform();
    v8::Local<v8::Object> jsret = JsbUtils::ccaffinetransform_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNodeToParentAffineTransform : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getNodeToParentAffineTransform : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 1);
  //     return false;
}

// bool js_cocos2dx_Node_convertTouchToNodeSpaceAR(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_convertTouchToNodeSpaceAR(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_convertTouchToNodeSpaceAR : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() == 1)
  {
    //         cocos2d::Touch* arg0 = nullptr;
    cocos2d::Touch *cTouch = nullptr;

    //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
    //             if (!args.get(0).isObject()) { ok = false; break; }
    //             js_proxy_t *jsProxy;
    //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
    //             jsProxy = jsb_get_js_proxy(tmpObj);
    //             arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
    //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
    if (args[0]->IsNull())
    {
      cTouch = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      cTouch = static_cast<cocos2d::Touch *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(cTouch, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_convertTouchToNodeSpaceAR : Error processing arguments");
      return;
    }
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_convertTouchToNodeSpaceAR : Error processing arguments");
    //         cocos2d::Vec2 ret = cobj->convertTouchToNodeSpaceAR(arg0);
    cocos2d::Vec2 ret = cNode->convertTouchToNodeSpaceAR(cTouch);
    //         JS::RootedValue jsret(cx);
    //         jsret = vector2_to_jsval(cx, ret);
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    //         args.rval().set(jsret);
    args.GetReturnValue().Set(jsret);
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_convertTouchToNodeSpaceAR : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_convertTouchToNodeSpaceAR : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getOnEnterCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getOnEnterCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getOnEnterCallback : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 0) {
  //         const std::function<void ()>& ret = cobj->getOnEnterCallback();
  //         JS::RootedValue jsret(cx);
  //         #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_getOnEnterCallback : Return value is a std::function, which is not supported in JavaScript");
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getOnEnterCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
  SE_REPORT_ERROR("js_cocos2dx_Node_getOnEnterCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_setPositionNormalized(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPositionNormalized(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionNormalized : Invalid Native Object");
  SE_PRECONDITION2(cNode, "Invalid Native Object");
  //     if (argc == 1) {
  if (args.Length() == 1)
  {
    //         cocos2d::Vec2 arg0;
    //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
    cocos2d::Vec2 arg0;
    if (!JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setPositionNormalized : Error processing arguments");
      return;
    }
    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionNormalized : Error processing arguments");
    //         cobj->setPositionNormalized(arg0);
    cNode->setPositionNormalized(arg0);
    //         args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    //         return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setPositionNormalized : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setPositionNormalized : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_isOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isOpacityModifyRGB(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isOpacityModifyRGB : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_isOpacityModifyRGB : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isOpacityModifyRGB();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cNode->isOpacityModifyRGB();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Boolean::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_isOpacityModifyRGB : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_isOpacityModifyRGB : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_stopActionByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_stopActionByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopActionByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_stopActionByTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_stopActionByTag : Error processing arguments");
  //         cobj->stopActionByTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    cNode->stopActionByTag(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_stopActionByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_stopActionByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_reorderChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_reorderChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_reorderChild : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_reorderChild : Invalid Native Object");
  //     if (argc == 2) {

  //     }
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_reorderChild : Function not implemented yet");
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //         cocos2d::Node* arg0 = nullptr;
  cocos2d::Node *cArg0 = nullptr;
  //         int arg1 = 0;
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
  if (args[0]->IsNull())
  {
    cArg0 = nullptr;
  }
  else if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    cArg0 = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

    SE_PRECONDITION2(cArg0, "Invalid Native Object");
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_reorderChild : Error processing arguments");
    return;
  }
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");

  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  int arg1 = args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_reorderChild : Error processing arguments");
  //         cobj->reorderChild(arg0, arg1);
  cNode->reorderChild(cArg0, arg1);
  //         args.rval().setUndefined();
  args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
  //         return true;
}

// bool js_cocos2dx_Node_setSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setSkewY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setSkewY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setSkewY : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setSkewY : Error processing arguments");
  //         cobj->setSkewY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if(args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    cNode->setSkewY(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setSkewY : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setSkewY : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setRotation3D(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotation3D : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec3 arg0;
//         ok &= jsval_to_vector3(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotation3D : Error processing arguments");
//         cobj->setRotation3D(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setRotation3D : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setPositionX(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionX : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionX : Error processing arguments");
//         cobj->setPositionX(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setPositionX : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setNodeToParentTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setNodeToParentTransform : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Mat4 arg0;
//         ok &= jsval_to_matrix(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setNodeToParentTransform : Error processing arguments");
//         cobj->setNodeToParentTransform(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setNodeToParentTransform : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }

// bool js_cocos2dx_Node_getAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getAnchorPoint : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Vec2& ret = cobj->getAnchorPoint();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getNumberOfRunningActions(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNumberOfRunningActions : Invalid Native Object");
//     if (argc == 0) {
//         ssize_t ret = cobj->getNumberOfRunningActions();
//         JS::RootedValue jsret(cx);
//         jsret = ssize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getNumberOfRunningActions : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_updateTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateTransform : Invalid Native Object");
//     if (argc == 0) {
//         cobj->updateTransform();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_updateTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_isVisible(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isVisible : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isVisible();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_isVisible : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getChildrenCount(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getChildrenCount : Invalid Native Object");
//     if (argc == 0) {
//         ssize_t ret = cobj->getChildrenCount();
//         JS::RootedValue jsret(cx);
//         jsret = ssize_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getChildrenCount : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getNodeToParentTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNodeToParentTransform : Invalid Native Object");
//     do {
//         if (argc == 1) {
//             cocos2d::Node* arg0 = nullptr;
//             do {
//                 if (args.get(0).isNull()) { arg0 = nullptr; break; }
//                 if (!args.get(0).isObject()) { ok = false; break; }
//                 js_proxy_t *jsProxy;
//                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//                 jsProxy = jsb_get_js_proxy(tmpObj);
//                 arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
//                 JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//             } while (0);
//             if (!ok) { ok = true; break; }
//             cocos2d::Mat4 ret = cobj->getNodeToParentTransform(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = matrix_to_jsval(cx, ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 0) {
//             const cocos2d::Mat4& ret = cobj->getNodeToParentTransform();
//             jsval jsret = JSVAL_NULL;
//             jsret = matrix_to_jsval(cx, ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_getNodeToParentTransform : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_convertToNodeSpaceAR(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_convertToNodeSpaceAR : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Vec2 arg0;
//         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_convertToNodeSpaceAR : Error processing arguments");
//         cocos2d::Vec2 ret = cobj->convertToNodeSpaceAR(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_convertToNodeSpaceAR : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_addComponent(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_addComponent : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Component* arg0 = nullptr;
//         do {
//             if (args.get(0).isNull()) { arg0 = nullptr; break; }
//             if (!args.get(0).isObject()) { ok = false; break; }
//             js_proxy_t *jsProxy;
//             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//             jsProxy = jsb_get_js_proxy(tmpObj);
//             arg0 = (cocos2d::Component*)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_addComponent : Error processing arguments");
//         bool ret = cobj->addComponent(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_addComponent : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_runAction(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_runAction : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Action* arg0 = nullptr;
//         do {
//             if (args.get(0).isNull()) { arg0 = nullptr; break; }
//             if (!args.get(0).isObject()) { ok = false; break; }
//             js_proxy_t *jsProxy;
//             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//             jsProxy = jsb_get_js_proxy(tmpObj);
//             arg0 = (cocos2d::Action*)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_runAction : Error processing arguments");
//         cocos2d::Action* ret = cobj->runAction(arg0);
//         JS::RootedValue jsret(cx);
//         if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Action>(cx, (cocos2d::Action*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_runAction : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_visit(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_visit : Invalid Native Object");
//     do {
//         if (argc == 0) {
//             cobj->visit();
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
//             unsigned int arg2 = 0;
//             ok &= jsval_to_uint32(cx, args.get(2), &arg2);
//             if (!ok) { ok = true; break; }
//             cobj->visit(arg0, arg1, arg2);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_visit : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_setGLProgram(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setGLProgram : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::GLProgram* arg0 = nullptr;
//         do {
//             if (args.get(0).isNull()) { arg0 = nullptr; break; }
//             if (!args.get(0).isObject()) { ok = false; break; }
//             js_proxy_t *jsProxy;
//             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//             jsProxy = jsb_get_js_proxy(tmpObj);
//             arg0 = (cocos2d::GLProgram*)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setGLProgram : Error processing arguments");
//         cobj->setGLProgram(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setGLProgram : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_getRotation(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotation : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getRotation();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getRotation : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getPhysicsBody(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPhysicsBody : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::PhysicsBody* ret = cobj->getPhysicsBody();
//         JS::RootedValue jsret(cx);
//         if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::PhysicsBody>(cx, (cocos2d::PhysicsBody*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getPhysicsBody : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getAnchorPointInPoints(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getAnchorPointInPoints : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Vec2& ret = cobj->getAnchorPointInPoints();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getAnchorPointInPoints : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getRotationQuat(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotationQuat : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::Quaternion ret = cobj->getRotationQuat();
//         JS::RootedValue jsret(cx);
//         jsret = quaternion_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getRotationQuat : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_removeChildByName(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeChildByName : Invalid Native Object");
//     if (argc == 1) {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByName : Error processing arguments");
//         cobj->removeChildByName(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2) {
//         std::string arg0;
//         bool arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByName : Error processing arguments");
//         cobj->removeChildByName(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_removeChildByName : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setPositionZ(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionZ : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionZ : Error processing arguments");
//         cobj->setPositionZ(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setPositionZ : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }

// bool js_cocos2dx_Node_getGLProgramState(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getGLProgramState : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::GLProgramState* ret = cobj->getGLProgramState();
//         JS::RootedValue jsret(cx);
//         if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::GLProgramState>(cx, (cocos2d::GLProgramState*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getGLProgramState : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_setScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScheduler : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Scheduler* arg0 = nullptr;
//         do {
//             if (args.get(0).isNull()) { arg0 = nullptr; break; }
//             if (!args.get(0).isObject()) { ok = false; break; }
//             js_proxy_t *jsProxy;
//             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
//             jsProxy = jsb_get_js_proxy(tmpObj);
//             arg0 = (cocos2d::Scheduler*)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setScheduler : Error processing arguments");
//         cobj->setScheduler(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setScheduler : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_stopAllActions(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopAllActions : Invalid Native Object");
//     if (argc == 0) {
//         cobj->stopAllActions();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_stopAllActions : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getSkewX : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getSkewX();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getSkewX : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getSkewY : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getSkewY();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getSkewY : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_isScheduled(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isScheduled : Invalid Native Object");
//     if (argc == 1) {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_isScheduled : Error processing arguments");
//         bool ret = cobj->isScheduled(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_isScheduled : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_getDisplayedColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getDisplayedColor : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Color3B& ret = cobj->getDisplayedColor();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor3b_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getDisplayedColor : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getActionByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getActionByTag : Invalid Native Object");
//     if (argc == 1) {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_getActionByTag : Error processing arguments");
//         cocos2d::Action* ret = cobj->getActionByTag(arg0);
//         JS::RootedValue jsret(cx);
//         if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Action>(cx, (cocos2d::Action*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getActionByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setRotationSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotationSkewX : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotationSkewX : Error processing arguments");
//         cobj->setRotationSkewX(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setRotationSkewX : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setRotationSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotationSkewY : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotationSkewY : Error processing arguments");
//         cobj->setRotationSkewY(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setRotationSkewY : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setName(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setName : Invalid Native Object");
//     if (argc == 1) {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setName : Error processing arguments");
//         cobj->setName(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setName : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_update(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_update : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_update : Error processing arguments");
//         cobj->update(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_update : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_getDisplayedOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getDisplayedOpacity : Invalid Native Object");
//     if (argc == 0) {
//         uint16_t ret = cobj->getDisplayedOpacity();
//         JS::RootedValue jsret(cx);
//         jsret = uint32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getDisplayedOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getLocalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getLocalZOrder : Invalid Native Object");
//     if (argc == 0) {
//         int32_t ret = cobj->getLocalZOrder();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getLocalZOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScheduler : Invalid Native Object");
//     do {
//         if (argc == 0) {
//             const cocos2d::Scheduler* ret = cobj->getScheduler();
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scheduler>(cx, (cocos2d::Scheduler*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 0) {
//             cocos2d::Scheduler* ret = cobj->getScheduler();
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scheduler>(cx, (cocos2d::Scheduler*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_getScheduler : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_getPositionNormalized(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionNormalized : Invalid Native Object");
//     if (argc == 0) {
//         const cocos2d::Vec2& ret = cobj->getPositionNormalized();
//         JS::RootedValue jsret(cx);
//         jsret = vector2_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getPositionNormalized : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPosition : Invalid Native Object");
//     do {
//         if (argc == 2) {
//             float* arg0 = 0;
//             #pragma warning NO CONVERSION TO NATIVE FOR float*
// 			ok = false;
//             if (!ok) { ok = true; break; }
//             float* arg1 = 0;
//             #pragma warning NO CONVERSION TO NATIVE FOR float*
// 			ok = false;
//             if (!ok) { ok = true; break; }
//             cobj->getPosition(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 0) {
//             const cocos2d::Vec2& ret = cobj->getPosition();
//             jsval jsret = JSVAL_NULL;
//             jsret = vector2_to_jsval(cx, ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_getPosition : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_isRunning(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isRunning : Invalid Native Object");
//     if (argc == 0) {
//         bool ret = cobj->isRunning();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_isRunning : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getParent(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::Node* cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getParent : Invalid Native Object");
//     do {
//         if (argc == 0) {
//             const cocos2d::Node* ret = cobj->getParent();
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     do {
//         if (argc == 0) {
//             cocos2d::Node* ret = cobj->getParent();
//             jsval jsret = JSVAL_NULL;
//             if (ret) {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)ret));
//         } else {
//             jsret = JSVAL_NULL;
//         };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while(0);

//     JS_ReportError(cx, "js_cocos2dx_Node_getParent : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_Node_getWorldToNodeTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getWorldToNodeTransform : Invalid Native Object");
//     if (argc == 0) {
//         cocos2d::Mat4 ret = cobj->getWorldToNodeTransform();
//         JS::RootedValue jsret(cx);
//         jsret = matrix_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getWorldToNodeTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getPositionY(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionY : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getPositionY();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getPositionY : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_getPositionX(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionX : Invalid Native Object");
//     if (argc == 0) {
//         double ret = cobj->getPositionX();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_getPositionX : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_Node_removeChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeChildByTag : Invalid Native Object");
//     if (argc == 1) {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByTag : Error processing arguments");
//         cobj->removeChildByTag(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2) {
//         int arg0 = 0;
//         bool arg1;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByTag : Error processing arguments");
//         cobj->removeChildByTag(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_removeChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setPositionY(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionY : Invalid Native Object");
//     if (argc == 1) {
//         double arg0 = 0;
//         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionY : Error processing arguments");
//         cobj->setPositionY(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setPositionY : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_updateDisplayedColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateDisplayedColor : Invalid Native Object");
//     if (argc == 1) {
//         cocos2d::Color3B arg0;
//         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_updateDisplayedColor : Error processing arguments");
//         cobj->updateDisplayedColor(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_updateDisplayedColor : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Node_setVisible(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setVisible : Invalid Native Object");
//     if (argc == 1) {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setVisible : Error processing arguments");
//         cobj->setVisible(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Node_setVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }

void js_register_cocos2dx_Node(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
}