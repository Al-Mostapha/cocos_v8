declare module ccui {
  /**
   * The Slider control of Cocos UI.
   * @class
   * @extends ccui.Widget
   *
   * @property {Number}   percent     - The current progress of loadingbar
   */
  class Slider extends Widget {
    /**
     * allocates and initializes a UISlider.
     * Constructor of ccui.Slider. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @example
     * // example
     * var uiSlider = new ccui.Slider();
     */
    constructor(
      barTextureName?: string,
      normalBallTextureName?: string,
      resType?: number
    );
    /**
     * Loads texture for slider bar.
     * @param {String} fileName
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadBarTexture(fileName: string, texType: number): void;

    //     /**
    //      * Loads dark state texture for slider progress bar.
    //      * @param {String} fileName
    //      * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
    //      */
    //     loadProgressBarTexture: function (fileName, texType) {
    //         if (!fileName) {
    //             return;
    //         }
    //         texType = texType || ccui.Widget.LOCAL_TEXTURE;
    //         this._progressBarTextureFile = fileName;
    //         this._progressBarTexType = texType;
    //         var progressBarRenderer = this._progressBarRenderer;
    //         var self = this;
    //         if (!progressBarRenderer._textureLoaded) {
    //             progressBarRenderer.addEventListener("load", function () {
    //                 self.loadProgressBarTexture(self._progressBarTextureFile, self._progressBarTexType);
    //             });
    //         }
    //         switch (this._progressBarTexType) {
    //             case ccui.Widget.LOCAL_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 progressBarRenderer.initWithFile(fileName);
    //                 break;
    //             case ccui.Widget.PLIST_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 progressBarRenderer.initWithSpriteFrameName(fileName);
    //                 break;
    //             default:
    //                 break;
    //         }
    //         this._updateChildrenDisplayedRGBA();
    //         this._progressBarRenderer.setAnchorPoint(cc.p(0, 0.5));
    //         var tz = this._progressBarRenderer.getContentSize();
    //         this._progressBarTextureSize = {width: tz.width, height: tz.height};
    //         this._progressBarRendererDirty = true;
    //         this._findLayout();
    //     },
    /**
     * Sets if slider is using scale9 renderer.
     * @param {Boolean} able
     */
    setScale9Enabled(able: boolean): void;
    //     /**
    //      * Returns slider is using scale9 renderer or not.
    //      * @returns {Boolean}
    //      */
    //     isScale9Enabled: function () {
    //         return this._scale9Enabled;
    //     },
    //     /**
    //      * override "ignoreContentAdaptWithSize" method of widget.
    //      * @param {Boolean} ignore
    //      */
    //     ignoreContentAdaptWithSize: function (ignore) {
    //         if (!this._scale9Enabled || (this._scale9Enabled && !ignore)) {
    //             ccui.Widget.prototype.ignoreContentAdaptWithSize.call(this, ignore);
    //             this._prevIgnoreSize = ignore;
    //         }
    //     },
    //     /**
    //      * Sets capinsets for slider, if slider is using scale9 renderer.
    //      * @param {cc.Rect} capInsets
    //      */
    //     setCapInsets: function (capInsets) {
    //         this.setCapInsetsBarRenderer(capInsets);
    //         this.setCapInsetProgressBarRenderer(capInsets);
    //     },
    /**
     * Sets capinsets for slider's renderer, if slider is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsetsBarRenderer(capInsets: cc.Rect): void;
    //     /**
    //      * Returns cap insets for slider.
    //      * @returns {cc.Rect}
    //      */
    //     getCapInsetsBarRenderer: function () {
    //         return cc.rect(this._capInsetsBarRenderer);
    //     },
    //     /**
    //      * Sets capinsets of ProgressBar for slider, if slider is using scale9 renderer.
    //      * @param {cc.Rect} capInsets
    //      */
    //     setCapInsetProgressBarRenderer: function (capInsets) {
    //         if (!capInsets)
    //             return;
    //         var locInsets = this._capInsetsProgressBarRenderer;
    //         locInsets.x = capInsets.x;
    //         locInsets.y = capInsets.y;
    //         locInsets.width = capInsets.width;
    //         locInsets.height = capInsets.height;
    //         if (!this._scale9Enabled)
    //             return;
    //         this._progressBarRenderer.setCapInsets(capInsets);
    //     },
    //     /**
    //      * Returns cap insets of ProgressBar for slider.
    //      * @returns {cc.Rect}
    //      */
    //     getCapInsetsProgressBarRenderer: function () {
    //         return cc.rect(this._capInsetsProgressBarRenderer);
    //     },
    //     /**
    //      * Loads textures for slider ball.
    //      * @param {String} normal
    //      * @param {String} pressed
    //      * @param {String} disabled
    //      * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
    //      */
    //     loadSlidBallTextures: function (normal, pressed, disabled, texType) {
    //         this.loadSlidBallTextureNormal(normal, texType);
    //         this.loadSlidBallTexturePressed(pressed, texType);
    //         this.loadSlidBallTextureDisabled(disabled, texType);
    //     },
    //     /**
    //      * Loads normal state texture for slider ball.
    //      * @param {String} normal
    //      * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
    //      */
    //     loadSlidBallTextureNormal: function (normal, texType) {
    //         if (!normal) {
    //             return;
    //         }
    //         texType = texType || ccui.Widget.LOCAL_TEXTURE;
    //         this._slidBallNormalTextureFile = normal;
    //         this._ballNTexType = texType;
    //         var self = this;
    //         if (!this._slidBallNormalRenderer._textureLoaded) {
    //             this._slidBallNormalRenderer.addEventListener("load", function () {
    //                 self.loadSlidBallTextureNormal(self._slidBallNormalTextureFile, self._ballNTexType);
    //             });
    //         }
    //         switch (this._ballNTexType) {
    //             case ccui.Widget.LOCAL_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallNormalRenderer.initWithFile(normal);
    //                 break;
    //             case ccui.Widget.PLIST_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallNormalRenderer.initWithSpriteFrameName(normal);
    //                 break;
    //             default:
    //                 break;
    //         }
    //         this._updateChildrenDisplayedRGBA();
    //         this._findLayout();
    //     },
    //     /**
    //      * Loads selected state texture for slider ball.
    //      * @param {String} pressed
    //      * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
    //      */
    //     loadSlidBallTexturePressed: function (pressed, texType) {
    //         if (!pressed) {
    //             return;
    //         }
    //         texType = texType || ccui.Widget.LOCAL_TEXTURE;
    //         this._slidBallPressedTextureFile = pressed;
    //         this._ballPTexType = texType;
    //         var self = this;
    //         if (!this._slidBallPressedRenderer._textureLoaded) {
    //             this._slidBallPressedRenderer.addEventListener("load", function () {
    //                 self.loadSlidBallTexturePressed(self._slidBallPressedTextureFile, self._ballPTexType);
    //             });
    //         }
    //         switch (this._ballPTexType) {
    //             case ccui.Widget.LOCAL_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallPressedRenderer.initWithFile(pressed);
    //                 break;
    //             case ccui.Widget.PLIST_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallPressedRenderer.initWithSpriteFrameName(pressed);
    //                 break;
    //             default:
    //                 break;
    //         }
    //         this._updateChildrenDisplayedRGBA();
    //         this._findLayout();
    //     },
    //     /**
    //      * Load dark state texture for slider ball.
    //      * @param {String} disabled
    //      * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
    //      */
    //     loadSlidBallTextureDisabled: function (disabled, texType) {
    //         if (!disabled) {
    //             return;
    //         }
    //         texType = texType || ccui.Widget.LOCAL_TEXTURE;
    //         this._slidBallDisabledTextureFile = disabled;
    //         this._ballDTexType = texType;
    //         var self = this;
    //         if (!this._slidBallDisabledRenderer._textureLoaded) {
    //             this._slidBallDisabledRenderer.addEventListener("load", function () {
    //                 self.loadSlidBallTextureDisabled(self._slidBallDisabledTextureFile, self._ballDTexType);
    //             });
    //         }
    //         switch (this._ballDTexType) {
    //             case ccui.Widget.LOCAL_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallDisabledRenderer.initWithFile(disabled);
    //                 break;
    //             case ccui.Widget.PLIST_TEXTURE:
    //                 //SetTexture cannot load resource
    //                 this._slidBallDisabledRenderer.initWithSpriteFrameName(disabled);
    //                 break;
    //             default:
    //                 break;
    //         }
    //         this._updateChildrenDisplayedRGBA();
    //         this._findLayout();
    //     },
    /**
     * Changes the progress direction of slider.
     * @param {number} percent
     */
    setPercent(percent: number): void;
    //     /**
    //      * test the point whether location in loadingBar's bounding box.
    //      * @override
    //      * @param {cc.Point} pt
    //      * @returns {boolean}
    //      */
    //     hitTest: function (pt) {
    //         var nsp = this._slidBallNormalRenderer.convertToNodeSpace(pt);
    //         var ballSize = this._slidBallNormalRenderer.getContentSize();
    //         var ballRect = cc.rect(0, 0, ballSize.width, ballSize.height);
    //         return (nsp.x >= ballRect.x &&
    //             nsp.x <= (ballRect.x + ballRect.width) &&
    //             nsp.y >= ballRect.y &&
    //             nsp.y <= (ballRect.y +ballRect.height));
    //     },
    //     onTouchBegan: function (touch, event) {
    //         var pass = ccui.Widget.prototype.onTouchBegan.call(this, touch, event);
    //         if (this._hit) {
    //             var nsp = this.convertToNodeSpace(this._touchBeganPosition);
    //             this.setPercent(this._getPercentWithBallPos(nsp.x));
    //             this._percentChangedEvent();
    //         }
    //         return pass;
    //     },
    //     onTouchMoved: function (touch, event) {
    //         var touchPoint = touch.getLocation();
    //         var nsp = this.convertToNodeSpace(touchPoint);
    //         this.setPercent(this._getPercentWithBallPos(nsp.x));
    //         this._percentChangedEvent();
    //     },
    //     onTouchEnded: function (touch, event) {
    //         ccui.Widget.prototype.onTouchEnded.call(this, touch, event);
    //     },
    //     onTouchCancelled: function (touch, event) {
    //         ccui.Widget.prototype.onTouchCancelled.call(this, touch, event);
    //     },
    //     /**
    //      * Returns percent with ball's position.
    //      * @param {cc.Point} px
    //      * @returns {number}
    //      */
    //     _getPercentWithBallPos: function (px) {
    //         return ((px / this._barLength) * 100);
    //     },
    /**
     * add event listener
     * @param {Function} selector
     * @param {Object} [target=]
     * @deprecated since v3.0, please use addEventListener instead.
     */
    addEventListenerSlider(selector: Function, target?: cc.Node): void;
    /**
     * Adds a callback
     * @param {Function} selector
     * @param {Object} [target=]
     */
    addEventListener(selector: Function, target?: cc.Node): void;
    //     _percentChangedEvent: function () {
    //         if (this._sliderEventSelector) {
    //             if (this._sliderEventListener)
    //                 this._sliderEventSelector.call(this._sliderEventListener, this, ccui.Slider.EVENT_PERCENT_CHANGED);
    //             else
    //                 this._sliderEventSelector(this, ccui.Slider.EVENT_PERCENT_CHANGED);  // _eventCallback
    //         }
    //         if (this._ccEventCallback)
    //             this._ccEventCallback(this, ccui.Slider.EVENT_PERCENT_CHANGED);
    //     },
         /**
          * Gets the progress direction of slider.
    //      * @returns {number}
    //      */
    //     getPercent: function () {
    //         return this._percent;
    //     },
    getPercent():number;
    //     _onSizeChanged: function () {
    //         ccui.Widget.prototype._onSizeChanged.call(this);
    //         this._barRendererAdaptDirty = true;
    //         this._progressBarRendererDirty = true;
    //     },
    //     _adaptRenderers: function () {
    //         if (this._barRendererAdaptDirty) {
    //             this._barRendererScaleChangedWithSize();
    //             this._barRendererAdaptDirty = false;
    //         }
    //         if (this._progressBarRendererDirty) {
    //             this._progressBarRendererScaleChangedWithSize();
    //             this._progressBarRendererDirty = false;
    //         }
    //     },
    //     /**
    //      * Returns the content size of bar renderer.
    //      * @returns {cc.Size}
    //      */
    //     getVirtualRendererSize: function () {
    //         return this._barRenderer.getContentSize();
    //     },
    //     /**
    //      * Returns the bar renderer.
    //      * @returns {cc.Node}
    //      */
    //     getVirtualRenderer: function () {
    //         return this._barRenderer;
    //     },
    //     _barRendererScaleChangedWithSize: function () {
    //         if (this._unifySize) {
    //             this._barLength = this._contentSize.width;
    //             this._barRenderer.setPreferredSize(this._contentSize);
    //         } else if (this._ignoreSize) {
    //             this._barRenderer.setScale(1.0);
    //             this._barLength = this._contentSize.width;
    //         } else {
    //             this._barLength = this._contentSize.width;
    //             if (this._scale9Enabled) {
    //                 this._barRenderer.setPreferredSize(this._contentSize);
    //                 this._barRenderer.setScale(1.0);
    //             } else {
    //                 var btextureSize = this._barTextureSize;
    //                 if (btextureSize.width <= 0.0 || btextureSize.height <= 0.0) {
    //                     this._barRenderer.setScale(1.0);
    //                 } else {
    //                     var bscaleX = this._contentSize.width / btextureSize.width;
    //                     var bscaleY = this._contentSize.height / btextureSize.height;
    //                     this._barRenderer.setScaleX(bscaleX);
    //                     this._barRenderer.setScaleY(bscaleY);
    //                 }
    //             }
    //         }
    //         this._barRenderer.setPosition(this._contentSize.width / 2.0, this._contentSize.height / 2.0);
    //         this.setPercent(this._percent);
    //     },
    //     _progressBarRendererScaleChangedWithSize: function () {
    //         if (this._unifySize) {
    //             this._progressBarRenderer.setPreferredSize(this._contentSize);
    //         } else if (this._ignoreSize) {
    //             if (!this._scale9Enabled) {
    //                 var ptextureSize = this._progressBarTextureSize;
    //                 var pscaleX = this._contentSize.width / ptextureSize.width;
    //                 var pscaleY = this._contentSize.height / ptextureSize.height;
    //                 this._progressBarRenderer.setScaleX(pscaleX);
    //                 this._progressBarRenderer.setScaleY(pscaleY);
    //             }
    //         }
    //         else {
    //             if (this._scale9Enabled) {
    //                 this._progressBarRenderer.setPreferredSize(this._contentSize);
    //                 this._progressBarRenderer.setScale(1);
    //             }
    //             else {
    //                 var ptextureSize = this._progressBarTextureSize;
    //                 if (ptextureSize.width <= 0.0 || ptextureSize.height <= 0.0) {
    //                     this._progressBarRenderer.setScale(1.0);
    //                     return;
    //                 }
    //                 var pscaleX = this._contentSize.width / ptextureSize.width;
    //                 var pscaleY = this._contentSize.height / ptextureSize.height;
    //                 this._progressBarRenderer.setScaleX(pscaleX);
    //                 this._progressBarRenderer.setScaleY(pscaleY);
    //             }
    //         }
    //         this._progressBarRenderer.setPosition(0.0, this._contentSize.height / 2.0);
    //         this.setPercent(this._percent);
    //     },
    //     _onPressStateChangedToNormal: function () {
    //         this._slidBallNormalRenderer.setVisible(true);
    //         this._slidBallPressedRenderer.setVisible(false);
    //         this._slidBallDisabledRenderer.setVisible(false);
    //         this._slidBallNormalRenderer.setScale(this._sliderBallNormalTextureScaleX, this._sliderBallNormalTextureScaleY);
    //         if (cc._renderType === cc.game.RENDER_TYPE_WEBGL) {
    //             this._slidBallNormalRenderer._renderCmd._shaderProgram = this._getNormalGLProgram();
    //         } else {
    //             // TODO: add canvas support
    //         }
    //     },
    //     _onPressStateChangedToPressed: function () {
    //         if (!this._slidBallPressedTextureFile) {
    //             this._slidBallNormalRenderer.setScale(this._sliderBallNormalTextureScaleX + this._zoomScale, this._sliderBallNormalTextureScaleY + this._zoomScale);
    //         } else {
    //             this._slidBallNormalRenderer.setVisible(false);
    //             this._slidBallPressedRenderer.setVisible(true);
    //             this._slidBallDisabledRenderer.setVisible(false);
    //         }
    //         if (cc._renderType === cc.game.RENDER_TYPE_WEBGL) {
    //             this._slidBallNormalRenderer._renderCmd._shaderProgram = this._getNormalGLProgram();
    //         } else {
    //             // TODO: add canvas support
    //         }
    //     },
    //     _onPressStateChangedToDisabled: function () {
    //         if (this._slidBallDisabledTextureFile) {
    //             this._slidBallNormalRenderer.setVisible(false);
    //             this._slidBallDisabledRenderer.setVisible(true);
    //         } else {
    //             this._slidBallNormalRenderer.setVisible(true);
    //             if (cc._renderType === cc.game.RENDER_TYPE_WEBGL) {
    //                 this._slidBallNormalRenderer._renderCmd._shaderProgram = this._getGrayGLProgram();
    //             } else {
    //                 // TODO: add canvas support
    //             }
    //         }
    //         this._slidBallNormalRenderer.setScale(this._sliderBallNormalTextureScaleX, this._sliderBallNormalTextureScaleY);
    //         this._slidBallPressedRenderer.setVisible(false);
    //     },
    //     setZoomScale: function (scale) {
    //         this._zoomScale = scale;
    //     },
    //     getZoomScale: function () {
    //         return this._zoomScale;
    //     },
    //     getSlidBallNormalRenderer: function () {
    //         return this._slidBallNormalRenderer;
    //     },
    //     getSlidBallPressedRenderer: function () {
    //         return this._slidBallPressedRenderer;
    //     },
    //     getSlidBallDisabledRenderer: function () {
    //         return this._slidBallDisabledRenderer;
    //     },
    getSlidBallRenderer(): cc.Node;
    //     /**
    //      * Returns the "class name" of ccui.LoadingBar.
    //      * @returns {string}
    //      */
    //     getDescription: function () {
    //         return "Slider";
    //     },
    //     _createCloneInstance: function () {
    //         return new ccui.Slider();
    //     },
    //     _copySpecialProperties: function (slider) {
    //         this._prevIgnoreSize = slider._prevIgnoreSize;
    //         this.setScale9Enabled(slider._scale9Enabled);
    //         this.loadBarTexture(slider._textureFile, slider._barTexType);
    //         this.loadProgressBarTexture(slider._progressBarTextureFile, slider._progressBarTexType);
    //         this.loadSlidBallTextureNormal(slider._slidBallNormalTextureFile, slider._ballNTexType);
    //         this.loadSlidBallTexturePressed(slider._slidBallPressedTextureFile, slider._ballPTexType);
    //         this.loadSlidBallTextureDisabled(slider._slidBallDisabledTextureFile, slider._ballDTexType);
    //         this.setPercent(slider.getPercent());
    //         this._sliderEventListener = slider._sliderEventListener;
    //         this._sliderEventSelector = slider._sliderEventSelector;
    //         this._zoomScale = slider._zoomScale;
    //         this._ccEventCallback = slider._ccEventCallback;
    //     }
  }

  // var _p = ccui.Slider.prototype;

  // // Extended properties
  // /** @expose */
  // _p.percent;
  // cc.defineGetterSetter(_p, "percent", _p.getPercent, _p.setPercent);

  // _p = null;

  // /**
  //  * allocates and initializes a UISlider.
  //  * @deprecated since v3.0, please use new ccui.Slider() instead.
  //  * @return {ccui.Slider}
  //  */
  // ccui.Slider.create = function (barTextureName, normalBallTextureName, resType) {
  //     return new ccui.Slider(barTextureName, normalBallTextureName, resType);
  // };

  // // Constant
  // //Slider event type
  // /**
  //  * The percent change event flag of ccui.Slider.
  //  * @constant
  //  * @type {number}
  //  */
  // ccui.Slider.EVENT_PERCENT_CHANGED = 0;

  // //Render zorder
  // /**
  //  * The zOrder value of ccui.Slider's base bar renderer.
  //  * @constant
  //  * @type {number}
  //  */
  // ccui.Slider.BASEBAR_RENDERER_ZORDER = -3;
  // /**
  //  * The zOrder value of ccui.Slider's progress bar renderer.
  //  * @constant
  //  * @type {number}
  //  */
  // ccui.Slider.PROGRESSBAR_RENDERER_ZORDER = -2;
  // /**
  //  * The zOrder value of ccui.Slider's ball renderer.
  //  * @constant
  //  * @type {number}
  //  */
  // ccui.Slider.BALL_RENDERER_ZORDER = -1;
}
