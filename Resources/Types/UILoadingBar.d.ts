declare module ccui {

    /**
     * The LoadingBar control of Cocos UI.
     * @class
     * @extends ccui.Widget
     *
     * @property {ccui.LoadingBar.TYPE_LEFT | ccui.LoadingBar.TYPE_RIGHT}   direction   - The progress direction of loadingbar
     * @property {Number}               percent     - The current progress of loadingbar
     */
  class  LoadingBar extends Widget {
    /**
     * allocates and initializes a UILoadingBar.                                                        <br/>
     * Constructor of ccui.LoadingBar, override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @param {string} textureName
     * @param {Number} percentage
     * @example
     * // example
     * var uiLoadingBar = new ccui.LoadingBar;
     */
    constructor(textureName?: string, percentage?: number);

    /**
     * Changes the progress direction of LoadingBar.                           <br/>
     * LoadingBarTypeLeft means progress left to right, LoadingBarTypeRight otherwise.
     * @param {ccui.LoadingBar.TYPE_LEFT | ccui.LoadingBar.TYPE_RIGHT} dir
     */
    setDirection(dir: number) : void;

    /**
     * Returns the progress direction of LoadingBar.                               <br/>
     * LoadingBarTypeLeft means progress left to right, LoadingBarTypeRight otherwise.
     * @returns {ccui.LoadingBar.TYPE_LEFT | ccui.LoadingBar.TYPE_RIGHT}
     */
    getDirection(): number;

    /**
     * Loads texture for LoadingBar.
     * @param {String} texture
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTexture(texture: string, texType: number): void;

    /**
     * Sets if LoadingBar is using scale9 renderer.
     * @param {Boolean} enabled
     */
    setScale9Enabled(enabled: boolean) : void;

    /**
     * Returns LoadingBar is using scale9 renderer or not..
     * @returns {Boolean}
     */
    isScale9Enabled(): boolean;

    /**
     * Sets capinsets for LoadingBar, if LoadingBar is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsets(capInsets: cc.Rect): void;

    /**
     * Returns cap insets for loadingBar.
     * @returns {cc.Rect}
     */
    getCapInsets(): cc.Rect;

    /**
     * The current progress of loadingBar
     * @param {number} percent   percent value from 1 to 100.
     */
    setPercent(percent: number): void;

    /**
     * Returns the progress direction of LoadingBar.
     * @returns {number} percent value from 1 to 100.
     */
    getPercent(): number;

    /**
     * Ignore the LoadingBar's custom size,  if ignore is true that LoadingBar will ignore it's custom size, use renderer's content size, false otherwise.
     * @override
     * @param {Boolean}ignore
     */
    ignoreContentAdaptWithSize(ignore: boolean): void;

    /**
     * Returns the texture size of renderer.
     * @returns {cc.Size|*}
     */
    getVirtualRendererSize(): cc.Size;

    /**
     * Returns the "class name" of widget.
     * @returns {string}
     */
    getDescription(): string;

    get direction(): number;
    set direction(value: number);
    get percent(): number;
    set percent(value: number);

    /**
    * The left direction of ccui.LoadingBar.
    * @constant
    * @type {number}
    */
    static readonly TYPE_LEFT = 0;
    /**
    * The right direction of ccui.LoadingBar.
    * @constant
    * @type {number}
    */
    static readonly TYPE_RIGHT = 1;

    /**
    * The zOrder value of ccui.LoadingBar's renderer.
    * @constant
    * @type {number}
    */
    static readonly RENDERER_ZORDER = -1;

  }
}
