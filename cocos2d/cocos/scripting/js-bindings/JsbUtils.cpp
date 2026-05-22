#include "JsbUtils.h"
#include "Core/JsbClass.hpp"
#include "Core/JsbObjectWrap.hpp"
#include "Core/JsbObject.hpp"
#include "ScriptEngine.hpp"
#include "Utils/MappingUtils.hpp"

std::string JsbUtils::FromV8String(v8::Isolate *isolate, v8::Local<v8::String> str)
{
  if (str.IsEmpty())
  {
    return std::string();
  }
  else if (str->Length() == 0)
  {
    return std::string();
  }
  else if (str->IsUndefined())
  {
    return "x-undefined";
  }
  else if (str->IsNull())
  {
    return "x-null";
  }

  v8::String::Utf8Value utf8(isolate, str);
  return std::string(*utf8, utf8.length());
}

std::string JsbUtils::FromV8String(v8::Isolate *isolate, v8::Local<v8::Value> value)
{
  return FromV8String(isolate, value->ToString(isolate->GetCurrentContext()).ToLocalChecked());
}

int JsbUtils::FromV8Int32(v8::Isolate *isolate, v8::Local<v8::Integer> value)
{
  if (value.IsEmpty())
  {
    return 0;
  }
  else if (value->IsUndefined())
  {
    // TODO Log a warning here since this is not expected.
    return 0;
  }
  else if (value->IsNull())
  {
    // TODO Log a warning here since this is not expected.
    return 0;
  }

  return value->Int32Value(isolate->GetCurrentContext()).FromJust();
}

v8::Local<v8::String> JsbUtils::ToV8String(v8::Isolate *isolate, const std::string &str)
{
  if (str.empty())
  {
    return v8::String::Empty(isolate);
  }

  return v8::String::NewFromUtf8(isolate, str.c_str(), v8::NewStringType::kNormal).ToLocalChecked();
}

bool JsbUtils::SetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> value)
{
  if (obj.IsEmpty())
    return false;

  auto context = isolate->GetCurrentContext();
  auto maybe = obj->Set(context, JsbUtils::ToV8String(isolate, key), value);
  return maybe.FromMaybe(false);
}

bool JsbUtils::GetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> *value)
{
  v8::EscapableHandleScope handle_scope(isolate);
  if (obj.IsEmpty())
    return false;

  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, key, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto maybe = obj->Get(context, nameValToLocal);
  if (maybe.IsEmpty())
    return false;

  *value = handle_scope.Escape(maybe.ToLocalChecked());
  return true;
}

bool JsbUtils::GetProperty(v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> *value)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::EscapableHandleScope handle_scope(isolate);
  if (obj.IsEmpty())
    return false;

  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(isolate, key, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto maybe = obj->Get(context, nameValToLocal);
  if (maybe.IsEmpty())
    return false;

  *value = handle_scope.Escape(maybe.ToLocalChecked());
  return true;
}

void *JsbUtils::GetPrivate(v8::Isolate *isolate, v8::Local<v8::Value> value)
{
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::MaybeLocal<v8::Object> obj = value->ToObject(context);
  if (obj.IsEmpty())
    return nullptr;

  v8::Local<v8::Object> objChecked = obj.ToLocalChecked();
  int c = objChecked->InternalFieldCount();
  if (c > 0)
  {
    void *nativeObj = objChecked->GetAlignedPointerFromInternalField(0);
    //                SE_LOGD("getPrivate1: %p\n", nativeObj);
    return nativeObj;
  }

  // Pure JS subclass object doesn't have a internal field
  v8::MaybeLocal<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATA, v8::NewStringType::kNormal);
  if (key.IsEmpty())
    return nullptr;

  v8::Local<v8::String> keyChecked = key.ToLocalChecked();
  v8::Maybe<bool> mbHas = objChecked->Has(context, keyChecked);
  if (mbHas.IsNothing() || !mbHas.FromJust())
    return nullptr;

  v8::MaybeLocal<v8::Value> mbVal = objChecked->Get(context, keyChecked);
  if (mbVal.IsEmpty())
    return nullptr;

  v8::MaybeLocal<v8::Object> privateObj = mbVal.ToLocalChecked()->ToObject(context);
  if (privateObj.IsEmpty())
    return nullptr;
  JsbPrivateData *privateData = (JsbPrivateData *)privateObj.ToLocalChecked()->GetAlignedPointerFromInternalField(0);
  //                SE_LOGD("getPrivate: native data: %p\n", privateData);
  return privateData->data;
}

