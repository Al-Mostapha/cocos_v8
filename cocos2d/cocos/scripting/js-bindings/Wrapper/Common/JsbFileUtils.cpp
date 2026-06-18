#include "JsbFileUtils.hpp"
#include "JsbUtils.h"
#include "JsbCtor.hpp"
#include "ScriptEngine.hpp"
#include "platform/CCFileUtils.h"
#include "JsbConvert.hpp"

// JSClass *jsb_cocos2d_FileUtils_class;
// JSObject *jsb_cocos2d_FileUtils_prototype;

// bool js_cocos2dx_FileUtils_fullPathForFilename(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_fullPathForFilename(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_fullPathForFilename : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_fullPathForFilename : Invalid Native Object");

  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_fullPathForFilename : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string fullPath = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_fullPathForFilename : Error processing arguments");
  //         std::string ret = cobj->fullPathForFilename(arg0);
  std::string ret = cFileUtils->fullPathForFilename(fullPath);
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_fullPathForFilename : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getStringFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getStringFromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getStringFromFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getStringFromFile : Invalid Native Object");
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    //             std::function<void(std::string)> arg1;
    std::function<void(std::string)> callback;
    if (args[1]->IsFunction())
    {
      v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(args[1]);
      callback = JsbConvert::FromJsFunc<void, std::string>(isolate, func, args.This());
    }
    else
    {
      callback = nullptr;
    }

    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](std::string larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = std_string_to_jsval(cx, larg0);
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
    //             cobj->getStringFromFile(arg0, arg1);
    cFileUtils->getStringFromFile(filename, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    std::string ret = cFileUtils->getStringFromFile(filename);
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
    return;
  }
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             std::string ret = cobj->getStringFromFile(arg0);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = std_string_to_jsval(cx, ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getStringFromFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_getStringFromFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_removeFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_removeFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_removeFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_removeFile : Invalid Native Object");

  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);

    //             std::function<void(bool)> arg1;
    std::function<void(bool)> callback;

    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
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
    if (args[1]->IsFunction())
    {
      v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(args[1]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, func, args.This());
    }
    else
    {
      callback = nullptr;
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_removeFile : argument 1 is not a function");
      return;
    }
    //             cobj->removeFile(arg0, arg1);
    cFileUtils->removeFile(filename, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    bool ret = cFileUtils->removeFile(filename);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    return;
  }
  //             std::string arg0;
  //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //             if (!ok)
  //             {
  //                 ok = true;
  //                 break;
  //             }
  //             bool ret = cobj->removeFile(arg0);
  //             jsval jsret = JSVAL_NULL;
  //             jsret = BOOLEAN_TO_JSVAL(ret);
  //             args.rval().set(jsret);
  //             return true;
  //         }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_removeFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_removeFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_isAbsolutePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_isAbsolutePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isAbsolutePath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_isAbsolutePath : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_isAbsolutePath : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string path = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_isAbsolutePath : Error processing arguments");
  //         bool ret = cobj->isAbsolutePath(arg0);
  bool ret = cFileUtils->isAbsolutePath(path);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_isAbsolutePath : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_renameFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_renameFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_renameFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_renameFile : Invalid Native Object");
  //     do
  //     {
  //         if (argc == 4)
  //         {
  if (args.Length() == 4)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filePath = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string oldName = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::string arg2;
    //             ok &= jsval_to_std_string(cx, args.get(2), &arg2);
    std::string newName = JsbUtils::FromV8String(isolate, args[2]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg3;
    std::function<void(bool)> callback;
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(3)) == JSTYPE_FUNCTION)
    //                 {
    if (args[3]->IsFunction())
    {
      v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(args[3]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, func, args.This());
    }
    else
    {
      callback = nullptr;
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_renameFile : argument 3 is not a function");
      return;
    }
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(3), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
    //                         JS::RootedValue rval(cx);
    //                         bool succeed = func->invoke(1, &largv[0], &rval);
    //                         if (!succeed && JS_IsExceptionPending(cx))
    //                         {
    //                             JS_ReportPendingException(cx);
    //                         }
    //                     };
    //                     arg3 = lambda;
    //                 }
    //                 else
    //                 {
    //                     arg3 = nullptr;
    //                 }
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->renameFile(arg0, arg1, arg2, arg3);
    cFileUtils->renameFile(filePath, oldName, newName, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //     do
  //     {
  //         if (argc == 3)
  //         {
  if (args.Length() == 3)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filePath = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string oldName = JsbUtils::FromV8String(isolate, args[1]);

    if (args[2]->IsFunction())
    {
      //             std::function<void(bool)> arg2;
      std::function<void(bool)> callback;

      //   if (JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
      //   {
      //       JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
      //       std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(2), args.thisv()));
      //       auto lambda = [=](bool larg0) -> void
      //       {
      //           JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
      //           jsval largv[1];
      //           largv[0] = BOOLEAN_TO_JSVAL(larg0);
      //           JS::RootedValue rval(cx);
      //           bool succeed = func->invoke(1, &largv[0], &rval);
      //           if (!succeed && JS_IsExceptionPending(cx))
      //           {
      //               JS_ReportPendingException(cx);
      //           }
      //       };
      //       arg2 = lambda;
      //   }
      //   else
      //   {
      //       arg2 = nullptr;
      //   }
      auto jsFunc = v8::Local<v8::Function>::Cast(args[2]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());

      //             cobj->renameFile(arg0, arg1, arg2);
      cFileUtils->renameFile(filePath, oldName, callback);
      //             args.rval().setUndefined();
      //             return true;
      return;
      //         }
    }
    else if (args[2]->IsString())
    {

      std::string newName = JsbUtils::FromV8String(isolate, args[2]);
      //             if (!ok)
      //             {
      //                 ok = true;
      //                 break;
      //             }
      //             bool ret = cobj->renameFile(arg0, arg1, arg2);
      bool ret = cFileUtils->renameFile(filePath, oldName, newName);
      args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
      //             jsval jsret = JSVAL_NULL;
      //             jsret = BOOLEAN_TO_JSVAL(ret);
      //             args.rval().set(jsret);
      //             return true;
      return;
    }
  }

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    std::string oldFolderPath = JsbUtils::FromV8String(isolate, args[0]);
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    std::string newFolderPath = JsbUtils::FromV8String(isolate, args[1]);
    //             bool ret = cobj->renameFile(arg0, arg1);
    bool ret = cFileUtils->renameFile(oldFolderPath, newFolderPath);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_renameFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_renameFile : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getDefaultResourceRootPath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getDefaultResourceRootPath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getDefaultResourceRootPath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getDefaultResourceRootPath : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getDefaultResourceRootPath : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  const std::string ret = cFileUtils->getDefaultResourceRootPath();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()).ToLocalChecked());

  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getDefaultResourceRootPath : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  cFileUtils->loadFilenameLookupDictionaryFromFile(filename);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile : Error processing arguments");
  //         cobj->loadFilenameLookupDictionaryFromFile(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_isPopupNotify(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_isPopupNotify(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isPopupNotify : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_isPopupNotify : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_isPopupNotify : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         bool ret = cobj->isPopupNotify();
  bool ret = cFileUtils->isPopupNotify();
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_isPopupNotify : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getValueVectorFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getValueVectorFromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueVectorFromFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getValueVectorFromFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getValueVectorFromFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueVectorFromFile : Error processing arguments");
  //         cocos2d::ValueVector ret = cobj->getValueVectorFromFile(arg0);
  cocos2d::ValueVector ret = cFileUtils->getValueVectorFromFile(filename);
  //         JS::RootedValue jsret(cx);
  //         jsret = ccvaluevector_to_jsval(cx, ret);
  CCASSERT(false, "ccvaluevector_to_jsval is not implemented yet");
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueVectorFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getSearchPaths(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSearchPaths : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getSearchPaths : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getSearchPaths : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         std::vector<std::string> ret = cobj->getSearchPaths();
  std::vector<std::string> ret = cFileUtils->getSearchPaths();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_vector_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  v8::Local<v8::Array> jsret = v8::Array::New(isolate, ret.size());
  for (size_t i = 0; i < ret.size(); ++i)
  {
    jsret->Set(isolate->GetCurrentContext(), static_cast<uint32_t>(i), JsbUtils::ToV8String(isolate, ret[i])).Check();
  }
  //         return true;
  //     }
  args.GetReturnValue().Set(jsret);
  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_writeToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_writeToFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeToFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_writeToFile : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeToFile : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         cocos2d::ValueMap arg0;
  cocos2d::ValueMap dict;
  //         std::string arg1;
  std::string filename = JsbUtils::FromV8String(isolate, args[1]);
  if (!args[0]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeToFile : argument 0 is not an object");
    return;
  }

  v8::Local<v8::Object> obj = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Array> propertyNames = obj->GetOwnPropertyNames(isolate->GetCurrentContext()).ToLocalChecked();
  for (uint32_t i = 0; i < propertyNames->Length(); ++i)
  {
    v8::Local<v8::Value> key = propertyNames->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
    v8::Local<v8::Value> value = obj->Get(isolate->GetCurrentContext(), key).ToLocalChecked();
    std::string strKey = JsbUtils::FromV8String(isolate, key);
    if (value->IsString())
    {
      dict[strKey] = cocos2d::Value(JsbUtils::FromV8String(isolate, value));
    }
    else if (value->IsNumber())
    {
      dict[strKey] = cocos2d::Value(value->NumberValue(isolate->GetCurrentContext()).ToChecked());
    }
    else if (value->IsBoolean())
    {
      dict[strKey] = cocos2d::Value(value->BooleanValue(isolate));
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeToFile : unsupported value type for key %s", strKey.c_str());
      return;
    }
  }
  //         ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_writeToFile : Error processing arguments");
  //         bool ret = cobj->writeToFile(arg0, arg1);
  bool ret = cFileUtils->writeToFile(dict, filename);
  //         JS::RootedValue jsret(cx);
  //         jsret = BOOLEAN_TO_JSVAL(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeToFile : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getOriginalSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getOriginalSearchPaths(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getOriginalSearchPaths : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getOriginalSearchPaths : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getOriginalSearchPaths : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         std::vector<std::string> ret = cobj->getOriginalSearchPaths();
  std::vector<std::string> ret = cFileUtils->getOriginalSearchPaths();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_vector_string_to_jsval(cx, ret);
  v8::Local<v8::Array> jsret = v8::Array::New(isolate, ret.size());
  for (size_t i = 0; i < ret.size(); ++i)
  {
    jsret->Set(isolate->GetCurrentContext(), static_cast<uint32_t>(i), JsbUtils::ToV8String(isolate, ret[i])).Check();
  }
  args.GetReturnValue().Set(jsret);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getOriginalSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getNewFilename(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getNewFilename(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getNewFilename : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getNewFilename : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getNewFilename : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getNewFilename : Error processing arguments");
  //         std::string ret = cobj->getNewFilename(arg0);
  std::string ret = cFileUtils->getNewFilename(filename);
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, ret));
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getNewFilename : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_listFiles(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_listFiles(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_listFiles : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_listFiles : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_listFiles : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string dirPath = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_listFiles : Error processing arguments");
  //         std::vector<std::string> ret = cobj->listFiles(arg0);
  std::vector<std::string> ret = cFileUtils->listFiles(dirPath);
  v8::Local<v8::Array> jsret = v8::Array::New(isolate, ret.size());
  for (size_t i = 0; i < ret.size(); ++i)
  {
    jsret->Set(isolate->GetCurrentContext(), static_cast<uint32_t>(i), JsbUtils::ToV8String(isolate, ret[i])).Check();
  }
  args.GetReturnValue().Set(jsret);
  //         JS::RootedValue jsret(cx);
  //         jsret = std_vector_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_listFiles : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getValueMapFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getValueMapFromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueMapFromFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, false, "js_cocos2dx_FileUtils_getValueMapFromFile : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getValueMapFromFile : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueMapFromFile : Error processing arguments");
  SE_PRECONDITION2(true, "js_cocos2dx_FileUtils_getValueMapFromFile : Error processing arguments");
  //         cocos2d::ValueMap ret = cobj->getValueMapFromFile(arg0);
  cocos2d::ValueMap ret = cFileUtils->getValueMapFromFile(filename);
  auto jsret = JsbUtils::ccvaluemap_to_jsval(isolate, ret);
  args.GetReturnValue().Set(jsret);
  //         JS::RootedValue jsret(cx);
  //         jsret = ccvaluemap_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueMapFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getFileSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getFileSize(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getFileSize : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getFileSize : Invalid Native Object");

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);

    //             std::function<void(long)> arg1;
    std::function<void(long)> callback;

    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    if (args[1]->IsFunction())
    {
      v8::Local<v8::Function> jsFunc = v8::Local<v8::Function>::Cast(args[1]);
      callback = JsbConvert::FromJsFunc<void, long>(isolate, jsFunc, args.This());
    }
    else
    {
      callback = nullptr;
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_getFileSize : argument 1 is not a function");
      return;
    }
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](long larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = long_to_jsval(cx, larg0);
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

    //             cobj->getFileSize(arg0, arg1);
    cFileUtils->getFileSize(filename, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  // if (argc == 1)
  // {
  if (args.Length() == 1)
  {
    //     std::string arg0;
    //     ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    //     if (!ok)
    //     {
    //         ok = true;
    //         break;
    //     }
    //     long ret = cobj->getFileSize(arg0);
    long ret = cFileUtils->getFileSize(filename);
    args.GetReturnValue().Set(v8::Number::New(isolate, ret));
    //     jsval jsret = JSVAL_NULL;
    //     jsret = long_to_jsval(cx, ret);
    //     args.rval().set(jsret);
    //     return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getFileSize : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_getFileSize : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getValueMapFromData(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getValueMapFromData(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueMapFromData : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getValueMapFromData : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getValueMapFromData : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         const char *arg0 = nullptr;
  //         int arg1 = 0;
  //         std::string arg0_tmp;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
  const char *arg0 = nullptr;
  std::string arg0_tmp = JsbUtils::FromV8String(isolate, args[0]);

  arg0 = arg0_tmp.c_str();
  //         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
  int arg1 = args[1]->Int32Value(isolate->GetCurrentContext()).ToChecked();
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueMapFromData : Error processing arguments");
  //         cocos2d::ValueMap ret = cobj->getValueMapFromData(arg0, arg1);
  cocos2d::ValueMap ret = cFileUtils->getValueMapFromData(arg0, arg1);
  auto jsret = JsbUtils::ccvaluemap_to_jsval(isolate, ret);
  //         JS::RootedValue jsret(cx);
  //         jsret = ccvaluemap_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueMapFromData : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_removeDirectory(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_removeDirectory(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_removeDirectory : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_removeDirectory : Invalid Native Object");

  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string dirPath = JsbUtils::FromV8String(isolate, args[0]);

    //             std::function<void(bool)> arg1;
    std::function<void(bool)> callback;
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
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
    if (!args[1]->IsFunction())
    {
      callback = nullptr;
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_removeDirectory : argument 1 is not a function");
      return;
    }
    auto jsFunc = v8::Local<v8::Function>::Cast(args[1]);
    callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());

    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->removeDirectory(arg0, arg1);
    cFileUtils->removeDirectory(dirPath, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //     do
  //     {
  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string dirPath = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->removeDirectory(arg0);
    bool ret = cFileUtils->removeDirectory(dirPath);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
    return;
  }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_removeDirectory : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_removeDirectory : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_setSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setSearchPaths(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setSearchPaths : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_setSearchPaths : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchPaths : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::vector<std::string> arg0;
  //         ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
  std::vector<std::string> searchPaths;
  if (args[0]->IsArray())
  {
    v8::Local<v8::Array> arr = v8::Local<v8::Array>::Cast(args[0]);
    for (uint32_t i = 0; i < arr->Length(); ++i)
    {
      v8::Local<v8::Value> val = arr->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
      if (val->IsString())
      {
        searchPaths.push_back(JsbUtils::FromV8String(isolate, val));
      }
      else
      {
        SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchPaths : array element is not a string");
        return;
      }
    }
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchPaths : argument is not an array");
    return;
  }

  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setSearchPaths : Error processing arguments");
  //         cobj->setSearchPaths(arg0);
  cFileUtils->setSearchPaths(searchPaths);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_setSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_writeStringToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_writeStringToFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeStringToFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_writeStringToFile : Invalid Native Object");

  if (args.Length() == 3)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string filename = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string content = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg2;
    std::function<void(bool)> callback;
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(2), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
    //                         JS::RootedValue rval(cx);
    //                         bool succeed = func->invoke(1, &largv[0], &rval);
    //                         if (!succeed && JS_IsExceptionPending(cx))
    //                         {
    //                             JS_ReportPendingException(cx);
    //                         }
    //                     };
    //                     arg2 = lambda;
    //                 }
    //                 else
    //                 {
    //                     arg2 = nullptr;
    //                 }
    if (!args[2]->IsFunction())
    {
      callback = nullptr;
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeStringToFile : argument 2 is not a function");
      return;
    }

    auto jsFunc = v8::Local<v8::Function>::Cast(args[2]);
    callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->writeStringToFile(arg0, arg1, arg2);
    cFileUtils->writeStringToFile(filename, content, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

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
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string content = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->writeStringToFile(arg0, arg1);
    bool ret = cFileUtils->writeStringToFile(filename, content);
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             return true;
  }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeStringToFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeStringToFile : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 2, 3);
  //     return false;
}

// bool js_cocos2dx_FileUtils_setSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setSearchResolutionsOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::vector<std::string> arg0;
  //         ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
  std::vector<std::string> resolutionsOrder;
  if (args[0]->IsArray())
  {
    v8::Local<v8::Array> arr = v8::Local<v8::Array>::Cast(args[0]);
    for (uint32_t i = 0; i < arr->Length(); ++i)
    {
      v8::Local<v8::Value> val = arr->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
      if (val->IsString())
      {
        resolutionsOrder.push_back(JsbUtils::FromV8String(isolate, val));
      }
      else
      {
        SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchResolutionsOrder : array element is not a string");
        return;
      }
    }
  }
  else
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setSearchResolutionsOrder : argument is not an array");
    return;
  }
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : Error processing arguments");
  //         cobj->setSearchResolutionsOrder(arg0);
  cFileUtils->setSearchResolutionsOrder(resolutionsOrder);
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_addSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_addSearchResolutionsOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() == 1)
  {
    std::string order = JsbUtils::FromV8String(isolate, args[0]);
    cFileUtils->addSearchResolutionsOrder(order);
    return;
  }
  else if (args.Length() == 2)
  {
    std::string order = JsbUtils::FromV8String(isolate, args[0]);
    bool front = args[1]->BooleanValue(isolate);
    cFileUtils->addSearchResolutionsOrder(order, front);
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_addSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_addSearchPath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_addSearchPath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_addSearchPath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_addSearchPath : Invalid Native Object");
  //     if (argc == 1)
  //     {
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_addSearchPath : Error processing arguments");
  //         cobj->addSearchPath(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  if (args.Length() == 1)
  {
    std::string path = JsbUtils::FromV8String(isolate, args[0]);
    cFileUtils->addSearchPath(path);
    return;
  }
  //     if (argc == 2)
  //     {
  //         std::string arg0;
  //         bool arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         arg1 = JS::ToBoolean(args.get(1));
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_addSearchPath : Error processing arguments");
  //         cobj->addSearchPath(arg0, arg1);
  //         args.rval().setUndefined();
  //         return true;
  else if (args.Length() == 2)
  {
    std::string path = JsbUtils::FromV8String(isolate, args[0]);
    bool front = args[1]->BooleanValue(isolate);
    cFileUtils->addSearchPath(path, front);
    return;
  }
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_addSearchPath : wrong number of arguments: %d, was expecting %d", argc, 1);
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_addSearchPath : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_writeValueVectorToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_writeValueVectorToFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeValueVectorToFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_writeValueVectorToFile : Invalid Native Object");

  //         if (argc == 3)
  //         {
  if (args.Length() == 3)
  {
    //             cocos2d::ValueVector arg0;
    //             ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
    cocos2d::ValueVector valueVector;
    bool ok = JsbUtils::jsval_to_ccvaluevector(isolate, args[0], &valueVector);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    if (!ok)
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueVectorToFile : Error processing argument 0");
      return;
    }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string filename = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg2;
    std::function<void(bool)> callback;
    if (args[2]->IsFunction())
    {
      auto jsFunc = v8::Local<v8::Function>::Cast(args[2]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueVectorToFile : argument 2 is not a function");
      return;
    }
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(2), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
    //                         JS::RootedValue rval(cx);
    //                         bool succeed = func->invoke(1, &largv[0], &rval);
    //                         if (!succeed && JS_IsExceptionPending(cx))
    //                         {
    //                             JS_ReportPendingException(cx);
    //                         }
    //                     };
    //                     arg2 = lambda;
    //                 }
    //                 else
    //                 {
    //                     arg2 = nullptr;
    //                 }
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->writeValueVectorToFile(arg0, arg1, arg2);
    cFileUtils->writeValueVectorToFile(valueVector, filename, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::ValueVector arg0;
    cocos2d::ValueVector valueVector;
    //             ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
    bool ok = JsbUtils::jsval_to_ccvaluevector(isolate, args[0], &valueVector);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    if (!ok)
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueVectorToFile : Error processing argument 0");
      return;
    }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string filename = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->writeValueVectorToFile(arg0, arg1);
    bool ret = cFileUtils->writeValueVectorToFile(valueVector, filename);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
  }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeValueVectorToFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueVectorToFile : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 2, 3);
  //     return false;
}

