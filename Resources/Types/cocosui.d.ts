declare namespace ccui {
  // class Widget extends cc.ProtectedNode {
  //   // /**
  //   // * The base class for ccui controls and layout
  //   // * @sample
  //   // * var uiWidget = new ccui.Widget();
  //   // * this.addChild(uiWidget);
  //   // * @class
  //   // * @extends ccui.ProtectedNode
  //   // *
  //   // * @property {Number}           xPercent        - Position x in percentage of width
  //   // * @property {Number}           yPercent        - Position y in percentage of height
  //   // * @property {Number}           widthPercent    - Width in percentage of parent width
  //   // * @property {Number}           heightPercent   - Height in percentage of parent height
  //   // * @property {ccui.Widget}      widgetParent    - <@readonly> The direct parent when it's a widget also, otherwise equals null
  //   // * @property {Boolean}          enabled         - Indicate whether the widget is enabled
  //   // * @property {Boolean}          focused         - Indicate whether the widget is focused
  //   // * @property {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT}     sizeType        - The size type of the widget
  //   // * @property {ccui.Widget.TYPE_WIDGET|ccui.Widget.TYPE_CONTAINER}   widgetType      - <@readonly> The type of the widget
  //   // * @property {Boolean}          touchEnabled    - Indicate whether touch events are enabled
  //   // * @property {Boolean}          updateEnabled   - Indicate whether the update function is scheduled
  //   // * @property {Boolean}          bright          - Indicate whether the widget is bright
  //   // * @property {String}           name            - The name of the widget
  //   // * @property {Number}           actionTag       - The action tag of the widget
  //   // */
  //   // ccui.Widget = ccui.ProtectedNode.extend(/** @lends ccui.Widget# */{
  //   constructor();

  //     /**
  //      * The direct parent when it's a widget also, otherwise equals null
  //      * @returns {ccui.Widget|null}
  //      */
  //     getWidgetParent() : ccui.Widget | null;

  //     /**
  //      * Allow widget touch events to propagate to its parents. Set false will disable propagation
  //      * @since v3.2
  //      * @param {Boolean} isPropagate
  //      */
  //     setPropagateTouchEvents(isPropagate: boolean) : void;

  //     /**
  //      * Return whether the widget is propagate touch events to its parents or not
  //      * @since v3.2
  //      * @returns {boolean}
  //      */
  //     isPropagateTouchEvents() : boolean;

  //     /**
  //      * Specify widget to swallow touches or not
  //      * @since v3.2
  //      * @param {Boolean} swallow
  //      */
  //     setSwallowTouches(swallow: boolean) : void;

  //     /**
  //      * Return whether the widget is swallowing touch or not
  //      * @since v3.2
  //      * @returns {boolean}
  //      */
  //     isSwallowTouches() : boolean;

  //     /**
  //      * <p>
  //      *     Sets whether the widget is enabled                                                                                    <br/>
  //      *     true if the widget is enabled, widget may be touched , false if the widget is disabled, widget cannot be touched.     <br/>
  //      *     The default value is true, a widget is default to enabled
  //      * </p>
  //      * @param {Boolean} enabled
  //      */
  //     setEnabled(enabled: boolean) : void;

  //     /**
  //      * Changes the percent that is widget's percent size
  //      * @param {cc.Point} percent that is widget's percent size, width and height value from 0 to 1.
  //      */
  //     setSizePercent(percent : cc.Point): void;

  //   /**
  //    * updates its size by size type and its position by position type.
  //    * @param {cc.Size} [parentSize] parent size
  //    */
  //   updateSizeAndPosition(parentSize: cc.Size): void;

  //   /**TEXTURE_RES_TYPE
  //    * Changes the size type of widget.
  //    * @param {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT} type that is widget's size type
  //    */
  //   setSizeType(type: number): void;

  //     /**
  //      * Gets the size type of widget.
  //      * @returns {ccui.Widget.SIZE_ABSOLUTE|ccui.Widget.SIZE_PERCENT} that is widget's size type
  //      */
  //     getSizeType(): number;

  //     /**
  //      * Ignore the widget size
  //      * @param {Boolean} ignore true that widget will ignore it's size, use texture size, false otherwise. Default value is true.
  //      */
  //     ignoreContentAdaptWithSize(ignore: boolean): void;

  //     /**
  //      * Gets whether ignore the content size (custom size)
  //      * @returns {boolean}  true that widget will ignore it's size, use texture size, false otherwise.
  //      */
  //     isIgnoreContentAdaptWithSize() : boolean;

  //     /**
  //      * Get custom size of ccui.Widget
  //      * @returns {cc.Size}
  //      */
  //     getCustomSize(): cc.Size;

  //     /**
  //      * Gets layout size of ccui.Widget.
  //      * @returns {cc.Size}
  //      */
  //     getLayoutSize(): cc.Size;

  //     /**
  //      * Returns size percent of ccui.Widget
  //      * @returns {cc.Point}
  //      */
  //     getSizePercent(): cc.Point;

  //     /**
  //      *  Gets world position of ccui.Widget.
  //      * @returns {cc.Point} world position of ccui.Widget.
  //      */
  //     getWorldPosition() : cc.Point;

  //     /**
  //      * Gets the Virtual Renderer of widget.
  //      * @returns {ccui.Widget}
  //      */
  //     getVirtualRenderer() : ccui.Widget;

  //     /**
  //      * Gets the content size of widget.  Content size is widget's texture size.
  //      */
  //     getVirtualRendererSize() : cc.Size;

  //     /**
  //      * Sets whether the widget is touch enabled. The default value is false, a widget is default to touch disabled
  //      * @param {Boolean} enable  true if the widget is touch enabled, false if the widget is touch disabled.
  //      */
  //     setTouchEnabled(enable: boolean): void;

  //     /**
  //      * Returns whether or not touch is enabled.
  //      * @returns {boolean} true if the widget is touch enabled, false if the widget is touch disabled.
  //      */
  //     isTouchEnabled(): boolean;

  //     /**
  //      * Determines if the widget is highlighted
  //      * @returns {boolean} true if the widget is highlighted, false if the widget is not highlighted .
  //      */
  //     isHighlighted(): boolean;

  //     /**
  //      * Sets whether the widget is highlighted. The default value is false, a widget is default to not highlighted
  //      * @param highlight true if the widget is highlighted, false if the widget is not highlighted.
  //      */
  //     setHighlighted(highlight: boolean): void;

  //     /**
  //      * Determines if the widget is on focused
  //      * @returns {boolean} whether the widget is focused or not
  //      */
  //     isFocused() : boolean;

  //     /**
  //      * Sets whether the widget is on focused
  //      * The default value is false, a widget is default to not on focused
  //      * @param {boolean} focus  pass true to let the widget get focus or pass false to let the widget lose focus
  //      */
  //     setFocused(focus: boolean): void;

  //     /**
  //      * returns whether the widget could accept focus.
  //      * @returns {boolean} true represent the widget could accept focus, false represent the widget couldn't accept focus
  //      */
  //     isFocusEnabled(): boolean;

  //     /**
  //      * sets whether the widget could accept focus.
  //      * @param {Boolean} enable true represent the widget could accept focus, false represent the widget couldn't accept focus
  //      */
  //     setFocusEnabled(enable: boolean): void;

  //     /**
  //      * <p>
  //      *     When a widget is in a layout, you could call this method to get the next focused widget within a specified direction. <br/>
  //      *     If the widget is not in a layout, it will return itself
  //      * </p>
  //      * @param direction the direction to look for the next focused widget in a layout
  //      * @param current  the current focused widget
  //      * @return  the next focused widget in a layout
  //      */
  //     findNextFocusedWidget(direction: number, current: ccui.Widget): ccui.Widget;

  //     /**
  //      * when a widget calls this method, it will get focus immediately.
  //      */
  //     requestFocus(): void;

  //     /**
  //      * no matter what widget object you call this method on , it will return you the exact one focused widget
  //      */
  //     getCurrentFocusedWidget(): ccui.Widget;

  //     /**
  //      * <p>
  //      *    When a widget lose/get focus, this method will be called. Be Caution when you provide your own version,       <br/>
  //      *    you must call widget.setFocused(true/false) to change the focus state of the current focused widget;
  //      * </p>
  //      */
  //     onFocusChanged: (widgetLostFocus: ccui.Widget, widgetGetFocus: ccui.Widget) => void;

  //     /**
  //      * use this function to manually specify the next focused widget regards to each direction
  //      */
  //     onNextFocusedWidget: (direction: number) => ccui.Widget;

  //     /**
  //      * Sends the touch event to widget's parent, its subclass will override it, e.g. ccui.ScrollView, ccui.PageView
  //      * @param {Number}  eventType
  //      * @param {ccui.Widget} sender
  //      * @param {cc.Touch} touch
  //      */
  //     interceptTouchEvent(eventType: number, sender: ccui.Widget, touch: cc.Touch): void;

  //     /**
  //      * This method is called when a focus change event happens
  //      * @param {ccui.Widget} widgetLostFocus
  //      * @param {ccui.Widget} widgetGetFocus
  //      */
  //     onFocusChange(widgetLostFocus: ccui.Widget, widgetGetFocus: ccui.Widget): void;

  //     /**
  //      * Dispatch a EventFocus through a EventDispatcher
  //      * @param {ccui.Widget} widgetLostFocus
  //      * @param {ccui.Widget} widgetGetFocus
  //      */
  //     dispatchFocusEvent(widgetLostFocus: ccui.Widget, widgetGetFocus: ccui.Widget): void;

  //     /**
  //      *  Sets whether the widget is bright. The default value is true, a widget is default to bright
  //      * @param {Boolean} bright true if the widget is bright, false if the widget is dark.
  //      */
  //     setBright(bright: boolean): void;

  //     /**
  //      * To set the bright style of ccui.Widget.
  //      * @param {Number} style BRIGHT_NORMAL the widget is normal state, BRIGHT_HIGHLIGHT the widget is height light state.
  //      */
  //     setBrightStyle(style:  number): void;

  //     /**
  //      * A call back function when widget lost of focus.
  //      */
  //     didNotSelectSelf(): void;

  //     /**
  //      * <p>
  //      *    The callback of touch began event.                                                               <br/>
  //      *    If the bounding box of ccui.Widget contains the touch point, it will do the following things:    <br/>
  //      *      1. sets highlight state,                                                                       <br/>
  //      *      2. sends event to parent widget by interceptTouchEvent                                         <br/>
  //      *      3. calls the callback of touch began event.                                                    <br/>
  //      *      4. returns true,                                                                               <br/>
  //      *    otherwise returns false directly.                                                                <br/>
  //      * </p>
  //      * @override
  //      * @param {cc.Touch} touch
  //      * @param {cc.Event} event
  //      * @returns {boolean}
  //      */
  //     onTouchBegan(touch: cc.Touch, event: cc.Event): boolean;

  //     propagateTouchEvent (event: cc.Event, sender: any, touch: cc.Touch): void;

  //     /**
  //      * <p>
  //      *    The callback of touch moved event.                                                                                                <br/>
  //      *    It sets the highlight state by touch, sends event to parent widget by interceptTouchEvent and calls the callback of touch moved event.
  //      * </p>
  //      * @param {cc.Touch} touch
  //      * @param {cc.Event} event
  //      */
  //     onTouchMoved(touch: cc.Touch, event: cc.Event): boolean;

  //     /**
  //      * <p>
  //      *      The callback of touch end event
  //      *      It sends event to parent widget by interceptTouchEvent,
  //      *      calls the callback of touch end event (highlight= true) or touch canceled event (highlight= false).
  //      *      sets the highlight state to false ,
  //      * </p>
  //      * @param touch
  //      * @param event
  //      */
  //     onTouchEnded(touch: cc.Touch, event: cc.Event): boolean;

  //     /**
  //      * A call back function called when widget is selected, and on touch canceled.
  //      * @param {cc.Point} touchPoint
  //      */
  //     onTouchCancelled(touchPoint: cc.Point): void

  //     /**
  //      * A call back function called when widget is selected, and on touch long clicked.
  //      * @param {cc.Point} touchPoint
  //      */
  //     onTouchLongClicked(touchPoint: cc.Point): void;

  //   //   longClickEvent: function () {
  //   //       //TODO it will implement in v3.1
  //   //   },

  //     /**
  //      * Sets the touch event target/selector of the ccui.Widget
  //      * @param {Function} selector
  //      * @param {Object} target
  //      */
  //     addTouchEventListener(selector: Function, target: cc.Node): void;

  //     addClickEventListener(callback: Function): void;

  //     /**
  //      * Checks a point if is in widget's space
  //      * @param {cc.Point} pt
  //      * @returns {boolean} true if the point is in widget's space, false otherwise.
  //      */
  //     hitTest(pt: cc.Point) : boolean;

  //   //   /**
  //   //    * returns whether clipping parent widget contains point.
  //   //    * @param {cc.Point} pt location point
  //   //    * @returns {Boolean}
  //   //    */
  //   //   isClippingParentContainsPoint: function (pt) {
  //   //       this._affectByClipping = false;
  //   //       var parent = this.getParent();
  //   //       var clippingParent = null;
  //   //       while (parent) {
  //   //           if (parent instanceof ccui.Layout) {
  //   //               if (parent.isClippingEnabled()) {
  //   //                   this._affectByClipping = true;
  //   //                   clippingParent = parent;
  //   //                   break;
  //   //               }
  //   //           }
  //   //           parent = parent.getParent();
  //   //       }

  //   //       if (!this._affectByClipping)
  //   //           return true;

  //   //       if (clippingParent) {
  //   //           if (clippingParent.hitTest(pt))
  //   //               return clippingParent.isClippingParentContainsPoint(pt);
  //   //           return false;
  //   //       }
  //   //       return true;
  //   //   },

  //   //   /**
  //   //    * Calls the checkChildInfo of widget's parent, its subclass will override it.
  //   //    * @param {number} handleState
  //   //    * @param {ccui.Widget} sender
  //   //    * @param {cc.Point} touchPoint
  //   //    */
  //   //   checkChildInfo: function (handleState, sender, touchPoint) {
  //   //       var widgetParent = this.getWidgetParent();
  //   //       if (widgetParent)
  //   //           widgetParent.checkChildInfo(handleState, sender, touchPoint);
  //   //   },

  //     /**
  //      * Changes the position (x,y) of the widget
  //      * @param {cc.Point} percent
  //      */
  //     setPositionPercent(percent: cc.Point) : void;

  //     /**
  //      * Gets the percent (x,y) of the widget
  //      * @returns {cc.Point} The percent (x,y) of the widget in OpenGL coordinates
  //      */
  //     getPositionPercent(): cc.Point;

  //     /**
  //      * Changes the position type of the widget
  //      * @param {Number} type  the position type of widget
  //      */
  //     setPositionType(type: number) : void;

  //     /**
  //      * Gets the position type of the widget
  //      * @returns {Number} the position type of widget
  //      */
  //     getPositionType(): number;

  //     /**
  //      * Sets whether the widget should be flipped horizontally or not.
  //      * @param {Boolean} flipX true if the widget should be flipped horizontally, false otherwise.
  //      */
  //     setFlippedX(flipX : boolean): void;

  //     /**
  //      * <p>
  //      *   Returns the flag which indicates whether the widget is flipped horizontally or not.             <br/>
  //      *   It only flips the texture of the widget, and not the texture of the widget's children.          <br/>
  //      *   Also, flipping the texture doesn't alter the anchorPoint.                                       <br/>
  //      *   If you want to flip the anchorPoint too, and/or to flip the children too use:                   <br/>
  //      *   widget.setScaleX(sprite.getScaleX() * -1);
  //      * </p>
  //      * @returns {Boolean} true if the widget is flipped horizontally, false otherwise.
  //      */
  //     isFlippedX(): boolean;

  //     /**
  //      * Sets whether the widget should be flipped vertically or not.
  //      * @param {Boolean} flipY  true if the widget should be flipped vertically, false otherwise.
  //      */
  //     setFlippedY(flipY: boolean): void;

  //     /**
  //      * <p>
  //      *     Return the flag which indicates whether the widget is flipped vertically or not.                <br/>
  //      *     It only flips the texture of the widget, and not the texture of the widget's children.          <br/>
  //      *     Also, flipping the texture doesn't alter the anchorPoint.                                       <br/>
  //      *     If you want to flip the anchorPoint too, and/or to flip the children too use:                   <br/>
  //      *     widget.setScaleY(widget.getScaleY() * -1);
  //      * </p>
  //      * @returns {Boolean} true if the widget is flipped vertically, false otherwise.
  //      */
  //     isFlippedY(): boolean;

  //     /**
  //      * Determines if the widget is bright
  //      * @returns {boolean} true if the widget is bright, false if the widget is dark.
  //      */
  //     isBright(): boolean;

  //     /**
  //      * Determines if the widget is enabled
  //      * @returns {boolean}
  //      */
  //     isEnabled(): boolean;

  //     /**
  //      * Gets the left boundary position of this widget.
  //      * @returns {number}
  //      */
  //     getLeftBoundary(): number;

  //     /**
  //      * Gets the bottom boundary position of this widget.
  //      * @returns {number}
  //      */
  //     getBottomBoundary(): number;

  //     /**
  //      * Gets the right boundary position of this widget.
  //      * @returns {number}
  //      */
  //     getRightBoundary(): number;

  //     /**
  //      * Gets the top boundary position of this widget.
  //      * @returns {number}
  //      */
  //     getTopBoundary(): number;

  //     /**
  //      * Gets the position of touch began event.
  //      * @returns {cc.Point}
  //      */
  //     getTouchBeganPosition(): cc.Point;

  //     /**
  //      * Gets the position of touch moved event
  //      * @returns {cc.Point}
  //      */
  //     getTouchMovePosition(): cc.Point;

  //     /**
  //      * Gets the position of touch end event
  //      * @returns {cc.Point}
  //      */
  //     getTouchEndPosition(): cc.Point;

  //     /**
  //      * get widget type
  //      * @returns {ccui.Widget.TYPE_WIDGET|ccui.Widget.TYPE_CONTAINER}
  //      */
  //     getWidgetType(): number;

  //   //   /**
  //   //    * Gets LayoutParameter of widget.
  //   //    * @param {ccui.LayoutParameter} parameter
  //   //    */
  //   //   setLayoutParameter: function (parameter) {
  //   //       if (!parameter)
  //   //           return;
  //   //       this._layoutParameterDictionary[parameter.getLayoutType()] = parameter;
  //   //       this._layoutParameterType = parameter.getLayoutType();
  //   //   },

  //   //   /**
  //   //    * Gets layout parameter
  //   //    * @param {ccui.LayoutParameter.NONE|ccui.LayoutParameter.LINEAR|ccui.LayoutParameter.RELATIVE} type
  //   //    * @returns {ccui.LayoutParameter}
  //   //    */
  //   //   getLayoutParameter: function (type) {
  //   //       type = type || this._layoutParameterType;
  //   //       return this._layoutParameterDictionary[type];
  //   //   },

  //   //   /**
  //   //    * Returns the "class name" of widget.
  //   //    * @returns {string}
  //   //    */
  //   //   getDescription: function () {
  //   //       return "Widget";
  //   //   },

  //   //   /**
  //   //    * Clones a new widget.
  //   //    * @returns {ccui.Widget}
  //   //    */
  //   //   clone: function () {
  //   //       var clonedWidget = this._createCloneInstance();
  //   //       clonedWidget._copyProperties(this);
  //   //       clonedWidget._copyClonedWidgetChildren(this);
  //   //       return clonedWidget;
  //   //   },

  //   //   _createCloneInstance: function () {
  //   //       return new ccui.Widget();
  //   //   },

  //   //   _copyClonedWidgetChildren: function (model) {
  //   //       var widgetChildren = model.getChildren();
  //   //       for (var i = 0; i < widgetChildren.length; i++) {
  //   //           var locChild = widgetChildren[i];
  //   //           if (locChild instanceof ccui.Widget)
  //   //               this.addChild(locChild.clone());
  //   //       }
  //   //   },

  //   //   /*temp action*/
  //   //   setActionTag: function (tag) {
  //   //       this._actionTag = tag;
  //   //   },

  //   //   getActionTag: function () {
  //   //       return this._actionTag;
  //   //   },

  //   //   /**
  //   //    * Gets the left boundary position of this widget.
  //   //    * @deprecated since v3.0, please use getLeftBoundary instead.
  //   //    * @returns {number}
  //   //    */
  //   //   getLeftInParent: function () {
  //   //       cc.log("getLeftInParent is deprecated. Please use getLeftBoundary instead.");
  //   //       return this.getLeftBoundary();
  //   //   },

  //   //   /**
  //   //    * Gets the bottom boundary position of this widget.
  //   //    * @deprecated since v3.0, please use getBottomBoundary instead.
  //   //    * @returns {number}
  //   //    */
  //   //   getBottomInParent: function () {
  //   //       cc.log("getBottomInParent is deprecated. Please use getBottomBoundary instead.");
  //   //       return this.getBottomBoundary();
  //   //   },

  //   //   /**
  //   //    * Gets the right boundary position of this widget.
  //   //    * @deprecated since v3.0, please use getRightBoundary instead.
  //   //    * @returns {number}
  //   //    */
  //   //   getRightInParent: function () {
  //   //       cc.log("getRightInParent is deprecated. Please use getRightBoundary instead.");
  //   //       return this.getRightBoundary();
  //   //   },

  //   //   /**
  //   //    * Gets the top boundary position of this widget.
  //   //    * @deprecated since v3.0, please use getTopBoundary instead.
  //   //    * @returns {number}
  //   //    */
  //   //   getTopInParent: function () {
  //   //       cc.log("getTopInParent is deprecated. Please use getTopBoundary instead.");
  //   //       return this.getTopBoundary();
  //   //   },

  //   //   /**
  //   //    * Gets the touch end point of widget when widget is selected.
  //   //    * @deprecated since v3.0, please use getTouchEndPosition instead.
  //   //    * @returns {cc.Point} the touch end point.
  //   //    */
  //   //   getTouchEndPos: function () {
  //   //       cc.log("getTouchEndPos is deprecated. Please use getTouchEndPosition instead.");
  //   //       return this.getTouchEndPosition();
  //   //   },

  //   //   /**
  //   //    *Gets the touch move point of widget when widget is selected.
  //   //   * @deprecated since v3.0, please use getTouchMovePosition instead.
  //   //   * @returns {cc.Point} the touch move point.
  //   //   */
  //   //   getTouchMovePos: function () {
  //   //       cc.log("getTouchMovePos is deprecated. Please use getTouchMovePosition instead.");
  //   //       return this.getTouchMovePosition();
  //   //   },

  //   //   /**
  //   //    * Checks a point if in parent's area.
  //   //    * @deprecated since v3.0, please use isClippingParentContainsPoint instead.
  //   //    * @param {cc.Point} pt
  //   //    * @returns {Boolean}
  //   //    */
  //   //   clippingParentAreaContainPoint: function (pt) {
  //   //       cc.log("clippingParentAreaContainPoint is deprecated. Please use isClippingParentContainsPoint instead.");
  //   //       this.isClippingParentContainsPoint(pt);
  //   //   },

  //   //   /**
  //   //    * Gets the touch began point of widget when widget is selected.
  //   //    * @deprecated since v3.0, please use getTouchBeganPosition instead.
  //   //    * @returns {cc.Point} the touch began point.
  //   //    */
  //   //   getTouchStartPos: function () {
  //   //       cc.log("getTouchStartPos is deprecated. Please use getTouchBeganPosition instead.");
  //   //       return this.getTouchBeganPosition();
  //   //   },

  //   //   /**
  //   //    * Changes the size that is widget's size
  //   //    * @deprecated since v3.0, please use setContentSize instead.
  //   //    * @param {cc.Size} size  that is widget's size
  //   //    */
  //   //   setSize: function (size) {
  //   //       this.setContentSize(size);
  //   //   },

  //   //   /**
  //   //    * Returns size of widget
  //   //    * @deprecated since v3.0, please use getContentSize instead.
  //   //    * @returns {cc.Size}
  //   //    */
  //   //   getSize: function () {
  //   //       return this.getContentSize();
  //   //   },

  //   //   /**
  //   //    * Adds a node for widget (this function is deleted in -x)
  //   //    * @param {cc.Node} node
  //   //    * @param {Number} zOrder
  //   //    * @param {Number} tag
  //   //    * @deprecated since v3.0, please use addChild instead.
  //   //    */
  //   //   addNode: function (node, zOrder, tag) {
  //   //       if (node instanceof ccui.Widget) {
  //   //           cc.log("Please use addChild to add a Widget.");
  //   //           return;
  //   //       }
  //   //       cc.Node.prototype.addChild.call(this, node, zOrder, tag);
  //   //       this._nodes.push(node);
  //   //   },

  //   //   /**
  //   //    * Gets node by tag
  //   //    * @deprecated since v3.0, please use getChildByTag instead.
  //   //    * @param {Number} tag
  //   //    * @returns {cc.Node}
  //   //    */
  //   //   getNodeByTag: function (tag) {
  //   //       var _nodes = this._nodes;
  //   //       for (var i = 0; i < _nodes.length; i++) {
  //   //           var node = _nodes[i];
  //   //           if (node && node.getTag() === tag) {
  //   //               return node;
  //   //           }
  //   //       }
  //   //       return null;
  //   //   },

  //   //   /**
  //   //    * Returns all children.
  //   //    * @deprecated since v3.0, please use getChildren instead.
  //   //    * @returns {Array}
  //   //    */
  //   //   getNodes: function () {
  //   //       return this._nodes;
  //   //   },

  //   //   /**
  //   //    * Removes a node from ccui.Widget
  //   //    * @deprecated since v3.0, please use removeChild instead.
  //   //    * @param {cc.Node} node
  //   //    * @param {Boolean} cleanup
  //   //    */
  //   //   removeNode: function (node, cleanup) {
  //   //       cc.Node.prototype.removeChild.call(this, node, cleanup);
  //   //       cc.arrayRemoveObject(this._nodes, node);
  //   //   },

  //   //   /**
  //   //    * Removes node by tag
  //   //    * @deprecated since v3.0, please use removeChildByTag instead.
  //   //    * @param {Number} tag
  //   //    * @param {Boolean} [cleanup]
  //   //    */
  //   //   removeNodeByTag: function (tag, cleanup) {
  //   //       var node = this.getChildByTag(tag);
  //   //       if (!node)
  //   //           cc.log("cocos2d: removeNodeByTag(tag = %d): child not found!", tag);
  //   //       else
  //   //           this.removeChild(node, cleanup);
  //   //   },

  //   //   /**
  //   //    * Removes all node
  //   //    * @deprecated since v3.0, please use removeAllChildren instead.
  //   //    */
  //   //   removeAllNodes: function () {
  //   //       for (var i = 0; i < this._nodes.length; i++) {
  //   //           var node = this._nodes[i];
  //   //           cc.Node.prototype.removeChild.call(this, node);
  //   //       }
  //   //       this._nodes.length = 0;
  //   //   },

  //   //   /**
  //   //    * @since v3.2
  //   //    * @returns {boolean} true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
  //   //    */
  //   //   isUnifySizeEnabled: function(){
  //   //       return this._unifySize;
  //   //   },

  //   //   /**
  //   //    * @since v3.2
  //   //    * @param {Boolean} enable enable Unify Size of a widget
  //   //    */
  //   //   setUnifySizeEnabled: function(enable){
  //   //       this._unifySize = enable;
  //   //   },

  //   //   /**
  //   //    * Set a event handler to the widget in order to use cocostudio editor and framework
  //   //    * @since v3.3
  //   //    * @param {function} callback
  //   //    */
  //   //   addCCSEventListener: function (callback) {
  //   //       this._ccEventCallback = callback;
  //   //   },

  //   //   //override the scale functions.
  //   //   setScaleX: function (scaleX) {
  //   //       if (this._flippedX)
  //   //           scaleX = scaleX * -1;
  //   //       cc.Node.prototype.setScaleX.call(this, scaleX);
  //   //   },
  //   //   setScaleY: function (scaleY) {
  //   //       if (this._flippedY)
  //   //           scaleY = scaleY * -1;
  //   //       cc.Node.prototype.setScaleY.call(this, scaleY);
  //   //   },
  //   //   setScale: function (scaleX, scaleY) {
  //   //       if (scaleY === undefined)
  //   //           scaleY = scaleX;
  //   //       this.setScaleX(scaleX);
  //   //       this.setScaleY(scaleY);
  //   //   },

  //   //   getScaleX: function () {
  //   //       var originalScale = cc.Node.prototype.getScaleX.call(this);
  //   //       if (this._flippedX)
  //   //           originalScale = originalScale * -1.0;
  //   //       return originalScale;
  //   //   },
  //   //   getScaleY: function () {
  //   //       var originalScale = cc.Node.prototype.getScaleY.call(this);
  //   //       if (this._flippedY)
  //   //           originalScale = originalScale * -1.0;
  //   //       return originalScale;
  //   //   },
  //   //   getScale: function () {
  //   //       if (this.getScaleX() !== this.getScaleY())
  //   //           cc.log("Widget#scale. ScaleX != ScaleY. Don't know which one to return");
  //   //       return this.getScaleX();
  //   //   },

  //   //   /**
  //   //    * Sets callback name to widget.
  //   //    * @since v3.3
  //   //    * @param {String} callbackName
  //   //    */
  //   //   setCallbackName: function (callbackName) {
  //   //       this._callbackName = callbackName;
  //   //   },

  //   //   /**
  //   //    * Gets callback name of widget
  //   //    * @since v3.3
  //   //    * @returns {String|Null}
  //   //    */
  //   //   getCallbackName: function () {
  //   //       return this._callbackName;
  //   //   },

  //     /**
  //      * Sets callback type to widget
  //      * @since v3.3
  //      * @param {String} callbackType
  //      */
  //     setCallbackType(callbackType: string): void;

  //     /**
  //      * Gets callback type of widget
  //      * @since v3.3
  //      * @returns {String|null}
  //      */
  //     getCallbackType():  string | null;

  //     /**
  //      * Whether enable layout component of a widget
  //      * @since v3.3
  //      * @param {Boolean} enable enable layout Component of a widget
  //      */
  //     setLayoutComponentEnabled(enable: boolean): void;

  //     /**
  //      * Returns whether enable layout component of a widget
  //      * @return {Boolean} true represent the widget use Layout Component, false represent the widget couldn't use Layout Component.
  //      */
  //     isLayoutComponentEnabled(): boolean;

  //   get xPercent(): number;
  //   set xPercent(value: number);
  //   get yPercent(): number;
  //   set yPercent(value: number);
  //   get widthPercent(): number;
  //   set widthPercent(value: number);
  //   get heightPercent(): number;
  //   set heightPercent(value: number);
  //   get widgetParent(): ccui.Widget | null;
  //   set widgetParent(value: ccui.Widget);
  //   get enabled(): boolean;
  //   set enabled(value: boolean);
  //   get focused(): boolean;
  //   set focused(value: boolean);
  //   get sizeType(): number;
  //   set sizeType(value: number);
  //   get widgetType(): number;
  //   set widgetType(value: number);
  //   get touchEnabled(): boolean;
  //   set touchEnabled(value: boolean);
  //   get updateEnabled(): boolean;
  //   set updateEnabled(value: boolean);
  //   get bright(): boolean;
  //   set bright(value: boolean);
  //   get name(): string;
  //   set name(value: string);
  //   get actionTag(): number;
  //   set actionTag(value: number);
  //   get opacity(): number;
  //   set opacity(value: number);

  //   // /**
  //   // * allocates and initializes a UIWidget.
  //   // * @deprecated
  //   // * @return {ccui.Widget}
  //   // */
  //   static create(): ccui.Widget;

  //   /**
  //   * call this method with parameter true to enable the Android Dpad focus navigation feature
  //   * @note it doesn't implemented on Web
  //   * @param {Boolean} enable set true to enable dpad focus navigation, otherwise disable dpad focus navigation
  //   */
  //   static enableDpadNavigation(enable: boolean): void;

  //   /**
  //   * Gets the focused widget of current stage.
  //   * @function
  //   * @returns {null|ccui.Widget}
  //   */
  //   static getCurrentFocusedWidget(): ccui.Widget | null;

  //   // Constants
  //   //bright style
  //   /**
  //   * None bright style of ccui.Widget.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly BRIGHT_STYLE_NONE = -1;
  //   /**
  //   * Normal bright style of ccui.Widget.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly BRIGHT_STYLE_NORMAL = 0;
  //   /**
  //   * Light bright style of ccui.Widget.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly BRIGHT_STYLE_HIGH_LIGHT = 1;

  //   //widget type
  //   /**
  //   * The type code of Widget for ccui controls.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly TYPE_WIDGET = 0;
  //   /**
  //   * The type code of Container for ccui controls.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly TYPE_CONTAINER = 1;

  //   //Focus Direction
  //   /**
  //   * The left of Focus direction for ccui.Widget
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly LEFT = 0;
  //   /**
  //   * The right of Focus direction for ccui.Widget
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly RIGHT = 1;
  //   /**
  //   * The up of Focus direction for ccui.Widget
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly UP = 2;
  //   /**
  //   * The down of Focus direction for ccui.Widget
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly DOWN = 3;

  //   //texture resource type
  //   /**
  //   * The image file texture type of ccui.Widget loads.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly LOCAL_TEXTURE = 0;
  //   /**
  //   * The sprite frame texture type of ccui.Widget loads.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly PLIST_TEXTURE = 1;

  //   //touch event type
  //   /**
  //   * The touch began type of ccui.Widget's touch event
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly TOUCH_BEGAN = 0;
  //   /**
  //   * The touch moved type of ccui.Widget's touch event
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly TOUCH_MOVED = 1;
  //   /**
  //   * The touch end type of ccui.Widget's touch event
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly TOUCH_ENDED = 2;
  //   /**
  //   * The touch canceled type of ccui.Widget's touch event
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly OUCH_CANCELED = 3;

  //   //size type
  //   /**
  //   * The absolute of ccui.Widget's size type.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly SIZE_ABSOLUTE = 0;
  //   /**
  //   * The percent of ccui.Widget's size type.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly SIZE_PERCENT = 1;

  //   //position type
  //   /**
  //   * The absolute of ccui.Widget's position type.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly POSITION_ABSOLUTE = 0;
  //   /**
  //   * The percent of ccui.Widget's position type.
  //   * @constant
  //   * @type {number}
  //   */
  //   static readonly POSITION_PERCENT = 1;

  // }

  /**
   * The button controls of Cocos UI.
   * @class
   * @extends ccui.Widget
   *
   * @property {String}   titleText               - The content string of the button title
   * @property {String}   titleFont               - The content string font of the button title
   * @property {Number}   titleFontSize           - The content string font size of the button title
   * @property {String}   titleFontName           - The content string font name of the button title
   * @property {cc.Color} titleColor          - The content string font color of the button title
   * @property {Boolean}  pressedActionEnabled    - Indicate whether button has zoom effect when clicked
   */
  class Button extends Widget {
    /**
     * Allocates and initializes a UIButton.
     * Constructor of ccui.Button. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @param {String} normalImage
     * @param {String} [selectedImage=""]
     * @param {String} [disableImage=""]
     * @param {Number} [texType=ccui.Widget.LOCAL_TEXTURE]
     * @example
     * // example
     * var uiButton = new ccui.Button();
     */
    constructor(
      normalImage?: string,
      selectedImage?: string,
      disableImage?: string,
      texType?: number,
    );

    /**
     * Sets if button is using scale9 renderer.
     * @param {Boolean} able true that using scale9 renderer, false otherwise.
     */
    setScale9Enabled(able: boolean): void;

    /**
     *  Returns button is using scale9 renderer or not.
     * @returns {Boolean}
     */
    isScale9Enabled(): boolean;

    /**
     * Sets whether ignore the widget size
     * @param {Boolean} ignore true that widget will ignore it's size, use texture size, false otherwise. Default value is true.
     * @override
     */
    ignoreContentAdaptWithSize(ignore: boolean): void;

    /**
     * Returns the renderer size.
     * @returns {cc.Size}
     */
    getVirtualRendererSize(): cc.Size;

    /**
     * Load textures for button.
     * @param {String} normal normal state of texture's filename.
     * @param {String} selected  selected state of texture's filename.
     * @param {String} disabled  disabled state of texture's filename.
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTextures(
      normal: string,
      selected: string,
      disabled: string,
      texType: number,
    ): void;

    /**
     * Load normal state texture for button.
     * @param {String} normal normal state of texture's filename.
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTextureNormal(normal: string, texType: number): void;

    /**
     * Load selected state texture for button.
     * @param {String} selected selected state of texture's filename.
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTexturePressed(selected: string, texType: number): void;

    /**
     * Load dark state texture for button.
     * @param {String} disabled disabled state of texture's filename.
     * @param {ccui.Widget.LOCAL_TEXTURE|ccui.Widget.PLIST_TEXTURE} texType
     */
    loadTextureDisabled(disabled: string, texType: number): void;

    /**
     * Sets capinsets for button, if button is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsets(capInsets: cc.Rect): void;

    /**
     * Sets capinsets for button, if button is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsetsNormalRenderer(capInsets: cc.Rect): void;

    /**
     *  Returns normal renderer cap insets.
     * @returns {cc.Rect}
     */
    getCapInsetsNormalRenderer(): cc.Rect;

    /**
     * Sets capinsets for button, if button is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsetsPressedRenderer(capInsets: cc.Rect): void;

    /**
     *  Returns pressed renderer cap insets.
     * @returns {cc.Rect}
     */
    getCapInsetsPressedRenderer(): cc.Rect;

    /**
     * Sets capinsets for button, if button is using scale9 renderer.
     * @param {cc.Rect} capInsets
     */
    setCapInsetsDisabledRenderer(capInsets: cc.Rect): void;

    /**
     * Returns disable renderer cap insets.
     * @returns {cc.Rect}
     */
    getCapInsetsDisabledRenderer(): cc.Rect;

    /**
     * Changes if button can be clicked zoom effect.
     * @param {Boolean} enabled
     */
    setPressedActionEnabled(enabled: boolean): void;

    /**
     * Sets title text to ccui.Button
     * @param {String} text
     */
    setTitleText(text: string): void;

    /**
     * Returns title text of ccui.Button
     * @returns {String} text
     */
    getTitleText(): string;

    /**
     * Sets title color to ccui.Button.
     * @param {cc.Color} color
     */
    setTitleColor(color: cc.Color): void;

    /**
     * Returns title color of ccui.Button
     * @returns {cc.Color}
     */
    getTitleColor(): cc.Color;

    /**
     * Sets title fontSize to ccui.Button
     * @param {cc.Size} size
     */
    setTitleFontSize(size: cc.Size | number): void;

    /**
     * Returns title fontSize of ccui.Button.
     * @returns {Number}
     */
    getTitleFontSize(): number;

    /**
     * When user pressed the button, the button will zoom to a scale.
     * The final scale of the button  equals (button original scale + _zoomScale)
     * @since v3.2
     * @param scale
     */
    setZoomScale(scale: number): void;

    /**
     * Returns a zoom scale
     * @since v3.2
     * @returns {number}
     */
    getZoomScale(): number;

    /**
     * Returns the normalize of texture size
     * @since v3.3
     * @returns {cc.Size}
     */
    getNormalTextureSize(): cc.Size;

    /**
     * Sets title fontName to ccui.Button.
     * @param {String} fontName
     */
    setTitleFontName(fontName: string): void;

    /**
     * Get the title renderer.
     * title ttf object.
     * @returns {cc.LabelTTF}
     */
    getTitleRenderer(): cc.LabelTTF;

    /**
     * Gets title fontName of ccui.Button.
     * @returns {String}
     */
    getTitleFontName(): string;

    /**
     * Returns the "class name" of widget.
     * @override
     * @returns {string}
     */
    getDescription(): string;

    setFillType(type: number): void;

    get titleText(): string;
    set titleText(value: string);
    get titleFont(): string;
    set titleFont(value: any);
    get titleFontSize(): number;
    set titleFontSize(value: number);
    get titleFontName(): string;
    set titleFontName(value: string);
    get titleColor(): cc.Color;
    set titleColor(value: cc.Color);

    // Constants
    /**
     * The normal renderer's zOrder value of ccui.Button.
     * @constant
     * @type {number}
     */
    static readonly NORMAL_RENDERER_ZORDER = -2;
    /**
     * The pressed renderer's zOrder value ccui.Button.
     * @constant
     * @type {number}
     */
    static readonly PRESSED_RENDERER_ZORDER = -2;
    /**
     * The disabled renderer's zOrder value of ccui.Button.
     * @constant
     * @type {number}
     */
    static readonly DISABLED_RENDERER_ZORDER = -2;
    /**
     * The title renderer's zOrder value of ccui.Button.
     * @constant
     * @type {number}
     */
    static readonly TITLE_RENDERER_ZORDER = -1;

    /**
     * the zoom action time step of ccui.Button
     * @constant
     * @type {number}
     */
    static readonly ZOOM_ACTION_TIME_STEP = 0.05;

    /**
     * @ignore
     */
    static readonly SYSTEM = 0;
    static readonly TTF = 1;
  }

  class Scale9Sprite extends cc.Node {
    constructor(
      file?: string | cc.SpriteFrame,
      rect?: cc.Rect,
      capInsets?: cc.Rect,
    );
    public setCapInsets(CapInsets: cc.Rect): void;
    public setPreferredSize(size: cc.Size): void;
    public setSpriteFrame(frame: cc.SpriteFrame): void;
    // TODO
    public setBlendFunc(src: number | any, dest?: number): void;
    setState(state: number): void;
    static state: { NORMAL: 0; GRAY: 1 };
    getSpriteFrame(): cc.SpriteFrame;

    static readonly POSITIONS_CENTRE = 0;
    static readonly POSITIONS_TOP = 1;
    static readonly POSITIONS_LEFT = 2;
    static readonly POSITIONS_RIGHT = 3;
    static readonly POSITIONS_BOTTOM = 4;
    static readonly POSITIONS_TOPRIGHT = 5;
    static readonly POSITIONS_TOPLEFT = 6;
    static readonly POSITIONS_BOTTOMRIGHT = 7;

    static readonly RenderingType: {
      /**
       * @property {Number} SIMPLE
       */
      SIMPLE: 0;
      /**
       * @property {Number} SLICED
       */
      SLICED: 1;
    };
  }

  class ScrollView extends ccui.Layout {
    constructor();
    public setDirection(direction: number): void;
    public setInnerContainerPosition(size: cc.Point): void;

    /**
     * Allocates and initializes a UIScrollView.
     * Constructor of ccui.ScrollView. override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @example
     * // example
     * var uiScrollView = new ccui.ScrollView();
     */
    constructor();

    /**
     * Changes inner container size of ScrollView.     <br/>
     * Inner container size must be larger than or equal the size of ScrollView.
     * @param {cc.Size} size inner container size.
     */
    setInnerContainerSize(size: cc.Size): void;

    /**
     * Set inner container position
     *
     * @param {cc.Point} position Inner container position.
     */
    setInnerContainerPosition(position: cc.Point): void;

    /**
     * Get inner container position
     *
     * @return The inner container position.
     */
    getInnerContainerPosition(): cc.Point;

    /**
     * Returns inner container size of ScrollView.     <br/>
     * Inner container size must be larger than or equal ScrollView's size.
     *
     * @return {cc.Size} inner container size.
     */
    getInnerContainerSize(): cc.Size;
    // _getInnerWidth: function () {
    //     return this._innerContainer.width;
    // },
    // _getInnerHeight: function () {
    //     return this._innerContainer.height;
    // },

    setListenAllScrollingEnabled(enabled: boolean): void;

    // _isInContainer: function (widget) {
    //     if (!this._clippingEnabled)
    //         return true;
    //     var wPos = widget._position,
    //         wSize = widget._contentSize,
    //         wAnchor = widget._anchorPoint,
    //         size = this._customSize,
    //         pos = this._innerContainer._position,
    //         bottom = 0, left = 0;
    //     if (
    //         // Top
    //     (bottom = wPos.y - wAnchor.y * wSize.height) >= size.height - pos.y ||
    //         // Bottom
    //     bottom + wSize.height <= -pos.y ||
    //         // right
    //     (left = wPos.x - wAnchor.x * wSize.width) >= size.width - pos.x ||
    //         // left
    //     left + wSize.width <= -pos.x
    //     )
    //         return false;
    //     else return true;
    // },

    // updateChildren: function () {
    //     var child, i, l;
    //     var childrenArray = this._innerContainer._children;
    //     for (i = 0, l = childrenArray.length; i < l; i++) {
    //         child = childrenArray[i];
    //         if (child._inViewRect === true && this._isInContainer(child) === false)
    //             child._inViewRect = false;
    //         else if (child._inViewRect === false && this._isInContainer(child) === true)
    //             child._inViewRect = true;
    //     }
    // },
    // /**
    //  * Add child to ccui.ScrollView.
    //  * @param {cc.Node} widget
    //  * @param {Number} [zOrder]
    //  * @param {Number|string} [tag] tag or name
    //  * @returns {boolean}
    //  */
    // addChild: function (widget, zOrder, tag) {
    //     if (!widget)
    //         return false;
    //     if (this._isInContainer(widget) === false)
    //         widget._inViewRect = false;
    //     zOrder = zOrder || widget.getLocalZOrder();
    //     tag = tag || widget.getTag();
    //     return this._innerContainer.addChild(widget, zOrder, tag);
    // },

    // /**
    //  * Removes all children.
    //  */
    // removeAllChildren: function () {
    //     this.removeAllChildrenWithCleanup(true);
    // },

    // /**
    //  * Removes all children.
    //  * @param {Boolean} cleanup
    //  */
    // removeAllChildrenWithCleanup: function (cleanup) {
    //     this._innerContainer.removeAllChildrenWithCleanup(cleanup);
    // },

    // /**
    //  * Removes widget child
    //  * @override
    //  * @param {ccui.Widget} child
    //  * @param {Boolean} cleanup
    //  * @returns {boolean}
    //  */
    // removeChild: function (child, cleanup) {
    //     return this._innerContainer.removeChild(child, cleanup);
    // },

    // /**
    //  * Returns inner container's children
    //  * @returns {Array}
    //  */
    // getChildren: function () {
    //     return this._innerContainer.getChildren();
    // },

    // /**
    //  * Gets the count of inner container's children
    //  * @returns {Number}
    //  */
    // getChildrenCount: function () {
    //     return this._innerContainer.getChildrenCount();
    // },

    // /**
    //  * Gets a child from the container given its tag
    //  * @param {Number} tag
    //  * @returns {ccui.Widget}
    //  */
    // getChildByTag: function (tag) {
    //     return this._innerContainer.getChildByTag(tag);
    // },

    // /**
    //  * Gets a child from the container given its name
    //  * @param {String} name
    //  * @returns {ccui.Widget}
    //  */
    // getChildByName: function (name) {
    //     return this._innerContainer.getChildByName(name);
    // },

    //     /**
    //      * Set the touch total time threshold
    //      * @param {Number} touchTotalTimeThreshold
    //      */
    //     setTouchTotalTimeThreshold: function (touchTotalTimeThreshold) {
    //         this._touchTotalTimeThreshold = touchTotalTimeThreshold;
    //     },

    //     /**
    //      * Get the touch total time threshold
    //      * @returns {Number}
    //      */
    //     getTouchTotalTimeThreshold: function () {
    //         return this._touchTotalTimeThreshold;
    //     },

    /**
     * Immediately stops inner container scroll initiated by any of the "scrollTo*" member functions
     */
    stopAutoScroll(): void;

    /**
     * Scroll inner container to bottom boundary of ScrollView.
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToBottom(time: number, attenuated: boolean): void;

    /**
     * Scroll inner container to top boundary of ScrollView.
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToTop(time: number, attenuated: boolean): void;

    /**
     * Scroll inner container to left boundary of ScrollView.
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToLeft(time: number, attenuated: boolean): void;

    /**
     * Scroll inner container to right boundary of ScrollView.
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToRight(time: number, attenuated: boolean): void;

    //     /**
    //      * Scroll inner container to top and left boundary of ScrollView.
    //      * @param {Number} time
    //      * @param {Boolean} attenuated
    //      */
    //     scrollToTopLeft: function (time, attenuated) {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll direction is not both!");
    //             return;
    //         }
    //         this._startAutoScrollToDestination(cc.p(0, this._contentSize.height - this._innerContainer.getContentSize().height), time, attenuated);
    //     },

    //     /**
    //      * Scroll inner container to top and right boundary of ScrollView.
    //      * @param {Number} time
    //      * @param {Boolean} attenuated
    //      */
    //     scrollToTopRight: function (time, attenuated) {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll direction is not both!");
    //             return;
    //         }
    //         var inSize = this._innerContainer.getContentSize();
    //         this._startAutoScrollToDestination(cc.p(this._contentSize.width - inSize.width,
    //             this._contentSize.height - inSize.height), time, attenuated);
    //     },

    //     /**
    //      * Scroll inner container to bottom and left boundary of ScrollView.
    //      * @param {Number} time
    //      * @param {Boolean} attenuated
    //      */
    //     scrollToBottomLeft: function (time, attenuated) {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll direction is not both!");
    //             return;
    //         }
    //         this._startAutoScrollToDestination(cc.p(0, 0), time, attenuated);
    //     },

    //     /**
    //      * Scroll inner container to bottom and right boundary of ScrollView.
    //      * @param {Number} time
    //      * @param {Boolean} attenuated
    //      */
    //     scrollToBottomRight: function (time, attenuated) {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll direction is not both!");
    //             return;
    //         }
    //         this._startAutoScrollToDestination(cc.p(this._contentSize.width - this._innerContainer.getContentSize().width, 0), time, attenuated);
    //     },

    /**
     * Scroll inner container to vertical percent position of ScrollView.
     * @param {Number} percent
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToPercentVertical(
      percent: number,
      time: number,
      attenuated: boolean,
    ): void;

    ScrollTo(x: number, y: number): void;

    /**
     * Scroll inner container to horizontal percent position of ScrollView.
     * @param {Number} percent
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToPercentHorizontal(
      percent: number,
      time: number,
      attenuated: boolean,
    ): void;

    /**
     * Scroll inner container to both _direction percent position of ScrollView.
     * @param {cc.Point} percent
     * @param {Number} time
     * @param {Boolean} attenuated
     */
    scrollToPercentBothDirection(
      percent: cc.Point,
      time: number,
      attenuated: boolean,
    ): void;

    /**
     * Move inner container to bottom boundary of ScrollView.
     */
    jumpToBottom(): void;

    /**
     * Move inner container to top boundary of ScrollView.
     */
    jumpToTop(): void;

    /**
     * Move inner container to left boundary of ScrollView.
     */
    jumpToLeft(): void;

    /**
     * Move inner container to right boundary of ScrollView.
     */
    jumpToRight(): void;

    //     /**
    //      * Move inner container to top and left boundary of ScrollView.
    //      */
    //     jumpToTopLeft: function () {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll _direction is not both!");
    //             return;
    //         }
    //         this._jumpToDestination(0, this._contentSize.height - this._innerContainer.getContentSize().height);
    //     },

    //     /**
    //      * Move inner container to top and right boundary of ScrollView.
    //      */
    //     jumpToTopRight: function () {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll _direction is not both!");
    //             return;
    //         }
    //         var inSize = this._innerContainer.getContentSize();
    //         this._jumpToDestination(this._contentSize.width - inSize.width, this._contentSize.height - inSize.height);
    //     },

    //     /**
    //      * Move inner container to bottom and left boundary of ScrollView.
    //      */
    //     jumpToBottomLeft: function () {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll _direction is not both!");
    //             return;
    //         }
    //         this._jumpToDestination(0, 0);
    //     },

    //     /**
    //      * Move inner container to bottom and right boundary of ScrollView.
    //      */
    //     jumpToBottomRight: function () {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH) {
    //             cc.log("Scroll _direction is not both!");
    //             return;
    //         }
    //         this._jumpToDestination(this._contentSize.width - this._innerContainer.getContentSize().width, 0);
    //     },

    /**
     * Move inner container to vertical percent position of ScrollView.
     * @param {Number} percent The destination vertical percent, accept value between 0 - 100
     */
    jumpToPercentVertical(percent: number): void;

    /**
     * Move inner container to horizontal percent position of ScrollView.
     * @param {Number} percent The destination vertical percent, accept value between 0 - 100
     */
    jumpToPercentHorizontal(percent: number): void;

    //     /**
    //      * Move inner container to both _direction percent position of ScrollView.
    //      * @param {cc.Point} percent The destination vertical percent, accept value between 0 - 100
    //      */
    //     jumpToPercentBothDirection: function (percent) {
    //         if (this._direction !== ccui.ScrollView.DIR_BOTH)
    //             return;
    //         var inSize = this._innerContainer.getContentSize();
    //         var minY = this._contentSize.height - inSize.height;
    //         var h = -minY;
    //         var w = inSize.width - this._contentSize.width;
    //         this._jumpToDestination(-(percent.x * w / 100), minY + percent.y * h / 100);
    //     },

    //     /**
    //      * The touch began event callback handler of ccui.ScrollView.
    //      * @param {cc.Touch} touch
    //      * @param {cc.Event} event
    //      * @returns {boolean}
    //      */
    //     onTouchBegan: function (touch, event) {
    //         var pass = ccui.Layout.prototype.onTouchBegan.call(this, touch, event);
    //         if (!this._isInterceptTouch) {
    //             if (this._hit)
    //                 this._handlePressLogic(touch);
    //         }
    //         return pass;
    //     },

    //     /**
    //      * The touch moved event callback handler of ccui.ScrollView.
    //      * @param {cc.Touch} touch
    //      * @param {cc.Event} event
    //      */
    //     onTouchMoved: function (touch, event) {
    //         ccui.Layout.prototype.onTouchMoved.call(this, touch, event);
    //         if (!this._isInterceptTouch)
    //             this._handleMoveLogic(touch);
    //     },

    //     /**
    //      * The touch ended event callback handler of ccui.ScrollView.
    //      * @param {cc.Touch} touch
    //      * @param {cc.Event} event
    //      */
    //     onTouchEnded: function (touch, event) {
    //         ccui.Layout.prototype.onTouchEnded.call(this, touch, event);
    //         if (!this._isInterceptTouch)
    //             this._handleReleaseLogic(touch);
    //         this._isInterceptTouch = false;
    //     },

    //     /**
    //      * The touch canceled event callback of ccui.ScrollView.
    //      * @param {cc.Touch} touch
    //      * @param {cc.Event} event
    //      */
    //     onTouchCancelled: function (touch, event) {
    //         ccui.Layout.prototype.onTouchCancelled.call(this, touch, event);
    //         if (!this._isInterceptTouch)
    //             this._handleReleaseLogic(touch);
    //         this._isInterceptTouch = false;
    //     },

    //     /**
    //      * The update callback handler.
    //      * @param {Number} dt
    //      */
    //     update: function (dt) {
    //         if (this._autoScrolling)
    //             this._processAutoScrolling(dt);
    //     },

    //     /**
    //      * Intercept touch event, handle its child's touch event.
    //      * @override
    //      * @param {number} event event type
    //      * @param {ccui.Widget} sender
    //      * @param {cc.Touch} touch
    //      */
    //     interceptTouchEvent: function (event, sender, touch) {
    //     },

    //     /**
    //      * Adds callback function called ScrollView event triggered
    //      * @param {Function} selector
    //      * @param {Object} [target=]
    //      * @deprecated since v3.0, please use addEventListener instead.
    //      */
    //     addEventListenerScrollView: function (selector, target) {
    //         this._scrollViewEventSelector = selector;
    //         this._scrollViewEventListener = target;
    //     },

    /**
     * Adds callback function called ScrollView event triggered
     * @param {Function} selector
     */
    addEventListener(selector: Function): void;

    //     /**
    //      * Changes scroll _direction of ScrollView.
    //      * @param {ccui.ScrollView.DIR_NONE | ccui.ScrollView.DIR_VERTICAL | ccui.ScrollView.DIR_HORIZONTAL | ccui.ScrollView.DIR_BOTH} dir
    //      *   Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll
    //      */
    //     setDirection: function (dir) {
    //         this._direction = dir;

    //         if(this._scrollBarEnabled)
    //         {
    //             this._removeScrollBar();
    //             this._initScrollBar();
    //         }
    //     },

    //     /**
    //      * Returns scroll direction of ScrollView.
    //      * @returns {ccui.ScrollView.DIR_NONE | ccui.ScrollView.DIR_VERTICAL | ccui.ScrollView.DIR_HORIZONTAL | ccui.ScrollView.DIR_BOTH}
    //      */
    //     getDirection: function () {
    //         return this._direction;
    //     },

    /**
     * Sets bounce enabled
     * @param {Boolean} enabled
     */
    setBounceEnabled(enabled: boolean): void;

    //     /**
    //      * Returns whether bounce is enabled
    //      * @returns {boolean}
    //      */
    //     isBounceEnabled: function () {
    //         return this.bounceEnabled;
    //     },

    //     /**
    //      * Sets inertiaScroll enabled
    //      * @param {boolean} enabled
    //      */
    //     setInertiaScrollEnabled: function (enabled) {
    //         this.inertiaScrollEnabled = enabled;
    //     },

    setInertiaValue(val: number): void;

    //     /**
    //      * Returns whether inertiaScroll is enabled
    //      * @returns {boolean}
    //      */
    //     isInertiaScrollEnabled: function () {
    //         return this.inertiaScrollEnabled;
    //     },

    /**
     * Toggle scroll bar enabled.
     * @param {boolean} enabled True if enable scroll bar, false otherwise.
     */
    setScrollBarEnabled(enabled: boolean): void;
    //     /**
    //      * Query scroll bar state.
    //      * @returns {boolean} True if scroll bar is enabled, false otherwise.
    //      */
    //     isScrollBarEnabled: function()
    //     {
    //         return this._scrollBarEnabled;
    //     },

    /**
     * Set the scroll bar positions from the left-bottom corner (horizontal) and right-top corner (vertical).
     * @param {cc.Point} positionFromCorner The position from the left-bottom corner (horizontal) and right-top corner (vertical).
     */
    setScrollBarPositionFromCorner(positionFromCorner: cc.Point): void;

    //     /**
    //      * Set the vertical scroll bar position from right-top corner.
    //      * @param {cc.Point} positionFromCorner The position from right-top corner
    //      */
    //     setScrollBarPositionFromCornerForVertical: function(positionFromCorner)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         cc.assert(this._direction !== ccui.ScrollView.DIR_HORIZONTAL, "Scroll view doesn't have a vertical scroll bar!");
    //         this._verticalScrollBar.setPositionFromCorner(positionFromCorner);
    //     },

    //     /**
    //      * Get the vertical scroll bar's position from right-top corner.
    //      * @returns {cc.Point}
    //      */
    //     getScrollBarPositionFromCornerForVertical: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         cc.assert(this._direction !== ccui.ScrollView.DIR_HORIZONTAL, "Scroll view doesn't have a vertical scroll bar!");
    //         return this._verticalScrollBar.getPositionFromCorner();
    //     },

    //     /**
    //      * Set the horizontal scroll bar position from left-bottom corner.
    //      * @param {cc.Point} positionFromCorner The position from left-bottom corner
    //      */
    //     setScrollBarPositionFromCornerForHorizontal: function(positionFromCorner)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         cc.assert(this._direction !== ccui.ScrollView.DIR_VERTICAL, "Scroll view doesn't have a horizontal scroll bar!");
    //         this._horizontalScrollBar.setPositionFromCorner(positionFromCorner);
    //     },

    //     /**
    //      * Get the horizontal scroll bar's position from right-top corner.
    //      * @returns {cc.Point}
    //      */
    //     getScrollBarPositionFromCornerForHorizontal: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         cc.assert(this._direction !== ccui.ScrollView.DIR_VERTICAL, "Scroll view doesn't have a horizontal scroll bar!");
    //         return this._horizontalScrollBar.getPositionFromCorner();
    //     },

    /**
     * Set the scroll bar's width
     * @param {number} width The scroll bar's width
     */
    setScrollBarWidth(width: number): void;

    //     /**
    //      * Get the scroll bar's width
    //      * @returns {number} the scroll bar's width
    //      */
    //     getScrollBarWidth: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             return this._verticalScrollBar.getWidth();
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             return this._horizontalScrollBar.getWidth();
    //         }
    //         return 0;
    //     },

    //     /**
    //      * Set the scroll bar's color
    //      * @param {cc.Color} color the scroll bar's color
    //      */
    //     setScrollBarColor: function(color)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar.setColor(color);
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar.setColor(color);
    //         }
    //     },

    //     /**
    //      * Get the scroll bar's color
    //      * @returns {cc.Color} the scroll bar's color
    //      */
    //     getScrollBarColor: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar.getColor();
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar.getColor();
    //         }
    //         return cc.color.WHITE;
    //     },

    //     /**
    //      * Set the scroll bar's opacity
    //      * @param {number} opacity the scroll bar's opacity
    //      */
    //     setScrollBarOpacity: function(opacity)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar.opacity = opacity;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar.opacity = opacity;
    //         }
    //     },

    //     /**
    //      * Get the scroll bar's opacity
    //      * @returns {number}
    //      */
    //     getScrollBarOpacity: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             return this._verticalScrollBar.opacity;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             return this._horizontalScrollBar.opacity;
    //         }
    //         return -1;
    //     },

    //     /**
    //      * Set scroll bar auto hide state
    //      * @param {boolean} autoHideEnabled scroll bar auto hide state
    //      */
    //     setScrollBarAutoHideEnabled: function(autoHideEnabled)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar.autoHideEnabled = autoHideEnabled;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar.autoHideEnabled = autoHideEnabled;
    //         }
    //     },

    //     /**
    //      * Query scroll bar auto hide state
    //      * @returns {boolean}
    //      */
    //     isScrollBarAutoHideEnabled: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             return this._verticalScrollBar.autoHideEnabled;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             return this._horizontalScrollBar.autoHideEnabled;
    //         }
    //         return false;
    //     },

    //     /**
    //      * Set scroll bar auto hide time
    //      * @param {number} autoHideTime scroll bar auto hide state
    //      */
    //     setScrollBarAutoHideTime: function(autoHideTime)
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar.autoHideTime = autoHideTime;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar.autoHideTime = autoHideTime;
    //         }
    //     },

    //     /**
    //      * Get the scroll bar's auto hide time
    //      * @returns {number}
    //      */
    //     getScrollBarAutoHideTime: function()
    //     {
    //         cc.assert(this._scrollBarEnabled, "Scroll bar should be enabled!");
    //         if(this._verticalScrollBar)
    //         {
    //             return this._verticalScrollBar.autoHideTime;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             return this._horizontalScrollBar.autoHideTime;
    //         }
    //         return 0;
    //     },

    /**
     * Gets inner container of ScrollView. Inner container is the container of ScrollView's children.
     * @returns {ccui.Layout}
     */
    getInnerContainer(): ccui.Layout;

    //     /**
    //      * Sets LayoutType of ccui.ScrollView.
    //      * @param {ccui.Layout.ABSOLUTE|ccui.Layout.LINEAR_VERTICAL|ccui.Layout.LINEAR_HORIZONTAL|ccui.Layout.RELATIVE} type
    //      */
    //     setLayoutType: function (type) {
    //         this._innerContainer.setLayoutType(type);
    //     },

    //     /**
    //      * Returns the layout type of ccui.ScrollView.
    //      * @returns {ccui.Layout.ABSOLUTE|ccui.Layout.LINEAR_VERTICAL|ccui.Layout.LINEAR_HORIZONTAL|ccui.Layout.RELATIVE}
    //      */
    //     getLayoutType: function () {
    //         return this._innerContainer.getLayoutType();
    //     },

    //     _doLayout: function () {
    //         if (!this._doLayoutDirty)
    //             return;
    //         this._doLayoutDirty = false;
    //     },

    isScrolling(): boolean;
    isAutoScrolling(): boolean;

    //     /**
    //      * Returns the "class name" of ccui.ScrollView.
    //      * @returns {string}
    //      */
    //     getDescription: function () {
    //         return "ScrollView";
    //     },

    //     _createCloneInstance: function () {
    //         return new ccui.ScrollView();
    //     },

    //     _initScrollBar: function()
    //     {
    //         if(this._direction !== ccui.ScrollView.DIR_HORIZONTAL && !this._verticalScrollBar)
    //         {
    //             this._verticalScrollBar = new ccui.ScrollViewBar(this, ccui.ScrollView.DIR_VERTICAL);
    //             this.addProtectedChild(this._verticalScrollBar, 2);
    //         }
    //         if(this._direction !== ccui.ScrollView.DIR_VERTICAL && !this._horizontalScrollBar)
    //         {
    //             this._horizontalScrollBar = new ccui.ScrollViewBar(this, ccui.ScrollView.DIR_HORIZONTAL);
    //             this.addProtectedChild(this._horizontalScrollBar, 2);
    //         }
    //     },

    //     _removeScrollBar: function()
    //     {
    //         if(this._verticalScrollBar)
    //         {
    //             this.removeProtectedChild(this._verticalScrollBar);
    //             this._verticalScrollBar = null;
    //         }
    //         if(this._horizontalScrollBar)
    //         {
    //             this.removeProtectedChild(this._horizontalScrollBar);
    //             this._horizontalScrollBar = null;
    //         }
    //     },

    //     /**
    //      * Returns a node by tag
    //      * @param {Number} tag
    //      * @returns {cc.Node}
    //      * @deprecated  since v3.0, please use getChildByTag instead.
    //      */
    //     getNodeByTag: function (tag) {
    //         return this._innerContainer.getNodeByTag(tag);
    //     },

    //     /**
    //      * Returns all nodes of inner container
    //      * @returns {Array}
    //      * @deprecated since v3.0, please use getChildren instead.
    //      */
    //     getNodes: function () {
    //         return this._innerContainer.getNodes();
    //     },

    //     /**
    //      * Removes a node from ccui.ScrollView.
    //      * @param {cc.Node} node
    //      * @deprecated since v3.0, please use removeChild instead.
    //      */
    //     removeNode: function (node) {
    //         this._innerContainer.removeNode(node);
    //     },

    //     /**
    //      * Removes a node by tag
    //      * @param {Number} tag
    //      * @deprecated since v3.0, please use removeChildByTag instead.
    //      */
    //     removeNodeByTag: function (tag) {
    //         this._innerContainer.removeNodeByTag(tag);
    //     },

    //     /**
    //      * Remove all node from ccui.ScrollView.
    //      * @deprecated since v3.0, please use removeAllChildren instead.
    //      */
    //     removeAllNodes: function () {
    //         this._innerContainer.removeAllNodes();
    //     },

    //     /**
    //      * Add node for scrollView
    //      * @param {cc.Node} node
    //      * @param {Number} zOrder
    //      * @param {Number} tag
    //      * @deprecated since v3.0, please use addChild instead.
    //      */
    //     addNode: function (node, zOrder, tag) {
    //         this._innerContainer.addNode(node, zOrder, tag);
    //     }
    // });

    // var _p = ccui.ScrollView.prototype;

    // // Extended properties
    // /** @expose */
    // _p.innerWidth;
    // cc.defineGetterSetter(_p, "innerWidth", _p._getInnerWidth, _p._setInnerWidth);
    // /** @expose */
    // _p.innerHeight;
    // cc.defineGetterSetter(_p, "innerHeight", _p._getInnerHeight, _p._setInnerHeight);
    // /** @expose */
    // _p.direction;
    // cc.defineGetterSetter(_p, "direction", _p.getDirection, _p.setDirection);
    // /** @expose */
    // _p.touchTotalTimeThreshold;
    // cc.defineGetterSetter(_p, "touchTotalTimeThreshold", _p.getTouchTotalTimeThreshold, _p.setTouchTotalTimeThreshold);
    // _p = null;
    // /**
    //  * allocates and initializes a UIScrollView.
    //  * @deprecated since v3.0, please use new ccui.ScrollView() instead.
    //  * @return {ccui.ScrollView}
    //  */
    // ccui.ScrollView.create = function () {
    //     return new ccui.ScrollView();
    // };

    // Constants
    //ScrollView direction
    /**
     * The none flag of ccui.ScrollView's direction.
     * @constant
     * @type {number}
     */
    static readonly DIR_NONE = 0;
    /**
     * The vertical flag of ccui.ScrollView's direction.
     * @constant
     * @type {number}
     */
    static readonly DIR_VERTICAL = 1;
    /**
     * The horizontal flag of ccui.ScrollView's direction.
     * @constant
     * @type {number}
     */
    static readonly DIR_HORIZONTAL = 2;
    /**
     * The both flag of ccui.ScrollView's direction.
     * @constant
     * @type {number}
     */
    static readonly DIR_BOTH = 3;

    //ScrollView event
    /**
     * The flag scroll to top of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_SCROLL_TO_TOP = 0;
    /**
     * The flag scroll to bottom of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_SCROLL_TO_BOTTOM = 1;
    /**
     * The flag scroll to left of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_SCROLL_TO_LEFT = 2;
    /**
     * The flag scroll to right of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_SCROLL_TO_RIGHT = 3;
    /**
     * The scrolling flag of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_SCROLLING = 4;
    /**
     * The flag bounce top of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_BOUNCE_TOP = 5;
    /**
     * The flag bounce bottom of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_BOUNCE_BOTTOM = 6;
    /**
     * The flag bounce left of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_BOUNCE_LEFT = 7;
    /**
     * The flag bounce right of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_BOUNCE_RIGHT = 8;
    /**
     * The flag container moved of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_CONTAINER_MOVED = 9;
    /**
     * The flag autoscroll ended of ccui.ScrollView's event.
     * @constant
     * @type {number}
     */
    static readonly EVENT_AUTOSCROLL_ENDED = 10;

    // /**
    //  * @ignore
    //  */

    static readonly MOVEDIR_TOP = 0;
    static readonly MOVEDIR_BOTTOM = 1;
    static readonly MOVEDIR_LEFT = 2;
    static readonly MOVEDIR_RIGHT = 3;
    static readonly SCROLLING_BEGAN = 10;
    static readonly SCROLLING_ENDED = 11;
  }
}