void JsbUtils::SetPrivate(v8::Isolate *isolate, ObjectWrap &wrap, void *data, JsbPrivateData **outInternalData)
{
  v8::Local<v8::Object> obj = wrap.handle(isolate);
  int c = obj->InternalFieldCount();
  if (c > 0)
  {
    wrap.wrap(data);
    //                SE_LOGD("setPrivate1: %p\n", data);
    if (outInternalData != nullptr)
      *outInternalData = nullptr;
  }
  else
  {
    JsbObject *privateObj = JsbObject::createObjectWithClass(__jsb_CCPrivateData_class);
    JsbPrivateData *privateData = (JsbPrivateData *)malloc(sizeof(JsbPrivateData));
    privateData->data = data;
    privateData->seObj = privateObj;

    privateObj->_getWrap().setFinalizeCallback(__jsb_CCPrivateData_class->_getFinalizeFunction());
    privateObj->_getWrap().wrap(privateData);

    v8::MaybeLocal<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATA, v8::NewStringType::kNormal);
    assert(!key.IsEmpty());
    v8::Maybe<bool> ret = obj->Set(isolate->GetCurrentContext(), key.ToLocalChecked(), privateObj->_getJSObject());
    assert(!ret.IsNothing());
    //                SE_LOGD("setPrivate: native data: %p\n", privateData);
    //                privateObj->decRef(); // NOTE: it's released in ScriptEngine::privateDataFinalize

    if (outInternalData != nullptr)
      *outInternalData = privateData;
  }
}

void JsbUtils::ClearPrivate(v8::Isolate *isolate, ObjectWrap &wrap)
{
  v8::Local<v8::Object> obj = wrap.handle(isolate);
  int c = obj->InternalFieldCount();
  if (c > 0)
  {
    wrap.wrap(nullptr);
  }
  else
  {
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    // Pure JS subclass object doesn't have a internal field
    v8::MaybeLocal<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATA, v8::NewStringType::kNormal);
    if (key.IsEmpty())
      return;

    v8::Local<v8::String> keyChecked = key.ToLocalChecked();
    v8::Maybe<bool> mbHas = obj->Has(context, keyChecked);
    if (mbHas.IsNothing() || !mbHas.FromJust())
      return;

    v8::MaybeLocal<v8::Value> mbVal = obj->Get(context, keyChecked);
    if (mbVal.IsEmpty())
      return;

    v8::MaybeLocal<v8::Object> privateObj = mbVal.ToLocalChecked()->ToObject(context);
    if (privateObj.IsEmpty())
      return;

    JsbPrivateData *privateData = (JsbPrivateData *)ObjectWrap::unwrap(privateObj.ToLocalChecked());
    free(privateData);
    v8::Maybe<bool> ok = obj->Delete(context, keyChecked);
    if (ok.IsNothing())
      return;

    assert(ok.FromJust());
  }
}

bool JsbUtils::DefineFunction(v8::Local<v8::Object> obj, const char *name, void (*callback)(const v8::FunctionCallbackInfo<v8::Value> &))
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Function> func;
  if (!v8::Function::New(context, callback).ToLocal(&func))
    return false;

  return obj->Set(context, JsbUtils::ToV8String(isolate, name), func).FromJust();
}

