#include "JsbParticle.hpp"
#include "JsbUtils.h"
#include "ScriptEngine.hpp"
#include "2d/CCParticleBatchNode.h"
#include "2d/CCParticleSystem.h"
#include "renderer/CCTextureAtlas.h"

// JSClass *jsb_cocos2d_ParticleBatchNode_class;
// JSObject *jsb_cocos2d_ParticleBatchNode_prototype;

// bool js_cocos2dx_ParticleBatchNode_setTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_setTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_setTexture : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_setTexture : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Texture2D *arg0 = nullptr;
  cocos2d::Texture2D *tex = nullptr;

  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  v8::Local<v8::Value> jsTex = args[0];
  if (jsTex->IsNull())
  {
    tex = nullptr;
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTexture : Error processing arguments");
    return;
  }

  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!jsTex->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTexture : Error processing arguments");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  v8::Local<v8::Object> jsObj = jsTex->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  tex = (cocos2d::Texture2D *)jsObj->GetAlignedPointerFromInternalField(0);

  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(tex, "js_cocos2dx_ParticleBatchNode_setTexture : Invalid Native Object");

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_setTexture : Error processing arguments");
  //         cobj->setTexture(arg0);
  cParticle->setTexture(tex);
  //         args.rval().setUndefined();

  //         return true;
}

