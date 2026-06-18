#include "JsbTexture2DWrapper.hpp"
#include "ScriptEngine.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "JsbConvert.hpp"
#include "renderer/CCTextureCache.h"

// JSClass *jsb_cocos2d_TextureCache_class;
// JSObject *jsb_cocos2d_TextureCache_prototype;

// bool js_cocos2dx_TextureCache_reloadTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_reloadTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     bool ok = true;
	//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
	//     cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_reloadTexture : Invalid Native Object");
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_reloadTexture : Invalid Native Object");
	//     if (argc == 1)
	//     {
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_reloadTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	//         std::string arg0;
	//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
	std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
	//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_reloadTexture : Error processing arguments");
	//         bool ret = cobj->reloadTexture(arg0);
	bool ret = cobj->reloadTexture(texturePath);
	//         JS::RootedValue jsret(cx);
	//         jsret = BOOLEAN_TO_JSVAL(ret);
	//         args.rval().set(jsret);
	args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
	//         return true;
	//     }

	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_reloadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
	//     return false;
}

// bool js_cocos2dx_TextureCache_unbindAllImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_unbindAllImageAsync(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_unbindAllImageAsync : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_unbindAllImageAsync : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	cobj->unbindAllImageAsync();
}

// bool js_cocos2dx_TextureCache_removeTextureForKey(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_removeTextureForKey(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_removeTextureForKey : Invalid Native Object");
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_removeTextureForKey : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
	cobj->removeTextureForKey(texturePath);
}

// bool js_cocos2dx_TextureCache_removeAllTextures(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_removeAllTextures(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_removeAllTextures : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_removeAllTextures : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	cobj->removeAllTextures();
}

// bool js_cocos2dx_TextureCache_addImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_addImageAsync(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_addImageAsync : Invalid Native Object");

	if (args.Length() == 3)
	{
		std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
		//             std::function<void(cocos2d::Texture2D *)> arg1;
		std::function<void(cocos2d::Texture2D *)> callback;
		std::string arg2;
		//             do
		//             {
		//                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		//                 {
		if (args[1]->IsFunction())
		{
			v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(args[1]);
			callback = JsbConvert::FromJsFunc<void, cocos2d::Texture2D *>(isolate, func, args.This());
			//  JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
			//  std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
			//  auto lambda = [=](cocos2d::Texture2D *larg0) -> void
			//  {
			//      JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
			//      jsval largv[1];
			//      if (larg0)
			//      {
			//          largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)larg0));
			//      }
			//      else
			//      {
			//          largv[0] = JSVAL_NULL;
			//      };
			//      JS::RootedValue rval(cx);
			//      bool succeed = func->invoke(1, &largv[0], &rval);

			//      if (!succeed && JS_IsExceptionPending(cx))
			//      {
			//          JS_ReportPendingException(cx);
			//      }
		}
		//             std::string arg2;
		//             ok &= jsval_to_std_string(cx, args.get(2), &arg2);
		std::string callBackKey = JsbUtils::FromV8String(isolate, args[2]);

		//             cobj->addImageAsync(arg0, arg1, arg2);
		cobj->addImageAsync(texturePath, callback, callBackKey);
		//             args.rval().setUndefined();
		return;
		//             return true;
	}
	else if (args.Length() == 2)
	{
		//             std::string arg0;
		std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
		//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
		//             if (!ok)
		//             {
		//                 ok = true;
		//                 break;
		//             }
		//             std::function<void(cocos2d::Texture2D *)> arg1;
		std::function<void(cocos2d::Texture2D *)> callback;
		//             do
		//             {
		//                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		//                 {
		if (args[1]->IsFunction())
		{
			v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(args[1]);
			callback = JsbConvert::FromJsFunc<void, cocos2d::Texture2D *>(isolate, func, args.This());

			//                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
			//                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
			//                     auto lambda = [=](cocos2d::Texture2D *larg0) -> void
			//                     {
			//                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
			//                         jsval largv[1];
			//                         if (larg0)
			//                         {
			//                             largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)larg0));
			//                         }
			//                         else
			//                         {
			//                             largv[0] = JSVAL_NULL;
			//                         };
			//                         JS::RootedValue rval(cx);
			//                         bool succeed = func->invoke(1, &largv[0], &rval);
			//                         if (!succeed && JS_IsExceptionPending(cx))
			//                         {
			//                             JS_ReportPendingException(cx);
			//                         }
			//                     };
			//                     arg1 = lambda;
			//                 }
			//                 else
			//                 {
			//                     arg1 = nullptr;
			//                 }
		}
		else
		{
			callback = nullptr;
		}
		//             cobj->addImageAsync(arg0, arg1);
		cobj->addImageAsync(texturePath, callback);
		//             args.rval().setUndefined();
		return;
		//             return true;
	}

	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_addImageAsync : wrong number of arguments");
	SE_REPORT_ERROR("js_cocos2dx_TextureCache_addImageAsync : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
	//     return false;
}