bool JsbUtils::SetPrivate(v8::Isolate *isolate, void *nativePtr, v8::Local<v8::Object> obj)
{
  assert(nativePtr == nullptr);
  assert(NativePtrToObjectMap::find(data) == NativePtrToObjectMap::end());

  // internal::setPrivate(__isolate, _obj, data, &_internalData);
  int c = obj->InternalFieldCount();
  if (c > 0)
  {
    obj->SetAlignedPointerInInternalField(0, nativePtr);
  }
  else
  {
    // TODo
    assert(false);
    // Object *privateObj = Object::createObjectWithClass(__jsb_CCPrivateData_class);
    // PrivateData *privateData = (PrivateData *)malloc(sizeof(PrivateData));
    // privateData->data = data;
    // privateData->seObj = privateObj;

    // privateObj->_getWrap().setFinalizeCallback(__jsb_CCPrivateData_class->_getFinalizeFunction());
    // privateObj->_getWrap().wrap(privateData);

    // v8::MaybeLocal<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATA, v8::NewStringType::kNormal);
    // assert(!key.IsEmpty());
    // v8::Maybe<bool> ret = obj->Set(isolate->GetCurrentContext(), key.ToLocalChecked(), privateObj->_getJSObject());
    // assert(!ret.IsNothing());
    // //                SE_LOGD("setPrivate: native data: %p\n", privateData);
    // //                privateObj->decRef(); // NOTE: it's released in ScriptEngine::privateDataFinalize

    // if (outInternalData != nullptr)
    //   *outInternalData = privateData;
  }

  // _privateData = data;
}

bool JsbUtils::NativePtrToObject(v8::Isolate *isolate, void *ptr, v8::Local<v8::Object> *outObj)
{

  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  auto jsbObj = NativePtrToObjectMap::find(ptr);

  if (jsbObj == NativePtrToObjectMap::end())
  {
    // If we couldn't find native object in map, then the native object is created from native code. e.g. TMXLayer::getTileAt
    //        CCLOGWARN("WARNING: Ref type: (%s) isn't catched!", typeid(*v).name());
    // assert(cls != nullptr);
    // obj = se::Object::createObjectWithClass(cls);
    // ret->setObject(obj, true);
    // obj->setPrivateData(v);
    // v->retain(); // Retain the native object to unify the logic in finalize method of js object.
    // if (isReturnCachedValue != nullptr)
    // {
    //     *isReturnCachedValue = false;
    // }
    v8::Local<v8::Object> obj;
    if (!CreateJsObjectByTypeName(typeid(ptr).name(), &obj))
    {
      SE_REPORT_ERROR("Failed to create js object for native type: %s", typeid(ptr).name());
      return false;
    }

    if (outObj != nullptr)
      *outObj = handle_scope.Escape(obj);

    SetPrivate(isolate, ptr, obj);
    NativePtrToObjectMap::emplace(ptr, obj);
  }
  else
  {
    if (outObj != nullptr)
      *outObj = handle_scope.Escape(jsbObj->second.Get(isolate));
  }

  return true;
}

bool JsbUtils::CreateJsObjectByTypeName(const char *typeName, v8::Local<v8::Object> *outObj)
{
  auto iter = ScriptEngine::_registeredClasses.find(typeName);
  if (iter == ScriptEngine::_registeredClasses.end())
  {
    SE_REPORT_ERROR("Failed to find class for native type: %s", typeName);
    return false;
  }

  v8::Isolate *isolate = v8::Isolate::GetCurrent();

  const v8::Global<v8::FunctionTemplate> &tmpl = iter->second;
  v8::Local<v8::FunctionTemplate> localTmpl = tmpl.Get(v8::Isolate::GetCurrent());
  v8::Local<v8::Object> obj;
  if (!localTmpl->InstanceTemplate()->NewInstance(v8::Isolate::GetCurrent()->GetCurrentContext()).ToLocal(&obj))
  {
    SE_REPORT_ERROR("Failed to create instance for native type: %s", typeName);
    return false;
  }
  if (outObj != nullptr)
    *outObj = obj;
  return true;
}