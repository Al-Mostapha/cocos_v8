#include "JsbSprite.hpp"
#include "JsbCtor.hpp"
#include "JsbUtils.h"
#include "2d/CCSprite.h"
#include "2d/CCSpriteFrame.h"
#include "2d/CCAnimationCache.h"
#include "2d/CCSpriteBatchNode.h"
#include "2d/CCSpriteFrameCache.h"
#include "renderer/CCTexture2D.h"
#include "ScriptEngine.hpp"

// JSClass *jsb_cocos2d_Sprite_class;
// JSObject *jsb_cocos2d_Sprite_prototype;

// bool js_cocos2dx_Sprite_setSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setSpriteFrame(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setSpriteFrame : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setSpriteFrame : Invalid Native Object");
  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setSpriteFrame : wrong number of arguments");
  //     return false;
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setSpriteFrame : wrong number of arguments");
    return;
  }

  v8::Local<v8::Value> arg0 = args[0];
  if (arg0->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setSpriteFrame : argument should be non-null");
    return;
  }
  else if (arg0->IsObject())
  {
    v8::Local<v8::Object> obj = arg0->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::SpriteFrame *spriteFrame = (cocos2d::SpriteFrame *)obj->GetAlignedPointerFromInternalField(0);
    if (!spriteFrame)
    {
      SE_REPORT_ERROR("js_cocos2dx_Sprite_setSpriteFrame : argument should be a SpriteFrame object");
      return;
    }
    cSprite->setSpriteFrame(spriteFrame);
  }
  else if (arg0->IsString())
  {
    std::string frameName = JsbUtils::FromV8String(isolate, arg0);
    cSprite->setSpriteFrame(frameName);
  }
}

// bool js_cocos2dx_Sprite_setTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setTexture : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setTexture : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setTexture : wrong number of arguments");
    return;
  }
  else if (args[0]->IsObject())
  {
    v8::Local<v8::Object> obj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    cocos2d::Texture2D *texture = (cocos2d::Texture2D *)obj->GetAlignedPointerFromInternalField(0);
    if (!texture)
    {
      SE_REPORT_ERROR("js_cocos2dx_Sprite_setTexture : argument should be a Texture2D object");
      return;
    }
    cSprite->setTexture(texture);
  }
  else if (args[0]->IsString())
  {
    std::string textureName = JsbUtils::FromV8String(isolate, args[0]);
    cSprite->setTexture(textureName);
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setTexture : argument should be a Texture2D object or a string");
    return;
  }
  //         if (argc == 1)
  //         {
  //             cocos2d::Texture2D *arg0 = nullptr;
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
  //                 arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cobj->setTexture(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }

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
  //             cobj->setTexture(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setTexture : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Sprite_getTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getTexture : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getTexture : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getTexture : wrong number of arguments");
    return;
  }
  //         cocos2d::Texture2D *ret = cobj->getTexture();
  cocos2d::Texture2D *texture = cSprite->getTexture();
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  if (texture)
  {
    v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(texture);
    args.GetReturnValue().Set(jsObj);
  }
  else
  {
    args.GetReturnValue().SetNull();
  }
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  //         args.rval().set(jsret);
  //         return true;
}

