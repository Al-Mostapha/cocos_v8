#include "v8.h"

// extern JSClass  *jsb_cocos2d_ParticleBatchNode_class;
// extern JSObject *jsb_cocos2d_ParticleBatchNode_prototype;

// bool js_cocos2dx_ParticleBatchNode_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleBatchNode_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleBatchNode(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_ParticleBatchNode(v8::Isolate *isolate, v8::Local<v8::Object> global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleBatchNode_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_initWithTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_disableParticle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_getTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_setTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_initWithFile(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_removeAllChildrenWithCleanup(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_getTextureAtlas(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_insertChild(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_removeChildAtIndex(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_createWithTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleBatchNode_ParticleBatchNode(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleData_class;
// extern JSObject *jsb_cocos2d_ParticleData_prototype;

// bool js_cocos2dx_ParticleData_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleData_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleData(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleData_release(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleData_getMaxCount(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleData_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleData_copyParticle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleData_ParticleData(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSystem_class;
// extern JSObject *jsb_cocos2d_ParticleSystem_prototype;

// bool js_cocos2dx_ParticleSystem_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSystem_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSystem(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSystem_getStartSizeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isFull(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getBatchNode(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getPositionType(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setPosVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndSpin(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setRotatePerSecondVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setSourcePositionCompatible(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartSpinVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getRadialAccelVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndSizeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setTangentialAccel(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getRadialAccel(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartRadius(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setRotatePerSecond(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndSize(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getGravity(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_resumeEmissions(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getTangentialAccel(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndRadius(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getSpeed(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_pauseEmissions(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getAngle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartSpin(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_addParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getPosVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_updateWithNoTime(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isBlendAdditive(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getSpeedVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setPositionType(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_stopSystem(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getSourcePosition(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setLifeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndColorVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartSize(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartSpinVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_resetSystem(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setAtlasIndex(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setTangentialAccelVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndRadiusVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndRadius(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isActive(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setRadialAccelVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartSize(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setSpeed(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartSpin(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getResourceFile(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getRotatePerSecond(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEmitterMode(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setSourcePosition(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_stop(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_updateParticleQuads(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndSpinVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setBlendAdditive(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setLife(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setAngleVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setRotationIsDir(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_start(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndSizeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setAngle(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setBatchNode(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getTangentialAccelVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEmitterMode(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndSpinVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_initWithFile(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getAngleVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getRotatePerSecondVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndSize(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getLife(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isPaused(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setSpeedVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setAutoRemoveOnFinish(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setGravity(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_postStep(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEmissionRate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndColorVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getRotationIsDir(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEmissionRate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndColor(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getLifeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartSizeVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartRadius(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getParticleCount(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartRadiusVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartColorVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setEndSpin(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setRadialAccel(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_initWithDictionary(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isAutoRemoveOnFinish(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_isSourcePositionCompatible(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setStartRadiusVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getEndRadiusVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getStartColorVar(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_getAllParticleSystems(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystem_ParticleSystem(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSystemQuad_class;
// extern JSObject *jsb_cocos2d_ParticleSystemQuad_prototype;

// bool js_cocos2dx_ParticleSystemQuad_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSystemQuad_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSystemQuad(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSystemQuad_setDisplayFrame(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystemQuad_setTextureWithRect(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystemQuad_listenRendererRecreated(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystemQuad_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystemQuad_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSystemQuad_ParticleSystemQuad(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleFire_class;
// extern JSObject *jsb_cocos2d_ParticleFire_prototype;

// bool js_cocos2dx_ParticleFire_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleFire_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleFire(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleFire_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFire_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFire_ParticleFire(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleFireworks_class;
// extern JSObject *jsb_cocos2d_ParticleFireworks_prototype;

// bool js_cocos2dx_ParticleFireworks_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleFireworks_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleFireworks(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleFireworks_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFireworks_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFireworks_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFireworks_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFireworks_ParticleFireworks(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSun_class;
// extern JSObject *jsb_cocos2d_ParticleSun_prototype;

// bool js_cocos2dx_ParticleSun_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSun_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSun(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSun_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSun_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSun_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSun_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSun_ParticleSun(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleGalaxy_class;
// extern JSObject *jsb_cocos2d_ParticleGalaxy_prototype;

// bool js_cocos2dx_ParticleGalaxy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleGalaxy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleGalaxy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleGalaxy_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleGalaxy_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleGalaxy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleGalaxy_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleGalaxy_ParticleGalaxy(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleFlower_class;
// extern JSObject *jsb_cocos2d_ParticleFlower_prototype;

// bool js_cocos2dx_ParticleFlower_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleFlower_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleFlower(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleFlower_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFlower_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFlower_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFlower_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleFlower_ParticleFlower(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleMeteor_class;
// extern JSObject *jsb_cocos2d_ParticleMeteor_prototype;

// bool js_cocos2dx_ParticleMeteor_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleMeteor_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleMeteor(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleMeteor_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleMeteor_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleMeteor_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleMeteor_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleMeteor_ParticleMeteor(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSpiral_class;
// extern JSObject *jsb_cocos2d_ParticleSpiral_prototype;

// bool js_cocos2dx_ParticleSpiral_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSpiral_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSpiral(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSpiral_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSpiral_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSpiral_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSpiral_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSpiral_ParticleSpiral(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleExplosion_class;
// extern JSObject *jsb_cocos2d_ParticleExplosion_prototype;

// bool js_cocos2dx_ParticleExplosion_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleExplosion_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleExplosion(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleExplosion_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleExplosion_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleExplosion_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleExplosion_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleExplosion_ParticleExplosion(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSmoke_class;
// extern JSObject *jsb_cocos2d_ParticleSmoke_prototype;

// bool js_cocos2dx_ParticleSmoke_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSmoke_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSmoke(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSmoke_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSmoke_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSmoke_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSmoke_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSmoke_ParticleSmoke(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleSnow_class;
// extern JSObject *jsb_cocos2d_ParticleSnow_prototype;

// bool js_cocos2dx_ParticleSnow_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleSnow_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleSnow(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleSnow_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSnow_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSnow_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSnow_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleSnow_ParticleSnow(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ParticleRain_class;
// extern JSObject *jsb_cocos2d_ParticleRain_prototype;

// bool js_cocos2dx_ParticleRain_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ParticleRain_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ParticleRain(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ParticleRain_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleRain_initWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleRain_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleRain_createWithTotalParticles(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ParticleRain_ParticleRain(JSContext *cx, uint32_t argc, jsval *vp);