// bool js_cocos2dx_TextureCache_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_getDescription(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_getDescription : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getDescription : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	std::string ret = cobj->getDescription();
	args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
}

// bool js_cocos2dx_TextureCache_getCachedTextureInfo(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_getCachedTextureInfo(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_getCachedTextureInfo : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getCachedTextureInfo : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	std::string ret = cobj->getCachedTextureInfo();
	args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
	//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
	//     cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
	//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_getCachedTextureInfo : Invalid Native Object");
	//     if (argc == 0)
	//     {
	//         std::string ret = cobj->getCachedTextureInfo();
	//         JS::RootedValue jsret(cx);
	//         jsret = std_string_to_jsval(cx, ret);
	//         args.rval().set(jsret);
	//         return true;
	//     }

	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_getCachedTextureInfo : wrong number of arguments: %d, was expecting %d", argc, 0);
	//     return false;
}

// bool js_cocos2dx_TextureCache_addImage(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_addImage(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	//     bool ok = true;
	//     cocos2d::TextureCache *cobj = nullptr;

	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     JS::RootedObject obj(cx);
	//     obj.set(args.thisv().toObjectOrNull());
	//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
	//     cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : nullptr);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_addImage : Invalid Native Object");
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_addImage : Invalid Native Object");
	if (args.Length() == 2)
	{
		//         if (argc == 2)
		//         {
		//             cocos2d::Image *arg0 = nullptr;
		cocos2d::Image *image = nullptr;
		//             do
		//             {
		//                 if (args.get(0).isNull())
		//                 {
		//                     arg0 = nullptr;
		//                     break;
		//                 }
		if (args[0]->IsNull())
		{
			SE_REPORT_ERROR("js_cocos2dx_TextureCache_addImage : first argument should be non-null");
			return;
		}

		else if (!args[0]->IsObject())
		{
			SE_REPORT_ERROR("js_cocos2dx_TextureCache_addImage : first argument should be an object");
			return;
		}
		else
		{
			//                 js_proxy_t *jsProxy;
			//                 JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
			//                 jsProxy = jsb_get_js_proxy(tmpObj);
			//                 arg0 = (cocos2d::Image *)(jsProxy ? jsProxy->ptr : NULL);
			auto tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
			image = (cocos2d::Image *)(tmpObj->GetAlignedPointerFromInternalField(0));
			SE_PRECONDITION2(image, "js_cocos2dx_TextureCache_addImage : first argument should be a cocos2d::Image object");
			//                 JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
		}

		//             std::string arg1;
		//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
		std::string textureKey = JsbUtils::FromV8String(isolate, args[1]);

		//             cocos2d::Texture2D *ret = cobj->addImage(arg0, arg1);
		cocos2d::Texture2D *ret = cobj->addImage(image, textureKey);
		//             jsval jsret = JSVAL_NULL;
		//             if (ret)
		//             {
		//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
		//             }
		//             else
		//             {
		//                 jsret = JSVAL_NULL;
		//             };
		auto jsObject = JsbUtils::NativePtrToObject(ret);
		//             args.rval().set(jsret);
		args.GetReturnValue().Set(jsObject);
		return;
		//             return true;
		//         }
	}

	//         if (argc == 1)
	//         {
	if (args.Length() == 1)
	{
		//             std::string arg0;
		//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
		std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
		//             if (!ok)
		//             {
		//                 ok = true;
		//                 break;
		//             }
		//             cocos2d::Texture2D *ret = cobj->addImage(arg0);
		cocos2d::Texture2D *ret = cobj->addImage(texturePath);
		//             jsval jsret = JSVAL_NULL;
		//             if (ret)
		//             {
		//                 jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
		//             }
		//             else
		//             {
		//                 jsret = JSVAL_NULL;
		//             };
		auto jsObject = JsbUtils::NativePtrToObject(ret);
		//             args.rval().set(jsret);
		args.GetReturnValue().Set(jsObject);
		return;
		//             return true;
	}

	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_addImage : wrong number of arguments");
	SE_REPORT_ERROR("js_cocos2dx_TextureCache_addImage : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
	//     return false;
}

