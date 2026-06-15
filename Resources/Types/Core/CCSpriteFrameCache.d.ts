declare namespace cc {
  /**
   * <p>
   * cc.spriteFrameCache is a singleton that handles the loading of the sprite frames. It saves in a cache the sprite frames.<br/>
   * <br/>
   * example<br/>
   * // add SpriteFrames to spriteFrameCache With File<br/>
   * cc.spriteFrameCache.addSpriteFrames(s_grossiniPlist);<br/>
   * </p>
   * @class
   * @name cc.spriteFrameCache
   */
  class SpriteFrameCache {
    static getInstance(): cc.SpriteFrameCache;
    _CCNS_REG1: RegExp;
    _CCNS_REG2: RegExp;

    _spriteFrames: {};
    _spriteFramesAliases: {};
    _frameConfigCache: {};

    // _rectFromString: function (content) {
    //   var result = this._CCNS_REG2.exec(content);
    //   if (!result) return cc.rect(0, 0, 0, 0);
    //   return cc.rect(
    //     parseFloat(result[1]),
    //     parseFloat(result[2]),
    //     parseFloat(result[3]),
    //     parseFloat(result[4]),
    //   );
    // },

    // _pointFromString: function (content) {
    //   var result = this._CCNS_REG1.exec(content);
    //   if (!result) return cc.p(0, 0);
    //   return cc.p(parseFloat(result[1]), parseFloat(result[2]));
    // },

    // _sizeFromString: function (content) {
    //   var result = this._CCNS_REG1.exec(content);
    //   if (!result) return cc.size(0, 0);
    //   return cc.size(parseFloat(result[1]), parseFloat(result[2]));
    // },

    // _getFrameConfig: function (url) {
    //   var dict = cc.loader.getRes(url);

    //   cc.assert(dict, cc._LogInfos.spriteFrameCache__getFrameConfig_2, url);

    //   cc.loader.release(url); //release it in loader
    //   if (dict._inited) {
    //     this._frameConfigCache[url] = dict;
    //     return dict;
    //   }
    //   this._frameConfigCache[url] = this._parseFrameConfig(dict);
    //   return this._frameConfigCache[url];
    // },

    // _getFrameConfigByJsonObject: function (url, jsonObject) {
    //   cc.assert(
    //     jsonObject,
    //     cc._LogInfos.spriteFrameCache__getFrameConfig_2,
    //     url,
    //   );
    //   this._frameConfigCache[url] = this._parseFrameConfig(jsonObject);
    //   return this._frameConfigCache[url];
    // },

    // _parseFrameConfig: function (dict) {
    //   var tempFrames = dict["frames"],
    //     tempMeta = dict["metadata"] || dict["meta"];
    //   var frames = {},
    //     meta = {};
    //   var format = 0;
    //   if (tempMeta) {
    //     //init meta
    //     var tmpFormat = tempMeta["format"];
    //     format = tmpFormat.length <= 1 ? parseInt(tmpFormat) : tmpFormat;
    //     meta.image =
    //       tempMeta["textureFileName"] ||
    //       tempMeta["textureFileName"] ||
    //       tempMeta["image"];
    //   }
    //   for (var key in tempFrames) {
    //     var frameDict = tempFrames[key];
    //     if (!frameDict) continue;
    //     var tempFrame = {};

    //     if (format == 0) {
    //       tempFrame.rect = cc.rect(
    //         frameDict["x"],
    //         frameDict["y"],
    //         frameDict["width"],
    //         frameDict["height"],
    //       );
    //       tempFrame.rotated = false;
    //       tempFrame.offset = cc.p(frameDict["offsetX"], frameDict["offsetY"]);
    //       var ow = frameDict["originalWidth"];
    //       var oh = frameDict["originalHeight"];
    //       // check ow/oh
    //       if (!ow || !oh) {
    //         cc.log(cc._LogInfos.spriteFrameCache__getFrameConfig);
    //       }
    //       // Math.abs ow/oh
    //       ow = Math.abs(ow);
    //       oh = Math.abs(oh);
    //       tempFrame.size = cc.size(ow, oh);
    //     } else if (format == 1 || format == 2) {
    //       tempFrame.rect = this._rectFromString(frameDict["frame"]);
    //       tempFrame.rotated = frameDict["rotated"] || false;
    //       tempFrame.offset = this._pointFromString(frameDict["offset"]);
    //       tempFrame.size = this._sizeFromString(frameDict["sourceSize"]);
    //     } else if (format == 3) {
    //       // get values
    //       var spriteSize = this._sizeFromString(frameDict["spriteSize"]);
    //       var textureRect = this._rectFromString(frameDict["textureRect"]);
    //       if (spriteSize) {
    //         textureRect = cc.rect(
    //           textureRect.x,
    //           textureRect.y,
    //           spriteSize.width,
    //           spriteSize.height,
    //         );
    //       }
    //       tempFrame.rect = textureRect;
    //       tempFrame.rotated = frameDict["textureRotated"] || false; // == "true";
    //       tempFrame.offset = this._pointFromString(frameDict["spriteOffset"]);
    //       tempFrame.size = this._sizeFromString(frameDict["spriteSourceSize"]);
    //       tempFrame.aliases = frameDict["aliases"];
    //     } else {
    //       var tmpFrame = frameDict["frame"],
    //         tmpSourceSize = frameDict["sourceSize"];
    //       key = frameDict["filename"] || key;
    //       tempFrame.rect = cc.rect(
    //         tmpFrame["x"],
    //         tmpFrame["y"],
    //         tmpFrame["w"],
    //         tmpFrame["h"],
    //       );
    //       tempFrame.rotated = frameDict["rotated"] || false;
    //       tempFrame.offset = cc.p(0, 0);
    //       tempFrame.size = cc.size(tmpSourceSize["w"], tmpSourceSize["h"]);
    //     }
    //     frames[key] = tempFrame;
    //   }
    //   return { _inited: true, frames: frames, meta: meta };
    // },

    // // Adds multiple Sprite Frames from a json object. it uses for local web view app.
    // _addSpriteFramesByObject: function (url, jsonObject, texture) {
    //   cc.assert(url, cc._LogInfos.spriteFrameCache_addSpriteFrames_2);
    //   if (!jsonObject || !jsonObject["frames"]) return;

    //   var frameConfig =
    //     this._frameConfigCache[url] ||
    //     this._getFrameConfigByJsonObject(url, jsonObject);
    //   //this._checkConflict(frameConfig);                             //TODO
    //   this._createSpriteFrames(url, frameConfig, texture);
    // },

    // _createSpriteFrames: function (url, frameConfig, texture) {
    //   var frames = frameConfig.frames,
    //     meta = frameConfig.meta;
    //   if (!texture) {
    //     var texturePath = cc.path.changeBasename(url, meta.image || ".png");
    //     texture = cc.textureCache.addImage(texturePath);
    //   } else if (texture instanceof cc.Texture2D) {
    //     //do nothing
    //   } else if (cc.isString(texture)) {
    //     //string
    //     texture = cc.textureCache.addImage(texture);
    //   } else {
    //     cc.assert(0, cc._LogInfos.spriteFrameCache_addSpriteFrames_3);
    //   }

    //   //create sprite frames
    //   var spAliases = this._spriteFramesAliases,
    //     spriteFrames = this._spriteFrames;
    //   for (var key in frames) {
    //     var frame = frames[key];
    //     var spriteFrame = spriteFrames[key];
    //     if (!spriteFrame) {
    //       spriteFrame = new cc.SpriteFrame(
    //         texture,
    //         frame.rect,
    //         frame.rotated,
    //         frame.offset,
    //         frame.size,
    //       );
    //       var aliases = frame.aliases;
    //       if (aliases) {
    //         //set aliases
    //         for (var i = 0, li = aliases.length; i < li; i++) {
    //           var alias = aliases[i];
    //           if (spAliases[alias])
    //             cc.log(cc._LogInfos.spriteFrameCache_addSpriteFrames, alias);
    //           spAliases[alias] = key;
    //         }
    //       }

    //       if (
    //         cc._renderType === cc.game.RENDER_TYPE_CANVAS &&
    //         spriteFrame.isRotated()
    //       ) {
    //         //clip to canvas
    //         var locTexture = spriteFrame.getTexture();
    //         if (locTexture.isLoaded()) {
    //           var tempElement = spriteFrame.getTexture().getHtmlElementObj();
    //           tempElement = cc.Sprite.CanvasRenderCmd._cutRotateImageToCanvas(
    //             tempElement,
    //             spriteFrame.getRectInPixels(),
    //           );
    //           var tempTexture = new cc.Texture2D();
    //           tempTexture.initWithElement(tempElement);
    //           tempTexture.handleLoadedTexture();
    //           spriteFrame.setTexture(tempTexture);

    //           var rect = spriteFrame._rect;
    //           spriteFrame.setRect(cc.rect(0, 0, rect.width, rect.height));
    //         }
    //       }
    //       spriteFrames[key] = spriteFrame;
    //     }
    //   }
    // },

    /**
     * <p>
     *   Adds multiple Sprite Frames from a plist or json file.<br/>
     *   A texture will be loaded automatically. The texture name will composed by replacing the .plist or .json suffix with .png<br/>
     *   If you want to use another texture, you should use the addSpriteFrames:texture method.<br/>
     * </p>
     * @param {String} url file path
     * @param {HTMLImageElement|cc.Texture2D|string} texture
     * @example
     * // add SpriteFrames to SpriteFrameCache With File
     * cc.spriteFrameCache.addSpriteFrames(s_grossiniPlist);
     * cc.spriteFrameCache.addSpriteFrames(s_grossiniJson);
     */
    addSpriteFrames(
      url: string,
      texture: HTMLImageElement | cc.Texture2D | string,
    ): void;
    // Function to check if frames to add exists already, if so there may be name conflit that must be solved
    // _checkConflict: function (dictionary) {
    //   var framesDict = dictionary["frames"];

    //   for (var key in framesDict) {
    //     if (this._spriteFrames[key]) {
    //       cc.log(cc._LogInfos.spriteFrameCache__checkConflict, key);
    //     }
    //   }
    // },

    /**
     * <p>
     *  Adds an sprite frame with a given name.<br/>
     *  If the name already exists, then the contents of the old name will be replaced with the new one.
     * </p>
     * @param {cc.SpriteFrame} frame
     * @param {String} frameName
     */
    addSpriteFrame(frame: cc.SpriteFrame, frameName: string): void;

    /**
     * <p>
     *   Purges the dictionary of loaded sprite frames.<br/>
     *   Call this method if you receive the "Memory Warning".<br/>
     *   In the short term: it will free some resources preventing your app from being killed.<br/>
     *   In the medium term: it will allocate more resources.<br/>
     *   In the long term: it will be the same.<br/>
     * </p>
     */
    removeSpriteFrames(): void;

    /**
     * Deletes an sprite frame from the sprite frame cache.
     * @param {String} name
     */
    removeSpriteFrameByName(name: string): void;

    /**
     * <p>
     *     Removes multiple Sprite Frames from a plist file.<br/>
     *     Sprite Frames stored in this file will be removed.<br/>
     *     It is convinient to call this method when a specific texture needs to be removed.<br/>
     * </p>
     * @param {String} url Plist filename
     */
    removeSpriteFramesFromFile(url: string): void;

    /**
     * <p>
     *    Removes all Sprite Frames associated with the specified textures.<br/>
     *    It is convenient to call this method when a specific texture needs to be removed.
     * </p>
     * @param {HTMLImageElement|HTMLCanvasElement|cc.Texture2D} texture
     */
    removeSpriteFramesFromTexture(
      texture: HTMLImageElement | HTMLCanvasElement | cc.Texture2D,
    ): void;

    /**
     * <p>
     *   Returns an Sprite Frame that was previously added.<br/>
     *   If the name is not found it will return nil.<br/>
     *   You should retain the returned copy if you are going to use it.<br/>
     * </p>
     * @param {String} name name of SpriteFrame
     * @return {cc.SpriteFrame}
     * @example
     * //get a SpriteFrame by name
     * var frame = cc.spriteFrameCache.getSpriteFrame("grossini_dance_01.png");
     */
    getSpriteFrame(name: string): cc.SpriteFrame;

    // _clear: function () {
    //   this._spriteFrames = {};
    //   this._spriteFramesAliases = {};
    //   this._frameConfigCache = {};
    // },
  }
}
