/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011      Zynga Inc.

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
 * TypeScript definitions for https://github.com/cocos2d/cocos2d-html5
 *
 * 29/JUN/2013 - Adam Davidson
 */

declare namespace ccs {
  var uiReader: any;
  var csLoader: any;
  class ActionTimeline extends cc.Action {
    /**
     * Set the Frame event
     * @param {function} listener
     */
    setFrameEventCallFunc(listener: Function): void;
    /**
     * Goto the specified frame index, and start playing from this index.
     * @param startIndex The animation will play from this index.
     * @param [endIndex=] The animation will end at this index.
     * @param [currentFrameIndex=] set current frame index.
     * @param [loop=] Whether or not the animation need loop.
     */
    gotoFrameAndPlay(
      start: number,
      end?: number | boolean,
      current?: number | boolean,
      loop?: boolean,
    ): void;

    /**
     * Goto the specified frame index, and pause at this index.
     * @param startIndex The animation will pause at this index.
     */
    gotoFrameAndPause(startIndex: number): void;
  }
  function load(
    file: import("fs").PathLike,
    path?: string,
  ): { node: cc.Node; action: ActionTimeline };
}

declare namespace cc {
  var War: any;
  var path: any;
  var math: any;

  var Codec: any;
  var _renderType: any;
  var _renderContext: any;
  var TMXLayer: any;

  var renderer: any;

  var TMXTiledMap: any;

  var SHADER_SPRITE_POSITION_TEXTURECOLORALPHATEST: string;
  var SHADER_SPRITE_POSITION_TEXTURECOLOR: string;
  // var UNIFORM_ALPHA_TEST_VALUE_S: string;

  var shaderCache: any;

  var Test: any;

  // var GLProgramState: GLProgramState | any;

  // function pointPixelsToPoints(val: cc.Point): cc.Point;
  // function sizePixelsToPoints(val: cc.Size): cc.Size;

  // function rectPixelsToPoints(rect: cc.Rect): cc.Rect;

  // function glBindTexture2D(texture: cc.Texture2D): void;
  /**
   * @constant
   * @type Number
   */

  const TMX_PROPERTY_NONE = 0;

  // let OPTIMIZE_BLEND_FUNC_FOR_PREMULTIPLIED_ALPHA: boolean;

  /**
   * @constant
   * @type Number
   */
  const TMX_PROPERTY_MAP = 1;

  /**
   * @constant
   * @type Number
   */
  const TMX_PROPERTY_LAYER = 2;

  /**
   * @constant
   * @type Number
   */
  const TMX_PROPERTY_OBJECTGROUP = 3;

  /**
   * @constant
   * @type Number
   */
  const TMX_PROPERTY_OBJECT = 4;

  /**
   * @constant
   * @type Number
   */
  const TMX_PROPERTY_TILE = 5;

  /**
   * @constant
   * @type Number
   */
  // const TMX_TILE_HORIZONTAL_FLAG = 0x80000000;

  /**
   * @constant
   * @type Number
   */
  // const TMX_TILE_VERTICAL_FLAG = 0x40000000;

  /**
   * @constant
   * @type Number
   */
  // const TMX_TILE_DIAGONAL_FLAG = 0x20000000;

  /**
   * @constant
   * @type Number
   */
  const TMX_TILE_FLIPPED_ALL: number;

  /**
   * @constant
   * @type Number
   */
  const TMX_TILE_FLIPPED_MASK: number;

  /**
   * Unpack a gzipped byte string encoded as base64
   * @param {String} input Byte string encoded as base64
   * @param {Number} bytes Bytes per array item
   * @returns {Array} Unpacked byte array
   */
  function unzipBase64AsArray(input: string, bytes: number): Uint8Array;

  function uint8ArrayToUint32Array(input: Uint8Array): Uint32Array;

  /**
   * create the animate with animation
   * @function
   * @param {cc.Animation} animation
   * @return {cc.Animate}
   * @example
   * // example
   * // create the animation with animation
   * var anim = cc.animate(dance_grey);
   */
  function animate(animation: cc.Animation): cc.Animate;

  /**
   * Generate a color object based on multiple forms of parameters
   * @example
   *
   * // 1. All channels separately as parameters
   * var color1 = cc.color(255, 255, 255, 255);
   *
   * // 2. Convert a hex string to a color
   * var color2 = cc.color("#000000");
   *
   * // 3. An color object as parameter
   * var color3 = cc.color({r: 255, g: 255, b: 255, a: 255});
   *
   * Alpha channel is optional. Default value is 255
   *
   * @param {Number|String|cc.Color} r
   * @param {Number} [g]
   * @param {Number} [b]
   * @param {Number} [a=255]
   * @return {cc.Color}
   */
  // function color(
  //   r: number | String | cc.Color,
  //   g?: number,
  //   b?: number,
  //   a?: number,
  // ): cc.Color;

  // class SAXParser {
  //   ctor: any;
  //   _parseXML(xmlStr: string): Document;
  // }

  const _txtLoader: any;

  let spriteFrameCache: cc.SpriteFrameCache;

  //#region cocos2d/CCCommon.js
  /**
   * copy an new object
   * @function
   * @param {object|Array} obj source object
   * @return {Array|object}
   */
  function clone(obj: any): any;

  /**
   * Function added for JS bindings compatibility. Not needed in cocos2d-html5.
   * @function
   * @param {object} jsobj subclass
   * @param {object} klass superclass
   */
  function associateWithNative(jsobj: any, superclass: any): void;

  /**
   * Is show bebug info on web page
   * @constant
   * @type {Boolean}
   */
  var IS_SHOW_DEBUG_ON_PAGE: boolean;

  /**
   * Output Debug message.
   * @function
   * @param {String} message
   */
  // function log(...message: any[]): void;

  function error(...message: any[]): void;
  function warn(...message: any[]): void;

  /**
   * Pop out a message box
   * @param {String} message
   * @function
   */
  function MessageBox(message: string): void;

  /**
   * Output Assert message.
   * @function
   * @param {Boolean} cond If cond is false, assert.
   * @param {String} message
   */
  function assert(cond: boolean, message: string, ...args: any[]): void;

  /**
   * Update Debug setting.
   * @function
   */
  function initDebugSetting(): void;

  // Enum the language type supportted now
  /**
   * English language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_ENGLISH: number;

  /**
   * Chinese language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_CHINESE: number;

  /**
   * French language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_FRENCH: number;

  /**
   * Italian language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_ITALIAN: number;

  /**
   * German language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_GERMAN: number;

  /**
   * Spanish language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_SPANISH: number;

  /**
   * Russian language code
   * @constant
   * @type Number
   */
  // var LANGUAGE_RUSSIAN: number;
  //#endregion cocos2d/CCCommon.js

  //#region cocos2d/CCDirector.js
  /**
   * <p>
   *    Class that creates and handle the main Window and manages how<br/>
   *    and when to execute the Scenes.<br/>
   *    <br/>
   *    The cc.Director is also responsible for:<br/>
   *      - initializing the OpenGL context<br/>
   *      - setting the OpenGL pixel format (default on is RGB565)<br/>
   *      - setting the OpenGL pixel format (default on is RGB565)<br/>
   *      - setting the OpenGL buffer depth (default one is 0-bit)<br/>
   *      - setting the projection (default one is 3D)<br/>
   *      - setting the orientation (default one is Protrait)<br/>
   *      <br/>
   *    Since the cc.Director is a singleton, the standard way to use it is by calling:<br/>
   *      - cc.Director.getInstance().methodName(); <br/>
   *    <br/>
   *    The CCDirector also sets the default OpenGL context:<br/>
   *      - GL_TEXTURE_2D is enabled<br/>
   *      - GL_VERTEX_ARRAY is enabled<br/>
   *      - GL_COLOR_ARRAY is enabled<br/>
   *      - GL_TEXTURE_COORD_ARRAY is enabled<br/>
   * </p>
   * @class
   * @extends cc.Class
   *
   */
  class DirectorDelegate {}
  class Director extends Class {
    /**
     * The event projection changed of cc.Director
     * @constant
     * @type {string}
     * @example
     *   cc.eventManager.addCustomListener(cc.Director.EVENT_PROJECTION_CHANGED, function(event) {
     *           cc.log("Projection changed.");
     *       });
     */
    static EVENT_PROJECTION_CHANGED: "director_projection_changed";

    /**
     * The event after update of cc.Director
     * @constant
     * @type {string}
     * @example
     *   cc.eventManager.addCustomListener(cc.Director.EVENT_AFTER_UPDATE, function(event) {
     *           cc.log("after update event.");
     *       });
     */
    static EVENT_AFTER_UPDATE: "director_after_update";

    /**
     * The event after visit of cc.Director
     * @constant
     * @type {string}
     * @example
     *   cc.eventManager.addCustomListener(cc.Director.EVENT_AFTER_VISIT, function(event) {
     *           cc.log("after visit event.");
     *       });
     */
    static EVENT_AFTER_VISIT: "director_after_visit";

    /**
     * The event after draw of cc.Director
     * @constant
     * @type {string}
     * @example
     *   cc.eventManager.addCustomListener(cc.Director.EVENT_AFTER_DRAW, function(event) {
     *           cc.log("after draw event.");
     *       });
     */
    static readonly EVENT_AFTER_DRAW = "director_after_draw";

    static readonly sharedDirector: Director;
    static readonly firstUseDirector = true;
    /**
     * Default fps is 60
     * @type {Number}
     */

    //Possible OpenGL projections used by director
    /**
     * Constant for 2D projection (orthogonal projection)
     * @constant
     * @type {Number}
     */
    static readonly PROJECTION_2D = 0;

    /**
     * Constant for 3D projection with a fovy=60, znear=0.5f and zfar=1500.
     * @constant
     * @type {Number}
     */
    static readonly PROJECTION_3D = 1;

    /**
     * Constant for custom projection, if cc.Director's projection set to it, it calls "updateProjection" on the projection delegate.
     * @constant
     * @type {Number}
     */
    static readonly PROJECTION_CUSTOM = 3;

    /**
     * Constant for default projection of cc.Director, default projection is 2D projection
     * @constant
     * @type {Number}
     */
    static readonly PROJECTION_DEFAULT = 1;

    /**
     * returns a shared instance of the director
     * @function
     * @return {cc.Director}
     */
    static getInstance(): Director;

    /**
     * initializes cc.Director
     * @return {Boolean}
     */
    init(): boolean;

    setAnimationInterval(interval: number): void;
    mainLoop(): void;

    /**
     * calculates delta time since last time it was called
     */
    calculateDeltaTime(): void;

    /**
     * Converts a view coordinate to an WebGL coordinate<br/>
     * Useful to convert (multi) touches coordinates to the current layout (portrait or landscape)<br/>
     * Implementation can be found in CCDirectorWebGL
     * @function
     * @param {cc.Point} uiPoint
     * @return {cc.Point}
     */
    convertToGL(uiPoint: Point): Point;

    /**
     * Converts an WebGL coordinate to a view coordinate<br/>
     * Useful to convert node points to window points for calls such as glScissor<br/>
     * Implementation can be found in CCDirectorWebGL
     * @function
     * @param {cc.Point} glPoint
     * @return {cc.Point}
     */
    convertToUI(glPoint: Point): Point;

    /**
     *  Draw the scene. This method is called every frame. Don't call it manually.
     */
    drawScene(): void;

    /**
     * End the life of director in the next frame
     */
    end(): void;

    /**
     * Returns the size in pixels of the surface. It could be different than the screen size.<br/>
     * High-res devices might have a higher surface size than the screen size.
     * @return {Number}
     */
    getContentScaleFactor(): number;
    /**
     * This object will be visited after the main scene is visited.<br/>
     * This object MUST implement the "visit" selector.<br/>
     * Useful to hook a notification object
     * @return {cc.Node}
     */
    getNotificationNode(): Node;
    /**
     * Returns the size of the WebGL view in points.<br/>
     * It takes into account any possible rotation (device orientation) of the window
     * @return {cc.Size}
     */
    getWinSize(): Size;

    /**
     * Returns the size of the OpenGL view in pixels.<br/>
     * It takes into account any possible rotation (device orientation) of the window.<br/>
     * On Mac winSize and winSizeInPixels return the same value.
     * @return {cc.Size}
     */
    getWinSizeInPixels(): Size;

    /**
     * getVisibleSize/getVisibleOrigin move to CCDirectorWebGL/CCDirectorCanvas
     * getZEye move to CCDirectorWebGL
     */

    /**
     * Returns the visible size of the running scene
     * @function
     * @return {cc.Size}
     */
    getVisibleSize(): Size;

    /**
     * Returns the visible origin of the running scene
     * @function
     * @return {cc.Point}
     */
    getVisibleOrigin(): Point;

    /**
     * Returns the z eye, only available in WebGL mode
     * @function
     * @return {Number}
     */
    getZEye(): number;

    /**
     * Pause the director's ticker
     */
    pause(): void;

    /**
     * Pops out a scene from the queue.<br/>
     * This scene will replace the running one.<br/>
     * The running scene will be deleted. If there are no more scenes in the stack the execution is terminated.<br/>
     * ONLY call it if there is a running scene.
     */
    popScene(): void;

    /**
     * Removes cached all cocos2d cached data. It will purge the cc.textureCache, cc.spriteFrameCache, cc.animationCache
     */
    purgeCachedData(): void;

    /**
     * Purge the cc.director itself, including unschedule all schedule, remove all event listeners, clean up and exit the running scene, stops all animations, clear cached data.
     */
    purgeDirector(): void;

    /**
     * Suspends the execution of the running scene, pushing it on the stack of suspended scenes.<br/>
     * The new scene will be executed.<br/>
     * Try to avoid big stacks of pushed scenes to reduce memory allocation.<br/>
     * ONLY call it if there is a running scene.
     * @param {cc.Scene} scene
     */
    pushScene(scene: Scene): void;

    /**
     * Run a scene. Replaces the running scene with a new one or enter the first scene.
     * @param {cc.Scene} scene
     */
    runScene(scene: Scene): void;
    /**
     * Resume director after pause, if the current scene is not paused, nothing will happen.
     */
    resume(): void;

