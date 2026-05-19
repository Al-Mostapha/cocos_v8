#pragma once
#include "JsbConfig.h"
#include <string>
#include <v8.h>
#include "Core/JsbObjectWrap.hpp"

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
    static void ClearPrivate(v8::Isolate* isolate, ObjectWrap& wrap);

    static bool DefineFunction(v8::Local<v8::Object> obj, const char *name, void (*callback)(const v8::FunctionCallbackInfo<v8::Value> &));
};