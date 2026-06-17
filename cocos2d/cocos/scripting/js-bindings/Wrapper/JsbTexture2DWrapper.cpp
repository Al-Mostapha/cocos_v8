JSClass *jsb_cocos2d_TextureCache_class;
JSObject *jsb_cocos2d_TextureCache_prototype;

bool js_cocos2dx_TextureCache_reloadTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_reloadTexture : Invalid Native Object");
    if (argc == 1)
    {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_reloadTexture : Error processing arguments");
        bool ret = cobj->reloadTexture(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_reloadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_unbindAllImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_unbindAllImageAsync : Invalid Native Object");
    if (argc == 0)
    {
        cobj->unbindAllImageAsync();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_unbindAllImageAsync : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_removeTextureForKey(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_removeTextureForKey : Invalid Native Object");
    if (argc == 1)
    {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_removeTextureForKey : Error processing arguments");
        cobj->removeTextureForKey(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_removeTextureForKey : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_removeAllTextures(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_removeAllTextures : Invalid Native Object");
    if (argc == 0)
    {
        cobj->removeAllTextures();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_removeAllTextures : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_addImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
{
    bool ok = true;
    cocos2d::TextureCache *cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_addImageAsync : Invalid Native Object");
    do
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok)
            {
                ok = true;
                break;
            }
            std::function<void(cocos2d::Texture2D *)> arg1;
            do
            {
                if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
                {
                    JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
                    std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
                    auto lambda = [=](cocos2d::Texture2D *larg0) -> void
                    {
                        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
                        jsval largv[1];
                        if (larg0)
                        {
                            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)larg0));
                        }
                        else
                        {
                            largv[0] = JSVAL_NULL;
                        };
                        JS::RootedValue rval(cx);
                        bool succeed = func->invoke(1, &largv[0], &rval);
                        if (!succeed && JS_IsExceptionPending(cx))
                        {
                            JS_ReportPendingException(cx);
                        }
                    };
                    arg1 = lambda;
                }
                else
                {
                    arg1 = nullptr;
                }
            } while (0);
            if (!ok)
            {
                ok = true;
                break;
            }
            std::string arg2;
            ok &= jsval_to_std_string(cx, args.get(2), &arg2);
            if (!ok)
            {
                ok = true;
                break;
            }
            cobj->addImageAsync(arg0, arg1, arg2);
            args.rval().setUndefined();
            return true;
        }
    } while (0);

    do
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok)
            {
                ok = true;
                break;
            }
            std::function<void(cocos2d::Texture2D *)> arg1;
            do
            {
                if (JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
                {
                    JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
                    std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
                    auto lambda = [=](cocos2d::Texture2D *larg0) -> void
                    {
                        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
                        jsval largv[1];
                        if (larg0)
                        {
                            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)larg0));
                        }
                        else
                        {
                            largv[0] = JSVAL_NULL;
                        };
                        JS::RootedValue rval(cx);
                        bool succeed = func->invoke(1, &largv[0], &rval);
                        if (!succeed && JS_IsExceptionPending(cx))
                        {
                            JS_ReportPendingException(cx);
                        }
                    };
                    arg1 = lambda;
                }
                else
                {
                    arg1 = nullptr;
                }
            } while (0);
            if (!ok)
            {
                ok = true;
                break;
            }
            cobj->addImageAsync(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while (0);

    JS_ReportError(cx, "js_cocos2dx_TextureCache_addImageAsync : wrong number of arguments");
    return false;
}
bool js_cocos2dx_TextureCache_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_getDescription : Invalid Native Object");
    if (argc == 0)
    {
        std::string ret = cobj->getDescription();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_getCachedTextureInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_getCachedTextureInfo : Invalid Native Object");
    if (argc == 0)
    {
        std::string ret = cobj->getCachedTextureInfo();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_getCachedTextureInfo : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_addImage(JSContext *cx, uint32_t argc, jsval *vp)
{
    bool ok = true;
    cocos2d::TextureCache *cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_addImage : Invalid Native Object");
    do
    {
        if (argc == 2)
        {
            cocos2d::Image *arg0 = nullptr;
            do
            {
                if (args.get(0).isNull())
                {
                    arg0 = nullptr;
                    break;
                }
                if (!args.get(0).isObject())
                {
                    ok = false;
                    break;
                }
                js_proxy_t *jsProxy;
                JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
                jsProxy = jsb_get_js_proxy(tmpObj);
                arg0 = (cocos2d::Image *)(jsProxy ? jsProxy->ptr : NULL);
                JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
            } while (0);
            if (!ok)
            {
                ok = true;
                break;
            }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok)
            {
                ok = true;
                break;
            }
            cocos2d::Texture2D *ret = cobj->addImage(arg0, arg1);
            jsval jsret = JSVAL_NULL;
            if (ret)
            {
                jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
            }
            else
            {
                jsret = JSVAL_NULL;
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);

    do
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok)
            {
                ok = true;
                break;
            }
            cocos2d::Texture2D *ret = cobj->addImage(arg0);
            jsval jsret = JSVAL_NULL;
            if (ret)
            {
                jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
            }
            else
            {
                jsret = JSVAL_NULL;
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);

    JS_ReportError(cx, "js_cocos2dx_TextureCache_addImage : wrong number of arguments");
    return false;
}
bool js_cocos2dx_TextureCache_unbindImageAsync(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_unbindImageAsync : Invalid Native Object");
    if (argc == 1)
    {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_unbindImageAsync : Error processing arguments");
        cobj->unbindImageAsync(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_unbindImageAsync : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_getTextureForKey(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_getTextureForKey : Invalid Native Object");
    if (argc == 1)
    {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_getTextureForKey : Error processing arguments");
        cocos2d::Texture2D *ret = cobj->getTextureForKey(arg0);
        JS::RootedValue jsret(cx);
        if (ret)
        {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Texture2D>(cx, (cocos2d::Texture2D *)ret));
        }
        else
        {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_getTextureForKey : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_getTextureFilePath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_getTextureFilePath : Invalid Native Object");
    if (argc == 1)
    {
        cocos2d::Texture2D *arg0 = nullptr;
        do
        {
            if (args.get(0).isNull())
            {
                arg0 = nullptr;
                break;
            }
            if (!args.get(0).isObject())
            {
                ok = false;
                break;
            }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_getTextureFilePath : Error processing arguments");
        std::string ret = cobj->getTextureFilePath(arg0);
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_getTextureFilePath : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_renameTextureWithKey(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_renameTextureWithKey : Invalid Native Object");
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_renameTextureWithKey : Error processing arguments");
        cobj->renameTextureWithKey(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_renameTextureWithKey : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_TextureCache_removeUnusedTextures(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_removeUnusedTextures : Invalid Native Object");
    if (argc == 0)
    {
        cobj->removeUnusedTextures();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_removeUnusedTextures : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_removeTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_removeTexture : Invalid Native Object");
    if (argc == 1)
    {
        cocos2d::Texture2D *arg0 = nullptr;
        do
        {
            if (args.get(0).isNull())
            {
                arg0 = nullptr;
                break;
            }
            if (!args.get(0).isObject())
            {
                ok = false;
                break;
            }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Texture2D *)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2(arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_removeTexture : Error processing arguments");
        cobj->removeTexture(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_removeTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_TextureCache_waitForQuit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::TextureCache *cobj = (cocos2d::TextureCache *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2(cobj, cx, false, "js_cocos2dx_TextureCache_waitForQuit : Invalid Native Object");
    if (argc == 0)
    {
        cobj->waitForQuit();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_TextureCache_waitForQuit : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_TextureCache_setETC1AlphaFileSuffix(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1)
    {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_TextureCache_setETC1AlphaFileSuffix : Error processing arguments");
        cocos2d::TextureCache::setETC1AlphaFileSuffix(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_TextureCache_setETC1AlphaFileSuffix : wrong number of arguments");
    return false;
}

bool js_cocos2dx_TextureCache_getETC1AlphaFileSuffix(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0)
    {

        std::string ret = cocos2d::TextureCache::getETC1AlphaFileSuffix();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_TextureCache_getETC1AlphaFileSuffix : wrong number of arguments");
    return false;
}

bool js_cocos2dx_TextureCache_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    cocos2d::TextureCache *cobj = new (std::nothrow) cocos2d::TextureCache();

    js_type_class_t *typeClass = js_get_type_from_native<cocos2d::TextureCache>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::TextureCache"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}

void js_register_cocos2dx_TextureCache(JSContext *cx, JS::HandleObject global)
{
    jsb_cocos2d_TextureCache_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_cocos2d_TextureCache_class->name = "TextureCache";
    jsb_cocos2d_TextureCache_class->addProperty = JS_PropertyStub;
    jsb_cocos2d_TextureCache_class->delProperty = JS_DeletePropertyStub;
    jsb_cocos2d_TextureCache_class->getProperty = JS_PropertyStub;
    jsb_cocos2d_TextureCache_class->setProperty = JS_StrictPropertyStub;
    jsb_cocos2d_TextureCache_class->enumerate = JS_EnumerateStub;
    jsb_cocos2d_TextureCache_class->resolve = JS_ResolveStub;
    jsb_cocos2d_TextureCache_class->convert = JS_ConvertStub;
    jsb_cocos2d_TextureCache_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END};

    static JSFunctionSpec funcs[] = {
        JS_FN("reloadTexture", js_cocos2dx_TextureCache_reloadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("unbindAllImageAsync", js_cocos2dx_TextureCache_unbindAllImageAsync, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeTextureForKey", js_cocos2dx_TextureCache_removeTextureForKey, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeAllTextures", js_cocos2dx_TextureCache_removeAllTextures, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addImageAsync", js_cocos2dx_TextureCache_addImageAsync, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDescription", js_cocos2dx_TextureCache_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCachedTextureInfo", js_cocos2dx_TextureCache_getCachedTextureInfo, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addImage", js_cocos2dx_TextureCache_addImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("unbindImageAsync", js_cocos2dx_TextureCache_unbindImageAsync, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTextureForKey", js_cocos2dx_TextureCache_getTextureForKey, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTextureFilePath", js_cocos2dx_TextureCache_getTextureFilePath, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("renameTextureWithKey", js_cocos2dx_TextureCache_renameTextureWithKey, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeUnusedTextures", js_cocos2dx_TextureCache_removeUnusedTextures, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeTexture", js_cocos2dx_TextureCache_removeTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("waitForQuit", js_cocos2dx_TextureCache_waitForQuit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END};

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setETC1AlphaFileSuffix", js_cocos2dx_TextureCache_setETC1AlphaFileSuffix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getETC1AlphaFileSuffix", js_cocos2dx_TextureCache_getETC1AlphaFileSuffix, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END};

    jsb_cocos2d_TextureCache_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_cocos2d_TextureCache_class,
        js_cocos2dx_TextureCache_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_cocos2d_TextureCache_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "TextureCache"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<cocos2d::TextureCache>(cx, jsb_cocos2d_TextureCache_class, proto, JS::NullPtr());
}
