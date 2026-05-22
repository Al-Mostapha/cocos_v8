/****************************************************************************
 Copyright (c) 2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "JsbObject.hpp"

// #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
// #include "Utils.hpp"
#include "JsbClass.hpp"
#include "ScriptEngine.hpp"
// #include "../MappingUtils.hpp"
#include "Utils/MappingUtils.hpp"
// #include "platform/CCPlatformConfig.h"
// #include <memory>
// #include <unordered_map>

// namespace se {

std::unique_ptr<std::unordered_map<JsbObject *, void *>> __objectMap; // Currently, the value `void*` is always nullptr

namespace
{
  v8::Isolate *__isolate = nullptr;
}

JsbObject::JsbObject()
    : _cls(nullptr), _rootCount(0), _privateData(nullptr), _finalizeCb(nullptr), _internalData(nullptr)
{
}

JsbObject::~JsbObject()
{
  if (_rootCount > 0)
  {
    _obj.unref();
  }

  if (__objectMap)
  {
    __objectMap->erase(this);
  }
}

/*static*/
void JsbObject::nativeObjectFinalizeHook(void *nativeObj)
{
  if (nativeObj == nullptr)
    return;

  auto iter = NativePtrToObjectMap::find(nativeObj);
  if (iter != NativePtrToObjectMap::end())
  {
    // TODO: 
    assert(false);
    // JsbObject *obj = iter->second;
    // NativePtrToObjectMap::erase(iter);
    // if (obj->_finalizeCb != nullptr)
    // {
    //   obj->_finalizeCb(nativeObj);
    // }
    // else
    // {
    //   assert(obj->_getClass() != nullptr);
    //   if (obj->_getClass()->_finalizeFunc != nullptr)
    //     obj->_getClass()->_finalizeFunc(nativeObj);
    // }
    // obj->decRef();
  }
  else
  {
    //            assert(false);
  }
}

/* static */
void JsbObject::setIsolate(v8::Isolate *isolate)
{
  __isolate = isolate;
}

void JsbObject::setup()
{
  __objectMap.reset(new std::unordered_map<JsbObject *, void *>());
}

/* static */
void JsbObject::cleanup()
{
  void *nativeObj = nullptr;
  JsbObject *obj = nullptr;
  Class *cls = nullptr;

  const auto &nativePtrToObjectMap = NativePtrToObjectMap::instance();
  for (const auto &e : nativePtrToObjectMap)
  {
    // TODO:
    assert(false);
    // nativeObj = e.first;
    // obj = e.second;

    // if (obj->_finalizeCb != nullptr)
    // {
    //   obj->_finalizeCb(nativeObj);
    // }
    // else
    // {
    //   if (obj->_getClass() != nullptr)
    //   {
    //     if (obj->_getClass()->_finalizeFunc != nullptr)
    //     {
    //       obj->_getClass()->_finalizeFunc(nativeObj);
    //     }
    //   }
    // }
    // // internal data should only be freed in Object::cleanup, since in other case, it is freed in ScriptEngine::privateDataFinalize
    // if (obj->_internalData != nullptr)
    // {
    //   free(obj->_internalData);
    //   obj->_internalData = nullptr;
    // }
    // obj->decRef();
  }

  NativePtrToObjectMap::clear();
  NonRefNativePtrCreatedByCtorMap::clear();

  if (__objectMap)
  {
    std::vector<JsbObject *> toReleaseObjects;
    for (const auto &e : *__objectMap)
    {
      obj = e.first;
      cls = obj->_getClass();
      obj->_obj.persistent().Reset();
      obj->_rootCount = 0;

      if (cls != nullptr && cls->_name == "__PrivateData")
      {
        toReleaseObjects.push_back(obj);
      }
    }
    for (auto e : toReleaseObjects)
    {
      e->decRef();
    }
  }

  __objectMap.reset();
  __isolate = nullptr;
}

JsbObject *JsbObject::createPlainObject()
{
  v8::Local<v8::Object> jsobj = v8::Object::New(__isolate);
  JsbObject *obj = _createJSObject(nullptr, jsobj);
  return obj;
}

JsbObject *JsbObject::getObjectWithPtr(void *ptr)
{
  JsbObject *obj = nullptr;
  auto iter = NativePtrToObjectMap::find(ptr);
  if (iter != NativePtrToObjectMap::end())
  {
    // TODO
    assert(false);
    // obj = iter->second;
    // obj->incRef();
  }
  return obj;
}

