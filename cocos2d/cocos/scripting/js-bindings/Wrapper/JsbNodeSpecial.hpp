#pragma once

#include "v8.h"
// extern JSClass  *jsb_cocos2d_AtlasNode_class;
// extern JSObject *jsb_cocos2d_AtlasNode_prototype;

// bool js_cocos2dx_AtlasNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_AtlasNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_AtlasNode(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_AtlasNode_updateAtlasValues(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_initWithTileFile(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_getTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_setTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_getTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_getQuadsToDraw(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_initWithTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_setQuadsToDraw(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_AtlasNode_AtlasNode(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ClippingNode_class;
// extern JSObject *jsb_cocos2d_ClippingNode_prototype;

// bool js_cocos2dx_ClippingNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ClippingNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ClippingNode(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ClippingNode_hasContent(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_setInverted(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_setStencil(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_getAlphaThreshold(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_getStencil(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_setAlphaThreshold(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_isInverted(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ClippingNode_ClippingNode(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_DrawNode_class;
// extern JSObject *jsb_cocos2d_DrawNode_prototype;

// bool js_cocos2dx_DrawNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_DrawNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_DrawNode(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_DrawNode_drawLine(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawPoints(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_setIsolated(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawRect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawSolidCircle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_setLineWidth(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_onDrawGLPoint(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawPolygon(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawDot(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawCatmullRom(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawSegment(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_onDraw(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawCircle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawQuadBezier(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_onDrawGLLine(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawSolidPoly(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawTriangle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_clear(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawCardinalSpline(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawSolidRect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_getLineWidth(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawPoint(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_isIsolated(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_drawCubicBezier(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DrawNode_DrawNode(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_NodeGrid_class;
// extern JSObject *jsb_cocos2d_NodeGrid_prototype;

// bool js_cocos2dx_NodeGrid_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_NodeGrid_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_NodeGrid(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_NodeGrid_setTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_NodeGrid_getGrid(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_NodeGrid_getGridRect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_NodeGrid_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_NodeGrid_NodeGrid(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ProtectedNode_class;
// extern JSObject *jsb_cocos2d_ProtectedNode_prototype;

// bool js_cocos2dx_ProtectedNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ProtectedNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ProtectedNode(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_ProtectedNode(v8::Isolate *isolate, v8::Local<v8::Object> global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ProtectedNode_addProtectedChild(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_disableCascadeColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_removeProtectedChildByTag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_reorderProtectedChild(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_removeAllProtectedChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_disableCascadeOpacity(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_sortAllProtectedChildren(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_getProtectedChildByTag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_removeProtectedChild(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_removeAllProtectedChildren(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ProtectedNode_ProtectedNode(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParallaxNode_class;
// extern JSObject *jsb_cocos2d_ParallaxNode_prototype;

// bool js_cocos2dx_ParallaxNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParallaxNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParallaxNode(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParallaxNode_getParallaxArray(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParallaxNode_addChild(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParallaxNode_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParallaxNode_setParallaxArray(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParallaxNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParallaxNode_ParallaxNode(JSContext *cx, uint32_t argc, jsval *vp);