    /**
     * The size in pixels of the surface. It could be different than the screen size.<br/>
     * High-res devices might have a higher surface size than the screen size.
     * @param {Number} scaleFactor
     */
    setContentScaleFactor(scaleFactor: number): void;

    /**
     * Enables or disables WebGL depth test.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js
     * @function
     * @param {Boolean} on
     */
    setDepthTest(on: boolean): void;

    /**
     * set color for clear screen.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js
     * @function
     * @param {cc.Color} clearColor
     */
    setClearColor(clearColor: Color): void;
    /**
     * Sets the default values based on the CCConfiguration info
     */
    setDefaultValues(): void;

    /**
     * Sets whether next delta time equals to zero
     * @param {Boolean} nextDeltaTimeZero
     */
    setNextDeltaTimeZero(nextDeltaTimeZero: boolean): void;

    /**
     * Starts the registered next scene
     */
    setNextScene(): void;
    /**
     * Sets Notification Node
     * @param {cc.Node} node
     */
    setNotificationNode(node: Node): void;

    /**
     * Returns the cc.director delegate.
     * @return {cc.DirectorDelegate}
     */
    getDelegate(): DirectorDelegate;

    /**
     * Sets the cc.director delegate. It shall implement the CCDirectorDelegate protocol
     * @return {cc.DirectorDelegate}
     */
    setDelegate(delegate: DirectorDelegate): void;

    /**
     * Sets the view, where everything is rendered, do not call this function.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     * @param {cc.view} openGLView
     */
    setOpenGLView(openGLView: EGLView): void;

    /**
     * Sets an OpenGL projection.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     * @param {Number} projection
     */
    setProjection(projection: number): void;

    /**
     * Update the view port.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     */
    setViewport(): void;

    /**
     * Get the CCEGLView, where everything is rendered.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     * @return {cc.view}
     */
    getOpenGLView(): EGLView;

    /**
     * Sets an OpenGL projection.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     * @return {Number}
     */
    getProjection(): number;

    /**
     * Enables/disables OpenGL alpha blending.<br/>
     * Implementation can be found in CCDirectorCanvas.js/CCDirectorWebGL.js.
     * @function
     * @param {Boolean} on
     */
    setAlphaBlending(on: boolean): void;

    /**
     * Returns whether or not the replaced scene will receive the cleanup message.<br>
     * If the new scene is pushed, then the old scene won't receive the "cleanup" message.<br/>
     * If the new scene replaces the old one, the it will receive the "cleanup" message.
     * @return {Boolean}
     */
    isSendCleanupToScene(): boolean;

    /**
     * Returns current running Scene. Director can only run one Scene at the time
     * @return {cc.Scene}
     */
    getRunningScene<T>(): T extends Scene ? T : Scene;

    /**
     * Returns the FPS value
     * @return {Number}
     */
    getAnimationInterval(): number;

    /**
     * Returns whether or not to display the FPS informations
     * @return {Boolean}
     */
    isDisplayStats(): boolean;

    /**
     * Sets whether display the FPS on the bottom-left corner
     * @param {Boolean} displayStats
     */
    setDisplayStats(displayStats: boolean): void;

    /**
     * Returns seconds per frame
     * @return {Number}
     */
    getSecondsPerFrame(): number;
    /**
     * Returns whether next delta time equals to zero
     * @return {Boolean}
     */
    isNextDeltaTimeZero(): boolean;

    /**
     * Returns whether or not the Director is paused
     * @return {Boolean}
     */
    isPaused(): boolean;

    /**
     * Returns how many frames were called since the director started
     * @return {Number}
     */
    getTotalFrames(): number;

    /**
     * Pops out all scenes from the queue until the root scene in the queue. <br/>
     * This scene will replace the running one.  <br/>
     * Internally it will call "popToSceneStackLevel(1)"
     */
    popToRootScene(): void;

    /**
     * Pops out all scenes from the queue until it reaches "level".                             <br/>
     * If level is 0, it will end the director.                                                 <br/>
     * If level is 1, it will pop all scenes until it reaches to root scene.                    <br/>
     * If level is <= than the current stack level, it won't do anything.
     * @param {Number} level
     */
    popToSceneStackLevel(level: number): void;

    /**
     * Returns the cc.Scheduler associated with this director
     * @return {cc.Scheduler}
     */
    getScheduler(): Scheduler;

    /**
     * Sets the cc.Scheduler associated with this director
     * @param {cc.Scheduler} scheduler
     */
    setScheduler(scheduler: Scheduler): void;

    /**
     * Returns the cc.ActionManager associated with this director
     * @return {cc.ActionManager}
     */
    getActionManager(): ActionManager;
    /**
     * Sets the cc.ActionManager associated with this director
     * @param {cc.ActionManager} actionManager
     */
    setActionManager(actionManager: ActionManager): void;

    /**
     * Returns the delta time since last frame
     * @return {Number}
     */
    getDeltaTime(): number;

    getEventDispatcher(): eventManager;
    getTextureCache(): any;
  }
  //#endregion cocos2d/CCDirector.js

  //#region cocos2d/CCDrawingPrimitives.js
  /**
   * <p>
   *   Drawing primitives Utility Class. this class is base class, it contain some render type version: Canvas, WebGL, DOM.<br/>
   *   this class contain some primitive Drawing Method: <br/>
   *     - drawPoint<br/>
   *     - drawLine<br/>
   *     - drawPoly<br/>
   *     - drawCircle<br/>
   *     - drawQuadBezier<br/>
   *     - drawCubicBezier<br/>
   *     You can change the color, width and other property by calling these WebGL API:<br/>
   *     glColor4ub(), glLineWidth(), glPointSize().<br/>
   * </p>
   * @class
   * @extends cc.Class
   * @warning These functions draws the Line, Point, Polygon, immediately. They aren't batched. <br/>
   *   If you are going to make a game that depends on these primitives, I suggest creating a batch.
   */
  export class DrawingPrimitive extends Class {
    /**
     * set render context of drawing primitive
     * @param context
     */
    setRenderContext(context: CanvasRenderingContext2D): void;

    /**
     * returns render context of drawing primitive
     * @return {CanvasContext}
     */
    getRenderContext(): CanvasRenderingContext2D;

    /**
     * Constructor
     * @param {CanvasContext} renderContext
     */
    constructor(renderContext: CanvasRenderingContext2D);

    /**
     * draws a point given x and y coordinate measured in points
     * @param {cc.Point} point
     */
    drawPoint(point: Point): void;

    /**
     * draws an array of points.
     * @param {Array} points point of array
     * @param {Number} numberOfPoints
     */
    drawPoints(points: Point[], numberOfPoints: number): void;

    /**
     * draws a line given the origin and destination point measured in points
     * @param {cc.Point} origin
     * @param {cc.Point} destination
     */
    drawLine(origin: Point, destination: Point): void;

    /**
     * draws a rectangle given the origin and destination point measured in points.
     * @param {cc.Point} origin
     * @param {cc.Point} destination
     */
    drawRect(origin: Point, destination: Point): void;

    /**
     * draws a solid rectangle given the origin and destination point measured in points.
     * @param {cc.Point} origin
     * @param {cc.Point} destination
     * @param {cc.Color4F} color
     */
    drawSolidRect(origin: Point, destination: Point, color: Color4F): void;

    /**
     * draws a poligon given a pointer to cc.Point coordiantes and the number of vertices measured in points.
     * @param {Array} vertices a pointer to cc.Point coordiantes
     * @param {Number} numOfVertices the number of vertices measured in points
     * @param {Boolean} closePolygon The polygon can be closed or open
     * @param {Boolean} fill The polygon can be closed or open and optionally filled with current color
     */
    drawPoly(
      vertices: Point[],
      numOfVertices: number,
      closePolygon: boolean,
      fill: boolean,
    ): void;

    /**
     * draws a solid polygon given a pointer to CGPoint coordiantes, the number of vertices measured in points, and a color.
     * @param {Array} poli
     * @param {Number} numberOfPoints
     * @param {cc.Color4F} color
     */
    drawSolidPoly(poli: Point[], numberOfPoints: number, color: Color4F): void;

    /**
     * draws a circle given the center, radius and number of segments.
     * @param {cc.Point} center center of circle
     * @param {Number} radius
     * @param {Number} angle angle in radians
     * @param {Number} segments
     * @param {Boolean} drawLineToCenter
     */
    drawCircle(
      center: Point,
      radius: number,
      angle: number,
      segments: number,
      drawLineToCenter: boolean,
    ): void;

    /**
     * draws a quad bezier path
     * @param {cc.Point} origin
     * @param {cc.Point} control
     * @param {cc.Point} destination
     * @param {Number} segments
     */
    drawQuadBezier(
      origin: Point,
      control: Point,
      destination: Point,
      segments: number,
    ): void;

    /**
     * draws a cubic bezier path
     * @param {cc.Point} origin
     * @param {cc.Point} control1
     * @param {cc.Point} control2
     * @param {cc.Point} destination
     * @param {Number} segments
     */
    drawCubicBezier(
      origin: Point,
      control1: Point,
      control2: Point,
      destination: Point,
      segments: number,
    ): void;

    /**
     * draw a catmull rom line
     * @param {cc.PointArray} points
     * @param {Number} segments
     */
    drawCatmullRom(points: Point[], segments: number): void;

    /**
     * draw a cardinal spline path
     * @param {cc.PointArray} config
     * @param {Number} tension
     * @param {Number} segments
     */
    drawCardinalSpline(
      config: Point[],
      tension: number,
      segments: number,
    ): void;

    // FIXME: Typescript doesn't support abstract classes so we have to put the common
    // methods from DrawingPrimitiveCanvas and DrawingPrimitiveWebGL here for convenience

    /**
     * set the drawing color with 4 unsigned bytes
     * @param {Number} r red value (0 to 255)
     * @param {Number} r green value (0 to 255)
     * @param {Number} r blue value (0 to 255)
     * @param {Number} a Alpha value (0 to 255)
     */
    setDrawColor4B(r: number, g: number, b: number, a: number): void;

    // ENDFIXME
  }

  /**
   * Canvas of DrawingPrimitive implement version
   * @class
   * @extends cc.DrawingPrimitive
   */
  export class DrawingPrimitiveCanvas extends DrawingPrimitive {}

  /**
   * Canvas of DrawingPrimitive implement version
   * @class
   * @extends cc.DrawingPrimitive
   */
  export class DrawingPrimitiveWebGL extends DrawingPrimitive {}
  //#endregion cocos2d/CCDrawingPrimitives.js

  //#region cocos2d/CCLoader.js
  /**
   * A class to pre-load resources before engine start game main loop.
   * @class
   * @extends cc.Scene
   */
  // export class Loader extends Class {
  //   /**
  //    * Preload resources in the background
  //    * @param {Array} resources
  //    * @param {Function|String} selector
  //    * @param {Object} target
  //    * @return {cc.Loader}
  //    * @example
  //    * //example
  //    * var g_mainmenu = [
  //    *    {src:"res/hello.png"},
  //    *    {src:"res/hello.plist"},
  //    *
  //    *    {src:"res/logo.png"},
  //    *    {src:"res/btn.png"},
  //    *
  //    *    {src:"res/boom.mp3"},
  //    * ]
  //    *
  //    * var g_level = [
  //    *    {src:"res/level01.png"},
  //    *    {src:"res/level02.png"},
  //    *    {src:"res/level03.png"}
  //    * ]
  //    *
  //    * //load a list of resources
  //    * cc.Loader.preload(g_mainmenu, this.startGame, this);
  //    *
  //    * //load multi lists of resources
  //    * cc.Loader.preload([g_mainmenu,g_level], this.startGame, this);
  //    */
  //   static preload(
  //     resources: any[],
  //     selector: () => void,
  //     target: Node,
  //   ): Loader;
  // }

  /**
   * Used to display the loading screen
   * @class
   * @extends cc.Scene
   */
  // export class LoaderScene extends Scene {
  //   /**
  //    * Preload multi scene resources.
  //    * @param {Array} resources
  //    * @param {Function|String} selector
  //    * @param {Object} target
  //    * @return {cc.LoaderScene}
  //    * @example
  //    * //example
  //    * var g_mainmenu = [
  //    *    {src:"res/hello.png"},
  //    *    {src:"res/hello.plist"},
  //    *
  //    *    {src:"res/logo.png"},
  //    *    {src:"res/btn.png"},
  //    *
  //    *    {src:"res/boom.mp3"},
  //    * ]
  //    *
  //    * var g_level = [
  //    *    {src:"res/level01.png"},
  //    *    {src:"res/level02.png"},
  //    *    {src:"res/level03.png"}
  //    * ]
  //    *
  //    * //load a list of resources
  //    * cc.LoaderScene.preload(g_mainmenu, this.startGame, this);
  //    *
  //    * //load multi lists of resources
  //    * cc.LoaderScene.preload([g_mainmenu,g_level], this.startGame, this);
  //    */
  //   static preload(
  //     resources: any[],
  //     selector: () => void,
  //     target: any,
  //   ): LoaderScene;
  // }
  //#endregion cocos2d/CCLoader.js

  //#region cocos2d/CCScheduler.js
  /**
   * <p>
   *    Scheduler is responsible of triggering the scheduled callbacks.<br/>
   *    You should not use NSTimer. Instead use this class.<br/>
   *    <br/>
   *    There are 2 different types of callbacks (selectors):<br/>
   *       - update selector: the 'update' selector will be called every frame. You can customize the priority.<br/>
   *       - custom selector: A custom selector will be called every frame, or with a custom interval of time<br/>
   *       <br/>
   *    The 'custom selectors' should be avoided when possible. It is faster, and consumes less memory to use the 'update selector'. *
   * </p>
   * @class
   * @extends cc.Class
   *
   * @example
   * //register a schedule to scheduler
   * cc.Director.getInstance().getScheduler().scheduleSelector(selector, this, interval, !this._isRunning);
   */

  //#endregion cocos2d/CCScheduler.js

  //#region cocos2d/actions/CCAction.js
  /**
   * Base class for cc.Action objects.
   * @class
   * @extends cc.Class
   */
  export class Action extends Class {
    release(): void;
    retain(): void;
    getReferenceCount(): number;
  }