JsbObject *JsbObject::_createJSObject(Class *cls, v8::Local<v8::Object> obj)
{
  JsbObject *ret = new JsbObject();
  if (!ret->init(cls, obj))
  {
    delete ret;
    ret = nullptr;
  }
  return ret;
}

JsbObject *JsbObject::createObjectWithClass(Class *cls)
{
  v8::Local<v8::Object> jsobj = Class::_createJSObjectWithClass(cls);
  JsbObject *obj = JsbObject::_createJSObject(cls, jsobj);
  return obj;
}

JsbObject *JsbObject::createArrayObject(size_t length)
{
  v8::Local<v8::Array> jsobj = v8::Array::New(__isolate, (int)length);
  JsbObject *obj = JsbObject::_createJSObject(nullptr, jsobj);
  return obj;
}

JsbObject *JsbObject::createArrayBufferObject(void *data, size_t byteLength)
{
  v8::Local<v8::ArrayBuffer> jsobj = v8::ArrayBuffer::New(__isolate, byteLength);

#if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY
  if (data)
  {
    memcpy(jsobj->GetBackingStore()->Data(), data, byteLength);
  }
  else
  {
    memset(jsobj->GetBackingStore()->Data(), 0, byteLength);
  }
#else
  if (data)
  {
    memcpy(jsobj->GetContents().Data(), data, byteLength);
  }
  else
  {
    memset(jsobj->GetContents().Data(), 0, byteLength);
  }
#endif
  JsbObject *obj = JsbObject::_createJSObject(nullptr, jsobj);
  return obj;
}

JsbObject *JsbObject::createTypedArray(TypedArrayType type, void *data, size_t byteLength)
{
  if (type == TypedArrayType::NONE)
  {
    SE_LOGE("Don't pass se::Object::TypedArrayType::NONE to createTypedArray API!");
    return nullptr;
  }

  if (type == TypedArrayType::UINT8_CLAMPED)
  {
    SE_LOGE("Doesn't support to create Uint8ClampedArray with Object::createTypedArray API!");
    return nullptr;
  }

  v8::Local<v8::ArrayBuffer> jsobj = v8::ArrayBuffer::New(__isolate, byteLength);
  // If data has content,then will copy data into buffer,or will only clear buffer.
#if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY
  if (data)
  {
    memcpy(jsobj->GetBackingStore()->Data(), data, byteLength);
  }
  else
  {
    memset(jsobj->GetBackingStore()->Data(), 0, byteLength);
  }
#else
  if (data)
  {
    memcpy(jsobj->GetContents().Data(), data, byteLength);
  }
  else
  {
    memset(jsobj->GetContents().Data(), 0, byteLength);
  }
#endif

  v8::Local<v8::Object> arr;
  switch (type)
  {
  case TypedArrayType::INT8:
    arr = v8::Int8Array::New(jsobj, 0, byteLength);
    break;
  case TypedArrayType::INT16:
    arr = v8::Int16Array::New(jsobj, 0, byteLength / 2);
    break;
  case TypedArrayType::INT32:
    arr = v8::Int32Array::New(jsobj, 0, byteLength / 4);
    break;
  case TypedArrayType::UINT8:
    arr = v8::Uint8Array::New(jsobj, 0, byteLength);
    break;
  case TypedArrayType::UINT16:
    arr = v8::Uint16Array::New(jsobj, 0, byteLength / 2);
    break;
  case TypedArrayType::UINT32:
    arr = v8::Uint32Array::New(jsobj, 0, byteLength / 4);
    break;
  case TypedArrayType::FLOAT32:
    arr = v8::Float32Array::New(jsobj, 0, byteLength / 4);
    break;
  case TypedArrayType::FLOAT64:
    arr = v8::Float64Array::New(jsobj, 0, byteLength / 8);
    break;
  default:
    assert(false); // Should never go here.
    break;
  }

  JsbObject *obj = JsbObject::_createJSObject(nullptr, arr);
  return obj;
}

JsbObject *JsbObject::createUint8TypedArray(uint8_t *data, size_t dataCount)
{
  return createTypedArray(TypedArrayType::UINT8, data, dataCount);
}

