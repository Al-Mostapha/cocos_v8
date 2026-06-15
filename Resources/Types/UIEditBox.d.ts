declare namespace cc {
  /**
   * The CheckBox control of Cocos UI.
   * @class
   * @extends ccui.Widget
   *
   * @property {Boolean}  selected    - Indicate whether the check box has been selected
   */
  class EditBox extends ccui.Widget {
    constructor(size: cc.Size, normal9SpriteBg?: string);

    static create(size: cc.Size, normal9SpriteBg?: ccui.Scale9Sprite): EditBox;

    setTouchEnabled(enable: boolean): void;

    _createRenderCmd(): any;

    setContentSize(width: cc.Size | number, height?: number): void;

    setVisible(visible: boolean): void;

    createDomElementIfNeeded(): void;

    setTabIndex(index: number): void;

    getTabIndex(): number;

    setFocus(): void;

    isFocused(): boolean;

    stayOnTop(flag: boolean): void;

    cleanup(): void;

    touchDownAction(txt: EditBox, event: number): void;

    registerScriptEditBoxHandler(handle: Function): void;

    getText(): string;

    closeKeyboard(): void;
    // ADDED
    closeIME(): void;

    setLineHeight(lineHeight: number): void;

    /**
     * Sets the font.
     * @param {String} fontName  The font name.
     * @param {Number} fontSize  The font size.
     */
    setFont(fontName: string, fontSize: number): void;

    getBackgroundSprite(): cc.Sprite;

    /**
     * Sets fontName
     * @param {String} fontName
     */
    setFontName(fontName: string): void;

    /**
     * Sets fontSize
     * @param {Number} fontSize
     */
    setFontSize(fontSize: number): void;

    /**
     * Sets the text entered in the edit box.
     * @param {string} text The given text.
     */
    setString(text: string): void;

    /**
     * Sets the font color of the widget's text.
     * @param {cc.Color} color
     */
    setFontColor(color: cc.Color): void;

    /**
     * Sets the maximum input length of the edit box. <br/>
     * Setting this value enables multiline input mode by default.
     * @param {Number} maxLength The maximum length.
     */
    setMaxLength(maxLength: number): void;

    /**
     * Gets the maximum input length of the edit box.
     * @return {Number} Maximum input length.
     */
    getMaxLength(): number;

    /**
     * Sets a text in the edit box that acts as a placeholder when an edit box is empty.
     * @param {string} text The given text.
     */
    setPlaceHolder(text: string): void;

    /**
     * Sets the placeholder's font.
     * @param {String} fontName
     * @param {Number} fontSize
     */
    setPlaceholderFont(fontName: string, fontSize: number): void;

    /**
     * Sets the placeholder's fontName.
     * @param {String} fontName
     */
    setPlaceholderFontName(fontName: string): void;

    /**
     * Sets the placeholder's fontSize.
     * @param {Number} fontSize
     */
    setPlaceholderFontSize(fontSize: number): void;

    /**
     * Sets the font color of the placeholder text when the edit box is empty.
     * @param {cc.Color} color
     */
    setPlaceholderFontColor(color: cc.Color): void;

    /**
     * Sets the input flags that are to be applied to the edit box.
     * @param {Number} inputFlag One of the EditBoxInputFlag constants.
     * e.g.cc.EDITBOX_INPUT_FLAG_PASSWORD
     */
    setInputFlag(inputFlag: number): void;

    /**
     * Gets the input string of the edit box.
     * @return {string}
     */
    getString(): string;

    /**
     * Init edit box with specified size.
     * @param {cc.Size} size
     * @param {cc.Color | cc.Scale9Sprite} normal9SpriteBg
     */
    initWithSizeAndBackgroundSprite(
      size: cc.Size,
      normal9SpriteBg: any
    ): boolean;

    /**
     * Sets the delegate for edit box.
     * @param {cc.EditBoxDelegate} delegate
     */
    setDelegate(delegate: cc.EditBoxDelegate): void;

    /**
     * Gets the text in the edit box that acts as a placeholder when an
     * edit box is empty.
     * @return {String}
     */
    getPlaceHolder(): string;

    /**
     * Sets the input mode of the edit box.
     * @param {Number} inputMode One of the EditBoxInputMode constants.
     */
    setInputMode(inputMode: number): void;

    /**
     * Sets the return type that are to be applied to the edit box.
     * @param {Number} returnType One of the CCKeyboardReturnType constants.
     */
    setReturnType(returnType: number): void;

    /**
     * @warning HTML5 Only
     * @param {cc.Size} size
     * @param {cc.color} bgColor
     */
    initWithBackgroundColor(size: cc.Size, bgColor: cc.Color): void;

    setTextHorizontalAlignment(alignment: number): void;

    setTextVerticalAlignment(alignment: number): void;
  }
}
