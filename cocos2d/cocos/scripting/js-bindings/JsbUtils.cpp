#include "JsbUtils.h"
#include "Core/JsbClass.hpp"
#include "Core/JsbObjectWrap.hpp"
#include "Core/JsbObject.hpp"
#include "ScriptEngine.hpp"
#include "Utils/MappingUtils.hpp"
#include "base/CCValue.h"
#include "math/CCAffineTransform.h"
#include <sstream>

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
  assert(nativePtr != nullptr);
  assert(NativePtrToObjectMap::find(nativePtr) == NativePtrToObjectMap::end());

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
  return true;
}

bool JsbUtils::NativePtrToObject(const char *typeName, void *ptr, v8::Local<v8::Object> *outObj)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
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
    if (!CreateJsObjectByTypeName(typeName, &obj))
    {
      SE_REPORT_ERROR("Failed to create js object for native type: %s", typeName);
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

bool JsbUtils::jsval_to_ccvalue(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Value *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *outValue = cocos2d::Value::Null;
    return true;
  }
  else if (value->IsBoolean())
  {
    *outValue = value->BooleanValue(isolate);
    return true;
  }
  else if (value->IsInt32())
  {
    *outValue = value->Int32Value(isolate->GetCurrentContext()).FromJust();
    return true;
  }
  else if (value->IsUint32())
  {
    *outValue = value->Uint32Value(isolate->GetCurrentContext()).FromJust();
    return true;
  }
  else if (value->IsNumber())
  {
    *outValue = value->NumberValue(isolate->GetCurrentContext()).FromJust();
    return true;
  }
  else if (value->IsString())
  {
    *outValue = FromV8String(isolate, value);
    return true;
  }
  else if (value->IsObject())
  {
    v8::Local<v8::Object> obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    if (obj->IsArray())
    {
      cocos2d::ValueVector arrVal;
      bool ok = jsval_to_ccvaluevector(isolate, value, &arrVal);
      if (ok)
      {
        // *outValue = cocos2d::Value(arrVal);
      }
    }
    else
    {
      cocos2d::ValueMap dictVal;
      bool ok = jsval_to_ccvaluemap(isolate, value, &dictVal);
      if (ok)
      {
        // *outValue = cocos2d::Value(dictVal);
      }
    }
  }
}

bool JsbUtils::jsval_to_ccvaluemap(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMap *ret)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    return true;
  }

  cocos2d::ValueMap &dict = *ret;

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Array> propertyNames;
  if (!obj->GetOwnPropertyNames(isolate->GetCurrentContext()).ToLocal(&propertyNames))
  {
    SE_REPORT_ERROR("Failed to get object property names");
    return false;
  }

  for (uint32_t i = 0; i < propertyNames->Length(); i++)
  {
    v8::Local<v8::Value> key;
    if (!propertyNames->Get(isolate->GetCurrentContext(), i).ToLocal(&key))
    {
      SE_REPORT_ERROR("Failed to get property name at index %d", i);
      return false;
    }

    if (!key->IsString())
    {
      continue; // ignore non-string properties
    }

    v8::Local<v8::Value> value;
    if (!obj->Get(isolate->GetCurrentContext(), key).ToLocal(&value))
    {
      SE_REPORT_ERROR("Failed to get property value for key %s", FromV8String(isolate, key).c_str());
      return false;
    }

    std::string keyStr = FromV8String(isolate, key);
    cocos2d::Value dictValue;
    if (jsval_to_ccvalue(isolate, value, &dictValue))
    {
      dict.insert(cocos2d::ValueMap::value_type(keyStr, dictValue));
    }
    else
    {
      SE_REPORT_ERROR("Failed to convert property value for key %s to CCValue", keyStr.c_str());
      return false;
    }
  }
  return true;
}