// bool js_cocos2dx_Sprite_setFlippedY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setFlippedY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setFlippedY : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setFlippedY : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setFlippedY : Error processing arguments");
  //         cobj->setFlippedY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setFlippedY : wrong number of arguments");
    return;
  }
  bool flippedY = args[0]->BooleanValue(isolate);
  cSprite->setFlippedY(flippedY);
  args.GetReturnValue().SetUndefined();

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setFlippedY : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setFlippedX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setFlippedX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setFlippedX : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setFlippedX : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setFlippedX : Error processing arguments");
  //         cobj->setFlippedX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setFlippedX : wrong number of arguments");
    return;
  }
  bool flippedX = args[0]->BooleanValue(isolate);
  cSprite->setFlippedX(flippedX);
  args.GetReturnValue().SetUndefined();
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setFlippedX : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setFlippedX : Error processing arguments");
  //         cobj->setFlippedX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setFlippedX : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setRotationSkewX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setRotationSkewX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setRotationSkewX : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setRotationSkewX : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setRotationSkewX : Error processing arguments");
  //         cobj->setRotationSkewX(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setRotationSkewX : wrong number of arguments");
    return;
  }
  double rotationSkewX = args[0]->NumberValue(isolate->GetCurrentContext()).FromMaybe(0);
  if (std::isnan(rotationSkewX))
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setRotationSkewX : argument should be a number");
    return;
  }
  cSprite->setRotationSkewX(rotationSkewX);
  args.GetReturnValue().SetUndefined();

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setRotationSkewX : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setRotationSkewY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setRotationSkewY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setRotationSkewY : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setRotationSkewY : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         double arg0 = 0;
  //         ok &= JS::ToNumber(cx, args.get(0), &arg0) && !std::isnan(arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setRotationSkewY : Error processing arguments");
  //         cobj->setRotationSkewY(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setRotationSkewY : wrong number of arguments");
    return;
  }
  double rotationSkewY = args[0]->NumberValue(isolate->GetCurrentContext()).FromMaybe(0);
  if (std::isnan(rotationSkewY))
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setRotationSkewY : argument should be a number");
    return;
  }
  cSprite->setRotationSkewY(rotationSkewY);
  args.GetReturnValue().SetUndefined();

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setRotationSkewY : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_getResourceType(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getResourceType(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getResourceType : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getResourceType : Invalid Native Object");
  //     if (argc == 0)
  //     {
  //         int ret = cobj->getResourceType();
  //         JS::RootedValue jsret(cx);
  //         jsret = int32_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getResourceType : wrong number of arguments");
    return;
  }
  int resourceType = cSprite->getResourceType();
  args.GetReturnValue().Set(v8::Integer::New(isolate, resourceType));

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getResourceType : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_setDisplayFrameWithAnimationName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setDisplayFrameWithAnimationName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setDisplayFrameWithAnimationName : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setDisplayFrameWithAnimationName : Invalid Native Object");
  //     if (argc == 2)
  //     {
  //         std::string arg0;
  //         ssize_t arg1 = 0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_ssize(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setDisplayFrameWithAnimationName : Error processing arguments");
  //         cobj->setDisplayFrameWithAnimationName(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setDisplayFrameWithAnimationName : wrong number of arguments");
    return;
  }
  std::string animationName = JsbUtils::FromV8String(isolate, args[0]);
  ssize_t frameIndex = args[1]->IntegerValue(isolate->GetCurrentContext()).FromMaybe(0);
  cSprite->setDisplayFrameWithAnimationName(animationName, frameIndex);
  args.GetReturnValue().SetUndefined();

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setDisplayFrameWithAnimationName : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_Sprite_getBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getBatchNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getBatchNode : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getBatchNode : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getBatchNode : wrong number of arguments");
    return;
  }

  //         cocos2d::SpriteBatchNode *ret = cobj->getBatchNode();
  cocos2d::SpriteBatchNode *batchNode = cSprite->getBatchNode();
  //         JS::RootedValue jsret(cx);
  v8::Local<v8::Value> jsret;
  if (batchNode)
  {
    v8::Local<v8::Object> jsObj = JsbUtils::NativePtrToObject(batchNode);
    jsret = jsObj;
  }
  else
  {
    jsret = v8::Null(isolate);
  }
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::SpriteBatchNode>(cx, (cocos2d::SpriteBatchNode *)ret));

  //         args.rval().set(jsret);
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getBatchNode : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_getOffsetPosition(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getOffsetPosition(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getOffsetPosition : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getOffsetPosition : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getOffsetPosition : wrong number of arguments");
    return;
  }

  //         const cocos2d::Vec2 &ret = cobj->getOffsetPosition();
  cocos2d::Vec2 offsetPosition = cSprite->getOffsetPosition();
  //         JS::RootedValue jsret(cx);
  //         jsret = vector2_to_jsval(cx, ret);
  auto jsret = JsbUtils::vector2_to_jsval(isolate, offsetPosition);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getOffsetPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_getCenterRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getCenterRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getCenterRect : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getCenterRect : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getCenterRect : wrong number of arguments");
    return;
  }

  //         cocos2d::Rect ret = cobj->getCenterRect();
  cocos2d::Rect centerRect = cSprite->getCenterRect();
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  auto jsret = JsbUtils::ccrect_to_jsval(isolate, centerRect);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getCenterRect : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_removeAllChildrenWithCleanup(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_removeAllChildrenWithCleanup : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_removeAllChildrenWithCleanup : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_removeAllChildrenWithCleanup : wrong number of arguments");
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool cleanup = args[0]->IsTrue();
  cSprite->removeAllChildrenWithCleanup(cleanup);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_removeAllChildrenWithCleanup : Error processing arguments");
  //         cobj->removeAllChildrenWithCleanup(arg0);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_removeAllChildrenWithCleanup : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setCenterRectNormalized(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setCenterRectNormalized(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setCenterRectNormalized : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setCenterRectNormalized : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setCenterRectNormalized : wrong number of arguments");
    return;
  }
  //         cocos2d::Rect arg0;
  //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
  cocos2d::Rect centerRect;
  bool ok = JsbUtils::jsval_to_ccrect(isolate, args[0], &centerRect);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setCenterRectNormalized : Error processing arguments");
  SE_PRECONDITION2(ok, "js_cocos2dx_Sprite_setCenterRectNormalized : Error processing arguments");
  //         cobj->setCenterRectNormalized(arg0);
  cSprite->setCenterRectNormalized(centerRect);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setCenterRectNormalized : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_isStretchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isStretchEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_isStretchEnabled : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isStretchEnabled : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isStretchEnabled : wrong number of arguments");
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isStretchEnabled();
  bool stretchEnabled = cSprite->isStretchEnabled();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, stretchEnabled));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_isStretchEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_setTextureRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setTextureRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setTextureRect : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setTextureRect : Invalid Native Object");

  //         if (argc == 3)
  //         {
  if (args.Length() == 3)
  {
    //             cocos2d::Rect arg0;
    cocos2d::Rect rect;
    //             ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
    bool ok = JsbUtils::jsval_to_ccrect(isolate, args[0], &rect);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool arg1;
    //             arg1 = JS::ToBoolean(args.get(1));
    bool rotated = args[1]->IsTrue();
    //             cocos2d::Size arg2;
    //             ok &= jsval_to_ccsize(cx, args.get(2), &arg2);
    cocos2d::Size untrimmedSize;
    ok &= JsbUtils::jsval_to_ccsize(isolate, args[2], &untrimmedSize);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->setTextureRect(arg0, arg1, arg2);
    cSprite->setTextureRect(rect, rotated, untrimmedSize);
    //             args.rval().setUndefined();
    args.GetReturnValue().SetUndefined();
    //             return true;
    return;
  }

  //         if (argc == 1)
  //         {
  //             cocos2d::Rect arg0;
  //             ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cobj->setTextureRect(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    cocos2d::Rect rect;
    bool ok = JsbUtils::jsval_to_ccrect(isolate, args[0], &rect);
    if (!ok)
    {
      SE_REPORT_ERROR("js_cocos2dx_Sprite_setTextureRect : Error processing arguments");
      return;
    }
    cSprite->setTextureRect(rect);
    args.GetReturnValue().SetUndefined();
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setTextureRect : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_Sprite_setTextureRect : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Sprite_initWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_initWithSpriteFrameName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_initWithSpriteFrameName : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_initWithSpriteFrameName : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_initWithSpriteFrameName : Error processing arguments");
  //         bool ret = cobj->initWithSpriteFrameName(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_initWithSpriteFrameName : wrong number of arguments");
    return;
  }
  std::string spriteFrameName = JsbUtils::FromV8String(isolate, args[0]);
  bool result = cSprite->initWithSpriteFrameName(spriteFrameName);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, result));

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_initWithSpriteFrameName : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setStretchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setStretchEnabled(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setStretchEnabled : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setStretchEnabled : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setStretchEnabled : Error processing arguments");
  //         cobj->setStretchEnabled(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setStretchEnabled : wrong number of arguments");
    return;
  }
  bool stretchEnabled = args[0]->IsTrue();
  cSprite->setStretchEnabled(stretchEnabled);
  args.GetReturnValue().SetUndefined();

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setStretchEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_isFrameDisplayed(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isFrameDisplayed(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_isFrameDisplayed : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isFrameDisplayed : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isFrameDisplayed : wrong number of arguments");
    return;
  }
  //         cocos2d::SpriteFrame *arg0 = nullptr;

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
  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isFrameDisplayed : argument should be a SpriteFrame object or null");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::SpriteFrame *)(jsProxy ? jsProxy->ptr : NULL);
  cocos2d::SpriteFrame *spriteFrame = nullptr;
  if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    spriteFrame = (cocos2d::SpriteFrame *)tmpObj->GetAlignedPointerFromInternalField(0);
  }
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_isFrameDisplayed : Error processing arguments");
  //         bool ret = cobj->isFrameDisplayed(arg0);
  bool isDisplayed = cSprite->isFrameDisplayed(spriteFrame);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  args.GetReturnValue().Set(isDisplayed);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_isFrameDisplayed : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_getAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getAtlasIndex(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getAtlasIndex : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getAtlasIndex : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getAtlasIndex : wrong number of arguments");
    return;
  }
  ssize_t atlasIndex = cSprite->getAtlasIndex();
  args.GetReturnValue().Set(v8::Integer::New(isolate, atlasIndex));
  //     if (argc == 0)
  //     {
  //         ssize_t ret = cobj->getAtlasIndex();
  //         JS::RootedValue jsret(cx);
  //         jsret = ssize_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getAtlasIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_setBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setBatchNode(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setBatchNode : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setBatchNode : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setBatchNode : wrong number of arguments");
    return;
  }
  //         cocos2d::SpriteBatchNode *arg0 = nullptr;

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
  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setBatchNode : argument should be a SpriteBatchNode object or null");
    return;
  }
  cocos2d::SpriteBatchNode *batchNode = nullptr;
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::SpriteBatchNode *)(jsProxy ? jsProxy->ptr : NULL);
  if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    batchNode = (cocos2d::SpriteBatchNode *)tmpObj->GetAlignedPointerFromInternalField(0);
  }
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setBatchNode : Error processing arguments");
  //         cobj->setBatchNode(arg0);
  cSprite->setBatchNode(batchNode);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
}