// bool js_cocos2dx_ParticleBatchNode_initWithTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_initWithTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_initWithTexture : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_initWithTexture : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_initWithTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::Texture2D *arg0 = nullptr;
  cocos2d::Texture2D *tex = nullptr;
  //         int arg1 = 0;
  int capacity = 0;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  v8::Local<v8::Value> jsTex = args[0];
  if (jsTex->IsNull())
  {
    tex = nullptr;
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_initWithTexture : Error processing arguments");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!jsTex->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_initWithTexture : Error processing arguments");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  v8::Local<v8::Object> jsObj = jsTex->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  tex = (cocos2d::Texture2D *)jsObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(tex, "js_cocos2dx_ParticleBatchNode_initWithTexture : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  capacity = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_initWithTexture : Error processing arguments");
  //         bool ret = cobj->initWithTexture(arg0, arg1);
  bool ret = cParticle->initWithTexture(tex, capacity);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_initWithTexture : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_disableParticle(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_disableParticle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_disableParticle : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_disableParticle : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_disableParticle : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int particleIndex = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_disableParticle : Error processing arguments");

  //         cobj->disableParticle(arg0);
  cParticle->disableParticle(particleIndex);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_disableParticle : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_getTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_getTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_getTexture : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_getTexture : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_getTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Texture2D *ret = cobj->getTexture();
  cocos2d::Texture2D *ret = cParticle->getTexture();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };

  if (ret)
  {
    v8::Local<v8::Object> jsObj;
    jsObj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsObj);
    return;
  }
  else
  {
    args.GetReturnValue().Set(v8::Null(isolate));
    return;
  }
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_getTexture : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_setTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_setTextureAtlas(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_setTextureAtlas : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_setTextureAtlas : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTextureAtlas : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::TextureAtlas *arg0 = nullptr;
  cocos2d::TextureAtlas *atlas = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    atlas = nullptr;
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTextureAtlas : Error processing arguments");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setTextureAtlas : Error processing arguments");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::TextureAtlas *)(jsProxy ? jsProxy->ptr : NULL);
  v8::Local<v8::Object> jsObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  atlas = (cocos2d::TextureAtlas *)jsObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(atlas, "js_cocos2dx_ParticleBatchNode_setTextureAtlas : Invalid Native Object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_setTextureAtlas : Error processing arguments");
  //         cobj->setTextureAtlas(arg0);
  cParticle->setTextureAtlas(atlas);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_setTextureAtlas : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_initWithFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_initWithFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_initWithFile : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_initWithFile : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_initWithFile : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         std::string arg0;
  std::string filePath = JsbUtils::FromV8String(isolate, args[0]->ToString(isolate->GetCurrentContext()).ToLocalChecked());
  int capacity = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         int arg1 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_initWithFile : Error processing arguments");
  //         bool ret = cobj->initWithFile(arg0, arg1);
  bool ret = cParticle->initWithFile(filePath, capacity);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_initWithFile : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_setBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_setBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_setBlendFunc : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setBlendFunc : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::BlendFunc arg0;
  cocos2d::BlendFunc blendFunc;
  //         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
  if (!JsbUtils::jsval_to_blendfunc(isolate, args[0], &blendFunc))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_setBlendFunc : Error processing arguments");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_setBlendFunc : Error processing arguments");
  //         cobj->setBlendFunc(arg0);
  cParticle->setBlendFunc(blendFunc);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool cleanup = args[0]->IsTrue();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup : Error processing arguments");
  //         cobj->removeAllChildrenWithCleanup(arg0);
  cParticle->removeAllChildrenWithCleanup(cleanup);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_getTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_getTextureAtlas(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_getTextureAtlas : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_getTextureAtlas : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_getTextureAtlas : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::TextureAtlas *ret = cobj->getTextureAtlas();
  cocos2d::TextureAtlas *ret = cParticle->getTextureAtlas();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::TextureAtlas>(cx, (cocos2d::TextureAtlas *)ret));
  //         }
  if (ret)
  {
    v8::Local<v8::Object> jsObj;
    jsObj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsObj);
    return;
  }
  else
  {
    args.GetReturnValue().SetNull();
    return;
  }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_getTextureAtlas : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_getBlendFunc : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_getBlendFunc : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
  const cocos2d::BlendFunc ret = cParticle->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  v8::Local<v8::Value> jsBlendFunc = JsbUtils::blendfunc_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsBlendFunc);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_insertChild(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_insertChild(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_insertChild : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_insertChild : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_insertChild : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::ParticleSystem *arg0 = nullptr;
  cocos2d::ParticleSystem *particle = nullptr;
  //         int arg1 = 0;
  int index = 0;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    particle = nullptr;
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_insertChild : Error processing arguments");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_insertChild : Error processing arguments");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ParticleSystem *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  v8::Local<v8::Object> jsObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  cocos2d::ParticleSystem *jsProxy = (cocos2d::ParticleSystem *)jsObj->GetAlignedPointerFromInternalField(0);
  //         } while (0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_insertChild : Error processing arguments");
  //         cobj->insertChild(arg0, arg1);
  cParticle->insertChild(jsProxy, index);
  //         args.rval().setUndefined();
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_insertChild : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_removeChildAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_removeChildAtIndex(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleBatchNode *cobj = (cocos2d::ParticleBatchNode *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleBatchNode *cParticle = (cocos2d::ParticleBatchNode *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleBatchNode_removeChildAtIndex : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleBatchNode_removeChildAtIndex : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_removeChildAtIndex : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         int arg0 = 0;
  int index = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         bool arg1;
  bool arg1 = args[1]->IsTrue();
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_removeChildAtIndex : Error processing arguments");
  //         cobj->removeChildAtIndex(arg0, arg1);
  cParticle->removeChildAtIndex(index, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_removeChildAtIndex : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_create(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_create : Error processing arguments");

  //         auto ret = cocos2d::ParticleBatchNode::create(arg0);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleBatchNode>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleBatchNode"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  cocos2d::ParticleBatchNode *ret = nullptr;
  if (args.Length() == 1)
  {
    std::string filePath = JsbUtils::FromV8String(isolate, args[0]->ToString(isolate->GetCurrentContext()).ToLocalChecked());
    ret = cocos2d::ParticleBatchNode::create(filePath);
    return;
  }
  //     if (argc == 2)
  //     {
  //         std::string arg0;
  //         int arg1 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_create : Error processing arguments");

  //         auto ret = cocos2d::ParticleBatchNode::create(arg0, arg1);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleBatchNode>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleBatchNode"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  if (args.Length() == 2)
  {
    std::string filePath = JsbUtils::FromV8String(isolate, args[0]->ToString(isolate->GetCurrentContext()).ToLocalChecked());
    int capacity = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
    ret = cocos2d::ParticleBatchNode::create(filePath, capacity);
    return;
  }
  if (!ret)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleBatchNode_create : Error processing arguments");
    return;
  }
  v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(ret);
  args.GetReturnValue().Set(jsObj);
  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_create : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_createWithTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleBatchNode_createWithTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1)
  //     {
  //         cocos2d::Texture2D *arg0 = nullptr;
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
  //             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_createWithTexture : Error processing arguments");

  //         auto ret = cocos2d::ParticleBatchNode::createWithTexture(arg0);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleBatchNode>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleBatchNode"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  //     if (argc == 2)
  //     {
  //         cocos2d::Texture2D *arg0 = nullptr;
  //         int arg1 = 0;
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
  //             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleBatchNode_createWithTexture : Error processing arguments");

  //         auto ret = cocos2d::ParticleBatchNode::createWithTexture(arg0, arg1);
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleBatchNode>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleBatchNode"));
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_ParticleBatchNode_createWithTexture : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ParticleBatchNode_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleBatchNode *cobj = new (std::nothrow) cocos2d::ParticleBatchNode();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleBatchNode>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleBatchNode"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_ParticleBatchNode_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::ParticleBatchNode *nobj = new (std::nothrow) cocos2d::ParticleBatchNode();
//     js_proxy_t *p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ParticleBatchNode");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_ParticleBatchNode(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleBatchNode_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleBatchNode_class->name = "ParticleBatchNode";
//     jsb_cocos2d_ParticleBatchNode_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleBatchNode_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleBatchNode_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleBatchNode_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleBatchNode_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleBatchNode_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleBatchNode_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleBatchNode_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("setTexture", js_cocos2dx_ParticleBatchNode_setTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithTexture", js_cocos2dx_ParticleBatchNode_initWithTexture, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("disableParticle", js_cocos2dx_ParticleBatchNode_disableParticle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTexture", js_cocos2dx_ParticleBatchNode_getTexture, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextureAtlas", js_cocos2dx_ParticleBatchNode_setTextureAtlas, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithFile", js_cocos2dx_ParticleBatchNode_initWithFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendFunc", js_cocos2dx_ParticleBatchNode_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeAllChildrenWithCleanup", js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTextureAtlas", js_cocos2dx_ParticleBatchNode_getTextureAtlas, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBlendFunc", js_cocos2dx_ParticleBatchNode_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("insertChild", js_cocos2dx_ParticleBatchNode_insertChild, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeChildAtIndex", js_cocos2dx_ParticleBatchNode_removeChildAtIndex, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_ParticleBatchNode_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleBatchNode_create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTexture", js_cocos2dx_ParticleBatchNode_createWithTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
//     jsb_cocos2d_ParticleBatchNode_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleBatchNode_class,
//         js_cocos2dx_ParticleBatchNode_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleBatchNode_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleBatchNode"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleBatchNode>(cx, jsb_cocos2d_ParticleBatchNode_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { cc.ParticleBatchNode.extend = cc.Class.extend; })()");
// }

// JSClass *jsb_cocos2d_ParticleData_class;
// JSObject *jsb_cocos2d_ParticleData_prototype;

// bool js_cocos2dx_ParticleData_release(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleData_release(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleData *cobj = (cocos2d::ParticleData *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleData *cParticle = (cocos2d::ParticleData *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleData_release : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleData_release : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->release();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleData_release : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleData_release : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleData_getMaxCount(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleData_getMaxCount(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleData *cobj = (cocos2d::ParticleData *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleData *cParticle = (cocos2d::ParticleData *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleData_getMaxCount : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleData_getMaxCount : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleData_getMaxCount : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         unsigned int ret = cobj->getMaxCount();
  unsigned int ret = cParticle->getMaxCount();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = uint32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleData_getMaxCount : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleData_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleData_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleData *cobj = (cocos2d::ParticleData *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleData *cParticle = (cocos2d::ParticleData *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleData_init : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleData_init : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleData_init : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int length = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleData_init : Error processing arguments");
  //         bool ret = cobj->init(arg0);
  bool ret = cParticle->init(length);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleData_init : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleData_copyParticle(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleData_copyParticle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleData *cobj = (cocos2d::ParticleData *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleData *cParticle = (cocos2d::ParticleData *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleData_copyParticle : Invalid Native Object");
  SE_PRECONDITION2(cParticle, "js_cocos2dx_ParticleData_copyParticle : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleData_copyParticle : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         int arg0 = 0;
  //         int arg1 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int dest = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  int src = args[1]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleData_copyParticle : Error processing arguments");
  //         cobj->copyParticle(arg0, arg1);
  cParticle->copyParticle(dest, src);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleData_copyParticle : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_ParticleData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleData_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  // TODO
  CCASSERT(false, "js_cocos2dx_ParticleData_constructor is not supported");
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::ParticleData *cobj = new (std::nothrow) cocos2d::ParticleData();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleData>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "cocos2d::ParticleData"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  //     return true;
}

// void js_cocos2d_ParticleData_finalize(JSFreeOp *fop, JSObject *obj)
// {
//     CCLOGINFO("jsbindings: finalizing JS object %p (ParticleData)", obj);
//     js_proxy_t *nproxy;
//     js_proxy_t *jsproxy;
//     JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
//     JS::RootedObject jsobj(cx, obj);
//     jsproxy = jsb_get_js_proxy(jsobj);
//     if (jsproxy)
//     {
//         cocos2d::ParticleData *nobj = static_cast<cocos2d::ParticleData *>(jsproxy->ptr);
//         nproxy = jsb_get_native_proxy(jsproxy->ptr);

//         if (nobj)
//         {
//             jsb_remove_proxy(nproxy, jsproxy);
//             JS::RootedValue flagValue(cx);
//             JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
//             if (flagValue.isNullOrUndefined())
//             {
//                 delete nobj;
//             }
//         }
//         else
//             jsb_remove_proxy(nullptr, jsproxy);
//     }
// }
// void js_register_cocos2dx_ParticleData(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleData_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleData_class->name = "ParticleData";
//     jsb_cocos2d_ParticleData_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleData_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleData_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleData_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleData_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleData_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleData_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleData_class->finalize = js_cocos2d_ParticleData_finalize;
//     jsb_cocos2d_ParticleData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("release", js_cocos2dx_ParticleData_release, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getMaxCount", js_cocos2dx_ParticleData_getMaxCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("init", js_cocos2dx_ParticleData_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("copyParticle", js_cocos2dx_ParticleData_copyParticle, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JSFunctionSpec *st_funcs = NULL;

//     jsb_cocos2d_ParticleData_prototype = JS_InitClass(
//         cx, global,
//         JS::NullPtr(),
//         jsb_cocos2d_ParticleData_class,
//         js_cocos2dx_ParticleData_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleData_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleData"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleData>(cx, jsb_cocos2d_ParticleData_class, proto, JS::NullPtr());
// }

// JSClass *jsb_cocos2d_ParticleSystem_class;
// JSObject *jsb_cocos2d_ParticleSystem_prototype;

// bool js_cocos2dx_ParticleSystem_getStartSizeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartSizeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartSizeVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartSizeVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartSizeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getStartSizeVar();
  double ret = cParticleSystem->getStartSizeVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartSizeVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getTexture : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getTexture : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::Texture2D *ret = cobj->getTexture();
  cocos2d::Texture2D *ret = cParticleSystem->getTexture();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));

  //         }
  if (ret)
  {
    auto jsObj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsObj);
  }
  else
  {
    args.GetReturnValue().SetNull();
    return;
  }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getTexture : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_isFull(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isFull(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isFull : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isFull : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isFull();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isFull : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  bool ret = cParticleSystem->isFull();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isFull : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getBatchNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getBatchNode : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getBatchNode : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getBatchNode : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cocos2d::ParticleBatchNode *ret = cobj->getBatchNode();
  cocos2d::ParticleBatchNode *ret = cParticleSystem->getBatchNode();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ParticleBatchNode>(cx, (cocos2d::ParticleBatchNode *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  if (ret)
  {
    auto jsObj = JsbUtils::NativePtrToObject(ret);
    args.GetReturnValue().Set(jsObj);
  }
  else
  {
    args.GetReturnValue().SetNull();
    return;
  }
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getBatchNode : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getStartColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartColor : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartColor : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Color4F &ret = cobj->getStartColor();
  const cocos2d::Color4F &ret = cParticleSystem->getStartColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4f_to_jsval(cx, ret);
  args.GetReturnValue().Set(JsbUtils::cccolor4f_to_jsval(isolate, ret));
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getPositionType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getPositionType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getPositionType : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getPositionType : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getPositionType : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         int ret = (int)cobj->getPositionType();
  int ret = (int)cParticleSystem->getPositionType();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getPositionType : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setPosVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setPosVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setPosVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setPosVar : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setPosVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Vec2 arg0;
  cocos2d::Vec2 pos;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  bool ok = JsbUtils::jsval_to_vector2(isolate, args[0], &pos);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setPosVar : Error processing arguments");
  //         cobj->setPosVar(arg0);
  cParticleSystem->setPosVar(pos);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setPosVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEndSpin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndSpin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndSpin : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndSpin : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndSpin : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getEndSpin();
  double ret = cParticleSystem->getEndSpin();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndSpin : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setRotatePerSecondVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setRotatePerSecondVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setRotatePerSecondVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setRotatePerSecondVar : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setRotatePerSecondVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double rotatePerSecondVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setRotatePerSecondVar : Error processing arguments");
  //         cobj->setRotatePerSecondVar(arg0);
  cParticleSystem->setRotatePerSecondVar(rotatePerSecondVar);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setRotatePerSecondVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setSourcePositionCompatible(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setSourcePositionCompatible(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setSourcePositionCompatible : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setSourcePositionCompatible : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setSourcePositionCompatible : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool compatible = args[0]->BooleanValue(isolate);
  cParticleSystem->setSourcePositionCompatible(compatible);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setSourcePositionCompatible : Error processing arguments");
  //         cobj->setSourcePositionCompatible(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setSourcePositionCompatible : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getStartSpinVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartSpinVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartSpinVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartSpinVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getStartSpinVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartSpinVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getStartSpinVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartSpinVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getRadialAccelVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getRadialAccelVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getRadialAccelVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getRadialAccelVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getRadialAccelVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getRadialAccelVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getRadialAccelVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getRadialAccelVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEndSizeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndSizeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndSizeVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndSizeVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndSizeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getEndSizeVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         double ret = cobj->getEndSizeVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndSizeVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setTangentialAccel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setTangentialAccel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setTangentialAccel : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setTangentialAccel : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTangentialAccel : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double tangentialAccel = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setTangentialAccel : Error processing arguments");
  //         cobj->setTangentialAccel(arg0);
  cParticleSystem->setTangentialAccel(tangentialAccel);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setTangentialAccel : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getRadialAccel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getRadialAccel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getRadialAccel : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getRadialAccel : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getRadialAccel : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getRadialAccel();
  double ret = cParticleSystem->getRadialAccel();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getRadialAccel : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setStartRadius : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartRadius : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartRadius : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double startRadius = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setStartRadius : Error processing arguments");
  //         cobj->setStartRadius(arg0);
  cParticleSystem->setStartRadius(startRadius);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setStartRadius : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setRotatePerSecond(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setRotatePerSecond(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setRotatePerSecond : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setRotatePerSecond : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setRotatePerSecond : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setRotatePerSecond : Error processing arguments");
  double rotatePerSecond = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         cobj->setRotatePerSecond(arg0);
  cParticleSystem->setRotatePerSecond(rotatePerSecond);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setRotatePerSecond : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEndSize : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndSize : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double endSize = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEndSize : Error processing arguments");
  //         cobj->setEndSize(arg0);
  cParticleSystem->setEndSize(endSize);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEndSize : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getGravity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getGravity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getGravity : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getGravity : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getGravity : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Vec2 &ret = cobj->getGravity();
  const cocos2d::Vec2 &ret = cParticleSystem->getGravity();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  auto jsret = JsbUtils::vector2_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getGravity : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_resumeEmissions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_resumeEmissions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_resumeEmissions : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_resumeEmissions : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_resumeEmissions : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->resumeEmissions();
  args.GetReturnValue().SetUndefined();
}

// bool js_cocos2dx_ParticleSystem_getTangentialAccel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getTangentialAccel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getTangentialAccel : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getTangentialAccel : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getTangentialAccel : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getTangentialAccel();
  double ret = cParticleSystem->getTangentialAccel();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getTangentialAccel : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEndRadius : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndRadius : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndRadius : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double endRadius = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEndRadius : Error processing arguments");
  //         cobj->setEndRadius(arg0);
  cParticleSystem->setEndRadius(endRadius);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEndRadius : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getSpeed(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getSpeed(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getSpeed : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getSpeed : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getSpeed : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getSpeed();
  double ret = cParticleSystem->getSpeed();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_pauseEmissions(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_pauseEmissions(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_pauseEmissions : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_pauseEmissions : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_pauseEmissions : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->pauseEmissions();
  args.GetReturnValue().Set(v8::Undefined(isolate));
}

// bool js_cocos2dx_ParticleSystem_getAngle(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getAngle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getAngle : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getAngle : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getAngle : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getAngle();
  double ret = cParticleSystem->getAngle();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEndColor : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndColor : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndColor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Color4F arg0;
  //         ok &= jsval_to_cccolor4f(cx, args.get(0), &arg0);
  cocos2d::Color4F endColor;
  bool ok = JsbUtils::jsval_to_cccolor4f(isolate, args[0], &endColor);
  if (!ok)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndColor : Error processing arguments");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEndColor : Error processing arguments");
  //         cobj->setEndColor(arg0);
  cParticleSystem->setEndColor(endColor);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEndColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartSpin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartSpin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setStartSpin : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartSpin : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartSpin : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double startSpin = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setStartSpin : Error processing arguments");
  //         cobj->setStartSpin(arg0);
  cParticleSystem->setStartSpin(startSpin);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setStartSpin : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setDuration(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setDuration(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setDuration : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setDuration : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setDuration : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double duration = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setDuration : Error processing arguments");
  //         cobj->setDuration(arg0);
  cParticleSystem->setDuration(duration);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setDuration : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_initWithTotalParticles(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_initWithTotalParticles : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_initWithTotalParticles : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_initWithTotalParticles : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int totalParticles = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_initWithTotalParticles : Error processing arguments");
  //         bool ret = cobj->initWithTotalParticles(arg0);
  bool ret = cParticleSystem->initWithTotalParticles(totalParticles);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_initWithTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_addParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_addParticles(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_addParticles : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_addParticles : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_addParticles : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int particles = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_addParticles : Error processing arguments");
  //         cobj->addParticles(arg0);
  cParticleSystem->addParticles(particles);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_addParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setTexture : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setTexture : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Texture2D *arg0 = nullptr;
  cocos2d::Texture2D *texture = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTexture : Error processing arguments, texture is null");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTexture : Error processing arguments, texture is not an object");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  v8::Local<v8::Object> textureObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  cocos2d::Texture2D *texturePtr = (cocos2d::Texture2D *)textureObj->GetAlignedPointerFromInternalField(0);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(texturePtr, "js_cocos2dx_ParticleSystem_setTexture : Invalid Native Object");
  cParticleSystem->setTexture(texturePtr);
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setTexture : Error processing arguments");
  //         cobj->setTexture(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getPosVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getPosVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getPosVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getPosVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getPosVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Vec2 &ret = cobj->getPosVar();
  const cocos2d::Vec2 &ret = cParticleSystem->getPosVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  auto jsret = JsbUtils::vector2_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getPosVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_updateWithNoTime(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_updateWithNoTime(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_updateWithNoTime : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_updateWithNoTime : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->updateWithNoTime();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_updateWithNoTime : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->updateWithNoTime();

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_updateWithNoTime : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_isBlendAdditive(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isBlendAdditive(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isBlendAdditive : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isBlendAdditive : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isBlendAdditive : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isBlendAdditive();
  bool ret = cParticleSystem->isBlendAdditive();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isBlendAdditive : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getSpeedVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getSpeedVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getSpeedVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getSpeedVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getSpeedVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getSpeedVar();
  double ret = cParticleSystem->getSpeedVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getSpeedVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setPositionType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setPositionType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setPositionType : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setPositionType : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setPositionType : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::ParticleSystem::PositionType arg0;
  cocos2d::ParticleSystem::PositionType positionType = (cocos2d::ParticleSystem::PositionType)args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setPositionType : Error processing arguments");
  //         cobj->setPositionType(arg0);
  cParticleSystem->setPositionType(positionType);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setPositionType : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_stopSystem(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_stopSystem(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_stopSystem : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_stopSystem : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_stopSystem : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->stopSystem();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_stopSystem : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getSourcePosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getSourcePosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getSourcePosition : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getSourcePosition : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getSourcePosition : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         const cocos2d::Vec2 &ret = cobj->getSourcePosition();
  const cocos2d::Vec2 &ret = cParticleSystem->getSourcePosition();
  auto jsret = JsbUtils::vector2_to_jsval(isolate, ret);
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getSourcePosition : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setLifeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setLifeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setLifeVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setLifeVar : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setLifeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  float lifeVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setLifeVar : Error processing arguments");
  //         cobj->setLifeVar(arg0);
  cParticleSystem->setLifeVar(lifeVar);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setLifeVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setTotalParticles(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setTotalParticles : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setTotalParticles : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTotalParticles : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         int arg0 = 0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  int totalParticles = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setTotalParticles : Error processing arguments");
  //         cobj->setTotalParticles(arg0);
  cParticleSystem->setTotalParticles(totalParticles);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndColorVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndColorVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEndColorVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndColorVar : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndColorVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::Color4F arg0;
  //         ok &= jsval_to_cccolor4f(cx, args.get(0), &arg0);
  cocos2d::Color4F color;
  if (!JsbUtils::jsval_to_cccolor4f(isolate, args[0], &color))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndColorVar : Error processing arguments, expected Color4F");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEndColorVar : Error processing arguments");
  //         cobj->setEndColorVar(arg0);
  cParticleSystem->setEndColorVar(color);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEndColorVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getAtlasIndex(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getAtlasIndex : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getAtlasIndex : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         int ret = cobj->getAtlasIndex();
  int ret = cParticleSystem->getAtlasIndex();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getAtlasIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getStartSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartSize : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getStartSize();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
}

// bool js_cocos2dx_ParticleSystem_setStartSpinVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartSpinVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartSpinVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartSpinVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double spinVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setStartSpinVar(spinVar);
}

// bool js_cocos2dx_ParticleSystem_resetSystem(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_resetSystem(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_resetSystem : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_resetSystem : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->resetSystem();
}

// bool js_cocos2dx_ParticleSystem_setAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setAtlasIndex(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setAtlasIndex : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setAtlasIndex : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  int atlasIndex = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setAtlasIndex(atlasIndex);
}

// bool js_cocos2dx_ParticleSystem_setTangentialAccelVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setTangentialAccelVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setTangentialAccelVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setTangentialAccelVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double tangentialAccelVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setTangentialAccelVar(tangentialAccelVar);
}

// bool js_cocos2dx_ParticleSystem_setEndRadiusVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndRadiusVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndRadiusVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndRadiusVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double endRadiusVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setEndRadiusVar(endRadiusVar);
}

// bool js_cocos2dx_ParticleSystem_getEndRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndRadius : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndRadius : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndRadius : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getEndRadius();
  double ret = cParticleSystem->getEndRadius();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndRadius : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}
// bool js_cocos2dx_ParticleSystem_isActive(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isActive(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isActive : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isActive : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isActive : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isActive();
  bool ret = cParticleSystem->isActive();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isActive : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setRadialAccelVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setRadialAccelVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setRadialAccelVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setRadialAccelVar : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setRadialAccelVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double radialAccelVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setRadialAccelVar : Error processing arguments");
  //         cobj->setRadialAccelVar(arg0);
  cParticleSystem->setRadialAccelVar(radialAccelVar);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setRadialAccelVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartSize : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartSize : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double startSize = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setStartSize(startSize);
}

// bool js_cocos2dx_ParticleSystem_setSpeed(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setSpeed(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setSpeed : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setSpeed : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double speed = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setSpeed(speed);
}

// bool js_cocos2dx_ParticleSystem_getStartSpin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartSpin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartSpin : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartSpin : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getStartSpin();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
}

// bool js_cocos2dx_ParticleSystem_getResourceFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getResourceFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getResourceFile : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getResourceFile : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  const std::string &ret = cParticleSystem->getResourceFile();
  auto jsret = JsbUtils::ToV8String(isolate, ret);
  args.GetReturnValue().Set(jsret);
}

// bool js_cocos2dx_ParticleSystem_getRotatePerSecond(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getRotatePerSecond(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getRotatePerSecond : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getRotatePerSecond : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  double ret = cParticleSystem->getRotatePerSecond();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
}

// bool js_cocos2dx_ParticleSystem_setEmitterMode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEmitterMode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEmitterMode : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEmitterMode : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEmitterMode : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::ParticleSystem::Mode arg0;
  //         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
  cocos2d::ParticleSystem::Mode mode = static_cast<cocos2d::ParticleSystem::Mode>(args[0]->Int32Value(isolate->GetCurrentContext()).FromJust());
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEmitterMode : Error processing arguments");
  //         cobj->setEmitterMode(arg0);
  cParticleSystem->setEmitterMode(mode);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEmitterMode : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getDuration(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getDuration(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getDuration : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getDuration : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getDuration : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getDuration();
  double ret = cParticleSystem->getDuration();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  args.GetReturnValue().Set(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getDuration : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setSourcePosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setSourcePosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setSourcePosition : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setSourcePosition : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  cocos2d::Vec2 sourcePosition;
  if (!JsbUtils::jsval_to_vector2(isolate, args[0], &sourcePosition))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setSourcePosition : Error processing arguments, expected Vec2");
    return;
  }
  cParticleSystem->setSourcePosition(sourcePosition);
}

// bool js_cocos2dx_ParticleSystem_stop(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_stop(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_stop : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_stop : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_stop : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->stop();
}

// bool js_cocos2dx_ParticleSystem_updateParticleQuads(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_updateParticleQuads(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_updateParticleQuads : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_updateParticleQuads : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->updateParticleQuads();
}

// bool js_cocos2dx_ParticleSystem_getEndSpinVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndSpinVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndSpinVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndSpinVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndSpinVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getEndSpinVar();
  double ret = cParticleSystem->getEndSpinVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndSpinVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setBlendAdditive(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setBlendAdditive(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setBlendAdditive : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setBlendAdditive : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  bool blendAdditive = args[0]->BooleanValue(isolate);
  cParticleSystem->setBlendAdditive(blendAdditive);
}

// bool js_cocos2dx_ParticleSystem_setLife(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setLife(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setLife : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setLife : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double life = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setLife(life);
}

// bool js_cocos2dx_ParticleSystem_setAngleVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setAngleVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setAngleVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setAngleVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setAngleVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double angleVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setAngleVar(angleVar);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setAngleVar : Error processing arguments");
  //         cobj->setAngleVar(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setAngleVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setRotationIsDir(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setRotationIsDir(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setRotationIsDir : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setRotationIsDir : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setRotationIsDir : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  bool rotationIsDir = args[0]->BooleanValue(isolate);
  cParticleSystem->setRotationIsDir(rotationIsDir);
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setRotationIsDir : Error processing arguments");
  //         cobj->setRotationIsDir(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setRotationIsDir : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_start(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_start(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_start : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_start : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_start : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         cobj->start();
  cParticleSystem->start();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_start : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndSizeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndSizeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndSizeVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndSizeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double endSizeVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setEndSizeVar(endSizeVar);
}

// bool js_cocos2dx_ParticleSystem_setAngle(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setAngle(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setAngle : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setAngle : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setAngle : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double angle = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setAngle(angle);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setAngle : Error processing arguments");
  //         cobj->setAngle(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setAngle : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setBatchNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setBatchNode : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setBatchNode : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setBatchNode : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::ParticleBatchNode *arg0 = nullptr;
  cocos2d::ParticleBatchNode *batchNode = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setBatchNode : argument is null, expected ParticleBatchNode");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setBatchNode : argument is not an object, expected ParticleBatchNode");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::ParticleBatchNode *)(jsProxy ? jsProxy->ptr : NULL);
  v8::Local<v8::Object> obj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  cocos2d::ParticleBatchNode *batchNode = (cocos2d::ParticleBatchNode *)obj->GetAlignedPointerFromInternalField(0);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(batchNode, "js_cocos2dx_ParticleSystem_setBatchNode : Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setBatchNode : Error processing arguments");
  //         cobj->setBatchNode(arg0);
  cParticleSystem->setBatchNode(batchNode);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setBatchNode : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getTangentialAccelVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getTangentialAccelVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getTangentialAccelVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getTangentialAccelVar : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getTangentialAccelVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getTangentialAccelVar();
  double ret = cParticleSystem->getTangentialAccelVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getTangentialAccelVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEmitterMode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEmitterMode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEmitterMode : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEmitterMode : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEmitterMode : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         int ret = (int)cobj->getEmitterMode();
  int ret = (int)cParticleSystem->getEmitterMode();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEmitterMode : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndSpinVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndSpinVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEndSpinVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndSpinVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndSpinVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double endSpinVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEndSpinVar : Error processing arguments");
  //         cobj->setEndSpinVar(arg0);
  cParticleSystem->setEndSpinVar(endSpinVar);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEndSpinVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_initWithFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_initWithFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_initWithFile : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_initWithFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_initWithFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_initWithFile : Error processing arguments");
  //         bool ret = cobj->initWithFile(arg0);
  bool ret = cParticleSystem->initWithFile(filename);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_initWithFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getAngleVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getAngleVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getAngleVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getAngleVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getAngleVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getAngleVar();
  double ret = cParticleSystem->getAngleVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getAngleVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setStartColor : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartColor : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartColor : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         cocos2d::Color4F arg0;
  cocos2d::Color4F startColor;
  if (!JsbUtils::jsval_to_cccolor4f(isolate, args[0], &startColor))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartColor : Error processing arguments");
    return;
  }
  //         ok &= jsval_to_cccolor4f(cx, args.get(0), &arg0);
  JsbUtils::jsval_to_cccolor4f(isolate, args[0], &startColor);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setStartColor : Error processing arguments");
  SE_PRECONDITION2(true, "js_cocos2dx_ParticleSystem_setStartColor : Error processing arguments");
  //         cobj->setStartColor(arg0);
  cParticleSystem->setStartColor(startColor);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setStartColor : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getRotatePerSecondVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getRotatePerSecondVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getRotatePerSecondVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getRotatePerSecondVar : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getRotatePerSecondVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getRotatePerSecondVar();
  double ret = cParticleSystem->getRotatePerSecondVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getRotatePerSecondVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEndSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndSize : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndSize : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndSize : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getEndSize();
  double ret = cParticleSystem->getEndSize();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndSize : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getLife(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getLife(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getLife : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getLife : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getLife : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getLife();
  double ret = cParticleSystem->getLife();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
}

// bool js_cocos2dx_ParticleSystem_isPaused(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isPaused(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isPaused : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isPaused : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isPaused : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isPaused();
  bool ret = cParticleSystem->isPaused();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isPaused : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setSpeedVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setSpeedVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setSpeedVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setSpeedVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setSpeedVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double speedVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setSpeedVar : Error processing arguments");
  //         cobj->setSpeedVar(arg0);
  cParticleSystem->setSpeedVar(speedVar);
}

// bool js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool autoRemove = args[0]->BooleanValue(isolate);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : Error processing arguments");
  SE_PRECONDITION2(true, "js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : Error processing arguments");
  //         cobj->setAutoRemoveOnFinish(arg0);
  cParticleSystem->setAutoRemoveOnFinish(autoRemove);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setGravity(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setGravity(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setGravity : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setGravity : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setGravity : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         cocos2d::Vec2 arg0;
  //         ok &= jsval_to_vector2(cx, args.get(0), &arg0);
  cocos2d::Vec2 gravity;
  if (!JsbUtils::jsval_to_vector2(isolate, args[0], &gravity))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setGravity : Error processing arguments");
    return;
  }
  cParticleSystem->setGravity(gravity);
}

// bool js_cocos2dx_ParticleSystem_postStep(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_postStep(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_postStep : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_postStep : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         cobj->postStep();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_postStep : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cParticleSystem->postStep();

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_postStep : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEmissionRate(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEmissionRate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setEmissionRate : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEmissionRate : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEmissionRate : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  double emissionRate = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setEmissionRate : Error processing arguments");
  SE_PRECONDITION2(true, "js_cocos2dx_ParticleSystem_setEmissionRate : Error processing arguments");
  //         cobj->setEmissionRate(arg0);
  cParticleSystem->setEmissionRate(emissionRate);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setEmissionRate : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEndColorVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndColorVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndColorVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndColorVar : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndColorVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         const cocos2d::Color4F &ret = cobj->getEndColorVar();
  const cocos2d::Color4F &ret = cParticleSystem->getEndColorVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4f_to_jsval(cx, ret);
  auto jsret = JsbUtils::cccolor4f_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndColorVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getRotationIsDir(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getRotationIsDir(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getRotationIsDir : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getRotationIsDir : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getRotationIsDir : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->getRotationIsDir();
  const bool ret = cParticleSystem->getRotationIsDir();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getRotationIsDir : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEmissionRate(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEmissionRate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEmissionRate : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEmissionRate : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEmissionRate : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getEmissionRate();
  double ret = cParticleSystem->getEmissionRate();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEmissionRate : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getEndColor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getEndColor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndColor : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getEndColor : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getEndColor : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         const cocos2d::Color4F &ret = cobj->getEndColor();
  const cocos2d::Color4F &ret = cParticleSystem->getEndColor();
  //         JS::RootedValue jsret(cx);
  //         jsret = cccolor4f_to_jsval(cx, ret);
  auto jsret = JsbUtils::cccolor4f_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndColor : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getLifeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getLifeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getLifeVar : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getLifeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         double ret = cobj->getLifeVar();
  double ret = cParticleSystem->getLifeVar();
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getLifeVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartSizeVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartSizeVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartSizeVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartSizeVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double startSizeVar = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setStartSizeVar(startSizeVar);
}

// bool js_cocos2dx_ParticleSystem_getStartRadius(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartRadius(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartRadius : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartRadius : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartRadius : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getStartRadius();
  double ret = cParticleSystem->getStartRadius();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartRadius : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getParticleCount(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getParticleCount(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getParticleCount : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getParticleCount : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getParticleCount : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         unsigned int ret = cobj->getParticleCount();
  unsigned int ret = cParticleSystem->getParticleCount();
  args.GetReturnValue().Set(v8::Integer::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = uint32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getParticleCount : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getStartRadiusVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getStartRadiusVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartRadiusVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getStartRadiusVar : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getStartRadiusVar : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         double ret = cobj->getStartRadiusVar();
  double ret = cParticleSystem->getStartRadiusVar();
  //         JS::RootedValue jsret(cx);
  //         jsret = DOUBLE_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Number::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartRadiusVar : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_getBlendFunc : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_getBlendFunc : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
  const cocos2d::BlendFunc &ret = cParticleSystem->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  auto jsret = JsbUtils::blendfunc_to_jsval(isolate, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setStartColorVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setStartColorVar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setStartColorVar : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setStartColorVar : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartColorVar : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //     if (argc == 1)
  //     {
  //         cocos2d::Color4F arg0;
  //         ok &= jsval_to_cccolor4f(cx, args.get(0), &arg0);
  cocos2d::Color4F startColorVar;
  if (!JsbUtils::jsval_to_cccolor4f(isolate, args[0], &startColorVar))
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setStartColorVar : Error processing arguments");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setStartColorVar : Error processing arguments");
  //         cobj->setStartColorVar(arg0);
  cParticleSystem->setStartColorVar(startColorVar);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setStartColorVar : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_setEndSpin(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setEndSpin(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setEndSpin : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setEndSpin : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double endSpin = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setEndSpin(endSpin);
}

// bool js_cocos2dx_ParticleSystem_setRadialAccel(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_setRadialAccel(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_setRadialAccel : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_setRadialAccel : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  double radialAccel = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  cParticleSystem->setRadialAccel(radialAccel);
}

// bool js_cocos2dx_ParticleSystem_initWithDictionary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_initWithDictionary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::ParticleSystem *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : nullptr);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_initWithDictionary : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_initWithDictionary : Invalid Native Object");
  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::ValueMap arg0;
    //             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
    cocos2d::ValueMap dict;
    if (!JsbUtils::jsval_to_ccvaluemap(isolate, args[0], &dict))
    {
      SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_initWithDictionary : Error processing arguments");
      return;
    }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string path = JsbUtils::FromV8String(isolate, args[1]);
    bool ret = cParticleSystem->initWithDictionary(dict, path);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithDictionary(arg0, arg1);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }
  else if (args.Length() == 1)
  {
    //             cocos2d::ValueMap arg0;
    cocos2d::ValueMap dict;
    if (!JsbUtils::jsval_to_ccvaluemap(isolate, args[0], &dict))
    {
      SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_initWithDictionary : Error processing arguments");
      return;
    }

    //             bool ret = cobj->initWithDictionary(arg0);
    bool ret = cParticleSystem->initWithDictionary(dict);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_initWithDictionary : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_initWithDictionary : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isAutoRemoveOnFinish();
  bool ret = cParticleSystem->isAutoRemoveOnFinish();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_isSourcePositionCompatible(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_ParticleSystem_isSourcePositionCompatible(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
  cocos2d::ParticleSystem *cParticleSystem = (cocos2d::ParticleSystem *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_isSourcePositionCompatible : Invalid Native Object");
  SE_PRECONDITION2(cParticleSystem, "js_cocos2dx_ParticleSystem_isSourcePositionCompatible : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_ParticleSystem_isSourcePositionCompatible : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isSourcePositionCompatible();
  bool ret = cParticleSystem->isSourcePositionCompatible();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_isSourcePositionCompatible : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_ParticleSystem_getTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getTotalParticles : Invalid Native Object");
//     if (argc == 0)
//     {
//         int ret = cobj->getTotalParticles();
//         JS::RootedValue jsret(cx);
//         jsret = int32_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleSystem_setStartRadiusVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setStartRadiusVar : Invalid Native Object");
//     if (argc == 1)
//     {
//         double arg0 = 0;
//         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setStartRadiusVar : Error processing arguments");
//         cobj->setStartRadiusVar(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setStartRadiusVar : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleSystem_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_setBlendFunc : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::BlendFunc arg0;
//         ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_setBlendFunc : Error processing arguments");
//         cobj->setBlendFunc(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleSystem_getEndRadiusVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getEndRadiusVar : Invalid Native Object");
//     if (argc == 0)
//     {
//         double ret = cobj->getEndRadiusVar();
//         JS::RootedValue jsret(cx);
//         jsret = DOUBLE_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getEndRadiusVar : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleSystem_getStartColorVar(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystem *cobj = (cocos2d::ParticleSystem *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystem_getStartColorVar : Invalid Native Object");
//     if (argc == 0)
//     {
//         const cocos2d::Color4F &ret = cobj->getStartColorVar();
//         JS::RootedValue jsret(cx);
//         jsret = cccolor4f_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getStartColorVar : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleSystem_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_create : Error processing arguments");

//         auto ret = cocos2d::ParticleSystem::create(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSystem>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleSystem"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSystem_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystem_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleSystem::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSystem>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleSystem"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSystem_getAllParticleSystems(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         cocos2d::Vector<cocos2d::ParticleSystem *> &ret = cocos2d::ParticleSystem::getAllParticleSystems();
//         jsval jsret = JSVAL_NULL;
//         jsret = ccvector_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSystem_getAllParticleSystems : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSystem_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleSystem *cobj = new (std::nothrow) cocos2d::ParticleSystem();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSystem>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleSystem"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }
// static bool js_cocos2dx_ParticleSystem_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     cocos2d::ParticleSystem *nobj = new (std::nothrow) cocos2d::ParticleSystem();
//     js_proxy_t *p = jsb_new_proxy(nobj, obj);
//     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::ParticleSystem");
//     bool isFound = false;
//     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
//     args.rval().setUndefined();
//     return true;
// }

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_ParticleSystem(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleSystem_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleSystem_class->name = "ParticleSystem";
//     jsb_cocos2d_ParticleSystem_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSystem_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleSystem_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSystem_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleSystem_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleSystem_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleSystem_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleSystem_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("getStartSizeVar", js_cocos2dx_ParticleSystem_getStartSizeVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTexture", js_cocos2dx_ParticleSystem_getTexture, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isFull", js_cocos2dx_ParticleSystem_isFull, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBatchNode", js_cocos2dx_ParticleSystem_getBatchNode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartColor", js_cocos2dx_ParticleSystem_getStartColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getPositionType", js_cocos2dx_ParticleSystem_getPositionType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setPosVar", js_cocos2dx_ParticleSystem_setPosVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndSpin", js_cocos2dx_ParticleSystem_getEndSpin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setRotatePerSecondVar", js_cocos2dx_ParticleSystem_setRotatePerSecondVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSourcePositionCompatible", js_cocos2dx_ParticleSystem_setSourcePositionCompatible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartSpinVar", js_cocos2dx_ParticleSystem_getStartSpinVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRadialAccelVar", js_cocos2dx_ParticleSystem_getRadialAccelVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndSizeVar", js_cocos2dx_ParticleSystem_getEndSizeVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTangentialAccel", js_cocos2dx_ParticleSystem_setTangentialAccel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRadialAccel", js_cocos2dx_ParticleSystem_getRadialAccel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartRadius", js_cocos2dx_ParticleSystem_setStartRadius, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setRotatePerSecond", js_cocos2dx_ParticleSystem_setRotatePerSecond, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndSize", js_cocos2dx_ParticleSystem_setEndSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getGravity", js_cocos2dx_ParticleSystem_getGravity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("resumeEmissions", js_cocos2dx_ParticleSystem_resumeEmissions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTangentialAccel", js_cocos2dx_ParticleSystem_getTangentialAccel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndRadius", js_cocos2dx_ParticleSystem_setEndRadius, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSpeed", js_cocos2dx_ParticleSystem_getSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("pauseEmissions", js_cocos2dx_ParticleSystem_pauseEmissions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getAngle", js_cocos2dx_ParticleSystem_getAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndColor", js_cocos2dx_ParticleSystem_setEndColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartSpin", js_cocos2dx_ParticleSystem_setStartSpin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setDuration", js_cocos2dx_ParticleSystem_setDuration, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithTotalParticles", js_cocos2dx_ParticleSystem_initWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addParticles", js_cocos2dx_ParticleSystem_addParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTexture", js_cocos2dx_ParticleSystem_setTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getPosVar", js_cocos2dx_ParticleSystem_getPosVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("updateWithNoTime", js_cocos2dx_ParticleSystem_updateWithNoTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isBlendAdditive", js_cocos2dx_ParticleSystem_isBlendAdditive, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSpeedVar", js_cocos2dx_ParticleSystem_getSpeedVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setPositionType", js_cocos2dx_ParticleSystem_setPositionType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("stopSystem", js_cocos2dx_ParticleSystem_stopSystem, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSourcePosition", js_cocos2dx_ParticleSystem_getSourcePosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setLifeVar", js_cocos2dx_ParticleSystem_setLifeVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTotalParticles", js_cocos2dx_ParticleSystem_setTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndColorVar", js_cocos2dx_ParticleSystem_setEndColorVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getAtlasIndex", js_cocos2dx_ParticleSystem_getAtlasIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartSize", js_cocos2dx_ParticleSystem_getStartSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartSpinVar", js_cocos2dx_ParticleSystem_setStartSpinVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("resetSystem", js_cocos2dx_ParticleSystem_resetSystem, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setAtlasIndex", js_cocos2dx_ParticleSystem_setAtlasIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTangentialAccelVar", js_cocos2dx_ParticleSystem_setTangentialAccelVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndRadiusVar", js_cocos2dx_ParticleSystem_setEndRadiusVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndRadius", js_cocos2dx_ParticleSystem_getEndRadius, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isActive", js_cocos2dx_ParticleSystem_isActive, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setRadialAccelVar", js_cocos2dx_ParticleSystem_setRadialAccelVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartSize", js_cocos2dx_ParticleSystem_setStartSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSpeed", js_cocos2dx_ParticleSystem_setSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartSpin", js_cocos2dx_ParticleSystem_getStartSpin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getResourceFile", js_cocos2dx_ParticleSystem_getResourceFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRotatePerSecond", js_cocos2dx_ParticleSystem_getRotatePerSecond, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEmitterMode", js_cocos2dx_ParticleSystem_setEmitterMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getDuration", js_cocos2dx_ParticleSystem_getDuration, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSourcePosition", js_cocos2dx_ParticleSystem_setSourcePosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("stop", js_cocos2dx_ParticleSystem_stop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("updateParticleQuads", js_cocos2dx_ParticleSystem_updateParticleQuads, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndSpinVar", js_cocos2dx_ParticleSystem_getEndSpinVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendAdditive", js_cocos2dx_ParticleSystem_setBlendAdditive, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setLife", js_cocos2dx_ParticleSystem_setLife, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setAngleVar", js_cocos2dx_ParticleSystem_setAngleVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setRotationIsDir", js_cocos2dx_ParticleSystem_setRotationIsDir, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("start", js_cocos2dx_ParticleSystem_start, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndSizeVar", js_cocos2dx_ParticleSystem_setEndSizeVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setAngle", js_cocos2dx_ParticleSystem_setAngle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBatchNode", js_cocos2dx_ParticleSystem_setBatchNode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTangentialAccelVar", js_cocos2dx_ParticleSystem_getTangentialAccelVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEmitterMode", js_cocos2dx_ParticleSystem_getEmitterMode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndSpinVar", js_cocos2dx_ParticleSystem_setEndSpinVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithFile", js_cocos2dx_ParticleSystem_initWithFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getAngleVar", js_cocos2dx_ParticleSystem_getAngleVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartColor", js_cocos2dx_ParticleSystem_setStartColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRotatePerSecondVar", js_cocos2dx_ParticleSystem_getRotatePerSecondVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndSize", js_cocos2dx_ParticleSystem_getEndSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLife", js_cocos2dx_ParticleSystem_getLife, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isPaused", js_cocos2dx_ParticleSystem_isPaused, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSpeedVar", js_cocos2dx_ParticleSystem_setSpeedVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setAutoRemoveOnFinish", js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setGravity", js_cocos2dx_ParticleSystem_setGravity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("postStep", js_cocos2dx_ParticleSystem_postStep, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEmissionRate", js_cocos2dx_ParticleSystem_setEmissionRate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndColorVar", js_cocos2dx_ParticleSystem_getEndColorVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getRotationIsDir", js_cocos2dx_ParticleSystem_getRotationIsDir, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEmissionRate", js_cocos2dx_ParticleSystem_getEmissionRate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndColor", js_cocos2dx_ParticleSystem_getEndColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getLifeVar", js_cocos2dx_ParticleSystem_getLifeVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartSizeVar", js_cocos2dx_ParticleSystem_setStartSizeVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartRadius", js_cocos2dx_ParticleSystem_getStartRadius, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getParticleCount", js_cocos2dx_ParticleSystem_getParticleCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartRadiusVar", js_cocos2dx_ParticleSystem_getStartRadiusVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getBlendFunc", js_cocos2dx_ParticleSystem_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartColorVar", js_cocos2dx_ParticleSystem_setStartColorVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setEndSpin", js_cocos2dx_ParticleSystem_setEndSpin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setRadialAccel", js_cocos2dx_ParticleSystem_setRadialAccel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithDictionary", js_cocos2dx_ParticleSystem_initWithDictionary, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isAutoRemoveOnFinish", js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isSourcePositionCompatible", js_cocos2dx_ParticleSystem_isSourcePositionCompatible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getTotalParticles", js_cocos2dx_ParticleSystem_getTotalParticles, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setStartRadiusVar", js_cocos2dx_ParticleSystem_setStartRadiusVar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setBlendFunc", js_cocos2dx_ParticleSystem_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getEndRadiusVar", js_cocos2dx_ParticleSystem_getEndRadiusVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStartColorVar", js_cocos2dx_ParticleSystem_getStartColorVar, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("ctor", js_cocos2dx_ParticleSystem_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleSystem_create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleSystem_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getAllParticleSystems", js_cocos2dx_ParticleSystem_getAllParticleSystems, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
//     jsb_cocos2d_ParticleSystem_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleSystem_class,
//         js_cocos2dx_ParticleSystem_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleSystem_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleSystem"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleSystem>(cx, jsb_cocos2d_ParticleSystem_class, proto, parent_proto);
//     anonEvaluate(cx, global, "(function () { cc.ParticleSystem.extend = cc.Class.extend; })()");
// }

// JSClass *jsb_cocos2d_ParticleSystemQuad_class;
// JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// bool js_cocos2dx_ParticleSystemQuad_setDisplayFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystemQuad *cobj = (cocos2d::ParticleSystemQuad *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystemQuad_setDisplayFrame : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::SpriteFrame *arg0 = nullptr;
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
//             arg0 = (cocos2d::SpriteFrame *)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystemQuad_setDisplayFrame : Error processing arguments");
//         cobj->setDisplayFrame(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystemQuad_setDisplayFrame : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleSystemQuad_setTextureWithRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystemQuad *cobj = (cocos2d::ParticleSystemQuad *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystemQuad_setTextureWithRect : Invalid Native Object");
//     if (argc == 2)
//     {
//         cocos2d::Texture2D *arg0 = nullptr;
//         cocos2d::Rect arg1;
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
//             arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         ok &= jsval_to_ccrect(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystemQuad_setTextureWithRect : Error processing arguments");
//         cobj->setTextureWithRect(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystemQuad_setTextureWithRect : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_ParticleSystemQuad_listenRendererRecreated(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSystemQuad *cobj = (cocos2d::ParticleSystemQuad *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSystemQuad_listenRendererRecreated : Invalid Native Object");
//     if (argc == 1)
//     {
//         cocos2d::EventCustom *arg0 = nullptr;
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
//             arg0 = (cocos2d::EventCustom *)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystemQuad_listenRendererRecreated : Error processing arguments");
//         cobj->listenRendererRecreated(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSystemQuad_listenRendererRecreated : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleSystemQuad_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;

//     do
//     {
//         if (argc == 1)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::ParticleSystemQuad *ret = cocos2d::ParticleSystemQuad::create(arg0);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ParticleSystemQuad>(cx, (cocos2d::ParticleSystemQuad *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 0)
//         {
//             cocos2d::ParticleSystemQuad *ret = cocos2d::ParticleSystemQuad::create();
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ParticleSystemQuad>(cx, (cocos2d::ParticleSystemQuad *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 1)
//         {
//             cocos2d::ValueMap arg0;
//             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cocos2d::ParticleSystemQuad *ret = cocos2d::ParticleSystemQuad::create(arg0);
//             jsval jsret = JSVAL_NULL;
//             if (ret)
//             {
//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::ParticleSystemQuad>(cx, (cocos2d::ParticleSystemQuad *)ret));
//             }
//             else
//             {
//                 jsret = JSVAL_NULL;
//             };
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);
//     JS_ReportError(cx, "js_cocos2dx_ParticleSystemQuad_create : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_ParticleSystemQuad_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSystemQuad_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleSystemQuad::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSystemQuad>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleSystemQuad"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSystemQuad_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSystemQuad_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleSystemQuad *cobj = new (std::nothrow) cocos2d::ParticleSystemQuad();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSystemQuad>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleSystemQuad"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }

// extern JSObject *jsb_cocos2d_ParticleSystem_prototype;

// void js_register_cocos2dx_ParticleSystemQuad(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleSystemQuad_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleSystemQuad_class->name = "ParticleSystem";
//     jsb_cocos2d_ParticleSystemQuad_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSystemQuad_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleSystemQuad_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSystemQuad_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleSystemQuad_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleSystemQuad_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleSystemQuad_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleSystemQuad_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("setDisplayFrame", js_cocos2dx_ParticleSystemQuad_setDisplayFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setTextureWithRect", js_cocos2dx_ParticleSystemQuad_setTextureWithRect, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("listenRendererRecreated", js_cocos2dx_ParticleSystemQuad_listenRendererRecreated, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleSystemQuad_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleSystemQuad_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ParticleSystem_prototype);
//     jsb_cocos2d_ParticleSystemQuad_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleSystemQuad_class,
//         js_cocos2dx_ParticleSystemQuad_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleSystemQuad_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleSystemQuad"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleSystemQuad>(cx, jsb_cocos2d_ParticleSystemQuad_class, proto, parent_proto);
// }

// JSClass *jsb_cocos2d_ParticleFire_class;
// JSObject *jsb_cocos2d_ParticleFire_prototype;

// bool js_cocos2dx_ParticleFire_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         auto ret = cocos2d::ParticleFire::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFire>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleFire"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleFire_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleFire_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleFire_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleFire::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFire>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleFire"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleFire_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleFire_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleFire *cobj = new (std::nothrow) cocos2d::ParticleFire();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFire>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleFire"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }

// extern JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// void js_register_cocos2dx_ParticleFire(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleFire_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleFire_class->name = "ParticleFire";
//     jsb_cocos2d_ParticleFire_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleFire_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleFire_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleFire_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleFire_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleFire_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleFire_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleFire_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleFire_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleFire_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ParticleSystemQuad_prototype);
//     jsb_cocos2d_ParticleFire_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleFire_class,
//         js_cocos2dx_ParticleFire_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleFire_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleFire"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleFire>(cx, jsb_cocos2d_ParticleFire_class, proto, parent_proto);
// }

// JSClass *jsb_cocos2d_ParticleFireworks_class;
// JSObject *jsb_cocos2d_ParticleFireworks_prototype;

// bool js_cocos2dx_ParticleFireworks_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleFireworks *cobj = (cocos2d::ParticleFireworks *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleFireworks_init : Invalid Native Object");
//     if (argc == 0)
//     {
//         bool ret = cobj->init();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleFireworks_init : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleFireworks_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleFireworks *cobj = (cocos2d::ParticleFireworks *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleFireworks_initWithTotalParticles : Invalid Native Object");
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleFireworks_initWithTotalParticles : Error processing arguments");
//         bool ret = cobj->initWithTotalParticles(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleFireworks_initWithTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleFireworks_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         auto ret = cocos2d::ParticleFireworks::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFireworks>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleFireworks"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleFireworks_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleFireworks_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleFireworks_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleFireworks::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFireworks>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleFireworks"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleFireworks_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleFireworks_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleFireworks *cobj = new (std::nothrow) cocos2d::ParticleFireworks();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleFireworks>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleFireworks"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }

// extern JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// void js_register_cocos2dx_ParticleFireworks(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleFireworks_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleFireworks_class->name = "ParticleFireworks";
//     jsb_cocos2d_ParticleFireworks_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleFireworks_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleFireworks_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleFireworks_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleFireworks_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleFireworks_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleFireworks_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleFireworks_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("init", js_cocos2dx_ParticleFireworks_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithTotalParticles", js_cocos2dx_ParticleFireworks_initWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleFireworks_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleFireworks_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ParticleSystemQuad_prototype);
//     jsb_cocos2d_ParticleFireworks_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleFireworks_class,
//         js_cocos2dx_ParticleFireworks_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleFireworks_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleFireworks"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleFireworks>(cx, jsb_cocos2d_ParticleFireworks_class, proto, parent_proto);
// }

// JSClass *jsb_cocos2d_ParticleSun_class;
// JSObject *jsb_cocos2d_ParticleSun_prototype;

// bool js_cocos2dx_ParticleSun_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSun *cobj = (cocos2d::ParticleSun *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSun_init : Invalid Native Object");
//     if (argc == 0)
//     {
//         bool ret = cobj->init();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSun_init : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleSun_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleSun *cobj = (cocos2d::ParticleSun *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleSun_initWithTotalParticles : Invalid Native Object");
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSun_initWithTotalParticles : Error processing arguments");
//         bool ret = cobj->initWithTotalParticles(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleSun_initWithTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleSun_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         auto ret = cocos2d::ParticleSun::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSun>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleSun"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSun_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSun_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleSun_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleSun::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSun>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleSun"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleSun_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleSun_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleSun *cobj = new (std::nothrow) cocos2d::ParticleSun();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleSun>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleSun"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }

// extern JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// void js_register_cocos2dx_ParticleSun(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleSun_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleSun_class->name = "ParticleSun";
//     jsb_cocos2d_ParticleSun_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSun_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleSun_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleSun_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleSun_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleSun_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleSun_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleSun_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("init", js_cocos2dx_ParticleSun_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithTotalParticles", js_cocos2dx_ParticleSun_initWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleSun_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleSun_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ParticleSystemQuad_prototype);
//     jsb_cocos2d_ParticleSun_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleSun_class,
//         js_cocos2dx_ParticleSun_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleSun_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleSun"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleSun>(cx, jsb_cocos2d_ParticleSun_class, proto, parent_proto);
// }

// JSClass *jsb_cocos2d_ParticleGalaxy_class;
// JSObject *jsb_cocos2d_ParticleGalaxy_prototype;

// bool js_cocos2dx_ParticleGalaxy_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleGalaxy *cobj = (cocos2d::ParticleGalaxy *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleGalaxy_init : Invalid Native Object");
//     if (argc == 0)
//     {
//         bool ret = cobj->init();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleGalaxy_init : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_ParticleGalaxy_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::ParticleGalaxy *cobj = (cocos2d::ParticleGalaxy *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_ParticleGalaxy_initWithTotalParticles : Invalid Native Object");
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleGalaxy_initWithTotalParticles : Error processing arguments");
//         bool ret = cobj->initWithTotalParticles(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_ParticleGalaxy_initWithTotalParticles : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_ParticleGalaxy_create(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         auto ret = cocos2d::ParticleGalaxy::create();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleGalaxy>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleGalaxy"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleGalaxy_create : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleGalaxy_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         int arg0 = 0;
//         ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_ParticleGalaxy_createWithTotalParticles : Error processing arguments");

//         auto ret = cocos2d::ParticleGalaxy::createWithTotalParticles(arg0);
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleGalaxy>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "cocos2d::ParticleGalaxy"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_ParticleGalaxy_createWithTotalParticles : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_ParticleGalaxy_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     cocos2d::ParticleGalaxy *cobj = new (std::nothrow) cocos2d::ParticleGalaxy();

//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::ParticleGalaxy>(cobj);

//     // link the native object with the javascript object
//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::ParticleGalaxy"));
//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
//     return true;
// }

// extern JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// void js_register_cocos2dx_ParticleGalaxy(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_ParticleGalaxy_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_ParticleGalaxy_class->name = "ParticleGalaxy";
//     jsb_cocos2d_ParticleGalaxy_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleGalaxy_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_ParticleGalaxy_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_ParticleGalaxy_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_ParticleGalaxy_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_ParticleGalaxy_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_ParticleGalaxy_class->convert = JS_ConvertStub;
//     jsb_cocos2d_ParticleGalaxy_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("init", js_cocos2dx_ParticleGalaxy_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("initWithTotalParticles", js_cocos2dx_ParticleGalaxy_initWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("create", js_cocos2dx_ParticleGalaxy_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createWithTotalParticles", js_cocos2dx_ParticleGalaxy_createWithTotalParticles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     JS::RootedObject parent_proto(cx, jsb_cocos2d_ParticleSystemQuad_prototype);
//     jsb_cocos2d_ParticleGalaxy_prototype = JS_InitClass(
//         cx, global,
//         parent_proto,
//         jsb_cocos2d_ParticleGalaxy_class,
//         js_cocos2dx_ParticleGalaxy_constructor, 0, // constructor
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_ParticleGalaxy_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "ParticleGalaxy"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::ParticleGalaxy>(cx, jsb_cocos2d_ParticleGalaxy_class, proto, parent_proto);
// }
