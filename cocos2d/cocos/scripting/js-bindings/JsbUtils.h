#pragma once
#include "JsbConfig.h"
#include <string>
#include <v8.h>
#include "Core/JsbObjectWrap.hpp"
#include "base/CCValue.h"
#include "base/CCVector.h"
#include "base/ccTypes.h"
#include "math/CCAffineTransform.h"
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
    static bool NativePtrToObject(const char *typeName, void *ptr, v8::Local<v8::Object> *outObj);

    static bool GetOrCreateJsObject(v8::Isolate *isolate, v8::Local<v8::Object> obj, const char *name, v8::Local<v8::Object> *outObj);

    static v8::Local<v8::FunctionTemplate> CreateClass(v8::Isolate *isolate, const char *className, v8::FunctionCallback constructor);

    static bool RegisterV8Class(const char *className, v8::Local<v8::FunctionTemplate> *constructor);

        static std::function<void()> FromJsFunc(v8::Isolate *isolate, v8::Local<v8::Function> func, v8::Local<v8::Object> self)
    {
        // TODO when delete the lambda, the jsGlobalFunc and jsSelf will be destructed, which will make the callback invalid. We need to make sure the callback is not called after the lambda is destructed.
        auto jsGlobalFunc = std::make_shared<v8::Global<v8::Function>>(isolate, func);
        auto jsSelf = std::make_shared<v8::Global<v8::Object>>(isolate, self);

        return [jsGlobalFunc, jsSelf, isolate]() -> void
        {
            v8::HandleScope handleScope(isolate);
            v8::Local<v8::Function> fn = jsGlobalFunc->Get(isolate);
            v8::Local<v8::Object> selfObj = jsSelf->Get(isolate);

            v8::TryCatch tryCatch(isolate);
            fn->Call(isolate->GetCurrentContext(), selfObj, 0, nullptr).ToLocalChecked();
            if (tryCatch.HasCaught())
            {
                v8::String::Utf8Value error(isolate, tryCatch.Exception());
                SE_REPORT_ERROR("Exception occurred while invoking callback: %s", *error ? *error : "unknown");
            }
        };
    }

    static bool jsval_to_ccvalue(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Value *outValue);
    static bool jsval_to_ccvaluemap(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMap *ret);
    static bool jsval_to_ccvaluemapintkey(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueMapIntKey *ret);
    static bool jsval_to_ccvaluevector(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::ValueVector *ret);
    static bool jsval_to_ccsize(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Size *ret);
    static bool jsval_to_cccolor4b(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color4B *ret);
    static bool jsval_to_ccrect(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Rect *ret);

    static v8::Local<v8::Value> ccvalue_to_jsval(v8::Isolate *isolate, const cocos2d::Value &v);
    static v8::Local<v8::Value> ccvaluemap_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMap &v);
    static v8::Local<v8::Value> ccvaluemapintkey_to_jsval(v8::Isolate *isolate, const cocos2d::ValueMapIntKey &v);
    static v8::Local<v8::Value> ccvaluevector_to_jsval(v8::Isolate *isolate, const cocos2d::ValueVector &v);

    static v8::Local<v8::Value> cccolor3b_to_jsval(v8::Isolate *isolate, const cocos2d::Color3B &v);
    static v8::Local<v8::Value> cccolor4f_to_jsval(v8::Isolate *isolate, const cocos2d::Color4F &v);
    static v8::Local<v8::Value> cccolor4b_to_jsval(v8::Isolate *isolate, const cocos2d::Color4B &v);
    static v8::Local<v8::Value> ccsize_to_jsval(v8::Isolate *isolate, const cocos2d::Size &v);
    static v8::Local<v8::Value> ccrect_to_jsval(v8::Isolate *isolate, const cocos2d::Rect &v);
    static v8::Local<v8::Value> blendfunc_to_jsval(v8::Isolate *isolate, const cocos2d::BlendFunc &v);

    static bool jsval_to_quaternion(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Quaternion *outValue);

    template <class T>
    static v8::Local<v8::Value> ccvector_to_jsval(v8::Isolate *isolate, const cocos2d::Vector<T> &v)
    {
        // JS::RootedObject jsretArr(isolate, JS_NewArrayObject(isolate, 0));
        v8::Local<v8::Array> jsretArr = v8::Array::New(isolate, 0);
        int i = 0;
        for (const auto &obj : v)
        {
            //     JS::RootedValue arrElement(cx);
            v8::Local<v8::Object> arrElement;
            JsbUtils::NativePtrToObject(typeid(*obj).name(), obj, &arrElement);
            //     // First, check whether object is associated with js object.
            //     js_type_class_t *typeClass = js_get_type_from_native(obj);
            //     JS::RootedObject jsobject(cx, jsb_ref_get_or_create_jsobject(cx, obj, typeClass, typeid(*obj).name()));
            //     if (jsobject.get())
            //     {
            //         arrElement = OBJECT_TO_JSVAL(jsobject);
            //     }

            //     if (!JS_SetElement(cx, jsretArr, i, arrElement))
            //     {
            //         break;
            //     }
            //     ++i;
            v8::Maybe<bool> maybe = jsretArr->Set(isolate->GetCurrentContext(), i, arrElement);
            if (maybe.IsNothing() || !maybe.FromJust())
            {
                SE_REPORT_ERROR("Failed to set array element at index %d", i);
                break;
            }
            ++i;
        }
        return jsretArr;
    }

    static v8::Local<v8::Value> vector3_to_jsval(v8::Isolate *isolate, const cocos2d::Vec3 &v);
    static v8::Local<v8::Value> vector2_to_jsval(v8::Isolate *isolate, const cocos2d::Vec2 &v);

    static v8::Local<v8::Array> matrix_to_jsval(v8::Isolate *isolate, const cocos2d::Mat4 &v);
    static v8::Local<v8::Object> ccaffinetransform_to_jsval(v8::Isolate *isolate, const cocos2d::AffineTransform &v);

    static bool jsval_to_vector2(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Vec2 *outValue);
    static bool jsval_to_vector3(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Vec3 *outValue);
    static bool jsval_to_matrix(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Mat4 *outValue);

    static bool jsval_to_cccolor3b(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color3B *outValue);
    static bool jsval_to_cccolor4f(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::Color4F *outValue);
    static bool jsval_to_blendfunc(v8::Isolate *isolate, v8::Local<v8::Value> value, cocos2d::BlendFunc *outValue);
};