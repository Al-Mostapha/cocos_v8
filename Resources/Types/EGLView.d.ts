/****************************************************************************
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011-2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

/**
 * @ignore
 */
declare namespace cc {
  var Touches: [];
  var TouchesIntergerDict: {};
  // var DENSITYDPI_DEVICE : "device-dpi";
  // var DENSITYDPI_HIGH : "high-dpi";
  // var DENSITYDPI_MEDIUM : "medium-dpi";
  // var DENSITYDPI_LOW : "low-dpi";

  class EGLView extends Class {
    /**
     * <p>
     * Sets view's target-densitydpi for android mobile browser. it can be set to:           <br/>
     *   1. cc.DENSITYDPI_DEVICE, value is "device-dpi"                                      <br/>
     *   2. cc.DENSITYDPI_HIGH, value is "high-dpi"  (default value)                         <br/>
     *   3. cc.DENSITYDPI_MEDIUM, value is "medium-dpi" (browser's default value)            <br/>
     *   4. cc.DENSITYDPI_LOW, value is "low-dpi"                                            <br/>
     *   5. Custom value, e.g: "480"                                                         <br/>
     * </p>
     * @param {String} densityDPI
     */
    setTargetDensityDPI(densityDPI: string): void;

    /**
     * Returns the current target-densitydpi value of cc.view.
     * @returns {String}
     */
    getTargetDensityDPI(): string;

    /**
     * Sets whether resize canvas automatically when browser's size changed.<br/>
     * Useful only on web.
     * @param {Boolean} enabled Whether enable automatic resize with browser's resize event
     */
    resizeWithBrowserSize(enabled: boolean): void;

    /**
     * Sets the callback function for cc.view's resize action,<br/>
     * this callback will be invoked before applying resolution policy, <br/>
     * so you can do any additional modifications within the callback.<br/>
     * Useful only on web.
     * @param {Function|null} callback The callback function
     */
    setResizeCallback(callback: Function | null): void;

    /**
     * Sets the orientation of the game, it can be landscape, portrait or auto.
     * When set it to landscape or portrait, and screen w/h ratio doesn't fit,
     * cc.view will automatically rotate the game canvas using CSS.
     * Note that this function doesn't have any effect in native,
     * in native, you need to set the application orientation in native project settings
     * @param {Number} orientation - Possible values: cc.ORIENTATION_LANDSCAPE | cc.ORIENTATION_PORTRAIT | cc.ORIENTATION_AUTO
     */
    setOrientation(orientation: number): void;

    setDocumentPixelWidth(width: number): void;

    initialize(): void;

    /**
     * Sets whether the engine modify the "viewport" meta in your web page.<br/>
     * It's enabled by default, we strongly suggest you not to disable it.<br/>
     * And even when it's enabled, you can still set your own "viewport" meta, it won't be overridden<br/>
     * Only useful on web
     * @param {Boolean} enabled Enable automatic modification to "viewport" meta
     */
    adjustViewPort(enabled: boolean): void;

    /**
     * Retina support is enabled by default for Apple device but disabled for other devices,<br/>
     * it takes effect only when you called setDesignResolutionPolicy<br/>
     * Only useful on web
     * @param {Boolean} enabled  Enable or disable retina display
     */
    enableRetina(enabled: boolean): void;

    /**
     * Check whether retina display is enabled.<br/>
     * Only useful on web
     * @return {Boolean}
     */
    isRetinaEnabled(): boolean;

    /**
     * If enabled, the application will try automatically to enter full screen mode on mobile devices<br/>
     * You can pass true as parameter to enable it and disable it by passing false.<br/>
     * Only useful on web
     * @param {Boolean} enabled  Enable or disable auto full screen on mobile devices
     */
    enableAutoFullScreen(enabled: boolean): void;

    /**
     * Check whether auto full screen is enabled.<br/>
     * Only useful on web
     * @return {Boolean} Auto full screen enabled or not
     */
    isAutoFullScreenEnabled(): boolean;

    /**
     * Get whether render system is ready(no matter opengl or canvas),<br/>
     * this name is for the compatibility with cocos2d-x, subclass must implement this method.
     * @return {Boolean}
     */
    isOpenGLReady(): boolean;

    /*
     * Set zoom factor for frame. This method is for debugging big resolution (e.g.new ipad) app on desktop.
     * @param {Number} zoomFactor
     */
    setFrameZoomFactor(zoomFactor: number): void;

    /**
     * Exchanges the front and back buffers, subclass must implement this method.
     */
    swapBuffers(): void;

    /**
     * Open or close IME keyboard , subclass must implement this method.
     * @param {Boolean} isOpen
     */
    setIMEKeyboardState(isOpen: boolean): void;

    /**
     * Sets the resolution translate on EGLView
     * @param {Number} offsetLeft
     * @param {Number} offsetTop
     */
    setContentTranslateLeftTop(offsetLeft: number, offsetTop: number): void;