bool JsbUtils::jsval_to_ccvaluemapintkey(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMapIntKey *ret)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    return true;
  }

  cocos2d::ValueMapIntKey &dict = *ret;
  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Array> propertyNames;
  if (!obj->GetOwnPropertyNames(isolate->GetCurrentContext()).ToLocal(&propertyNames))
  {
    SE_REPORT_ERROR("Failed to get object property names");
    return false;
  }

  for (uint32_t i = 0; i < propertyNames->Length(); i++)
  {
    v8::Local<v8::Value> key;
    if (!propertyNames->Get(isolate->GetCurrentContext(), i).ToLocal(&key))
    {
      SE_REPORT_ERROR("Failed to get property name at index %d", i);
      return false;
    }

    if (!key->IsString())
    {
      continue; // ignore non-string properties
    }

    int keyVal = key->Int32Value(isolate->GetCurrentContext()).FromJust();
    v8::Local<v8::Value> value;
    if (!obj->Get(isolate->GetCurrentContext(), key).ToLocal(&value))
    {
      SE_REPORT_ERROR("Failed to get property value for key %d", keyVal);
      return false;
    }

    cocos2d::Value dictValue;
    if (jsval_to_ccvalue(isolate, value, &dictValue))
    {
      dict.insert(cocos2d::ValueMapIntKey::value_type(keyVal, dictValue));
    }
    else
    {
      SE_REPORT_ERROR("Failed to convert property value for key %d to CCValue", keyVal);
      return false;
    }
  }

  return true;
}

bool JsbUtils::jsval_to_ccvaluevector(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueVector *ret)
{
  v8::HandleScope handle_scope(isolate);
  // JS::RootedObject jsArr(cx);
  // bool ok = v.isObject() && JS_ValueToObject( cx, v, &jsArr );
  // JSB_PRECONDITION3( ok, cx, false, "Error converting value to object");
  // JSB_PRECONDITION3( jsArr && JS_IsArrayObject( cx, jsArr),  cx, false, "Object must be an array");

  // uint32_t len = 0;
  // JS_GetArrayLength(cx, jsArr, &len);

  v8::Local<v8::Object> obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  if (!obj->IsArray())
  {
    SE_REPORT_ERROR("Object must be an array");
    return false;
  }
  v8::Local<v8::Array> arr = obj.As<v8::Array>();

  for (uint32_t i = 0; i < arr->Length(); i++)
  {
    v8::Local<v8::Value> element;
    if (!arr->Get(isolate->GetCurrentContext(), i).ToLocal(&element))
    {
      SE_REPORT_ERROR("Failed to get array element at index %d", i);
      return false;
    }

    cocos2d::Value vecValue;
    if (jsval_to_ccvalue(isolate, element, &vecValue))
    {
      ret->push_back(vecValue);
    }
    else
    {
      SE_REPORT_ERROR("Failed to convert array element at index %d to CCValue", i);
      return false;
    }
  }
  // for (uint32_t i=0; i < len; i++)
  // {
  //     JS::RootedValue value(cx);
  //     if (JS_GetElement(cx, jsArr, i, &value))
  //     {
  //         if (value.isObject())
  //         {
  //             JS::RootedObject jsobj(cx, value.toObjectOrNull());
  //             CCASSERT(jsb_get_js_proxy(jsobj) == nullptr, "Native object should be added!");

  //             if (!JS_IsArrayObject(cx, jsobj))
  //             {
  //                 // It's a normal js object.
  //                 ValueMap dictVal;
  //                 ok = jsval_to_ccvaluemap(cx, value, &dictVal);
  //                 if (ok)
  //                 {
  //                     ret->push_back(Value(dictVal));
  //                 }
  //             }
  //             else {
  //                 // It's a js array object.
  //                 ValueVector arrVal;
  //                 ok = jsval_to_ccvaluevector(cx, value, &arrVal);
  //                 if (ok)
  //                 {
  //                     ret->push_back(Value(arrVal));
  //                 }
  //             }
  //         }
  //         else if (value.isString())
  //         {
  //             JSStringWrapper valueWapper(value.toString(), cx);
  //             ret->push_back(Value(valueWapper.get()));
  //         }
  //         else if (value.isNumber())
  //         {
  //             double number = 0.0;
  //             ok = JS::ToNumber(cx, value, &number);
  //             if (ok)
  //             {
  //                 ret->push_back(Value(number));
  //             }
  //         }
  //         else if (value.isBoolean())
  //         {
  //             bool boolVal = JS::ToBoolean(value);
  //             ret->push_back(Value(boolVal));
  //         }
  //         else
  //         {
  //             CCASSERT(false, "not supported type");
  //         }
  //     }
  // }

  return true;
}

