declare namespace ccui {
  /**
   * The text control of Cocos UI.
   * @class
   * @extends ccui.Widget
   *
   * @property {Number}   boundingWidth       - Width of the bounding area of label, the real content width is limited by boundingWidth
   * @property {Number}   boundingHeight      - Height of the bounding area of label, the real content height is limited by boundingHeight
   * @property {String}   string              - The content string of the label
   * @property {Number}   stringLength        - <@readonly> The content string length of the label
   * @property {String}   font                - The label font with a style string: e.g. "18px Verdana"
   * @property {String}   fontName            - The label font name
   * @property {Number}   fontSize            - The label font size
   * @property {Number}   textAlign           - Horizontal Alignment of label, cc.TEXT_ALIGNMENT_LEFT|cc.TEXT_ALIGNMENT_CENTER|cc.TEXT_ALIGNMENT_RIGHT
   * @property {Number}   verticalAlign       - Vertical Alignment of label: cc.VERTICAL_TEXT_ALIGNMENT_TOP|cc.VERTICAL_TEXT_ALIGNMENT_CENTER|cc.VERTICAL_TEXT_ALIGNMENT_BOTTOM
   * @property {Boolean}  touchScaleEnabled   - Indicate whether the label will scale when touching
   */
  class Text extends ccui.Widget {
    /**
     * allocates and initializes a UILabel.
     * Constructor of ccui.Text. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @param {String} textContent
     * @param {String} fontName
     * @param {Number} fontSize
     * @example
     * // example
     * var uiLabel = new ccui.Text();
     */
    //   ctor: function (textContent, fontName, fontSize) {
    //       this._type = ccui.Text.Type.SYSTEM;
    //       this._textAreaSize = cc.size(0, 0);
    //       ccui.Widget.prototype.ctor.call(this);

    //       if (fontSize !== undefined) {
    //           this.setFontName(fontName);
    //           this.setFontSize(fontSize);
    //           this.setString(textContent);
    //       } else {
    //           this.setFontName(this._fontName);
    //       }
    //   },
    constructor(textContent: string, fontName: string, fontSize: number);

    //   _initRenderer: function () {
    //       this._labelRenderer = new cc.LabelTTF();
    //       this.addProtectedChild(this._labelRenderer, ccui.Text.RENDERER_ZORDER, -1);
    //   },

    /**
     * Changes the  value of ccui.Text.
     * @param {String} text
     */
    setString(text: string | number): void;
    setStringResize(text: string): void;

    /**
     * Gets the string value of ccui.Text.
     * @returns {String}
     */
    getString(): string;

    //   /**
    //    * Gets the string length of ccui.Text.
    //    * @returns {Number}
    //    */
    //   getStringLength: function () {
    //       return this._labelRenderer.getStringLength();
    //   },

    /**
     * Sets fontSize
     * @param {Number} size
     */
    setFontSize(size: number): void;

    /**
     * Returns font Size of ccui.Text
     * @returns {Number}
     */
    getFontSize(): number;

    /**
     * Sets font name
     * @return {String} name
     */
    setFontName(name: string): void;

    //   _setFontName: function (name) {
    //       this._fontName = name;
    //       this._labelRenderer.setFontName(name);
    //       this._labelRendererAdaptDirty = true;
    //   },

    //   _updateUITextContentSize: function () {
    //       this._updateContentSizeWithTextureSize(this._labelRenderer.getContentSize());
    //   },

    //   /**
    //    * Returns font name of ccui.Text.
    //    * @returns {string}
    //    */
    //   getFontName: function () {
    //       return this._fontName;
    //   },

    //   _setFont: function (font) {
    //       var res = cc.LabelTTF._fontStyleRE.exec(font);
    //       if (res) {
    //           this._fontSize = parseInt(res[1]);
    //           this._fontName = res[2];
    //           this._labelRenderer._setFont(font);
    //           this._labelScaleChangedWithSize();
    //       }
    //   },
    //   _getFont: function () {
    //       return this._labelRenderer._getFont();
    //   },

    //   /**
    //    * Returns the type of ccui.Text.
    //    * @returns {null}
    //    */
    //   getType: function () {
    //       return this._type;
    //   },

    /**
     * Sets text Area Size
     * @param {cc.Size} size
     */
    setTextAreaSize(size: cc.Size): void;

    //   _setTextAreaSize: function (size) {
    //       this._labelRenderer.setDimensions(size);
    //       if (!this._ignoreSize){
    //           this._customSize = size;
    //       }
    //       this._labelRendererAdaptDirty = true;
    //   },

    //   /**
    //    * Returns renderer's dimension.
    //    * @returns {cc.Size}
    //    */
    //   getTextAreaSize: function () {
    //       return this._labelRenderer.getDimensions();
    //   },

    /**
     * Sets Horizontal Alignment of cc.LabelTTF
     * @param {cc.TEXT_ALIGNMENT_LEFT|cc.TEXT_ALIGNMENT_CENTER|cc.TEXT_ALIGNMENT_RIGHT} alignment Horizontal Alignment
     */
    setTextHorizontalAlignment(alignment: number): void;