// bool js_cocos2dx_Sprite_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getBlendFunc : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getBlendFunc : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getBlendFunc : wrong number of arguments");
    return;
  }
  //     if (argc == 0)
  //     {
  //         const cocos2d::BlendFunc &ret = cobj->getBlendFunc();
  //         JS::RootedValue jsret(cx);
  //         jsret = blendfunc_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  v8::Local<v8::Value> jsret = JsbUtils::blendfunc_to_jsval(isolate, cSprite->getBlendFunc());
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_setCenterRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setCenterRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setCenterRect : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setCenterRect : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setCenterRect : wrong number of arguments");
    return;
  }
  //     if (argc == 1)
  //     {
  //         cocos2d::Rect arg0;
  //         ok &= jsval_to_ccrect(cx, args.get(0), &arg0);
  cocos2d::Rect centerRect;
  bool ok = JsbUtils::jsval_to_ccrect(isolate, args[0], &centerRect);
  if (!ok)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setCenterRect : Error processing arguments");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setCenterRect : Error processing arguments");
  //         cobj->setCenterRect(arg0);
  cSprite->setCenterRect(centerRect);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setCenterRect : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_setTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setTextureAtlas(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setTextureAtlas : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setTextureAtlas : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setTextureAtlas : wrong number of arguments");
    return;
  }

  //         cocos2d::TextureAtlas *arg0 = nullptr;

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
  if (!args[0]->IsObject() && !args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setTextureAtlas : argument should be a TextureAtlas object or null");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::TextureAtlas *)(jsProxy ? jsProxy->ptr : NULL);
  cocos2d::TextureAtlas *textureAtlas = nullptr;
  if (args[0]->IsObject())
  {
    v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    textureAtlas = (cocos2d::TextureAtlas *)tmpObj->GetAlignedPointerFromInternalField(0);
  }
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(textureAtlas, "Invalid Native Object");

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setTextureAtlas : Error processing arguments");
  //         cobj->setTextureAtlas(arg0);
  cSprite->setTextureAtlas(textureAtlas);
  //         args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //         return true;
  //     JS_ReportError(cx, "js_cocos2dx_Sprite_setTextureAtlas : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_Sprite_getSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getSpriteFrame(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getSpriteFrame : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getSpriteFrame : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getSpriteFrame : wrong number of arguments");
    return;
  }

  //         cocos2d::SpriteFrame *ret = cobj->getSpriteFrame();
  cocos2d::SpriteFrame *spriteFrame = cSprite->getSpriteFrame();
  //         JS::RootedValue jsret(cx);

  if (spriteFrame)
  {
    v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(spriteFrame);
    args.GetReturnValue().Set(jsret);
  }
  else
  {
    args.GetReturnValue().SetNull();
    return;
  }

  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::SpriteFrame>(cx, (cocos2d::SpriteFrame *)ret));

  //         args.rval().set(jsret);
  //         return true;

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getSpriteFrame : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_getResourceName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getResourceName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getResourceName : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getResourceName : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getResourceName : wrong number of arguments");
    return;
  }
  //     if (argc == 0)
  //     {
  //         const std::string &ret = cobj->getResourceName();
  const std::string &resourceName = cSprite->getResourceName();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  v8::Local<v8::String> jsret = JsbUtils::ToV8String(isolate, resourceName);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getResourceName : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_isDirty(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isDirty(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_isDirty : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isDirty : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isDirty : wrong number of arguments");
    return;
  }
  //     if (argc == 0)
  //     {
  //         bool ret = cobj->isDirty();
  bool isDirty = cSprite->isDirty();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, isDirty));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_isDirty : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_getCenterRectNormalized(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getCenterRectNormalized(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_getCenterRectNormalized : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getCenterRectNormalized : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getCenterRectNormalized : wrong number of arguments");
    return;
  }
  //     if (argc == 0)
  //     {
  //         cocos2d::Rect ret = cobj->getCenterRectNormalized();
  cocos2d::Rect centerRectNormalized = cSprite->getCenterRectNormalized();
  v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(isolate, centerRectNormalized);
  args.GetReturnValue().Set(jsret);
  //         JS::RootedValue jsret(cx);
  //         jsret = ccrect_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_getCenterRectNormalized : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_Sprite_setAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setAtlasIndex(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setAtlasIndex : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setAtlasIndex : wrong number of arguments");
    return;
  }
  ssize_t atlasIndex = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
  cSprite->setAtlasIndex(atlasIndex);
}
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_setAtlasIndex : Invalid Native Object");
//     if (argc == 1)
//     {
//         ssize_t arg0 = 0;
//         ok &= jsval_to_ssize(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_setAtlasIndex : Error processing arguments");
//         cobj->setAtlasIndex(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_Sprite_setAtlasIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_Sprite_initWithTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_initWithTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_initWithTexture : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_initWithTexture : Invalid Native Object");

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::Texture2D *arg0 = nullptr;
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
    //                 arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
    cocos2d::Texture2D *texture = nullptr;
    if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      texture = (cocos2d::Texture2D *)tmpObj->GetAlignedPointerFromInternalField(0);
    }

    //             cocos2d::Rect arg1;
    cocos2d::Rect rect;
    //             ok &= jsval_to_ccrect(cx, args.get(1), &arg1);
    bool ok = JsbUtils::jsval_to_ccrect(isolate, args[1], &rect);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithTexture(arg0, arg1);
    bool ret = cSprite->initWithTexture(texture, rect);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             cocos2d::Texture2D *arg0 = nullptr;
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
    //                 arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
    cocos2d::Texture2D *texture = nullptr;
    if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      texture = (cocos2d::Texture2D *)tmpObj->GetAlignedPointerFromInternalField(0);
    }
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithTexture(arg0);
    bool ret = cSprite->initWithTexture(texture);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //         if (argc == 3)
  //         {
  if (args.Length() == 3)
  {
    //             cocos2d::Texture2D *arg0 = nullptr;
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
    //                 arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
    cocos2d::Texture2D *texture = nullptr;
    if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      texture = (cocos2d::Texture2D *)tmpObj->GetAlignedPointerFromInternalField(0);
    }
    //                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cocos2d::Rect arg1;
    //             ok &= jsval_to_ccrect(cx, args.get(1), &arg1);
    cocos2d::Rect rect;
    bool ok = JsbUtils::jsval_to_ccrect(isolate, args[1], &rect);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool arg2;
    //             arg2 = JS::ToBoolean(args.get(2));
    bool rotated = args[2]->BooleanValue(isolate);
    //             bool ret = cobj->initWithTexture(arg0, arg1, arg2);
    bool ret = cSprite->initWithTexture(texture, rect, rotated);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_initWithTexture : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Sprite_setDirty(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setDirty(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setDirty : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setDirty : wrong number of arguments");
    return;
  }
  bool dirty = args[0]->BooleanValue(isolate);
  cSprite->setDirty(dirty);
}
// bool js_cocos2dx_Sprite_isTextureRectRotated(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isTextureRectRotated(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isTextureRectRotated : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isTextureRectRotated : wrong number of arguments");
    return;
  }
  bool rotated = cSprite->isTextureRectRotated();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, rotated));
}
// bool js_cocos2dx_Sprite_getTextureRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getTextureRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getTextureRect : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getTextureRect : wrong number of arguments");
    return;
  }
  cocos2d::Rect textureRect = cSprite->getTextureRect();
  v8::Local<v8::Value> jsret = JsbUtils::ccrect_to_jsval(isolate, textureRect);
  args.GetReturnValue().Set(jsret);
}

