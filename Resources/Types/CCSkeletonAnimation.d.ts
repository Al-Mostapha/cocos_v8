// /**
//  * The main namespace of Spine, all classes, functions, properties and constants of Spine are defined in this namespace
//  * @namespace
//  * @name sp
//  */
declare module sp {
  /**
   * <p>
   *     The skeleton of Spine.                                                                          <br/>
   *     Skeleton has a reference to a SkeletonData and stores the state for skeleton instance,
   *     which consists of the current pose's bone SRT, slot colors, and which slot attachments are visible.           <br/>
   *     Multiple skeletons can use the same SkeletonData (which includes all animations, skins, and attachments).     <br/>
   * </p>
   * @class
   * @extends cc.Node
   */
  // sp.Skeleton = cc.Node.extend(/** @lends sp.Skeleton# */{
  class Skeleton extends cc.Node {
    /**
     * The constructor of sp.Skeleton. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     */
    constructor(skeletonDataFile: string, atlasFile: string, scale?: number);

    /**
     * Sets whether open debug slots.
     * @param {boolean} enable true to open, false to close.
     */
    setDebugSolots(enable: boolean): void;

    /**
     * Sets whether open debug bones.
     * @param {boolean} enable
     */
    setDebugBones(enable: boolean): void;

    /**
     * Sets whether open debug slots.
     * @param {boolean} enabled true to open, false to close.
     */
    setDebugSlotsEnabled(enabled: boolean): void;

    //     /**
    //      * Gets whether open debug slots.
    //      * @returns {boolean} true to open, false to close.
    //      */
    //     getDebugSlotsEnabled: function() {
    //         return this._debugSlots;
    //     },

    //     /**
    //      * Sets whether open debug bones.
    //      * @param {boolean} enabled
    //      */
    //     setDebugBonesEnabled: function(enabled) {
    //         this._debugBones = enabled;
    //     },

    //     /**
    //      * Gets whether open debug bones.
    //      * @returns {boolean} true to open, false to close.
    //      */
    //     getDebugBonesEnabled: function() {
    //         return this._debugBones;
    //     },

    //     /**
    //      * Sets the time scale of sp.Skeleton.
    //      * @param {Number} scale
    //      */
    //     setTimeScale:function(scale){
    //         this._timeScale = scale;
    //     },

    //     getTimeScale: function(){
    //         return this._timeScale;
    //     },

    /**
     * Initializes sp.Skeleton with Data.
     * @param {sp.spine.SkeletonData|String} skeletonDataFile
     * @param {String|spine.Atlas|spine.SkeletonData} atlasFile atlas filename or atlas data or owns SkeletonData
     * @param {Number} [scale] scale can be specified on the JSON or binary loader which will scale the bone positions, image sizes, and animation translations.
     */
    initWithArgs(
      skeletonDataFile: string,
      atlasFile: string,
      scale?: number
    ): void;

    //     /**
    //      * Computes the world SRT from the local SRT for each bone.
    //      */
    //     updateWorldTransform: function () {
    //         this._skeleton.updateWorldTransform();
    //     },

    //     /**
    //      * Sets the bones and slots to the setup pose.
    //      */
    //     setToSetupPose: function () {
    //         this._skeleton.setToSetupPose();
    //     },

    //     /**
    //      * Sets the bones to the setup pose, using the values from the `BoneData` list in the `SkeletonData`.
    //      */
    //     setBonesToSetupPose: function () {
    //         this._skeleton.setBonesToSetupPose();
    //     },

    //     /**
    //      * Sets the slots to the setup pose, using the values from the `SlotData` list in the `SkeletonData`.
    //      */
    //     setSlotsToSetupPose: function () {
    //         this._skeleton.setSlotsToSetupPose();
    //     },

    //     /**
    //      * Finds a bone by name. This does a string comparison for every bone.
    //      * @param {String} boneName
    //      * @returns {sp.spine.Bone}
    //      */
    //     findBone: function (boneName) {
    //         return this._skeleton.findBone(boneName);
    //     },

    //     /**
    //      * Finds a slot by name. This does a string comparison for every slot.
    //      * @param {String} slotName
    //      * @returns {sp.spine.Slot}
    //      */
    //     findSlot: function (slotName) {
    //         return this._skeleton.findSlot(slotName);
    //     },