    /**
     * Returns the resolution translate on EGLView
     * @return {cc.Size|Object}
     */
    getContentTranslateLeftTop(): Size | object;

    /**
     * Returns the canvas size of the view.<br/>
     * On native platforms, it returns the screen size since the view is a fullscreen view.<br/>
     * On web, it returns the size of the canvas element.
     * @return {cc.Size}
     */
    getCanvasSize(): Size;

    /**
     * Returns the frame size of the view.<br/>
     * On native platforms, it returns the screen size since the view is a fullscreen view.<br/>
     * On web, it returns the size of the canvas's outer DOM element.
     * @return {cc.Size}
     */
    getFrameSize(): Size;

    /**
     * On native, it sets the frame size of view.<br/>
     * On web, it sets the size of the canvas's outer DOM element.
     * @param {Number} width
     * @param {Number} height
     */
    setFrameSize(width: number, height: number): void;

    /**
     * Returns the visible area size of the view port.
     * @return {cc.Size}
     */
    getVisibleSize(): Size;

    /**
     * Returns the visible area size of the view port.
     * @return {cc.Size}
     */
    getVisibleSizeInPixel(): Size;

    /**
     * Returns the visible origin of the view port.
     * @return {cc.Point}
     */
    getVisibleOrigin(): Point;

    /**
     * Returns the visible origin of the view port.
     * @return {cc.Point}
     */
    getVisibleOriginInPixel(): Point;

    /**
     * Returns whether developer can set content's scale factor.
     * @return {Boolean}
     */
    canSetContentScaleFactor(): boolean;

    /**
     * Returns the current resolution policy
     * @see cc.ResolutionPolicy
     * @return {cc.ResolutionPolicy}
     */
    getResolutionPolicy(): ResolutionPolicy;

    /**
     * Sets the current resolution policy
     * @see cc.ResolutionPolicy
     * @param {cc.ResolutionPolicy|Number} resolutionPolicy
     */
    setResolutionPolicy(resolutionPolicy: ResolutionPolicy | number): void;

    /**
     * Sets the resolution policy with designed view size in points.<br/>
     * The resolution policy include: <br/>
     * [1] ResolutionExactFit       Fill screen by stretch-to-fit: if the design resolution ratio of width to height is different from the screen resolution ratio, your game view will be stretched.<br/>
     * [2] ResolutionNoBorder       Full screen without black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two areas of your game view will be cut.<br/>
     * [3] ResolutionShowAll        Full screen with black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two black borders will be shown.<br/>
     * [4] ResolutionFixedHeight    Scale the content's height to screen's height and proportionally scale its width<br/>
     * [5] ResolutionFixedWidth     Scale the content's width to screen's width and proportionally scale its height<br/>
     * [cc.ResolutionPolicy]        [Web only feature] Custom resolution policy, constructed by cc.ResolutionPolicy<br/>
     * @param {Number} width Design resolution width.
     * @param {Number} height Design resolution height.
     * @param {cc.ResolutionPolicy|Number} resolutionPolicy The resolution policy desired
     */
    setDesignResolutionSize(
      width: number,
      height: number,
      resolutionPolicy: ResolutionPolicy | number,
    ): void;

    /**
     * Returns the designed size for the view.
     * Default resolution size is the same as 'getFrameSize'.
     * @return {cc.Size}
     */
    getDesignResolutionSize(): Size;

    /**
     * Sets the document body to desired pixel resolution and fit the game content to it.
     * This function is very useful for adaptation in mobile browsers.
     * In some HD android devices, the resolution is very high, but its browser performance may not be very good.
     * In this case, enabling retina display is very costy and not suggested, and if retina is disabled, the image may be blurry.
     * But this API can be helpful to set a desired pixel resolution which is in between.
     * This API will do the following:
     *     1. Set viewport's width to the desired width in pixel
     *     2. Set body width to the exact pixel resolution
     *     3. The resolution policy will be reset with designed view size in points.
     * @param {Number} width Design resolution width.
     * @param {Number} height Design resolution height.
     * @param {cc.ResolutionPolicy|Number} resolutionPolicy The resolution policy desired
     */
    setRealPixelResolution(
      width: number,
      height: number,
      resolutionPolicy: ResolutionPolicy | number,
    ): void;

    /**
     * Sets view port rectangle with points.
     * @param {Number} x
     * @param {Number} y
     * @param {Number} w width
     * @param {Number} h height
     */
    setViewPortInPoints(x: number, y: number, w: number, h: number): void;

    /**
     * Sets Scissor rectangle with points.
     * @param {Number} x
     * @param {Number} y
     * @param {Number} w
     * @param {Number} h
     */
    setScissorInPoints(x: number, y: number, w: number, h: number): void;
    /**
     * Returns whether GL_SCISSOR_TEST is enable
     * @return {Boolean}
     */
    isScissorEnabled(): boolean;