JsbObject *JsbObject::createJSONObject(const std::string &jsonStr)
{
  v8::Local<v8::Context> context = __isolate->GetCurrentContext();
  // Value strVal(jsonStr);
  // v8::Local<v8::Value> jsStr;
  // internal::seToJsValue(__isolate, strVal, &jsStr);

  v8::Local<v8::String> v8Str = v8::String::NewFromUtf8(__isolate, jsonStr.c_str(), v8::NewStringType::kNormal).ToLocalChecked();
  v8::MaybeLocal<v8::Value> ret = v8::JSON::Parse(context, v8Str);
  if (ret.IsEmpty())
    return nullptr;

  v8::Local<v8::Object> jsobj = v8::Local<v8::Object>::Cast(ret.ToLocalChecked());
  return JsbObject::_createJSObject(nullptr, jsobj);
}

bool JsbObject::init(Class *cls, v8::Local<v8::Object> obj)
{
  _cls = cls;

  _obj.init(obj);
  _obj.setFinalizeCallback(nativeObjectFinalizeHook);

  if (__objectMap)
  {
    assert(__objectMap->find(this) == __objectMap->end());
    __objectMap->emplace(this, nullptr);
  }

  return true;
}

bool JsbObject::getProperty(const char *name, v8::Local<v8::Value> *data)
{
  assert(data != nullptr);
  *data = v8::Undefined(__isolate);

  v8::EscapableHandleScope handle_scope(__isolate);

  if (_obj.persistent().IsEmpty())
  {
    return false;
  }

  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
  v8::Local<v8::Context> context = __isolate->GetCurrentContext();
  v8::Maybe<bool> maybeExist = _obj.handle(__isolate)->Has(context, nameValToLocal);
  if (maybeExist.IsNothing())
    return false;

  if (!maybeExist.FromJust())
    return false;

  v8::MaybeLocal<v8::Value> result = _obj.handle(__isolate)->Get(context, nameValToLocal);
  if (result.IsEmpty())
    return false;

  // internal::jsToSeValue(__isolate, result.ToLocalChecked(), data);
  *data = handle_scope.Escape(result.ToLocalChecked());

  return true;
}

bool JsbObject::deleteProperty(const char *name)
{

  v8::HandleScope handle_scope(__isolate);

  if (_obj.persistent().IsEmpty())
  {
    return false;
  }

  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  v8::Local<v8::String> nameValToLocal = nameValue.ToLocalChecked();
  v8::Local<v8::Context> context = __isolate->GetCurrentContext();
  v8::Maybe<bool> maybeExist = _obj.handle(__isolate)->Delete(context, nameValToLocal);
  if (maybeExist.IsNothing())
    return false;

  if (!maybeExist.FromJust())
    return false;

  return true;
}

bool JsbObject::setProperty(const char *name, v8::Local<v8::Value> data)
{
  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  // v8::Local<v8::Value> value;
  // internal::seToJsValue(__isolate, data, &value);
  v8::Maybe<bool> ret = _obj.handle(__isolate)->Set(__isolate->GetCurrentContext(), nameValue.ToLocalChecked(), data);
  if (ret.IsNothing())
  {
    SE_LOGD("ERROR: %s, Set return nothing ...\n", __FUNCTION__);
    return false;
  }
  return true;
}

bool JsbObject::defineProperty(const char *name, v8::AccessorNameGetterCallback getter, v8::AccessorNameSetterCallback setter)
{
  v8::MaybeLocal<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal);
  if (nameValue.IsEmpty())
    return false;

  v8::Local<v8::String> nameValChecked = nameValue.ToLocalChecked();
  v8::Local<v8::Name> jsName = v8::Local<v8::Name>::Cast(nameValChecked);
  v8::Maybe<bool> ret = _obj.handle(__isolate)->SetAccessor(__isolate->GetCurrentContext(), jsName, getter, setter);
  return ret.IsJust() && ret.FromJust();
}

bool JsbObject::isFunction() const
{
  return const_cast<JsbObject *>(this)->_obj.handle(__isolate)->IsCallable();
}

bool JsbObject::_isNativeFunction() const
{
  if (isFunction())
  {
    std::string info = toString();
    if (info.find("[native code]") != std::string::npos)
    {
      return true;
    }
  }
  return false;
}

bool JsbObject::isTypedArray() const
{
  return const_cast<JsbObject *>(this)->_obj.handle(__isolate)->IsTypedArray();
}

