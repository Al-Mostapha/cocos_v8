
#include "JsbCtor.hpp"

void CallCustomConstructor(const v8::FunctionCallbackInfo<v8::Value> &args, v8::Local<v8::Object> obj)
{
  v8::Isolate *isolate = args.GetIsolate();
  v8::Local<v8::Value> ctor;
  if (JsbUtils::GetProperty(isolate, obj, "_ctor", &ctor))
  {
    if (ctor->IsFunction())
    {
      // TODO check if the function is a class method or global function
      v8::Local<v8::Function> ctorFunc = ctor.As<v8::Function>();
      ctorFunc->Call(isolate->GetCurrentContext(), obj, args.Length(), &args.Data()).ToLocalChecked();
    }
  }
}