#include "base/ccConfig.h"
#ifndef __cocos2dx_h__
#define __cocos2dx_h__

#include "jsapi.h"
#include "jsfriendapi.h"






extern JSClass  *jsb_cocos2d_ComponentContainer_class;
extern JSObject *jsb_cocos2d_ComponentContainer_prototype;

bool js_cocos2dx_ComponentContainer_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ComponentContainer_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ComponentContainer(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ComponentContainer_visit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ComponentContainer_remove(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ComponentContainer_removeAll(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ComponentContainer_add(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ComponentContainer_isEmpty(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ComponentContainer_get(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Component_class;
extern JSObject *jsb_cocos2d_Component_prototype;

bool js_cocos2dx_Component_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Component_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Component(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Component_setEnabled(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_setName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_isEnabled(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_getOwner(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_setOwner(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_getName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Component_Component(JSContext *cx, uint32_t argc, jsval *vp);




extern JSClass  *jsb_cocos2d___NodeRGBA_class;
extern JSObject *jsb_cocos2d___NodeRGBA_prototype;

bool js_cocos2dx___NodeRGBA_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx___NodeRGBA_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx___NodeRGBA(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx___NodeRGBA___NodeRGBA(JSContext *cx, uint32_t argc, jsval *vp);









extern JSClass  *jsb_cocos2d_Follow_class;
extern JSObject *jsb_cocos2d_Follow_prototype;

bool js_cocos2dx_Follow_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Follow_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Follow(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Follow_setBoundarySet(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_initWithTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_initWithTargetAndOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_isBoundarySet(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_createWithOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Follow_Follow(JSContext *cx, uint32_t argc, jsval *vp);









extern JSClass  *jsb_cocos2d_TargetedAction_class;
extern JSObject *jsb_cocos2d_TargetedAction_prototype;

bool js_cocos2dx_TargetedAction_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_TargetedAction_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_TargetedAction(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_TargetedAction_getForcedTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TargetedAction_initWithTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TargetedAction_setForcedTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TargetedAction_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TargetedAction_TargetedAction(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ActionFloat_class;
extern JSObject *jsb_cocos2d_ActionFloat_prototype;

bool js_cocos2dx_ActionFloat_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ActionFloat_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ActionFloat(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ActionFloat_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionFloat_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionFloat_ActionFloat(JSContext *cx, uint32_t argc, jsval *vp);






















extern JSClass  *jsb_cocos2d_Place_class;
extern JSObject *jsb_cocos2d_Place_prototype;

bool js_cocos2dx_Place_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Place_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Place(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Place_initWithPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Place_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Place_Place(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_CallFunc_class;
extern JSObject *jsb_cocos2d_CallFunc_prototype;

bool js_cocos2dx_CallFunc_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_CallFunc_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_CallFunc(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_CallFunc_execute(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_CallFunc_CallFunc(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_CallFuncN_class;
extern JSObject *jsb_cocos2d_CallFuncN_prototype;

bool js_cocos2dx_CallFuncN_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_CallFuncN_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_CallFuncN(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_CallFuncN_CallFuncN(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_GridAction_class;
extern JSObject *jsb_cocos2d_GridAction_prototype;

bool js_cocos2dx_GridAction_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_GridAction_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_GridAction(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_GridAction_getGrid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_GridAction_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Grid3DAction_class;
extern JSObject *jsb_cocos2d_Grid3DAction_prototype;

bool js_cocos2dx_Grid3DAction_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Grid3DAction_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Grid3DAction(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Grid3DAction_getGridRect(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_TiledGrid3DAction_class;
extern JSObject *jsb_cocos2d_TiledGrid3DAction_prototype;

bool js_cocos2dx_TiledGrid3DAction_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_TiledGrid3DAction_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_TiledGrid3DAction(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);

extern JSClass  *jsb_cocos2d_StopGrid_class;
extern JSObject *jsb_cocos2d_StopGrid_prototype;

bool js_cocos2dx_StopGrid_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_StopGrid_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_StopGrid(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_StopGrid_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_StopGrid_StopGrid(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ReuseGrid_class;
extern JSObject *jsb_cocos2d_ReuseGrid_prototype;

bool js_cocos2dx_ReuseGrid_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ReuseGrid_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ReuseGrid(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ReuseGrid_initWithTimes(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ReuseGrid_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ReuseGrid_ReuseGrid(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Waves3D_class;
extern JSObject *jsb_cocos2d_Waves3D_prototype;

bool js_cocos2dx_Waves3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Waves3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Waves3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Waves3D_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves3D_Waves3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FlipX3D_class;
extern JSObject *jsb_cocos2d_FlipX3D_prototype;

bool js_cocos2dx_FlipX3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FlipX3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FlipX3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FlipX3D_initWithSize(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FlipX3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FlipX3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FlipX3D_FlipX3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FlipY3D_class;
extern JSObject *jsb_cocos2d_FlipY3D_prototype;

bool js_cocos2dx_FlipY3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FlipY3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FlipY3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FlipY3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FlipY3D_FlipY3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Lens3D_class;
extern JSObject *jsb_cocos2d_Lens3D_prototype;

bool js_cocos2dx_Lens3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Lens3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Lens3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Lens3D_setConcave(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_setLensEffect(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_getLensEffect(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_setPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_getPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Lens3D_Lens3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Ripple3D_class;
extern JSObject *jsb_cocos2d_Ripple3D_prototype;

bool js_cocos2dx_Ripple3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Ripple3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Ripple3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Ripple3D_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_setPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_getPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Ripple3D_Ripple3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Shaky3D_class;
extern JSObject *jsb_cocos2d_Shaky3D_prototype;

bool js_cocos2dx_Shaky3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Shaky3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Shaky3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Shaky3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Shaky3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Shaky3D_Shaky3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Liquid_class;
extern JSObject *jsb_cocos2d_Liquid_prototype;

bool js_cocos2dx_Liquid_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Liquid_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Liquid(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Liquid_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Liquid_Liquid(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Waves_class;
extern JSObject *jsb_cocos2d_Waves_prototype;

bool js_cocos2dx_Waves_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Waves_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Waves(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Waves_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Waves_Waves(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Twirl_class;
extern JSObject *jsb_cocos2d_Twirl_prototype;

bool js_cocos2dx_Twirl_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_Twirl_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_Twirl(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_Twirl_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_setPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_getPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_Twirl_Twirl(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ActionManager_class;
extern JSObject *jsb_cocos2d_ActionManager_prototype;

bool js_cocos2dx_ActionManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ActionManager_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ActionManager(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ActionManager_getActionByTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeActionByTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeActionsByFlags(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeAllActions(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_addAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_resumeTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_getNumberOfRunningActions(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_pauseTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_getNumberOfRunningActionsInTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeAllActionsFromTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_resumeTargets(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_pauseAllRunningActions(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_removeAllActionsByTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_getNumberOfRunningActionsInTargetByTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionManager_ActionManager(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_PageTurn3D_class;
extern JSObject *jsb_cocos2d_PageTurn3D_prototype;

bool js_cocos2dx_PageTurn3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_PageTurn3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_PageTurn3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_PageTurn3D_create(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ProgressTo_class;
extern JSObject *jsb_cocos2d_ProgressTo_prototype;

bool js_cocos2dx_ProgressTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ProgressTo_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ProgressTo(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ProgressTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ProgressTo_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ProgressTo_ProgressTo(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ProgressFromTo_class;
extern JSObject *jsb_cocos2d_ProgressFromTo_prototype;

bool js_cocos2dx_ProgressFromTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ProgressFromTo_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ProgressFromTo(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ProgressFromTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ProgressFromTo_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ProgressFromTo_ProgressFromTo(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ShakyTiles3D_class;
extern JSObject *jsb_cocos2d_ShakyTiles3D_prototype;

bool js_cocos2dx_ShakyTiles3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ShakyTiles3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ShakyTiles3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ShakyTiles3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShakyTiles3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShakyTiles3D_ShakyTiles3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ShatteredTiles3D_class;
extern JSObject *jsb_cocos2d_ShatteredTiles3D_prototype;

bool js_cocos2dx_ShatteredTiles3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ShatteredTiles3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ShatteredTiles3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ShatteredTiles3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShatteredTiles3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShatteredTiles3D_ShatteredTiles3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ShuffleTiles_class;
extern JSObject *jsb_cocos2d_ShuffleTiles_prototype;

bool js_cocos2dx_ShuffleTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ShuffleTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ShuffleTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ShuffleTiles_placeTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShuffleTiles_shuffle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShuffleTiles_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShuffleTiles_getDelta(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShuffleTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ShuffleTiles_ShuffleTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FadeOutTRTiles_class;
extern JSObject *jsb_cocos2d_FadeOutTRTiles_prototype;

bool js_cocos2dx_FadeOutTRTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FadeOutTRTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FadeOutTRTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FadeOutTRTiles_turnOnTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutTRTiles_turnOffTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutTRTiles_transformTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutTRTiles_testFunc(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutTRTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutTRTiles_FadeOutTRTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FadeOutBLTiles_class;
extern JSObject *jsb_cocos2d_FadeOutBLTiles_prototype;

bool js_cocos2dx_FadeOutBLTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FadeOutBLTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FadeOutBLTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FadeOutBLTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutBLTiles_FadeOutBLTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FadeOutUpTiles_class;
extern JSObject *jsb_cocos2d_FadeOutUpTiles_prototype;

bool js_cocos2dx_FadeOutUpTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FadeOutUpTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FadeOutUpTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FadeOutUpTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutUpTiles_FadeOutUpTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_FadeOutDownTiles_class;
extern JSObject *jsb_cocos2d_FadeOutDownTiles_prototype;

bool js_cocos2dx_FadeOutDownTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_FadeOutDownTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_FadeOutDownTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_FadeOutDownTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_FadeOutDownTiles_FadeOutDownTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_TurnOffTiles_class;
extern JSObject *jsb_cocos2d_TurnOffTiles_prototype;

bool js_cocos2dx_TurnOffTiles_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_TurnOffTiles_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_TurnOffTiles(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_TurnOffTiles_turnOnTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TurnOffTiles_turnOffTile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TurnOffTiles_shuffle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TurnOffTiles_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TurnOffTiles_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_TurnOffTiles_TurnOffTiles(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_WavesTiles3D_class;
extern JSObject *jsb_cocos2d_WavesTiles3D_prototype;

bool js_cocos2dx_WavesTiles3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_WavesTiles3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_WavesTiles3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_WavesTiles3D_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_WavesTiles3D_WavesTiles3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_JumpTiles3D_class;
extern JSObject *jsb_cocos2d_JumpTiles3D_prototype;

bool js_cocos2dx_JumpTiles3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_JumpTiles3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_JumpTiles3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_JumpTiles3D_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_getAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_setAmplitude(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_JumpTiles3D_JumpTiles3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_SplitRows_class;
extern JSObject *jsb_cocos2d_SplitRows_prototype;

bool js_cocos2dx_SplitRows_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_SplitRows_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_SplitRows(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_SplitRows_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_SplitRows_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_SplitRows_SplitRows(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_SplitCols_class;
extern JSObject *jsb_cocos2d_SplitCols_prototype;

bool js_cocos2dx_SplitCols_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_SplitCols_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_SplitCols(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_SplitCols_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_SplitCols_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_SplitCols_SplitCols(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_ActionTween_class;
extern JSObject *jsb_cocos2d_ActionTween_prototype;

bool js_cocos2dx_ActionTween_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ActionTween_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ActionTween(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_ActionTween_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_ActionTween_create(JSContext *cx, uint32_t argc, jsval *vp);




extern JSClass  *jsb_cocos2d_SAXParser_class;
extern JSObject *jsb_cocos2d_SAXParser_prototype;

bool js_cocos2dx_SAXParser_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_SAXParser_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_SAXParser(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_SAXParser_init(JSContext *cx, uint32_t argc, jsval *vp);

















extern JSClass  *jsb_cocos2d_ComponentJS_class;
extern JSObject *jsb_cocos2d_ComponentJS_prototype;

bool js_cocos2dx_ComponentJS_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_ComponentJS_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_ComponentJS(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);

#endif // __cocos2dx_h__