v8::Local<v8::Value> JsbUtils::ccvalue_to_jsval(v8::Isolate *isolate, const cocos2d::Value &v)
{
  v8::HandleScope handle_scope(isolate);
  v8::Local<v8::Object> retObj;
  switch (v.getType())
  {
  case cocos2d::Value::Type::NONE:
    return v8::Null(isolate);
    break;
  case cocos2d::Value::Type::BOOLEAN:
    return v8::Boolean::New(isolate, v.asBool());
    break;
  case cocos2d::Value::Type::INTEGER:
    return v8::Integer::New(isolate, v.asInt());
    break;
  case cocos2d::Value::Type::FLOAT:
  case cocos2d::Value::Type::DOUBLE:
    return v8::Number::New(isolate, v.asDouble());
    break;
  case cocos2d::Value::Type::STRING:
    return ToV8String(isolate, v.asString());
    break;
  case cocos2d::Value::Type::MAP:
    return ccvaluemap_to_jsval(isolate, v.asValueMap());
    break;
  case cocos2d::Value::Type::INT_KEY_MAP:
    return ccvaluemapintkey_to_jsval(isolate, v.asIntKeyMap());
    break;
  case cocos2d::Value::Type::VECTOR:
    return ccvaluevector_to_jsval(isolate, v.asValueVector());
  default:
    break;
  }
}

v8::Local<v8::Value> JsbUtils::ccvaluemap_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMap &v)
{
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);

  for (auto iter = v.begin(); iter != v.end(); ++iter)
  {
    v8::Local<v8::Value> dictElement;

    std::string key = iter->first;
    const cocos2d::Value &obj = iter->second;

    switch (obj.getType())
    {
    case cocos2d::Value::Type::BOOLEAN:
      dictElement = v8::Boolean::New(isolate, obj.asBool());
      break;
    case cocos2d::Value::Type::FLOAT:
    case cocos2d::Value::Type::DOUBLE:
      dictElement = v8::Number::New(isolate, obj.asDouble());
      break;
    case cocos2d::Value::Type::INTEGER:
      dictElement = v8::Integer::New(isolate, obj.asInt());
      break;
    case cocos2d::Value::Type::STRING:
      dictElement = ToV8String(isolate, obj.asString());
      break;
    case cocos2d::Value::Type::VECTOR:
      dictElement = ccvaluevector_to_jsval(isolate, obj.asValueVector());
      break;
    case cocos2d::Value::Type::MAP:
      dictElement = ccvaluemap_to_jsval(isolate, obj.asValueMap());
      break;
    case cocos2d::Value::Type::INT_KEY_MAP:
      dictElement = ccvaluemapintkey_to_jsval(isolate, obj.asIntKeyMap());
      break;
    default:
      break;
    }

    if (!key.empty())
    {
      // JS_SetProperty(cx, jsRet, key.c_str(), dictElement);
      jsRet->Set(isolate->GetCurrentContext(), ToV8String(isolate, key), dictElement).FromJust();
    }
  }
  return jsRet;
}