// bool js_cocos2dx_Sprite_initWithFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_initWithFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : nullptr);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_initWithFile : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_initWithFile : Invalid Native Object");

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cocos2d::Rect arg1;
    //             ok &= jsval_to_ccrect(cx, args.get(1), &arg1);
    cocos2d::Rect rect;
    bool ok = JsbUtils::jsval_to_ccrect(isolate, args[1], &rect);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithFile(arg0, arg1);
    bool ret = cSprite->initWithFile(filename, rect);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //     do
  //     {
  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->initWithFile(arg0);
    bool ret = cSprite->initWithFile(filename);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_initWithFile : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Sprite_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setBlendFunc(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setBlendFunc : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setBlendFunc : wrong number of arguments");
    return;
  }
  cocos2d::BlendFunc blendFunc;
  bool ok = JsbUtils::jsval_to_blendfunc(isolate, args[0], &blendFunc);
  if (!ok)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setBlendFunc : Error processing arguments");
    return;
  }
  cSprite->setBlendFunc(blendFunc);
}

// bool js_cocos2dx_Sprite_getTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_getTextureAtlas(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_getTextureAtlas : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_getTextureAtlas : wrong number of arguments");
    return;
  }
  cocos2d::TextureAtlas *textureAtlas = cSprite->getTextureAtlas();
  if (textureAtlas)
  {
    v8::Local<v8::Object> jsret = JsbUtils::NativePtrToObject(textureAtlas);
    args.GetReturnValue().Set(jsret);
  }
  else
  {
    args.GetReturnValue().SetNull();
    return;
  }
}

// bool js_cocos2dx_Sprite_initWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_initWithSpriteFrame(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::Sprite *cobj = (cocos2d::Sprite *)(proxy ? proxy->ptr : NULL);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_Sprite_initWithSpriteFrame : Invalid Native Object");
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_initWithSpriteFrame : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    //         cocos2d::SpriteFrame *arg0 = nullptr;

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
    cocos2d::SpriteFrame *spriteFrame = nullptr;
    if (args[0]->IsObject())
    {
      v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      spriteFrame = (cocos2d::SpriteFrame *)tmpObj->GetAlignedPointerFromInternalField(0);
    }
    //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");

    //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_Sprite_initWithSpriteFrame : Error processing arguments");
    //         bool ret = cobj->initWithSpriteFrame(arg0);
    bool ret = cSprite->initWithSpriteFrame(spriteFrame);
    //         JS::RootedValue jsret(cx);
    //         jsret = BOOLEAN_TO_JSVAL(ret);
    //         args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //         return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_Sprite_initWithSpriteFrame : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_Sprite_initWithSpriteFrame : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_Sprite_isFlippedX(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isFlippedX(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isFlippedX : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isFlippedX : wrong number of arguments");
    return;
  }
  bool flippedX = cSprite->isFlippedX();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, flippedX));
}

// bool js_cocos2dx_Sprite_isFlippedY(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_isFlippedY(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_isFlippedY : Invalid Native Object");
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_isFlippedY : wrong number of arguments");
    return;
  }
  bool flippedY = cSprite->isFlippedY();
  args.GetReturnValue().Set(v8::Boolean::New(isolate, flippedY));
}

// bool js_cocos2dx_Sprite_setVertexRect(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_setVertexRect(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  cocos2d::Sprite *cSprite = (cocos2d::Sprite *)(args.This()->GetAlignedPointerFromInternalField(0));
  SE_PRECONDITION2(cSprite, "js_cocos2dx_Sprite_setVertexRect : Invalid Native Object");
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setVertexRect : wrong number of arguments");
    return;
  }
  cocos2d::Rect vertexRect;
  bool ok = JsbUtils::jsval_to_ccrect(isolate, args[0], &vertexRect);
  if (!ok)
  {
    SE_REPORT_ERROR("js_cocos2dx_Sprite_setVertexRect : Error processing arguments");
    return;
  }
  cSprite->setVertexRect(vertexRect);
}

// bool js_cocos2dx_Sprite_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::Sprite *cobj = new (std::nothrow) cocos2d::Sprite();
  cocos2d::Sprite *cSprite = new (std::nothrow) cocos2d::Sprite();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::Sprite>(cobj);

  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::Sprite"));
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(cSprite);
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  args.GetReturnValue().Set(jsobj);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     return true;
}

