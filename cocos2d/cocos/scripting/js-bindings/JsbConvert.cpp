#include "JsbConvert.hpp"
#include "JsbUtils.h"
#include "renderer/CCTexture2D.h"

v8::Local<v8::Value> JsbConvert::ToV8Value(v8::Isolate *isolate, cocos2d::Texture2D *texture)
{
  v8::EscapableHandleScope handle_scope(isolate);

  if (texture == nullptr)
  {
    return v8::Null(isolate);
  }
  return handle_scope.Escape(JsbUtils::NativePtrToObject(texture));
}

v8::Local<v8::Value> JsbConvert::ToV8Value(v8::Isolate *isolate, long value)
{
  v8::EscapableHandleScope handle_scope(isolate);
  return handle_scope.Escape(v8::Number::New(isolate, static_cast<double>(value)));
}

v8::Local<v8::Value> JsbConvert::ToV8Value(v8::Isolate *isolate, bool value)
{
  v8::EscapableHandleScope handle_scope(isolate);
  return handle_scope.Escape(v8::Boolean::New(isolate, value));
}

v8::Local<v8::Value> JsbConvert::ToV8Value(v8::Isolate *isolate, const std::string &value)
{
  v8::EscapableHandleScope handle_scope(isolate);
  return handle_scope.Escape(v8::String::NewFromUtf8(isolate, value.c_str()).ToLocalChecked());
}