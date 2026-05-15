#include "JsbUtils.h"

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