// bool js_cocos2dx_TextureCache_unbindImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_unbindImageAsync(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_unbindImageAsync : Invalid Native Object");
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_unbindImageAsync : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	std::string texturePath = JsbUtils::FromV8String(isolate, args[0]);
	cobj->unbindImageAsync(texturePath);
}

// bool js_cocos2dx_TextureCache_getTextureForKey(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_getTextureForKey(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_getTextureForKey : Invalid Native Object");
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getTextureForKey : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	std::string textureKey = JsbUtils::FromV8String(isolate, args[0]);
	cocos2d::Texture2D *ret = cobj->getTextureForKey(textureKey);
	auto jsObject = JsbUtils::NativePtrToObject(ret);
	args.GetReturnValue().Set(jsObject);
}

// bool js_cocos2dx_TextureCache_getTextureFilePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_getTextureFilePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_getTextureFilePath : Invalid Native Object");
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getTextureFilePath : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	cocos2d::Texture2D *texture = nullptr;
	if (args[0]->IsNull())
	{
		texture = nullptr;
	}
	else if (!args[0]->IsObject())
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getTextureFilePath : first argument should be an object");
		return;
	}
	else
	{
		v8::Local<v8::Object> tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
		texture = (cocos2d::Texture2D *)(tmpObj->GetAlignedPointerFromInternalField(0));
		SE_PRECONDITION2(texture, "js_cocos2dx_TextureCache_getTextureFilePath : first argument should be a cocos2d::Texture2D object");
	}
	std::string ret = cobj->getTextureFilePath(texture);
	args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
}

// bool js_cocos2dx_TextureCache_renameTextureWithKey(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_renameTextureWithKey(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_renameTextureWithKey : Invalid Native Object");
	if (args.Length() != 2)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_renameTextureWithKey : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
		return;
	}
	std::string oldKey = JsbUtils::FromV8String(isolate, args[0]);
	std::string newKey = JsbUtils::FromV8String(isolate, args[1]);
	cobj->renameTextureWithKey(oldKey, newKey);
}

// bool js_cocos2dx_TextureCache_removeUnusedTextures(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_removeUnusedTextures(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_removeUnusedTextures : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_removeUnusedTextures : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	cobj->removeUnusedTextures();
}

// bool js_cocos2dx_TextureCache_removeTexture(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_removeTexture(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_removeTexture : Invalid Native Object");
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_removeTexture : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	cocos2d::Texture2D *texture = nullptr;
	if (args[0]->IsNull())
	{
		texture = nullptr;
	}
	else if (!args[0]->IsObject())
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_removeTexture : first argument should be an object");
		return;
	}
	else
	{
		auto tmpObj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
		texture = (cocos2d::Texture2D *)(tmpObj->GetAlignedPointerFromInternalField(0));
		SE_PRECONDITION2(texture, "js_cocos2dx_TextureCache_removeTexture : first argument should be a cocos2d::Texture2D object");
	}
	cobj->removeTexture(texture);
}

// bool js_cocos2dx_TextureCache_waitForQuit(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_waitForQuit(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)args.This()->GetAlignedPointerFromInternalField(0);
	SE_PRECONDITION2(cobj, "js_cocos2dx_TextureCache_waitForQuit : Invalid Native Object");
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_waitForQuit : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}
	cobj->waitForQuit();
}
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_waitForQuit : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->waitForQuit();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_TextureCache_waitForQuit : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }

// bool js_cocos2dx_TextureCache_setETC1AlphaFileSuffix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_setETC1AlphaFileSuffix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     bool ok = true;
	//     if (argc == 1)
	//     {
	if (args.Length() != 1)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_setETC1AlphaFileSuffix : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
		return;
	}
	//         std::string arg0;
	//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
	std::string alphaFileSuffix = JsbUtils::FromV8String(args.GetIsolate(), args[0]);
	//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_setETC1AlphaFileSuffix : Error processing arguments");
	//         cocos2d::TextureCache::setETC1AlphaFileSuffix(arg0);
	cocos2d::TextureCache::setETC1AlphaFileSuffix(alphaFileSuffix);
	//         args.rval().setUndefined();
	//         return true;
	//     }
	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_setETC1AlphaFileSuffix : wrong number of arguments");
	//     return false;
}

// }

// bool js_cocos2dx_TextureCache_getETC1AlphaFileSuffix(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_getETC1AlphaFileSuffix(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     if (argc == 0)
	//     {
	if (args.Length() != 0)
	{
		SE_REPORT_ERROR("js_cocos2dx_TextureCache_getETC1AlphaFileSuffix : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
		return;
	}

	//         std::string ret = cocos2d::TextureCache::getETC1AlphaFileSuffix();
	std::string ret = cocos2d::TextureCache::getETC1AlphaFileSuffix();
	//         jsval jsret = JSVAL_NULL;
	//         jsret = std_string_to_jsval(cx, ret);
	auto jsString = JsbUtils::ToV8String(isolate, ret);
	args.GetReturnValue().Set(jsString);
	//         args.rval().set(jsret);
	//         return true;
	//     }
	//     JS_ReportError(cx, "js_cocos2dx_TextureCache_getETC1AlphaFileSuffix : wrong number of arguments");
	//     return false;
}

// bool js_cocos2dx_TextureCache_constructor(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_TextureCache_constructor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	v8::Isolate *isolate = args.GetIsolate();
	v8::HandleScope handleScope(isolate);
	//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
	//     bool ok = true;
	//     cocos2d::TextureCache *cobj = new (std::nothrow) cocos2d::TextureCache();
	cocos2d::TextureCache *cobj = new (std::nothrow) cocos2d::TextureCache();

	//     js_type_class_t *typeClass = js_get_type_from_native<cocos2d::TextureCache>(cobj);
	auto jsObject = JsbUtils::NativePtrToObject(cobj);
	args.GetReturnValue().Set(jsObject);
	CallCustomConstructor(args, jsObject);

	//     // link the native object with the javascript object
	//     JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::TextureCache"));
	//     args.rval().set(OBJECT_TO_JSVAL(jsobj));
	//     if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
	//         ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
	//     return true;
}

