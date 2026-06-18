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
  
  //         std::string arg0;
  //         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
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
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isPopupNotify : Invalid Native Object");
//     if (argc == 0)
//     {
//         bool ret = cobj->isPopupNotify();
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_isPopupNotify : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getValueVectorFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueVectorFromFile : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueVectorFromFile : Error processing arguments");
//         cocos2d::ValueVector ret = cobj->getValueVectorFromFile(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = ccvaluevector_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueVectorFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSearchPaths : Invalid Native Object");
//     if (argc == 0)
//     {
//         std::vector<std::string> ret = cobj->getSearchPaths();
//         JS::RootedValue jsret(cx);
//         jsret = std_vector_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_writeToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeToFile : Invalid Native Object");
//     if (argc == 2)
//     {
//         cocos2d::ValueMap arg0;
//         std::string arg1;
//         ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
//         ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_writeToFile : Error processing arguments");
//         bool ret = cobj->writeToFile(arg0, arg1);
//         JS::RootedValue jsret(cx);
//         jsret = BOOLEAN_TO_JSVAL(ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeToFile : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getOriginalSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getOriginalSearchPaths : Invalid Native Object");
//     if (argc == 0)
//     {
//         std::vector<std::string> ret = cobj->getOriginalSearchPaths();
//         JS::RootedValue jsret(cx);
//         jsret = std_vector_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getOriginalSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getNewFilename(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getNewFilename : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getNewFilename : Error processing arguments");
//         std::string ret = cobj->getNewFilename(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getNewFilename : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_listFiles(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_listFiles : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_listFiles : Error processing arguments");
//         std::vector<std::string> ret = cobj->listFiles(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = std_vector_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_listFiles : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getValueMapFromFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueMapFromFile : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueMapFromFile : Error processing arguments");
//         cocos2d::ValueMap ret = cobj->getValueMapFromFile(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = ccvaluemap_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueMapFromFile : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getFileSize(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getFileSize : Invalid Native Object");
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
//             std::function<void(long)> arg1;
//             do
//             {
//                 if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
//                 {
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
//             } while (0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             cobj->getFileSize(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

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
//             long ret = cobj->getFileSize(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = long_to_jsval(cx, ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getFileSize : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_getValueMapFromData(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getValueMapFromData : Invalid Native Object");
//     if (argc == 2)
//     {
//         const char *arg0 = nullptr;
//         int arg1 = 0;
//         std::string arg0_tmp;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp);
//         arg0 = arg0_tmp.c_str();
//         ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getValueMapFromData : Error processing arguments");
//         cocos2d::ValueMap ret = cobj->getValueMapFromData(arg0, arg1);
//         JS::RootedValue jsret(cx);
//         jsret = ccvaluemap_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getValueMapFromData : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_FileUtils_removeDirectory(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_removeDirectory : Invalid Native Object");
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
//             cobj->removeDirectory(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

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
//             bool ret = cobj->removeDirectory(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_removeDirectory : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_setSearchPaths(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setSearchPaths : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::vector<std::string> arg0;
//         ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setSearchPaths : Error processing arguments");
//         cobj->setSearchPaths(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_setSearchPaths : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_writeStringToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeStringToFile : Invalid Native Object");
//     do
//     {
//         if (argc == 3)
//         {
//             std::string arg0;
//             ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::function<void(bool)> arg2;
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
//             cobj->writeStringToFile(arg0, arg1, arg2);
//             args.rval().setUndefined();
//             return true;
//         }
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
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->writeStringToFile(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeStringToFile : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_setSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::vector<std::string> arg0;
//         ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : Error processing arguments");
//         cobj->setSearchResolutionsOrder(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_setSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_addSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : Error processing arguments");
//         cobj->addSearchResolutionsOrder(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
//     if (argc == 2)
//     {
//         std::string arg0;
//         bool arg1;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         arg1 = JS::ToBoolean(args.get(1));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : Error processing arguments");
//         cobj->addSearchResolutionsOrder(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_addSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_addSearchPath(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_addSearchPath : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_addSearchPath : Error processing arguments");
//         cobj->addSearchPath(arg0);
//         args.rval().setUndefined();
//         return true;
//     }
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
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_addSearchPath : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_writeValueVectorToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeValueVectorToFile : Invalid Native Object");
//     do
//     {
//         if (argc == 3)
//         {
//             cocos2d::ValueVector arg0;
//             ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::function<void(bool)> arg2;
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
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 2)
//         {
//             cocos2d::ValueVector arg0;
//             ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->writeValueVectorToFile(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeValueVectorToFile : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_isFileExist(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isFileExist : Invalid Native Object");
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
//         }
//     } while (0);

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
//             bool ret = cobj->isFileExist(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_isFileExist : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_purgeCachedEntries(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_purgeCachedEntries : Invalid Native Object");
//     if (argc == 0)
//     {
//         cobj->purgeCachedEntries();
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_purgeCachedEntries : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_fullPathFromRelativeFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_fullPathFromRelativeFile : Invalid Native Object");
//     if (argc == 2)
//     {
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
//     return false;
// }
// bool js_cocos2dx_FileUtils_getSuitableFOpen(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSuitableFOpen : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_getSuitableFOpen : Error processing arguments");
//         std::string ret = cobj->getSuitableFOpen(arg0);
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSuitableFOpen : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_writeValueMapToFile(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_writeValueMapToFile : Invalid Native Object");
//     do
//     {
//         if (argc == 3)
//         {
//             cocos2d::ValueMap arg0;
//             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::function<void(bool)> arg2;
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
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

//     do
//     {
//         if (argc == 2)
//         {
//             cocos2d::ValueMap arg0;
//             ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             std::string arg1;
//             ok &= jsval_to_std_string(cx, args.get(1), &arg1);
//             if (!ok)
//             {
//                 ok = true;
//                 break;
//             }
//             bool ret = cobj->writeValueMapToFile(arg0, arg1);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_writeValueMapToFile : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_getFileExtension(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getFileExtension : Invalid Native Object");
//     if (argc == 1)
//     {
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
// }
// bool js_cocos2dx_FileUtils_setWritablePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setWritablePath : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setWritablePath : Error processing arguments");
//         cobj->setWritablePath(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_setWritablePath : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_setPopupNotify(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setPopupNotify : Invalid Native Object");
//     if (argc == 1)
//     {
//         bool arg0;
//         arg0 = JS::ToBoolean(args.get(0));
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setPopupNotify : Error processing arguments");
//         cobj->setPopupNotify(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_setPopupNotify : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_isDirectoryExist(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_isDirectoryExist : Invalid Native Object");
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
//             cobj->isDirectoryExist(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

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
//             bool ret = cobj->isDirectoryExist(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_isDirectoryExist : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_setDefaultResourceRootPath(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : Invalid Native Object");
//     if (argc == 1)
//     {
//         std::string arg0;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : Error processing arguments");
//         cobj->setDefaultResourceRootPath(arg0);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_setDefaultResourceRootPath : wrong number of arguments: %d, was expecting %d", argc, 1);
//     return false;
// }
// bool js_cocos2dx_FileUtils_getSearchResolutionsOrder(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getSearchResolutionsOrder : Invalid Native Object");
//     if (argc == 0)
//     {
//         std::vector<std::string> ret = cobj->getSearchResolutionsOrder();
//         JS::RootedValue jsret(cx);
//         jsret = std_vector_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getSearchResolutionsOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_createDirectory(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     bool ok = true;
//     cocos2d::FileUtils *cobj = nullptr;

//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx);
//     obj.set(args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : nullptr);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_createDirectory : Invalid Native Object");
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
//             cobj->createDirectory(arg0, arg1);
//             args.rval().setUndefined();
//             return true;
//         }
//     } while (0);

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
//             bool ret = cobj->createDirectory(arg0);
//             jsval jsret = JSVAL_NULL;
//             jsret = BOOLEAN_TO_JSVAL(ret);
//             args.rval().set(jsret);
//             return true;
//         }
//     } while (0);

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_createDirectory : wrong number of arguments");
//     return false;
// }
// bool js_cocos2dx_FileUtils_getWritablePath(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_getWritablePath : Invalid Native Object");
//     if (argc == 0)
//     {
//         std::string ret = cobj->getWritablePath();
//         JS::RootedValue jsret(cx);
//         jsret = std_string_to_jsval(cx, ret);
//         args.rval().set(jsret);
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getWritablePath : wrong number of arguments: %d, was expecting %d", argc, 0);
//     return false;
// }
// bool js_cocos2dx_FileUtils_listFilesRecursively(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
//     js_proxy_t *proxy = jsb_get_js_proxy(obj);
//     cocos2d::FileUtils *cobj = (cocos2d::FileUtils *)(proxy ? proxy->ptr : NULL);
//     JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_FileUtils_listFilesRecursively : Invalid Native Object");
//     if (argc == 2)
//     {
//         std::string arg0;
//         std::vector<std::string> *arg1 = nullptr;
//         ok &= jsval_to_std_string(cx, args.get(0), &arg0);
//         do
//         {
//             if (args.get(1).isNull())
//             {
//                 arg1 = nullptr;
//                 break;
//             }
//             if (!args.get(1).isObject())
//             {
//                 ok = false;
//                 break;
//             }
//             js_proxy_t *jsProxy;
//             JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
//             jsProxy = jsb_get_js_proxy(tmpObj);
//             arg1 = (std::vector<std::string> *)(jsProxy ? jsProxy->ptr : NULL);
//             JSB_PRECONDITION2(arg1, cx, false, "Invalid Native Object");
//         } while (0);
//         JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_FileUtils_listFilesRecursively : Error processing arguments");
//         cobj->listFilesRecursively(arg0, arg1);
//         args.rval().setUndefined();
//         return true;
//     }

//     JS_ReportError(cx, "js_cocos2dx_FileUtils_listFilesRecursively : wrong number of arguments: %d, was expecting %d", argc, 2);
//     return false;
// }
// bool js_cocos2dx_FileUtils_setDelegate(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     bool ok = true;
//     if (argc == 1)
//     {
//         cocos2d::FileUtils *arg0 = nullptr;
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
// }

// bool js_cocos2dx_FileUtils_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
// {
//     JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
//     if (argc == 0)
//     {

//         cocos2d::FileUtils *ret = cocos2d::FileUtils::getInstance();
//         jsval jsret = JSVAL_NULL;
//         if (ret)
//         {
//             jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::FileUtils>(cx, (cocos2d::FileUtils *)ret));
//         }
//         else
//         {
//             jsret = JSVAL_NULL;
//         };
//         args.rval().set(jsret);
//         return true;
//     }
//     JS_ReportError(cx, "js_cocos2dx_FileUtils_getInstance : wrong number of arguments");
//     return false;
// }

// void js_register_cocos2dx_FileUtils(JSContext *cx, JS::HandleObject global)
// {
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

//     static JSPropertySpec properties[] = {
//         JS_PS_END};

//     static JSFunctionSpec funcs[] = {
//         JS_FN("fullPathForFilename", js_cocos2dx_FileUtils_fullPathForFilename, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getStringFromFile", js_cocos2dx_FileUtils_getStringFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeFile", js_cocos2dx_FileUtils_removeFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isAbsolutePath", js_cocos2dx_FileUtils_isAbsolutePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("renameFile", js_cocos2dx_FileUtils_renameFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getDefaultResourceRootPath", js_cocos2dx_FileUtils_getDefaultResourceRootPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("loadFilenameLookup", js_cocos2dx_FileUtils_loadFilenameLookupDictionaryFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isPopupNotify", js_cocos2dx_FileUtils_isPopupNotify, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getValueVectorFromFile", js_cocos2dx_FileUtils_getValueVectorFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSearchPaths", js_cocos2dx_FileUtils_getSearchPaths, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("writeToFile", js_cocos2dx_FileUtils_writeToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getOriginalSearchPaths", js_cocos2dx_FileUtils_getOriginalSearchPaths, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getNewFilename", js_cocos2dx_FileUtils_getNewFilename, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("listFiles", js_cocos2dx_FileUtils_listFiles, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getValueMapFromFile", js_cocos2dx_FileUtils_getValueMapFromFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFileSize", js_cocos2dx_FileUtils_getFileSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getValueMapFromData", js_cocos2dx_FileUtils_getValueMapFromData, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("removeDirectory", js_cocos2dx_FileUtils_removeDirectory, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSearchPaths", js_cocos2dx_FileUtils_setSearchPaths, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("writeStringToFile", js_cocos2dx_FileUtils_writeStringToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setSearchResolutionsOrder", js_cocos2dx_FileUtils_setSearchResolutionsOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addSearchResolutionsOrder", js_cocos2dx_FileUtils_addSearchResolutionsOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("addSearchPath", js_cocos2dx_FileUtils_addSearchPath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("writeValueVectorToFile", js_cocos2dx_FileUtils_writeValueVectorToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isFileExist", js_cocos2dx_FileUtils_isFileExist, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("purgeCachedEntries", js_cocos2dx_FileUtils_purgeCachedEntries, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("fullPathFromRelativeFile", js_cocos2dx_FileUtils_fullPathFromRelativeFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSuitableFOpen", js_cocos2dx_FileUtils_getSuitableFOpen, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("writeValueMapToFile", js_cocos2dx_FileUtils_writeValueMapToFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getFileExtension", js_cocos2dx_FileUtils_getFileExtension, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setWritablePath", js_cocos2dx_FileUtils_setWritablePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setPopupNotify", js_cocos2dx_FileUtils_setPopupNotify, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("isDirectoryExist", js_cocos2dx_FileUtils_isDirectoryExist, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("setDefaultResourceRootPath", js_cocos2dx_FileUtils_setDefaultResourceRootPath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getSearchResolutionsOrder", js_cocos2dx_FileUtils_getSearchResolutionsOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("createDirectory", js_cocos2dx_FileUtils_createDirectory, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getWritablePath", js_cocos2dx_FileUtils_getWritablePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("listFilesRecursively", js_cocos2dx_FileUtils_listFilesRecursively, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FS_END};

//     static JSFunctionSpec st_funcs[] = {
//         JS_FN("setDelegate", js_cocos2dx_FileUtils_setDelegate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
//         JS_FN("getInstance", js_cocos2dx_FileUtils_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
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
//     JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
//     JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
//     // add the proto and JSClass to the type->js info hash table
//     jsb_register_class<cocos2d::FileUtils>(cx, jsb_cocos2d_FileUtils_class, proto, JS::NullPtr());
// }