v8::Local<v8::Value> JsbUtils::ccvaluemapintkey_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMapIntKey &v)
{
  v8::Local<v8::Array> jsRet = v8::Array::New(isolate, v.size());

  for (auto iter = v.begin(); iter != v.end(); ++iter)
  {
    v8::Local<v8::Value> dictElement;
    std::stringstream keyss;
    keyss << iter->first;
    std::string key = keyss.str();

    const cocos2d::Value &obj = iter->second;

    switch (obj.getType())
    {
    case cocos2d::Value::Type::BOOLEAN:
      dictElement = v8::Boolean::New(isolate, obj.asBool());
      break;
    case cocos2d::Value::Type::FLOAT:
    case cocos2d::Value::Type::DOUBLE:
      dictElement = v8::Number::New(isolate, obj.asDouble());
      break;
    case cocos2d::Value::Type::INTEGER:
      dictElement = v8::Integer::New(isolate, obj.asInt());
      break;
    case cocos2d::Value::Type::STRING:
      dictElement = ToV8String(isolate, obj.asString());
      break;
    case cocos2d::Value::Type::VECTOR:
      dictElement = ccvaluevector_to_jsval(isolate, obj.asValueVector());
      break;
    case cocos2d::Value::Type::MAP:
      dictElement = ccvaluemap_to_jsval(isolate, obj.asValueMap());
      break;
    case cocos2d::Value::Type::INT_KEY_MAP:
      dictElement = ccvaluemapintkey_to_jsval(isolate, obj.asIntKeyMap());
      break;
    default:
      break;
    }

    if (!key.empty())
    {
      // JS_SetProperty(cx, jsRet, key.c_str(), dictElement);
      jsRet->Set(isolate->GetCurrentContext(), ToV8String(isolate, key), dictElement).FromJust();
    }
  }
  return jsRet;
}

v8::Local<v8::Value> JsbUtils::ccvaluevector_to_jsval(v8::Isolate *isolate, const cocos2d::ValueVector &v)
{
  v8::Local<v8::Array> jsRet = v8::Array::New(isolate, v.size());

  int i = 0;
  for (const auto &obj : v)
  {
    v8::Local<v8::Value> arrElement;

    switch (obj.getType())
    {
    case cocos2d::Value::Type::BOOLEAN:
      arrElement = v8::Boolean::New(isolate, obj.asBool());
      break;
    case cocos2d::Value::Type::FLOAT:
    case cocos2d::Value::Type::DOUBLE:
      arrElement = v8::Number::New(isolate, obj.asDouble());
      break;
    case cocos2d::Value::Type::INTEGER:
      arrElement = v8::Integer::New(isolate, obj.asInt());
      break;
    case cocos2d::Value::Type::STRING:
      arrElement = ToV8String(isolate, obj.asString());
      break;
    case cocos2d::Value::Type::VECTOR:
      arrElement = ccvaluevector_to_jsval(isolate, obj.asValueVector());
      break;
    case cocos2d::Value::Type::MAP:
      arrElement = ccvaluemap_to_jsval(isolate, obj.asValueMap());
      break;
    case cocos2d::Value::Type::INT_KEY_MAP:
      arrElement = ccvaluemapintkey_to_jsval(isolate, obj.asIntKeyMap());
      break;
    default:
      break;
    }

    // if (!JS_SetElement(cx, jsretArr, i, arrElement))
    // {
    //   break;
    // }
    jsRet->Set(isolate->GetCurrentContext(), i, arrElement).FromJust();
    ++i;
  }
  return jsRet;
}

v8::Local<v8::FunctionTemplate> JsbUtils::CreateClass(v8::Isolate *isolate, const char *className, v8::FunctionCallback constructor)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate, constructor);
  tmpl->SetClassName(ToV8String(isolate, className));
  tmpl->InstanceTemplate()->SetInternalFieldCount(1);
  return handle_scope.Escape(tmpl);
}

bool JsbUtils::RegisterV8Class(const char *className, v8::Local<v8::FunctionTemplate> *constructor)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  if (constructor->IsEmpty())
  {
    SE_REPORT_ERROR("Failed to get function template for class: %s", className);
    return false;
  }
  SE_LOGD("Register class: %s", className);
  ScriptEngine::_registeredClasses[className] = v8::Global<v8::FunctionTemplate>(isolate, *constructor);
  return true;
}