JsbObject::TypedArrayType JsbObject::getTypedArrayType() const
{
  v8::Local<v8::Value> value = const_cast<JsbObject *>(this)->_obj.handle(__isolate);
  TypedArrayType ret = TypedArrayType::NONE;
  if (value->IsInt8Array())
    ret = TypedArrayType::INT8;
  else if (value->IsInt16Array())
    ret = TypedArrayType::INT16;
  else if (value->IsInt32Array())
    ret = TypedArrayType::INT32;
  else if (value->IsUint8Array())
    ret = TypedArrayType::UINT8;
  else if (value->IsUint8ClampedArray())
    ret = TypedArrayType::UINT8_CLAMPED;
  else if (value->IsUint16Array())
    ret = TypedArrayType::UINT16;
  else if (value->IsUint32Array())
    ret = TypedArrayType::UINT32;
  else if (value->IsFloat32Array())
    ret = TypedArrayType::FLOAT32;
  else if (value->IsFloat64Array())
    ret = TypedArrayType::FLOAT64;

  return ret;
}

bool JsbObject::getTypedArrayData(uint8_t **ptr, size_t *length) const
{
  assert(isTypedArray());
  v8::Local<v8::Object> obj = const_cast<JsbObject *>(this)->_obj.handle(__isolate);
  v8::Local<v8::TypedArray> arr = v8::Local<v8::TypedArray>::Cast(obj);
#if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY
  const auto &backingStore = arr->Buffer()->GetBackingStore();
  *ptr = static_cast<uint8_t *>(backingStore->Data()) + arr->ByteOffset();
#else
  v8::ArrayBuffer::Contents content = arr->Buffer()->GetContents();
  *ptr = (uint8_t *)content.Data() + arr->ByteOffset();
#endif

  *length = arr->ByteLength();
  return true;
}

bool JsbObject::isArrayBuffer() const
{
  v8::Local<v8::Object> obj = const_cast<JsbObject *>(this)->_obj.handle(__isolate);
  return obj->IsArrayBuffer();
}

bool JsbObject::getArrayBufferData(uint8_t **ptr, size_t *length) const
{
  assert(isArrayBuffer());
  v8::Local<v8::Object> obj = const_cast<JsbObject *>(this)->_obj.handle(__isolate);
  v8::Local<v8::ArrayBuffer> arrBuf = v8::Local<v8::ArrayBuffer>::Cast(obj);
#if CC_TARGET_PLATFORM == CC_PLATFORM_OPENHARMONY
  const auto &backingStore = arrBuf->GetBackingStore();
  *ptr = static_cast<uint8_t *>(backingStore->Data());
  *length = backingStore->ByteLength();
#else
  v8::ArrayBuffer::Contents content = arrBuf->GetContents();
  *ptr = (uint8_t *)content.Data();
  *length = content.ByteLength();
#endif
  return true;
}

void JsbObject::setPrivateData(void *data)
{
  // assert(_privateData == nullptr);
  // assert(NativePtrToObjectMap::find(data) == NativePtrToObjectMap::end());
  // // internal::setPrivate(__isolate, _obj, data, &_internalData);
  // JsbUtils::SetPrivate(__isolate, _obj, data, &_internalData);
  // NativePtrToObjectMap::emplace(data, this);
  // _privateData = data;
  // TODO:
  assert(false);
}

void *JsbObject::getPrivateData() const
{
  if (_privateData == nullptr)
  {
    const_cast<JsbObject *>(this)->_privateData = JsbUtils::GetPrivate(__isolate, const_cast<JsbObject *>(this)->_obj.handle(__isolate));
  }
  return _privateData;
}

void JsbObject::clearPrivateData(bool clearMapping)
{
  if (_privateData != nullptr)
  {
    if (clearMapping)
      NativePtrToObjectMap::erase(_privateData);
    // internal::clearPrivate(__isolate, _obj);
    JsbUtils::ClearPrivate(__isolate, _obj);
    _privateData = nullptr;
  }
}

v8::Local<v8::Object> JsbObject::_getJSObject() const
{
  return const_cast<JsbObject *>(this)->_obj.handle(__isolate);
}

ObjectWrap &JsbObject::_getWrap()
{
  return _obj;
}

