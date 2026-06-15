declare namespace ccui {
  class Widget extends cc.ProtectedNode {
    _touchBeganPosition: cc.Point;
    _touchMovePosition: cc.Point;
    _touchEndPosition: cc.Point; ///< touch ended point
    _hit: boolean;
    // /**
    // * The base class for ccui controls and layout
    // * @sample
    // * var uiWidget = new ccui.Widget();
    // * this.addChild(uiWidget);
    // * @class
    // * @extends ccui.ProtectedNode
    // *
    // * @property {Number}           xPercent        - Position x in percentage of width
    // * @property {Number}           yPercent        - Position y in percentage of height
    // * @property {Number}           widthPercent    - Width in percentage of parent width
    // * @property {Number}           heightPercent   - Height in percentage of parent height
    // * @property {ccui.Widget}      widgetParent    - <@readonly> The direct parent when it's a widget also, otherwise equals null
    // * @property {Boolean}          enabled         - Indicate whether the widget is enabled
    // * @property {Boolean}          focused         - Indicate whether the widget is focused
    // * @property {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT}     sizeType        - The size type of the widget
    // * @property {ccui.Widget.TYPE_WIDGET|ccui.Widget.TYPE_CONTAINER}   widgetType      - <@readonly> The type of the widget
    // * @property {Boolean}          touchEnabled    - Indicate whether touch events are enabled
    // * @property {Boolean}          updateEnabled   - Indicate whether the update function is scheduled
    // * @property {Boolean}          bright          - Indicate whether the widget is bright
    // * @property {String}           name            - The name of the widget
    // * @property {Number}           actionTag       - The action tag of the widget
    // */
    // ccui.Widget = ccui.ProtectedNode.extend(/** @lends ccui.Widget# */{
    constructor();

    /**
     * The direct parent when it's a widget also, otherwise equals null
     * @returns {ccui.Widget|null}
     */
    getWidgetParent(): ccui.Widget | null;

    /**
     * Allow widget touch events to propagate to its parents. Set false will disable propagation
     * @since v3.2
     * @param {Boolean} isPropagate
     */
    setPropagateTouchEvents(isPropagate: boolean): void;

    /**
     * Return whether the widget is propagate touch events to its parents or not
     * @since v3.2
     * @returns {boolean}
     */
    isPropagateTouchEvents(): boolean;

    /**
     * Specify widget to swallow touches or not
     * @since v3.2
     * @param {Boolean} swallow
     */
    setSwallowTouches(swallow: boolean): void;

    /**
     * Return whether the widget is swallowing touch or not
     * @since v3.2
     * @returns {boolean}
     */
    isSwallowTouches(): boolean;

    /**
     * <p>
     *     Sets whether the widget is enabled                                                                                    <br/>
     *     true if the widget is enabled, widget may be touched , false if the widget is disabled, widget cannot be touched.     <br/>
     *     The default value is true, a widget is default to enabled
     * </p>
     * @param {Boolean} enabled
     */
    setEnabled(enabled: boolean): void;

    /**
     * Changes the percent that is widget's percent size
     * @param {cc.Point} percent that is widget's percent size, width and height value from 0 to 1.
     */
    setSizePercent(percent: cc.Point): void;

    /**
     * updates its size by size type and its position by position type.
     * @param {cc.Size} [parentSize] parent size
     */
    updateSizeAndPosition(parentSize: cc.Size): void;

    /**TEXTURE_RES_TYPE
     * Changes the size type of widget.
     * @param {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT} type that is widget's size type
     */
    setSizeType(type: number): void;

    /**
     * Gets the size type of widget.
     * @returns {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT} that is widget's size type
     */
    getSizeType(): number;

    /**
     * Ignore the widget size
     * @param {Boolean} ignore true that widget will ignore it's size, use texture size, false otherwise. Default value is true.
     */
    ignoreContentAdaptWithSize(ignore: boolean): void;

    /**
     * Gets whether ignore the content size (custom size)
     * @returns {boolean}  true that widget will ignore it's size, use texture size, false otherwise.
     */
    isIgnoreContentAdaptWithSize(): boolean;

    /**
     * Get custom size of ccui.Widget
     * @returns {cc.Size}
     */
    getCustomSize(): cc.Size;

    /**
     * Gets layout size of ccui.Widget.
     * @returns {cc.Size}
     */
    getLayoutSize(): cc.Size;

    /**
     * Returns size percent of ccui.Widget
     * @returns {cc.Point}
     */
    getSizePercent(): cc.Point;

    /**
     *  Gets world position of ccui.Widget.
     * @returns {cc.Point} world position of ccui.Widget.
     */
    getWorldPosition(): cc.Point;

    /**
     * Gets the Virtual Renderer of widget.
     * @returns {ccui.Widget}
     */
    getVirtualRenderer(): cc.Node;

    /**
     * Gets the content size of widget.  Content size is widget's texture size.
     */
    getVirtualRendererSize(): cc.Size;

    /**
     * Sets whether the widget is touch enabled. The default value is false, a widget is default to touch disabled
     * @param {Boolean} enable  true if the widget is touch enabled, false if the widget is touch disabled.
     */
    setTouchEnabled(enable: boolean): void;

    /**
     * Returns whether or not touch is enabled.
     * @returns {boolean} true if the widget is touch enabled, false if the widget is touch disabled.
     */
    isTouchEnabled(): boolean;

    /**
     * Determines if the widget is highlighted
     * @returns {boolean} true if the widget is highlighted, false if the widget is not highlighted .
     */
    isHighlighted(): boolean;

    /**
     * Sets whether the widget is highlighted. The default value is false, a widget is default to not highlighted
     * @param highlight true if the widget is highlighted, false if the widget is not highlighted.
     */
    setHighlighted(highlight: boolean): void;

    /**
     * Determines if the widget is on focused
     * @returns {boolean} whether the widget is focused or not
     */
    isFocused(): boolean;

    /**
     * Sets whether the widget is on focused
     * The default value is false, a widget is default to not on focused
     * @param {boolean} focus  pass true to let the widget get focus or pass false to let the widget lose focus
     */
    setFocused(focus: boolean): void;

    /**
     * returns whether the widget could accept focus.
     * @returns {boolean} true represent the widget could accept focus, false represent the widget couldn't accept focus
     */
    isFocusEnabled(): boolean;

    /**
     * sets whether the widget could accept focus.
     * @param {Boolean} enable true represent the widget could accept focus, false represent the widget couldn't accept focus
     */
    setFocusEnabled(enable: boolean): void;

    /**
     * <p>
     *     When a widget is in a layout, you could call this method to get the next focused widget within a specified direction. <br/>
     *     If the widget is not in a layout, it will return itself
     * </p>
     * @param direction the direction to look for the next focused widget in a layout
     * @param current  the current focused widget
     * @return  the next focused widget in a layout
     */
    findNextFocusedWidget(direction: number, current: ccui.Widget): ccui.Widget;

    /**
     * when a widget calls this method, it will get focus immediately.
     */
    requestFocus(): void;

    /**
     * no matter what widget object you call this method on , it will return you the exact one focused widget
     */
    getCurrentFocusedWidget(): ccui.Widget;

    /**
     * <p>
     *    When a widget lose/get focus, this method will be called. Be Caution when you provide your own version,       <br/>
     *    you must call widget.setFocused(true/false) to change the focus state of the current focused widget;
     * </p>
     */
    onFocusChanged: (
      widgetLostFocus: ccui.Widget,
      widgetGetFocus: ccui.Widget
    ) => void;

    /**
     * use this function to manually specify the next focused widget regards to each direction
     */
    onNextFocusedWidget: (direction: number) => ccui.Widget;

    /**
     * Sends the touch event to widget's parent, its subclass will override it, e.g. ccui.ScrollView, ccui.PageView
     * @param {Number}  eventType
     * @param {ccui.Widget} sender
     * @param {cc.Touch} touch
     */
    interceptTouchEvent(
      eventType: number,
      sender: ccui.Widget,
      touch: cc.Touch
    ): void;

    /**
     * This method is called when a focus change event happens
     * @param {ccui.Widget} widgetLostFocus
     * @param {ccui.Widget} widgetGetFocus
     */
    onFocusChange(
      widgetLostFocus: ccui.Widget,
      widgetGetFocus: ccui.Widget
    ): void;

    /**
     * Dispatch a EventFocus through a EventDispatcher
     * @param {ccui.Widget} widgetLostFocus
     * @param {ccui.Widget} widgetGetFocus
     */
    dispatchFocusEvent(
      widgetLostFocus: ccui.Widget,
      widgetGetFocus: ccui.Widget
    ): void;

    /**
     *  Sets whether the widget is bright. The default value is true, a widget is default to bright
     * @param {Boolean} bright true if the widget is bright, false if the widget is dark.
     */
    setBright(bright: boolean): void;

    /**
     * To set the bright style of ccui.Widget.
     * @param {Number} style BRIGHT_NORMAL the widget is normal state, BRIGHT_HIGHLIGHT the widget is height light state.
     */
    setBrightStyle(style: number): void;

    /**
     * A call back function when widget lost of focus.
     */
    didNotSelectSelf(): void;

    /**
     * <p>
     *    The callback of touch began event.                                                               <br/>
     *    If the bounding box of ccui.Widget contains the touch point, it will do the following things:    <br/>
     *      1. sets highlight state,                                                                       <br/>
     *      2. sends event to parent widget by interceptTouchEvent                                         <br/>
     *      3. calls the callback of touch began event.                                                    <br/>
     *      4. returns true,                                                                               <br/>
     *    otherwise returns false directly.                                                                <br/>
     * </p>
     * @override
     * @param {cc.Touch} touch
     * @param {cc.Event} event
     * @returns {boolean}
     */
    onTouchBegan(touch: cc.Touch, event: cc.Event): boolean;

    propagateTouchEvent(event: cc.Event, sender: any, touch: cc.Touch): void;

    /**
     * <p>
     *    The callback of touch moved event.                                                                                                <br/>
     *    It sets the highlight state by touch, sends event to parent widget by interceptTouchEvent and calls the callback of touch moved event.
     * </p>
     * @param {cc.Touch} touch
     * @param {cc.Event} event
     */
    onTouchMoved(touch: cc.Touch, event: cc.Event): void;

    /**
     * <p>
     *      The callback of touch end event
     *      It sends event to parent widget by interceptTouchEvent,
     *      calls the callback of touch end event (highlight= true) or touch canceled event (highlight= false).
     *      sets the highlight state to false ,
     * </p>
     * @param touch
     * @param event
     */
    onTouchEnded(touch: cc.Touch, event: cc.Event): void;

    /**
     * A call back function called when widget is selected, and on touch canceled.
     * @param {cc.Point} touchPoint
     */
    onTouchCancelled(touchPoint: cc.Touch, event: cc.Event): void;

    /**
     * A call back function called when widget is selected, and on touch long clicked.
     * @param {cc.Point} touchPoint
     */
    onTouchLongClicked(touchPoint: cc.Point): void;

    //   longClickEvent: function () {
    //       //TODO it will implement in v3.1
    //   },

    /**
     * Sets the touch event target/selector of the ccui.Widget
     * @param {Function} selector
     * @param {Object} target
     */
    addTouchEventListener(selector: Function, target?: cc.Node): void;

    addClickEventListener(callback: Function): void;

    /**
     * Checks a point if is in widget's space
     * @param {cc.Point} pt
     * @returns {boolean} true if the point is in widget's space, false otherwise.
     */
    hitTest(pt: cc.Point): boolean;

    //   /**
    //    * returns whether clipping parent widget contains point.
    //    * @param {cc.Point} pt location point
    //    * @returns {Boolean}
    //    */
    //   isClippingParentContainsPoint: function (pt) {
    //       this._affectByClipping = false;
    //       var parent = this.getParent();
    //       var clippingParent = null;
    //       while (parent) {
    //           if (parent instanceof ccui.Layout) {
    //               if (parent.isClippingEnabled()) {
    //                   this._affectByClipping = true;
    //                   clippingParent = parent;
    //                   break;
    //               }
    //           }
    //           parent = parent.getParent();
    //       }

    //       if (!this._affectByClipping)
    //           return true;

    //       if (clippingParent) {
    //           if (clippingParent.hitTest(pt))
    //               return clippingParent.isClippingParentContainsPoint(pt);
    //           return false;
    //       }
    //       return true;
    //   },

    //   /**
    //    * Calls the checkChildInfo of widget's parent, its subclass will override it.
    //    * @param {number} handleState
    //    * @param {ccui.Widget} sender
    //    * @param {cc.Point} touchPoint
    //    */
    //   checkChildInfo: function (handleState, sender, touchPoint) {
    //       var widgetParent = this.getWidgetParent();
    //       if (widgetParent)
    //           widgetParent.checkChildInfo(handleState, sender, touchPoint);
    //   },

    /**
     * Changes the position (x,y) of the widget
     * @param {cc.Point} percent
     */
    setPositionPercent(percent: cc.Point): void;

    /**
     * Gets the percent (x,y) of the widget
     * @returns {cc.Point} The percent (x,y) of the widget in OpenGL coordinates
     */
    getPositionPercent(): cc.Point;

    /**
     * Changes the position type of the widget
     * @param {Number} type  the position type of widget
     */
    setPositionType(type: number): void;

    /**
     * Gets the position type of the widget
     * @returns {Number} the position type of widget
     */
    getPositionType(): number;

    /**
     * Sets whether the widget should be flipped horizontally or not.
     * @param {Boolean} flipX true if the widget should be flipped horizontally, false otherwise.
     */
    setFlippedX(flipX: boolean): void;

    /**
     * <p>
     *   Returns the flag which indicates whether the widget is flipped horizontally or not.             <br/>
     *   It only flips the texture of the widget, and not the texture of the widget's children.          <br/>
     *   Also, flipping the texture doesn't alter the anchorPoint.                                       <br/>
     *   If you want to flip the anchorPoint too, and/or to flip the children too use:                   <br/>
     *   widget.setScaleX(sprite.getScaleX() * -1);
     * </p>
     * @returns {Boolean} true if the widget is flipped horizontally, false otherwise.
     */
    isFlippedX(): boolean;

    /**
     * Sets whether the widget should be flipped vertically or not.
     * @param {Boolean} flipY  true if the widget should be flipped vertically, false otherwise.
     */
    setFlippedY(flipY: boolean): void;

    /**
     * <p>
     *     Return the flag which indicates whether the widget is flipped vertically or not.                <br/>
     *     It only flips the texture of the widget, and not the texture of the widget's children.          <br/>
     *     Also, flipping the texture doesn't alter the anchorPoint.                                       <br/>
     *     If you want to flip the anchorPoint too, and/or to flip the children too use:                   <br/>
     *     widget.setScaleY(widget.getScaleY() * -1);
     * </p>
     * @returns {Boolean} true if the widget is flipped vertically, false otherwise.
     */
    isFlippedY(): boolean;

    /**
     * Determines if the widget is bright
     * @returns {boolean} true if the widget is bright, false if the widget is dark.
     */
    isBright(): boolean;

    /**
     * Determines if the widget is enabled
     * @returns {boolean}
     */
    isEnabled(): boolean;

    /**
     * Gets the left boundary position of this widget.
     * @returns {number}
     */
    getLeftBoundary(): number;

    /**
     * Gets the bottom boundary position of this widget.
     * @returns {number}
     */
    getBottomBoundary(): number;

    /**
     * Gets the right boundary position of this widget.
     * @returns {number}
     */
    getRightBoundary(): number;

    /**
     * Gets the top boundary position of this widget.
     * @returns {number}
     */
    getTopBoundary(): number;

    /**
     * Gets the position of touch began event.
     * @returns {cc.Point}
     */
    getTouchBeganPosition(): cc.Point;

    /**
     * Gets the position of touch moved event
     * @returns {cc.Point}
     */
    getTouchMovePosition(): cc.Point;

    /**
     * Gets the position of touch end event
     * @returns {cc.Point}
     */
    getTouchEndPosition(): cc.Point;

    /**
     * get widget type
     * @returns {ccui.Widget.TYPE_WIDGET|ccui.Widget.TYPE_CONTAINER}
     */
    getWidgetType(): number;

    /**
     * Gets LayoutParameter of widget.
     * @param {ccui.LayoutParameter} parameter
     */
    setLayoutParameter(parameter: ccui.LayoutParameter): void;

    /**
     * Gets layout parameter
     * @param {ccui.LayoutParameter.NONE|ccui.LayoutParameter.LINEAR|ccui.LayoutParameter.RELATIVE} type
     * @returns {ccui.LayoutParameter}
     */
    getLayoutParameter(type?: ccui.LayoutParameter): ccui.LayoutParameter;

    //   /**
    //    * Returns the "class name" of widget.
    //    * @returns {string}
    //    */
    getDescription(): string;

    //   /**
    //    * Clones a new widget.
    //    * @returns {ccui.Widget}
    //    */
    clone<T = ccui.Widget>(): T;

    //   /*temp action*/
    setActionTag(tag: number): void;

    getActionTag(): number;

    //   /**
    //    * Gets the left boundary position of this widget.
    //    * @deprecated since v3.0, please use getLeftBoundary instead.
    //    * @returns {number}
    //    */
    getLeftInParent(): number;

    //   /**
    //    * Gets the bottom boundary position of this widget.
    //    * @deprecated since v3.0, please use getBottomBoundary instead.
    //    * @returns {number}
    //    */
    getBottomInParent(): number;

    //   /**
    //    * Gets the right boundary position of this widget.
    //    * @deprecated since v3.0, please use getRightBoundary instead.
    //    * @returns {number}
    //    */
    getRightInParent(): number;

    //   /**
    //    * Gets the top boundary position of this widget.
    //    * @deprecated since v3.0, please use getTopBoundary instead.
    //    * @returns {number}
    //    */
    getTopInParent(): number;

    //   /**
    //    * Gets the touch end point of widget when widget is selected.
    //    * @deprecated since v3.0, please use getTouchEndPosition instead.
    //    * @returns {cc.Point} the touch end point.
    //    */
    getTouchEndPos(): cc.Point;

    //   /**
    //    *Gets the touch move point of widget when widget is selected.
    //   * @deprecated since v3.0, please use getTouchMovePosition instead.
    //   * @returns {cc.Point} the touch move point.
    //   */
    getTouchMovePos(): cc.Point;

    //   /**
    //    * Checks a point if in parent's area.
    //    * @deprecated since v3.0, please use isClippingParentContainsPoint instead.
    //    * @param {cc.Point} pt
    //    * @returns {Boolean}
    //    */
    clippingParentAreaContainPoin(pt: cc.Point): boolean;

    /**
     * Gets the touch began point of widget when widget is selected.
     * @deprecated since v3.0, please use getTouchBeganPosition instead.
     * @returns {cc.Point} the touch began point.
     */
    getTouchStartPos(): cc.Point;

    /**
     * Changes the size that is widget's size
     * @deprecated since v3.0, please use setContentSize instead.
     * @param {cc.Size} size  that is widget's size
     */
    setSize(size: cc.Size): void;

    /**
     * Returns size of widget
     * @deprecated since v3.0, please use getContentSize instead.
     * @returns {cc.Size}
     */
    getSize(): cc.Size;

    /**
     * Adds a node for widget (this function is deleted in -x)
     * @param {cc.Node} node
     * @param {Number} zOrder
     * @param {Number} tag
     * @deprecated since v3.0, please use addChild instead.
     */
    addNode(node: cc.Node, zOrder: number, tag: number): void;

    /**
     * Gets node by tag
     * @deprecated since v3.0, please use getChildByTag instead.
     * @param {Number} tag
     * @returns {cc.Node}
     */
    getNodeByTag(tag: number): cc.Node;

    //   /**
    //    * Returns all children.
    //    * @deprecated since v3.0, please use getChildren instead.
    //    * @returns {Array}
    //    */
    getNodes(): Array<cc.Node>;

    //   /**
    //    * Removes a node from ccui.Widget
    //    * @deprecated since v3.0, please use removeChild instead.
    //    * @param {cc.Node} node
    //    * @param {Boolean} cleanup
    //    */
    removeNode(node: cc.Node, cleanup: boolean): void;

    //   /**
    //    * Removes node by tag
    //    * @deprecated since v3.0, please use removeChildByTag instead.
    //    * @param {Number} tag
    //    * @param {Boolean} [cleanup]
    //    */
    removeNodeByTag(tag: number, cleanup?: boolean): void;

    //   /**
    //    * Removes all node
    //    * @deprecated since v3.0, please use removeAllChildren instead.
    //    */
    removeAllNodes(): void;

    //   /**
    //    * @since v3.2
    //    * @returns {boolean} true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
    //    */
    isUnifySizeEnabled(): boolean;

    //   /**
    //    * @since v3.2
    //    * @param {Boolean} enable enable Unify Size of a widget
    //    */
    setUnifySizeEnabled(enable: boolean): void;

    //   /**
    //    * Set a event handler to the widget in order to use cocostudio editor and framework
    //    * @since v3.3
    //    * @param {function} callback
    //    */
    addCCSEventListener(callback: Function): void;

    //   //override the scale functions.
    setScaleX(scaleX: number): void;
    setScaleY(scaleY: number): void;

    getScaleX(): number;
    getScaleY(): number;
    getScale(): number;

    //   /**
    //    * Sets callback name to widget.
    //    * @since v3.3
    //    * @param {String} callbackName
    //    */
    setCallbackName(callbackName: string): void;

    //   /**
    //    * Gets callback name of widget
    //    * @since v3.3
    //    * @returns {String|Null}
    //    */
    getCallbackName(): string;

    /**
     * Sets callback type to widget
     * @since v3.3
     * @param {String} callbackType
     */
    setCallbackType(callbackType: string): void;

    /**
     * Gets callback type of widget
     * @since v3.3
     * @returns {String|null}
     */
    getCallbackType(): string | null;

    /**
     * Whether enable layout component of a widget
     * @since v3.3
     * @param {Boolean} enable enable layout Component of a widget
     */
    setLayoutComponentEnabled(enable: boolean): void;

    /**
     * Returns whether enable layout component of a widget
     * @return {Boolean} true represent the widget use Layout Component, false represent the widget couldn't use Layout Component.
     */
    isLayoutComponentEnabled(): boolean;

    get xPercent(): number;
    set xPercent(value: number);
    get yPercent(): number;
    set yPercent(value: number);
    get widthPercent(): number;
    set widthPercent(value: number);
    get heightPercent(): number;
    set heightPercent(value: number);
    get widgetParent(): ccui.Widget | null;
    set widgetParent(value: ccui.Widget);
    get enabled(): boolean;
    set enabled(value: boolean);
    get focused(): boolean;
    set focused(value: boolean);
    get sizeType(): number;
    set sizeType(value: number);
    get widgetType(): number;
    set widgetType(value: number);
    get touchEnabled(): boolean;
    set touchEnabled(value: boolean);
    get updateEnabled(): boolean;
    set updateEnabled(value: boolean);
    get bright(): boolean;
    set bright(value: boolean);
    get name(): string;
    set name(value: string);
    get actionTag(): number;
    set actionTag(value: number);
    get opacity(): number;
    set opacity(value: number);

    // /**
    // * allocates and initializes a UIWidget.
    // * @deprecated
    // * @return {ccui.Widget}
    // */
    static create(...args: any[]): any;

    /**
     * call this method with parameter true to enable the Android Dpad focus navigation feature
     * @note it doesn't implemented on Web
     * @param {Boolean} enable set true to enable dpad focus navigation, otherwise disable dpad focus navigation
     */
    static enableDpadNavigation(enable: boolean): void;

    /**
     * Gets the focused widget of current stage.
     * @function
     * @returns {null|ccui.Widget}
     */
    static getCurrentFocusedWidget(): ccui.Widget | null;

    // Constants
    //bright style
    /**
     * None bright style of ccui.Widget.
     * @constant
     * @type {number}
     */
    static readonly BRIGHT_STYLE_NONE = -1;
    /**
     * Normal bright style of ccui.Widget.
     * @constant
     * @type {number}
     */
    static readonly BRIGHT_STYLE_NORMAL = 0;
    /**
     * Light bright style of ccui.Widget.
     * @constant
     * @type {number}
     */
    static readonly BRIGHT_STYLE_HIGH_LIGHT = 1;

    //widget type
    /**
     * The type code of Widget for ccui controls.
     * @constant
     * @type {number}
     */
    static readonly TYPE_WIDGET = 0;
    /**
     * The type code of Container for ccui controls.
     * @constant
     * @type {number}
     */
    static readonly TYPE_CONTAINER = 1;

    //Focus Direction
    /**
     * The left of Focus direction for ccui.Widget
     * @constant
     * @type {number}
     */
    static readonly LEFT = 0;
    /**
     * The right of Focus direction for ccui.Widget
     * @constant
     * @type {number}
     */
    static readonly RIGHT = 1;
    /**
     * The up of Focus direction for ccui.Widget
     * @constant
     * @type {number}
     */
    static readonly UP = 2;
    /**
     * The down of Focus direction for ccui.Widget
     * @constant
     * @type {number}
     */
    static readonly DOWN = 3;

    //texture resource type
    /**
     * The image file texture type of ccui.Widget loads.
     * @constant
     * @type {number}
     */
    static readonly LOCAL_TEXTURE = 0;
    /**
     * The sprite frame texture type of ccui.Widget loads.
     * @constant
     * @type {number}
     */
    static readonly PLIST_TEXTURE = 1;

    //touch event type
    /**
     * The touch began type of ccui.Widget's touch event
     * @constant
     * @type {number}
     */
    static readonly TOUCH_BEGAN = 0;
    /**
     * The touch moved type of ccui.Widget's touch event
     * @constant
     * @type {number}
     */
    static readonly TOUCH_MOVED = 1;
    /**
     * The touch end type of ccui.Widget's touch event
     * @constant
     * @type {number}
     */
    static readonly TOUCH_ENDED = 2;
    /**
     * The touch canceled type of ccui.Widget's touch event
     * @constant
     * @type {number}
     */
    static readonly TOUCH_CANCELED = 3;

    //size type
    /**
     * The absolute of ccui.Widget's size type.
     * @constant
     * @type {number}
     */
    static readonly SIZE_ABSOLUTE = 0;
    /**
     * The percent of ccui.Widget's size type.
     * @constant
     * @type {number}
     */
    static readonly SIZE_PERCENT = 1;

    //position type
    /**
     * The absolute of ccui.Widget's position type.
     * @constant
     * @type {number}
     */
    static readonly POSITION_ABSOLUTE = 0;
    /**
     * The percent of ccui.Widget's position type.
     * @constant
     * @type {number}
     */
    static readonly POSITION_PERCENT = 1;
  }
}