bool JsbUtils::jsval_to_cccolor4b(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color4B *ret)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *ret = cocos2d::Color4B::BLACK;
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> rVal, gVal, bVal, aVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "r")).ToLocal(&rVal) ||
      !obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "g")).ToLocal(&gVal) ||
      !obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "b")).ToLocal(&bVal) ||
      !obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "a")).ToLocal(&aVal))
  {
    SE_REPORT_ERROR("Failed to get r/g/b/a property from object");
    return false;
  }

  if (!rVal->IsUint32() || !gVal->IsUint32() || !bVal->IsUint32() || !aVal->IsUint32())
  {
    SE_REPORT_ERROR("r/g/b/a property must be uint");
    return false;
  }

  ret->r = rVal->Uint32Value(isolate->GetCurrentContext()).FromJust();
  ret->g = gVal->Uint32Value(isolate->GetCurrentContext()).FromJust();
  ret->b = bVal->Uint32Value(isolate->GetCurrentContext()).FromJust();
  ret->a = aVal->Uint32Value(isolate->GetCurrentContext()).FromJust();

  return true;
}

v8::Local<v8::Value> JsbUtils::cccolor4b_to_jsval(v8::Isolate *isolate, const cocos2d::Color4B &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "r", v8::Integer::New(isolate, v.r));
  SetProperty(isolate, jsRet, "g", v8::Integer::New(isolate, v.g));
  SetProperty(isolate, jsRet, "b", v8::Integer::New(isolate, v.b));
  SetProperty(isolate, jsRet, "a", v8::Integer::New(isolate, v.a));

  return handle_scope.Escape(jsRet);
}

v8::Local<v8::Value> JsbUtils::blendfunc_to_jsval(v8::Isolate *isolate, const cocos2d::BlendFunc &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "src", v8::Integer::New(isolate, (int)v.src));
  SetProperty(isolate, jsRet, "dst", v8::Integer::New(isolate, (int)v.dst));

  return handle_scope.Escape(jsRet);
}

bool JsbUtils::GetOrCreateJsObject(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *name, v8::Local<v8::Object> *outObj)
{
  v8::EscapableHandleScope handle_scope(isolate);
  // JS::RootedValue nsval(cx);
  // JS_GetProperty(cx, obj, name.c_str(), &nsval);
  v8::Local<v8::Value> nsval;
  if (!JsbUtils::GetProperty(isolate, obj, name, &nsval))
  {
    SE_REPORT_ERROR("Failed to get property %s from object", name);
    return false;
  }
  // if (nsval == JSVAL_VOID)
  // {
  //   jsObj.set(JS_NewObject(cx, nullptr, JS::NullPtr(), JS::NullPtr()));
  //   nsval = OBJECT_TO_JSVAL(jsObj);
  //   JS_SetProperty(cx, obj, name.c_str(), nsval);
  // }
  // else
  // {
  //   jsObj.set(nsval.toObjectOrNull());
  // }
  if (nsval->IsUndefined())
  {
    v8::Local<v8::Object> newObj = v8::Object::New(isolate);
    if (!JsbUtils::SetProperty(isolate, obj, name, newObj))
    {
      SE_REPORT_ERROR("Failed to set property %s to object", name);
      return false;
    }
    if (outObj != nullptr)
      *outObj = handle_scope.Escape(newObj);
  }
  else
  {
    if (!nsval->IsObject())
    {
      SE_REPORT_ERROR("Property %s is not an object", name);
      return false;
    }
    if (outObj != nullptr)
      *outObj = handle_scope.Escape(nsval->ToObject(isolate->GetCurrentContext()).ToLocalChecked());
  }
  return true;
}

v8::Local<v8::Value> JsbUtils::cccolor3b_to_jsval(v8::Isolate *isolate, const cocos2d::Color3B &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "r", v8::Integer::New(isolate, v.r));
  SetProperty(isolate, jsRet, "g", v8::Integer::New(isolate, v.g));
  SetProperty(isolate, jsRet, "b", v8::Integer::New(isolate, v.b));

  return handle_scope.Escape(jsRet);
}