  /**
     * <p>Base class actions that do have a finite time duration.<br/>
     * Possible actions: <br/>
     * - An action with a duration of 0 seconds<br/>
     * - An action with a duration of 35.5 seconds  </p>

     * Infinite time actions are valid
     * @class
     * @extends cc.Action
     */
  export class FiniteTimeAction extends Action {}
  //#endregion cocos2d/actions/CCAction.js

  //#region cocos2d/actions/CCActionInterval.js
  /**
   * <p> An interval action is an action that takes place within a certain period of time. <br/>
   * It has an start time, and a finish time. The finish time is the parameter<br/>
   * duration plus the start time.</p>
   *
   * <p>These CCActionInterval actions have some interesting properties, like:<br/>
   * - They can run normally (default)  <br/>
   * - They can run reversed with the reverse method   <br/>
   * - They can run with the time altered with the Accelerate, AccelDeccel and Speed actions. </p>
   *
   * <p>For example, you can simulate a Ping Pong effect running the action normally and<br/>
   * then running it again in Reverse mode. </p>
   *
   * @class
   * @extends cc.FiniteTimeAction
   * @Example
   * // example
   * var pingPongAction = cc.Sequence.create(action, action.reverse());
   */
  export class ActionInterval extends FiniteTimeAction {
    setTag(tag: number): void;
    easing(action: any): ActionInterval;
  }

  /** Runs actions sequentially, one after another
   * @class
   * @extends cc.ActionInterval
   */
  export class Sequence extends ActionInterval {
    /** helper constructor to create an array of sequenceable actions
     * @param {Array|cc.FiniteTimeAction} tempArray
     * @return {cc.FiniteTimeAction}
     * @example
     * // example
     * // create sequence with actions
     * var seq = cc.Sequence.create(act1, act2);
     *
     * // create sequence with array
     * var seq = cc.Sequence.create(actArray);
     */
    static create(...rest: FiniteTimeAction[]): Sequence;
  }

  /** Repeats an action a number of times.
   * To repeat an action forever use the CCRepeatForever action.
   * @class
   * @extends cc.ActionInterval
   */
  export class Repeat extends ActionInterval {
    /** creates a CCRepeat action. Times is an unsigned integer between 1 and pow(2,30)
     * @param {cc.FiniteTimeAction} action
     * @param {Number} times
     * @return {cc.Repeat}
     * @example
     * // example
     * var rep = cc.Repeat.create(cc.Sequence.create(jump2, jump1), 5);
     */
    static create(action: FiniteTimeAction, times: number): Repeat;
  }

  /**  Repeats an action for ever.  <br/>
   * To repeat the an action for a limited number of times use the Repeat action. <br/>
   * @warning This action can't be Sequenceable because it is not an IntervalAction
   * @class
   * @extends cc.ActionInterval
   */
  export class RepeatForever extends ActionInterval {
    /**
     * Repeat the acton forever
     * @param action
     * @return {cc.RepeatForever}
     * @example
     * // example
     * var repeat = cc.RepeatForever.create(cc.RotateBy.create(1.0, 360));
     */
    static create(action: FiniteTimeAction): RepeatForever;
  }

  /** Spawn a new action immediately
   * @class
   * @extends cc.ActionInterval
   */
  export class Spawn extends ActionInterval {
    /**
     * @param {Array|cc.FiniteTimeAction}tempArray
     * @return {cc.FiniteTimeAction}
     * @example
     * // example
     * var action = cc.Spawn.create(cc.JumpBy.create(2, cc.p(300, 0), 50, 4), cc.RotateBy.create(2, 720));
     */
    static create(...rest: FiniteTimeAction[]): Spawn;
  }

  /** Rotates a cc.Node object to a certain angle by modifying it's
   * rotation attribute. <br/>
   * The direction will be decided by the shortest angle.
   * @class
   * @extends cc.ActionInterval
   */
  export class RotateTo extends ActionInterval {
    /**
     * creates the action with separate rotation angles
     * @param {Number} duration duration in seconds
     * @param {Number} deltaAngleX deltaAngleX in degrees.
     * @param {Number} deltaAngleY deltaAngleY in degrees.
     * @return {cc.RotateTo}
     * @example
     * // example
     * var rotateTo = cc.RotateTo.create(2, 61.0);
     */
    static create(
      duration: number,
      deltaAngleX: number,
      deltaAngleY?: number,
    ): RotateTo;
  }

  /** Rotates a cc.Node object clockwise a number of degrees by modifying it's rotation attribute.
   * @class
   * @extends  cc.ActionInterval
   */
  export class RotateBy extends ActionInterval {
    /**
     * @param {Number} duration druation in seconds
     * @param {Number} deltaAngleX deltaAngleX in degrees
     * @param {Number} deltaAngleY deltaAngleY in degrees
     * @return {cc.RotateBy}
     * @example
     * // example
     * var actionBy = cc.RotateBy.create(2, 360);
     */
    static create(
      duration: number,
      deltaAngleX: number,
      deltaAngleY: number,
    ): RotateBy;
  }

  /** Moves a cc.Node object to the position x,y. x and y are absolute coordinates by modifying it's position attribute.
   * @class
   * @extends cc.ActionInterval
   */
  export class MoveTo extends ActionInterval {
    /**
     * @param {Number} duration duration in seconds
     * @param {cc.Point} position
     * @return {cc.MoveTo}
     * @example
     * // example
     * var actionTo = cc.MoveTo.create(2, cc.p(windowSize.width - 40, windowSize.height - 40));
     */
    static create(duration: number, position: Point): MoveTo;
  }

  /** Moves a cc.Node object x,y pixels by modifying it's position attribute. <br/>
   * x and y are relative to the position of the object. <br/>
   * @class
   * @extends cc.MoveTo
   */
  export class MoveBy extends MoveTo {
    /**
     * @param {Number} duration duration in seconds
     * @param {cc.Point} position
     * @return {cc.MoveBy}
     * @example
     * // example
     * var actionBy = cc.MoveBy.create(2, cc.p(80, 80));
     */
    static create(duration: number, position: Point): MoveBy;
  }

  /** Skews a cc.Node object to given angles by modifying it's skewX and skewY attributes
   * @class
   * @extends cc.ActionInterval
   */
  export class SkewTo extends ActionInterval {
    /**
     * @param {Number} t time in seconds
     * @param {Number} sx
     * @param {Number} sy
     * @return {cc.SkewTo}
     * @example
     * // example
     * var actionTo = cc.SkewTo.create(2, 37.2, -37.2);
     */
    static create(t: number, sx: number, sy: number): SkewTo;
  }

  /** Skews a cc.Node object by skewX and skewY degrees
   * @class
   * @extends cc.SkewTo
   */
  export class SkewBy extends SkewTo {
    /**
     * @param {Number} t time in seconds
     * @param {Number} sx sx skew in degrees for X axis
     * @param {Number} sy sy skew in degrees for Y axis
     * @return {cc.SkewBy}
     * @example
     * // example
     * var actionBy = cc.SkewBy.create(2, 0, -90);
     */
    static create(t: number, sx: number, sy: number): SkewBy;
  }

  /**  Moves a cc.Node object simulating a parabolic jump movement by modifying it's position attribute.
   * @class
   * @extends cc.ActionInterval
   */
  export class JumpBy extends ActionInterval {
    /**
     * @param {Number} duration
     * @param {cc.Point} position
     * @param {Number} height
     * @param {Number} jumps
     * @return {cc.JumpBy}
     * @example
     * // example
     * var actionBy = cc.JumpBy.create(2, cc.p(300, 0), 50, 4);
     */
    static create(
      duration: number,
      position: Point,
      height: number,
      jumps: number,
    ): JumpBy;
  }

  /**  Moves a cc.Node object to a parabolic position simulating a jump movement by modifying it's position attribute.
   * @class
   * @extends cc.JumpBy
   */
  export class JumpTo extends JumpBy {
    /**
     * @param {Number} duration
     * @param {cc.Point} position
     * @param {Number} height
     * @param {Number} jumps
     * @return {cc.JumpTo}
     * @example
     * // example
     * var actionTo = cc.JumpTo.create(2, cc.p(300, 300), 50, 4);
     */
    static create(
      duration: number,
      position: Point,
      height: number,
      jumps: number,
    ): JumpTo;
  }

  /** An action that moves the target with a cubic Bezier curve by a certain distance.
   * @class
   * @extends cc.ActionInterval
   */
  export class BezierBy extends ActionInterval {
    /**
     * @param {Number} t time in seconds
     * @param {Array} c Array of points
     * @return {cc.BezierBy}
     * @example
     * // example
     * var bezier = [cc.p(0, windowSize.height / 2), cc.p(300, -windowSize.height / 2), cc.p(300, 100)];
     * var bezierForward = cc.BezierBy.create(3, bezier);
     *
     */
    static create(t: number, c: Point[]): BezierBy;
  }

  /** An action that moves the target with a cubic Bezier curve to a destination point.
   * @class
   * @extends cc.BezierBy
   */
  export class BezierTo extends BezierBy {
    /**
     * @param {Number} t
     * @param {Array} c array of points
     * @return {cc.BezierTo}
     * @example
     * // example
     * var bezier = [cc.p(0, windowSize.height / 2), cc.p(300, -windowSize.height / 2), cc.p(300, 100)];
     * var bezierTo = cc.BezierTo.create(2, bezier);
     */
    static create(t: number, c: Point[]): BezierTo;
  }

  /** Scales a cc.Node object to a zoom factor by modifying it's scale attribute.
   * @warning This action doesn't support "reverse"
   * @class
   * @extends cc.ActionInterval
   */
  export class ScaleTo extends ActionInterval {
    /**
     * @param {Number} duration
     * @param {Number} sx  scale parameter in X
     * @param {Number|Null} sy scale parameter in Y, if Null equal to sx
     * @return {cc.ScaleTo}
     * @example
     * // example
     * // It scales to 0.5 in both X and Y.
     * var actionTo = cc.ScaleTo.create(2, 0.5);
     *
     * // It scales to 0.5 in x and 2 in Y
     * var actionTo = cc.ScaleTo.create(2, 0.5, 2);
     */
    static create(duration: number, sx: number, sy?: number): ScaleTo;
  }

  /** Scales a cc.Node object a zoom factor by modifying it's scale attribute.
   * @class
   * @extends cc.ScaleTo
   */
  export class ScaleBy extends ScaleTo {
    /**
     * @param {Number} duration duration in seconds
     * @param {Number} sx sx  scale parameter in X
     * @param {Number|Null} sy sy scale parameter in Y, if Null equal to sx
     * @return {cc.ScaleBy}
     * @example
     * // example without sy, it scales by 2 both in X and Y
     * var actionBy = cc.ScaleBy.create(2, 2);
     *
     * //example with sy, it scales by 0.25 in X and 4.5 in Y
     * var actionBy2 = cc.ScaleBy.create(2, 0.25, 4.5);
     */
    static create(duration: number, sx: number, sy?: number): ScaleBy;
  }

  /** Blinks a cc.Node object by modifying it's visible attribute
   * @class
   * @extends cc.ActionInterval
   */
  export class Blink extends ActionInterval {
    /**
     * @param {Number} duration  duration in seconds
     * @param blinks blinks in times
     * @return {cc.Blink}
     * @example
     * // example
     * var action = cc.Blink.create(2, 10);
     */
    static create(duration: number, blinks: number): Blink;
  }

  /** Fades In an object that implements the cc.RGBAProtocol protocol. It modifies the opacity from 0 to 255.<br/>
   * The "reverse" of this action is FadeOut
   * @class
   * @extends cc.ActionInterval
   */
  export class FadeIn extends ActionInterval {
    /**
     * @param {Number} duration duration in seconds
     * @return {cc.FadeIn}
     * @example
     * //example
     * var action = cc.FadeIn.create(1.0);
     */
    static create(duration: number): FadeIn;
  }

  /** Fades Out an object that implements the cc.RGBAProtocol protocol. It modifies the opacity from 255 to 0.
   * The "reverse" of this action is FadeIn
   * @class
   * @extends cc.ActionInterval
   */
  export class FadeOut extends ActionInterval {
    /**
     * @param {Number} d  duration in seconds
     * @return {cc.FadeOut}
     * @example
     * // example
     * var action = cc.FadeOut.create(1.0);
     */
    static create(d: number): FadeOut;
  }

  /** Fades an object that implements the cc.RGBAProtocol protocol. It modifies the opacity from the current value to a custom one.
   * @warning This action doesn't support "reverse"
   * @class
   * @extends cc.ActionInterval
   */
  export class FadeTo extends ActionInterval {
    /**
     * @param {Number} duration
     * @param {Number} opacity 0-255, 0 is transparent
     * @return {cc.FadeTo}
     * @example
     * // example
     * var action = cc.FadeTo.create(1.0, 0);
     */
    static create(duration: number, opacity: number): FadeTo;
  }

  /** Tints a cc.Node that implements the cc.NodeRGB protocol from current tint to a custom one.
   * @warning This action doesn't support "reverse"
   * @class
   * @extends cc.ActionInterval
   */
  export class TintTo extends ActionInterval {
    /**
     * @param {Number} duration
     * @param {Number} red 0-255
     * @param {Number} green  0-255
     * @param {Number} blue 0-255
     * @return {cc.TintTo}
     * @example
     * // example
     * var action = cc.TintTo.create(2, 255, 0, 255);
     */
    static create(
      duration: number,
      red: number,
      green: number,
      blue: number,
    ): TintTo;
  }

  /**  Tints a cc.Node that implements the cc.NodeRGB protocol from current tint to a custom one.
   * @class
   * @extends cc.ActionInterval
   */
  export class TintBy extends ActionInterval {
    /**
     * @param {Number} duration  duration in seconds
     * @param {Number} deltaRed
     * @param {Number} deltaGreen
     * @param {Number} deltaBlue
     * @return {cc.TintBy}
     * @example
     * // example
     * var action = cc.TintBy.create(2, -127, -255, -127);
     */
    static create(
      duration: number,
      deltaRed: number,
      deltaGreen: number,
      deltaBlue: number,
    ): TintBy;
  }

  /** Delays the action a certain amount of seconds
   * @class
   * @extends cc.ActionInterval
   */
  export class DelayTime extends ActionInterval {
    /**
     * @param {Number} d duration in seconds
     * @return {cc.DelayTime}
     * @example
     * // example
     * var delay = cc.DelayTime.create(1);
     */
    static create(d: number): DelayTime;
  }

