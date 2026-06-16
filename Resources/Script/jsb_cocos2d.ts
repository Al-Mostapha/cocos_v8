/*
 * Copyright (c) 2013-2016 Chukong Technologies Inc.
 * Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

namespace cc {
  export const ENGINE_VERSION = "Cocos2d-JS v3.17";

  export const DIRECTOR_STATS_POSITION = { x: 0, y: 0 };
  export const DIRECTOR_FPS_INTERVAL = 0.5;
  export const COCOSNODE_RENDER_SUBPIXEL = 1;
  export const OPTIMIZE_BLEND_FUNC_FOR_PREMULTIPLIED_ALPHA = 0;
  export const TEXTURE_NPOT_SUPPORT = 0;
  export const RETINA_DISPLAY_SUPPORT = 1;
  export const RETINA_DISPLAY_FILENAME_SUFFIX = "-hd";
  export const USE_LA88_LABELS = 1;
  export const SPRITEBATCHNODE_DEBUG_DRAW = 0;

  export const IS_RETINA_DISPLAY_SUPPORTED = 1;
  export const DEFAULT_ENGINE = cc.ENGINE_VERSION + "-native";

  export enum ResolutionPolicy {
    // The entire application is visible in the specified area without trying to preserve the original aspect ratio.
    // Distortion can occur, and the application may appear stretched or compressed.
    EXACT_FIT = 0,
    // The entire application fills the specified area, without distortion but possibly with some cropping,
    // while maintaining the original aspect ratio of the application.
    NO_BORDER = 1,
    // The entire application is visible in the specified area without distortion while maintaining the original
    // aspect ratio of the application. Borders can appear on two sides of the application.
    SHOW_ALL = 2,
    // The application takes the height of the design resolution size and modifies the width of the internal
    // canvas so that it fits the aspect ratio of the device
    // no distortion will occur however you must make sure your application works on different
    // aspect ratios
    FIXED_HEIGHT = 3,
    // The application takes the width of the design resolution size and modifies the height of the internal
    // canvas so that it fits the aspect ratio of the device
    // no distortion will occur however you must make sure your application works on different
    // aspect ratios
    FIXED_WIDTH = 4,

    UNKNOWN = 5,
  }

  export const LANGUAGE_ENGLISH = 0;
  export const LANGUAGE_CHINESE = 1;
  export const LANGUAGE_FRENCH = 2;
  export const LANGUAGE_ITALIAN = 3;
  export const LANGUAGE_GERMAN = 4;
  export const LANGUAGE_SPANISH = 5;
  export const LANGUAGE_RUSSIAN = 6;
  export const LANGUAGE_KOREAN = 7;
  export const LANGUAGE_JAPANESE = 8;
  export const LANGUAGE_HUNGARIAN = 9;
  export const LANGUAGE_PORTUGUESE = 10;
  export const LANGUAGE_ARABIC = 11;

  // TODO
  // cc.Director.PROJECTION_2D = 0;
  // cc.Director.PROJECTION_3D = 1;
  // cc.Director.PROJECTION_CUSTOM = 3;
  // cc.Director.PROJECTION_DEFAULT = cc.Director.PROJECTION_3D;

  export const DEVICE_ORIENTATION_PORTRAIT = 0;
  export const DEVICE_ORIENTATION_LANDSCAPE_LEFT = 1;
  export const DEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN = 2;
  export const DEVICE_ORIENTATION_LANDSCAPE_RIGHT = 3;
  export const DEVICE_MAX_ORIENTATIONS = 2;

  export const IMAGE_FORMAT_RAWDATA = 9;

  export const TOUCH_ALL_AT_ONCE = 0;
  export const TOUCH_ONE_BY_ONE = 1;

  export const RED = { r: 255, g: 0, b: 0 };
  export const GREEN = { r: 0, g: 255, b: 0 };
  export const BLUE = { r: 0, g: 0, b: 255 };
  export const BLACK = { r: 0, g: 0, b: 0 };
  export const WHITE = { r: 255, g: 255, b: 255 };
  export const YELLOW = { r: 255, g: 255, b: 0 };

  export const POINT_ZERO = { x: 0, y: 0 };

  export const PARTICLE_DEFAULT_CAPACITY = 500;

  export const DEFAULT_PADDING = 5;

  // TODO
  // cc.Scheduler.PRIORITY_SYSTEM = -2147483648;
  // cc.Scheduler.PRIORITY_SYSTEM = -2147483648;
  // cc.Scheduler.PRIORITY_NON_SYSTEM = cc.Scheduler.PRIORITY_SYSTEM + 1;

  // var _Class = cc.Texture2D;

  // cc.Texture2D.PIXEL_FORMAT_NONE = -1;
  // cc.Texture2D.PIXEL_FORMAT_AUTO = 0;
  // cc.Texture2D.PIXEL_FORMAT_BGRA8888 = 1;
  // cc.Texture2D.PIXEL_FORMAT_RGBA8888 = 2;
  // cc.Texture2D.PIXEL_FORMAT_RGB888 = 3;
  // cc.Texture2D.PIXEL_FORMAT_RGB565 = 4;
  // cc.Texture2D.PIXEL_FORMAT_A8 = 5;
  // cc.Texture2D.PIXEL_FORMAT_I8 = 6;
  // cc.Texture2D.PIXEL_FORMAT_AI88 = 7;
  // cc.Texture2D.PIXEL_FORMAT_RGBA4444 = 8;
  // cc.Texture2D.PIXEL_FORMAT_RGB5A1 = 9;
  // cc.Texture2D.PIXEL_FORMAT_PVRTC4 = 10;
  // cc.Texture2D.PIXEL_FORMAT_PVRTC4A = 11;
  // cc.Texture2D.PIXEL_FORMAT_PVRTC2 = 11;
  // cc.Texture2D.PIXEL_FORMAT_PVRTC2A = 13;
  // cc.Texture2D.PIXEL_FORMAT_ETC = 14;
  // cc.Texture2D.PIXEL_FORMAT_S3TC_DXT1 = 15;
  // cc.Texture2D.PIXEL_FORMAT_S3TC_DXT3 = 16;
  // cc.Texture2D.PIXEL_FORMAT_S3TC_DXT5 = 17;
  // cc.Texture2D.PIXEL_FORMAT_ATC_RGB = 18;
  // cc.Texture2D.PIXEL_FORMAT_ATC_EXPLICIT_ALPHA = 19;
  // cc.Texture2D.PIXEL_FORMAT_ATC_INTERPOLATED_ALPHA = 20;
  // cc.Texture2D.PIXEL_FORMAT_DEFAULT = _Class.PIXEL_FORMAT_AUTO;
  // cc.Texture2D.defaultPixelFormat = _Class.PIXEL_FORMAT_DEFAULT;
  export enum PixelFormat {
    //! auto detect the type
    AUTO = 0,
    //! 32-bit texture: BGRA8888
    BGRA8888,
    //! 32-bit texture: RGBA8888
    RGBA8888,
    //! 24-bit texture: RGBA888
    RGB888,
    //! 16-bit texture without Alpha channel
    RGB565,
    //! 8-bit textures used as masks
    A8,
    //! 8-bit intensity texture
    I8,
    //! 16-bit textures used as masks
    AI88,
    //! 16-bit textures: RGBA4444
    RGBA4444,
    //! 16-bit textures: RGB5A1
    RGB5A1,
    //! 4-bit PVRTC-compressed texture: PVRTC4
    PVRTC4,
    //! 4-bit PVRTC-compressed texture: PVRTC4 (has alpha channel)
    PVRTC4A,
    //! 2-bit PVRTC-compressed texture: PVRTC2
    PVRTC2,
    //! 2-bit PVRTC-compressed texture: PVRTC2 (has alpha channel)
    PVRTC2A,
    //! ETC-compressed texture: ETC
    ETC,
    //! S3TC-compressed texture: S3TC_Dxt1
    S3TC_DXT1,
    //! S3TC-compressed texture: S3TC_Dxt3
    S3TC_DXT3,
    //! S3TC-compressed texture: S3TC_Dxt5
    S3TC_DXT5,
    //! ATITC-compressed texture: ATC_RGB
    ATC_RGB,
    //! ATITC-compressed texture: ATC_EXPLICIT_ALPHA
    ATC_EXPLICIT_ALPHA,
    //! ATITC-compressed texture: ATC_INTERPOLATED_ALPHA
    ATC_INTERPOLATED_ALPHA,
    //! Default texture format: AUTO

    MTL_B5G6R5,
    //MTL_A1BGR5,
    MTL_BGR5A1,
    MTL_ABGR4,

    // A packed 32-bit combined depth and stencil pixel format with two nomorlized unsigned integer
    // components: 24 bits, typically used for a depth render target, and 8 bits, typically used for
    // a stencil render target.
    D24S8,

    DEFAULT = AUTO,

    NONE = -1,
  }

  // // For blend
  export const ONE = 1;
  export const ZERO = 0;
  export const SRC_ALPHA = 0x0302;
  export const SRC_ALPHA_SATURATE = 0x308;
  export const SRC_COLOR = 0x300;
  export const DST_ALPHA = 0x304;
  export const DST_COLOR = 0x306;
  export const ONE_MINUS_SRC_ALPHA = 0x0303;
  export const ONE_MINUS_SRC_COLOR = 0x301;
  export const ONE_MINUS_DST_ALPHA = 0x305;
  export const ONE_MINUS_DST_COLOR = 0x0307;
  export const ONE_MINUS_CONSTANT_ALPHA = 0x8004;
  export const ONE_MINUS_CONSTANT_COLOR = 0x8002;

  // //texture parameters
  export const LINEAR = 0x2601;
  export const REPEAT = 0x2901;
  export const CLAMP_TO_EDGE = 0x812f;
  export const MIRRORED_REPEAT = 0x8370;

  export const VERTEX_ATTRIB_FLAG_NONE = 0;
  export const VERTEX_ATTRIB_FLAG_POSITION = 1 << 0;
  export const VERTEX_ATTRIB_FLAG_COLOR = 1 << 1;
  export const VERTEX_ATTRIB_FLAG_TEX_COORDS = 1 << 2;
  export const VERTEX_ATTRIB_FLAG_POS_COLOR_TEX =
    VERTEX_ATTRIB_FLAG_POSITION |
    VERTEX_ATTRIB_FLAG_COLOR |
    VERTEX_ATTRIB_FLAG_TEX_COORDS;
  // export const GL_ALL = 0;

  export const VERTEX_ATTRIB_POSITION = 0;
  export const VERTEX_ATTRIB_COLOR = 1;
  export const VERTEX_ATTRIB_TEX_COORDS = 2;
  export const VERTEX_ATTRIB_MAX = 3;

  export const UNIFORM_PMATRIX = 0;
  export const UNIFORM_MVMATRIX = 1;
  export const UNIFORM_MVPMATRIX = 2;
  export const UNIFORM_SINTIME = 4;
  export const UNIFORM_COSTIME = 5;

  // Shaders
  export const UNIFORM_TIME_S = "CC_Time";
  export const UNIFORM_COS_TIME_S = "CC_CosTime";
  export const UNIFORM_COSTIME_S = "CC_CosTime";
  export const UNIFORM_SIN_TIME_S = "CC_SinTime";
  export const UNIFORM_SINTIME_S = "CC_SinTime";
  export const UNIFORM_PMATRIX_S = "CC_PMatrix";
  export const UNIFORM_MVMATRIX_S = "CC_MVMatrix";
  export const UNIFORM_MVPMATRIX_S = "CC_MVPMatrix";
  export const UNIFORM_P_MATRIX_S = "CC_PMatrix";
  export const UNIFORM_MV_MATRIX_S = "CC_MVMatrix";
  export const UNIFORM_MVP_MATRIX_S = "CC_MVPMatrix";
  export const UNIFORM_RANDOM01_S = "CC_Random01";
  export const UNIFORM_SAMPLER_S = "CC_Texture0";
  export const UNIFORM_ALPHA_TEST_VALUE_S = "CC_AlphaValue";

  export const CURRENT_ITEM = 0xc0c05001;
  export const ZOOM_ACTION_TAG = 0xc0c05002;
  export const NORMAL_TAG = 8801;
  export const SELECTED_TAG = 8802;
  export const DISABLE_TAG = 8803;

  export const stencilBits = -1; //CCClippingNode.js

  let g_NumberOfDraws = 0; //CCDirector.js

  export const s_globalOrderOfArrival = 1;

  // TODO: add thiem in the c++
  // cc.Event.TOUCH = 0; //CCEvent.js
  // cc.Event.KEYBOARD = 1;
  // cc.Event.ACCELERATION = 2;
  // cc.Event.MOUSE = 3;
  // cc.Event.FOCUS = 4;
  // //game controller 5
  // cc.Event.CUSTOM = 6;
  // cc.EventMouse.NONE = 0;
  // cc.EventMouse.DOWN = 1;
  // cc.EventMouse.UP = 2;
  // cc.EventMouse.MOVE = 3;
  // cc.EventMouse.SCROLL = 4;
  // cc.EventMouse.BUTTON_LEFT = 0;
  // cc.EventMouse.BUTTON_RIGHT = 1;
  // cc.EventMouse.BUTTON_MIDDLE = 2;
  // cc.EventMouse.BUTTON_4 = 3;
  // cc.EventMouse.BUTTON_5 = 4;
  // cc.EventMouse.BUTTON_6 = 5;
  // cc.EventMouse.BUTTON_7 = 6;
  // cc.EventMouse.BUTTON_8 = 7;
  // cc.EventTouch.MAX_TOUCHES = 5;
  // cc.EventTouch.EventCode = { BEGAN: 0, MOVED: 1, ENDED: 2, CANCELLED: 3 };

  // cc.SpriteBatchNode.DEFAULT_CAPACITY = 29; //CCSpriteBatchNode.js

  // cc.ParticleSystem.SHAPE_MODE = 0; //CCParticleSystem.js
  // cc.ParticleSystem.TEXTURE_MODE = 1;
  // cc.ParticleSystem.STAR_SHAPE = 0;
  // cc.ParticleSystem.BALL_SHAPE = 1;

  // cc.ProgressTimer.TEXTURE_COORDS_COUNT = 4; //CCProgressTimer.js
  // cc.ProgressTimer.TEXTURE_COORDS = 0x4b;

  // cc.IMAGE_FORMAT_RAWDATA = 2; //CCRenderTexture.js

  // cc.TMXLayerInfo.ATTRIB_NONE = 1 << 0; //CCTMXXMLParser.js
  // cc.TMXLayerInfo.ATTRIB_BASE64 = 1 << 1;
  // cc.TMXLayerInfo.ATTRIB_GZIP = 1 << 2;
  // cc.TMXLayerInfo.ATTRIB_ZLIB = 1 << 3;
  // cc.TMX_PROPERTY_NONE = 0;
  // cc.TMX_PROPERTY_MAP = 1;
  // cc.TMX_PROPERTY_LAYER = 2;
  // cc.TMX_PROPERTY_OBJECTGROUP = 3;
  // cc.TMX_PROPERTY_OBJECT = 4;
  // cc.TMX_PROPERTY_TILE = 5;

  // cc.SCENE_FADE = 4208917214; //CCTransition.js

  // cc.SCENE_RADIAL = 0xc001; //CCTransitionProgress.js

  //
  // CCMacro.js export
  //

  /**
   * @constant
   * @type Number
   */
  export const INVALID_INDEX = -1;

  /**
   * PI is the ratio of a circle's circumference to its diameter.
   * @constant
   * @type Number
   */
  export const PI = Math.PI;

  /**
   * @constant
   * @type Number
   */
  export const PI2 = Math.PI * 2;

  /**
   * @constant
   * @type Number
   */
  export const FLT_MAX = parseFloat("3.402823466e+38F");

  /**
   * @constant
   * @type Number
   */
  export const RAD = PI / 180;

  /**
   * @constant
   * @type Number
   */
  export const DEG = 180 / PI;

  /**
   * maximum unsigned int value
   * @constant
   * @type Number
   */
  export const UINT_MAX = 0xffffffff;

  /**
   * <p>
   * simple macro that swaps 2 variables<br/>
   *  modified from c++ macro, you need to pass in the x and y variables names in string, <br/>
   *  and then a reference to the whole object as third variable
   * </p>
   * @param x
   * @param y
   * @param ref
   * @function
   * @deprecated
   */
  export const swap = (x: string, y: string, ref: any) => {
    if (
      typeof ref == "object" &&
      typeof ref.x != "undefined" &&
      typeof ref.y != "undefined"
    ) {
      const tmp = ref[x];
      ref[x] = ref[y];
      ref[y] = tmp;
    } else {
      cc.log(
        "cc.swap is being modified from original macro, please check usage",
      );
    }
  };

  /**
   * <p>
   *     Linear interpolation between 2 numbers, the ratio sets how much it is biased to each end
   * </p>
   * @param {Number} a number A
   * @param {Number} b number B
   * @param {Number} r ratio between 0 and 1
   * @function
   * @example
   * cc.lerp(2,10,0.5)//returns 6<br/>
   * cc.lerp(2,10,0.2)//returns 3.6
   */
  // cc.lerp = function (a, b, r) {
  //   return a + (b - a) * r;
  // };
  export const lerp = (a: number, b: number, r: number) => {
    return a + (b - a) * r;
  };

  /**
   * get a random number from 0 to 0xffffff
   * @function
   * @returns {number}
   */
  export const rand = () => {
    return Math.random() * 0xffffff;
  };

  /**
   * returns a random float between -1 and 1
   * @return {Number}
   * @function
   */
  // cc.randomMinus1To1 = function () {
  //   return (Math.random() - 0.5) * 2;
  // };
  export const randomMinus1To1 = () => {
    return (Math.random() - 0.5) * 2;
  };

  /**
   * returns a random float between 0 and 1
   * @return {Number}
   * @function
   */
  // cc.random0To1 = Math.random;
  export const random0To1 = Math.random;

  /**
   * converts degrees to radians
   * @param {Number} angle
   * @return {Number}
   * @function
   */
  export const degreesToRadians = (angle: number) => {
    return angle * cc.RAD;
  };

  /**
   * converts radians to degrees
   * @param {Number} angle
   * @return {Number}
   * @function
   */
  // cc.radiansToDegrees = function (angle) {
  //   return angle * cc.DEG;
  // };
  export const radiansToDegrees = (angle: number) => {
    return angle * cc.DEG;
  };

  /**
   * @constant
   * @type Number
   */
  // cc.REPEAT_FOREVER = 0xffffffff;
  export const REPEAT_FOREVER = 0xffffffff;

  /**
   * Helpful macro that setups the GL server state, the correct GL program and sets the Model View Projection matrix
   * @param {cc.Node} node setup node
   * @function
   */
  export const nodeDrawSetup = (node: cc.Node) => {
    // //cc.glEnable(node._glServerState);
    if (node._shaderProgram) {
      // //cc._renderContext.useProgram(node._shaderProgram._programObj);
      node._shaderProgram.use();
      // TODO
      (<any>(
        node
      ))._shaderProgram.setUniformForModelViewAndProjectionMatrixWithMat4();
    }
  };

  /**
   * <p>
   *     GL states that are enabled:<br/>
   *       - GL_TEXTURE_2D<br/>
   *       - GL_VERTEX_ARRAY<br/>
   *       - GL_TEXTURE_COORD_ARRAY<br/>
   *       - GL_COLOR_ARRAY<br/>
   * </p>
   * @function
   */
  export const enableDefaultGLStates = () => {
    //TODO OPENGL STUFF
    /*
       glEnableClientState(GL_VERTEX_ARRAY);
       glEnableClientState(GL_COLOR_ARRAY);
       glEnableClientState(GL_TEXTURE_COORD_ARRAY);
       glEnable(GL_TEXTURE_2D);*/
  };

  /**
   * <p>
   *   Disable default GL states:<br/>
   *     - GL_TEXTURE_2D<br/>
   *     - GL_TEXTURE_COORD_ARRAY<br/>
   *     - GL_COLOR_ARRAY<br/>
   * </p>
   * @function
   */
  export const disableDefaultGLStates = () => {
    //TODO OPENGL
    /*
       glDisable(GL_TEXTURE_2D);
       glDisableClientState(GL_COLOR_ARRAY);
       glDisableClientState(GL_TEXTURE_COORD_ARRAY);
       glDisableClientState(GL_VERTEX_ARRAY);
       */
  };

  /**
   * <p>
   *  Increments the GL Draws counts by one.<br/>
   *  The number of calls per frame are displayed on the screen when the CCDirector's stats are enabled.<br/>
   * </p>
   * @param {Number} addNumber
   * @function
   */
  // cc.incrementGLDraws = function (addNumber) {
  //   cc.g_NumberOfDraws += addNumber;
  // };
  export const incrementGLDraws = (addNumber: number) => {
    g_NumberOfDraws += addNumber;
  };

  /**
   * @constant
   * @type Number
   */
  export const FLT_EPSILON = 0.0000001192092896;

  /**
   * <p>
   *     On Mac it returns 1;<br/>
   *     On iPhone it returns 2 if RetinaDisplay is On. Otherwise it returns 1
   * </p>
   * @function
   */
  export const contentScaleFactor = cc.IS_RETINA_DISPLAY_SUPPORTED
    ? () => {
        return cc.director.getContentScaleFactor();
      }
    : () => {
        return 1;
      };

  /**
   * Converts a Point in points to pixels
   * @param {cc.Point} points
   * @return {cc.Point}
   * @function
   */
  // cc.pointPointsToPixels = function (points) {
  //   var scale = cc.contentScaleFactor();
  //   return cc.p(points.x * scale, points.y * scale);
  // };
  export const pointPointsToPixels = (points: cc.Point) => {
    const scale = cc.contentScaleFactor();
    return cc.p(points.x * scale, points.y * scale);
  };

  /**
   * Converts a Point in pixels to points
   * @param {Point} pixels
   * @function
   */
  export const pointPixelsToPoints = (pixels: cc.Point) => {
    const scale = cc.contentScaleFactor();
    return cc.p(pixels.x / scale, pixels.y / scale);
  };

  export const _pointPixelsToPointsOut = (
    pixels: cc.Point,
    outPoint: cc.Point,
  ) => {
    const scale = cc.contentScaleFactor();
    outPoint.x = pixels.x / scale;
    outPoint.y = pixels.y / scale;
  };

  /**
   * Converts a Size in points to pixels
   * @param {cc.Size} sizeInPoints
   * @return {cc.Size}
   * @function
   */
  export const sizePointsToPixels = (sizeInPoints: cc.Size) => {
    const scale = cc.contentScaleFactor();
    return cc.size(sizeInPoints.width * scale, sizeInPoints.height * scale);
  };

  /**
   * Converts a size in pixels to points
   * @param {cc.Size} sizeInPixels
   * @return {cc.Size}
   * @function
   */
  export const sizePixelsToPoints = (sizeInPixels: cc.Size) => {
    const scale = cc.contentScaleFactor();
    return cc.size(sizeInPixels.width / scale, sizeInPixels.height / scale);
  };

  export const _sizePixelsToPointsOut = (
    sizeInPixels: cc.Size,
    outSize: cc.Size,
  ) => {
    const scale = cc.contentScaleFactor();
    outSize.width = sizeInPixels.width / scale;
    outSize.height = sizeInPixels.height / scale;
  };

  /**
   * Converts a rect in pixels to points
   * @param {cc.Rect} pixel
   * @function
   */
  export const rectPixelsToPoints = cc.IS_RETINA_DISPLAY_SUPPORTED
    ? function (pixel: cc.Rect) {
        var scale = cc.contentScaleFactor();
        return cc.rect(
          pixel.x / scale,
          pixel.y / scale,
          pixel.width / scale,
          pixel.height / scale,
        );
      }
    : function (p: cc.Rect) {
        return p;
      };

  /**
   * Converts a rect in points to pixels
   * @param {cc.Rect} point
   * @function
   */
  export const rectPointsToPixels = cc.IS_RETINA_DISPLAY_SUPPORTED
    ? function (point: cc.Rect) {
        var scale = cc.contentScaleFactor();
        return cc.rect(
          point.x * scale,
          point.y * scale,
          point.width * scale,
          point.height * scale,
        );
      }
    : function (p: cc.Rect) {
        return p;
      };

  export const checkGLErrorDebug = function () {
    // TODO
    // if (cc.renderMode == cc.game.RENDER_TYPE_WEBGL) {
    //   var _error = cc._renderContext.getError();
    //   if (_error) {
    //     cc.log(CC._localZOrder.checkGLErrorDebug, _error);
    //   }
    // }
  };

  //
  // Reusable objects
  //
  // cc._reuse_p = [
  //   { x: 0, y: 0 },
  //   { x: 0, y: 0 },
  //   { x: 0, y: 0 },
  //   { x: 0, y: 0 },
  // ];
  // cc._reuse_p_index = 0;

  // cc._reuse_color3b = { r: 255, g: 255, b: 255 };
  // cc._reuse_color4b = { r: 255, g: 255, b: 255, a: 255 };

  //

  /**
   * Clamp a value between from and to.
   * @param {Number} value
   * @param {Number} min_inclusive
   * @param {Number} max_inclusive
   * @return {Number}
   */
  export const clampf = (
    value: number,
    min_inclusive: number,
    max_inclusive: number,
  ) => {
    if (min_inclusive > max_inclusive) {
      var temp = min_inclusive;
      min_inclusive = max_inclusive;
      max_inclusive = temp;
    }
    return value < min_inclusive
      ? min_inclusive
      : value < max_inclusive
        ? value
        : max_inclusive;
  };

  // //
  // // Grid
  // //
  // cc._g = function (x, y) {
  //   cc._reuse_grid.x = x;
  //   cc._reuse_grid.y = y;
  //   return cc._reuse_grid;
  // };

  // var ConfigType = {
  //   NONE: 0,
  //   COCOSTUDIO: 1,
  // };

  // var __onParseConfig = function (type, str) {
  //   if (type === ConfigType.COCOSTUDIO) {
  //     ccs.triggerManager.parse(JSON.parse(str));
  //   }
  // };

  let _windowTimeIntervalId = 0;
  let _windowTimeFunHash: { [key: number]: WindowTimeFun } = {};
  class WindowTimeFun extends cc.Class {
    _code: Function | null = null;
    _intervalId: number = 0;
    _args: any[] | null = null;
    constructor(code: any) {
      super();
      this._intervalId = _windowTimeIntervalId++;
      this._code = code;
    }
    fun() {
      if (!this._code) return;
      const code = this._code;
      code(this._args);
    }
  }

  /**
   * overwrite window's setTimeout
   @param {Function} code
   @param {number} delay
   @return {number}
   */
  export const setTimeout = function (code: Function, delay: number) {
    const target = new WindowTimeFun(code);
    if (arguments.length > 2)
      target._args = Array.prototype.slice.call(arguments, 2);
    const original = target.fun;
    target.fun = function () {
      original.apply(this, arguments as any);
      clearTimeout(target._intervalId);
    };

    cc.director
      .getScheduler()
      .schedule(
        target.fun,
        target,
        delay / 1000,
        0,
        0,
        false,
        target._intervalId + "",
      );
    _windowTimeFunHash[target._intervalId] = target;
    return target._intervalId;
  };

  /**
   * overwrite window's setInterval
   @param {Function} code
   @param {number} delay
   @return {number}
   */
  export const setInterval = function (code: Function, delay: number) {
    const target = new WindowTimeFun(code);
    if (arguments.length > 2)
      target._args = Array.prototype.slice.call(arguments, 2);
    cc.director
      .getScheduler()
      .schedule(
        target.fun,
        target,
        delay / 1000,
        cc.REPEAT_FOREVER,
        0,
        false,
        target._intervalId + "",
      );
    _windowTimeFunHash[target._intervalId] = target;
    return target._intervalId;
  };

  /**
   * overwrite window's clearInterval
    @param {number} intervalId
  */
  export const clearInterval = (intervalId: number) => {
    const target = _windowTimeFunHash[intervalId];
    if (target) {
      cc.director.getScheduler().unschedule(target._intervalId + "", target);
      delete _windowTimeFunHash[intervalId];
    }
  };

  export const clearTimeout = clearInterval;

  // event listener type
  cc.EventListener.UNKNOWN = 0;
  cc.EventListener.TOUCH_ONE_BY_ONE = 1;
  cc.EventListener.TOUCH_ALL_AT_ONCE = 2;
  cc.EventListener.KEYBOARD = 3;
  cc.EventListener.MOUSE = 4;
  cc.EventListener.ACCELERATION = 5;
  cc.EventListener.FOCUS = 6;

  //game controller 7
  cc.EventListener.CUSTOM = 8;

  cc.EventListener.create = function (argObj: {
    event?: number;
    [key: string]: any;
  }) {
    if (!argObj || !argObj.event) {
      throw "Invalid parameter.";
    }
    const listenerType = argObj.event;
    delete argObj.event;

    let listener = null;
    if (listenerType === cc.EventListener.TOUCH_ONE_BY_ONE) {
      // TODO
      listener = (<any>cc).EventListenerTouchOneByOne.create();
      if (argObj.swallowTouches) {
        listener.setSwallowTouches(argObj.swallowTouches);
      }
    } else if (listenerType === cc.EventListener.TOUCH_ALL_AT_ONCE)
      // TODO
      listener = (<any>cc).EventListenerTouchAllAtOnce.create();
    else if (listenerType === cc.EventListener.MOUSE)
      // TODO
      listener = (<any>cc).EventListenerMouse.create();
    else if (listenerType === cc.EventListener.CUSTOM) {
      // TODO
      listener = (<any>cc).EventListenerCustom.create(
        argObj.eventName,
        argObj.callback,
      );
      delete argObj.eventName;
      delete argObj.callback;
    } else if (listenerType === cc.EventListener.KEYBOARD)
      listener = (<any>cc).EventListenerKeyboard.create();
    else if (listenerType === cc.EventListener.ACCELERATION) {
      listener = (<any>cc).EventListenerAcceleration.create(argObj.callback);
      delete argObj.callback;
    } else if (listenerType === cc.EventListener.FOCUS) {
      listener = (<any>cc).EventListenerFocus.create();
    } else {
      cc.log("Error: Invalid listener type.");
    }

    for (const key in argObj) {
      // Temporary fix for EventMouse to support getDelta functions (doesn't exist in Cocos2d-x)
      if (key == "onMouseDown" || key == "onMouseMove")
        listener["_" + key] = argObj[key];
      else listener[key] = argObj[key];
    }

    return listener;
  };

  // Event manager
  cc.eventManager.addListener = function (listener, nodeOrPriority) {
    if (!(listener instanceof cc.EventListener)) {
      listener = cc.EventListener.create(listener as any);
    }

    if (typeof nodeOrPriority == "number") {
      if (nodeOrPriority == 0) {
        cc.log(
          "0 priority is forbidden for fixed priority since it's used for scene graph based priority.",
        );
        return;
      }

      cc.eventManager.addEventListenerWithFixedPriority(
        listener,
        nodeOrPriority,
      );
    } else {
      cc.eventManager.addEventListenerWithSceneGraphPriority(
        listener,
        nodeOrPriority,
      );
    }

    return listener! as cc.EventListener;
  };

  cc.eventManager.dispatchCustomEvent = function (
    eventName: string,
    optionalUserData?: any,
  ) {
    const ev = new cc.EventCustom(eventName);
    ev.setUserData(optionalUserData);
    this.dispatchEvent(ev);
  };

  cc.EventCustom.prototype.setUserData = function (userData) {
    this._userData = userData;
  };

  cc.EventCustom.prototype.getUserData = function () {
    return this._userData;
  };

  // cc.inputManager = {
  //   setAccelerometerEnabled: cc.Device.setAccelerometerEnabled,
  //   setAccelerometerInterval: cc.Device.setAccelerometerInterval,
  //   getDPI: cc.Device.getDPI,
  // };

  // cc.EventListenerTouchOneByOne.prototype.clone = function () {
  //   var ret = cc.EventListenerTouchOneByOne.create();
  //   ret.onTouchBegan = this.onTouchBegan;
  //   ret.onTouchMoved = this.onTouchMoved;
  //   ret.onTouchEnded = this.onTouchEnded;
  //   ret.onTouchCancelled = this.onTouchCancelled;
  //   ret.setSwallowTouches(this.isSwallowTouches());
  //   return ret;
  // };

  // cc.EventListenerTouchAllAtOnce.prototype.clone = function () {
  //   var ret = cc.EventListenerTouchAllAtOnce.create();
  //   ret.onTouchesBegan = this.onTouchesBegan;
  //   ret.onTouchesMoved = this.onTouchesMoved;
  //   ret.onTouchesEnded = this.onTouchesEnded;
  //   ret.onTouchesCancelled = this.onTouchesCancelled;
  //   return ret;
  // };

  // cc.EventListenerKeyboard.prototype.clone = function () {
  //   var ret = cc.EventListenerKeyboard.create();
  //   ret.onKeyPressed = this.onKeyPressed;
  //   ret.onKeyReleased = this.onKeyReleased;
  //   return ret;
  // };

  // cc.EventListenerFocus.prototype.clone = function () {
  //   var ret = cc.EventListenerFocus.create();
  //   ret.onFocusChanged = this.onFocusChanged;
  //   return ret;
  // };

  // cc.EventListenerMouse.prototype.clone = function () {
  //   var ret = cc.EventListenerMouse.create();
  //   ret._onMouseDown = this._onMouseDown;
  //   ret._onMouseMove = this._onMouseMove;
  //   ret.onMouseUp = this.onMouseUp;
  //   ret.onMouseScroll = this.onMouseScroll;
  //   return ret;
  // };
  // cc.EventListenerMouse.prototype.onMouseMove = function (event) {
  //   if (!this._onMouseMove) return;
  //   event._listener = this;
  //   this._onMouseMove(event);
  //   this._previousX = event.getLocationX();
  //   this._previousY = event.getLocationY();
  // };
  // cc.EventListenerMouse.prototype.onMouseDown = function (event) {
  //   if (!this._onMouseDown) return;
  //   event._listener = this;
  //   this._previousX = event.getLocationX();
  //   this._previousY = event.getLocationY();
  //   this._onMouseDown(event);
  // };

  // cc.EventListenerKeyboard.prototype._onKeyPressed = function (keyCode, event) {
  //   if (!this.onKeyPressed) return;
  //   this.onKeyPressed(jsbKeyArr[keyCode], event);
  // };

  // cc.EventListenerKeyboard.prototype._onKeyReleased = function (keyCode, event) {
  //   if (!this.onKeyReleased) return;
  //   this.onKeyReleased(jsbKeyArr[keyCode], event);
  // };

  // cc.EventMouse.prototype.getLocation = function () {
  //   return { x: this.getLocationX(), y: this.getLocationY() };
  // };

  // cc.EventMouse.prototype.getLocationInView = function () {
  //   return {
  //     x: this.getLocationX(),
  //     y: cc.view.getDesignResolutionSize().height - this.getLocationY(),
  //   };
  // };

  // // Temporary fix for EventMouse to support getDelta functions (doesn't exist in Cocos2d-x)
  // cc.EventMouse.prototype.getDelta = function () {
  //   if (isNaN(this._listener._previousX)) {
  //     this._listener._previousX = this.getLocationX();
  //     this._listener._previousY = this.getLocationY();
  //   }
  //   return {
  //     x: this.getLocationX() - this._listener._previousX,
  //     y: this.getLocationY() - this._listener._previousY,
  //   };
  // };

  // cc.EventMouse.prototype.getDeltaX = function () {
  //   if (isNaN(this._listener._previousX)) {
  //     this._listener._previousX = this.getLocationX();
  //     this._listener._previousY = this.getLocationY();
  //   }
  //   return this.getLocationX() - this._listener._previousX;
  // };

  // cc.EventMouse.prototype.getDeltaY = function () {
  //   if (isNaN(this._listener._previousX)) {
  //     this._listener._previousX = this.getLocationX();
  //     this._listener._previousY = this.getLocationY();
  //   }
  //   return this.getLocationY() - this._listener._previousY;
  // };

  // cc.Touch.prototype.getLocationX = function () {
  //   return this.getLocation().x;
  // };

  // cc.Touch.prototype.getLocationY = function () {
  //   return this.getLocation().y;
  // };

  // cc.Director.EVENT_PROJECTION_CHANGED = "director_projection_changed";
  // cc.Director.EVENT_AFTER_DRAW = "director_after_draw";
  // cc.Director.EVENT_AFTER_VISIT = "director_after_visit";
  // cc.Director.EVENT_BEFORE_UPDATE = "director_before_update";
  // cc.Director.EVENT_AFTER_UPDATE = "director_after_update";
  // cc.Director.EVENT_BEFORE_SCENE_LAUNCH = "director_before_scene_launch";

  // cc.Director.prototype.runScene = cc.Director.prototype.replaceScene;

  // cc.visibleRect = {
  //   topLeft: cc.p(0, 0),
  //   topRight: cc.p(0, 0),
  //   top: cc.p(0, 0),
  //   bottomLeft: cc.p(0, 0),
  //   bottomRight: cc.p(0, 0),
  //   bottom: cc.p(0, 0),
  //   center: cc.p(0, 0),
  //   left: cc.p(0, 0),
  //   right: cc.p(0, 0),
  //   width: 0,
  //   height: 0,

  //   init: function () {
  //     var origin = cc.director.getVisibleOrigin();
  //     var size = cc.director.getVisibleSize();
  //     var w = (this.width = size.width);
  //     var h = (this.height = size.height);
  //     var l = origin.x,
  //       b = origin.y,
  //       t = b + h,
  //       r = l + w;

  //     //top
  //     this.topLeft.x = l;
  //     this.topLeft.y = t;
  //     this.topRight.x = r;
  //     this.topRight.y = t;
  //     this.top.x = l + w / 2;
  //     this.top.y = t;

  //     //bottom
  //     this.bottomLeft.x = l;
  //     this.bottomLeft.y = b;
  //     this.bottomRight.x = r;
  //     this.bottomRight.y = b;
  //     this.bottom.x = l + w / 2;
  //     this.bottom.y = b;

  //     //center
  //     this.center.x = l + w / 2;
  //     this.center.y = b + h / 2;

  //     //left
  //     this.left.x = l;
  //     this.left.y = b + h / 2;

  //     //right
  //     this.right.x = r;
  //     this.right.y = b + h / 2;
  //   },
  // };
  // cc.visibleRect.init();

  // //
  // // setBlendFunc JS API Wrapper
  // //

  // var protoHasBlend = [
  //   cc.AtlasNode.prototype,
  //   cc.DrawNode.prototype,
  //   cc.LabelTTF.prototype,
  //   cc.SpriteBatchNode.prototype,
  //   cc.LabelBMFont.prototype,
  //   cc.LayerColor.prototype,
  //   cc.MotionStreak.prototype,
  //   cc.Sprite.prototype,
  //   cc.ParticleBatchNode.prototype,
  //   cc.ParticleSystem.prototype,
  // ];

  // var templateSetBlendFunc = function (src, dst) {
  //   var blendf;
  //   if (dst === undefined) blendf = src;
  //   else blendf = { src: src, dst: dst };
  //   this._setBlendFunc(blendf);
  // };
  // for (var i = 0, l = protoHasBlend.length; i < l; i++) {
  //   var proto = protoHasBlend[i];
  //   proto._setBlendFunc = proto.setBlendFunc;
  //   proto.setBlendFunc = templateSetBlendFunc;
  // }

  // //
  // // Ease actions JS API Wrapper
  // //

  // var easeActions = {
  //   easeIn: 0,
  //   easeOut: 1,
  //   easeInOut: 2,
  //   easeExponentialIn: 3,
  //   easeExponentialOut: 4,
  //   easeExponentialInOut: 5,
  //   easeSineIn: 6,
  //   easeSineOut: 7,
  //   easeSineInOut: 8,
  //   easeElasticIn: 9,
  //   easeElasticOut: 10,
  //   easeElasticInOut: 11,
  //   easeBounceIn: 12,
  //   easeBounceOut: 13,
  //   easeBounceInOut: 14,
  //   easeBackIn: 15,
  //   easeBackOut: 16,
  //   easeBackInOut: 17,

  //   easeBezierAction: 18,
  //   easeQuadraticActionIn: 19,
  //   easeQuadraticActionOut: 20,
  //   easeQuadraticActionInOut: 21,
  //   easeQuarticActionIn: 22,
  //   easeQuarticActionOut: 23,
  //   easeQuarticActionInOut: 24,
  //   easeQuinticActionIn: 25,
  //   easeQuinticActionOut: 26,
  //   easeQuinticActionInOut: 27,
  //   easeCircleActionIn: 28,
  //   easeCircleActionOut: 29,
  //   easeCircleActionInOut: 30,
  //   easeCubicActionIn: 31,
  //   easeCubicActionOut: 32,
  //   easeCubicActionInOut: 33,
  // };

  // function templateEaseActions(actionTag) {
  //   return function (param, param2, param3, param4) {
  //     return {
  //       tag: actionTag,
  //       param: param,
  //       param2: param2,
  //       param3: param3,
  //       param4: param4,
  //     };
  //   };
  // }

  // for (var a in easeActions) {
  //   var actionTag = easeActions[a];
  //   cc[a] = templateEaseActions(actionTag);
  // }

  // // Action2d
  // cc.action = cc.Action.create;
  // cc.speed = cc.Speed.create;
  // cc.follow = cc.Follow.create;
  // cc.orbitCamera = cc.OrbitCamera.create;
  // cc.cardinalSplineTo = cc.CardinalSplineTo.create;
  // cc.cardinalSplineBy = cc.CardinalSplineBy.create;
  // cc.catmullRomTo = cc.CatmullRomTo.create;
  // cc.catmullRomBy = cc.CatmullRomBy.create;
  // cc.show = cc.Show.create;
  // cc.hide = cc.Hide.create;
  // cc.toggleVisibility = cc.ToggleVisibility.create;
  // cc.removeSelf = cc.RemoveSelf.create;
  // cc.flipX = cc.FlipX.create;
  // cc.flipY = cc.FlipY.create;
  // // cc.place = cc.Place.create;
  // cc.callFunc = cc.CallFunc.create;
  // cc.actionInterval = cc.ActionInterval.create;
  // cc.sequence = cc.Sequence.create;
  // cc.repeat = cc.Repeat.create;
  // cc.repeatForever = cc.RepeatForever.create;
  // cc.spawn = cc.Spawn.create;
  // cc.rotateTo = cc.RotateTo.create;
  // cc.rotateBy = cc.RotateBy.create;
  // //cc.moveBy = cc.MoveBy.create;
  // //cc.moveTo = cc.MoveTo.create;
  // cc.skewTo = cc.SkewTo.create;
  // cc.skewBy = cc.SkewBy.create;
  // //cc.jumpBy = cc.JumpBy.create;
  // //cc.jumpTo = cc.JumpTo.create;
  // cc.bezierBy = cc.BezierBy.create;
  // cc.bezierTo = cc.BezierTo.create;
  // cc.scaleTo = cc.ScaleTo.create;
  // cc.scaleBy = cc.ScaleBy.create;
  // cc.blink = cc.Blink.create;
  // cc.fadeTo = cc.FadeTo.create;
  // cc.fadeIn = cc.FadeIn.create;
  // cc.fadeOut = cc.FadeOut.create;
  // cc.tintTo = cc.TintTo.create;
  // cc.tintBy = cc.TintBy.create;
  // cc.delayTime = cc.DelayTime.create;
  // cc.reverseTime = cc.ReverseTime.create;
  // cc.animate = cc.Animate.create;
  // cc.targetedAction = cc.TargetedAction.create;
  // cc.actionTween = cc.ActionTween.create;

  // cc.Place._create = cc.Place.create;
  // cc.place = cc.Place.create = function (posOrX, y) {
  //   if (undefined === y) {
  //     return cc.Place._create(posOrX);
  //   } else {
  //     return cc.Place._create(cc.p(posOrX, y));
  //   }
  // };
  // cc.MoveTo._create = cc.MoveTo.create;
  // cc.moveTo = cc.MoveTo.create = function (duration, posOrX, y) {
  //   if (undefined === y) {
  //     return cc.MoveTo._create(duration, posOrX);
  //   } else {
  //     return cc.MoveTo._create(duration, cc.p(posOrX, y));
  //   }
  // };
  // cc.MoveBy._create = cc.MoveBy.create;
  // cc.moveBy = cc.MoveBy.create = function (duration, posOrX, y) {
  //   if (undefined === y) {
  //     return cc.MoveBy._create(duration, posOrX);
  //   } else {
  //     return cc.MoveBy._create(duration, cc.p(posOrX, y));
  //   }
  // };
  // cc.JumpTo._create = cc.JumpTo.create;
  // cc.jumpTo = cc.JumpTo.create = function (duration, position, y, height, jumps) {
  //   if (undefined === jumps) {
  //     jumps = height;
  //     height = y;
  //     return cc.JumpTo._create(duration, position, height, jumps);
  //   } else {
  //     return cc.JumpTo._create(duration, cc.p(position, y), height, jumps);
  //   }
  // };
  // cc.JumpBy._create = cc.JumpBy.create;
  // cc.jumpBy = cc.JumpBy.create = function (duration, position, y, height, jumps) {
  //   if (undefined === jumps) {
  //     jumps = height;
  //     height = y;
  //     return cc.JumpBy._create(duration, position, height, jumps);
  //   } else {
  //     return cc.JumpBy._create(duration, cc.p(position, y), height, jumps);
  //   }
  // };

  // // Actions3d
  // cc.gridAction = cc.GridAction.create;
  // cc.grid3DAction = cc.Grid3DAction.create;
  // cc.tiledGrid3DAction = cc.TiledGrid3DAction.create;
  // cc.stopGrid = cc.StopGrid.create;
  // cc.reuseGrid = cc.ReuseGrid.create;
  // cc.waves3D = cc.Waves3D.create;
  // cc.flipX3D = cc.FlipX3D.create;
  // cc.flipY3D = cc.FlipY3D.create;
  // cc.lens3D = cc.Lens3D.create;
  // cc.ripple3D = cc.Ripple3D.create;
  // cc.shaky3D = cc.Shaky3D.create;
  // cc.liquid = cc.Liquid.create;
  // cc.waves = cc.Waves.create;
  // cc.twirl = cc.Twirl.create;
  // cc.pageTurn3D = cc.PageTurn3D.create;
  // cc.shakyTiles3D = cc.ShakyTiles3D.create;
  // cc.shatteredTiles3D = cc.ShatteredTiles3D.create;
  // cc.shuffleTiles = cc.ShuffleTiles.create;
  // cc.fadeOutTRTiles = cc.FadeOutTRTiles.create;
  // cc.fadeOutBLTiles = cc.FadeOutBLTiles.create;
  // cc.fadeOutUpTiles = cc.FadeOutUpTiles.create;
  // cc.fadeOutDownTiles = cc.FadeOutDownTiles.create;
  // cc.turnOffTiles = cc.TurnOffTiles.create;
  // cc.wavesTiles3D = cc.WavesTiles3D.create;
  // cc.jumpTiles3D = cc.JumpTiles3D.create;
  // cc.splitRows = cc.SplitRows.create;
  // cc.splitCols = cc.SplitCols.create;
  // cc.progressTo = cc.ProgressTo.create;
  // cc.progressFromTo = cc.ProgressFromTo.create;

  // // Speed functions
  // cc.Speed.prototype.speed = cc.ActionInterval.prototype.speed = function (
  //   speed,
  // ) {
  //   //    if (speed < 0) {
  //   //        cc.warn("cc.ActionInterval#speed : Speed must not be negative");
  //   //        return;
  //   //    }
  //   var action = this,
  //     found = false;
  //   while (action.getInnerAction && !found) {
  //     if (action instanceof cc.Speed) {
  //       found = true;
  //     } else {
  //       action = action.getInnerAction();
  //     }
  //   }
  //   if (found) {
  //     speed = speed * action._getSpeed();
  //     action._setSpeed(speed);
  //   } else {
  //     this._speed(speed);
  //   }
  //   return this;
  // };
  // cc.Speed.prototype.setSpeed = cc.ActionInterval.prototype.setSpeed = function (
  //   speed,
  // ) {
  //   //    if (speed < 0) {
  //   //        cc.warn("cc.ActionInterval#setSpeed : Speed must not be negative");
  //   //        return;
  //   //    }
  //   var action = this,
  //     found = false;
  //   while (action.getInnerAction && !found) {
  //     if (action instanceof cc.Speed) {
  //       found = true;
  //     } else {
  //       action = action.getInnerAction();
  //     }
  //   }
  //   if (found) {
  //     action._setSpeed(speed);
  //   } else {
  //     this._speed(speed);
  //   }
  // };
  // cc.Speed.prototype.getSpeed = cc.ActionInterval.prototype.getSpeed =
  //   function () {
  //     var action = this,
  //       found = false;
  //     while (action.getInnerAction && !found) {
  //       if (action instanceof cc.Speed) {
  //         found = true;
  //       } else {
  //         action = action.getInnerAction();
  //       }
  //     }
  //     if (found) {
  //       return action._getSpeed();
  //     } else {
  //       return 1;
  //     }
  //   };

  // //
  // // cc.BlendFunc
  // //
  // /**
  //  * Blend Function used for textures
  //  * @Class cc.BlendFunc
  //  * @Constructor
  //  * @param {Number} src1 source blend function
  //  * @param {Number} dst1 destination blend function
  //  */
  // cc.BlendFunc = function (src1, dst1) {
  //   this.src = src1;
  //   this.dst = dst1;
  // };

  // cc.BlendFunc._disable = function () {
  //   return new cc.BlendFunc(cc.ONE, cc.ZERO);
  // };
  // cc.BlendFunc._alphaPremultiplied = function () {
  //   return new cc.BlendFunc(cc.ONE, cc.ONE_MINUS_SRC_ALPHA);
  // };
  // cc.BlendFunc._alphaNonPremultiplied = function () {
  //   return new cc.BlendFunc(cc.SRC_ALPHA, cc.ONE_MINUS_SRC_ALPHA);
  // };
  // cc.BlendFunc._additive = function () {
  //   return new cc.BlendFunc(cc.SRC_ALPHA, cc.ONE);
  // };

  // /** @expose */
  // cc.BlendFunc.DISABLE;
  // cc.defineGetterSetter(cc.BlendFunc, "DISABLE", cc.BlendFunc._disable);
  // /** @expose */
  // cc.BlendFunc.ALPHA_PREMULTIPLIED;
  // cc.defineGetterSetter(
  //   cc.BlendFunc,
  //   "ALPHA_PREMULTIPLIED",
  //   cc.BlendFunc._alphaPremultiplied,
  // );
  // /** @expose */
  // cc.BlendFunc.ALPHA_NON_PREMULTIPLIED;
  // cc.defineGetterSetter(
  //   cc.BlendFunc,
  //   "ALPHA_NON_PREMULTIPLIED",
  //   cc.BlendFunc._alphaNonPremultiplied,
  // );
  // /** @expose */
  // cc.BlendFunc.ADDITIVE;
  // cc.defineGetterSetter(cc.BlendFunc, "ADDITIVE", cc.BlendFunc._additive);

  // cc.GLProgram.prototype.setUniformLocationWithMatrix2fv = function () {
  //   var tempArray = Array.prototype.slice.call(arguments);
  //   tempArray = Array.prototype.concat.call(tempArray, 2);
  //   this.setUniformLocationWithMatrixfvUnion.apply(this, tempArray);
  // };

  // cc.GLProgram.prototype.setUniformLocationWithMatrix3fv = function () {
  //   var tempArray = Array.prototype.slice.call(arguments);
  //   tempArray = Array.prototype.concat.call(tempArray, 3);
  //   this.setUniformLocationWithMatrixfvUnion.apply(this, tempArray);
  // };
  // cc.GLProgram.prototype.setUniformLocationWithMatrix4fv = function () {
  //   var tempArray = Array.prototype.slice.call(arguments);
  //   tempArray = Array.prototype.concat.call(tempArray, 4);
  //   this.setUniformLocationWithMatrixfvUnion.apply(this, tempArray);
  // };

  // var jsbSetUniformCallback = cc.GLProgramState.prototype.setUniformCallback;
  // cc.GLProgramState.prototype.setUniformCallback = function (uniform, callback) {
  //   jsbSetUniformCallback.call(this, uniform, callback);
  // };

  // //
  // // Script Component
  // //
  // cc._ComponentJS = cc.ComponentJS;
  // cc._ComponentJS.extend = cc.Class.extend;
  // cc.ComponentJS = function (filename) {
  //   var comp = cc._ComponentJS.create(filename);
  //   var res = comp.getScriptObject();
  //   return res;
  // };
  // cc.ComponentJS.extend = function (prop) {
  //   return cc._ComponentJS.extend(prop);
  // };

  // //
  // // 3D module rename to jsb namespace
  // //
  // jsb.BaseLight = cc.BaseLight;
  // delete cc.BaseLight;
  // jsb.DirectionLight = cc.DirectionLight;
  // delete cc.DirectionLight;
  // jsb.PointLight = cc.PointLight;
  // delete cc.PointLight;
  // jsb.SpotLight = cc.SpotLight;
  // delete cc.SpotLight;
  // jsb.AmbientLight = cc.AmbientLight;
  // delete cc.AmbientLight;
}