v8::Local<v8::Value> JsbUtils::cccolor4f_to_jsval(v8::Isolate *isolate, const cocos2d::Color4F &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "r", v8::Number::New(isolate, v.r));
  SetProperty(isolate, jsRet, "g", v8::Number::New(isolate, v.g));
  SetProperty(isolate, jsRet, "b", v8::Number::New(isolate, v.b));
  SetProperty(isolate, jsRet, "a", v8::Number::New(isolate, v.a));

  return handle_scope.Escape(jsRet);
}

v8::Local<v8::Value> JsbUtils::vector3_to_jsval(v8::Isolate *isolate, const cocos2d::Vec3 &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "x", v8::Number::New(isolate, v.x));
  SetProperty(isolate, jsRet, "y", v8::Number::New(isolate, v.y));
  SetProperty(isolate, jsRet, "z", v8::Number::New(isolate, v.z));

  return handle_scope.Escape(jsRet);
}

v8::Local<v8::Value> JsbUtils::vector2_to_jsval(v8::Isolate *isolate, const cocos2d::Vec2 &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "x", v8::Number::New(isolate, v.x));
  SetProperty(isolate, jsRet, "y", v8::Number::New(isolate, v.y));

  return handle_scope.Escape(jsRet);
}

bool JsbUtils::jsval_to_vector2(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Vec2 *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *outValue = cocos2d::Vec2::ZERO;
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> xVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "x")).ToLocal(&xVal))
  {
    SE_REPORT_ERROR("Failed to get property x from object");
    return false;
  }
  v8::Local<v8::Value> yVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "y")).ToLocal(&yVal))
  {
    SE_REPORT_ERROR("Failed to get property y from object");
    return false;
  }

  outValue->x = xVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->y = yVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  return true;
}

v8::Local<v8::Array> JsbUtils::matrix_to_jsval(v8::Isolate *isolate, const cocos2d::Mat4 &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Array> jsArray = v8::Array::New(isolate, 16);
  for (int i = 0; i < 16; i++)
  {
    jsArray->Set(isolate->GetCurrentContext(), i, v8::Number::New(isolate, v.m[i])).FromJust();
  }

  return handle_scope.Escape(jsArray);
}

v8::Local<v8::Object> JsbUtils::ccaffinetransform_to_jsval(v8::Isolate *isolate, const cocos2d::AffineTransform &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> jsRet = v8::Object::New(isolate);
  SetProperty(isolate, jsRet, "a", v8::Number::New(isolate, v.a));
  SetProperty(isolate, jsRet, "b", v8::Number::New(isolate, v.b));
  SetProperty(isolate, jsRet, "c", v8::Number::New(isolate, v.c));
  SetProperty(isolate, jsRet, "d", v8::Number::New(isolate, v.d));
  SetProperty(isolate, jsRet, "tx", v8::Number::New(isolate, v.tx));
  SetProperty(isolate, jsRet, "ty", v8::Number::New(isolate, v.ty));

  return handle_scope.Escape(jsRet);
}