// bool js_cocos2dx_FileUtils_isFileExist(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_isFileExist(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isFileExist : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_isFileExist : Invalid Native Object");

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
    if (args[1]->IsFunction())
    {
      auto jsFunc = v8::Local<v8::Function>::Cast(args[1]);
      std::function<void(bool)> callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
      cFileUtils->isFileExist(filename, callback);
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_isFileExist : argument 1 is not a function");
      return;
    }
    //             std::function<void(bool)> arg1;
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
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
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->isFileExist(arg0, arg1);
    //             args.rval().setUndefined();
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
    //             bool ret = cobj->isFileExist(arg0);
    bool ret = cFileUtils->isFileExist(filename);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
    return;
  }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_isFileExist : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_isFileExist : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_purgeCachedEntries(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_purgeCachedEntries(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_purgeCachedEntries : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_purgeCachedEntries : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_purgeCachedEntries : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  cFileUtils->purgeCachedEntries();
  return;
  //         cobj->purgeCachedEntries();
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_purgeCachedEntries : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_fullPathFromRelativeFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_fullPathFromRelativeFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_fullPathFromRelativeFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_fullPathFromRelativeFile : Invalid Native Object");

  //     if (argc == 2)
  //     {
  if (args.Length() == 2)
  {
    std::string relativePath = JsbUtils::FromV8String(isolate, args[0]);
    std::string relatedFile = JsbUtils::FromV8String(isolate, args[1]);
    std::string fullPath = cFileUtils->fullPathFromRelativeFile(relativePath, relatedFile);
    args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, fullPath));
    return;
  }
  //         std::string arg0;
  //         std::string arg1;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_fullPathFromRelativeFile : Error processing arguments");
  //         std::string ret = cobj->fullPathFromRelativeFile(arg0, arg1);
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_fullPathFromRelativeFile : wrong number of arguments: %d, was expecting %d", argc, 2);
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_fullPathFromRelativeFile : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getSuitableFOpen(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getSuitableFOpen(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSuitableFOpen : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getSuitableFOpen : Invalid Native Object");

  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getSuitableFOpen : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getSuitableFOpen : Error processing arguments");
  //         std::string ret = cobj->getSuitableFOpen(arg0);
  std::string suitableFOpen = cFileUtils->getSuitableFOpen(filename);
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, suitableFOpen));

  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSuitableFOpen : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_writeValueMapToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_writeValueMapToFile(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeValueMapToFile : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_writeValueMapToFile : Invalid Native Object");

  if (args.Length() == 3)
  {
    //             cocos2d::ValueMap arg0;
    //             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
    cocos2d::ValueMap valueMap;
    bool ok = JsbUtils::jsval_to_ccvaluemap(isolate, args[0], &valueMap);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    if (!ok)
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueMapToFile : Error processing argument 0");
      return;
    }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string filename = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg2;
    std::function<void(bool)> callback;
    if (args[2]->IsFunction())
    {
      auto jsFunc = v8::Local<v8::Function>::Cast(args[2]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueMapToFile : argument 2 is not a function");
      return;
    }
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(2), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
    //                         JS::RootedValue rval(cx);
    //                         bool succeed = func->invoke(1, &largv[0], &rval);
    //                         if (!succeed && JS_IsExceptionPending(cx))
    //                         {
    //                             JS_ReportPendingException(cx);
    //                         }
    //                     };
    //                     arg2 = lambda;
    //                 }
    //                 else
    //                 {
    //                     arg2 = nullptr;
    //                 }
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->writeValueMapToFile(arg0, arg1, arg2);
    cFileUtils->writeValueMapToFile(valueMap, filename, callback);
    //             args.rval().setUndefined();
    //             return true;
  }

  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             cocos2d::ValueMap arg0;
    cocos2d::ValueMap valueMap;
    //             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
    bool ok = JsbUtils::jsval_to_ccvaluemap(isolate, args[0], &valueMap);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    if (!ok)
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueMapToFile : Error processing argument 0");
      return;
    }
    //             std::string arg1;
    //             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
    std::string filename = JsbUtils::FromV8String(isolate, args[1]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->writeValueMapToFile(arg0, arg1);
    bool ret = cFileUtils->writeValueMapToFile(valueMap, filename);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
  }

  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeValueMapToFile : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_writeValueMapToFile : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 2, 3);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getFileExtension(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getFileExtension(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getFileExtension : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getFileExtension : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getFileExtension : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  std::string filename = JsbUtils::FromV8String(isolate, args[0]);
  std::string extension = cFileUtils->getFileExtension(filename);
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, extension));
  return;
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getFileExtension : Error processing arguments");
  //         std::string ret = cobj->getFileExtension(arg0);
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getFileExtension : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_setWritablePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setWritablePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setWritablePath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_setWritablePath : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setWritablePath : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  std::string writablePath = JsbUtils::FromV8String(isolate, args[0]);
  cFileUtils->setWritablePath(writablePath);
  return;
}

