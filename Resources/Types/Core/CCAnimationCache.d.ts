/**
 * <p>
 *     cc.animationCache is a singleton object that manages the Animations.<br/>
 *     It saves in a cache the animations. You should use this class if you want to save your animations in a cache.<br/>
 * <br/>
 * example<br/>
 * cc.animationCache.addAnimation(animation,"animation1");<br/>
 * </p>
 * @class
 * @name cc.animationCache
 */
declare namespace cc {

  let animationCache: AnimationCache;
  class AnimationCache {
    _animations: Record<string, cc.Animation>;

    static getInstance(): cc.AnimationCache;

    /**
     * Adds a cc.Animation with a name.
     * @param {cc.Animation} animation
     * @param {String} name
     */
    addAnimation(animation: cc.Animation, name: string): void;

    /**
     * Deletes a cc.Animation from the cache.
     * @param {String} name
     */
    removeAnimation(name: string): void;

    /**
     * <p>
     *     Returns a cc.Animation that was previously added.<br/>
     *      If the name is not found it will return nil.<br/>
     *      You should retain the returned copy if you are going to use it.</br>
     * </p>
     * @param {String} name
     * @return {cc.Animation}
     */
    getAnimation(name: string): cc.Animation;

    // _addAnimationsWithDictionary: function (dictionary, plist) {
    //   var animations = dictionary["animations"];
    //   if (!animations) {
    //     cc.log(cc._LogInfos.animationCache__addAnimationsWithDictionary);
    //     return;
    //   }

    //   var version = 1;
    //   var properties = dictionary["properties"];
    //   if (properties) {
    //     version =
    //       properties["format"] != null
    //         ? parseInt(properties["format"])
    //         : version;
    //     var spritesheets = properties["spritesheets"];
    //     var spriteFrameCache = cc.spriteFrameCache;
    //     var path = cc.path;
    //     for (var i = 0; i < spritesheets.length; i++) {
    //       spriteFrameCache.addSpriteFrames(
    //         path.changeBasename(plist, spritesheets[i]),
    //       );
    //     }
    //   }

    //   switch (version) {
    //     case 1:
    //       this._parseVersion1(animations);
    //       break;
    //     case 2:
    //       this._parseVersion2(animations);
    //       break;
    //     default:
    //       cc.log(cc._LogInfos.animationCache__addAnimationsWithDictionary_2);
    //       break;
    //   }
    // },

    /**
     * <p>
     *    Adds an animations from a plist file.<br/>
     *    Make sure that the frames were previously loaded in the cc.SpriteFrameCache.
     * </p>
     * @param {String} plist
     */
    addAnimations(plist: string): void;

    // _parseVersion1: function (animations) {
    //   var frameCache = cc.spriteFrameCache;

    //   for (var key in animations) {
    //     var animationDict = animations[key];
    //     var frameNames = animationDict["frames"];
    //     var delay = parseFloat(animationDict["delay"]) || 0;
    //     var animation = null;
    //     if (!frameNames) {
    //       cc.log(cc._LogInfos.animationCache__parseVersion1, key);
    //       continue;
    //     }

    //     var frames = [];
    //     for (var i = 0; i < frameNames.length; i++) {
    //       var spriteFrame = frameCache.getSpriteFrame(frameNames[i]);
    //       if (!spriteFrame) {
    //         cc.log(
    //           cc._LogInfos.animationCache__parseVersion1_2,
    //           key,
    //           frameNames[i],
    //         );
    //         continue;
    //       }
    //       var animFrame = new cc.AnimationFrame();
    //       animFrame.initWithSpriteFrame(spriteFrame, 1, null);
    //       frames.push(animFrame);
    //     }

    //     if (frames.length === 0) {
    //       cc.log(cc._LogInfos.animationCache__parseVersion1_3, key);
    //       continue;
    //     } else if (frames.length !== frameNames.length) {
    //       cc.log(cc._LogInfos.animationCache__parseVersion1_4, key);
    //     }
    //     animation = new cc.Animation(frames, delay, 1);
    //     cc.animationCache.addAnimation(animation, key);
    //   }
    // },

    // _parseVersion2: function (animations) {
    //   var frameCache = cc.spriteFrameCache;

    //   for (var key in animations) {
    //     var animationDict = animations[key];

    //     var isLoop = animationDict["loop"];
    //     var loopsTemp = parseInt(animationDict["loops"]);
    //     var loops = isLoop
    //       ? cc.REPEAT_FOREVER
    //       : isNaN(loopsTemp)
    //         ? 1
    //         : loopsTemp;
    //     var restoreOriginalFrame =
    //       animationDict["restoreOriginalFrame"] &&
    //       animationDict["restoreOriginalFrame"] == true
    //         ? true
    //         : false;
    //     var frameArray = animationDict["frames"];

    //     if (!frameArray) {
    //       cc.log(cc._LogInfos.animationCache__parseVersion2, key);
    //       continue;
    //     }

    //     //Array of AnimationFrames
    //     var arr = [];
    //     for (var i = 0; i < frameArray.length; i++) {
    //       var entry = frameArray[i];
    //       var spriteFrameName = entry["spriteframe"];
    //       var spriteFrame = frameCache.getSpriteFrame(spriteFrameName);
    //       if (!spriteFrame) {
    //         cc.log(
    //           cc._LogInfos.animationCache__parseVersion2_2,
    //           key,
    //           spriteFrameName,
    //         );
    //         continue;
    //       }

    //       var delayUnits = parseFloat(entry["delayUnits"]) || 0;
    //       var userInfo = entry["notification"];
    //       var animFrame = new cc.AnimationFrame();
    //       animFrame.initWithSpriteFrame(spriteFrame, delayUnits, userInfo);
    //       arr.push(animFrame);
    //     }

    //     var delayPerUnit = parseFloat(animationDict["delayPerUnit"]) || 0;
    //     var animation = new cc.Animation();
    //     animation.initWithAnimationFrames(arr, delayPerUnit, loops);
    //     animation.setRestoreOriginalFrame(restoreOriginalFrame);
    //     cc.animationCache.addAnimation(animation, key);
    //   }
    // },

    // _clear: function () {
    //   this._animations = {};
    // },
  }
}