// void js_register_cocos2dx_TextureCache(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_TextureCache(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
	v8::HandleScope handleScope(isolate);
	//     jsb_cocos2d_TextureCache_class = (JSClass *)calloc(1, sizeof(JSClass));
	//     jsb_cocos2d_TextureCache_class->name = "TextureCache";
	//     jsb_cocos2d_TextureCache_class->addProperty = JS_PropertyStub;
	//     jsb_cocos2d_TextureCache_class->delProperty = JS_DeletePropertyStub;
	//     jsb_cocos2d_TextureCache_class->getProperty = JS_PropertyStub;
	//     jsb_cocos2d_TextureCache_class->setProperty = JS_StrictPropertyStub;
	//     jsb_cocos2d_TextureCache_class->enumerate = JS_EnumerateStub;
	//     jsb_cocos2d_TextureCache_class->resolve = JS_ResolveStub;
	//     jsb_cocos2d_TextureCache_class->convert = JS_ConvertStub;
	//     jsb_cocos2d_TextureCache_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
	auto tpl = v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_constructor);
	tpl->SetClassName(JsbUtils::ToV8String(isolate, "TextureCache"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	//     static JSPropertySpec properties[] = {
	//         JS_PS_END};

	//     static JSFunctionSpec funcs[] = {
	//         JS_FN("reloadTexture", js_cocos2dx_TextureCache_reloadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "reloadTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_reloadTexture));
	//         JS_FN("unbindAllImageAsync", js_cocos2dx_TextureCache_unbindAllImageAsync, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "unbindAllImageAsync", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_unbindAllImageAsync));
	//         JS_FN("removeTextureForKey", js_cocos2dx_TextureCache_removeTextureForKey, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "removeTextureForKey", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_removeTextureForKey));
	//         JS_FN("removeAllTextures", js_cocos2dx_TextureCache_removeAllTextures, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "removeAllTextures", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_removeAllTextures));
	//         JS_FN("addImageAsync", js_cocos2dx_TextureCache_addImageAsync, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "addImageAsync", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_addImageAsync));
	//         JS_FN("getDescription", js_cocos2dx_TextureCache_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "getDescription", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_getDescription));
	//         JS_FN("getCachedTextureInfo", js_cocos2dx_TextureCache_getCachedTextureInfo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "getCachedTextureInfo", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_getCachedTextureInfo));
	//         JS_FN("addImage", js_cocos2dx_TextureCache_addImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "addImage", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_addImage));
	//         JS_FN("unbindImageAsync", js_cocos2dx_TextureCache_unbindImageAsync, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "unbindImageAsync", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_unbindImageAsync));
	//         JS_FN("getTextureForKey", js_cocos2dx_TextureCache_getTextureForKey, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "getTextureForKey", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_getTextureForKey));
	//         JS_FN("getTextureFilePath", js_cocos2dx_TextureCache_getTextureFilePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "getTextureFilePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_getTextureFilePath));
	//         JS_FN("renameTextureWithKey", js_cocos2dx_TextureCache_renameTextureWithKey, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "renameTextureWithKey", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_renameTextureWithKey));
	//         JS_FN("removeUnusedTextures", js_cocos2dx_TextureCache_removeUnusedTextures, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "removeUnusedTextures", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_removeUnusedTextures));
	//         JS_FN("removeTexture", js_cocos2dx_TextureCache_removeTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "removeTexture", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_removeTexture));
	//         JS_FN("waitForQuit", js_cocos2dx_TextureCache_waitForQuit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->PrototypeTemplate()->Set(isolate, "waitForQuit", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_waitForQuit));

	//         JS_FS_END};

	//     static JSFunctionSpec st_funcs[] = {
	//         JS_FN("setETC1AlphaFileSuffix", js_cocos2dx_TextureCache_setETC1AlphaFileSuffix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->Set(isolate, "setETC1AlphaFileSuffix", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_setETC1AlphaFileSuffix));
	//         JS_FN("getETC1AlphaFileSuffix", js_cocos2dx_TextureCache_getETC1AlphaFileSuffix, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
	tpl->Set(isolate, "getETC1AlphaFileSuffix", v8::FunctionTemplate::New(isolate, js_cocos2dx_TextureCache_getETC1AlphaFileSuffix));
	//         JS_FS_END};

	//     jsb_cocos2d_TextureCache_prototype = JS_InitClass(
	//         cx, global,
	//         JS::NullPtr(),
	//         jsb_cocos2d_TextureCache_class,
	//         js_cocos2dx_TextureCache_constructor, 0, // constructor
	//         properties,
	//         funcs,
	//         NULL, // no static properties
	//         st_funcs);

	//     JS::RootedObject proto(cx, jsb_cocos2d_TextureCache_prototype);
	//     JS::RootedValue className(cx, std_string_to_jsval(cx, "TextureCache"));
	//     JS_SetProperty(cx, proto, "_className", className);
	tpl->PrototypeTemplate()->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "TextureCache"));
	//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
	tpl->PrototypeTemplate()->Set(isolate, "__nativeObj", v8::True(isolate));
	//     JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
	tpl->PrototypeTemplate()->Set(isolate, "__is_ref", v8::True(isolate));
	//     // add the proto and JSClass to the type->js info hash table
	//     jsb_register_class<cocos2d::TextureCache>(cx, jsb_cocos2d_TextureCache_class, proto, JS::NullPtr());
	JsbUtils::RegisterV8Class(typeid(cocos2d::TextureCache).name(), &tpl);
	JsbUtils::BindJsClass("TextureCache", global, tpl);
}