// bool js_cocos2dx_FileUtils_setPopupNotify(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setPopupNotify(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setPopupNotify : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_setPopupNotify : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setPopupNotify : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         bool arg0;
  //         arg0 = JS::ToBoolean(args.get(0));
  bool popupNotify = args[0]->BooleanValue(isolate);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setPopupNotify : Error processing arguments");
  //         cobj->setPopupNotify(arg0);
  cFileUtils->setPopupNotify(popupNotify);
  return;
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_setPopupNotify : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_isDirectoryExist(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_isDirectoryExist(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isDirectoryExist : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_isDirectoryExist : Invalid Native Object");
  //     do
  //     {
  //         if (argc == 2)
  //         {
  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string directory = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg1;
    std::function<void(bool)> callback;
    if (args[1]->IsFunction())
    {
      auto jsFunc = v8::Local<v8::Function>::Cast(args[1]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_isDirectoryExist : argument 1 is not a function");
      return;
    }
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
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
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->isDirectoryExist(arg0, arg1);
    cFileUtils->isDirectoryExist(directory, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  //     } while (0);

  //     do
  //     {
  //         if (argc == 1)
  //         {
  if (args.Length() == 1)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string directory = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->isDirectoryExist(arg0);
    bool ret = cFileUtils->isDirectoryExist(directory);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
    return;
  }
  //     } while (0);

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_isDirectoryExist : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_isDirectoryExist : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_setDefaultResourceRootPath(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setDefaultResourceRootPath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : Invalid Native Object");
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setDefaultResourceRootPath : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string rootPath = JsbUtils::FromV8String(isolate, args[0]);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : Error processing arguments");
  //         cobj->setDefaultResourceRootPath(arg0);
  cFileUtils->setDefaultResourceRootPath(rootPath);
  return;
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : wrong number of arguments: %d, was expecting %d", argc, 1);
  //     return false;
}

// bool js_cocos2dx_FileUtils_getSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getSearchResolutionsOrder(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSearchResolutionsOrder : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getSearchResolutionsOrder : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  //         std::vector<std::string> ret = cobj->getSearchResolutionsOrder();
  std::vector<std::string> searchResolutionsOrder = cFileUtils->getSearchResolutionsOrder();
  v8::Local<v8::Array> jsArray = v8::Array::New(isolate, static_cast<int>(searchResolutionsOrder.size()));
  for (size_t i = 0; i < searchResolutionsOrder.size(); ++i)
  {
    jsArray->Set(isolate->GetCurrentContext(), static_cast<uint32_t>(i), JsbUtils::ToV8String(isolate, searchResolutionsOrder[i])).Check();
  }
  args.GetReturnValue().Set(jsArray);
  //         JS::RootedValue jsret(cx);
  //         jsret = std_vector_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_createDirectory(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_createDirectory(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     bool ok = true;
  //     cocos2d::FileUtils *cobj = nullptr;

  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx);
  //     obj.set(args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_createDirectory : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_createDirectory : Invalid Native Object");

  if (args.Length() == 2)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string directory = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             std::function<void(bool)> arg1;
    std::function<void(bool)> callback;
    if (args[1]->IsFunction())
    {
      auto jsFunc = v8::Local<v8::Function>::Cast(args[1]);
      callback = JsbConvert::FromJsFunc<void, bool>(isolate, jsFunc, args.This());
    }
    else
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_createDirectory : argument 1 is not a function");
      return;
    }
    //             do
    //             {
    //                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
    //                 {
    //                     JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
    //                     std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
    //                     auto lambda = [=](bool larg0) -> void
    //                     {
    //                         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
    //                         jsval largv[1];
    //                         largv[0] = BOOLEAN_TO_JSVAL(larg0);
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
    //             } while (0);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             cobj->createDirectory(arg0, arg1);
    cFileUtils->createDirectory(directory, callback);
    //             args.rval().setUndefined();
    //             return true;
    return;
  }

  if (args.Length() == 1)
  {
    //             std::string arg0;
    //             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    std::string directory = JsbUtils::FromV8String(isolate, args[0]);
    //             if (!ok)
    //             {
    //                 ok = true;
    //                 break;
    //             }
    //             bool ret = cobj->createDirectory(arg0);
    bool ret = cFileUtils->createDirectory(directory);
    args.GetReturnValue().Set(v8::Boolean::New(isolate, ret));
    //             jsval jsret = JSVAL_NULL;
    //             jsret = BOOLEAN_TO_JSVAL(ret);
    //             args.rval().set(jsret);
    //             return true;
    return;
  }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_createDirectory : wrong number of arguments");
  SE_REPORT_ERROR("js_cocos2dx_FileUtils_createDirectory : wrong number of arguments: %d, was expecting %d or %d", args.Length(), 1, 2);
  //     return false;
}