  /**
   * Executes an action in reverse order, from time=duration to time=0
   * @warning Use this action carefully. This action is not
   * sequenceable. Use it as the default "reversed" method
   * of your own actions, but using it outside the "reversed"
   * scope is not recommended.
   * @class
   * @extends cc.ActionInterval
   */
  export class ReverseTime extends ActionInterval {
    /**
     * @param {cc.FiniteTimeAction} action
     * @return {cc.ReverseTime}
     * @example
     * // example
     *  var reverse = cc.ReverseTime.create(this);
     */
    static create(action: FiniteTimeAction): ReverseTime;
  }

  /**  Animates a sprite given the name of an Animation
   * @class
   * @extends cc.ActionInterval
   */
  export class Animate extends ActionInterval {
    /**
     * create the animate with animation
     * @param {cc.Animation} animation
     * @return {cc.Animate}
     * @example
     * // example
     * // create the animation with animation
     * var anim = cc.Animate.create(dance_grey);
     */
    static create(animation: Animation): Animate;
    /**
     * Repeats an action for ever.  <br/>
     * To repeat the an action for a limited number of times use the Repeat action. <br/>
     * @returns {cc.ActionInterval}
     */
    repeatForever(): ActionInterval;
  }
  //#endregion cocos2d/actions/CCActionInterval.js

  //#region cocos2d/actions/CCActionManager.js

  /**
   * <p>
   *     Overrides the target of an action so that it always runs on the target<br/>
   *     specified at action creation rather than the one specified by runAction.
   * </p>
   * @class
   * @extends cc.ActionInterval
   */
  export class TargetedAction extends ActionInterval {}
  //#endregion cocos2d/actions/CCActionManager.js

  //#region cocos2d/base_nodes/CCNode.js
  /** <p>cc.Node is the main element. Anything thats gets drawn or contains things that get drawn is a cc.Node.<br/>
     The most popular cc.Nodes are: cc.Scene, cc.Layer, cc.Sprite, cc.Menu. (WebGL implement)<br/></p>

     <p>The main features of a cc.Node are: <br/>
     - They can contain other cc.Node nodes (addChild, getChildByTag, removeChild, etc) <br/>
     - They can schedule periodic callback (schedule, unschedule, etc) <br/>
     - They can execute actions (runAction, stopAction, etc) <br/></p>

     <p>Some cc.Node nodes provide extra functionality for them or their children.</p>

     <p>Subclassing a cc.Node usually means (one/all) of: <br/>
     - overriding init to initialize resources and schedule callbacks  <br/>
     - create callbacks to handle the advancement of time <br/>
     - overriding draw to render the node   <br/></p>

     <p>Features of cc.Node: <br/>
     - position  <br/>
     - scale (x, y) <br/>
     - rotation (in degrees, clockwise) <br/>
     - cc.Camera (an interface to gluLookAt ) <br/>
     - cc.GridBase (to do mesh transformations)  <br/>
     - anchor point<br/>
     - size <br/>
     - visible<br/>
     - z-order <br/>
     - openGL z position <br/></P>

     <p> Default values: <br/>
     - rotation: 0 <br/>
     - position: (x=0,y=0) <br/>
     - scale: (x=1,y=1) <br/>
     - contentSize: (x=0,y=0)<br/>
     - anchorPoint: (x=0,y=0)<br/></p>

     <p> Limitations:<br/>
     - A cc.Node is a "void" object. It doesn't have a texture <br/></P>

     <p>Order in transformations with grid disabled <br/>
     -# The node will be translated (position)  <br/>
     -# The node will be rotated (rotation)<br/>
     -# The node will be scaled (scale)  <br/>
     -# The node will be moved according to the camera values (camera) <br/></p>

     <p>Order in transformations with grid enabled<br/>
     -# The node will be translated (position)<br/>
     -# The node will be rotated (rotation) <br/>
     -# The node will be scaled (scale) <br/>
     -# The grid will capture the screen <br/>
     -# The node will be moved according to the camera values (camera) <br/>
     -# The grid will render the captured screen <br/></P>

     <p>Camera:  <br/>
     - Each node has a camera. By default it points to the center of the cc.Node.</P>
     * @class
     * @extends cc.Class
     * @example
     * // example
     * cc.Sprite = cc.Node.extend({});
     * cc.Sprite.initWithImage = function(){
     * };
     */

  class ProtectedNode extends Node {}
  //#endregion cocos2d/base_nodes/CCNode.js

  //#region cocos2d/cocoa/CCAffineTranform.js
  /**
   * @function
   * @param {Number} a
   * @param {Number} b
   * @param {Number} c
   * @param {Number} d
   * @param {Number} tx
   * @param {Number} ty
   */
  export class AffineTransform {
    a: number;
    b: number;
    c: number;
    d: number;
    tx: number;
    ty: number;
    constructor(
      a: number,
      b: number,
      c: number,
      d: number,
      tx: number,
      ty: number,
    );
  }
  //#endregion cocos2d/cocoa/CCAffineTranform.js

  //#region cocos2d/cocoa/CCGeometry.js
  /**
   * @class
   * @param {Number} _x
   * @param {Number} _y
   * Constructor
   */
  export class Point {
    x: number;
    y: number;

    constructor(_x: number, _y: number);
  }

  /**
   * Helper macro that creates a cc.Point.
   * @param {Number} x
   * @param {Number} y
   */
  function p(x: number | Point, y?: number): Point;

  /**
   * The "left bottom" point -- equivalent to cc.p(0, 0).
   * @function
   * @return {cc.Point}
   */
  function PointZero(): Point;

  /**
   * @class
   * @param {Number} _width
   * @param {Number} _height
   * Constructor
   */
  export class Size {
    width: number;
    height: number;

    constructor(_width: number, _height: number);
  }

  /**
   * @function
   * @param {Number} w width
   * @param {Number} h height
   * @return {cc.Size}
   */
  function size(w: number, h: number): Size;

  /**
   * @class
   * @param {Number} x1
   * @param {Number} y1
   * @param {Number} width1
   * @param {Number} height1
   * Constructor
   */
  export class Rect {
    x: number;
    y: number;
    width: number;
    height: number;

    constructor(x1: number, y1: number, width1: number, height1: number);
  }

  function rect(x1: number, y1: number, width1: number, height1: number): Rect;

  /**
   * @function
   * @param {Number} x
   * @param {Number} y
   * @param {Number} width
   * @param {Number} height
   * @return {cc.Rect}
   */
  function RectMake(x: number, y: number, width: number, height: number): Rect;

  // backward compatible
  function rect(x: number, y: number, w: number, h: number): Rect;

  /**
   * The "zero" rectangle -- equivalent to cc.rect(0, 0, 0, 0).
   * @function
   * @return {cc.Rect}
   */
  function RectZero(): Rect;

  /**
   * @function
   * @param {cc.Rect} rect1
   * @param {cc.Rect} rect2
   * @return {Boolean}
   */
  function rectEqualToRect(rect1: Rect, rect2: Rect): boolean;

  /**
   * @function
   * @param {cc.Rect} rect1
   * @param {cc.Rect} rect2
   * @return {Boolean}
   */
  function rectContainsRect(rect1: Rect, rect2: Rect): boolean;

  /**
   * return the rightmost x-value of 'rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMaxX(rect: Rect): number;

  /**
   * return the midpoint x-value of 'rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMidX(rect: Rect): number;

  /**
   * return the leftmost x-value of 'rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMinX(rect: Rect): number;

  /**
   * Return the topmost y-value of `rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMaxY(rect: Rect): number;

  /**
   * Return the midpoint y-value of `rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMidY(rect: Rect): number;

  /**
   * Return the bottommost y-value of `rect'
   * @function
   * @param {cc.Rect} rect
   * @return {Number}
   */
  function rectGetMinY(rect: Rect): number;

  /**
   * @function
   * @param {cc.Rect} rect
   * @param {cc.Point} point
   * @return {Boolean}
   */
  function rectContainsPoint(rect: Rect, point: Point): boolean;

  /**
   * @function
   * @param {cc.Rect} rectA
   * @param {cc.Rect} rectB
   * @return {Boolean}
   */
  function rectIntersectsRect(rectA: Rect, rectB: Rect): boolean;

  /**
   * @function
   * @param {cc.Rect} rectA
   * @param {cc.Rect} rectB
   * @return {Boolean}
   */
  function rectOverlapsRect(rectA: Rect, rectB: Rect): boolean;

  /**
   * Returns the smallest rectangle that contains the two source rectangles.
   * @function
   * @param {cc.Rect} rectA
   * @param {cc.Rect} rectB
   * @return {cc.Rect}
   */
  function rectUnion(rectA: Rect, rectB: Rect): Rect;

  /**
   * Returns the overlapping portion of 2 rectangles
   * @function
   * @param {cc.Rect} rectA
   * @param {cc.Rect} rectB
   * @return {cc.Rect}
   */
  function rectIntersection(rectA: Rect, rectB: Rect): Rect;
  //#endregion cocos2d/cocoa/CCGeometry.js

  //#endregion cocos2d/label_nodes/CCLabelTTF.js

  //#region cocos2d/layers_scenes_transitions_nodes/CCScene.js
  /**
   * <p>cc.Scene is a subclass of cc.Node that is used only as an abstract concept.</p>
   *  <p>cc.Scene an cc.Node are almost identical with the difference that cc.Scene has it's
   * anchor point (by default) at the center of the screen.</p>
   *
   * <p>For the moment cc.Scene has no other logic than that, but in future releases it might have
   * additional logic.</p>
   *
   * <p>It is a good practice to use and cc.Scene as the parent of all your nodes.</p>
   * @class
   * @extends cc.Node
   */
  export class Scene extends Node {
    /**
     * Constructor
     */
    constructor();

    /**
     * creates a scene
     * @return {cc.Scene}
     * @example
     * // Example
     * var aScene = cc.Scene.create();
     * //OR
     * var aScene = new cc.Scene();
     */
    static create(t?: number, scene?: Scene): Scene;
  }
  //#endregion cocos2d/layers_scenes_transitions_nodes/CCScene.js

  //#region cocos2d/layers_scenes_transitions_nodes/CCLayer.js
  /** cc.Layer is a subclass of cc.Node that implements the TouchEventsDelegate protocol.<br/>
   * All features from cc.Node are valid, plus the following new features:<br/>
   * It can receive iPhone Touches<br/>
   * It can receive Accelerometer input
   * @class
   * @extends cc.Node
   */
  export class Layer extends Node {
    /**
     *
     * @return {Boolean}
     */
    init(...args: any[]): boolean;

    isMouseEnabled(): boolean;

    setMouseEnabled(enabled: boolean): void;

    setMousePriority(priority: number): void;

    getMousePriority(): number;

    /**
     * whether or not it will receive Touch events.<br/>
     * You can enable / disable touch events with this property.<br/>
     * Only the touches of this node will be affected. This "method" is not propagated to it's children.<br/>
     * @return {Boolean}
     */
    isTouchEnabled(): boolean;

    /**
     * Enable touch events
     * @param {Boolean} enabled
     */
    setTouchEnabled(enabled: boolean): void;

    /** returns the priority of the touch event handler
     * @return {Number}
     */
    getTouchPriority(): number;

    /** Sets the touch event handler priority. Default is 0.
     * @param {Number} priority
     */
    setTouchPriority(priority: number): void;

    /** returns the touch mode.
     * @return {Number}
     */
    getTouchMode(): number;

    /** Sets the touch mode.
     * @param {Number} mode
     */
    setTouchMode(mode: number): void;

    /**
     * whether or not it will receive Accelerometer events<br/>
     * You can enable / disable accelerometer events with this property.
     * @return {Boolean}
     */
    isAccelerometerEnabled(): boolean;

    /**
     * isAccelerometerEnabled setter
     * @param {Boolean} enabled
     */
    setAccelerometerEnabled(enabled: boolean): void;

    /**
     * accelerometerInterval setter
     * @param {Number} interval
     */
    setAccelerometerInterval(interval: number): void;

    onAccelerometer(accelerationValue: number): void;

    /**
     * whether or not it will receive keyboard events<br/>
     * You can enable / disable accelerometer events with this property.<br/>
     * it's new in cocos2d-x
     * @return {Boolean}
     */
    isKeyboardEnabled(): boolean;

    /**
     * Enable Keyboard interaction
     * @param {Boolean} enabled
     */
    setKeyboardEnabled(enabled: boolean): void;

    /**
     * This is run when ever a layer just become visible
     */
    onEnter(): void;

    /**
     * @function
     */
    onExit(): void;

    /**
     * this is called when ever a layer is a child of a scene that just finished a transition
     */
    onEnterTransitionDidFinish(): void;

    // ---------------------CCTouchDelegate interface------------------------------

    /**
     * default implements are used to call script callback if exist<br/>
     * you must override these touch functions if you wish to utilize them
     * @param {cc.Touch} touch
     * @param {event} event
     * @return {Boolean}
     */
    onTouchBegan(touch: Touch, event: TouchEvent): boolean;

    /**
     * callback when a touch event moved
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchMoved(touch: Touch, event: TouchEvent): void;

    /**
     * callback when a touch event finished
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchEnded(touch: Touch, event: TouchEvent): void;

    /**
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchCancelled(touch: Touch, event: TouchEvent): void;

    /**
     * Touches is the same as Touch, except this one can handle multi-touch
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchesBegan(touch: Touch, event: TouchEvent): void;

    /**
     * when a touch moved
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchesMoved(touch: Touch, event: TouchEvent): void;

    /**
     * when a touch finished
     * @param {cc.Touch} touch
     * @param {event} event
     */
    onTouchesEnded(touch: Touch, event: TouchEvent): void;

    /**
     * @param touch
     * @param event
     */
    onTouchesCancelled(touch: Touch, event: TouchEvent): void;

    // ---------------------CCMouseEventDelegate interface------------------------------

    /**
     * <p>called when the "mouseDown" event is received. <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onMouseDown(event: MouseEvent): boolean;

    /**
     * <p>called when the "mouseDragged" event is received.         <br/>
     * Return YES to avoid propagating the event to other delegates.</p>
     * @param event
     * @return {Boolean}
     */
    onMouseDragged(event: MouseEvent): boolean;