// static bool js_cocos2dx_Sprite_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_Sprite_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::Sprite *nobj = new (std::nothrow) cocos2d::Sprite();
  cocos2d::Sprite *nSprite = new (std::nothrow) cocos2d::Sprite();
  //     js_proxy_t *p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::Sprite");
  v8::Local<v8::Object> jsobj = jsb_ref_create_jsobject(nSprite);
  //     bool isFound = false;
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, jsobj);
  //     args.rval().setUndefined();
  args.GetReturnValue().SetUndefined();
  //     return true;
}

// extern JSObject *jsb_cocos2d_Node_prototype;

// void js_register_cocos2dx_Sprite(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_Sprite(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  v8::HandleScope handleScope(isolate);
  //     jsb_cocos2d_Sprite_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_Sprite_class->name = "Sprite";
  //     jsb_cocos2d_Sprite_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_Sprite_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_Sprite_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_Sprite_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_Sprite_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_Sprite_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_Sprite_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_Sprite_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_constructor);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Sprite").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();
  v8::Local<v8::FunctionTemplate> parentProto = ScriptEngine::getInstance()->getClassByName(typeid(cocos2d::Node).name());
  tpl->Inherit(parentProto);
  JsbUtils::RegisterV8Class(typeid(cocos2d::Sprite).name(), &tpl);
  JsbUtils::BindJsClass("Sprite", global, tpl);

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("setSpriteFrame", js_cocos2dx_Sprite_setSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSpriteFrame", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setSpriteFrame));
  //         JS_FN("setTexture", js_cocos2dx_Sprite_setTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setTexture));
  //         JS_FN("getTexture", js_cocos2dx_Sprite_getTexture, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getTexture));
  //         JS_FN("setFlippedY", js_cocos2dx_Sprite_setFlippedY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFlippedY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setFlippedY));
  //         JS_FN("setFlippedX", js_cocos2dx_Sprite_setFlippedX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setFlippedX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setFlippedX));
  //         JS_FN("setRotationSkewX", js_cocos2dx_Sprite_setRotationSkewX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setRotationSkewX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setRotationSkewX));
  //         JS_FN("setRotationSkewY", js_cocos2dx_Sprite_setRotationSkewY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setRotationSkewY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setRotationSkewY));
  //         JS_FN("getResourceType", js_cocos2dx_Sprite_getResourceType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getResourceType", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getResourceType));
  //         JS_FN("setDisplayFrameWithAnimationName", js_cocos2dx_Sprite_setDisplayFrameWithAnimationName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setDisplayFrameWithAnimationName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setDisplayFrameWithAnimationName));
  //         JS_FN("getBatchNode", js_cocos2dx_Sprite_getBatchNode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBatchNode", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getBatchNode));
  //         JS_FN("getOffsetPosition", js_cocos2dx_Sprite_getOffsetPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getOffsetPosition", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getOffsetPosition));
  //         JS_FN("getCenterRect", js_cocos2dx_Sprite_getCenterRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCenterRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getCenterRect));
  //         JS_FN("removeAllChildrenWithCleanup", js_cocos2dx_Sprite_removeAllChildrenWithCleanup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAllChildrenWithCleanup", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_removeAllChildrenWithCleanup));
  //         JS_FN("setCenterRectNormalized", js_cocos2dx_Sprite_setCenterRectNormalized, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCenterRectNormalized", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setCenterRectNormalized));
  //         JS_FN("isStretchEnabled", js_cocos2dx_Sprite_isStretchEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isStretchEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isStretchEnabled));
  //         JS_FN("setTextureRect", js_cocos2dx_Sprite_setTextureRect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTextureRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setTextureRect));
  //         JS_FN("initWithSpriteFrameName", js_cocos2dx_Sprite_initWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "initWithSpriteFrameName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_initWithSpriteFrameName));
  //         JS_FN("setStretchEnabled", js_cocos2dx_Sprite_setStretchEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setStretchEnabled", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setStretchEnabled));
  //         JS_FN("isFrameDisplayed", js_cocos2dx_Sprite_isFrameDisplayed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFrameDisplayed", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isFrameDisplayed));
  //         JS_FN("getAtlasIndex", js_cocos2dx_Sprite_getAtlasIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getAtlasIndex", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getAtlasIndex));
  //         JS_FN("setBatchNode", js_cocos2dx_Sprite_setBatchNode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBatchNode", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setBatchNode));
  //         JS_FN("getBlendFunc", js_cocos2dx_Sprite_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getBlendFunc));
  //         JS_FN("setCenterRect", js_cocos2dx_Sprite_setCenterRect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setCenterRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setCenterRect));
  //         JS_FN("setTextureAtlas", js_cocos2dx_Sprite_setTextureAtlas, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setTextureAtlas", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setTextureAtlas));
  //         JS_FN("getSpriteFrame", js_cocos2dx_Sprite_getSpriteFrame, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSpriteFrame", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getSpriteFrame));
  //         JS_FN("getResourceName", js_cocos2dx_Sprite_getResourceName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getResourceName", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getResourceName));
  //         JS_FN("isDirty", js_cocos2dx_Sprite_isDirty, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isDirty", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isDirty));
  //         JS_FN("getCenterRectNormalized", js_cocos2dx_Sprite_getCenterRectNormalized, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getCenterRectNormalized", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getCenterRectNormalized));
  //         JS_FN("setAtlasIndex", js_cocos2dx_Sprite_setAtlasIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setAtlasIndex", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setAtlasIndex));
  //         JS_FN("initWithTexture", js_cocos2dx_Sprite_initWithTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "initWithTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_initWithTexture));
  //         JS_FN("setDirty", js_cocos2dx_Sprite_setDirty, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setDirty", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setDirty));
  //         JS_FN("isTextureRectRotated", js_cocos2dx_Sprite_isTextureRectRotated, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isTextureRectRotated", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isTextureRectRotated));
  //         JS_FN("getTextureRect", js_cocos2dx_Sprite_getTextureRect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTextureRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getTextureRect));
  //         JS_FN("initWithFile", js_cocos2dx_Sprite_initWithFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "initWithFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_initWithFile));
  //         JS_FN("setBlendFunc", js_cocos2dx_Sprite_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setBlendFunc", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setBlendFunc));
  //         JS_FN("getTextureAtlas", js_cocos2dx_Sprite_getTextureAtlas, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getTextureAtlas", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_getTextureAtlas));
  //         JS_FN("initWithSpriteFrame", js_cocos2dx_Sprite_initWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "initWithSpriteFrame", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_initWithSpriteFrame));
  //         JS_FN("isFlippedX", js_cocos2dx_Sprite_isFlippedX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFlippedX", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isFlippedX));
  //         JS_FN("isFlippedY", js_cocos2dx_Sprite_isFlippedY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFlippedY", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_isFlippedY));
  //         JS_FN("setVertexRect", js_cocos2dx_Sprite_setVertexRect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setVertexRect", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_setVertexRect));
  //         JS_FN("ctor", js_cocos2dx_Sprite_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_Sprite_ctor));
  //         JS_FS_END};

  //     JSFunctionSpec *st_funcs = NULL;

  //     JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
  //     jsb_cocos2d_Sprite_prototype = JS_InitClass(
  //         cx, global,
  //         parent_proto,
  //         jsb_cocos2d_Sprite_class,
  //         js_cocos2dx_Sprite_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_Sprite_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "Sprite"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "Sprite"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  proto->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::Sprite>(cx, jsb_cocos2d_Sprite_class, proto, parent_proto);
  //     anonEvaluate(cx, global, "(function () { cc.Sprite.extend = cc.Class.extend; })()");
}