void js_cocos2dx_FileUtils_getWritablePath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  //     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getWritablePath : Invalid Native Object");
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_getWritablePath : Invalid Native Object");
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getWritablePath : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }
  std::string writablePath = cFileUtils->getWritablePath();
  args.GetReturnValue().Set(JsbUtils::ToV8String(isolate, writablePath));
  //         std::string ret = cobj->getWritablePath();
  //         JS::RootedValue jsret(cx);
  //         jsret = std_string_to_jsval(cx, ret);
  //         args.rval().set(jsret);
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getWritablePath : wrong number of arguments: %d, was expecting %d", argc, 0);
  //     return false;
}

// bool js_cocos2dx_FileUtils_listFilesRecursively(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_listFilesRecursively(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
  //     js_proxy_t *proxy = jsb_get_js_proxy(obj);
  //     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
  cocos2d::FileUtils *cFileUtils = (cocos2d::FileUtils *)args.This()->GetAlignedPointerFromInternalField(0);
  SE_PRECONDITION2(cFileUtils, "js_cocos2dx_FileUtils_listFilesRecursively : Invalid Native Object");
  //     if (argc == 2)
  //     {
  if (args.Length() != 2)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_listFilesRecursively : wrong number of arguments: %d, was expecting %d", args.Length(), 2);
    return;
  }
  //         std::string arg0;
  //         std::vector<std::string> *arg1 = nullptr;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
  std::string path = JsbUtils::FromV8String(isolate, args[0]);
  std::vector<std::string> files;
  //         do
  //         {
  //             if (args.get(1).isNull())
  //             {
  //                 arg1 = nullptr;
  //                 break;
  //             }
  if (args[1]->IsNull())
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_listFilesRecursively : argument 1 is null");
    return;
  }
  //             if (!args.get(1).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  if (!args[1]->IsObject())
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_listFilesRecursively : argument 1 is not an object");
    return;
  }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg1 = (std::vector<std::string> *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_listFilesRecursively : Error processing arguments");
  //         cobj->listFilesRecursively(arg0, arg1);
  cFileUtils->listFilesRecursively(path, &files);
  auto arrayParam = args[1].As<v8::Array>();
  for (size_t i = 0; i < files.size(); ++i)
  {
    arrayParam->Set(isolate->GetCurrentContext(), static_cast<uint32_t>(i), JsbUtils::ToV8String(isolate, files[i])).Check();
  }
  //         args.rval().setUndefined();
  //         return true;
  //     }

  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_listFilesRecursively : wrong number of arguments: %d, was expecting %d", argc, 2);
  //     return false;
}

