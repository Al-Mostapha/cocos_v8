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

declare const cc: any;

// //
// // cocos2d constants
// //
// 
// // CCConfig.js
// //
// cc.ENGINE_VERSION = "Cocos2d-JS v3.17";

cc.ENGINE_VERSION = "Cocos2d-JS v3.17";

// cc.FIX_ARTIFACTS_BY_STRECHING_TEXEL = 0;
// cc.DIRECTOR_STATS_POSITION = {x: 0, y: 0};
// cc.DIRECTOR_FPS_INTERVAL = 0.5;
// ... (All constants follow)

cc.FIX_ARTIFACTS_BY_STRECHING_TEXEL = 0;
cc.DIRECTOR_STATS_POSITION = { x: 0, y: 0 };
cc.DIRECTOR_FPS_INTERVAL = 0.5;
cc.COCOSNODE_RENDER_SUBPIXEL = 1;
cc.SPRITEBATCHNODE_RENDER_SUBPIXEL = 1;
cc.OPTIMIZE_BLEND_FUNC_FOR_PREMULTIPLIED_ALPHA = 0;
cc.TEXTURE_ATLAS_USE_TRIANGLE_STRIP = 0;
cc.TEXTURE_ATLAS_USE_VAO = 0;
cc.TEXTURE_NPOT_SUPPORT = 0;
cc.RETINA_DISPLAY_SUPPORT = 1;
cc.RETINA_DISPLAY_FILENAME_SUFFIX = "-hd";
cc.USE_LA88_LABELS = 1;
cc.SPRITE_DEBUG_DRAW = 0;
cc.SPRITEBATCHNODE_DEBUG_DRAW = 0;
cc.LABELBMFONT_DEBUG_DRAW = 0;
cc.LABELATLAS_DEBUG_DRAW = 0;
cc.IS_RETINA_DISPLAY_SUPPORTED = 1;
cc.DEFAULT_ENGINE = cc.ENGINE_VERSION + "-native";
cc.ENABLE_STACKABLE_ACTIONS = 1;
cc.ENABLE_GL_STATE_CACHE = 1;

// Resolution policies
interface ResolutionPolicy {
    EXACT_FIT: number;
    NO_BORDER: number;
    SHOW_ALL: number;
    FIXED_HEIGHT: number;
    FIXED_WIDTH: number;
    UNKNOWN: number;
}

cc.ResolutionPolicy = {
    EXACT_FIT: 0,
    NO_BORDER: 1,
    SHOW_ALL: 2,
    FIXED_HEIGHT: 3,
    FIXED_WIDTH: 4,
    UNKNOWN: 5
} as ResolutionPolicy;

// Language constants
cc.LANGUAGE_ENGLISH = 0;
cc.LANGUAGE_CHINESE = 1;
cc.LANGUAGE_FRENCH = 2;
cc.LANGUAGE_ITALIAN = 3;
cc.LANGUAGE_GERMAN = 4;
cc.LANGUAGE_SPANISH = 5;
cc.LANGUAGE_RUSSIAN = 6;
cc.LANGUAGE_KOREAN = 7;
cc.LANGUAGE_JAPANESE = 8;
cc.LANGUAGE_HUNGARIAN = 9;
cc.LANGUAGE_PORTUGUESE = 10;
cc.LANGUAGE_ARABIC = 11;

// Director projection constants
cc.Director.PROJECTION_2D = 0;
cc.Director.PROJECTION_3D = 1;
cc.Director.PROJECTION_CUSTOM = 3;
cc.Director.PROJECTION_DEFAULT = cc.Director.PROJECTION_3D;

// Device orientation constants
cc.DEVICE_ORIENTATION_PORTRAIT = 0;
cc.DEVICE_ORIENTATION_LANDSCAPE_LEFT = 1;
cc.DEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN = 2;
cc.DEVICE_ORIENTATION_LANDSCAPE_RIGHT = 3;
cc.DEVICE_MAX_ORIENTATIONS = 2;

// Image format constants
cc.IMAGE_FORMAT_JPEG = 0;
cc.IMAGE_FORMAT_PNG = 1;
cc.IMAGE_FORMAT_RAWDATA = 9;

// Touch constants
cc.TOUCH_ALL_AT_ONCE = 0;
cc.TOUCH_ONE_BY_ONE = 1;

// Transition orientation constants
cc.TRANSITION_ORIENTATION_LEFT_OVER = 0;
cc.TRANSITION_ORIENTATION_RIGHT_OVER = 1;
cc.TRANSITION_ORIENTATION_UP_OVER = 0;
cc.TRANSITION_ORIENTATION_DOWN_OVER = 1;

// Color constants
interface ColorRGB {
    r: number;
    g: number;
    b: number;
}

cc.RED = { r: 255, g: 0, b: 0 } as ColorRGB;
cc.GREEN = { r: 0, g: 255, b: 0 } as ColorRGB;
cc.BLUE = { r: 0, g: 0, b: 255 } as ColorRGB;
cc.BLACK = { r: 0, g: 0, b: 0 } as ColorRGB;
cc.WHITE = { r: 255, g: 255, b: 255 } as ColorRGB;
cc.YELLOW = { r: 255, g: 255, b: 0 } as ColorRGB;