// JSClass *jsb_cocos2d_AnimationCache_class;
// JSObject *jsb_cocos2d_AnimationCache_prototype;

// bool js_cocos2dx_AnimationCache_getAnimation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_getAnimation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_getAnimation : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_getAnimation : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_getAnimation : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string animKey = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_AnimationCache_getAnimation : Error processing arguments");
  //         cocos2d::Animation *ret = cobj->getAnimation(arg0);
  cocos2d::Animation *animation = cAnimationCache->getAnimation(animKey);
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Animation>(cx, (cocos2d::Animation *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  auto jsret = JsbUtils::NativePtrToObject(animation);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_getAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_addAnimation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_addAnimation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_addAnimation : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_addAnimation : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimation : wrong number of arguments");
    return;
  }
  //         cocos2d::Animation *arg0 = nullptr;
  cocos2d::Animation *animation = nullptr;
  //         std::string arg1;
  std::string animKey;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimation : argument 0 is null");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimation : argument 0 is not an object");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::Animation *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  animation = (cocos2d::Animation *)jsObj->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(animation, "js_cocos2dx_AnimationCache_addAnimation : argument 0 is not a valid Animation object");
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  animKey = JsbUtils::FromV8String(isolate, args[1]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_AnimationCache_addAnimation : Error processing arguments");
  //         cobj->addAnimation(arg0, arg1);
  cAnimationCache->addAnimation(animation, animKey);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_addAnimation : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_init : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_init : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_init : wrong number of arguments");
    return;
  }
  //         bool ret = cobj->init();
  bool ret = cAnimationCache->init();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_init : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_addAnimationsWithDictionary(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_addAnimationsWithDictionary(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_addAnimationsWithDictionary : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_addAnimationsWithDictionary : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimationsWithDictionary : wrong number of arguments");
    return;
  }
  //         cocos2d::ValueMap arg0;
  //         std::string arg1;
  //         ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
  cocos2d::ValueMap dict;
  bool ok = JsbUtils::jsval_to_ccvaluemap(isolate, args[0], &dict);
  if (!ok)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimationsWithDictionary : Error processing arguments");
    return;
  }
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  std::string animKeyPrefix = JsbUtils::FromV8String(isolate, args[1]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_AnimationCache_addAnimationsWithDictionary : Error processing arguments");
  //         cobj->addAnimationsWithDictionary(arg0, arg1);
  cAnimationCache->addAnimationsWithDictionary(dict, animKeyPrefix);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_addAnimationsWithDictionary : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_removeAnimation(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_removeAnimation(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_removeAnimation : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_removeAnimation : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_removeAnimation : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string animKey = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_AnimationCache_removeAnimation : Error processing arguments");
  //         cobj->removeAnimation(arg0);
  cAnimationCache->removeAnimation(animKey);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_removeAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_addAnimationsWithFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_addAnimationsWithFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::AnimationCache *cobj = (cocos2d::AnimationCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::AnimationCache *cAnimationCache = (cocos2d::AnimationCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_AnimationCache_addAnimationsWithFile : Invalid Native Object");
  SE_PRECONDITION2(cAnimationCache, "js_cocos2dx_AnimationCache_addAnimationsWithFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_addAnimationsWithFile : wrong number of arguments");
    return;
  }
  std::string file = JsbUtils::FromV8String(isolate, args[0]);
  cAnimationCache->addAnimationsWithFile(file);
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_AnimationCache_addAnimationsWithFile : Error processing arguments");
  //         cobj->addAnimationsWithFile(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_addAnimationsWithFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_AnimationCache_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_destroyInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_destroyInstance : wrong number of arguments");
    return;
  }
  //         cocos2d::AnimationCache::destroyInstance();
  cocos2d::AnimationCache::destroyInstance();
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_destroyInstance : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_AnimationCache_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_AnimationCache_getInstance : wrong number of arguments");
    return;
  }
  //         auto ret = cocos2d::AnimationCache::getInstance();
  auto animationCache = cocos2d::AnimationCache::getInstance();
  //         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::AnimationCache>(ret);
  //         JS::RootedObject jsret(cx, jsb_ref_get_or_create_jsobject(cx, ret, typeClass, "cocos2d::AnimationCache"));
  auto jsret = JsbUtils::NativePtrToObject(animationCache);
  //         args.rval().set(OBJECT_TO_JSVAL(jsret));
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_AnimationCache_getInstance : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_AnimationCache_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     cocos2d::AnimationCache *cobj = new (std::nothrow) cocos2d::AnimationCache();
  cocos2d::AnimationCache *cAnimationCache = new (std::nothrow) cocos2d::AnimationCache();

  //     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::AnimationCache>(cobj);
  auto jsret = jsb_ref_create_jsobject(cAnimationCache);
  //     // link the native object with the javascript object
  //     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::AnimationCache"));
  //     args.rval().set(OBJECT_TO_JSVAL(jsobj));
  args.GetReturnValue().Set(jsret);
  //     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
  CallCustomConstructor(args, args.This());
  //     return true;
}

// static bool js_cocos2dx_AnimationCache_ctor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_AnimationCache_ctor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     cocos2d::AnimationCache *nobj = new (std::nothrow) cocos2d::AnimationCache();
  cocos2d::AnimationCache *nAnimationCache = new (std::nothrow) cocos2d::AnimationCache();
  //     js_proxy_t *p = jsb_new_proxy(nobj, obj);
  //     jsb_ref_init(cx, &p->obj, nobj, "cocos2d::AnimationCache");
  //     bool isFound = false;
  auto jsObj = jsb_ref_create_jsobject(nAnimationCache);
  //     if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
  //         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
  CallCustomConstructor(args, args.This());
  //     args.rval().setUndefined();
  //     return true;
}

