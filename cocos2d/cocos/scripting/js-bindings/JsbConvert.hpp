#pragma once
#include "v8.h"

namespace cocos2d
{
  class Texture2D;
};

class JsbConvert
{
public:
  static v8::Local<v8::Value> ToV8Value(v8::Isolate *isolate, cocos2d::Texture2D *texture);
  static v8::Local<v8::Value> ToV8Value(v8::Isolate *isolate, long value);
  static v8::Local<v8::Value> ToV8Value(v8::Isolate *isolate, bool value);
  static v8::Local<v8::Value> ToV8Value(v8::Isolate *isolate, const std::string &value);

  template <typename T, typename... Args>
  static std::function<T(Args...)> FromJsFunc(v8::Isolate *isolate,
                                              v8::Local<v8::Function> func,
                                              v8::Local<v8::Object> self);
};


template <typename T, typename... Args>
static std::function<T(Args...)> JsbConvert::FromJsFunc(v8::Isolate *isolate,
                                             v8::Local<v8::Function> func,
                                             v8::Local<v8::Object> self)
{
  // TODO when delete the lambda, the jsGlobalFunc and jsSelf will be
  // destructed, which will make the callback invalid. We need to make sure
  // the callback is not called after the lambda is destructed.
  auto jsGlobalFunc =
      std::make_shared<v8::Global<v8::Function>>(isolate, func);
  auto jsSelf = std::make_shared<v8::Global<v8::Object>>(isolate, self);

  return [jsGlobalFunc, jsSelf, isolate](Args... args) -> T
  {
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Function> fn = jsGlobalFunc->Get(isolate);
    v8::Local<v8::Object> selfObj = jsSelf->Get(isolate);

    constexpr size_t argLength = sizeof...(args);
    std::array<v8::Local<v8::Value>, argLength> argv = { JsbConvert::ToV8Value(isolate, args)... };

    v8::TryCatch tryCatch(isolate);
    fn->Call(isolate->GetCurrentContext(), selfObj, argLength, argv.data())
        .ToLocalChecked();
    if (tryCatch.HasCaught())
    {
      v8::String::Utf8Value error(isolate, tryCatch.Exception());
      SE_REPORT_ERROR("Exception occurred while invoking callback: %s",
                      *error ? *error : "unknown");
    }
  };
}