    /**
     * <p> called when the "mouseMoved" event is received.            <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onMouseMoved(event: MouseEvent): boolean;

    /**
     * <p> called when the "mouseUp" event is received.               <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onMouseUp(event: MouseEvent): boolean;

    //right
    /**
     * <p> called when the "rightMouseDown" event is received.        <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onRightMouseDown(event: MouseEvent): boolean;

    /**
     * <p> called when the "rightMouseDragged" event is received.    <br/>
     * Return YES to avoid propagating the event to other delegates. </p>
     * @param event
     * @return {Boolean}
     */
    onRightMouseDragged(event: MouseEvent): boolean;

    /**
     * <p> called when the "rightMouseUp" event is received.          <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onRightMouseUp(event: MouseEvent): boolean;

    //other
    /**
     * <p>called when the "otherMouseDown" event is received.         <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onOtherMouseDown(event: MouseEvent): boolean;

    /**
     * <p> called when the "otherMouseDragged" event is received.     <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onOtherMouseDragged(event?: any): boolean;

    /**
     * <p> called when the "otherMouseUp" event is received.          <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onOtherMouseUp(event?: any): boolean;

    //scroll wheel
    /**
     * <p> called when the "scrollWheel" event is received.           <br/>
     * Return YES to avoid propagating the event to other delegates.  </p>
     * @param event
     * @return {Boolean}
     */
    onScrollWheel(event?: any): boolean;

    // enter / exit
    /**
     *  <p> called when the "mouseEntered" event is received.         <br/>
     *  Return YES to avoid propagating the event to other delegates. </p>
     * @param theEvent
     * @return {Boolean}
     */
    onMouseEntered(theEvent?: any): boolean;

    /**
     * <p> called when the "mouseExited" event is received.          <br/>
     * Return YES to avoid propagating the event to other delegates. </p>
     * @param theEvent
     * @return {Boolean}
     */
    onMouseExited(theEvent?: any): boolean;

    // ---------------------CCKeyboardDelegate interface------------------------------

    /**
     * Call back when a key is pressed down
     * @param {Integer} keyCode
     * @example
     * // example
     * if(keyCode == cc.KEY.w){}
     */
    onKeyDown(keyCode: number): void;

    /**
     * Call back when a key is released
     * @param {Integer} keyCode
     * @example
     * // example
     * if(keyCode == cc.KEY.w){}
     */
    onKeyUp(keyCode: number): void;

    /**
     * creates a layer
     * @example
     * // Example
     * var myLayer = cc.Layer.create();
     * //Yes! it's that simple
     * @return {cc.Layer|Null}
     */
    static create(): Layer;
  }

  /**
   * creates a cc.LayerColorCanvas with color, width and height in Points
   * @param {cc.Color4B} color
   * @param {Number|Null} width
   * @param {Number|Null} height
   * @return {cc.LayerColor}
   * @example
   * // Example
   * //Create a yellow color layer as background
   * var yellowBackground = cc.LayerColor.create(cc.c4b(255,255,0,255));
   * //If you didnt pass in width and height, it defaults to the same size as the canvas
   *
   * //create a yellow box, 200 by 200 in size
   * var yellowBox = cc.LayerColorCanvas.create(cc.c3b(255,255,0,255), 200, 200);
   */
  export class LayerColor extends Layer {
    /**
     * @param {cc.Color4B} color
     * @param {Number} width
     * @param {Number} height
     * @return {Boolean}
     */
    init(
      ...args: any[] /*color: Color4B, width: number, height: number*/
    ): boolean;

    static create(color?: Color4B, width?: number, height?: number): LayerColor;
  }

  /**
   * <p>
   * CCLayerGradient is a subclass of cc.LayerColor that draws gradients across the background.<br/>
   *<br/>
   * All features from cc.LayerColor are valid, plus the following new features:<br/>
   * <ul><li>direction</li>
   * <li>final color</li>
   * <li>interpolation mode</li></ul>
   * <br/>
   * Color is interpolated between the startColor and endColor along the given<br/>
   * vector (starting at the origin, ending at the terminus).  If no vector is<br/>
   * supplied, it defaults to (0, -1) -- a fade from top to bottom.<br/>
   * <br/>
   * If 'compressedInterpolation' is disabled, you will not see either the start or end color for<br/>
   * non-cardinal vectors; a smooth gradient implying both end points will be still<br/>
   * be drawn, however.<br/>
   *<br/>
   * If 'compressedInterpolation' is enabled (default mode) you will see both the start and end colors of the gradient.
   * </p>
   * @class
   * @extends cc.LayerColor
   */
  export class LayerGradient extends LayerColor {
    /**
     * get the starting color
     * @return {cc.Color3B}
     */
    getStartColor(): Color3B;

    /**
     * set the starting color
     * @param {cc.Color3B} color
     * @example
     * // Example
     * myGradientLayer.setStartColor(cc.c3b(255,0,0));
     * //set the starting gradient to red
     */
    setStartColor(color: Color3B): void;

    /**
     * set the end gradient color
     * @param {cc.Color3B} color
     * @example
     * // Example
     * myGradientLayer.setEndColor(cc.c3b(255,0,0)): void;
     * //set the ending gradient to red
     */
    setEndColor(color: Color3B): void;

    /**
     * get the end color
     * @return {cc.Color3B}
     */
    getEndColor(): Color3B;

    /**
     * set starting gradient opacity
     * @param {Number} o from 0 to 255, 0 is transparent
     */
    setStartOpacity(o: number): void;

    /**
     * get the starting gradient opacity
     * @return {Number}
     */
    getStartOpacity(): number;

    /**
     * set the end gradient opacity
     * @param {Number} o
     */
    setEndOpacity(o: number): void;

    /**
     * get the end gradient opacity
     * @return {Number}
     */
    getEndOpacity(): number;

    /**
     * set vector
     * @param {cc.Point} Var
     */
    setVector(Var: Point): void;

    /**
     * @return {cc.Point}
     */
    getVector(): Point;

    /** is Compressed Interpolation
     * @return {Boolean}
     */
    isCompressedInterpolation(): boolean;

    /**
     * @param {Boolean} compress
     */
    setCompressedInterpolation(compress: boolean): void;

    /**
     * @param {cc.Color4B} start starting color
     * @param {cc.Color4B} end
     * @param {cc.Point|Null} v
     * @return {Boolean}
     */
    init(start: Color4B, end: Color4B, v?: Point): boolean;
  }
  //#endregion cocos2d/layers_scenes_transitions_nodes/CCLayer.js

  //#region cocos2d/layers_scenes_transitions_nodes/Transition.js
  /**
   * A tag constant for identifying fade scenes
   * @constant
   * @type Number
   */
  var SCENE_FADE: number;

  /**
   * cc.TransitionEaseScene can ease the actions of the scene protocol.
   * @class
   * @extends cc.Class
   */
  export class TransitionEaseScene extends Class {
    /**
     * returns the Ease action that will be performed on a linear action.
     */
    easeActionWithAction(): Action;
  }

  /**
   * horizontal orientation Type where the Left is nearer
   * @constant
   * @type Number
   */
  // var TRANSITION_ORIENTATION_LEFT_OVER: number;
  /**
   * horizontal orientation type where the Right is nearer
   * @constant
   * @type Number
   */
  // var TRANSITION_ORIENTATION_RIGHT_OVER: number;
  /**
   * vertical orientation type where the Up is nearer
   * @constant
   * @type Number
   */
  // var TRANSITION_ORIENTATION_UP_OVER: number;
  /**
   * vertical orientation type where the Bottom is nearer
   * @constant
   * @type Number
   */
  // var TRANSITION_ORIENTATION_DOWN_OVER: number;

  /**
   * @class
   * @extends cc.Scene
   */
  export class TransitionScene extends Scene {
    /**
     * custom onEnter
     */
    onEnter(): void;

    /**
     * custom onExit
     */
    onExit(): void;

    /**
     * custom cleanup
     */
    cleanup(): void;

    /**
     * initializes a transition with duration and incoming scene
     * @param {Number} t time in seconds
     * @param {cc.Scene} scene a scene to transit to
     * @return {Boolean} return false if error
     */
    initWithDuration(t: number, scene: Scene): boolean;

    /**
     * called after the transition finishes
     */
    finish(): void;

    /**
     * set hide the out scene and show in scene
     */
    hideOutShowIn(): void;
  }
  //#region cocos2d/layers_scenes_transitions_nodes/Transition.js

  //#region cocos2d/layers_scenes_transitions_nodes/TransitionProgress.js
  /**
   * tag for scene redial
   * @constant
   * @type Number
   */
  var SCENE_RADIAL: number;

  /**
   * cc.TransitionProgress transition.
   * @class
   * @extends cc.TransitionScene
   */
  export class TransitionProgress extends TransitionScene {
    /**
     * @override
     */
    onEnter(): void;

    /**
     * @override
     */
    onExit(): void;

    /**
     * create a cc.TransitionProgress object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgress}
     */
    static create(t?: number, scene?: Scene): TransitionProgress;
  }

