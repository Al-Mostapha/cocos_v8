#pragma once
#include "v8.h"
#include "JsbConfig.h"
#include "base/CCData.h"
#include <cassert>

template <typename T>
bool seval_to_native_ptr(const v8::Local<v8::Value> &v, T *ret)
{
    assert(ret != nullptr);
    v8::Isolate *isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (v->IsObject())
    {
        T ptr = (T)v->ToObject(context).ToLocalChecked()->GetAlignedPointerFromInternalField(0);
        if (ptr == nullptr)
        {
            // This should never happen, return 'false' to mark the conversion fails.
            *ret = nullptr;
            return false;
        }

        *ret = ptr;
        return true;
    }
    else if (v->IsNull() || v->IsUndefined())
    {
        // If js value is null or undefined, the convertion should be successful.
        // So we should return 'true' to indicate the convertion succeeds and mark
        // the out value to 'nullptr'.
        *ret = nullptr;
        return true;
    }

    // If js value isn't null, undefined and Object, mark the convertion fails.
    *ret = nullptr;
    return false;
}

bool seval_to_Data(const v8::Local<v8::Value> &v, cocos2d::Data *ret)
{
    v8::Isolate *isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    assert(ret != nullptr);
    // TODO
    assert(false);
    // SE_PRECONDITION2(v->IsObject() && v->ToObject(context)->IsTypedArray(), false, "Convert parameter to Data failed!");
    // uint8_t *ptr = nullptr;
    // size_t length = 0;
    // bool ok = v->ToObject(context).ToLocalChecked()->GetTypedArrayData(&ptr, &length);
    // if (ok)
    // {
    //     ret->copy(ptr, length);
    // }
    // else
    // {
    //     ret->clear();
    // }

    return false;
}