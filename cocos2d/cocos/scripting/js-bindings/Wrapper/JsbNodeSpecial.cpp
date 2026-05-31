#include "JsbNodeSpecial.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "2d/CCProtectedNode.h"
#include "JsbNode.hpp"
#include "ScriptEngine.hpp"
// JSClass *jsb_cocos2d_ProtectedNode_class;
// JSObject *jsb_cocos2d_ProtectedNode_prototype;

// bool js_cocos2dx_ProtectedNode_addProtectedChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_addProtectedChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::ProtectedNode *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : nullptr);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_addProtectedChild : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_addProtectedChild : Invalid Native Object");
  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             cocos2d::Node *arg0 = nullptr;
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
    if (args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : argument 0 is null");
      return;
    }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : argument 0 is not an object");
      return;
    }
    //                 arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_addProtectedChild : Invalid Native Object");

    //             cobj->addProtectedChild(arg0);
    cNode->addProtectedChild(childNode);
    //             args.rval().setUndefined();
    args.GetReturnValue().Set(v8::Undefined(isolate));
    //             return true;
    return;
    //         }
  }
  else if (args.Length() == 2)
  {
    //             cocos2d::Node *arg0 = nullptr;
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
    if (!args[0]->IsObject() && !args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : argument 0 is not an object");
      return;
    }
    //                 jsProxy = jsb_get_js_proxy(tmpObj);
    //                 arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_addProtectedChild : Invalid Native Object");
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             int arg1 = 0;
    //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
    if (!args[1]->IsInt32())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : argument 1 is not an integer");
      return;
    }
    int zOrder = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->addProtectedChild(arg0, arg1);
    cNode->addProtectedChild(childNode, zOrder);
    //             args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //             return true;
    return;
  }
  else if (args.Length() == 3)
  {
    //             cocos2d::Node *arg0 = nullptr;
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
    if (!args[0]->IsObject() && !args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : argument 0 is not an object");
      return;
    }
    //                 jsProxy = jsb_get_js_proxy(tmpObj);
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_addProtectedChild : Invalid Native Object");
    //                 arg0 = (cocos2d::Node *)(jsProxy ? jsProxy->ptr : NULL);
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             int arg1 = 0;
    //             ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
    int zOrder = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             int arg2 = 0;
    //             ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
    int tag = args[2]->Int32Value(isolate->GetCurrentContext()).FromJust();
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->addProtectedChild(arg0, arg1, arg2);
    cNode->addProtectedChild(childNode, zOrder, tag);
    //             args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //             return true;
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_addProtectedChild : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_addProtectedChild : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_disableCascadeColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_disableCascadeColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_disableCascadeColor : Invalid Native Object");
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_disableCascadeColor : Invalid Native Object");
  //     if (argc == 0)
  if (args.Length() == 0)
  {
    //         cobj->disableCascadeColor();
    cNode->disableCascadeColor();
    //         args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //         return true;
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_disableCascadeColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_disableCascadeColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_removeProtectedChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_removeProtectedChildByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_removeProtectedChildByTag : Invalid Native Object");
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_removeProtectedChildByTag : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ProtectedNode_removeProtectedChildByTag : Error processing arguments");
  //         cobj->removeProtectedChildByTag(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    if (!args[0]->IsInt32())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChildByTag : argument 0 is not an integer");
      return;
    }
    int tag = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cNode->removeProtectedChildByTag(tag);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 2)
  //     {
  //         int arg0 = 0;
  //         bool arg1;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ProtectedNode_removeProtectedChildByTag : Error processing arguments");
  //         cobj->removeProtectedChildByTag(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    if (!args[0]->IsInt32())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChildByTag : argument 0 is not an integer");
      return;
    }
    int tag = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    bool cleanup = args[1]->BooleanValue(isolate);
    cNode->removeProtectedChildByTag(tag, cleanup);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_removeProtectedChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChildByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_reorderProtectedChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_reorderProtectedChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_reorderProtectedChild : Invalid Native Object");
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_reorderProtectedChild : Invalid Native Object");
  if (args.Length() == 2)
  {
    if (!args[0]->IsObject() && !args[0]->IsNull())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_reorderProtectedChild : argument 0 is not an object");
      return;
    }
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_reorderProtectedChild : Invalid Native Object");
    if (!args[1]->IsInt32())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_reorderProtectedChild : argument 1 is not an integer");
      return;
    }
    int zOrder = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cNode->reorderProtectedChild(childNode, zOrder);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_reorderProtectedChild : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_reorderProtectedChild : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup : Invalid Native Object");
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup : Invalid Native Object");
  if (args.Length() == 1)
  {
    bool cleanup = args[0]->BooleanValue(isolate);
    cNode->removeAllProtectedChildrenWithCleanup(cleanup);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_disableCascadeOpacity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_disableCascadeOpacity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_disableCascadeOpacity : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_disableCascadeOpacity : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->disableCascadeOpacity();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->disableCascadeOpacity();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_disableCascadeOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_disableCascadeOpacity : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_sortAllProtectedChildren(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_sortAllProtectedChildren(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_sortAllProtectedChildren : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_sortAllProtectedChildren : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->sortAllProtectedChildren();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->sortAllProtectedChildren();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_sortAllProtectedChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_sortAllProtectedChildren : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_getProtectedChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_getProtectedChildByTag(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_getProtectedChildByTag : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_getProtectedChildByTag : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    if (!args[0]->IsInt32())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_getProtectedChildByTag : argument 0 is not an integer");
      return;
    }
    int tag = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    cocos2d::Node *ret = cNode->getProtectedChildByTag(tag);
    if (ret)
    {
      v8::Local<v8::Object> jsret = v8::Object::New(isolate);
      jsret->SetAlignedPointerInInternalField(0, ret);
      args.GetReturnValue().Set(jsret);
    }
    else
    {
      args.GetReturnValue().Set(v8::Null(isolate));
    }
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ProtectedNode_getProtectedChildByTag : Error processing arguments");
  //         cocos2d::Node *ret = cobj->getProtectedChildByTag(arg0);
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_getProtectedChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_getProtectedChildByTag : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_removeProtectedChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_removeProtectedChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_removeProtectedChild : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_removeProtectedChild : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    if (args[0]->IsNull())
    {
      cNode->removeProtectedChild(nullptr);
      args.GetReturnValue().SetUndefined();
      return;
    }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChild : argument 0 is not an object");
      return;
    }
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_removeProtectedChild : Invalid Native Object");
    cNode->removeProtectedChild(childNode);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     if (argc == 2)
  //     {
  else if (args.Length() == 2)
  {
    if (args[0]->IsNull())
    {
      cNode->removeProtectedChild(nullptr, args[1]->BooleanValue(isolate));
      args.GetReturnValue().SetUndefined();
      return;
    }
    else if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChild : argument 0 is not an object");
      return;
    }
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Node *childNode = (cocos2d::Node *)tmpObj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(childNode, "js_cocos2dx_ProtectedNode_removeProtectedChild : Invalid Native Object");
    bool cleanup = args[1]->BooleanValue(isolate);
    cNode->removeProtectedChild(childNode, cleanup);
    args.GetReturnValue().SetUndefined();
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_removeProtectedChild : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeProtectedChild : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_removeAllProtectedChildren(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_removeAllProtectedChildren(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ProtectedNode *cobj = (cocos2d::ProtectedNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ProtectedNode *cNode = (cocos2d::ProtectedNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ProtectedNode_removeAllProtectedChildren : Invalid Native Object");
  SE_PRECONDITION2(cNode, "js_cocos2dx_ProtectedNode_removeAllProtectedChildren : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->removeAllProtectedChildren();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cNode->removeAllProtectedChildren();
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_removeAllProtectedChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_removeAllProtectedChildren : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {

  //         auto ret = cocos2d::ProtectedNode::create();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ProtectedNode>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ProtectedNode"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 0)
  {
    cocos2d::ProtectedNode *ret = cocos2d::ProtectedNode::create();
    v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(ret);
    args.GetReturnValue().Set(jsret);
    return;
  }
  //     JS_ReportError(cx, "js_cocos2dx_ProtectedNode_create : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_ProtectedNode_create : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
  //     return false;
}

// bool js_cocos2dx_ProtectedNode_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ProtectedNode_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::ProtectedNode *cobj = new (std::nothrow) cocos2d::ProtectedNode();
  cocos2d::ProtectedNode *cNode = new (std::nothrow) cocos2d::ProtectedNode();
  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ProtectedNode>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ProtectedNode"));
  v8::Local<v8::Object> jsret = jsb_ref_autoreleased_create_jsobject(cNode);
  args.GetReturnValue().SetUndefined();
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsret);
  //     return true;
}

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_ProtectedNode(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_ProtectedNode(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_ProtectedNode_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_ProtectedNode_class->name = "ProtectedNode";
  //     jsb_cocos2d_ProtectedNode_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_ProtectedNode_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_ProtectedNode_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_ProtectedNode_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_ProtectedNode_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_ProtectedNode_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_ProtectedNode_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_ProtectedNode_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_constructor);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "ProtectedNode").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(0);
  JsbUtils::RegisterV8Class(typeid(cocos2d::ProtectedNode).name(), &tpl);
  v8::Local<v8::FunctionTemplate> parentPrototype = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::Node).name());
  tpl->Inherit(parentPrototype);
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("addProtectedChild", js_cocos2dx_ProtectedNode_addProtectedChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addProtectedChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_addProtectedChild));
  //         JS_FN("disableCascadeColor", js_cocos2dx_ProtectedNode_disableCascadeColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "disableCascadeColor", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_disableCascadeColor));
  //         JS_FN("removeProtectedChildByTag", js_cocos2dx_ProtectedNode_removeProtectedChildByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeProtectedChildByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_removeProtectedChildByTag));
  //         JS_FN("reorderProtectedChild", js_cocos2dx_ProtectedNode_reorderProtectedChild, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "reorderProtectedChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_reorderProtectedChild));
  //         JS_FN("removeAllProtectedChildrenWithCleanup", js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAllProtectedChildrenWithCleanup", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup));
  //         JS_FN("disableCascadeOpacity", js_cocos2dx_ProtectedNode_disableCascadeOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "disableCascadeOpacity", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_disableCascadeOpacity));
  //         JS_FN("sortAllProtectedChildren", js_cocos2dx_ProtectedNode_sortAllProtectedChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "sortAllProtectedChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_sortAllProtectedChildren));
  //         JS_FN("getProtectedChildByTag", js_cocos2dx_ProtectedNode_getProtectedChildByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getProtectedChildByTag", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_getProtectedChildByTag));
  //         JS_FN("removeProtectedChild", js_cocos2dx_ProtectedNode_removeProtectedChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeProtectedChild", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_removeProtectedChild));
  //         JS_FN("removeAllProtectedChildren", js_cocos2dx_ProtectedNode_removeAllProtectedChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAllProtectedChildren", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_removeAllProtectedChildren));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("create", js_cocos2dx_ProtectedNode_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "create", v8::FunctionTemplate::New(isolate, js_cocos2dx_ProtectedNode_create));
  //         JS_FS_END};

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
  //     jsb_cocos2d_ProtectedNode_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_ProtectedNode_class,
  //         js_cocos2dx_ProtectedNode_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_ProtectedNode_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "ProtectedNode"));
  //     JS_SetProperty(cx, proto, "_className", className);
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::ProtectedNode>(cx, jsb_cocos2d_ProtectedNode_class, proto, parent_proto);
}
