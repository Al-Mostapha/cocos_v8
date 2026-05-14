#pragma once
#include "JsbConfig.h"
#include <string>
#include <v8.h>

class JsbUtils
{
public:
    static std::string FromV8String(v8::Isolate *isolate, v8::Local<v8::String> str);
    static std::string FromV8String(v8::Isolate *isolate, v8::Local<v8::Value> value);

    static v8::Local<v8::String> ToV8String(v8::Isolate *isolate, const std::string &str);

    static int FromV8Int32(v8::Isolate *isolate, v8::Local<v8::Integer> value);

    static bool SetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> value);

    static bool GetProperty(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *key, v8::Local<v8::Value> *value);
};