    /**
     * Returns Horizontal Alignment of label
     * @returns {TEXT_ALIGNMENT_LEFT|TEXT_ALIGNMENT_CENTER|TEXT_ALIGNMENT_RIGHT}
     */
    getTextHorizontalAlignment(): number;

    /**
     * Sets Vertical Alignment of label
     * @param {cc.VERTICAL_TEXT_ALIGNMENT_TOP|cc.VERTICAL_TEXT_ALIGNMENT_CENTER|cc.VERTICAL_TEXT_ALIGNMENT_BOTTOM} alignment
     */
    setTextVerticalAlignment(alignment: number): void;

    //   _setTextVerticalAlignment: function (alignment) {
    //       this._labelRenderer.setVerticalAlignment(alignment);
    //       this._labelRendererAdaptDirty = true;
    //   },

    /**
     * Gets text vertical alignment.
     * @returns {VERTICAL_TEXT_ALIGNMENT_TOP|VERTICAL_TEXT_ALIGNMENT_CENTER|VERTICAL_TEXT_ALIGNMENT_BOTTOM}
     */
    getTextVerticalAlignment(): number;

    /**
     * Sets the touch scale enabled of label.
     * @param {Boolean} enable
     */
    setTouchScaleChangeEnabled(enable: boolean): void;

    //   /**
    //    * Gets the touch scale enabled of label.
    //    * @returns {Boolean}
    //    */
    //   isTouchScaleChangeEnabled: function () {
    //       return this._touchScaleChangeEnabled;
    //   },

    //   _onPressStateChangedToNormal: function () {
    //       if (!this._touchScaleChangeEnabled)
    //           return;
    //       this._labelRenderer.setScaleX(this._normalScaleValueX);
    //       this._labelRenderer.setScaleY(this._normalScaleValueY);
    //   },

    //   _onPressStateChangedToPressed: function () {
    //       if (!this._touchScaleChangeEnabled)
    //           return;
    //       this._labelRenderer.setScaleX(this._normalScaleValueX + this._onSelectedScaleOffset);
    //       this._labelRenderer.setScaleY(this._normalScaleValueY + this._onSelectedScaleOffset);
    //   },

    //   _onPressStateChangedToDisabled: function () {
    //   },

    //   _onSizeChanged: function () {
    //       ccui.Widget.prototype._onSizeChanged.call(this);
    //       this._labelRendererAdaptDirty = true;
    //   },

    //   _adaptRenderers: function () {
    //       if (this._labelRendererAdaptDirty) {
    //           this._labelScaleChangedWithSize();
    //           this._labelRendererAdaptDirty = false;
    //       }
    //   },

    //   /**
    //    * Returns the renderer's content size.
    //    * @override
    //    * @returns {cc.Size}
    //    */
    //   getVirtualRendererSize: function () {
    //       return this._labelRenderer.getContentSize();
    //   },

    /**
     * Returns the renderer of ccui.Text.
     * @returns {cc.Node}
     */
    getVirtualRenderer(): cc.LabelTTF;

    //   //@since v3.3
    //   getAutoRenderSize: function () {
    //       var virtualSize = this._labelRenderer.getContentSize();
    //       if (!this._ignoreSize) {
    //           this._labelRenderer.setDimensions(0, 0);
    //           virtualSize = this._labelRenderer.getContentSize();
    //           this._labelRenderer.setDimensions(this._contentSize.width, this._contentSize.height);
    //       }
    //       return virtualSize;
    //   },

    //   _labelScaleChangedWithSize: function () {
    //       var locContentSize = this._contentSize;
    //       if (this._ignoreSize) {
    //           this._labelRenderer.setScale(1.0);
    //           this._normalScaleValueX = this._normalScaleValueY = 1;
    //       } else {
    //           this._labelRenderer.setDimensions(cc.size(locContentSize.width, locContentSize.height));
    //           var textureSize = this._labelRenderer.getContentSize();
    //           if (textureSize.width <= 0.0 || textureSize.height <= 0.0) {
    //               this._labelRenderer.setScale(1.0);
    //               return;
    //           }
    //           var scaleX = locContentSize.width / textureSize.width;
    //           var scaleY = locContentSize.height / textureSize.height;
    //           this._labelRenderer.setScaleX(scaleX);
    //           this._labelRenderer.setScaleY(scaleY);
    //           this._normalScaleValueX = scaleX;
    //           this._normalScaleValueY = scaleY;
    //       }
    //       this._labelRenderer.setPosition(locContentSize.width / 2.0, locContentSize.height / 2.0);
    //   },

    //   /**
    //    * Returns the "class name" of ccui.Text.
    //    * @returns {string}
    //    */
    //   getDescription: function () {
    //       return "Label";
    //   },