    //     /**
    //      * Finds a skin by name and makes it the active skin. This does a string comparison for every skin. Note that setting the skin does not change which attachments are visible.
    //      * @param {string} skinName
    //      * @returns {sp.spine.Skin}
    //      */
    //     setSkin: function (skinName) {
    //         return this._skeleton.setSkinByName(skinName);
    //     },

    //     /**
    //      * Returns the attachment for the slot and attachment name. The skeleton looks first in its skin, then in the skeleton data’s default skin.
    //      * @param {String} slotName
    //      * @param {String} attachmentName
    //      * @returns {sp.spine.Attachment}
    //      */
    //     getAttachment: function (slotName, attachmentName) {
    //         return this._skeleton.getAttachmentByName(slotName, attachmentName);
    //     },

    //     /**
    //      * Sets the attachment for the slot and attachment name. The skeleton looks first in its skin, then in the skeleton data’s default skin.
    //      * @param {String} slotName
    //      * @param {String} attachmentName
    //      */
    //     setAttachment: function (slotName, attachmentName) {
    //         this._skeleton.setAttachment(slotName, attachmentName);
    //     },

    //     /**
    //      * Sets the premultiplied alpha value to sp.Skeleton.
    //      * @param {Number} alpha
    //      */
    //     setPremultipliedAlpha: function (premultiplied) {
    //         this._premultipliedAlpha = premultiplied;
    //     },

    //     /**
    //      * Returns whether to enable premultiplied alpha.
    //      * @returns {boolean}
    //      */
    //     isPremultipliedAlpha: function () {
    //         return this._premultipliedAlpha;
    //     },

    //     /**
    //      * Sets skeleton data to sp.Skeleton.
    //      * @param {sp.spine.SkeletonData} skeletonData
    //      * @param {sp.spine.SkeletonData} ownsSkeletonData
    //      */
    //     setSkeletonData: function (skeletonData, ownsSkeletonData) {
    //         if(skeletonData.width != null && skeletonData.height != null)
    //             this.setContentSize(skeletonData.width / cc.director.getContentScaleFactor(), skeletonData.height / cc.director.getContentScaleFactor());

    //         this._skeleton = new spine.Skeleton(skeletonData);
    //         this._skeleton.updateWorldTransform();
    //         this._rootBone = this._skeleton.getRootBone();
    //         this._ownsSkeletonData = ownsSkeletonData;

    //         this._renderCmd._createChildFormSkeletonData();
    //     },

    //     /**
    //      * Return the renderer of attachment.
    //      * @param {sp.spine.RegionAttachment|sp.spine.BoundingBoxAttachment} regionAttachment
    //      * @returns {sp.spine.TextureAtlasRegion}
    //      */
    //     getTextureAtlas: function (regionAttachment) {
    //         return regionAttachment.region;
    //     },

    //     /**
    //      * Returns the blendFunc of sp.Skeleton.
    //      * @returns {cc.BlendFunc}
    //      */
    //     getBlendFunc: function () {
    //         var slot = this._skeleton.drawOrder[0];
    //         if (slot) {
    //             var blend = this._renderCmd._getBlendFunc(slot.data.blendMode, this._premultipliedAlpha);
    //             return blend;
    //         }
    //         else {
    //             return {};
    //         }
    //     },

    //     /**
    //      * Sets the blendFunc of sp.Skeleton, it won't have any effect for skeleton, skeleton is using slot's data to determine the blend function.
    //      * @param {cc.BlendFunc|Number} src
    //      * @param {Number} [dst]
    //      */
    //     setBlendFunc: function (src, dst) {
    //         return;
    //     },

    //     /**
    //      * Update will be called automatically every frame if "scheduleUpdate" is called when the node is "live".
    //      * @param {Number} dt Delta time since last update
    //      */
    //     update: function (dt) {
    //         this._skeleton.update(dt);
    //     }
    // });

    // cc.defineGetterSetter(sp.Skeleton.prototype, "opacityModifyRGB", sp.Skeleton.prototype.isOpacityModifyRGB);