interface Point {
    x: number;
    y: number;
}

cc.POINT_ZERO = { x: 0, y: 0 } as Point;

// Particle constants
cc.PARTICLE_DEFAULT_CAPACITY = 500;

// Menu constants
cc.MENU_STATE_WAITING = 0;
cc.MENU_STATE_TRACKING_TOUCH = 1;
cc.MENU_HANDLER_PRIORITY = -128;
cc.DEFAULT_PADDING = 5;

// Scheduler constants
cc.Scheduler.PRIORITY_SYSTEM = -2147483648;
cc.Scheduler.PRIORITY_NON_SYSTEM = cc.Scheduler.PRIORITY_SYSTEM + 1;

// Texture2D pixel format constants
const Texture2D = cc.Texture2D;

Texture2D.PIXEL_FORMAT_NONE = -1;
Texture2D.PIXEL_FORMAT_AUTO = 0;
Texture2D.PIXEL_FORMAT_BGRA8888 = 1;
Texture2D.PIXEL_FORMAT_RGBA8888 = 2;
Texture2D.PIXEL_FORMAT_RGB888 = 3;
Texture2D.PIXEL_FORMAT_RGB565 = 4;
Texture2D.PIXEL_FORMAT_A8 = 5;
Texture2D.PIXEL_FORMAT_I8 = 6;
Texture2D.PIXEL_FORMAT_AI88 = 7;
Texture2D.PIXEL_FORMAT_RGBA4444 = 8;
Texture2D.PIXEL_FORMAT_RGB5A1 = 9;
Texture2D.PIXEL_FORMAT_PVRTC4 = 10;
Texture2D.PIXEL_FORMAT_PVRTC4A = 11;
Texture2D.PIXEL_FORMAT_PVRTC2 = 11;
Texture2D.PIXEL_FORMAT_PVRTC2A = 13;
Texture2D.PIXEL_FORMAT_ETC = 14;
Texture2D.PIXEL_FORMAT_S3TC_DXT1 = 15;
Texture2D.PIXEL_FORMAT_S3TC_DXT3 = 16;
Texture2D.PIXEL_FORMAT_S3TC_DXT5 = 17;
Texture2D.PIXEL_FORMAT_ATC_RGB = 18;
Texture2D.PIXEL_FORMAT_ATC_EXPLICIT_ALPHA = 19;
Texture2D.PIXEL_FORMAT_ATC_INTERPOLATED_ALPHA = 20;
Texture2D.PIXEL_FORMAT_DEFAULT = Texture2D.PIXEL_FORMAT_AUTO;
Texture2D.defaultPixelFormat = Texture2D.PIXEL_FORMAT_DEFAULT;

// Blend constants
cc.ONE = 1;
cc.ZERO = 0;
cc.SRC_ALPHA = 0x0302;
cc.SRC_ALPHA_SATURATE = 0x308;
cc.SRC_COLOR = 0x300;
cc.DST_ALPHA = 0x304;
cc.DST_COLOR = 0x306;
cc.ONE_MINUS_SRC_ALPHA = 0x0303;
cc.ONE_MINUS_SRC_COLOR = 0x301;
cc.ONE_MINUS_DST_ALPHA = 0x305;
cc.ONE_MINUS_DST_COLOR = 0x0307;
cc.ONE_MINUS_CONSTANT_ALPHA = 0x8004;
cc.ONE_MINUS_CONSTANT_COLOR = 0x8002;

// Texture parameters
cc.LINEAR = 0x2601;
cc.REPEAT = 0x2901;
cc.CLAMP_TO_EDGE = 0x812f;
cc.MIRRORED_REPEAT = 0x8370;

// Vertex attrib flags
cc.VERTEX_ATTRIB_FLAG_NONE = 0;
cc.VERTEX_ATTRIB_FLAG_POSITION = 1 << 0;
cc.VERTEX_ATTRIB_FLAG_COLOR = 1 << 1;
cc.VERTEX_ATTRIB_FLAG_TEX_COORDS = 1 << 2;
cc.VERTEX_ATTRIB_FLAG_POS_COLOR_TEX = (cc.VERTEX_ATTRIB_FLAG_POSITION | cc.VERTEX_ATTRIB_FLAG_COLOR | cc.VERTEX_ATTRIB_FLAG_TEX_COORDS);
cc.GL_ALL = 0;

cc.VERTEX_ATTRIB_POSITION = 0;
cc.VERTEX_ATTRIB_COLOR = 1;
cc.VERTEX_ATTRIB_TEX_COORDS = 2;
cc.VERTEX_ATTRIB_MAX = 3;

