declare namespace ccui {
  // /**
  //  * The ImageView control of Cocos GUI
  //  * @class
  //  * @extends ccui.Widget
  //  */
  class ImageView extends ccui.Widget {
    /**
     * allocates and initializes a ccui.ImageView.
     * Constructor of ccui.ImageView, override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @param {String} imageFileName
     * @param {Number} [texType==ccui.Widget.LOCAL_TEXTURE]
     * @example
     * // example
     * var uiImageView = new ccui.ImageView;
     */
    constructor(imageFileName?: string, texType?: number);

    /**
     * Loads textures for button.
     * @param {String} fileName
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTexture(fileName: string, texType?: number): void;

    //   /**
    //    * Sets texture rect
    //    * @param {cc.Rect} rect
    //    */
    //   setTextureRect: function () {
    //       cc.warn('ImageView.setTextureRect  is deprecated!');
    //   },

    /**
     * Sets if button is using scale9 renderer.
     * @param {Boolean} able
     */
    setScale9Enabled(able: boolean): void;

    //   /**
    //    * Returns ImageView is using scale9 renderer or not.
    //    * @returns {Boolean}
    //    */
    //   isScale9Enabled:function(){
    //       return this._scale9Enabled;
    //   },

    //   /**
    //    * Ignore the imageView's custom size, true that imageView will ignore it's custom size, use renderer's content size, false otherwise.
    //    * @override
    //    * @param {Boolean} ignore
    //    */
    //   ignoreContentAdaptWithSize: function (ignore) {
    //       if (!this._scale9Enabled || (this._scale9Enabled && !ignore)) {
    //           ccui.Widget.prototype.ignoreContentAdaptWithSize.call(this, ignore);
    //           this._prevIgnoreSize = ignore;
    //       }
    //   },

    /**
     * Sets capinsets for button, if button is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsets(capInsets: cc.Rect): void;

    setFillType(type: number): void;
    //   /**
    //    * Returns cap insets of ccui.ImageView.
    //    * @returns {cc.Rect}
    //    */
    //   getCapInsets:function(){
    //       return cc.rect(this._capInsets);
    //   },

    //   _onSizeChanged: function () {
    //       ccui.Widget.prototype._onSizeChanged.call(this);
    //       this._imageRendererAdaptDirty = true;
    //   },

    //   _adaptRenderers: function(){
    //       if (this._imageRendererAdaptDirty){
    //           this._imageTextureScaleChangedWithSize();
    //           this._imageRendererAdaptDirty = false;
    //       }
    //   },

    //   /**
    //    * Returns the image's texture size.
    //    * @returns {cc.Size}
    //    */
    //   getVirtualRendererSize: function(){
    //       return cc.size(this._imageTextureSize);
    //   },

    /**
     * Returns the renderer of ccui.ImageView
     * @override
     * @returns {cc.Node}
     */
    getVirtualRenderer(): ccui.Scale9Sprite;

    //   _imageTextureScaleChangedWithSize: function () {
    //       this._imageRenderer.setContentSize(this._contentSize);
    //       this._imageRenderer.setPosition(this._contentSize.width / 2.0, this._contentSize.height / 2.0);
    //   },

    //   /**
    //    * Returns the "class name" of ccui.ImageView.
    //    * @override
    //    * @returns {string}
    //    */
    //   getDescription: function () {
    //       return "ImageView";
    //   },

    //   _createCloneInstance:function(){
    //       return new ccui.ImageView();
    //   },

    //   _copySpecialProperties: function (imageView) {
    //       if(imageView instanceof ccui.ImageView){
    //           this._prevIgnoreSize = imageView._prevIgnoreSize;
    //           this._capInsets = imageView._capInsets;
    //           this.loadTexture(imageView._textureFile, imageView._imageTexType);
    //           this.setScale9Enabled(imageView._scale9Enabled);
    //       }
    //   },
    //   /**
    //    * Sets _customSize of ccui.Widget, if ignoreSize is true, the content size is its renderer's contentSize, otherwise the content size is parameter.
    //    * and updates size percent by parent content size. At last, updates its children's size and position.
    //    * @param {cc.Size|Number} contentSize content size or width of content size
    //    * @param {Number} [height]
    //    * @override
    //    */
    //   setContentSize: function(contentSize, height){
    //       if (height) {
    //           contentSize = cc.size(contentSize, height);
    //       }

    //       ccui.Widget.prototype.setContentSize.call(this, contentSize);
    //       this._imageRenderer.setContentSize(contentSize);
    //   }

    // });

    // /**
    // * Allocates and initializes a UIImageView.
    // * @deprecated since v3.0, please use new ccui.ImageView() instead.
    // * @param {string} imageFileName
    // * @param {Number} texType
    // * @return {ccui.ImageView}
    // */
    // ccui.ImageView.create = function (imageFileName, texType) {
    //   return new ccui.ImageView(imageFileName, texType);
    // };

    // // Constants
    // /**
    // * The zOrder value of ccui.ImageView's renderer.
    // * @constant
    // * @type {number}
    // */
    // ccui.ImageView.RENDERER_ZORDER = -1;
  }
}