bool JsbObject::call(const std::vector<v8::Local<v8::Value>> &args, JsbObject *thisObject, v8::Local<v8::Value> *rval /* = nullptr*/)
{
  if (_obj.persistent().IsEmpty())
  {
    SE_LOGD("Function object is released!\n");
    return false;
  }
  size_t argc = 0;
  std::vector<v8::Local<v8::Value>> argv;
  argv.reserve(10);
  argc = args.size();
  // internal::seToJsArgs(__isolate, args, &argv);

  v8::Local<v8::Object> thiz = v8::Local<v8::Object>::Cast(v8::Undefined(__isolate));
  if (thisObject != nullptr)
  {
    if (thisObject->_obj.persistent().IsEmpty())
    {
      SE_LOGD("This object is released!\n");
      return false;
    }
    thiz = thisObject->_obj.handle(__isolate);
  }

  for (size_t i = 0; i < argc; ++i)
  {
    if (argv[i].IsEmpty())
    {
      SE_LOGD("%s argv[%d] is released!\n", __FUNCTION__, (int)i);
      return false;
    }
  }

  v8::Local<v8::Context> context = ScriptEngine::getInstance()->_getContext();
  v8::MaybeLocal<v8::Value> result = _obj.handle(__isolate)->CallAsFunction(context, thiz, (int)argc, argv.data());

  if (!result.IsEmpty())
  {
    if (rval != nullptr)
    {
      // internal::jsToSeValue(__isolate, result.ToLocalChecked(), rval);
      *rval = result.ToLocalChecked();
    }
    return true;
  }
  else
  {
    SE_REPORT_ERROR("Invoking function (%p) failed!", this);
    ScriptEngine::getInstance()->clearException();
  }

  //        assert(false);

  return false;
}

bool JsbObject::defineFunction(const char *funcName, void (*func)(const v8::FunctionCallbackInfo<v8::Value> &args))
{
  v8::MaybeLocal<v8::String> maybeFuncName = v8::String::NewFromUtf8(__isolate, funcName, v8::NewStringType::kNormal);
  if (maybeFuncName.IsEmpty())
    return false;

  v8::Local<v8::Context> context = __isolate->GetCurrentContext();
  v8::MaybeLocal<v8::Function> maybeFunc = v8::FunctionTemplate::New(__isolate, func)->GetFunction(context);
  if (maybeFunc.IsEmpty())
    return false;

  v8::Maybe<bool> ret = _obj.handle(__isolate)->Set(context,
                                                    v8::Local<v8::Name>::Cast(maybeFuncName.ToLocalChecked()),
                                                    maybeFunc.ToLocalChecked());

  return ret.IsJust() && ret.FromJust();
}

bool JsbObject::isArray() const
{
  return const_cast<JsbObject *>(this)->_obj.handle(__isolate)->IsArray();
}

bool JsbObject::getArrayLength(uint32_t *length) const
{
  assert(isArray());
  assert(length != nullptr);
  JsbObject *thiz = const_cast<JsbObject *>(this);

  v8::MaybeLocal<v8::String> lengthStr = v8::String::NewFromUtf8(__isolate, "length", v8::NewStringType::kNormal);
  if (lengthStr.IsEmpty())
  {
    *length = 0;
    return false;
  }
  v8::Local<v8::Context> context = __isolate->GetCurrentContext();

  v8::MaybeLocal<v8::Value> val = thiz->_obj.handle(__isolate)->Get(context, lengthStr.ToLocalChecked());
  if (val.IsEmpty())
    return false;

  v8::MaybeLocal<v8::Object> obj = val.ToLocalChecked()->ToObject(context);
  if (obj.IsEmpty())
    return false;

  v8::Maybe<uint32_t> mbLen = obj.ToLocalChecked()->Uint32Value(context);
  if (mbLen.IsNothing())
    return false;

  *length = mbLen.FromJust();
  return true;
}

bool JsbObject::getArrayElement(uint32_t index, v8::Local<v8::Value> *data) const
{
  assert(isArray());
  assert(data != nullptr);
  JsbObject *thiz = const_cast<JsbObject *>(this);
  v8::MaybeLocal<v8::Value> result = thiz->_obj.handle(__isolate)->Get(__isolate->GetCurrentContext(), index);

  if (result.IsEmpty())
    return false;

  // internal::jsToSeValue(__isolate, result.ToLocalChecked(), data);
  *data = result.ToLocalChecked();
  return true;
}

bool JsbObject::setArrayElement(uint32_t index, const v8::Local<v8::Value> &data)
{
  assert(isArray());

  // internal::seToJsValue(__isolate, data, &jsval);
  v8::Maybe<bool> ret = _obj.handle(__isolate)->Set(__isolate->GetCurrentContext(), index, data);

  return ret.IsJust() && ret.FromJust();
}