bool JsbUtils::jsval_to_vector3(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Vec3 *outValue)
{
  // JS::RootedObject tmp(cx);
  // JS::RootedValue jsx(cx);
  // JS::RootedValue jsy(cx);
  // JS::RootedValue jsz(cx);
  // double x, y, z;
  double x = 0.0, y = 0.0, z = 0.0;
  // bool ok = vp.isObject() &&
  // JS_ValueToObject(cx, vp, &tmp) &&
  // JS_GetProperty(cx, tmp, "x", &jsx) &&
  // JS_GetProperty(cx, tmp, "y", &jsy) &&
  // JS_GetProperty(cx, tmp, "z", &jsz) &&
  // JS::ToNumber(cx, jsx, &x) &&
  // JS::ToNumber(cx, jsy, &y) &&
  // JS::ToNumber(cx, jsz, &z) &&
  // !std::isnan(x) && !std::isnan(y) && !std::isnan(z);
  if (!value->IsObject())
  {
    SE_REPORT_ERROR("Value is not an object");
    return false;
  }
  v8::Local<v8::Object> obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> xVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "x")).ToLocal(&xVal))
  {
    SE_REPORT_ERROR("Failed to get property x from object");
    return false;
  }
  v8::Local<v8::Value> yVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "y")).ToLocal(&yVal))
  {
    SE_REPORT_ERROR("Failed to get property y from object");
    return false;
  }
  v8::Local<v8::Value> zVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "z")).ToLocal(&zVal))
  {
    SE_REPORT_ERROR("Failed to get property z from object");
    return false;
  }
  x = xVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  y = yVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  z = zVal->NumberValue(isolate->GetCurrentContext()).FromJust();

  // JSB_PRECONDITION3(ok, cx, false, "Error processing arguments");

  // ret->x = (float)x;
  // ret->y = (float)y;
  // ret->z = (float)z;
  outValue->x = static_cast<float>(x);
  outValue->y = static_cast<float>(y);
  outValue->z = static_cast<float>(z);

  // return true;
  return true;
}

bool JsbUtils::jsval_to_matrix(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Mat4 *outValue)
{
  // JS::RootedObject jsobj(cx);
  // bool ok = vp.isObject() && JS_ValueToObject(cx, vp, &jsobj);
  // JSB_PRECONDITION3(ok, cx, false, "Error converting value to object");
  // JSB_PRECONDITION3(jsobj && JS_IsArrayObject(cx, jsobj), cx, false, "Object must be an matrix");

  // uint32_t len = 0;
  uint32_t len = 0;
  v8::Local<v8::Object> obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

  if (!obj->IsArray())
  {
    SE_REPORT_ERROR("Object must be an array");
    return false;
  }
  v8::Local<v8::Array> arr = obj.As<v8::Array>();
  len = arr->Length();

  if (len != 16)
  {
    SE_REPORT_ERROR("Array length error: %d, was expecting 16", len);
    return false;
  }

  for (uint32_t i = 0; i < len; i++)
  {
    v8::Local<v8::Value> element;
    if (!arr->Get(isolate->GetCurrentContext(), i).ToLocal(&element))
    {
      SE_REPORT_ERROR("Failed to get array element at index %d", i);
      return false;
    }

    if (element->IsNumber())
    {
      double number = element->NumberValue(isolate->GetCurrentContext()).FromJust();
      outValue->m[i] = static_cast<float>(number);
    }
    else
    {
      SE_REPORT_ERROR("Not supported type in matrix");
      return false;
    }
  }

  return true;
}

bool JsbUtils::jsval_to_cccolor3b(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color3B *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *outValue = cocos2d::Color3B::BLACK;
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> rVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "r")).ToLocal(&rVal))
  {
    SE_REPORT_ERROR("Failed to get property r from object");
    return false;
  }
  v8::Local<v8::Value> gVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "g")).ToLocal(&gVal))
  {
    SE_REPORT_ERROR("Failed to get property g from object");
    return false;
  }
  v8::Local<v8::Value> bVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "b")).ToLocal(&bVal))
  {
    SE_REPORT_ERROR("Failed to get property b from object");
    return false;
  }

  outValue->r = static_cast<unsigned char>(rVal->Int32Value(isolate->GetCurrentContext()).FromJust());
  outValue->g = static_cast<unsigned char>(gVal->Int32Value(isolate->GetCurrentContext()).FromJust());
  outValue->b = static_cast<unsigned char>(bVal->Int32Value(isolate->GetCurrentContext()).FromJust());
  return true;
}

v8::Local<v8::Value> JsbUtils::ccsize_to_jsval(v8::Isolate *isolate, const cocos2d::Size &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> obj = v8::Object::New(isolate);
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "width"), v8::Number::New(isolate, v.width)).FromJust();
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "height"), v8::Number::New(isolate, v.height)).FromJust();
  return handle_scope.Escape(obj);
}