    // // For renderer webgl to identify skeleton's default texture and blend function
    // cc.defineGetterSetter(sp.Skeleton.prototype, "_blendFunc", sp.Skeleton.prototype.getBlendFunc);
    // cc.defineGetterSetter(sp.Skeleton.prototype, '_texture', function () {
    //     return this._renderCmd._currTexture;
    // });

    // /**
    //  * Creates a skeleton object.
    //  * @deprecated since v3.0, please use new sp.Skeleton(skeletonDataFile, atlasFile, scale) instead.
    //  * @param {spine.SkeletonData|String} skeletonDataFile
    //  * @param {String|spine.Atlas|spine.SkeletonData} atlasFile atlas filename or atlas data or owns SkeletonData
    //  * @param {Number} [scale] scale can be specified on the JSON or binary loader which will scale the bone positions, image sizes, and animation translations.
    //  * @returns {sp.Skeleton}
    //  */
    // sp.Skeleton.create = function (skeletonDataFile, atlasFile/* or atlas*/, scale) {
    //     return new sp.Skeleton(skeletonDataFile, atlasFile, scale);
    // };
  }
  class SkeletonAnimation extends Skeleton {
    // /**
    //  * The skeleton animation of spine. It updates animation's state and skeleton's world transform.
    //  * @class
    //  * @extends sp.Skeleton
    //  * @example
    //  * var spineBoy = new sp.SkeletonAnimation('res/skeletons/spineboy.json', 'res/skeletons/spineboy.atlas');
    //  * this.addChild(spineBoy, 4);
    //  */
    // sp.SkeletonAnimation = sp.Skeleton.extend(/** @lends sp.SkeletonAnimation# */{
    //   /**
    //    * Initializes a sp.SkeletonAnimation. please do not call this function by yourself, you should pass the parameters to constructor to initialize it.
    //    * @override
    //    */
    //   init: function () {
    //       sp.Skeleton.prototype.init.call(this);
    //       this._ownsAnimationStateData = true;
    //       this.setAnimationStateData(new spine.AnimationStateData(this._skeleton.data));
    //   },

    //   /**
    //    * Sets animation state data to sp.SkeletonAnimation.
    //    * @param {sp.spine.AnimationStateData} stateData
    //    */
    //   setAnimationStateData: function (stateData) {
    //       var state = new spine.AnimationState(stateData);
    //       this._listener = new sp.TrackEntryListeners();
    //       state.rendererObject = this;
    //       state.addListener(this._listener);
    //       this._state = state;
    //   },
    /**
     * @method createWithBinaryFile
     * @param {String|String} str
     * @param {String|spAtlas} str
     * @param {float|float} float
     * @return {sp.SkeletonAnimation|sp.SkeletonAnimation}
     */
    static createWithBinaryFile(
      skel: string,
      atlas: string,
      scale: number
    ): sp.SkeletonAnimation;
    //   /**
    //    * Mix applies all keyframe values, interpolated for the specified time and mixed with the current values.  <br/>
    //    * @param {String} fromAnimation
    //    * @param {String} toAnimation
    //    * @param {Number} duration
    //    */
    //   setMix: function (fromAnimation, toAnimation, duration) {
    //       this._state.data.setMixWith(fromAnimation, toAnimation, duration);
    //   },

    //   /**
    //    * Sets event listener of sp.SkeletonAnimation.
    //    * @param {Object} target
    //    * @param {Function} callback
    //    */
    //   setAnimationListener: function (target, callback) {
    //       this._listener.callbackTarget = target;
    //       this._listener.callback = callback;
    //       this._listener.skeletonNode = this;
    //   },

    /**
     * Set the current animation. Any queued animations are cleared.
     * @param {Number} trackIndex
     * @param {String} name
     * @param {Boolean} loop
     * @returns {sp.spine.TrackEntry|null}
     */
    setAnimation(trackIndex: number, name: string, loop: boolean): any;

    //   /**
    //    * Adds an animation to be played delay seconds after the current or last queued animation.
    //    * @param {Number} trackIndex
    //    * @param {String} name
    //    * @param {Boolean} loop
    //    * @param {Number} [delay=0]
    //    * @returns {sp.spine.TrackEntry|null}
    //    */
    //   addAnimation: function (trackIndex, name, loop, delay) {
    //       delay = delay == null ? 0 : delay;
    //       var animation = this._skeleton.data.findAnimation(name);
    //       if (!animation) {
    //           cc.log("Spine: Animation not found:" + name);
    //           return null;
    //       }
    //       return this._state.addAnimationWith(trackIndex, animation, loop, delay);
    //   },