bool JsbObject::getAllKeys(std::vector<std::string> *allKeys) const
{
  assert(allKeys != nullptr);
  JsbObject *thiz = const_cast<JsbObject *>(this);
  v8::Local<v8::Context> context = __isolate->GetCurrentContext();
  v8::MaybeLocal<v8::Array> keys = thiz->_obj.handle(__isolate)->GetOwnPropertyNames(context);
  if (keys.IsEmpty())
    return false;

  v8::Local<v8::Array> keysChecked = keys.ToLocalChecked();
  v8::Local<v8::Value> keyVal;
  for (uint32_t i = 0, len = keysChecked->Length(); i < len; ++i)
  {
    v8::MaybeLocal<v8::Value> key = keysChecked->Get(context, i);
    if (key.IsEmpty())
    {
      allKeys->clear();
      return false;
    }
    // internal::jsToSeValue(__isolate, key.ToLocalChecked(), &keyVal);
    keyVal = key.ToLocalChecked();
    if (keyVal->IsString())
    {
      v8::String::Utf8Value utf8(__isolate, keyVal);
      allKeys->push_back(*utf8);
    }
    else if (keyVal->IsNumber())
    {
      char buf[50] = {0};
      snprintf(buf, sizeof(buf), "%d", keyVal->Int32Value(context).FromJust());
      allKeys->push_back(buf);
    }
    else
    {
      assert(false);
    }
  }
  return true;
}

Class *JsbObject::_getClass() const
{
  return _cls;
}

void JsbObject::_setFinalizeCallback(V8FinalizeFunc finalizeCb)
{
  assert(finalizeCb != nullptr);
  _finalizeCb = finalizeCb;
}

void JsbObject::root()
{
  if (_rootCount == 0)
  {
    _obj.ref();
  }
  ++_rootCount;
}

void JsbObject::unroot()
{
  if (_rootCount > 0)
  {
    --_rootCount;
    if (_rootCount == 0)
    {
      _obj.unref();
    }
  }
}

bool JsbObject::isRooted() const
{
  return _rootCount > 0;
}

bool JsbObject::strictEquals(JsbObject *o) const
{
  JsbObject *a = const_cast<JsbObject *>(this);
  return a->_obj.handle(__isolate) == o->_obj.handle(__isolate);
}

bool JsbObject::attachObject(JsbObject *obj)
{
  assert(obj);

  auto global = ScriptEngine::getInstance()->getGlobalObject();
  v8::Local<v8::Value> jsbVal;
  if (!JsbUtils::GetProperty(global, "jsb", &jsbVal))
    return false;
  // JsbObject *jsbObj = jsbVal.toObject();

  v8::Local<v8::Value> func;

  if (!JsbUtils::GetProperty(jsbVal.As<v8::Object>(), "registerNativeRef", &func))
    return false;

  std::vector<v8::Local<v8::Value>> args;

  // args.push_back(Value(this));
  // args.push_back(Value(obj));
  // func->call(args, global);
  args.push_back(this->_getJSObject());
  args.push_back(obj->_getJSObject());

  v8::Local<v8::Context> context = ScriptEngine::getInstance()->_getContext();
  v8::MaybeLocal<v8::Value> result = func.As<v8::Function>()->CallAsFunction(context, global, (int)args.size(), args.data());
  return true;
}

bool JsbObject::detachObject(JsbObject *obj)
{
  assert(obj);

  v8::Local<v8::Object> global = ScriptEngine::getInstance()->getGlobalObject();
  v8::Local<v8::Value> jsbVal;
  if (!JsbUtils::GetProperty(global, "jsb", &jsbVal))
    return false;

  v8::Local<v8::Value> func;

  if (!JsbUtils::GetProperty(jsbVal.As<v8::Object>(), "unregisterNativeRef", &func))
    return false;

  std::vector<v8::Local<v8::Value>> args;
  args.push_back(this->_getJSObject());
  args.push_back(obj->_getJSObject());
  func.As<v8::Function>()->CallAsFunction(ScriptEngine::getInstance()->_getContext(), global, (int)args.size(), args.data());
  return true;
}

std::string JsbObject::toString() const
{
  std::string ret;
  if (isFunction() || isArray() || isTypedArray())
  {
    v8::String::Utf8Value utf8(__isolate, const_cast<JsbObject *>(this)->_obj.handle(__isolate));
    ret = *utf8;
  }
  else if (isArrayBuffer())
  {
    ret = "[object ArrayBuffer]";
  }
  else
  {
    ret = "[object Object]";
  }
  return ret;
}

// } // namespace se {

// #endif // #if SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8