// Uniform indices
cc.UNIFORM_PMATRIX = 0;
cc.UNIFORM_MVMATRIX = 1;
cc.UNIFORM_MVPMATRIX = 2;
cc.UNIFORM_TIME = 3;
cc.UNIFORM_SINTIME = 4;
cc.UNIFORM_COSTIME = 5;
cc.UNIFORM_RANDOM01 = 6;
cc.UNIFORM_SAMPLER = 7;
cc.UNIFORM_MAX = 8;

// Shader uniform string names
cc.UNIFORM_TIME_S = "CC_Time";
cc.UNIFORM_COS_TIME_S = 'CC_CosTime';
cc.UNIFORM_COSTIME_S = "CC_CosTime";
cc.UNIFORM_SIN_TIME_S = 'CC_SinTime';
cc.UNIFORM_SINTIME_S = "CC_SinTime";
cc.UNIFORM_PMATRIX_S = "CC_PMatrix";
cc.UNIFORM_MVMATRIX_S = "CC_MVMatrix";
cc.UNIFORM_MVPMATRIX_S = "CC_MVPMatrix";
cc.UNIFORM_P_MATRIX_S = 'CC_PMatrix';
cc.UNIFORM_MV_MATRIX_S = 'CC_MVMatrix';
cc.UNIFORM_MVP_MATRIX_S = 'CC_MVPMatrix';
cc.UNIFORM_RANDOM01_S = 'CC_Random01';
cc.UNIFORM_SAMPLER_S = 'CC_Texture0';
cc.UNIFORM_ALPHA_TEST_VALUE_S = "CC_AlphaValue";

// Item and tag constants
cc.ITEM_SIZE = 32;
cc.CURRENT_ITEM = 0xc0c05001;
cc.ZOOM_ACTION_TAG = 0xc0c05002;
cc.NORMAL_TAG = 8801;
cc.SELECTED_TAG = 8802;
cc.DISABLE_TAG = 8803;

// Global state variables
cc.stencilBits = -1;
cc.g_NumberOfDraws = 0;
cc.s_globalOrderOfArrival = 1;

// Event constants
cc.Event.TOUCH = 0;
cc.Event.KEYBOARD = 1;
cc.Event.ACCELERATION = 2;
cc.Event.MOUSE = 3;
cc.Event.FOCUS = 4;
cc.Event.CUSTOM = 6;

// EventMouse constants
cc.EventMouse.NONE = 0;
cc.EventMouse.DOWN = 1;
cc.EventMouse.UP = 2;
cc.EventMouse.MOVE = 3;
cc.EventMouse.SCROLL = 4;
cc.EventMouse.BUTTON_LEFT = 0;
cc.EventMouse.BUTTON_RIGHT = 1;
cc.EventMouse.BUTTON_MIDDLE = 2;
cc.EventMouse.BUTTON_4 = 3;
cc.EventMouse.BUTTON_5 = 4;
cc.EventMouse.BUTTON_6 = 5;
cc.EventMouse.BUTTON_7 = 6;
cc.EventMouse.BUTTON_8 = 7;

// EventTouch constants
cc.EventTouch.MAX_TOUCHES = 5;
cc.EventTouch.EventCode = { BEGAN: 0, MOVED: 1, ENDED: 2, CANCELLED: 3 };

// SpriteBatchNode constant
cc.SpriteBatchNode.DEFAULT_CAPACITY = 29;

// ParticleSystem constants
cc.ParticleSystem.SHAPE_MODE = 0;
cc.ParticleSystem.TEXTURE_MODE = 1;
cc.ParticleSystem.STAR_SHAPE = 0;
cc.ParticleSystem.BALL_SHAPE = 1;

// ProgressTimer constants
cc.ProgressTimer.TEXTURE_COORDS_COUNT = 4;
cc.ProgressTimer.TEXTURE_COORDS = 0x4b;

// RenderTexture
cc.IMAGE_FORMAT_RAWDATA = 2;

// TMXLayerInfo constants
cc.TMXLayerInfo.ATTRIB_NONE = 1 << 0;
cc.TMXLayerInfo.ATTRIB_BASE64 = 1 << 1;
cc.TMXLayerInfo.ATTRIB_GZIP = 1 << 2;
cc.TMXLayerInfo.ATTRIB_ZLIB = 1 << 3;

// TMX property constants
cc.TMX_PROPERTY_NONE = 0;
cc.TMX_PROPERTY_MAP = 1;
cc.TMX_PROPERTY_LAYER = 2;
cc.TMX_PROPERTY_OBJECTGROUP = 3;
cc.TMX_PROPERTY_OBJECT = 4;
cc.TMX_PROPERTY_TILE = 5;

// Transition constants
cc.SCENE_FADE = 4208917214;
cc.SCENE_RADIAL = 0xc001;

// CCMacro.js exports
cc.INVALID_INDEX = -1;
cc.PI = Math.PI;
cc.PI2 = Math.PI * 2;
cc.FLT_MAX = parseFloat('3.402823466e+38F');
cc.RAD = cc.PI / 180;
cc.DEG = 180 / cc.PI;
cc.UINT_MAX = 0xffffffff;
cc.FLT_EPSILON = 0.0000001192092896;