    //   /**
    //    * Find animation with specified name
    //    * @param {String} name
    //    * @returns {sp.spine.Animation|null}
    //    */
    //   findAnimation: function (name) {
    //       return this._skeleton.data.findAnimation(name);
    //   },

    //   /**
    //    * Returns track entry by trackIndex.
    //    * @param trackIndex
    //    * @returns {sp.spine.TrackEntry|null}
    //    */
    //   getCurrent: function (trackIndex) {
    //       return this._state.getCurrent(trackIndex);
    //   },

    //   /**
    //    * Clears all tracks of animation state.
    //    */
    //   clearTracks: function () {
    //       this._state.clearTracks();
    //   },

    //   /**
    //    * Clears track of animation state by trackIndex.
    //    * @param {Number} trackIndex
    //    */
    //   clearTrack: function (trackIndex) {
    //       this._state.clearTrack(trackIndex);
    //   },

    //   /**
    //    * Update will be called automatically every frame if "scheduleUpdate" is called when the node is "live".
    //    * It updates animation's state and skeleton's world transform.
    //    * @param {Number} dt Delta time since last update
    //    * @override
    //    */
    //   update: function (dt) {
    //       this._super(dt);
    //       dt *= this._timeScale;
    //       this._renderCmd.setDirtyFlag(cc.Node._dirtyFlags.contentDirty);
    //       this._state.update(dt);
    //       this._state.apply(this._skeleton);
    //       this._skeleton.updateWorldTransform();
    //       this._renderCmd._updateChild();
    //   },

    //   /**
    //    * Set the start event listener.
    //    * @param {function} listener
    //    */
    //   setStartListener: function(listener){
    //       this._listener.startListener = listener;
    //   },

    //   /**
    //    * Set the interrupt listener
    //    * @param {function} listener
    //    */
    //   setInterruptListener: function(listener) {
    //       this._listener.interruptListener = listener;
    //   },

    //   /**
    //    * Set the end event listener.
    //    * @param {function} listener
    //    */
    //   setEndListener: function(listener) {
    //       this._listener.endListener = listener;
    //   },

    //   /**
    //    * Set the dispose listener
    //    * @param {function} listener
    //    */
    //   setDisposeListener: function(listener) {
    //       this._listener.disposeListener = listener;
    //   },

    //   setCompleteListener: function(listener) {
    //       this._listener.completeListener = listener;
    //   },
    setCompleteListener(listener: Function): void;

    //   setEventListener: function(listener){
    //       this._listener.eventListener = listener;
    //   },

    //   setTrackStartListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).startListener = listener;
    //   },

    //   setTrackInterruptListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).interruptListener = listener;
    //   },

    //   setTrackEndListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).endListener = listener;
    //   },

    //   setTrackDisposeListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).disposeListener = listener;
    //   },

    //   setTrackCompleteListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).completeListener = listener;
    //   },

    //   setTrackEventListener: function(entry, listener){
    //       sp.TrackEntryListeners.getListeners(entry).eventListener = listener;
    //   },

    //   getState: function(){
    //       return this._state;
    //   }
    // });

    // /**
    // * Creates a skeleton animation object.
    // * @deprecated since v3.0, please use new sp.SkeletonAnimation(skeletonDataFile, atlasFile, scale) instead.
    // * @param {spine.SkeletonData|String} skeletonDataFile
    // * @param {String|spine.Atlas|spine.SkeletonData} atlasFile atlas filename or atlas data or owns SkeletonData
    // * @param {Number} [scale] scale can be specified on the JSON or binary loader which will scale the bone positions, image sizes, and animation translations.
    // * @returns {sp.Skeleton}
    // */
    // sp.SkeletonAnimation.createWithJsonFile = sp.SkeletonAnimation.create = function (skeletonDataFile, atlasFile/* or atlas*/, scale) {
    //   return new sp.SkeletonAnimation(skeletonDataFile, atlasFile, scale);
    // };
  }
}