// bool js_cocos2dx_FileUtils_setDelegate(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_setDelegate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     bool ok = true;
  //     if (argc == 1)
  //     {
  if (args.Length() != 1)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_setDelegate : wrong number of arguments: %d, was expecting %d", args.Length(), 1);
    return;
  }
  //         cocos2d::FileUtils *arg0 = nullptr;
  cocos2d::FileUtils *delegate = nullptr;
  //         do
  //         {
  //             if (args.get(0).isNull())
  //             {
  //                 arg0 = nullptr;
  //                 break;
  //             }
  if (args[0]->IsNull())
  {
    delegate = nullptr;
  }
  else
  {
    if (!args[0]->IsObject())
    {
      SE_REPORT_ERROR("js_cocos2dx_FileUtils_setDelegate : argument 0 is not an object");
      return;
    }
    v8::Local<v8::Object> obj = args[0].As<v8::Object>();
    delegate = (cocos2d::FileUtils *)obj->GetAlignedPointerFromInternalField(0);
    SE_PRECONDITION2(delegate, "js_cocos2dx_FileUtils_setDelegate : Invalid Native Object");
  }
  cocos2d::FileUtils::setDelegate(delegate);
  //             if (!args.get(0).isObject())
  //             {
  //                 ok = false;
  //                 break;
  //             }
  //             js_proxy_t *jsProxy;
  //             JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
  //             jsProxy = jsb_get_js_proxy(tmpObj);
  //             arg0 = (cocos2d::FileUtils *)(jsProxy ? jsProxy->ptr : NULL);
  //             JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
  //         } while (0);
  //         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setDelegate : Error processing arguments");
  //         cocos2d::FileUtils::setDelegate(arg0);
  //         args.rval().setUndefined();
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_setDelegate : wrong number of arguments");
  //     return false;
}

