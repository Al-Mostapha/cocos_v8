#include "JsbNode.hpp"
#include "2d/CCNode.h"
#include "2d/CCScene.h"
#include "cocos2d.h"
#include "JsbConfig.h"
#include "renderer/backend/opengl/ProgramGL.h"
#include "JsbCtor.hpp"
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
void js_cocos2dx_Node_removeComponent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cobj = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeComponent : Invalid Native Object");
  SE_PRECONDITION2(cobj, "js_cocos2dx_Node_removeComponent : Invalid Native Object");

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
  if (args.Length() == 1)
  {
    cocos2d::Component *pComponent = nullptr;
    v8::Local<v8::Value> arg0Val = args[0];
    v8::Isolate *isolate = args.GetIsolate();

    if (arg0Val->IsNull() || arg0Val->IsUndefined())
    {
      pComponent = nullptr;
      SE_PRECONDITION2(pComponent, "js_cocos2dx_Node_removeComponent : Invalid Native Object");
      return;
    }
    else if (arg0Val->IsObject())
    {
      v8::Local<v8::Object> tmpObj = arg0Val->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      pComponent = static_cast<cocos2d::Component *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(pComponent, "js_cocos2dx_Node_removeComponent : Invalid Native Object");
      bool ret = cobj->removeComponent(pComponent);
      args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
      return;
    }
    else if (arg0Val->IsString())
    {
      std::string arg0 = JsbUtils::FromV8String(isolate, arg0Val);

      bool ret = cobj->removeComponent(arg0);
      args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
      return;
    }
  }

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
  SE_REPORT_ERROR("js_cocos2dx_Node_removeComponent : wrong number of arguments");
  //     return false;
}

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

    if (ret)
    {
      v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      // jsret = v8::Null(isolate);
      args.GetReturnValue().SetNull();
    }
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
  SE_PRECONDITION2(cobj, "js_cocos2dx_Node_setOnExitCallback : Invalid Native Object");
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
      cFunc = JsbUtils::FromJsFunc(isolate, jsFunc, args.This());

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

    if (ret)
    {
      v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(ret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      // jsret = v8::Null(isolate).As;
      args.GetReturnValue().SetNull();
    }
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

      cFunc = JsbUtils::FromJsFunc(isolate, jsFunc, args.This());
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
void js_cocos2dx_Node_getNodeToWorldAffineTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  CCASSERT(false, "js_cocos2dx_Node_getNodeToWorldAffineTransform : Not supported in v8, please use getNodeToWorldTransform instead");
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
}

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
      jsret = JsbUtils::NativePtrToObject(ret);
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
      v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(ret);
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
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope scope(isolate);
  auto context = isolate->GetCurrentContext();

  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setOnEnterCallback : Invalid Native Object");

  if (args.Length() != 1 || !args[0]->IsFunction())
  {
    SE_REPORT_ERROR("js_cocos2dx_Node_setOnEnterCallback : Error processing arguments, expected a function");
    return;
  }

  //         std::function<void ()> arg0;

  v8::Local<v8::Function> jsFunc = args[0].As<v8::Function>();
  auto func = std::make_shared<v8::Global<v8::Function>>(isolate, jsFunc);
  auto self = std::make_shared<v8::Global<v8::Object>>(isolate, args.This());

  // 		        auto lambda = [=]() -> void {
  // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
  // 		            JS::RootedValue rval(cx);
  // 		            bool succeed = func->invoke(0, nullptr, &rval);
  // 		            if (!succeed && JS_IsExceptionPending(cx)) {
  // 		                JS_ReportPendingException(cx);
  // 		            }
  // 		        };
  auto cFunc = JsbUtils::FromJsFunc(isolate, jsFunc, args.This());

  cNode->setOnEnterCallback(cFunc);
  args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
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
    cFunc = JsbUtils::FromJsFunc(args.GetIsolate(), jsFunc, args.This());
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
  if (args.Length() == 1)
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
void js_cocos2dx_Node_setRotation3D(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotation3D : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setRotation3D : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec3 arg0;
  //         ok &= jsval_to_vector3(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotation3D : Error processing arguments");
  //         cobj->setRotation3D(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec3 arg0;
    if (!JsbUtils::jsval_to_vector3(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setRotation3D : Error processing arguments");
      return;
    }
    cNode->setRotation3D(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setRotation3D : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setRotation3D : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setPositionX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPositionX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setPositionX : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionX : Error processing arguments");
  //         cobj->setPositionX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    cNode->setPositionX(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setPositionX : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setPositionX : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setNodeToParentTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setNodeToParentTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setNodeToParentTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setNodeToParentTransform : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Mat4 arg0;
  //         ok &= jsval_to_matrix(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setNodeToParentTransform : Error processing arguments");
  //         cobj->setNodeToParentTransform(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Mat4 arg0;
    if (!JsbUtils::jsval_to_matrix(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setNodeToParentTransform : Error processing arguments");
      return;
    }
    cNode->setNodeToParentTransform(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setNodeToParentTransform : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setNodeToParentTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getAnchorPoint(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getAnchorPoint : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getAnchorPoint : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getAnchorPoint();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &ret = cNode->getAnchorPoint();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getAnchorPoint : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getNumberOfRunningActions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNumberOfRunningActions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNumberOfRunningActions : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getNumberOfRunningActions : Invalid Native Object");
  //     if (argc == 0) {
  //         ssize_t ret = cobj->getNumberOfRunningActions();
  //         JS::RootedValue jsret(cx);
  //         jsret = ssize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    ssize_t ret = cNode->getNumberOfRunningActions();
    v8::Local<v8::Value> jsret = v8::Integer::New(args.GetIsolate(), static_cast<int32_t>(ret));
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNumberOfRunningActions : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getNumberOfRunningActions : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_updateTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_updateTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_updateTransform : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->updateTransform();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->updateTransform();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_updateTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_isVisible(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isVisible(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isVisible : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_isVisible : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isVisible();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cNode->isVisible();
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Value> jsret = v8::Boolean::New(isolate, ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_isVisible : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getChildrenCount(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getChildrenCount(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getChildrenCount : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getChildrenCount : Invalid Native Object");
  //     if (argc == 0) {
  //         ssize_t ret = cobj->getChildrenCount();
  //         JS::RootedValue jsret(cx);
  //         jsret = ssize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    ssize_t ret = cNode->getChildrenCount();
    v8::Local<v8::Value> jsret = v8::Integer::New(args.GetIsolate(), static_cast<int32_t>(ret));
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getChildrenCount : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getChildrenCount : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getNodeToParentTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNodeToParentTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNodeToParentTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getNodeToParentTransform : Invalid Native Object");

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
  if (args.Length() == 1)
  {
    cocos2d::Node *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Node *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_getNodeToParentTransform : Error processing arguments");
      return;
    }

    cocos2d::Mat4 ret = cNode->getNodeToParentTransform(arg0);
    v8::Local<v8::Value> jsret = JsbUtils::matrix_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //         if (argc == 0) {
  //             const cocos2d::Mat4& ret = cobj->getNodeToParentTransform();
  //             jsval jsret = JSVAL_NULL;
  //             jsret = matrix_to_jsval(cx, ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    const cocos2d::Mat4 &ret = cNode->getNodeToParentTransform();
    v8::Local<v8::Value> jsret = JsbUtils::matrix_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNodeToParentTransform : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getNodeToParentTransform : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 1);
  //     return false;
}

// bool js_cocos2dx_Node_convertToNodeSpaceAR(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_convertToNodeSpaceAR(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_convertToNodeSpaceAR : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_convertToNodeSpaceAR : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    if (!JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_convertToNodeSpaceAR : Error processing arguments");
      return;
    }
    cocos2d::Vec2 ret = cNode->convertToNodeSpaceAR(arg0);
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_convertToNodeSpaceAR : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_convertToNodeSpaceAR : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
  return;
}

// bool js_cocos2dx_Node_addComponent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_addComponent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_addComponent : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_addComponent : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    cocos2d::Component *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Component *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_addComponent : Error processing arguments");
      return;
    }

    bool ret = cNode->addComponent(arg0);
    v8::Local<v8::Value> jsret = v8::Boolean::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_addComponent : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_addComponent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_runAction(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_runAction(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_runAction : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_runAction : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    cocos2d::Action *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Action *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_runAction : Error processing arguments");
      return;
    }

    cocos2d::Action *ret = cNode->runAction(arg0);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_runAction : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  return;
}

// bool js_cocos2dx_Node_visit(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_visit(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_visit : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_visit : Invalid Native Object");

  //         if (argc == 0) {
  //             cobj->visit();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cNode->visit();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

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
  if (args.Length() == 3)
  {
    cocos2d::Renderer *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Renderer *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_visit : Error processing arguments");
      return;
    }

    cocos2d::Mat4 arg1;
    if (!JsbUtils::jsval_to_matrix(args.GetIsolate(), args[1], &arg1))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_visit : Error processing arguments");
      return;
    }

    unsigned int arg2 = args[2]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->visit(arg0, arg1, arg2);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_visit : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_visit : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 3);
  //     return false;
}

// bool js_cocos2dx_Node_setGLProgram(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setGLProgram(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setGLProgram : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setGLProgram : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    cocos2d::backend::ProgramState *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::backend::ProgramState *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setGLProgram : Error processing arguments");
      return;
    }

    cNode->setProgramState(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setGLProgram : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setGLProgram : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getRotation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getRotation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotation : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getRotation : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getRotation();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getRotation();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getRotation : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getRotation : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPhysicsBody(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPhysicsBody(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPhysicsBody : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPhysicsBody : Invalid Native Object");
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
  if (args.Length() == 0)
  {
    cocos2d::PhysicsBody *ret = cNode->getPhysicsBody();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPhysicsBody : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPhysicsBody : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getAnchorPointInPoints(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getAnchorPointInPoints(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getAnchorPointInPoints : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getAnchorPointInPoints : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getAnchorPointInPoints();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &ret = cNode->getAnchorPointInPoints();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getAnchorPointInPoints : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getRotationQuat(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getRotationQuat(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getRotationQuat : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getRotationQuat : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Quaternion ret = cobj->getRotationQuat();
  //         JS::RootedValue jsret(cx);
  //         jsret = quaternion_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  assert(false && "js_cocos2dx_Node_getRotationQuat : not implemented");

  //     JS_ReportError(cx, "js_cocos2dx_Node_getRotationQuat : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Node_removeChildByName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeChildByName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeChildByName : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_removeChildByName : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByName : Error processing arguments");
  //         cobj->removeChildByName(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);

    cNode->removeChildByName(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
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
  if (args.Length() == 2)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
    bool arg1 = args[1]->BooleanValue(args.GetIsolate());

    cNode->removeChildByName(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeChildByName : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_removeChildByName : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_Node_setPositionZ(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPositionZ(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionZ : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setPositionZ : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionZ : Error processing arguments");
  //         cobj->setPositionZ(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setPositionZ(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setPositionZ : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_getGLProgramState(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getGLProgramState(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getGLProgramState : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getGLProgramState : Invalid Native Object");
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
  if (args.Length() == 0)
  {
    cocos2d::backend::ProgramState *ret = cNode->getProgramState();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getGLProgramState : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getGLProgramState : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setScheduler(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScheduler : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setScheduler : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    cocos2d::Scheduler *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Scheduler *>(tmpObj->GetAlignedPointerFromInternalField(0));

      SE_PRECONDITION2(arg0, "js_cocos2dx_Node_setScheduler : Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setScheduler : Error processing arguments");
      return;
    }

    cNode->setScheduler(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setScheduler : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Node_stopAllActions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_stopAllActions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopAllActions : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_stopAllActions : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->stopAllActions();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->stopAllActions();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_stopAllActions : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_stopAllActions : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getSkewX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getSkewX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getSkewX : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getSkewX();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getSkewX();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getSkewX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getSkewY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getSkewY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getSkewY : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getSkewY();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getSkewY();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getSkewY : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getSkewY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_isScheduled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isScheduled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isScheduled : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_isScheduled : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);

    bool ret = cNode->isScheduled(arg0);
    v8::Local<v8::Value> jsret = v8::Boolean::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_isScheduled : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_isScheduled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getDisplayedColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getDisplayedColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getDisplayedColor : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getDisplayedColor : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Color3B& ret = cobj->getDisplayedColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor3b_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Color3B &ret = cNode->getDisplayedColor();
    v8::Local<v8::Value> jsret = JsbUtils::cccolor3b_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getDisplayedColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getActionByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getActionByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getActionByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getActionByTag : Invalid Native Object");
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
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cocos2d::Action *ret = cNode->getActionByTag(arg0);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getActionByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_getActionByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setRotationSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setRotationSkewX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotationSkewX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setRotationSkewX : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotationSkewX : Error processing arguments");
  //         cobj->setRotationSkewX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setRotationSkewX(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setRotationSkewX : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setRotationSkewX : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setRotationSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setRotationSkewY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotationSkewY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setRotationSkewY : Invalid Native Object");
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setRotationSkewY(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setRotationSkewY : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setRotationSkewY : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setName : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setName : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setName : Error processing arguments");
  //         cobj->setName(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);

    cNode->setName(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setName : wrong number of arguments: %d, was expecting %d", args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Node_setName : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Node_update(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_update(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_update : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_update : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_update : Error processing arguments");
  //         cobj->update(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->update(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_update : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_getDisplayedOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getDisplayedOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getDisplayedOpacity : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getDisplayedOpacity : Invalid Native Object");
  //     if (argc == 0) {
  //         uint16_t ret = cobj->getDisplayedOpacity();
  //         JS::RootedValue jsret(cx);
  //         jsret = uint32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    uint16_t ret = cNode->getDisplayedOpacity();
    v8::Local<v8::Value> jsret = v8::Integer::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getDisplayedOpacity : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getLocalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getLocalZOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getLocalZOrder : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getLocalZOrder : Invalid Native Object");
  //     if (argc == 0) {
  //         int32_t ret = cobj->getLocalZOrder();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int32_t ret = cNode->getLocalZOrder();
    v8::Local<v8::Value> jsret = v8::Integer::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getLocalZOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getLocalZOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getScheduler(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScheduler(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScheduler : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getScheduler : Invalid Native Object");

  //         if (argc == 0) {
  //             const cocos2d::Scheduler* ret = cobj->getScheduler();
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Scheduler>(cx, (cocos2d::Scheduler*)ret));
  if (args.Length() == 0)
  {
    cocos2d::Scheduler *ret = cNode->getScheduler();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getScheduler : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getScheduler : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPositionNormalized(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPositionNormalized(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionNormalized : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPositionNormalized : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getPositionNormalized();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &ret = cNode->getPositionNormalized();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPositionNormalized : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPositionNormalized : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPosition : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPosition : Invalid Native Object");

  //         if (argc == 0) {
  //             const cocos2d::Vec2& ret = cobj->getPosition();
  //             jsval jsret = JSVAL_NULL;
  //             jsret = vector2_to_jsval(cx, ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &ret = cNode->getPosition();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPosition : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_isRunning(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isRunning(const v8::FunctionCallbackInfo<v8::Value> &args)
{

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isRunning : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_isRunning : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isRunning();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cNode->isRunning();
    v8::Local<v8::Value> jsret = v8::Boolean::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_isRunning : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_isRunning : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getParent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getParent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getParent : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getParent : Invalid Native Object");

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
  if (args.Length() == 0)
  {
    cocos2d::Node *ret = cNode->getParent();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getParent : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getParent : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getWorldToNodeTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getWorldToNodeTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getWorldToNodeTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getWorldToNodeTransform : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Mat4 ret = cobj->getWorldToNodeTransform();
  //         JS::RootedValue jsret(cx);
  //         jsret = matrix_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Mat4 ret = cNode->getWorldToNodeTransform();
    v8::Local<v8::Value> jsret = JsbUtils::matrix_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getWorldToNodeTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getWorldToNodeTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPositionY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPositionY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPositionY : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getPositionY();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getPositionY();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPositionY : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPositionY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPositionX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPositionX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPositionX : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getPositionX();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getPositionX();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPositionX : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPositionX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_removeChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeChildByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeChildByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_removeChildByTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_removeChildByTag : Error processing arguments");
  //         cobj->removeChildByTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->removeChildByTag(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }
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
  if (args.Length() == 2)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
    bool arg1 = args[1]->BooleanValue(args.GetIsolate());

    cNode->removeChildByTag(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_removeChildByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setPositionY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPositionY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPositionY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setPositionY : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPositionY : Error processing arguments");
  //         cobj->setPositionY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setPositionY(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setPositionY : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setPositionY : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_updateDisplayedColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_updateDisplayedColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateDisplayedColor : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_updateDisplayedColor : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Color3B arg0;
  //         ok &= jsval_to_cccolor3b(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_updateDisplayedColor : Error processing arguments");
  //         cobj->updateDisplayedColor(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Color3B arg0;
    if (!JsbUtils::jsval_to_cccolor3b(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_updateDisplayedColor : Error processing arguments");
      return;
    }
    cNode->updateDisplayedColor(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_updateDisplayedColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_updateDisplayedColor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setVisible(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setVisible(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setVisible : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setVisible : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setVisible : Error processing arguments");
  //         cobj->setVisible(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());

    cNode->setVisible(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setVisible : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getParentToNodeAffineTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getParentToNodeAffineTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getParentToNodeAffineTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getParentToNodeAffineTransform : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::AffineTransform ret = cobj->getParentToNodeAffineTransform();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccaffinetransform_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::AffineTransform ret = cNode->getParentToNodeAffineTransform();
    v8::Local<v8::Value> jsret = JsbUtils::ccaffinetransform_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getParentToNodeAffineTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getParentToNodeAffineTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getPositionZ(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getPositionZ(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getPositionZ : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getPositionZ : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getPositionZ();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getPositionZ();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getPositionZ : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getPositionZ : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setGlobalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setGlobalZOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setGlobalZOrder : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setGlobalZOrder : Invalid Native Object");
  //     if (argc == 1) {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setGlobalZOrder : Error processing arguments");
  //         cobj->setGlobalZOrder(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setGlobalZOrder(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setGlobalZOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setGlobalZOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setScale(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setScale(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setScale : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setScale : Invalid Native Object");

  //         if (argc == 2) {
  //             double arg0 = 0;
  //             ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //             if (!ok) { ok = true; break; }
  //             double arg1 = 0;
  //             ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
  //             if (!ok) { ok = true; break; }
  //             cobj->setScale(arg0, arg1);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 2)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    double arg1 = args[1]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setScale(arg0, arg1);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //         if (argc == 1) {
  //             double arg0 = 0;
  //             ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
  //             if (!ok) { ok = true; break; }
  //             cobj->setScale(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    double arg0 = args[0]->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setScale(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setScale : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_setScale : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getOnExitCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getOnExitCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getOnExitCallback : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getOnExitCallback : Invalid Native Object");
  //     if (argc == 0) {
  //         const std::function<void ()>& ret = cobj->getOnExitCallback();
  //         JS::RootedValue jsret(cx);
  //         #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::function<void()> &ret = cNode->getOnExitCallback();
    v8::Local<v8::Value> jsret;
    // #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getOnExitCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getOnExitCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getChildByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getChildByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getChildByTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_getChildByTag : Error processing arguments");
  //         cocos2d::Node* ret = cobj->getChildByTag(arg0);
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
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cocos2d::Node *ret = cNode->getChildByTag(arg0);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsobj = JsbUtils::NativePtrToObject(ret);
      jsret = jsobj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    };
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_getChildByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getScaleZ(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScaleZ(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScaleZ : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getScaleZ : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getScaleZ();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getScaleZ();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getScaleZ : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_getScaleY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScaleY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScaleY : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getScaleY : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getScaleY();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getScaleY();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getScaleY : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Node_getScaleY : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Node_getScaleX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScaleX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScaleX : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getScaleX : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getScaleX();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getScaleX();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getScaleX : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getScaleX : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setLocalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setLocalZOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setLocalZOrder : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setLocalZOrder : Invalid Native Object");
  //     if (argc == 1) {
  //         int32_t arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setLocalZOrder : Error processing arguments");
  //         cobj->setLocalZOrder(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int32_t arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setLocalZOrder(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setLocalZOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_setCascadeColorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setCascadeColorEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setCascadeColorEnabled : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setCascadeColorEnabled : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setCascadeColorEnabled : Error processing arguments");
  //         cobj->setCascadeColorEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());

    cNode->setCascadeColorEnabled(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setCascadeColorEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_setOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setOpacity : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setOpacity : Invalid Native Object");
  //     if (argc == 1) {
  //         uint16_t arg0;
  //         ok &= jsval_to_uint16(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setOpacity : Error processing arguments");
  //         cobj->setOpacity(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    uint16_t arg0 = args[0]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setOpacity(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_setOpacity : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
}

// bool js_cocos2dx_Node_getComponent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getComponent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getComponent : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getComponent : Invalid Native Object");
  //     if (argc == 1) {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_getComponent : Error processing arguments");
  //         cocos2d::Component* ret = cobj->getComponent(arg0);
  //         JS::RootedValue jsret(cx);
  //         if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Component>(cx, (cocos2d::Component*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);

    cocos2d::Component *ret = cNode->getComponent(arg0);
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsobj = JsbUtils::NativePtrToObject(ret);
      jsret = jsobj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    };
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getComponent : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_getComponent : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getContentSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getContentSize : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getContentSize : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Size& ret = cobj->getContentSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccsize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Size &ret = cNode->getContentSize();
    v8::Local<v8::Value> jsret = JsbUtils::ccsize_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getContentSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_stopAllActionsByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_stopAllActionsByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopAllActionsByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_stopAllActionsByTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_stopAllActionsByTag : Error processing arguments");
  //         cobj->stopAllActionsByTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->stopAllActionsByTag(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_stopAllActionsByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_stopAllActionsByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getBoundingBox(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getBoundingBox(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getBoundingBox : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getBoundingBox : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::Rect ret = cobj->getBoundingBox();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::Rect ret = cNode->getBoundingBox();
    v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getBoundingBox : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getBoundingBox : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_setIgnoreAnchorPointForPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setIgnoreAnchorPointForPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setIgnoreAnchorPointForPosition : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setIgnoreAnchorPointForPosition : Invalid Native Object");
  //     if (argc == 1) {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setIgnoreAnchorPointForPosition : Error processing arguments");
  //         cobj->setIgnoreAnchorPointForPosition(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());

    cNode->setIgnoreAnchorPointForPosition(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setIgnoreAnchorPointForPosition : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setIgnoreAnchorPointForPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setEventDispatcher(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setEventDispatcher(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setEventDispatcher : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setEventDispatcher : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::EventDispatcher* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::EventDispatcher*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setEventDispatcher : Error processing arguments");
  //         cobj->setEventDispatcher(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::EventDispatcher *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::EventDispatcher *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setEventDispatcher : Error processing arguments");
      return;
    }

    cNode->setEventDispatcher(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setEventDispatcher : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setEventDispatcher : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getGlobalZOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getGlobalZOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getGlobalZOrder : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getGlobalZOrder : Invalid Native Object");

  //     if (argc == 0) {
  //         double ret = cobj->getGlobalZOrder();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getGlobalZOrder();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getGlobalZOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getGlobalZOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_draw(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_draw(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_draw : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_draw : Invalid Native Object");

  //         if (argc == 0) {
  //             cobj->draw();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cNode->draw();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

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
  //             cobj->draw(arg0, arg1, arg2);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 3)
  {
    cocos2d::Renderer *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Renderer *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_draw : Error processing arguments");
      return;
    }

    cocos2d::Mat4 arg1;
    if (!JsbUtils::jsval_to_matrix(args.GetIsolate(), args[1], &arg1))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_draw : Error processing arguments");
      return;
    }

    unsigned int arg2 = args[2]->Uint32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->draw(arg0, arg1, arg2);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_draw : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_draw : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 3);
  //     return false;
}

// bool js_cocos2dx_Node_setUserObject(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setUserObject(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setUserObject : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setUserObject : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Ref* arg0 = nullptr;
  //         do {
  //             if (args.get(0).isNull()) { arg0 = nullptr; break; }
  //             if (!args.get(0).isObject()) { ok = false; break; }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Ref*)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setUserObject : Error processing arguments");
  //         cobj->setUserObject(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Ref *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      arg0 = static_cast<cocos2d::Ref *>(tmpObj->GetAlignedPointerFromInternalField(0));
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setUserObject : Error processing arguments");
      return;
    }

    cNode->setUserObject(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setUserObject : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setUserObject : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_enumerateChildren(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_enumerateChildren(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_enumerateChildren : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_enumerateChildren : Invalid Native Object");

  std::string arg0 = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
  std::function<bool(cocos2d::Node *)> arg1;
  v8::Local<v8::Value> func = args[1];
  if (func->IsFunction())
  {
    // 		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    // 		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    v8::Isolate *isolate = args.GetIsolate();

    // ✅ Persistent function
    auto jsGlobalFunc = std::make_shared<v8::Global<v8::Function>>(isolate, func.As<v8::Function>());

    // ✅ Persistent 'this'
    auto self = std::make_shared<v8::Global<v8::Object>>(isolate, args.This());
    // 		        auto lambda = [=](cocos2d::Node* larg0) -> bool {

    // 		        };
    auto lambda = [jsGlobalFunc, self, isolate](cocos2d::Node *larg0) -> bool
    {
      // 		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
      // 		            jsval largv[1];
      // 		            if (larg0) {
      // 		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)larg0));
      // 		        } else {
      // 		            largv[0] = JSVAL_NULL;
      // 		        };
      // 		            JS::RootedValue rval(cx);
      // 		            bool succeed = func->invoke(1, &largv[0], &rval);
      // 		            if (!succeed && JS_IsExceptionPending(cx)) {
      // 		                JS_ReportPendingException(cx);
      // 		            }
      // 		            bool ok = true;
      // 		            bool ret;
      // 		            ret = JS::ToBoolean(rval);
      // 		            JSB_PRECONDITION2(ok, cx, false, "lambda function : Error processing return value with type bool");
      // 		            return ret;
      return false;
    };
    // 		        arg1 = lambda;
    arg1 = lambda;
    assert(false);
  }
  else
  {
    arg1 = nullptr;
  }

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_enumerateChildren : Error processing arguments");
  //         cobj->enumerateChildren(arg0, arg1);
  cNode->enumerateChildren(arg0, arg1);
  //         args.rval().setUndefined();
  args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
  //         return true;
  return;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Node_enumerateChildren : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_Node_enumerateChildren : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_Node_getonExitTransitionDidStartCallback(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getonExitTransitionDidStartCallback(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getonExitTransitionDidStartCallback : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getonExitTransitionDidStartCallback : Invalid Native Object");
  //     if (argc == 0) {
  //         const std::function<void ()>& ret = cobj->getonExitTransitionDidStartCallback();
  //         JS::RootedValue jsret(cx);
  //         #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const std::function<void()> &ret = cNode->getOnExitTransitionDidStartCallback();
    v8::Local<v8::Value> jsret; // TODO: convert std::function to jsval
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getonExitTransitionDidStartCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getonExitTransitionDidStartCallback : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_removeFromParentAndCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_removeFromParentAndCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_removeFromParentAndCleanup : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_removeFromParentAndCleanup : Invalid Native Object");

  //         if (argc == 1) {
  //             bool arg0;
  //             arg0 = JS::ToBoolean(args.get(0));
  //             cobj->removeFromParentAndCleanup(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    bool arg0 = args[0]->BooleanValue(args.GetIsolate());

    cNode->removeFromParentAndCleanup(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     do {
  //         if (argc == 0) {
  //             cobj->removeFromParent();
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while(0);
  if (args.Length() == 0)
  {
    cNode->removeFromParent();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_removeFromParentAndCleanup : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_removeFromParentAndCleanup : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 0, 1);
  //     return false;
}

// bool js_cocos2dx_Node_setPosition3D(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setPosition3D(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setPosition3D : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setPosition3D : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec3 arg0;
  //         ok &= jsval_to_vector3(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setPosition3D : Error processing arguments");
  //         cobj->setPosition3D(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec3 arg0;
    if (!JsbUtils::jsval_to_vector3(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setPosition3D : Error processing arguments");
      return;
    }

    cNode->setPosition3D(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setPosition3D : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setPosition3D : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_getNumberOfRunningActionsByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNumberOfRunningActionsByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNumberOfRunningActionsByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getNumberOfRunningActionsByTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_getNumberOfRunningActionsByTag : Error processing arguments");
  //         ssize_t ret = cobj->getNumberOfRunningActionsByTag(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = ssize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    ssize_t ret = cNode->getNumberOfRunningActionsByTag(arg0);
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), static_cast<double>(ret));
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNumberOfRunningActionsByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_getNumberOfRunningActionsByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_sortAllChildren(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_sortAllChildren(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_sortAllChildren : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_sortAllChildren : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->sortAllChildren();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->sortAllChildren();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_sortAllChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_sortAllChildren : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getWorldToNodeAffineTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getWorldToNodeAffineTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getWorldToNodeAffineTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getWorldToNodeAffineTransform : Invalid Native Object");
  //     if (argc == 0) {
  //         cocos2d::AffineTransform ret = cobj->getWorldToNodeAffineTransform();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccaffinetransform_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::AffineTransform ret = cNode->getWorldToNodeAffineTransform();
    v8::Local<v8::Value> jsret = JsbUtils::ccaffinetransform_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getWorldToNodeAffineTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getWorldToNodeAffineTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getScale(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getScale(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getScale : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getScale : Invalid Native Object");
  //     if (argc == 0) {
  //         double ret = cobj->getScale();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    double ret = cNode->getScale();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getScale : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getScale : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getOpacity : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getOpacity : Invalid Native Object");
  //     if (argc == 0) {
  //         uint16_t ret = cobj->getOpacity();
  //         JS::RootedValue jsret(cx);
  //         jsret = uint32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    uint16_t ret = cNode->getOpacity();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getOpacity : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_updateOrderOfArrival(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_updateOrderOfArrival(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_updateOrderOfArrival : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_updateOrderOfArrival : Invalid Native Object");
  //     if (argc == 0) {
  //         cobj->updateOrderOfArrival();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->updateOrderOfArrival();
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_updateOrderOfArrival : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_updateOrderOfArrival : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getNormalizedPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getNormalizedPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getNormalizedPosition : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getNormalizedPosition : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Vec2& ret = cobj->getNormalizedPosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Vec2 &ret = cNode->getNormalizedPosition();
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getNormalizedPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_Node_getNormalizedPosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getParentToNodeTransform(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getParentToNodeTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getParentToNodeTransform : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getParentToNodeTransform : Invalid Native Object");
  //     if (argc == 0) {
  //         const cocos2d::Mat4& ret = cobj->getParentToNodeTransform();
  //         JS::RootedValue jsret(cx);
  //         jsret = matrix_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    const cocos2d::Mat4 &ret = cNode->getParentToNodeTransform();
    v8::Local<v8::Value> jsret = JsbUtils::matrix_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_getParentToNodeTransform : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_convertToNodeSpace(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_convertToNodeSpace(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_convertToNodeSpace : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_convertToNodeSpace : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_convertToNodeSpace : Error processing arguments");
  //         cocos2d::Vec2 ret = cobj->convertToNodeSpace(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Vec2 arg0;
    if (!JsbUtils::jsval_to_vector2(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_convertToNodeSpace : Error processing arguments");
      return;
    }

    cocos2d::Vec2 ret = cNode->convertToNodeSpace(arg0);
    v8::Local<v8::Value> jsret = JsbUtils::vector2_to_jsval(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_convertToNodeSpace : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_convertToNodeSpace : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_setTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setTag : Invalid Native Object");
  //     if (argc == 1) {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setTag : Error processing arguments");
  //         cobj->setTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    int arg0 = args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();

    cNode->setTag(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_isCascadeColorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_isCascadeColorEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_isCascadeColorEnabled : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_isCascadeColorEnabled : Invalid Native Object");
  //     if (argc == 0) {
  //         bool ret = cobj->isCascadeColorEnabled();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    bool ret = cNode->isCascadeColorEnabled();
    v8::Local<v8::Value> jsret = v8::Boolean::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_isCascadeColorEnabled : wrong number of arguments: %d, was expecting %d", args.Length(), 0);

  //     JS_ReportError(cx, "js_cocos2dx_Node_isCascadeColorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Node_setRotationQuat(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_setRotationQuat(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_setRotationQuat : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_setRotationQuat : Invalid Native Object");
  //     if (argc == 1) {
  //         cocos2d::Quaternion arg0;
  //         ok &= jsval_to_quaternion(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_setRotationQuat : Error processing arguments");
  //         cobj->setRotationQuat(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Quaternion arg0;
    if (!JsbUtils::jsval_to_quaternion(args.GetIsolate(), args[0], &arg0))
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_setRotationQuat : Error processing arguments");
      return;
    }

    cNode->setRotationQuat(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_setRotationQuat : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Node_setRotationQuat : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_Node_stopAction(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_stopAction(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Node* cobj = (cocos2d::Node *)(proxy ? proxy->ptr : NULL);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_stopAction : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_stopAction : Invalid Native Object");
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
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Node_stopAction : Error processing arguments");
  //         cobj->stopAction(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    cocos2d::Action *arg0 = nullptr;
    if (args[0]->IsNull())
    {
      arg0 = nullptr;
    }
    else if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
      // js_proxy_t *jsProxy = jsb_get_js_proxy(tmpObj);
      arg0 = (cocos2d::Action *)tmpObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(arg0, "Invalid Native Object");
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_Node_stopAction : Error processing arguments");
      return;
    }

    cNode->stopAction(arg0);
    args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
    return;
  }

  SE_REPORT_ERROR("js_cocos2dx_Node_stopAction : wrong number of arguments: %d, was expecting %d", args.Length(), 1);

  //     JS_ReportError(cx, "js_cocos2dx_Node_stopAction : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Node_getActionManager(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getActionManager(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     bool ok = true;
  //     cocos2d::Node* cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Node *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Node *cNode = static_cast<cocos2d::Node *>(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_Node_getActionManager : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_Node_getActionManager : Invalid Native Object");

  //         if (argc == 0) {
  //             const cocos2d::ActionManager* ret = cobj->getActionManager();
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ActionManager>(cx, (cocos2d::ActionManager*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cocos2d::ActionManager *ret = cNode->getActionManager();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //         if (argc == 0) {
  //             cocos2d::ActionManager* ret = cobj->getActionManager();
  //             jsval jsret = JSVAL_NULL;
  //             if (ret) {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ActionManager>(cx, (cocos2d::ActionManager*)ret));
  //         } else {
  //             jsret = JSVAL_NULL;
  //         };
  //             args.rval().set(jsret);
  //             return true;
  //         }
  if (args.Length() == 0)
  {
    cocos2d::ActionManager *ret = cNode->getActionManager();
    v8::Local<v8::Value> jsret;
    if (ret)
    {
      v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
      jsret = jsObj;
    }
    else
    {
      jsret = v8::Null(args.GetIsolate());
    }
    args.GetReturnValue().Set(jsret);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Node_getActionManager : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getActionManager : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_getAttachedNodeCount(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_getAttachedNodeCount(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {

  //         int ret = cocos2d::Node::getAttachedNodeCount();
  //         jsval jsret = JSVAL_NULL;
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    int ret = cocos2d::Node::getAttachedNodeCount();
    v8::Local<v8::Value> jsret = v8::Number::New(args.GetIsolate(), ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_Node_getAttachedNodeCount : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Node_getAttachedNodeCount : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_Node_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0) {

  //         auto ret = cocos2d::Node::create();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Node>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::Node"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    auto ret = cocos2d::Node::create();
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  SE_REPORT_ERROR("js_cocos2dx_Node_create : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
}

// bool js_cocos2dx_Node_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::Node* cobj = new (std::nothrow) cocos2d::Node();
  cocos2d::Node *cNode = new (std::nothrow) cocos2d::Node();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Node>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::Node"));
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(cNode);
  args.GetReturnValue().Set(jsobj);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     return true;
  return;
}

// static bool js_cocos2dx_Node_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Node_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::Node *nobj = new (std::nothrow) cocos2d::Node();
  cocos2d::Node *nobj = new (std::nothrow) cocos2d::Node();
  //     js_proxy_t* p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::Node");
  auto jsobj = jsb_ref_create_jsobject(nobj);
  //     bool isFound = false;
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     args.rval().setUndefined();
  args.GetReturnValue().Set(v8::Undefined(args.GetIsolate()));
  //     return true;
}

void js_register_cocos2dx_Node(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  // jsb_cocos2d_Node_class = (JSClass *)calloc(1, sizeof(JSClass));
  // jsb_cocos2d_Node_class->name = "Node";
  // jsb_cocos2d_Node_class->addProperty = JS_PropertyStub;
  // jsb_cocos2d_Node_class->delProperty = JS_DeletePropertyStub;
  // jsb_cocos2d_Node_class->getProperty = JS_PropertyStub;
  // jsb_cocos2d_Node_class->setProperty = JS_StrictPropertyStub;
  // jsb_cocos2d_Node_class->enumerate = JS_EnumerateStub;
  // jsb_cocos2d_Node_class->resolve = JS_ResolveStub;
  // jsb_cocos2d_Node_class->convert = JS_ConvertStub;
  // jsb_cocos2d_Node_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "Node"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  JsbUtils::RegisterV8Class(typeid(cocos2d::Node).name(), &tpl);

  // static JSPropertySpec properties[] = {
  //     JS_PS_END
  // };

  // static JSFunctionSpec funcs[] = {
  //     JS_FN("addChild", js_cocos2dx_Node_addChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "addChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_addChild));
  //     JS_FN("removeComponent", js_cocos2dx_Node_removeComponent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeComponent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeComponent));
  //     JS_FN("setPhysicsBody", js_cocos2dx_Node_setPhysicsBody, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setPhysicsBody", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPhysicsBody));
  //     JS_FN("getShaderProgram", js_cocos2dx_Node_getGLProgram, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getShaderProgram", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getGLProgram));
  //     JS_FN("getDescription", js_cocos2dx_Node_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDescription", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getDescription));
  //     JS_FN("setOpacityModifyRGB", js_cocos2dx_Node_setOpacityModifyRGB, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOpacityModifyRGB", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setOpacityModifyRGB));
  //     JS_FN("setCascadeOpacityEnabled", js_cocos2dx_Node_setCascadeOpacityEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setCascadeOpacityEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setCascadeOpacityEnabled));
  //     JS_FN("getChildren", js_cocos2dx_Node_getChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getChildren));
  //     JS_FN("setOnExitCallback", js_cocos2dx_Node_setOnExitCallback, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOnExitCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setOnExitCallback));
  //     JS_FN("setActionManager", js_cocos2dx_Node_setActionManager, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setActionManager", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setActionManager));
  //     JS_FN("isIgnoreAnchorPointForPosition", js_cocos2dx_Node_isIgnoreAnchorPointForPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isIgnoreAnchorPointForPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isIgnoreAnchorPointForPosition));
  //     JS_FN("getChildByName", js_cocos2dx_Node_getChildByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getChildByName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getChildByName));
  //     JS_FN("updateDisplayedOpacity", js_cocos2dx_Node_updateDisplayedOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "updateDisplayedOpacity", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_updateDisplayedOpacity));
  //     JS_FN("init", js_cocos2dx_Node_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_init));
  //     JS_FN("getCameraMask", js_cocos2dx_Node_getCameraMask, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getCameraMask", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getCameraMask));
  //     JS_FN("setRotation", js_cocos2dx_Node_setRotation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setRotation", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setRotation));
  //     JS_FN("setScaleZ", js_cocos2dx_Node_setScaleZ, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScaleZ", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setScaleZ));
  //     JS_FN("setScaleY", js_cocos2dx_Node_setScaleY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScaleY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setScaleY));
  //     JS_FN("setScaleX", js_cocos2dx_Node_setScaleX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScaleX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setScaleX));
  //     JS_FN("getColor", js_cocos2dx_Node_getColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getColor));
  //     JS_FN("setOnEnterTransitionDidFinishCallback", js_cocos2dx_Node_setOnEnterTransitionDidFinishCallback, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOnEnterTransitionDidFinishCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setonEnterTransitionDidFinishCallback));
  //     JS_FN("removeAllComponents", js_cocos2dx_Node_removeAllComponents, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeAllComponents", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeAllComponents));
  //     JS_FN("_setLocalZOrder", js_cocos2dx_Node__setLocalZOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "_setLocalZOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node__setLocalZOrder));
  //     JS_FN("setCameraMask", js_cocos2dx_Node_setCameraMask, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setCameraMask", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setCameraMask));
  //     JS_FN("getTag", js_cocos2dx_Node_getTag, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getTag));
  //     JS_FN("getonEnterTransitionDidFinishCallback", js_cocos2dx_Node_getonEnterTransitionDidFinishCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getonEnterTransitionDidFinishCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getonEnterTransitionDidFinishCallback));
  //     JS_FN("getNodeToWorldTransform", js_cocos2dx_Node_getNodeToWorldAffineTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNodeToWorldTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNodeToWorldAffineTransform));
  //     JS_FN("getPosition3D", js_cocos2dx_Node_getPosition3D, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPosition3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPosition3D));
  //     JS_FN("removeChild", js_cocos2dx_Node_removeChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeChild));
  //     JS_FN("getScene", js_cocos2dx_Node_getScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScene", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScene));
  //     JS_FN("getEventDispatcher", js_cocos2dx_Node_getEventDispatcher, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getEventDispatcher", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getEventDispatcher));
  //     JS_FN("setSkewX", js_cocos2dx_Node_setSkewX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setSkewX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setSkewX));
  //     JS_FN("setGLProgramState", js_cocos2dx_Node_setGLProgramState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setGLProgramState", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setGLProgramState));
  //     JS_FN("setOnEnterCallback", js_cocos2dx_Node_setOnEnterCallback, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOnEnterCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setOnEnterCallback));
  //     JS_FN("stopActionsByFlags", js_cocos2dx_Node_stopActionsByFlags, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopActionsByFlags", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_stopActionsByFlags));
  //     JS_FN("setNormalizedPosition", js_cocos2dx_Node_setNormalizedPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setNormalizedPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setNormalizedPosition));
  //     JS_FN("setonExitTransitionDidStartCallback", js_cocos2dx_Node_setonExitTransitionDidStartCallback, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setonExitTransitionDidStartCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setonExitTransitionDidStartCallback));
  //     JS_FN("convertTouchToNodeSpace", js_cocos2dx_Node_convertTouchToNodeSpace, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertTouchToNodeSpace", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_convertTouchToNodeSpace));
  //     JS_FN("removeAllChildren", js_cocos2dx_Node_removeAllChildrenWithCleanup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeAllChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeAllChildrenWithCleanup));
  //     JS_FN("getRotationX", js_cocos2dx_Node_getRotationSkewX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRotationX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getRotationSkewX));
  //     JS_FN("getRotationY", js_cocos2dx_Node_getRotationSkewY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRotationY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getRotationSkewY));
  //     JS_FN("getNodeToWorldTransform3D", js_cocos2dx_Node_getNodeToWorldTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNodeToWorldTransform3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNodeToWorldTransform));
  //     JS_FN("isCascadeOpacityEnabled", js_cocos2dx_Node_isCascadeOpacityEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isCascadeOpacityEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isCascadeOpacityEnabled));
  //     JS_FN("setParent", js_cocos2dx_Node_setParent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setParent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setParent));
  //     JS_FN("getName", js_cocos2dx_Node_getName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getName));
  //     JS_FN("getRotation3D", js_cocos2dx_Node_getRotation3D, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRotation3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getRotation3D));
  //     JS_FN("getNodeToParentTransform", js_cocos2dx_Node_getNodeToParentAffineTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNodeToParentTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNodeToParentAffineTransform));
  //     JS_FN("convertTouchToNodeSpaceAR", js_cocos2dx_Node_convertTouchToNodeSpaceAR, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertTouchToNodeSpaceAR", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_convertTouchToNodeSpaceAR));
  //     JS_FN("getOnEnterCallback", js_cocos2dx_Node_getOnEnterCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getOnEnterCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getOnEnterCallback));
  //     JS_FN("setPositionNormalized", js_cocos2dx_Node_setPositionNormalized, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setPositionNormalized", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPositionNormalized));
  //     JS_FN("isOpacityModifyRGB", js_cocos2dx_Node_isOpacityModifyRGB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isOpacityModifyRGB", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isOpacityModifyRGB));
  //     JS_FN("stopActionByTag", js_cocos2dx_Node_stopActionByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopActionByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_stopActionByTag));
  //     JS_FN("reorderChild", js_cocos2dx_Node_reorderChild, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "reorderChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_reorderChild));
  //     JS_FN("setSkewY", js_cocos2dx_Node_setSkewY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setSkewY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setSkewY));
  //     JS_FN("setRotation3D", js_cocos2dx_Node_setRotation3D, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setRotation3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setRotation3D));
  //     JS_FN("setPositionX", js_cocos2dx_Node_setPositionX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setPositionX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPositionX));
  //     JS_FN("setNodeToParentTransform", js_cocos2dx_Node_setNodeToParentTransform, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setNodeToParentTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setNodeToParentTransform));
  //     JS_FN("getAnchorPoint", js_cocos2dx_Node_getAnchorPoint, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getAnchorPoint", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getAnchorPoint));
  //     JS_FN("getNumberOfRunningActions", js_cocos2dx_Node_getNumberOfRunningActions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNumberOfRunningActions", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNumberOfRunningActions));
  //     JS_FN("updateTransform", js_cocos2dx_Node_updateTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "updateTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_updateTransform));
  //     JS_FN("isVisible", js_cocos2dx_Node_isVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isVisible", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isVisible));
  //     JS_FN("getChildrenCount", js_cocos2dx_Node_getChildrenCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getChildrenCount", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getChildrenCount));
  //     JS_FN("getNodeToParentTransform3D", js_cocos2dx_Node_getNodeToParentTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNodeToParentTransform3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNodeToParentTransform));
  //     JS_FN("convertToNodeSpaceAR", js_cocos2dx_Node_convertToNodeSpaceAR, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertToNodeSpaceAR", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_convertToNodeSpaceAR));
  //     JS_FN("addComponent", js_cocos2dx_Node_addComponent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "addComponent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_addComponent));
  //     JS_FN("runAction", js_cocos2dx_Node_runAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "runAction", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_runAction));
  //     JS_FN("visit", js_cocos2dx_Node_visit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "visit", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_visit));
  //     JS_FN("setShaderProgram", js_cocos2dx_Node_setGLProgram, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setShaderProgram", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setGLProgram));
  //     JS_FN("getRotation", js_cocos2dx_Node_getRotation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRotation", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getRotation));
  //     JS_FN("getPhysicsBody", js_cocos2dx_Node_getPhysicsBody, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPhysicsBody", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPhysicsBody));
  //     JS_FN("getAnchorPointInPoints", js_cocos2dx_Node_getAnchorPointInPoints, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getAnchorPointInPoints", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getAnchorPointInPoints));
  //     JS_FN("getRotationQuat", js_cocos2dx_Node_getRotationQuat, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getRotationQuat", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getRotationQuat));
  //     JS_FN("removeChildByName", js_cocos2dx_Node_removeChildByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeChildByName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeChildByName));
  //     JS_FN("setVertexZ", js_cocos2dx_Node_setPositionZ, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setVertexZ", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPositionZ));
  //     JS_FN("getGLProgramState", js_cocos2dx_Node_getGLProgramState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getGLProgramState", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getGLProgramState));
  //     JS_FN("setScheduler", js_cocos2dx_Node_setScheduler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScheduler", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setScheduler));
  //     JS_FN("stopAllActions", js_cocos2dx_Node_stopAllActions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopAllActions", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_stopAllActions));
  //     JS_FN("getSkewX", js_cocos2dx_Node_getSkewX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getSkewX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getSkewX));
  //     JS_FN("getSkewY", js_cocos2dx_Node_getSkewY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getSkewY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getSkewY));
  //     JS_FN("isScheduled", js_cocos2dx_Node_isScheduled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isScheduled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isScheduled));
  //     JS_FN("getDisplayedColor", js_cocos2dx_Node_getDisplayedColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDisplayedColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getDisplayedColor));
  //     JS_FN("getActionByTag", js_cocos2dx_Node_getActionByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getActionByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getActionByTag));
  //     JS_FN("setRotationX", js_cocos2dx_Node_setRotationSkewX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setRotationX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setRotationSkewX));
  //     JS_FN("setRotationY", js_cocos2dx_Node_setRotationSkewY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setRotationY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setRotationSkewY));
  //     JS_FN("setName", js_cocos2dx_Node_setName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setName));
  //     JS_FN("update", js_cocos2dx_Node_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "update", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_update));
  //     JS_FN("getDisplayedOpacity", js_cocos2dx_Node_getDisplayedOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getDisplayedOpacity", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getDisplayedOpacity));
  //     JS_FN("getLocalZOrder", js_cocos2dx_Node_getLocalZOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getLocalZOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getLocalZOrder));
  //     JS_FN("getScheduler", js_cocos2dx_Node_getScheduler, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScheduler", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScheduler));
  //     JS_FN("getPositionNormalized", js_cocos2dx_Node_getPositionNormalized, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPositionNormalized", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPositionNormalized));
  //     JS_FN("getPosition", js_cocos2dx_Node_getPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPosition));
  //     JS_FN("isRunning", js_cocos2dx_Node_isRunning, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isRunning", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isRunning));
  //     JS_FN("getParent", js_cocos2dx_Node_getParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getParent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getParent));
  //     JS_FN("getWorldToNodeTransform3D", js_cocos2dx_Node_getWorldToNodeTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getWorldToNodeTransform3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getWorldToNodeTransform));
  //     JS_FN("getPositionY", js_cocos2dx_Node_getPositionY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPositionY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPositionY));
  //     JS_FN("getPositionX", js_cocos2dx_Node_getPositionX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getPositionX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPositionX));
  //     JS_FN("removeChildByTag", js_cocos2dx_Node_removeChildByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeChildByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeChildByTag));
  //     JS_FN("setPositionY", js_cocos2dx_Node_setPositionY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setPositionY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPositionY));
  //     JS_FN("updateDisplayedColor", js_cocos2dx_Node_updateDisplayedColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "updateDisplayedColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_updateDisplayedColor));
  //     JS_FN("setVisible", js_cocos2dx_Node_setVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setVisible", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setVisible));
  //     JS_FN("getParentToNodeTransform", js_cocos2dx_Node_getParentToNodeAffineTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getParentToNodeTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getParentToNodeAffineTransform));
  //     JS_FN("getVertexZ", js_cocos2dx_Node_getPositionZ, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getVertexZ", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getPositionZ));
  //     JS_FN("setGlobalZOrder", js_cocos2dx_Node_setGlobalZOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setGlobalZOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setGlobalZOrder));
  //     JS_FN("setScale", js_cocos2dx_Node_setScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setScale", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setScale));
  //     JS_FN("getOnExitCallback", js_cocos2dx_Node_getOnExitCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getOnExitCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getOnExitCallback));
  //     JS_FN("getChildByTag", js_cocos2dx_Node_getChildByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getChildByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getChildByTag));
  //     JS_FN("getScaleZ", js_cocos2dx_Node_getScaleZ, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScaleZ", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScaleZ));
  //     JS_FN("getScaleY", js_cocos2dx_Node_getScaleY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScaleY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScaleY));
  //     JS_FN("getScaleX", js_cocos2dx_Node_getScaleX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScaleX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScaleX));
  //     JS_FN("setLocalZOrder", js_cocos2dx_Node_setLocalZOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setLocalZOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setLocalZOrder));
  //     JS_FN("setCascadeColorEnabled", js_cocos2dx_Node_setCascadeColorEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setCascadeColorEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setCascadeColorEnabled));
  //     JS_FN("setOpacity", js_cocos2dx_Node_setOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setOpacity", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setOpacity));
  //     JS_FN("getComponent", js_cocos2dx_Node_getComponent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getComponent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getComponent));
  //     JS_FN("getContentSize", js_cocos2dx_Node_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getContentSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getContentSize));
  //     JS_FN("stopAllActionsByTag", js_cocos2dx_Node_stopAllActionsByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopAllActionsByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_stopAllActionsByTag));
  //     JS_FN("getBoundingBox", js_cocos2dx_Node_getBoundingBox, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getBoundingBox", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getBoundingBox));
  //     JS_FN("setIgnoreAnchorPointForPosition", js_cocos2dx_Node_setIgnoreAnchorPointForPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setIgnoreAnchorPointForPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setIgnoreAnchorPointForPosition));
  //     JS_FN("setEventDispatcher", js_cocos2dx_Node_setEventDispatcher, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setEventDispatcher", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setEventDispatcher));
  //     JS_FN("getGlobalZOrder", js_cocos2dx_Node_getGlobalZOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getGlobalZOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getGlobalZOrder));
  //     JS_FN("draw", js_cocos2dx_Node_draw, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "draw", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_draw));
  //     JS_FN("setUserObject", js_cocos2dx_Node_setUserObject, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setUserObject", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setUserObject));
  //     JS_FN("enumerateChildren", js_cocos2dx_Node_enumerateChildren, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "enumerateChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_enumerateChildren));
  //     JS_FN("getonExitTransitionDidStartCallback", js_cocos2dx_Node_getonExitTransitionDidStartCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getonExitTransitionDidStartCallback", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getonExitTransitionDidStartCallback));
  //     JS_FN("removeFromParent", js_cocos2dx_Node_removeFromParentAndCleanup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "removeFromParent", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_removeFromParentAndCleanup));
  //     JS_FN("setPosition3D", js_cocos2dx_Node_setPosition3D, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setPosition3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setPosition3D));
  //     JS_FN("getNumberOfRunningActionsByTag", js_cocos2dx_Node_getNumberOfRunningActionsByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNumberOfRunningActionsByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNumberOfRunningActionsByTag));
  //     JS_FN("sortAllChildren", js_cocos2dx_Node_sortAllChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "sortAllChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_sortAllChildren));
  //     JS_FN("getWorldToNodeTransform", js_cocos2dx_Node_getWorldToNodeAffineTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getWorldToNodeTransform", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getWorldToNodeAffineTransform));
  //     JS_FN("getScale", js_cocos2dx_Node_getScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getScale", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getScale));
  //     JS_FN("getOpacity", js_cocos2dx_Node_getOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getOpacity", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getOpacity));
  //     JS_FN("updateOrderOfArrival", js_cocos2dx_Node_updateOrderOfArrival, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "updateOrderOfArrival", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_updateOrderOfArrival));
  //     JS_FN("getNormalizedPosition", js_cocos2dx_Node_getNormalizedPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getNormalizedPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getNormalizedPosition));
  //     JS_FN("getParentToNodeTransform3D", js_cocos2dx_Node_getParentToNodeTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getParentToNodeTransform3D", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getParentToNodeTransform));
  //     JS_FN("convertToNodeSpace", js_cocos2dx_Node_convertToNodeSpace, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "convertToNodeSpace", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_convertToNodeSpace));
  //     JS_FN("setTag", js_cocos2dx_Node_setTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setTag));
  //     JS_FN("isCascadeColorEnabled", js_cocos2dx_Node_isCascadeColorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "isCascadeColorEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_isCascadeColorEnabled));
  //     JS_FN("setRotationQuat", js_cocos2dx_Node_setRotationQuat, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "setRotationQuat", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_setRotationQuat));
  //     JS_FN("stopAction", js_cocos2dx_Node_stopAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "stopAction", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_stopAction));
  //     JS_FN("getActionManager", js_cocos2dx_Node_getActionManager, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "getActionManager", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getActionManager));
  //     JS_FN("ctor", js_cocos2dx_Node_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->PrototypeTemplate()->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_ctor));
  //     JS_FS_END
  // };

  // static JSFunctionSpec st_funcs[] = {
  //     JS_FN("create", js_cocos2dx_Node_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_create));
  //     JS_FN("getAttachedNodeCount", js_cocos2dx_Node_getAttachedNodeCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getAttachedNodeCount", v8::FunctionTemplate::New(isolate, js_cocos2dx_Node_getAttachedNodeCount));
  //     JS_FS_END
  // };

  // jsb_cocos2d_Node_prototype = JS_InitClass(
  //     cx, global,
  //     JS::NullPtr(),
  //     jsb_cocos2d_Node_class,
  //     js_cocos2dx_Node_constructor, 0, // constructor
  //     properties,
  //     funcs,
  //     NULL, // no static properties
  //     st_funcs);

  // JS::RootedObject proto(cx, jsb_cocos2d_Node_prototype);
  // JS::RootedValue className(cx, std_string_to_jsval(cx, "Node"));
  // JS_SetProperty(cx, proto, "_className", className);
  // JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "_className", v8::String::NewFromUtf8(isolate, "Node").ToLocalChecked());
  tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
  // JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::True(isolate));
  // // add the proto and JSClass to the type->js info hash table
  // jsb_register_class<cocos2d::Node>(cx, jsb_cocos2d_Node_class, proto, JS::NullPtr());
  // anonEvaluate(cx, global, "(function () { cc.Node.extend = cc.Class.extend; })()");
}