  /**
   *  cc.TransitionRadialCCW transition.<br/>
   *  A counter colock-wise radial transition to the next scene
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressRadialCCW extends TransitionProgress {
    /**
     * create a cc.TransitionProgressRadialCCW object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressRadialCCW}
     */
    static create(t?: number, scene?: Scene): TransitionProgressRadialCCW;
  }

  /**
   * cc.TransitionRadialCW transition.<br/>
   * A counter colock-wise radial transition to the next scene
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressRadialCW extends TransitionProgress {
    /**
     * create a cc.TransitionProgressRadialCW object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressRadialCW}
     */
    static create(t?: number, scene?: Scene): TransitionProgressRadialCW;
  }

  /**
   * cc.TransitionProgressHorizontal transition.<br/>
   * A  colock-wise radial transition to the next scene
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressHorizontal extends TransitionProgress {
    /**
     * create a cc.TransitionProgressHorizontal object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressHorizontal}
     */
    create(t: number, scene: Scene): TransitionProgressHorizontal;
  }

  /**
   * cc.TransitionProgressVertical transition.
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressVertical extends TransitionProgress {
    /**
     * create a cc.TransitionProgressVertical object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressVertical}
     */
    create(t: number, scene: Scene): TransitionProgressVertical;
  }

  /**
   * cc.TransitionProgressInOut transition.
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressInOut extends TransitionProgress {
    /**
     * create a cc.TransitionProgressInOut object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressInOut}
     */
    create(t: number, scene: Scene): TransitionProgressInOut;
  }

  /**
   * cc.TransitionProgressOutIn transition.
   * @class
   * @extends cc.TransitionProgress
   */
  export class TransitionProgressOutIn extends TransitionProgress {
    /**
     * create a cc.TransitionProgressOutIn object
     * @function
     * @param {Number} t time
     * @param {cc.Scene} scene
     * @return {cc.TransitionProgressOutIn}
     */
    create(t: number, scene: Scene): TransitionProgressOutIn;
  }
  //#endregion cocos2d/layers_scenes_transitions_nodes/TransitionProgress.js

  //#region cocos2d/menu_nodes/CCMenu.js
  /**
   * <p> Features and Limitation:<br/>
   *  - You can add MenuItem objects in runtime using addChild:<br/>
   *  - But the only accecpted children are MenuItem objects</p>
   * @class
   * @extends cc.Layer
   */
  export class Menu extends Layer {
    /**
     * create a new menu
     * @return {cc.Menu}
     * @example
     * // Example
     * //there is no limit on how many menu item you can pass in
     * var myMenu = cc.Menu.create(menuitem1, menuitem2, menuitem3);
     */
    static create(...nodes: Node[]): Menu;
  }
  //#endregion cocos2d/menu_nodes/CCMenu.js

  //#region cocos2d/menu_nodes/CCMenuItem.js
  /**
   * Subclass cc.MenuItem (or any subclass) to create your custom cc.MenuItem objects.
   * @class
   * @extends cc.Node
   */
  export class MenuItem extends Node {
    /**
     * MenuItem is selected
     * @return {Boolean}
     */
    isSelected(): boolean;

    /**
     * set the target/selector of the menu item
     * @param {function|String} selector
     * @param {cc.Node} rec
     */
    setTarget(selector: any, rec: Node): void;

    /**
     * MenuItem is Enabled
     * @return {Boolean}
     */
    isEnabled(): boolean;

    /**
     * set enable value of MenuItem
     * @param {Boolean} enable
     */
    setEnabled(enable: boolean): void;

    /**
     * @param {function|String} selector
     * @param {cc.Node} rec
     * @return {Boolean}
     */
    initWithCallback(selector: () => {} | string, rec: Node): boolean;

    /**
     * return rect value of cc.MenuItem
     * @return {cc.Rect}
     */
    rect(): Rect;

    /**
     * same as setIsSelected(true)
     */
    selected(): void;

    /**
     * same as setIsSelected(false)
     */
    unselected(): void;

    /**
     * @param {function|String} selector
     * @param {cc.Node} rec
     */
    setCallback(selector: any, rec: Node): void;

    /**
     * call the selector with target
     */
    activate(): void;
  }

  /**
   *  Any cc.Node that supports the cc.LabelProtocol protocol can be added.<br/>
   * Supported nodes:<br/>
   * - cc.BitmapFontAtlas<br/>
   * - cc.LabelAtlas<br/>
   * - cc.LabelTTF<br/>
   * @class
   * @extends cc.MenuItem
   */
  export class MenuItemLabel extends MenuItem {
    /**
     * @param {cc.Node} label
     * @param {function|String|Null} selector
     * @param {cc.Node|Null} target
     * @return {cc.MenuItemLabel}
     */
    static create(...args: any[] /*label, selector, target*/): MenuItemLabel;
  }

  /**
   * Helper class that creates a MenuItemLabel class with a LabelAtlas
   * @class
   * @extends cc.MenuItemLabel
   */
  export class MenuItemAtlasFont extends cc.MenuItemLabel {
    /**
     * create menu item from string with font
     * @param {String} value the text to display
     * @param {String} charMapFile the character map file
     * @param {Number} itemWidth
     * @param {Number} itemHeight
     * @param {String} startCharMap a single character
     * @param {cc.Node|Null} target
     * @param {function|String|Null} selector
     * @return {cc.MenuItemAtlasFont}
     * @example
     * // Example
     * var item = cc.MenuItemAtlasFont.create('text to display', 'font.fnt', 12, 32, ' ')
     *
     * //OR
     * var item = cc.MenuItemAtlasFont.create('text to display', 'font.fnt', 12, 32, ' ', game, game.run)
     */
    static create(
      ...args: any[] /*value, charMapFile, itemWidth, itemHeight, startCharMap, target, selector*/
    ): MenuItemAtlasFont;
  }

  /**
   * Helper class that creates a CCMenuItemLabel class with a Label
   * @class
   * @extends cc.MenuItemLabel
   */
  export class MenuItemFont extends MenuItemLabel {
    /**
     * @param {Number} s
     */
    setFontSize(s: number): void;

    /**
     *
     * @return {Number}
     */
    fontSize(): number;

    /**
     * @param {String} name
     */
    setFontName(name: string): void;

    /**
     * @return {String}
     */
    fontName(): string;

    /**
     * create a menu item from string
     * @param {String} value the text to display
     * @param {String|function|Null} selector the callback to run, either in function name or pass in the actual function
     * @param {cc.Node|Null} target the target to run callback
     * @return {cc.MenuItemFont}
     * @example
     * // Example
     * var item = cc.MenuItemFont.create("Game start", 'start', Game)
     * //creates a menu item from string "Game start", and when clicked, it will run Game.start()
     *
     * var item = cc.MenuItemFont.create("Game start", game.start, Game)//same as above
     *
     * var item = cc.MenuItemFont.create("i do nothing")//create a text menu item that does nothing
     *
     * //you can set font size and name before or after
     * cc.MenuItemFont.setFontName('my Fancy Font');
     * cc.MenuItemFont.setFontSize(62);
     */
    static create(...args: any[] /*value, selector, target*/): MenuItemFont;
  }

  /**
     * CCMenuItemSprite accepts CCNode<CCRGBAProtocol> objects as items.<br/>
     The images has 3 different states:<br/>
     - unselected image<br/>
     - selected image<br/>
     - disabled image<br/>
     * @class
     * @extends cc.MenuItem
     */
  export class MenuItemSprite extends MenuItem {
    /**
     * create a menu item from sprite
     * @param {Image} normal normal state image
     * @param {Image|Null} selected selected state image
     * @param {Image|cc.Node|Null} three disabled state image OR target node
     * @param {String|function|cc.Node|Null} four callback function name in string or actual function, OR target Node
     * @param {String|function|Null} five callback function name in string or actual function
     * @return {cc.MenuItemSprite}
     * @example
     * // Example
     * var item = cc.MenuItemSprite.create(normalImage)//create a menu item from a sprite with no functionality
     *
     * var item = cc.MenuItemSprite.create(normalImage, selectedImage)//create a menu Item, nothing will happen when clicked
     *
     * var item = cc.MenuItemSprite.create(normalImage, SelectedImage, disabledImage)//same above, but with disabled state image
     *
     * var item = cc.MenuItemSprite.create(normalImage, SelectedImage, 'callback', targetNode)//create a menu item, when clicked runs targetNode.callback()
     *
     * var item = cc.MenuItemSprite.create(normalImage, SelectedImage, disabledImage, targetNode.callback, targetNode)
     * //same as above, but with disabled image, and passing in callback function
     */
    static create(
      ...args: any[] /*normalSprite, selectedSprite, three, four, five*/
    ): MenuItemSprite;
  }

  /**
   * cc.MenuItemImage accepts images as items.<br/>
   * The images has 3 different states:<br/>
   * - unselected image<br/>
   * - selected image<br/>
   * - disabled image<br/>
   * <br/>
   * For best results try that all images are of the same size<br/>
   * @class
   * @extends cc.MenuItemSprite
   */
  export class MenuItemImage extends MenuItemSprite {
    /**
     * creates a new menu item image
     * @param {String} normalImage file name for normal state
     * @param {String} selectedImage image for selected state
     * @param {String|cc.Node} three Disabled image OR allback function
     * @param {String|function|Null} four callback function, either name in string or pass the whole function OR the target
     * @param {cc.Node|String|function|Null} five cc.Node target to run callback when clicked
     * @return {cc.MenuItemImage}
     * @example
     * // Example
     * //create a dom menu item with normal and selected state, when clicked it will run the run function from gameScene object
     * var item = cc.MenuItemImage.create('normal.png', 'selected.png', 'run', gameScene)
     *
     * //same as above, but pass in the actual function and disabled image
     * var item = cc.MenuItemImage.create('normal.png', 'selected.png', 'disabled.png', gameScene.run, gameScene)
     */
    static create(): MenuItemImage;
    static create(
      normalImage: string,
      selectedImage: string,
      three: (sender: any) => void,
    ): MenuItemImage;
    static create(
      normalImage: string,
      selectedImage: string,
      three: (sender: any) => void,
      four: Node,
    ): MenuItemImage;
    static create(
      normalImage: string,
      selectedImage: string,
      three: string,
      four: (sender: any) => void,
      five: Node,
    ): MenuItemImage;
  }

  /**
   * A simple container class that "toggles" it's inner items<br/>
   * The inner items can be any MenuItem
   * @class
   * @extends cc.MenuItem
   */
  export class MenuItemToggle extends MenuItem {
    /**
     * @return {Number}
     */
    getOpacity(): number;

    /**
     * @param {Number} Opacity
     */
    setOpacity(Opacity: number): void;

    /**
     * @return {cc.Color3B}
     */
    getColor(): Color3B;

    /**
     * @param {cc.Color3B} Color
     */
    setColor(Color: Color3B): void;

    /**
     * @return {Number}
     */
    getSelectedIndex(): number;

    /**
     * @param {Number} SelectedIndex
     */
    setSelectedIndex(SelectedIndex: number): void;

    /**
     * similar to get children
     * @return {cc.MenuItem}
     */
    getSubItems(): MenuItem[];

    /**
     * @param {cc.MenuItem} SubItems
     */
    setSubItems(SubItems: MenuItem[]): void;

    /**
     * @param {cc.MenuItem} args[0...last-2] the rest in the array are cc.MenuItems
     * @param {function|String} args[last-1] the second item in the args array is the callback
     * @param {cc.Node} args[last] the first item in the args array is a target
     * @return {Boolean}
     */
    initWithItems(...args: any[]): boolean;

    /**
     * @param {cc.MenuItem} item
     */
    addSubItem(item: MenuItem): void;

    /**
     * activate the menu item
     */
    activate(): void;

    /**
     * menu item is selected (runs callback)
     */
    selected(): void;

    /**
     * menu item goes back to unselected state
     */
    unselected(): void;

    /**
     * @param {Boolean} enabled
     */
    setEnabled(enabled: boolean): void;

    /**
     * returns the selected item
     * @return {cc.MenuItem}
     */
    selectedItem(): MenuItem;

    setOpacityModifyRGB(value: boolean): void;

    isOpacityModifyRGB(): boolean;

    onEnter(): void;

    /**
     * create a simple container class that "toggles" it's inner items<br/>
     * The inner items can be any MenuItem
     * @return {cc.MenuItemToggle}
     * @example
     * // Example
     *
     * //create a toggle item with 2 menu items (which you can then toggle between them later)
     * var toggler = cc.MenuItemToggle.create(this, this.callback, cc.MenuItemFont.create("On"), cc.MenuItemFont.create("Off"))
     * //Note: the first param is the target, the second is the callback function, afterwards, you can pass in any number of menuitems
     *
     * //if you pass only 1 variable, then it must be a cc.MenuItem
     * var notYetToggler = cc.MenuItemToggle.create(cc.MenuItemFont.create("On"));//it is useless right now, until you add more stuff to it
     * notYetToggler.addSubItem(cc.MenuItemFont.create("Off"));
     * //this is useful for constructing a toggler without a callback function (you wish to control the behavior from somewhere else)
     */
    static create(...args: any[]): MenuItemToggle;
  }
  //#endregion cocos2d/menu_nodes/CCMenuItem.js

  //#region cocos2d/platform/AppControl.js
  /**
   * Controller of Game Application
   * @class
   * @extends cc.Class
   */
  export class AppController extends Class {
    /**
     * did something when Finish Launching
     * @return {Boolean}
     */
    didFinishLaunchingWithOptions(): boolean;

    /**
     * Return Controller of Game Application
     * @return {cc.AppController}
     */
    static shareAppController(): AppController;
  }
  //#endregion cocos2d/platform/AppControl.js

  //#region cocos2d/platform/CCApplication.js
  /**
   * Device type
   * @constant
   * @type {Object}
   */
  enum TARGET_PLATFORM {
    WINDOWS, //: 0,
    LINUX, //: 1,
    MACOS, //: 2,
    ANDROID, //: 3,
    IPHONE, //: 4,
    IPAD, //: 5,
    BLACKBERRY, //: 6,
    NACL, //: 7,
    EMSCRIPTEN, //: 8,
    MOBILE_BROWSER, //: 100,
    PC_BROWSER, //: 101
  }

  /**
   * Device oriented vertically, home button on the bottom
   * @constant
   * @type Number
   */
  var ORIENTATION_PORTRAIT: number;

  /**
   * Device oriented vertically, home button on the top
   * @constant
   * @type Number
   */
  var ORIENTATION_PORTRAIT_UPSIDE_DOWN: number;

  /**
   * Device oriented horizontally, home button on the right
   * @constant
   * @type Number
   */
  var ORIENTATION_LANDSCAPE_LEFT: number;

  /**
   * Device oriented horizontally, home button on the left
   * @constant
   * @type Number
   */
  var ORIENTATION_LANDSCAPE_RIGHT: number;

  //engine render type

  /**
   * Canvas of render type
   * @constant
   * @type Number
   */
  var CANVAS: number;

  /**
   * WebGL of render type
   * @constant
   * @type Number
   */
  var WEBGL: number;

  /**
   * drawing primitive of game engine
   * @type cc.DrawingPrimitive
   */
  var drawingUtil: DrawingPrimitive;

  /**
   * main Canvas 2D Context of game engine
   * @type CanvasContext
   */
  var renderContext: CanvasRenderingContext2D;

  /**
   * main Canvas of game engine
   * @type HTMLCanvasElement
   */
  var canvas: HTMLCanvasElement;

  /**
   * This Div element contain all game canvas
   * @type HTMLDivElement
   */
  var gameDiv: HTMLDivElement;

  /**
   * current render type of game engine
   * @type Number
   */
  var renderContextType: number;

  /**
   * save original size of canvas, use for resize canvas
   * @type cc.Size
   */
  var originalCanvasSize: Size;

  /**
   * <p>
   *   setup game main canvas,renderContext,gameDiv and drawingUtil with argument  <br/>
   *   <br/>
   *   can receive follow type of arguemnt: <br/>
   *      - empty: create a canvas append to document's body, and setup other option    <br/>
   *      - string: search the element by document.getElementById(),    <br/>
   *          if this element is HTMLCanvasElement, set this element as main canvas of engine, and set it's ParentNode as cc.gameDiv.<br/>
   *          if this element is HTMLDivElement, set it's ParentNode to cc.gameDiv， and create a canvas as main canvas of engine.   <br/>
   * </p>
   * @function
   * @example
   * //setup with null
   * cc.setup();
   *
   * // setup with HTMLCanvasElement, gameCanvas is Canvas element
   * // declare like this: <canvas id="gameCanvas" width="800" height="450"></canvas>
   * cc.setup("gameCanvas");
   *
   * //setup with HTMLDivElement, gameDiv is Div element
   * // declare like this: <div id="Cocos2dGameContainer" width="800" height="450"></div>
   * cc.setup("Cocos2dGameContainer");
   */
  function setup(el?: string, width?: number, height?: number): void;

  /**
   * Run main loop of game engine
   * @class
   * @extends cc.Class
   */
  export class Application extends Class {
    static getInstance(): Application;
    getCurrentLanguage(): number;
    openURL(url: string): boolean;
  }
  //#endregion cocos2d/platform/CCApplication.js

  //#region cocos2d/platform/CCClass.js
  // export class Class {
  //   static extend(props: any): any;
  //   constructor();
  //   _className: string;
  // }
  //#endregion cocos2d/platform/CCClass.js

  //#region cocos2d/platform/CCTypes.js
  export class Color3B {
    r: number;
    g: number;
    b: number;

    /**
     * RGB color composed of bytes 3 bytes
     * @Class
     * @Construct
     * @param {Number | cc.Color3B} r1 red value (0 to 255) or destination color of new color
     * @param {Number} g1 green value (0 to 255)
     * @param {Number} b1 blue value (0 to 255)
     * @example
     * //create an empty color
     * var color1 = new cc.Color3B();
     *
     * //create a red color
     * var redColor = new cc.Color3B(255,0,0);
     *
     * //create a new color with color
     * var newColor = new cc.Color3B(redColor);
     */
    constructor(r1: any, g1?: number, b1?: number);
  }

  /**
   * RGBA color composed of 4 bytes
   * @Class
   * @Construct
   * @param {Number} r1 red value (0 to 255)
   * @param {Number} g1 green value (0 to 255)
   * @param {Number} b1 blue value (0 to 255)
   * @param {Number} a1 Alpha value (0 to 255)
   * @example
   * //create a red color
   * var redColor = new cc.Color4B(255,0,0,255);
   */
  export class Color4B {
    r: number;
    g: number;
    b: number;
    a: number;

    constructor(r1: any, g1: number, b1: number, a1: number);
  }

  /**
   * helper macro that creates an ccColor4B type
   * @function
   * @param {Number} r red value (0 to 255)
   * @param {Number} g green value (0 to 255)
   * @param {Number} b blue value (0 to 255)
   * @param {Number} a Alpha value (0 to 255)
   * @return {Number,Number,Number,Number}
   */
  function c4b(r: number, g: number, b: number, a: number): Color4B;

  /**
   * RGBA color composed of 4 floats
   * @Class
   * @Construct
   * @param {Number} r1 red value (0 to 1)
   * @param {Number} g1 green value (0 to 1)
   * @param {Number} b1 blue value (0 to 1)
   * @param {Number} a1 Alpha value (0 to 1)
   * @example
   * //create a red color
   * var redColor = new cc.Color4F(1,0,0,1);
   */
  export class Color4F {
    r: number;
    g: number;
    b: number;
    a: number;

    constructor(r1: number, g1: number, b1: number, a1: number);
  }

  /**
   * helper macro that creates an ccColor4F type
   * @Class
   * @Construct
   * @param {Number} r red value (0 to 1)
   * @param {Number} g green value (0 to 1)
   * @param {Number} b blue value (0 to 1)
   * @param {Number} a Alpha value (0 to 1)
   * @example
   * //create a red color
   * var redColor = cc.c4f(1,0,0,1);
   */
  function c4f(r: number, g: number, b: number, a: number): Color4F;

  /**
   * Returns a cc.Color4F from a cc.Color3B. Alpha will be 1.
   * @function
   * @param {cc.Color3B} c color
   * @return {cc.Color4F}
   */
  function c4FFromccc3B(c: Color3B): Color4F;

  /**
   * Returns a cc.Color4F from a cc.Color4B.
   * @function
   * @param {cc.Color4B} c Color
   * @return {cc.Color4F}
   */
  function c4FFromccc4B(c: Color4B): Color4F;

  /**
   * Returns a cc.Color4B from a cc.Color4F.
   * @param {cc.Color4F} c
   * @return {cc.Color4B}
   */
  function c4BFromccc4F(c: Color4F): Color4B;

  /**
   * returns YES if both cc.Color4F are equal. Otherwise it returns NO.
   * @param {cc.Color4F} a color1
   * @param {cc.Color4F} b color2
   * @return {Boolean}
   */
  function c4FEqual(a: Color4F, b: Color4F): boolean;

  /**
   * A vertex composed of 2 floats: x, y
   * @Class
   * @Construct
   * @param {Number} x1
   * @param {Number} y1
   */
  export class Vertex2F {
    x: number;
    y: number;

    constructor(x1?: number, y1?: number);
  }

  /**
   * helper macro that creates an Vertex2F type
   * @function
   * @param {Number} x
   * @param {Number} y
   * @return {cc.Vertex2F}
   */
  function Vertex2(x: number, y: number): Vertex2F;

  /**
   * A vertex composed of 3 floats: x, y, z
   * @Class
   * @Construct
   * @param {Number} x1
   * @param {Number} y1
   * @param {Number} z1
   */
  export class Vertex3F {
    x: number;
    y: number;
    z: number;

    constructor(x1?: number, y1?: number, z1?: number);
  }

  /**
   * helper macro that creates an Vertex3F type
   * @function
   * @param {Number} x
   * @param {Number} y
   * @param {Number} z
   * @return {cc.Vertex3F}
   */
  function vertex3(x: number, y: number, z: number): Vertex3F;

  /**
   * A texcoord composed of 2 floats: u, y
   * @Class
   * @Construct
   * @param {Number} u1
   * @param {Number} v1
   */
  export class Tex2F {
    u: number;
    v: number;

    constructor(u1?: number, v1?: number);
  }

  /**
   * helper macro that creates an Tex2F type
   * @function
   * @param {Number} u
   * @param {Number} v
   * @return {cc.Tex2F}
   */
  function tex2(u: number, v: number): Tex2F;

  /**
   * Point Sprite component
   * @Class
   * @Construct
   * @param {cc.Vertex2F} pos1
   * @param {cc.Color4B} color1
   * @param {Number} size1
   */
  export class PointSprite {
    pos: Vertex2F;
    color: Color4B;
    size: number;

    constructor(pos1: Vertex2F, color1: Color4B, size1: number);
  }

  /**
   * A 2D Quad. 4 * 2 floats
   * @Class
   * @Construct
   * @param {cc.Vertex2F} tl1
   * @param {cc.Vertex2F} tr1
   * @param {cc.Vertex2F} bl1
   * @param {cc.Vertex2F} br1
   */
  export class Quad2 {
    tl: Vertex2F;
    tr: Vertex2F;
    bl: Vertex2F;
    br: Vertex2F;

    constructor(tl1?: Vertex2F, tr1?: Vertex2F, bl1?: Vertex2F, br1?: Vertex2F);
  }

  /**
   * A 3D Quad. 4 * 3 floats
   * @Class
   * @Construct
   * @param {cc.Vertex3F} bl1
   * @param {cc.Vertex3F} br1
   * @param {cc.Vertex3F} tl1
   * @param {cc.Vertex3F} tr1
   */
  export class Quad3 {
    bl: Vertex3F;
    br: Vertex3F;
    tl: Vertex3F;
    tr: Vertex3F;

    constructor(bl1?: Vertex3F, br1?: Vertex3F, tl1?: Vertex3F, tr1?: Vertex3F);
  }

  /**
   * text alignment : left
   * @constant
   * @type Number
   */
  // var TEXT_ALIGNMENT_LEFT: number;

  /**
   * text alignment : center
   * @constant
   * @type Number
   */
  // var TEXT_ALIGNMENT_CENTER: number;

  /**
   * text alignment : right
   * @constant
   * @type Number
   */
  // var TEXT_ALIGNMENT_RIGHT: number;

  /**
   * text alignment : top
   * @constant
   * @type Number
   */
  // var VERTICAL_TEXT_ALIGNMENT_TOP: number;

  /**
   * text alignment : center
   * @constant
   * @type Number
   */
  // var VERTICAL_TEXT_ALIGNMENT_CENTER: number;

  /**
   * text alignment : bottom
   * @constant
   * @type Number
   */
  // var VERTICAL_TEXT_ALIGNMENT_BOTTOM: number;

  //#endregion cocos2d/platform/CCTypes.js

  //#region cocos2d/sprite_nodes/CCAnimation.js
  /**
   * <p>
   *    cc.AnimationFrame
   *    A frame of the animation. It contains information like:
   *       - sprite frame name
   *       - # of delay units.
   *       - offset
   * </p>
   * @class
   * @extends cc.Class
   */
  export class AnimationFrame extends Class {}

  /**
   * <p>
   *     A cc.Animation object is used to perform animations on the cc.Sprite objects.<br/>
   *     <br/>
   *      The cc.Animation object contains cc.SpriteFrame objects, and a possible delay between the frames. <br/>
   *      You can animate a cc.Animation object by using the cc.Animate action. Example:  <br/>
   * </p>
   * @class
   * @extends cc.Class
   *
   * @example
   * //create an animation object
   * var animation = cc.Animation.create();
   *
   * //add a sprite frame to this animation
   * animation.addFrameWithFile("grossini_dance_01.png");
   *
   * //create an animate with this animation
   * var action = cc.Animate.create(animation);
   *
   * //run animate
   * this._grossini.runAction(action);
   */
  export class Animation extends Class {
    constructor(frames: SpriteFrame[], delay: number, userInfo?: any);
    /**
     * Creates an animation.
     * @param {Array} frames
     * @param {Number} delay
     * @param {Number} loops
     * @return {cc.Animation}
     * @example
     * //Creates an animation
     * var animation1 = cc.Animation.create();
     *
     * //Create an animation with sprite frames
     * var animFrames = [];
     * var frame = cache.getSpriteFrame("grossini_dance_01.png");
     * animFrames.push(frame);
     * var animation2 = cc.Animation.create(animFrames);
     *
     * //Create an animation with sprite frames and delay
     * var animation3 = cc.Animation.create(animFrames, 0.2);
     */
    static create(
      frames: AnimationFrame[],
      delay: number,
      loops: number,
    ): Animation;

    /**
     * Creates an animation with an array of cc.AnimationFrame, the delay per units in seconds and and how many times it should be executed.
     * @param {Array} arrayOfAnimationFrameNames
     * @param {Number} delayPerUnit
     * @param {Number} loops
     * @return {cc.Animation}
     */
    static createWithAnimationFrames(
      arrayOfAnimationFrameNames: SpriteFrame[] | AnimationFrame[] | string[],
      delayPerUnit: number,
      loops?: number,
    ): Animation;
    setDelayPerUnit(delayPerUnit: number): void;
    setRestoreOriginalFrame(restoreOriginalFrame: boolean): void;
  }
  //#endregion cocos2d/sprite_nodes/CCAnimation.js

  //#region cocos2d/sprite_nodes/CCSprite.js
  /**
   * <p>cc.Sprite is a 2d image ( http://en.wikipedia.org/wiki/Sprite_(computer_graphics) ) (Canvas implement) <br/>
   *
   * cc.Sprite can be created with an image, or with a sub-rectangle of an image.  <br/>
   *
   * If the parent or any of its ancestors is a cc.SpriteBatchNode then the following features/limitations are valid   <br/>
   *    - Features when the parent is a cc.BatchNode: <br/>
   *        - MUCH faster rendering, specially if the cc.SpriteBatchNode has many children. All the children will be drawn in a single batch.  <br/>
   *
   *    - Limitations   <br/>
   *        - Camera is not supported yet (eg: CCOrbitCamera action doesn't work)  <br/>
   *        - GridBase actions are not supported (eg: CCLens, CCRipple, CCTwirl) <br/>
   *        - The Alias/Antialias property belongs to CCSpriteBatchNode, so you can't individually set the aliased property.  <br/>
   *        - The Blending function property belongs to CCSpriteBatchNode, so you can't individually set the blending function property. <br/>
   *        - Parallax scroller is not supported, but can be simulated with a "proxy" sprite.        <br/>
   *
   *  If the parent is an standard cc.Node, then cc.Sprite behaves like any other cc.Node:      <br/>
   *    - It supports blending functions    <br/>
   *    - It supports aliasing / antialiasing    <br/>
   *    - But the rendering will be slower: 1 draw per children.   <br/>
   *
   * The default anchorPoint in cc.Sprite is (0.5, 0.5). </p>
   * @class
   * @extends cc.Node
   *
   * @example
   * var aSprite = new cc.Sprite();
   * aSprite.initWithFile("HelloHTML5World.png",cc.rect(0,0,480,320));
   */

  export class SpriteFrame {
    getOriginalSize(): Size;
  }
  //#endregion cocos2d/sprite_nodes/CCSprite.js

  //#endregion cocos2d/touch_dispatcher/CCTouchDelegateProtocol.js

  //#region CocosDension/SimpleAudioEngine.js
  class AudioEngine extends Class {
    static getInstance(): AudioEngine;
    /**
     * Indicates whether any background music can be played or not.
     * @returns {boolean} <i>true</i> if the background music is playing, otherwise <i>false</i>
     */
    willPlayMusic(): boolean;
    /**
     * Play music.
     * @param {String} url The path of the music file without filename extension.
     * @param {Boolean} loop Whether the music loop or not.
     * @example
     * //example
     * cc.audioEngine.playMusic(path, false);
     */
    playMusic(url: string, loop: boolean): void;
    /**
     * Stop playing music.
     * @param {Boolean} [releaseData] If release the music data or not.As default value is false.
     * @example
     * //example
     * cc.audioEngine.stopMusic();
     */
    stopMusic(releaseData?: boolean | any): void;
    /**
     * Pause playing music.
     * @example
     * //example
     * cc.audioEngine.pauseMusic();
     */
    pauseMusic(): void;
    /**
     * Resume playing music.
     * @example
     * //example
     * cc.audioEngine.resumeMusic();
     */
    resumeMusic(): void;
    /**
     * Rewind playing music.
     * @example
     * //example
     * cc.audioEngine.rewindMusic();
     */
    rewindMusic(): void;
    /**
     * The volume of the music max value is 1.0,the min value is 0.0 .
     * @return {Number}
     * @example
     * //example
     * var volume = cc.audioEngine.getMusicVolume();
     */
    getMusicVolume(): number;
    /**
     * Set the volume of music.
     * @param {Number} volume Volume must be in 0.0~1.0 .
     * @example
     * //example
     * cc.audioEngine.setMusicVolume(0.5);
     */
    setMusicVolume(volume: number): void;
    /**
     * Whether the music is playing.
     * @return {Boolean} If is playing return true,or return false.
     * @example
     * //example
     *  if (cc.audioEngine.isMusicPlaying()) {
     *      cc.log("music is playing");
     *  }
     *  else {
     *      cc.log("music is not playing");
     *  }
     */
    isMusicPlaying(): boolean;
    /**
     * Play sound effect.
     * @param {String} url The path of the sound effect with filename extension.
     * @param {Boolean} loop Whether to loop the effect playing, default value is false
     * @return {Number|null} the audio id
     * @example
     * //example
     * var soundId = cc.audioEngine.playEffect(path);
     */
    playEffect(url: string, loop: boolean): number | null;
    /**
     * Set the volume of sound effects.
     * @param {Number} volume Volume must be in 0.0~1.0 .
     * @example
     * //example
     * cc.audioEngine.setEffectsVolume(0.5);
     */
    setEffectsVolume(volume: number): void;
    /**
     * The volume of the effects max value is 1.0,the min value is 0.0 .
     * @return {Number}
     * @example
     * //example
     * var effectVolume = cc.audioEngine.getEffectsVolume();
     */
    getEffectsVolume(): number;
    /**
     * Pause playing sound effect.
     * @param {Number} audio The return value of function playEffect.
     * @example
     * //example
     * cc.audioEngine.pauseEffect(audioID);
     */
    pauseEffect(audio: number): void;
    /**
     * Pause all playing sound effect.
     * @example
     * //example
     * cc.audioEngine.pauseAllEffects();
     */
    pauseAllEffects(): void;
    /**
     * Resume playing sound effect.
     * @param {Number} audio The return value of function playEffect.
     * @audioID
     * //example
     * cc.audioEngine.resumeEffect(audioID);
     */
    resumeEffect(audio: number): void;
    /**
     * Resume all playing sound effect
     * @example
     * //example
     * cc.audioEngine.resumeAllEffects();
     */
    resumeAllEffects(): void;
    /**
     * Stop playing sound effect.
     * @param {Number} audio The return value of function playEffect.
     * @example
     * //example
     * cc.audioEngine.stopEffect(audioID);
     */
    stopEffect(audio: number): void;
    /**
     * Stop all playing sound effects.
     * @example
     * //example
     * cc.audioEngine.stopAllEffects();
     */
    stopAllEffects(): void;
    /**
     * Unload the preloaded effect from internal buffer
     * @param {String} url
     * @example
     * //example
     * cc.audioEngine.unloadEffect(EFFECT_FILE);
     */
    unloadEffect(url: string): void;
    /**
     * End music and effects.
     */
    end(): void;

    features: {
      MULTI_CHANNEL: boolean;
      WEBAUDIO?: boolean;
      AUTOPLAY: boolean;
    };
  }

  /**
   * The Audio Engine implementation via <audio> tag in HTML5.
   * @class
   * @extends   cc.AudioEngine
   */
  class SimpleAudioEngine extends AudioEngine {
    /**
     * Preload music resource.<br />
     * This method is called when cc.Loader preload  resources.
     * @param {String} path The path of the music file with filename extension.
     */
    preloadSound(path: string): void;

    /**
     * Play music.
     * @param {String} path The path of the music file without filename extension.
     * @param {Boolean} loop Whether the music loop or not.
     * @example
     * //example
     * cc.AudioEngine.getInstance().playMusic(path, false);
     */
    playMusic(path: string, loop: boolean): void;

    /**
     * Stop playing music.
     * @param {Boolean} releaseData If release the music data or not.As default value is false.
     * @example
     * //example
     * cc.AudioEngine.getInstance().stopMusic();
     */
    stopMusic(releaseData: boolean): void;

    /**
     * Pause playing music.
     * @example
     * //example
     * cc.AudioEngine.getInstance().pauseMusic();
     */
    pauseMusic(): void;

    /**
     * Resume playing music.
     * @example
     * //example
     * cc.AudioEngine.getInstance().resumeMusic();
     */
    resumeMusic(): void;

    /**
     * Rewind playing music.
     * @example
     * //example
     * cc.AudioEngine.getInstance().rewindMusic();
     */
    rewindMusic(): void;

    /**
     * The volume of the music max value is 1.0,the min value is 0.0 .
     * @return {Number}
     * @example
     * //example
     * var volume = cc.AudioEngine.getInstance().getMusicVolume();
     */
    getMusicVolume(): number;

    /**
     * Set the volume of music.
     * @param {Number} volume Volume must be in 0.0~1.0 .
     * @example
     * //example
     * cc.AudioEngine.getInstance().setMusicVolume(0.5);
     */
    setMusicVolume(volume: number): void;

    /**
     * Whether the music is playing.
     * @return {Boolean} If is playing return true,or return false.
     * @example
     * //example
     *  if (cc.AudioEngine.getInstance().isMusicPlaying()) {
     *      cc.log("music is playing");
     *  }
     *  else {
     *      cc.log("music is not playing");
     *  }
     */
    isMusicPlaying(): boolean;

    /**
     * Play sound effect.
     * @param {String} path The path of the sound effect with filename extension.
     * @param {Boolean} loop Whether to loop the effect playing, default value is false
     * @example
     * //example
     * var soundId = cc.AudioEngine.getInstance().playEffect(path);
     */
    playEffect(path: string, loop: boolean): number;

    /**
     *The volume of the effects max value is 1.0,the min value is 0.0 .
     * @return {Number}
     * @example
     * //example
     * var effectVolume = cc.AudioEngine.getInstance().getEffectsVolume();
     */
    getEffectsVolume(): number;

    /**
     * Set the volume of sound effecs.
     * @param {Number} volume Volume must be in 0.0~1.0 .
     * @example
     * //example
     * cc.AudioEngine.getInstance().setEffectsVolume(0.5);
     */
    setEffectsVolume(volume: number): void;

    /**
     * Pause playing sound effect.
     * @param {Number} audioID The return value of function playEffect.
     * @example
     * //example
     * cc.AudioEngine.getInstance().pauseEffect(audioID);
     */
    pauseEffect(audioID: number): void;

    /**
     * Pause all playing sound effect.
     * @example
     * //example
     * cc.AudioEngine.getInstance().pauseAllEffects();
     */
    pauseAllEffects(): void;

    /**
     * Resume playing sound effect.
     * @param {Number} audioID The return value of function playEffect.
     * @audioID
     * //example
     * cc.AudioEngine.getInstance().resumeEffect(audioID);
     */
    resumeEffect(audioID: number): void;

    /**
     * Resume all playing sound effect
     * @example
     * //example
     * cc.AudioEngine.getInstance().resumeAllEffects();
     */
    resumeAllEffects(): void;

    /**
     * Stop playing sound effect.
     * @param {Number} audioID The return value of function playEffect.
     * @example
     * //example
     * cc.AudioEngine.getInstance().stopEffect(audioID);
     */
    stopEffect(audioID: number): void;

    /**
     * Stop all playing sound effects.
     * @example
     * //example
     * cc.AudioEngine.getInstance().stopAllEffects();
     */
    stopAllEffects(): void;

    /**
     * Unload the preloaded effect from internal buffer
     * @param {String} path
     * @example
     * //example
     * cc.AudioEngine.getInstance().unloadEffect(EFFECT_FILE);
     */
    unloadEffect(path: string): void;

    /**
     * search in this._supportedFormat if @param ext is there
     * @param {String} ext
     * @returns {Boolean}
     */
    isFormatSupported(ext: string): boolean;
  }
  //#endregion CocosDension/SimpleAudioEngine.js
  /** N/A in cocos2d-html5 */
  // class sys {
  //   static capabilities: any;
  //   static isNative: boolean;

  //   /**
  //    * English language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_ENGLISH
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_ENGLISH: "en";

  //   /**
  //    * Chinese language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_CHINESE
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_CHINESE: "zh";

  //   /**
  //    * French language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_FRENCH
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_FRENCH: "fr";

  //   /**
  //    * Italian language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_ITALIAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_ITALIAN: "it";

  //   /**
  //    * German language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_GERMAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_GERMAN: "de";

  //   /**
  //    * Spanish language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_SPANISH
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_SPANISH: "es";

  //   /**
  //    * Spanish language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_DUTCH
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_DUTCH: "du";

  //   /**
  //    * Russian language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_RUSSIAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_RUSSIAN: "ru";

  //   /**
  //    * Korean language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_KOREAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_KOREAN: "ko";

  //   /**
  //    * Japanese language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_JAPANESE
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_JAPANESE: "ja";

  //   /**
  //    * Hungarian language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_HUNGARIAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_HUNGARIAN: "hu";

  //   /**
  //    * Portuguese language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_PORTUGUESE
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_PORTUGUESE: "pt";

  //   /**
  //    * Arabic language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_ARABIC
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_ARABIC: "ar";

  //   /**
  //    * Norwegian language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_NORWEGIAN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_NORWEGIAN: "no";

  //   /**
  //    * Polish language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_POLISH
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_POLISH: "pl";

  //   /**
  //    * Unknown language code
  //    * @memberof cc.sys
  //    * @name LANGUAGE_UNKNOWN
  //    * @constant
  //    * @type {Number}
  //    */
  //   static LANGUAGE_UNKNOWN: "unkonwn";

  //   /**
  //    * @memberof cc.sys
  //    * @name OS_IOS
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_IOS: "iOS";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_ANDROID
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_ANDROID: "Android";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_WINDOWS
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_WINDOWS: "Windows";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_MARMALADE
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_MARMALADE: "Marmalade";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_LINUX
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_LINUX: "Linux";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_BADA
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_BADA: "Bada";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_BLACKBERRY
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_BLACKBERRY: "Blackberry";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_OSX
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_OSX: "OS X";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_WP8
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_WP8: "WP8";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_WINRT
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_WINRT: "WINRT";
  //   /**
  //    * @memberof cc.sys
  //    * @name OS_UNKNOWN
  //    * @constant
  //    * @type {string}
  //    */
  //   static OS_UNKNOWN: "Unknown";

  //   /**
  //    * @memberof cc.sys
  //    * @name UNKNOWN
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static UNKNOWN: -1;
  //   /**
  //    * @memberof cc.sys
  //    * @name WIN32
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static WIN32: 0;
  //   /**
  //    * @memberof cc.sys
  //    * @name LINUX
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static LINUX: 1;
  //   /**
  //    * @memberof cc.sys
  //    * @name MACOS
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static MACOS: 2;
  //   /**
  //    * @memberof cc.sys
  //    * @name ANDROID
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static ANDROID: 3;
  //   /**
  //    * @memberof cc.sys
  //    * @name IOS
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static IPHONE: 4;
  //   /**
  //    * @memberof cc.sys
  //    * @name IOS
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static IPAD: 5;
  //   /**
  //    * @memberof cc.sys
  //    * @name BLACKBERRY
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static BLACKBERRY: 6;
  //   /**
  //    * @memberof cc.sys
  //    * @name NACL
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static NACL: 7;
  //   /**
  //    * @memberof cc.sys
  //    * @name EMSCRIPTEN
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static EMSCRIPTEN: 8;
  //   /**
  //    * @memberof cc.sys
  //    * @name TIZEN
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static TIZEN: 9;
  //   /**
  //    * @memberof cc.sys
  //    * @name WINRT
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static WINRT: 10;
  //   /**
  //    * @memberof cc.sys
  //    * @name WP8
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static WP8: 11;
  //   /**
  //    * @memberof cc.sys
  //    * @name MOBILE_BROWSER
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static MOBILE_BROWSER: 100;
  //   /**
  //    * @memberof cc.sys
  //    * @name DESKTOP_BROWSER
  //    * @constant
  //    * @default
  //    * @type {Number}
  //    */
  //   static DESKTOP_BROWSER: 101;

  //   static BROWSER_TYPE_WECHAT: "wechat";
  //   static BROWSER_TYPE_ANDROID: "androidbrowser";
  //   static BROWSER_TYPE_IE: "ie";
  //   static BROWSER_TYPE_QQ_APP: "qq"; // QQ App
  //   static BROWSER_TYPE_QQ: "qqbrowser";
  //   static BROWSER_TYPE_MOBILE_QQ: "mqqbrowser";
  //   static BROWSER_TYPE_UC: "ucbrowser";
  //   static BROWSER_TYPE_360: "360browser";
  //   static BROWSER_TYPE_BAIDU_APP: "baiduboxapp";
  //   static BROWSER_TYPE_BAIDU: "baidubrowser";
  //   static BROWSER_TYPE_MAXTHON: "maxthon";
  //   static BROWSER_TYPE_OPERA: "opera";
  //   static BROWSER_TYPE_OUPENG: "oupeng";
  //   static BROWSER_TYPE_MIUI: "miuibrowser";
  //   static BROWSER_TYPE_FIREFOX: "firefox";
  //   static BROWSER_TYPE_SAFARI: "safari";
  //   static BROWSER_TYPE_CHROME: "chrome";
  //   static BROWSER_TYPE_LIEBAO: "liebao";
  //   static BROWSER_TYPE_QZONE: "qzone";
  //   static BROWSER_TYPE_SOUGOU: "sogou";
  //   static BROWSER_TYPE_UNKNOWN: "unknown";
  //   /**
  //    * Indicate whether system is mobile system
  //    * @memberof cc.sys
  //    * @name isMobile
  //    * @type {Boolean}
  //    */
  //   static isMobile: boolean;
  //   static platform: number;
  //   /**
  //    * Indicate the current language of the running system
  //    * @memberof cc.sys
  //    * @name language
  //    * @type {String}
  //    */
  //   static language: string;

  //   /**
  //    * Indicate the running os name
  //    * @memberof cc.sys
  //    * @name os
  //    * @type {String}
  //    */

  //   static os: string;
  //   /**
  //    * Indicate the running os version string
  //    * @memberof cc.sys
  //    * @name osVersion
  //    * @type {String}
  //    */
  //   static osVersion: string;
  //   /**
  //    * Indicate the running os main version number
  //    * @memberof cc.sys
  //    * @name osMainVersion
  //    * @type {Number}
  //    */
  //   static osMainVersion: number;

  //   /**
  //    * Indicate the running browser type
  //    * @memberof cc.sys
  //    * @name browserType
  //    * @type {String}
  //    */
  //   static browserType: string;

  //   /**
  //    * Indicate the running browser version
  //    * @memberof cc.sys
  //    * @name browserVersion
  //    * @type {String}
  //    */
  //   static browserVersion: string;

  //   /**
  //    * Indicate the real pixel resolution of the whole game window
  //    * @memberof cc.sys
  //    * @name windowPixelResolution
  //    * @type {Size}
  //    */
  //   static windowPixelResolution: Size;

  //   static localStorage: Storage;

  //   /**
  //    * Forces the garbage collection, only available in JSB
  //    * @memberof cc.sys
  //    * @name garbageCollect
  //    * @function
  //    */
  //   static garbageCollect(): void;

  //   /**
  //    * Dumps rooted objects, only available in JSB
  //    * @memberof cc.sys
  //    * @name dumpRoot
  //    * @function
  //    */
  //   static dumpRoot(): void;

  //   /**
  //    * Restart the JS VM, only available in JSB
  //    * @memberof cc.sys
  //    * @name restartVM
  //    * @function
  //    */
  //   static restartVM(): void;

  //   /**
  //    * Clean a script in the JS VM, only available in JSB
  //    * @memberof cc.sys
  //    * @name cleanScript
  //    * @param {String} jsfile
  //    * @function
  //    */
  //   static cleanScript(jsfile: string): void;

  //   /**
  //    * Check whether an object is valid,
  //    * In web engine, it will return true if the object exist
  //    * In native engine, it will return true if the JS object and the correspond native object are both valid
  //    * @memberof cc.sys
  //    * @name isObjectValid
  //    * @param {Object} obj
  //    * @return {boolean} Validity of the object
  //    * @function
  //    */
  //   static isObjectValid(obj: object): boolean;

  //   /**
  //    * Dump system informations
  //    * @memberof cc.sys
  //    * @name dump
  //    * @function
  //    */
  //   static dump(): void;

  //   /**
  //    * Open a url in browser
  //    * @memberof cc.sys
  //    * @name openURL
  //    * @param {String} url
  //    */
  //   static openURL(url: string): void;

  //   /**
  //    * Get the number of milliseconds elapsed since 1 January 1970 00:00:00 UTC.
  //    * @memberof cc.sys
  //    * @name now
  //    * @return {Number}
  //    */
  //   static now(): number;

  //   static garbageCollect(): void;

  //   // Dumps rooted objects
  //   static dumpRoot(): any;

  //   // restarts the JS VM
  //   static restartVM(): void;
  // }
}