    /**
     * Enables shadow style and sets color, offset and blur radius styles.
     * @param {cc.Color} shadowColor
     * @param {cc.Size} offset
     * @param {Number} blurRadius
     */
    enableShadow(
      shadowColor: cc.Color,
      offset?: cc.Size,
      blurRadius?: number,
    ): void;

    /**
     * Enables outline style and sets outline's color and size.
     * @param {cc.Color} outlineColor
     * @param {cc.Size} outlineSize
     */
    enableOutline(outlineColor: cc.Color, outlineSize?: number | cc.Size): void;

    //   /**
    //    * Enables glow color
    //    * @param glowColor
    //    */
    //   enableGlow: function (glowColor) {
    //       if (this._type === ccui.Text.Type.TTF)
    //           this._labelRenderer.enableGlow(glowColor);
    //   },

    //   /**
    //    * Disables renderer's effect.
    //    */
    //   disableEffect: function () {
    //       if (this._labelRenderer.disableEffect)
    //           this._labelRenderer.disableEffect();
    //   },

    //   _createCloneInstance: function () {
    //       return new ccui.Text();
    //   },

    //   _copySpecialProperties: function (uiLabel) {
    //       if (uiLabel instanceof ccui.Text) {
    //           this.setFontName(uiLabel._fontName);
    //           this.setFontSize(uiLabel.getFontSize());
    //           this.setString(uiLabel.getString());
    //           this.setTouchScaleChangeEnabled(uiLabel.touchScaleEnabled);
    //           this.setTextAreaSize(uiLabel._textAreaSize);
    //           this.setTextHorizontalAlignment(uiLabel._labelRenderer.getHorizontalAlignment());
    //           this.setTextVerticalAlignment(uiLabel._labelRenderer.getVerticalAlignment());
    //           this.setContentSize(uiLabel.getContentSize());
    //           this.setTextColor(uiLabel.getTextColor());
    //       }
    //   },

    //   _setBoundingWidth: function (value) {
    //       this._textAreaSize.width = value;
    //       this._labelRenderer._setBoundingWidth(value);
    //       this._labelScaleChangedWithSize();
    //   },
    //   _setBoundingHeight: function (value) {
    //       this._textAreaSize.height = value;
    //       this._labelRenderer._setBoundingHeight(value);
    //       this._labelScaleChangedWithSize();
    //   },
    //   _getBoundingWidth: function () {
    //       return this._textAreaSize.width;
    //   },
    //   _getBoundingHeight: function () {
    //       return this._textAreaSize.height;
    //   },

    //   _changePosition: function () {
    //       this._adaptRenderers();
    //   },

    setColor(color: cc.Color): void;

    setTextColor(color: cc.Color): void;
    //   getTextColor: function () {
    //       return this._labelRenderer._getFillStyle();
    //   }
    // });
    get boundingWidth(): number;
    set boundingWidth(value: number);

    get boundingHeight(): number;
    set boundingHeight(value: number);

    // var _p = ccui.Text.prototype;

    // // Extended properties
    // /** @expose */
    // _p.boundingWidth;
    // cc.defineGetterSetter(_p, "boundingWidth", _p._getBoundingWidth, _p._setBoundingWidth);
    // /** @expose */
    // _p.boundingHeight;
    // cc.defineGetterSetter(_p, "boundingHeight", _p._getBoundingHeight, _p._setBoundingHeight);
    // /** @expose */
    // _p.string;
    // cc.defineGetterSetter(_p, "string", _p.getString, _p.setString);
    // /** @expose */
    // _p.stringLength;
    // cc.defineGetterSetter(_p, "stringLength", _p.getStringLength);
    // /** @expose */
    // _p.font;
    // cc.defineGetterSetter(_p, "font", _p._getFont, _p._setFont);
    // /** @expose */
    // _p.fontSize;
    // cc.defineGetterSetter(_p, "fontSize", _p.getFontSize, _p.setFontSize);
    // /** @expose */
    // _p.fontName;
    // cc.defineGetterSetter(_p, "fontName", _p.getFontName, _p.setFontName);
    // /** @expose */
    // _p.textAlign;
    // cc.defineGetterSetter(_p, "textAlign", _p.getTextHorizontalAlignment, _p.setTextHorizontalAlignment);
    // /** @expose */
    // _p.verticalAlign;
    // cc.defineGetterSetter(_p, "verticalAlign", _p.getTextVerticalAlignment, _p.setTextVerticalAlignment);

    // _p = null;

    // /**
    // * allocates and initializes a UILabel.
    // * @deprecated since v3.0, please use new ccui.Text() instead.
    // * @return {ccui.Text}
    // */
    // ccui.Label = ccui.Text.create = function (textContent, fontName, fontSize) {
    //   return new ccui.Text(textContent, fontName, fontSize);
    // };

    // /**
    // * The zOrder value of ccui.Text's renderer.
    // * @constant
    // * @type {number}
    // */
    // ccui.Text.RENDERER_ZORDER = -1;

    // /**
    // * @ignore
    // */
    // ccui.Text.Type = {
    //   SYSTEM: 0,
    //   TTF: 1
    // };
  }
}