v8::Local<v8::Value> JsbUtils::ccrect_to_jsval(v8::Isolate *isolate, const cocos2d::Rect &v)
{
  v8::EscapableHandleScope handle_scope(isolate);
  v8::Local<v8::Object> obj = v8::Object::New(isolate);
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "x"), v8::Number::New(isolate, v.origin.x)).FromJust();
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "y"), v8::Number::New(isolate, v.origin.y)).FromJust();
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "width"), v8::Number::New(isolate, v.size.width)).FromJust();
  obj->Set(isolate->GetCurrentContext(), ToV8String(isolate, "height"), v8::Number::New(isolate, v.size.height)).FromJust();
  return handle_scope.Escape(obj);
}

bool JsbUtils::jsval_to_quaternion(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Quaternion *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> xVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "x")).ToLocal(&xVal))
  {
    SE_REPORT_ERROR("Failed to get property x from object");
    return false;
  }
  v8::Local<v8::Value> yVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "y")).ToLocal(&yVal))
  {
    SE_REPORT_ERROR("Failed to get property y from object");
    return false;
  }
  v8::Local<v8::Value> zVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "z")).ToLocal(&zVal))
  {
    SE_REPORT_ERROR("Failed to get property z from object");
    return false;
  }
  v8::Local<v8::Value> wVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "w")).ToLocal(&wVal))
  {
    SE_REPORT_ERROR("Failed to get property w from object");
    return false;
  }
  outValue->x = xVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->y = yVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->z = zVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->w = wVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  return true;
}

bool JsbUtils::jsval_to_ccsize(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Size *ret)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> widthVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "width")).ToLocal(&widthVal))
  {
    SE_REPORT_ERROR("Failed to get property width from object");
    return false;
  }
  v8::Local<v8::Value> heightVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "height")).ToLocal(&heightVal))
  {
    SE_REPORT_ERROR("Failed to get property height from object");
    return false;
  }
  ret->width = widthVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  ret->height = heightVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  return true;
}

bool JsbUtils::jsval_to_cccolor4f(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color4F *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *outValue = cocos2d::Color4F::BLACK;
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> rVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "r")).ToLocal(&rVal))
  {
    SE_REPORT_ERROR("Failed to get property r from object");
    return false;
  }
  v8::Local<v8::Value> gVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "g")).ToLocal(&gVal))
  {
    SE_REPORT_ERROR("Failed to get property g from object");
    return false;
  }
  v8::Local<v8::Value> bVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "b")).ToLocal(&bVal))
  {
    SE_REPORT_ERROR("Failed to get property b from object");
    return false;
  }
  v8::Local<v8::Value> aVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "a")).ToLocal(&aVal))
  {
    SE_REPORT_ERROR("Failed to get property a from object");
    return false;
  }

  outValue->r = rVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->g = gVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->b = bVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  outValue->a = aVal->NumberValue(isolate->GetCurrentContext()).FromJust();
  return true;
}

bool JsbUtils::jsval_to_blendfunc(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::BlendFunc *outValue)
{
  v8::HandleScope handle_scope(isolate);

  if (value->IsNull() || value->IsUndefined())
  {
    *outValue = cocos2d::BlendFunc::ALPHA_PREMULTIPLIED;
    return true;
  }

  auto obj = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
  v8::Local<v8::Value> srcVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "src")).ToLocal(&srcVal))
  {
    SE_REPORT_ERROR("Failed to get property src from object");
    return false;
  }
  v8::Local<v8::Value> dstVal;
  if (!obj->Get(isolate->GetCurrentContext(), ToV8String(isolate, "dst")).ToLocal(&dstVal))
  {
    SE_REPORT_ERROR("Failed to get property dst from object");
    return false;
  }

  outValue->src = static_cast<cocos2d::backend::BlendFactor>(srcVal->Int32Value(isolate->GetCurrentContext()).FromJust());
  outValue->dst = static_cast<cocos2d::backend::BlendFactor>(dstVal->Int32Value(isolate->GetCurrentContext()).FromJust());
  return true;
}