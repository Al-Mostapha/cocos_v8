declare namespace ccui {
  /**
   * The TextBMFont control of Cocos UI, it rendered by LabelBMFont.
   * @class
   * @extends ccui.Widget
   *
   * @property {String}   string  - Content string of the label
   */
  class TextBMFont extends Widget {
    // ccui.LabelBMFont = ccui.TextBMFont = ccui.Widget.extend(/** @lends ccui.TextBMFont# */{
    //   _labelBMFontRenderer: null,
    //   _fntFileHasInit: false,
    //   _fntFileName: "",
    //   _stringValue: "",
    //   _className: "TextBMFont",
    //   _labelBMFontRendererAdaptDirty: true,

    //   /**
    //    * Allocates and initializes a TextBMFont.                <br/>
    //    * Constructor of ccui.TextBMFont. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
    //    * @param {String} text
    //    * @param {String} filename
    //    * @example
    //    * // example
    //    * var uiLabelBMFont = new ccui.TextBMFont();
    //    */
    constructor(text?: string, fileName?: string);

    //   _initRenderer: function () {
    //     this._labelBMFontRenderer = new cc.LabelBMFont();
    //     this.addProtectedChild(this._labelBMFontRenderer, ccui.TextBMFont.RENDERER_ZORDER, -1);
    //   },

    /**
     * Initializes a bitmap font atlas with an initial string and the FNT file
     * @param {String} fileName
     */
    setFntFile(fileName: string): void;

    //   /**
    //    * Sets string value for TextBMFont
    //    * @deprecated since v3.0, please use setString instead.
    //    * @param {String} value
    //    */
    //   setText: function (value) {
    //     cc.log("Please use the setString");
    //     this.setString(value);
    //   },

    /**
     * Sets string value for TextBMFont
     * @param {String} value
     */
    setString(value: string): void;

    //   /**
    //    * Returns string value for TextBMFont.
    //    * @returns {String}
    //    */
    //   getString: function () {
    //     return this._stringValue;
    //   },

    //   /**
    //    * Returns the length of TextBMFont's string.
    //    * @returns {Number}
    //    */
    //   getStringLength: function () {
    //     return this._labelBMFontRenderer.getStringLength();
    //   },

    //   _onSizeChanged: function () {
    //     ccui.Widget.prototype._onSizeChanged.call(this);
    //     this._labelBMFontRendererAdaptDirty = true;
    //   },

    //   _adaptRenderers: function () {
    //     if (this._labelBMFontRendererAdaptDirty) {
    //       this._labelBMFontScaleChangedWithSize();
    //       this._labelBMFontRendererAdaptDirty = false;
    //     }
    //   },

    //   /**
    //    * Returns TextBMFont's content size
    //    * @override
    //    * @returns {cc.Size}
    //    */
    //   getVirtualRendererSize: function () {
    //     return this._labelBMFontRenderer.getContentSize();
    //   },

    //   /**
    //    * Returns the renderer of TextBMFont
    //    * @override
    //    * @returns {cc.Node}
    //    */
    //   getVirtualRenderer: function () {
    //     return this._labelBMFontRenderer;
    //   },

    //   _labelBMFontScaleChangedWithSize: function () {
    //     var locRenderer = this._labelBMFontRenderer;
    //     if (this._ignoreSize)
    //       locRenderer.setScale(1.0);
    //     else {
    //       var textureSize = locRenderer.getContentSize();
    //       if (textureSize.width <= 0.0 || textureSize.height <= 0.0) {
    //         locRenderer.setScale(1.0);
    //         return;
    //       }
    //       locRenderer.setScaleX(this._contentSize.width / textureSize.width);
    //       locRenderer.setScaleY(this._contentSize.height / textureSize.height);
    //     }
    //     locRenderer.setPosition(this._contentSize.width / 2.0, this._contentSize.height / 2.0);
    //   },

    //   /**
    //    * Returns the "class name" of ccui.TextBMFont.
    //    * @returns {string}
    //    */
    //   getDescription: function () {
    //     return "TextBMFont";
    //   },

    //   _createCloneInstance: function () {
    //     return new ccui.TextBMFont();
    //   },

    //   _copySpecialProperties: function (labelBMFont) {
    //     this.setFntFile(labelBMFont._fntFileName);
    //     this.setString(labelBMFont._stringValue);
    //   }
    // });

    // var _p = ccui.TextBMFont.prototype;

    // // Extended properties
    // /** @expose */
    // _p.string;
    // cc.defineGetterSetter(_p, "string", _p.getString, _p.setString);

    // _p = null;

    // Constants
    /**
     * The zOrder value of TextBMFont's renderer.
     * @constant
     * @type {number}
     */
    static readonly RENDERER_ZORDER: number;
  }
}
