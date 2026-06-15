declare namespace cc {
  /**
   * @ignore
   */
  const SCROLLVIEW_DIRECTION_NONE = -1;

  const SCROLLVIEW_DIRECTION_HORIZONTAL = 0;

  const SCROLLVIEW_DIRECTION_VERTICAL = 1;

  const SCROLLVIEW_DIRECTION_BOTH = 2;

  function convertDistanceFromPointToInch(pointDis: number): number;

  class ScrollViewDelegate extends Class {
    scrollViewDidScroll(view: cc.ScrollView): void;
    scrollViewDidZoom(view: cc.ScrollView): void;
  }

  /**
   * ScrollView support for cocos2d -x.
   * It provides scroll view functionalities to cocos2d projects natively.
   * @class
   * @extends cc.Layer
   *
   * @property {cc.Point}                 minOffset   - <@readonly> The current container's minimum offset
   * @property {cc.Point}                 maxOffset   - <@readonly> The current container's maximum offset
   * @property {Boolean}                  bounceable  - Indicate whether the scroll view is bounceable
   * @property {cc.Size}                  viewSize    - The size of the scroll view
   * @property {cc.Layer}                 container   - The inside container of the scroll view
   * @property {Number}                   direction   - The direction allowed to scroll: cc.SCROLLVIEW_DIRECTION_BOTH by default, or cc.SCROLLVIEW_DIRECTION_NONE | cc.SCROLLVIEW_DIRECTION_HORIZONTAL | cc.SCROLLVIEW_DIRECTION_VERTICAL
   * @property {cc.ScrollViewDelegate}    delegate    - The inside container of the scroll view
   * @property {Boolean}           clippingToBounds   - Indicate whether the scroll view clips its children
   */
  // cc.ScrollView = cc.Layer.extend(/** @lends cc.ScrollView# */{
  class ScrollView extends Layer {
    _zoomScale: number;
    _minZoomScale: number;
    _maxZoomScale: number;
    _delegate: cc.ScrollViewDelegate | null;
    _dragging: boolean;
    _contentOffset: cc.Point;
    _container: cc.Node | undefined;
    _touchMoved: boolean;
    _maxInset: cc.Point;
    _minInset: cc.Point;
    _bounceable: boolean;
    _clippingToBounds: boolean;
    _scrollDistance: cc.Point;
    _touchPoint: cc.Point;
    _touchLength: number;
    _touches: cc.Touch[];
    _viewSize: cc.Size;
    _minScale: boolean;
    _maxScale: boolean;

    //scissor rect for parent; just for restoring GL_SCISSOR_BOX
    _parentScissorRect: cc.Rect;
    _scissorRestored: boolean;

    // cache object
    _tmpViewRect: cc.Rect;
    _touchListener: Function | null;
    _className: string;
    /**
     * @contructor
     * @param size
     * @param container
     * @returns {ScrollView}
     */
    constructor(size: cc.Size, container?: cc.Node);

    /**
     * Sets a new content offset. It ignores max/min offset. It just sets what's given. (just like UIKit's UIScrollView)
     *
     * @param {cc.Point} offset new offset
     * @param {Number} [animated=] If true, the view will scroll to the new offset
     */
    setContentOffset(offset: Point, animated?: boolean): void;

    getContentOffset(): cc.Point;

    /**
     * <p>Sets a new content offset. It ignores max/min offset. It just sets what's given. (just like UIKit's UIScrollView) <br/>
     * You can override the animation duration with this method.
     * </p>
     * @param {cc.Point} offset new offset
     * @param {Number} dt animation duration
     */
    setContentOffsetInDuration(offset: cc.Point, dt: number): void;

    /**
     * Sets a new scale and does that for a predefined duration.
     *
     * @param {Number} scale a new scale vale
     * @param {Boolean} [animated=null] if YES, scaling is animated
     */
    setZoomScale(scale: number, animated?: boolean): void;

    getZoomScale(): number;

    /**
     * Sets a new scale for container in a given duration.
     *
     * @param {Number} s a new scale value
     * @param {Number} dt animation duration
     */
    setZoomScaleInDuration(s: number, dt: number): void;

    /**
     * Returns the current container's minimum offset. You may want this while you animate scrolling by yourself
     * @return {cc.Point} Returns the current container's minimum offset.
     */
    minContainerOffset(): cc.Point;

    /**
     * Returns the current container's maximum offset. You may want this while you animate scrolling by yourself
     * @return {cc.Point} Returns the current container's maximum offset.
     */
    maxContainerOffset(): cc.Point;

    /**
     * Determines if a given node's bounding box is in visible bounds
     * @param {cc.Node} node
     * @return {Boolean} YES if it is in visible bounds
     */
    isNodeVisible(node: cc.Node): boolean;

    // /**
    //  * Provided to make scroll view compatible with SWLayer's pause method
    //  */
    // pause(sender: cc.Node): void;

    // /**
    //  * Provided to make scroll view compatible with SWLayer's resume method
    //  */
    // resume(sender: any): void;

    isDragging(): boolean;
    isTouchMoved(): boolean;
    isBounceable(): boolean;
    setBounceable(bounceable: boolean): void;

    /**
     * <p>
     * size to clip. CCNode boundingBox uses contentSize directly.                   <br/>
     * It's semantically different what it actually means to common scroll views.    <br/>
     * Hence, this scroll view will use a separate size property.
     * </p>
     */
    getViewSize(): cc.Size;

    setViewSize(size: cc.Size): void;

    getContainer(): cc.Node;

    setContainer(container: cc.Node): void;

    /**
     * direction allowed to scroll. CCScrollViewDirectionBoth by default.
     */
    getDirection(): number;

    setDirection(direction: number): void;

    getDelegate(): ScrollViewDelegate;

    setDelegate(delegate: ScrollViewDelegate): void;

    /** override functions */
    // optional
    onTouchBegan(touch: cc.Touch, event: any): boolean;

    onTouchMoved(touch: cc.Touch, event: any): void;

    onTouchEnded(touch: cc.Touch, event: any): void;

    getContentSize(): cc.Size;

    /**
     * Determines whether it clips its children or not.
     */
    isClippingToBounds(): boolean;

    setClippingToBounds(clippingToBounds: boolean): void;

    isTouchEnabled(): boolean;

    setTouchEnabled(e: boolean): void;

    get minOffset(): cc.Point;
    set minOffset(value: cc.Point);
    get maxOffset(): cc.Point;
    set maxOffset(value: cc.Point);
    get bounceable(): boolean;
    set bounceable(value: boolean);
    get viewSize(): cc.Size;
    set viewSize(value: cc.Size);
    get container(): cc.Node;
    set container(value: cc.Node);
    get direction(): number;
    set direction(value: number);
    get delegate(): cc.ScrollViewDelegate;
    set delegate(value: cc.ScrollViewDelegate);
    get clippingToBounds(): boolean;
    set clippingToBounds(value: boolean);
  }
}