// bool js_cocos2dx_FileUtils_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
void js_cocos2dx_FileUtils_getInstance(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::HandleScope handleScope(isolate);
  //     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  //     if (argc == 0)
  //     {
  if (args.Length() != 0)
  {
    SE_REPORT_ERROR("js_cocos2dx_FileUtils_getInstance : wrong number of arguments: %d, was expecting %d", args.Length(), 0);
    return;
  }

  //         cocos2d::FileUtils *ret = cocos2d::FileUtils::getInstance();
  cocos2d::FileUtils *ret = cocos2d::FileUtils::getInstance();
  //         jsval jsret = JSVAL_NULL;
  //         if (ret)
  //         {
  //             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::FileUtils>(cx, (cocos2d::FileUtils *)ret));
  //         }
  //         else
  //         {
  //             jsret = JSVAL_NULL;
  //         };
  auto jsret = JsbUtils::NativePtrToObject(ret);
  //         args.rval().set(jsret);
  args.GetReturnValue().Set(jsret);
  //         return true;
  //     }
  //     JS_ReportError(cx, "js_cocos2dx_FileUtils_getInstance : wrong number of arguments");
  //     return false;
}

// void js_register_cocos2dx_FileUtils(JSContext *cx, JS::HandleObject global)
// {
void js_register_cocos2dx_FileUtils(v8::Isolate *isolate, v8::Local<v8::Object> global)
{
  //     jsb_cocos2d_FileUtils_class = (JSClass *)calloc(1, sizeof(JSClass));
  //     jsb_cocos2d_FileUtils_class->name = "FileUtils";
  //     jsb_cocos2d_FileUtils_class->addProperty = JS_PropertyStub;
  //     jsb_cocos2d_FileUtils_class->delProperty = JS_DeletePropertyStub;
  //     jsb_cocos2d_FileUtils_class->getProperty = JS_PropertyStub;
  //     jsb_cocos2d_FileUtils_class->setProperty = JS_StrictPropertyStub;
  //     jsb_cocos2d_FileUtils_class->enumerate = JS_EnumerateStub;
  //     jsb_cocos2d_FileUtils_class->resolve = JS_ResolveStub;
  //     jsb_cocos2d_FileUtils_class->convert = JS_ConvertStub;
  //     jsb_cocos2d_FileUtils_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate);
  tpl->SetClassName(JsbUtils::ToV8String(isolate, "FileUtils"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  auto proto = tpl->PrototypeTemplate();

  //     static JSPropertySpec properties[] = {
  //         JS_PS_END};

  //     static JSFunctionSpec funcs[] = {
  //         JS_FN("fullPathForFilename", js_cocos2dx_FileUtils_fullPathForFilename, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "fullPathForFilename", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_fullPathForFilename));
  //         JS_FN("getStringFromFile", js_cocos2dx_FileUtils_getStringFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getStringFromFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getStringFromFile));
  //         JS_FN("removeFile", js_cocos2dx_FileUtils_removeFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_removeFile));
  //         JS_FN("isAbsolutePath", js_cocos2dx_FileUtils_isAbsolutePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isAbsolutePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_isAbsolutePath));
  //         JS_FN("renameFile", js_cocos2dx_FileUtils_renameFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "renameFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_renameFile));
  //         JS_FN("getDefaultResourceRootPath", js_cocos2dx_FileUtils_getDefaultResourceRootPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getDefaultResourceRootPath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getDefaultResourceRootPath));
  //         JS_FN("loadFilenameLookup", js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "loadFilenameLookup", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile));
  //         JS_FN("isPopupNotify", js_cocos2dx_FileUtils_isPopupNotify, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isPopupNotify", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_isPopupNotify));
  //         JS_FN("getValueVectorFromFile", js_cocos2dx_FileUtils_getValueVectorFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getValueVectorFromFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getValueVectorFromFile));
  //         JS_FN("getSearchPaths", js_cocos2dx_FileUtils_getSearchPaths, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSearchPaths", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getSearchPaths));
  //         JS_FN("writeToFile", js_cocos2dx_FileUtils_writeToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "writeToFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_writeToFile));
  //         JS_FN("getOriginalSearchPaths", js_cocos2dx_FileUtils_getOriginalSearchPaths, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getOriginalSearchPaths", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getOriginalSearchPaths));
  //         JS_FN("getNewFilename", js_cocos2dx_FileUtils_getNewFilename, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getNewFilename", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getNewFilename));
  //         JS_FN("listFiles", js_cocos2dx_FileUtils_listFiles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "listFiles", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_listFiles));
  //         JS_FN("getValueMapFromFile", js_cocos2dx_FileUtils_getValueMapFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getValueMapFromFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getValueMapFromFile));
  //         JS_FN("getFileSize", js_cocos2dx_FileUtils_getFileSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getFileSize", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getFileSize));
  //         JS_FN("getValueMapFromData", js_cocos2dx_FileUtils_getValueMapFromData, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getValueMapFromData", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getValueMapFromData));
  //         JS_FN("removeDirectory", js_cocos2dx_FileUtils_removeDirectory, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "removeDirectory", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_removeDirectory));
  //         JS_FN("setSearchPaths", js_cocos2dx_FileUtils_setSearchPaths, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSearchPaths", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setSearchPaths));
  //         JS_FN("writeStringToFile", js_cocos2dx_FileUtils_writeStringToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "writeStringToFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_writeStringToFile));
  //         JS_FN("setSearchResolutionsOrder", js_cocos2dx_FileUtils_setSearchResolutionsOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setSearchResolutionsOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setSearchResolutionsOrder));
  //         JS_FN("addSearchResolutionsOrder", js_cocos2dx_FileUtils_addSearchResolutionsOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addSearchResolutionsOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_addSearchResolutionsOrder));
  //         JS_FN("addSearchPath", js_cocos2dx_FileUtils_addSearchPath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "addSearchPath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_addSearchPath));
  //         JS_FN("writeValueVectorToFile", js_cocos2dx_FileUtils_writeValueVectorToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "writeValueVectorToFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_writeValueVectorToFile));
  //         JS_FN("isFileExist", js_cocos2dx_FileUtils_isFileExist, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isFileExist", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_isFileExist));
  //         JS_FN("purgeCachedEntries", js_cocos2dx_FileUtils_purgeCachedEntries, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "purgeCachedEntries", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_purgeCachedEntries));
  //         JS_FN("fullPathFromRelativeFile", js_cocos2dx_FileUtils_fullPathFromRelativeFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "fullPathFromRelativeFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_fullPathFromRelativeFile));
  //         JS_FN("getSuitableFOpen", js_cocos2dx_FileUtils_getSuitableFOpen, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSuitableFOpen", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getSuitableFOpen));
  //         JS_FN("writeValueMapToFile", js_cocos2dx_FileUtils_writeValueMapToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "writeValueMapToFile", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_writeValueMapToFile));
  //         JS_FN("getFileExtension", js_cocos2dx_FileUtils_getFileExtension, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getFileExtension", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getFileExtension));
  //         JS_FN("setWritablePath", js_cocos2dx_FileUtils_setWritablePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setWritablePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setWritablePath));
  //         JS_FN("setPopupNotify", js_cocos2dx_FileUtils_setPopupNotify, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setPopupNotify", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setPopupNotify));
  //         JS_FN("isDirectoryExist", js_cocos2dx_FileUtils_isDirectoryExist, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "isDirectoryExist", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_isDirectoryExist));
  //         JS_FN("setDefaultResourceRootPath", js_cocos2dx_FileUtils_setDefaultResourceRootPath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "setDefaultResourceRootPath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setDefaultResourceRootPath));
  //         JS_FN("getSearchResolutionsOrder", js_cocos2dx_FileUtils_getSearchResolutionsOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getSearchResolutionsOrder", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getSearchResolutionsOrder));
  //         JS_FN("createDirectory", js_cocos2dx_FileUtils_createDirectory, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "createDirectory", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_createDirectory));
  //         JS_FN("getWritablePath", js_cocos2dx_FileUtils_getWritablePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "getWritablePath", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getWritablePath));
  //         JS_FN("listFilesRecursively", js_cocos2dx_FileUtils_listFilesRecursively, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  proto->Set(isolate, "listFilesRecursively", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_listFilesRecursively));
  //         JS_FS_END};

  //     static JSFunctionSpec st_funcs[] = {
  //         JS_FN("setDelegate", js_cocos2dx_FileUtils_setDelegate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "setDelegate", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_setDelegate));
  //         JS_FN("getInstance", js_cocos2dx_FileUtils_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
  tpl->Set(isolate, "getInstance", v8::FunctionTemplate::New(isolate, js_cocos2dx_FileUtils_getInstance));
  //         JS_FS_END};

  //     jsb_cocos2d_FileUtils_prototype = JS_InitClass(
  //         cx, global,
  //         JS::NullPtr(),
  //         jsb_cocos2d_FileUtils_class,
  //         empty_constructor, 0,
  //         properties,
  //         funcs,
  //         NULL, // no static properties
  //         st_funcs);

  //     JS::RootedObject proto(cx, jsb_cocos2d_FileUtils_prototype);
  //     JS::RootedValue className(cx, std_string_to_jsval(cx, "FileUtils"));
  //     JS_SetProperty(cx, proto, "_className", className);
  proto->Set(isolate, "_className", JsbUtils::ToV8String(isolate, "FileUtils"));
  //     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
  proto->Set(isolate, "__nativeObj", v8::Boolean::New(isolate, true));
  //     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
  proto->Set(isolate, "__is_ref", v8::Boolean::New(isolate, false));
  //     // add the proto and JSClass to the type->js info hash table
  //     jsb_register_class<cocos2d::FileUtils>(cx, jsb_cocos2d_FileUtils_class, proto, JS::NullPtr());
  JsbUtils::RegisterV8Class(typeid(cocos2d::FileUtils).name(), &tpl);
  JsbUtils::BindJsClass("FileUtils", global, tpl);
}
