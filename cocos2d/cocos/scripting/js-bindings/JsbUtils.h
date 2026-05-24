#pragma once
#include "JsbConfig.h"
#include <string>
#include <v8.h>
#include "Core/JsbObjectWrap.hpp"
#include "base/CCValue.h"
// namespace cocos2d
// {
//     class Value;
//     class ValueMap;
//     class ValueMapIntKey;
//     class ValueVector;
// }

class JsbObject;

struct JsbPrivateData
{
    void *data;
    JsbObject *seObj;
};

class JsbUtils
{
public:
    static std::string FromV8String(v8::Isolate *isolate, v8::Local<v8::String> str);
    static std::string FromV8String(v8::Isolate *isolate, v8::Local<v8::Value> value);

    static v8::Local<v8::String> ToV8String(v8::Isolate *isolate, const std::string &str);

    static int FromV8Int32(v8::Isolate *isolate, v8::Local<v8::Integer> value);

    static bool SetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> value);

    static bool GetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> *value);
    static bool GetProperty(v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> *value);

    static void *GetPrivate(v8::Isolate *isolate, v8::Local<v8::Value> val);

    static void SetPrivate(v8::Isolate *isolate, ObjectWrap &wrap, void *data, JsbPrivateData **outInternalData);
    static void ClearPrivate(v8::Isolate *isolate, ObjectWrap &wrap);

    static bool DefineFunction(v8::Local<v8::Object> obj, const char *name, void (*callback)(const v8::FunctionCallbackInfo<v8::Value> &));

    static bool SetPrivate(v8::Isolate *isolate, void *nativePtr, v8::Local<v8::Object> obj);
    static bool CreateJsObjectByTypeName(const char *typeName, v8::Local<v8::Object> *outObj);
    static bool NativePtrToObject(v8::Isolate *isolate, void *ptr, v8::Local<v8::Object> *outObj);

    static bool jsval_to_ccvalue(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Value *outValue);
    static bool jsval_to_ccvaluemap(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMap *ret);
    static bool jsval_to_ccvaluemapintkey(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMapIntKey *ret);
    static bool jsval_to_ccvaluevector(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueVector *ret);

    static v8::Local<v8::Value> ccvalue_to_jsval(v8::Isolate *isolate, const cocos2d::Value &v);
    static v8::Local<v8::Value> ccvaluemap_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMap &v);
    static v8::Local<v8::Value> ccvaluemapintkey_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMapIntKey &v);
    static v8::Local<v8::Value> ccvaluevector_to_jsval(v8::Isolate *isolate, const cocos2d::ValueVector &v);
};