// void js_register_cocos2dx_AnimationCache(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_AnimationCache(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_AnimationCache_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_AnimationCache_class->name = "AnimationCache";
  //     jsb_cocos2d_AnimationCache_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_AnimationCache_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_AnimationCache_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_AnimationCache_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_AnimationCache_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_AnimationCache_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_AnimationCache_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_AnimationCache_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
  auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_constructor);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "AnimationCache"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  auto proto = tpl->PrototypeTemplate();

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("getAnimation", js_cocos2dx_AnimationCache_getAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getAnimation", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_getAnimation));
  //         JS_FN("addAnimation", js_cocos2dx_AnimationCache_addAnimation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addAnimation", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_addAnimation));
  //         JS_FN("init", js_cocos2dx_AnimationCache_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "init", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_init));
  //         JS_FN("addAnimationsWithDictionary", js_cocos2dx_AnimationCache_addAnimationsWithDictionary, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addAnimationsWithDictionary", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_addAnimationsWithDictionary));
  //         JS_FN("removeAnimation", js_cocos2dx_AnimationCache_removeAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeAnimation", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_removeAnimation));
  //         JS_FN("addAnimations", js_cocos2dx_AnimationCache_addAnimationsWithFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addAnimations", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_addAnimationsWithFile));
  //         JS_FN("ctor", js_cocos2dx_AnimationCache_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "ctor", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_ctor));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("destroyInstance", js_cocos2dx_AnimationCache_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "destroyInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_destroyInstance));
  //         JS_FN("getInstance", js_cocos2dx_AnimationCache_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_AnimationCache_getInstance));
  //         JS_FS_END};

  //     jsb_cocos2d_AnimationCache_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_AnimationCache_class,
  //         js_cocos2dx_AnimationCache_constructor, 0, // constructor
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_AnimationCache_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "AnimationCache"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "AnimationCache"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
  proto->Set(isolate, "__is_ref", v8::Boolean::New(isolate, true));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::AnimationCache>(cx, jsb_cocos2d_AnimationCache_class, proto, JS::NullPtr());
  //     anonEvaluate(cx, global, "(function () { cc.AnimationCache.extend = cc.Class.extend; })()");
  JsbUtils::RegisterV8Class(typeid(cocos2d::AnimationCache).name(), &tpl);
  JsbUtils::BindJsClass("AnimationCache", global, tpl);
}

// JSClass *jsb_cocos2d_SpriteFrameCache_class;
// JSObject *jsb_cocos2d_SpriteFrameCache_prototype;

