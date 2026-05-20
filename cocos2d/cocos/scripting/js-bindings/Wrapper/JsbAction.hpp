
// extern JSClass  *jsb_cocos2d_Action_class;
// extern JSObject *jsb_cocos2d_Action_prototype;

// bool js_cocos2dx_Action_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Action_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Action(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Action_startWithTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_setOriginalTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_clone(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_getOriginalTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_stop(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_update(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_getTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_getFlags(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_step(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_setTag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_setFlags(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_getTag(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_setTarget(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_isDone(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Action_reverse(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_FiniteTimeAction_class;
// extern JSObject *jsb_cocos2d_FiniteTimeAction_prototype;

// bool js_cocos2dx_FiniteTimeAction_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_FiniteTimeAction_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_FiniteTimeAction(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_FiniteTimeAction_setDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FiniteTimeAction_getDuration(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Speed_class;
// extern JSObject *jsb_cocos2d_Speed_prototype;

// bool js_cocos2dx_Speed_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Speed_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Speed(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Speed_setInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_getSpeed(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_setSpeed(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_initWithAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_getInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Speed_Speed(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_ActionInterval_class;
// extern JSObject *jsb_cocos2d_ActionInterval_prototype;

// bool js_cocos2dx_ActionInterval_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ActionInterval_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ActionInterval(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ActionInterval_getAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionInterval_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionInterval_setAmplitudeRate(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ActionInterval_getElapsed(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Sequence_class;
// extern JSObject *jsb_cocos2d_Sequence_prototype;

// bool js_cocos2dx_Sequence_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Sequence_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Sequence(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Sequence_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Sequence_initWithTwoActions(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Sequence_Sequence(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Repeat_class;
// extern JSObject *jsb_cocos2d_Repeat_prototype;

// bool js_cocos2dx_Repeat_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Repeat_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Repeat(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Repeat_setInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Repeat_initWithAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Repeat_getInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Repeat_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Repeat_Repeat(JSContext *cx, uint32_t argc, jsval *vp);


// extern JSClass  *jsb_cocos2d_RepeatForever_class;
// extern JSObject *jsb_cocos2d_RepeatForever_prototype;

// bool js_cocos2dx_RepeatForever_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_RepeatForever_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_RepeatForever(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_RepeatForever_setInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RepeatForever_initWithAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RepeatForever_getInnerAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RepeatForever_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RepeatForever_RepeatForever(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_Spawn_class;
// extern JSObject *jsb_cocos2d_Spawn_prototype;

// bool js_cocos2dx_Spawn_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Spawn_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Spawn(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Spawn_init(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Spawn_initWithTwoActions(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Spawn_Spawn(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_RotateTo_class;
// extern JSObject *jsb_cocos2d_RotateTo_prototype;

// bool js_cocos2dx_RotateTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_RotateTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_RotateTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_RotateTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RotateTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RotateTo_RotateTo(JSContext *cx, uint32_t argc, jsval *vp);


// extern JSClass  *jsb_cocos2d_RotateBy_class;
// extern JSObject *jsb_cocos2d_RotateBy_prototype;

// bool js_cocos2dx_RotateBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_RotateBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_RotateBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_RotateBy_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RotateBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_RotateBy_RotateBy(JSContext *cx, uint32_t argc, jsval *vp);




// extern JSClass  *jsb_cocos2d_MoveBy_class;
// extern JSObject *jsb_cocos2d_MoveBy_prototype;

// bool js_cocos2dx_MoveBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_MoveBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_MoveBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_MoveBy_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_MoveBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_MoveBy_MoveBy(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_MoveTo_class;
// extern JSObject *jsb_cocos2d_MoveTo_prototype;

// bool js_cocos2dx_MoveTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_MoveTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_MoveTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_MoveTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_MoveTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_MoveTo_MoveTo(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_SkewTo_class;
// extern JSObject *jsb_cocos2d_SkewTo_prototype;

// bool js_cocos2dx_SkewTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_SkewTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_SkewTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_SkewTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SkewTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SkewTo_SkewTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_SkewBy_class;
// extern JSObject *jsb_cocos2d_SkewBy_prototype;

// bool js_cocos2dx_SkewBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_SkewBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_SkewBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_SkewBy_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SkewBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_SkewBy_SkewBy(JSContext *cx, uint32_t argc, jsval *vp);


