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