#pragma once 
#include "v8.h"
// extern JSClass  *jsb_cocos2d_GLProgram_class;
// extern JSObject *jsb_cocos2d_GLProgram_prototype;

// bool js_cocos2dx_GLProgram_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_GLProgram_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_GLProgram(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_GLProgram_getFragmentShaderLog(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_bindAttribLocation(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getUniformFlags(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getUniformLocationForName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_use(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getVertexShaderLog(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getUniform(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_initWithByteArrays(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith1f(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_initWithFilenames(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith3f(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformsForBuiltins(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith3i(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith4f(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_updateUniforms(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getUniformLocation(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_link(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_reset(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getAttribLocation(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_getVertexAttrib(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith2f(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith4i(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith1i(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_setUniformLocationWith2i(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_createWithByteArrays(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_createWithFilenames(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgram_GLProgram(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_GLProgramCache_class;
// extern JSObject *jsb_cocos2d_GLProgramCache_prototype;

// bool js_cocos2dx_GLProgramCache_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_GLProgramCache_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_GLProgramCache(JSContext *cx, JS::HandleObject global);
void js_register_cocos2dx_GLProgramCache(v8::Isolate* isolate, v8::Local<v8::Object> global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_GLProgramCache_loadDefaultGLPrograms(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_reloadDefaultGLProgramsRelativeToLights(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_addGLProgram(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_reloadDefaultGLPrograms(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_getGLProgram(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_GLProgramCache_GLProgramCache(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_RenderState_class;
// extern JSObject *jsb_cocos2d_RenderState_prototype;

// bool js_cocos2dx_RenderState_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_RenderState_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_RenderState(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_RenderState_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_getTopmost(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_getTexture(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_bind(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_getName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_getStateBlock(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_setParent(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_initialize(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RenderState_finalize(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Pass_class;
// extern JSObject *jsb_cocos2d_Pass_prototype;

// bool js_cocos2dx_Pass_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Pass_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Pass(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Pass_unbind(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_bind(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_clone(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_getGLProgramState(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_getVertexAttributeBinding(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_getHash(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_setVertexAttribBinding(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Pass_createWithGLProgramState(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Technique_class;
// extern JSObject *jsb_cocos2d_Technique_prototype;

// bool js_cocos2dx_Technique_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Technique_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Technique(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Technique_getPassCount(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_clone(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_addPass(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_getPasses(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_getName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_getPassByIndex(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Technique_createWithGLProgramState(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Material_class;
// extern JSObject *jsb_cocos2d_Material_prototype;

// bool js_cocos2dx_Material_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Material_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Material(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Material_clone(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getTechniqueCount(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_setName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getTechniqueByIndex(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getTechniques(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_setTechnique(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getTechniqueByName(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_addTechnique(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_getTechnique(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_createWithFilename(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_createWithGLStateProgram(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Material_createWithProperties(JSContext *cx, uint32_t argc, jsval *vp);