// extern JSClass  *jsb_cocos2d_JumpBy_class;
// extern JSObject *jsb_cocos2d_JumpBy_prototype;

// bool js_cocos2dx_JumpBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_JumpBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_JumpBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_JumpBy_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_JumpBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_JumpBy_JumpBy(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_JumpTo_class;
// extern JSObject *jsb_cocos2d_JumpTo_prototype;

// bool js_cocos2dx_JumpTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_JumpTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_JumpTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_JumpTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_JumpTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_JumpTo_JumpTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_BezierBy_class;
// extern JSObject *jsb_cocos2d_BezierBy_prototype;

// bool js_cocos2dx_BezierBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_BezierBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_BezierBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_BezierBy_BezierBy(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_BezierTo_class;
// extern JSObject *jsb_cocos2d_BezierTo_prototype;

// bool js_cocos2dx_BezierTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_BezierTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_BezierTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_BezierTo_BezierTo(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_ScaleTo_class;
// extern JSObject *jsb_cocos2d_ScaleTo_prototype;

// bool js_cocos2dx_ScaleTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ScaleTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ScaleTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ScaleTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ScaleTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ScaleTo_ScaleTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_ScaleBy_class;
// extern JSObject *jsb_cocos2d_ScaleBy_prototype;

// bool js_cocos2dx_ScaleBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ScaleBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ScaleBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ScaleBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ScaleBy_ScaleBy(JSContext *cx, uint32_t argc, jsval *vp);



// extern JSClass  *jsb_cocos2d_Blink_class;
// extern JSObject *jsb_cocos2d_Blink_prototype;

// bool js_cocos2dx_Blink_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_Blink_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_Blink(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_Blink_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Blink_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_Blink_Blink(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_FadeTo_class;
// extern JSObject *jsb_cocos2d_FadeTo_prototype;

// bool js_cocos2dx_FadeTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_FadeTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_FadeTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_FadeTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeTo_FadeTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_FadeIn_class;
// extern JSObject *jsb_cocos2d_FadeIn_prototype;

// bool js_cocos2dx_FadeIn_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_FadeIn_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_FadeIn(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_FadeIn_setReverseAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeIn_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeIn_FadeIn(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_FadeOut_class;
// extern JSObject *jsb_cocos2d_FadeOut_prototype;

// bool js_cocos2dx_FadeOut_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_FadeOut_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_FadeOut(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_FadeOut_setReverseAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeOut_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_FadeOut_FadeOut(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_TintTo_class;
// extern JSObject *jsb_cocos2d_TintTo_prototype;

// bool js_cocos2dx_TintTo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_TintTo_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_TintTo(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_TintTo_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_TintTo_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_TintTo_TintTo(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_TintBy_class;
// extern JSObject *jsb_cocos2d_TintBy_prototype;

// bool js_cocos2dx_TintBy_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_TintBy_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_TintBy(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_TintBy_initWithDuration(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_TintBy_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_TintBy_TintBy(JSContext *cx, uint32_t argc, jsval *vp);

// extern JSClass  *jsb_cocos2d_DelayTime_class;
// extern JSObject *jsb_cocos2d_DelayTime_prototype;

// bool js_cocos2dx_DelayTime_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_DelayTime_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_DelayTime(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_DelayTime_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_DelayTime_DelayTime(JSContext *cx, uint32_t argc, jsval *vp);


// extern JSClass  *jsb_cocos2d_ReverseTime_class;
// extern JSObject *jsb_cocos2d_ReverseTime_prototype;

// bool js_cocos2dx_ReverseTime_constructor(JSContext *cx, uint32_t argc, jsval *vp);
// void js_cocos2dx_ReverseTime_finalize(JSContext *cx, JSObject *obj);
// void js_register_cocos2dx_ReverseTime(JSContext *cx, JS::HandleObject global);
// void register_all_cocos2dx(JSContext* cx, JS::HandleObject obj);
// bool js_cocos2dx_ReverseTime_initWithAction(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ReverseTime_create(JSContext *cx, uint32_t argc, jsval *vp);
// bool js_cocos2dx_ReverseTime_ReverseTime(JSContext *cx, uint32_t argc, jsval *vp);