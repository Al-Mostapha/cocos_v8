#include "v8.h"

// extern JSClass  *jsb_cocos2d_ActionCamera_class;
// extern JSObject *jsb_cocos2d_ActionCamera_prototype;

// bool js_cocos2dx_ActionCamera_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ActionCamera_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ActionCamera(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ActionCamera_setEye(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_getEye(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_setUp(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_getCenter(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_setCenter(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_getUp(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionCamera_ActionCamera(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_OrbitCamera_class;
// extern JSObject *jsb_cocos2d_OrbitCamera_prototype;

// bool js_cocos2dx_OrbitCamera_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_OrbitCamera_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_OrbitCamera(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_OrbitCamera_sphericalRadius(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_OrbitCamera_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_OrbitCamera_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_OrbitCamera_OrbitCamera(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CardinalSplineTo_class;
// extern JSObject *jsb_cocos2d_CardinalSplineTo_prototype;

// bool js_cocos2dx_CardinalSplineTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CardinalSplineTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CardinalSplineTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CardinalSplineTo_getPoints(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CardinalSplineTo_updatePosition(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CardinalSplineTo_CardinalSplineTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CardinalSplineBy_class;
// extern JSObject *jsb_cocos2d_CardinalSplineBy_prototype;

// bool js_cocos2dx_CardinalSplineBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CardinalSplineBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CardinalSplineBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CardinalSplineBy_CardinalSplineBy(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CatmullRomTo_class;
// extern JSObject *jsb_cocos2d_CatmullRomTo_prototype;

// bool js_cocos2dx_CatmullRomTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CatmullRomTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CatmullRomTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);

// extern JSClass  *jsb_cocos2d_CatmullRomBy_class;
// extern JSObject *jsb_cocos2d_CatmullRomBy_prototype;

// bool js_cocos2dx_CatmullRomBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CatmullRomBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CatmullRomBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);

// extern JSClass  *jsb_cocos2d_Camera_class;
// extern JSObject *jsb_cocos2d_Camera_prototype;

// bool js_cocos2dx_Camera_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Camera_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Camera(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Camera_restore(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getDepth(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getViewProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_applyViewport(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setBackgroundBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_lookAt(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_apply(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getBackgroundBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getProjectionMatrix(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_isBrushValid(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getDepthInView(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_restoreViewport(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_clearBackground(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setAdditionalProjection(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setViewport(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_initDefault(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getCameraFlag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getType(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_initOrthographic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getRenderOrder(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setDepth(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setScene(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_projectGL(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_restoreFrameBufferObject(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getViewMatrix(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getNearPlane(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_project(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setCameraFlag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getFarPlane(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_applyFrameBufferObject(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setFrameBufferObject(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_isViewProjectionUpdated(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_initPerspective(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_createOrthographic(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getVisitingCamera(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_createPerspective(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getDefaultViewport(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_setDefaultViewport(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_getDefaultCamera(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Camera_Camera(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CameraBackgroundBrush_class;
// extern JSObject *jsb_cocos2d_CameraBackgroundBrush_prototype;

// bool js_cocos2dx_CameraBackgroundBrush_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CameraBackgroundBrush_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CameraBackgroundBrush(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CameraBackgroundBrush_getBrushType(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_drawBackground(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_isValid(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_createSkyboxBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_createColorBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_createNoneBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_createDepthBrush(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundBrush_CameraBackgroundBrush(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CameraBackgroundDepthBrush_class;
// extern JSObject *jsb_cocos2d_CameraBackgroundDepthBrush_prototype;

// bool js_cocos2dx_CameraBackgroundDepthBrush_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CameraBackgroundDepthBrush_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CameraBackgroundDepthBrush(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CameraBackgroundDepthBrush_setDepth(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundDepthBrush_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundDepthBrush_CameraBackgroundDepthBrush(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CameraBackgroundColorBrush_class;
// extern JSObject *jsb_cocos2d_CameraBackgroundColorBrush_prototype;

// bool js_cocos2dx_CameraBackgroundColorBrush_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CameraBackgroundColorBrush_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CameraBackgroundColorBrush(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CameraBackgroundColorBrush_setColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundColorBrush_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundColorBrush_CameraBackgroundColorBrush(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_CameraBackgroundSkyBoxBrush_class;
// extern JSObject *jsb_cocos2d_CameraBackgroundSkyBoxBrush_prototype;

// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_CameraBackgroundSkyBoxBrush_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_CameraBackgroundSkyBoxBrush(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_setTextureValid(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_setActived(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_isActived(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_CameraBackgroundSkyBoxBrush_CameraBackgroundSkyBoxBrush(JSContext *cx, uint32_t argc, jsval *vp);