    /**
     * Returns the current scissor rectangle
     * @return {cc.Rect}
     */
    getScissorRect(): Rect;

    /**
     * Sets the name of the view
     * @param {String} viewName
     */
    setViewName(viewName: string): void;

    /**
     * Returns the name of the view
     * @return {String}
     */
    getViewName(): string;

    /**
     * Returns the view port rectangle.
     * @return {cc.Rect}
     */
    getViewPortRect(): Rect;

    /**
     * Returns scale factor of the horizontal direction (X axis).
     * @return {Number}
     */
    getScaleX(): number;

    /**
     * Returns scale factor of the vertical direction (Y axis).
     * @return {Number}
     */
    getScaleY(): number;

    /**
     * Returns device pixel ratio for retina display.
     * @return {Number}
     */
    getDevicePixelRatio(): number;

    getRetinaFactor(): number;

    /**
     * Returns the real location in view for a translation based on a related position
     * @param {Number} tx The X axis translation
     * @param {Number} ty The Y axis translation
     * @param {Object} relatedPos The related position object including "left", "top", "width", "height" informations
     * @return {cc.Point}
     */
    convertToLocationInView(tx: number, ty: number, relatedPos: object): Point;
  }

  class ContainerStrategy extends Class {}
  class ContentStrategy extends Class {}

  // class ResolutionPolicy extends Class{
  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name EXACT_FIT
  //    * @constant
  //    * @type Number
  //    * @static
  //    * The entire application is visible in the specified area without trying to preserve the original aspect ratio.<br/>
  //    * Distortion can occur, and the application may appear stretched or compressed.
  //    */
  //   static EXACT_FIT: 0;

  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name NO_BORDER
  //    * @constant
  //    * @type Number
  //    * @static
  //    * The entire application fills the specified area, without distortion but possibly with some cropping,<br/>
  //    * while maintaining the original aspect ratio of the application.
  //    */
  //   static NO_BORDER: 1;

  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name SHOW_ALL
  //    * @constant
  //    * @type Number
  //    * @static
  //    * The entire application is visible in the specified area without distortion while maintaining the original<br/>
  //    * aspect ratio of the application. Borders can appear on two sides of the application.
  //    */
  //   static SHOW_ALL: 2;

  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name FIXED_HEIGHT
  //    * @constant
  //    * @type Number
  //    * @static
  //    * The application takes the height of the design resolution size and modifies the width of the internal<br/>
  //    * canvas so that it fits the aspect ratio of the device<br/>
  //    * no distortion will occur however you must make sure your application works on different<br/>
  //    * aspect ratios
  //    */
  //   static FIXED_HEIGHT: 3;

  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name FIXED_WIDTH
  //    * @constant
  //    * @type Number
  //    * @static
  //    * The application takes the width of the design resolution size and modifies the height of the internal<br/>
  //    * canvas so that it fits the aspect ratio of the device<br/>
  //    * no distortion will occur however you must make sure your application works on different<br/>
  //    * aspect ratios
  //    */
  //   static FIXED_WIDTH: 4;

  //   /**
  //    * @memberOf cc.ResolutionPolicy#
  //    * @name UNKNOWN
  //    * @constant
  //    * @type Number
  //    * @static
  //    * Unknow policy
  //    */
  //   static UNKNOWN: 5;
  //   /**
  //    * Constructor of cc.ResolutionPolicy
  //    * @param {cc.ContainerStrategy} containerStg
  //    * @param {cc.ContentStrategy} contentStg
  //    */
  //   constructor(containerStg?: ContainerStrategy, contentStg?: ContentStrategy);

  //   /**
  //    * Manipulation before applying the resolution policy
  //    * @param {cc.view} view The target view
  //    */
  //   preApply(view: EGLView): void;

  //   /**
  //    * Function to apply this resolution policy
  //    * The return value is {scale: [scaleX, scaleY], viewport: {cc.Rect}},
  //    * The target view can then apply these value to itself, it's preferred not to modify directly its private variables
  //    * @param {cc.view} view The target view
  //    * @param {cc.Size} designedResolution The user defined design resolution
  //    * @return {object} An object contains the scale X/Y values and the viewport rect
  //    */
  //   apply(view: EGLView, designedResolution: Size): object;

  //   /**
  //    * Manipulation after appyling the strategy
  //    * @param {cc.view} view The target view
  //    */
  //   postApply(view: EGLView): void;

  //   /**
  //    * Setup the container's scale strategy
  //    * @param {cc.ContainerStrategy} containerStg
  //    */
  //   setContainerStrategy(containerStg: ContainerStrategy): void;

  //   /**
  //    * Setup the content's scale strategy
  //    * @param {cc.ContentStrategy} contentStg
  //    */
  //   setContentStrategy(contentStg: ContentStrategy): void;
  // }
}