// bool js_cocos2dx_SpriteFrameCache_reloadTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_reloadTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_reloadTexture : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_reloadTexture : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_reloadTexture : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string textureFile = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_reloadTexture : Error processing arguments");
  //         bool ret = cobj->reloadTexture(arg0);
  bool ret = cSpriteFrameCache->reloadTexture(textureFile);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_reloadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         cocos2d::Texture2D *arg1 = nullptr;
  cocos2d::Texture2D *texture = nullptr;
  std::string plistContent;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  plistContent = JsbUtils::FromV8String(isolate, args[0]);
  //         do
  //         {
  //             if (args.get(1).isNull())
  //             {
  //                 arg1 = nullptr;
  //                 break;
  //             }
  if (args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : argument 1 is null");
    return;
  }
  //             if (!args.get(1).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[1]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : argument 1 is not an object");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  texture = (cocos2d::Texture2D *)jsObj->GetAlignedPointerFromInternalField(0);
  //             JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(texture, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : argument 1 is not a valid Texture2D object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : Error processing arguments");
  //         cobj->addSpriteFramesWithFileContent(arg0, arg1);
  cSpriteFrameCache->addSpriteFramesWithFileContent(plistContent, texture);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_addSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_addSpriteFrame(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_addSpriteFrame : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_addSpriteFrame : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFrame : wrong number of arguments");
    return;
  }
  //         cocos2d::SpriteFrame *arg0 = nullptr;
  cocos2d::SpriteFrame *spriteFrame = nullptr;
  //         std::string arg1;
  std::string frameKey;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFrame : argument 0 is null");
    return;
  }
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFrame : argument 0 is not an object");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::SpriteFrame *)(jsProxy ? jsProxy->ptr : NULL);
  auto jsObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  spriteFrame = (cocos2d::SpriteFrame *)jsObj->GetAlignedPointerFromInternalField(0);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  SE_PRECONDITION2(spriteFrame, "js_cocos2dx_SpriteFrameCache_addSpriteFrame : argument 0 is not a valid SpriteFrame object");
  //         } while (0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  frameKey = JsbUtils::FromV8String(isolate, args[1]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_addSpriteFrame : Error processing arguments");
  //         cobj->addSpriteFrame(arg0, arg1);
  cSpriteFrameCache->addSpriteFrame(spriteFrame, frameKey);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_addSpriteFrame : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::SpriteFrameCache *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : nullptr);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile : Invalid Native Object");

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
  //             cobj->addSpriteFramesWithFile(arg0);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  if (args.Length() == 1)
  {
    std::string plistFile = JsbUtils::FromV8String(isolate, args[0]);
    cSpriteFrameCache->addSpriteFramesWithFile(plistFile);
    return;
  }
  //     } while (0);

  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string plistFile = JsbUtils::FromV8String(isolate, args[0]);

    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->addSpriteFramesWithFile(arg0, arg1);
    //             args.rval().setUndefined();
    //             return true;
    if (args[1]->IsString())
    {
      std::string textureFile = JsbUtils::FromV8String(isolate, args[1]);
      cSpriteFrameCache->addSpriteFramesWithFile(plistFile, textureFile);
      return;
    }
    else if (args[1]->IsObject())
    {
      auto jsObj = args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
      cocos2d::Texture2D *texture = (cocos2d::Texture2D *)jsObj->GetAlignedPointerFromInternalField(0);
      SE_PRECONDITION2(texture, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile : argument 1 is not a valid Texture2D object");
      cSpriteFrameCache->addSpriteFramesWithFile(plistFile, texture);
      return;
    }
  }

  //     } while (0);

  //     do
  //     {
  //         if (argc == 2)
  //         {
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cocos2d::Texture2D *arg1 = nullptr;
  //             do
  //             {
  //                 if (args.get(1).isNull())
  //                 {
  //                     arg1 = nullptr;
  //                     break;
  //                 }
  //                 if (!args.get(1).isObject())
  //                 {
  //                     ok = false;
  //                     break;
  //                 }
  //                 js_proxy_t *jsProxy;
  //                 JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //                 jsProxy = jsb_get_js_proxy(tmpObj);
  //                 arg1 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
  //                 JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
  //             } while (0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             cobj->addSpriteFramesWithFile(arg0, arg1);
  //             args.rval().setUndefined();
  //             return true;
  //         }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_getSpriteFrameByName(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_getSpriteFrameByName(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_getSpriteFrameByName : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_getSpriteFrameByName : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_getSpriteFrameByName : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string frameName = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_getSpriteFrameByName : Error processing arguments");
  //         cocos2d::SpriteFrame *ret = cobj->getSpriteFrameByName(arg0);
  cocos2d::SpriteFrame *spriteFrame = cSpriteFrameCache->getSpriteFrameByName(frameName);
  //         JS::RootedValue jsret(cx);
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::SpriteFrame>(cx, (cocos2d::SpriteFrame *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  auto jsret = JsbUtils::NativePtrToObject(spriteFrame);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_getSpriteFrameByName : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile : wrong number of arguments");
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string plistFile = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile : Error processing arguments");
  //         cobj->removeSpriteFramesFromFile(arg0);
  cSpriteFrameCache->removeSpriteFramesFromFile(plistFile);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_init(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_SpriteFrameCache_init(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
  cocos2d::SpriteFrameCache *cSpriteFrameCache = (cocos2d::SpriteFrameCache *)(args.This()->GetAlignedPointerFromInternalField(0));
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_init : Invalid Native Object");
  SE_PRECONDITION2(cSpriteFrameCache, "js_cocos2dx_SpriteFrameCache_init : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if(args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_SpriteFrameCache_init : wrong number of arguments");
    return;
  }[]
  //         bool ret = cobj->init();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_init : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_SpriteFrameCache_removeSpriteFrames(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFrames : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->removeSpriteFrames();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeSpriteFrames : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_removeUnusedSpriteFrames(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeUnusedSpriteFrames : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->removeUnusedSpriteFrames();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeUnusedSpriteFrames : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFileContent(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFileContent : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFileContent : Error processing arguments");
//         cobj->removeSpriteFramesFromFileContent(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFileContent : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_removeSpriteFrameByName(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFrameByName : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFrameByName : Error processing arguments");
//         cobj->removeSpriteFrameByName(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeSpriteFrameByName : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_isSpriteFramesWithFileLoaded(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_isSpriteFramesWithFileLoaded : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_isSpriteFramesWithFileLoaded : Error processing arguments");
//         bool ret = cobj->isSpriteFramesWithFileLoaded(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_isSpriteFramesWithFileLoaded : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::SpriteFrameCache *cobj = (cocos2d::SpriteFrameCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromTexture : Invalid Native Object");
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
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromTexture : Error processing arguments");
//         cobj->removeSpriteFramesFromTexture(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_SpriteFrameCache_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {
//         cocos2d::SpriteFrameCache::destroyInstance();
//         args.rval().setUndefined();
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_destroyInstance : wrong number of arguments");
//     return false;
// }

// bool js_cocos2dx_SpriteFrameCache_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         auto ret = cocos2d::SpriteFrameCache::getInstance();
//         js_type_class_t *typeClass = js_get_type_from_native<cocos2d::SpriteFrameCache>(ret);
//         JS::RootedObject jsret(cx, jsb_ref_get_or_create_jsobject(cx, ret, typeClass, "cocos2d::SpriteFrameCache"));
//         args.rval().set(OBJECT_TO_JSVAL(jsret));
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_SpriteFrameCache_getInstance : wrong number of arguments");
//     return false;
// }

// void js_register_cocos2dx_SpriteFrameCache(JSContext *cx, JS::HandleObject global)
// {
//     jsb_cocos2d_SpriteFrameCache_class = (JSClass *)calloc(1, sizeof(JSClass));
//     jsb_cocos2d_SpriteFrameCache_class->name = "SpriteFrameCache";
//     jsb_cocos2d_SpriteFrameCache_class->addProperty = JS_PropertyStub;
//     jsb_cocos2d_SpriteFrameCache_class->delProperty = JS_DeletePropertyStub;
//     jsb_cocos2d_SpriteFrameCache_class->getProperty = JS_PropertyStub;
//     jsb_cocos2d_SpriteFrameCache_class->setProperty = JS_StrictPropertyStub;
//     jsb_cocos2d_SpriteFrameCache_class->enumerate = JS_EnumerateStub;
//     jsb_cocos2d_SpriteFrameCache_class->resolve = JS_ResolveStub;
//     jsb_cocos2d_SpriteFrameCache_class->convert = JS_ConvertStub;
//     jsb_cocos2d_SpriteFrameCache_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("reloadTexture", js_cocos2dx_SpriteFrameCache_reloadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addSpriteFramesWithFileContent", js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFileContent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addSpriteFrame", js_cocos2dx_SpriteFrameCache_addSpriteFrame, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addSpriteFrames", js_cocos2dx_SpriteFrameCache_addSpriteFramesWithFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSpriteFrame", js_cocos2dx_SpriteFrameCache_getSpriteFrameByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeSpriteFramesFromFile", js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("init", js_cocos2dx_SpriteFrameCache_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeSpriteFrames", js_cocos2dx_SpriteFrameCache_removeSpriteFrames, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeUnusedSpriteFrames", js_cocos2dx_SpriteFrameCache_removeUnusedSpriteFrames, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeSpriteFramesFromFileContent", js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromFileContent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeSpriteFrameByName", js_cocos2dx_SpriteFrameCache_removeSpriteFrameByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isSpriteFramesWithFileLoaded", js_cocos2dx_SpriteFrameCache_isSpriteFramesWithFileLoaded, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeSpriteFramesFromTexture", js_cocos2dx_SpriteFrameCache_removeSpriteFramesFromTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("destroyInstance", js_cocos2dx_SpriteFrameCache_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getInstance", js_cocos2dx_SpriteFrameCache_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     jsb_cocos2d_SpriteFrameCache_prototype = JS_InitClass(
//         cx, global,
//         JS::NullPtr(),
//         jsb_cocos2d_SpriteFrameCache_class,
//         empty_constructor, 0,
//         properties,
//         funcs,
//         NULL, // no static properties
//         st_funcs);

//     JS::RootedObject proto(cx, jsb_cocos2d_SpriteFrameCache_prototype);
//     JS::RootedValue className(cx, std_string_to_jsval(cx, "SpriteFrameCache"));
//     JS_SetProperty(cx, proto, "_className", className);
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::SpriteFrameCache>(cx, jsb_cocos2d_SpriteFrameCache_class, proto, JS::NullPtr());
// }
