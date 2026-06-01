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

//
// OpenGL Constants and Support
//

declare const cc: any;

// // OpenGL context constants
// cc.GL_ZERO = 0;
// cc.GL_ONE = 1;
// ... (all OpenGL constants)

// Common OpenGL constants
cc.GL_ZERO = 0;
cc.GL_ONE = 1;
cc.GL_TRUE = 1;
cc.GL_FALSE = 0;

// Blending functions
cc.GL_SRC_ALPHA = 0x0302;
cc.GL_ONE_MINUS_SRC_ALPHA = 0x0303;
cc.GL_DST_ALPHA = 0x0304;
cc.GL_ONE_MINUS_DST_ALPHA = 0x0305;

// Texture parameters
cc.GL_LINEAR = 0x2601;
cc.GL_NEAREST = 0x2600;
cc.GL_REPEAT = 0x2901;
cc.GL_CLAMP_TO_EDGE = 0x812F;
cc.GL_TEXTURE_WRAP_S = 0x2802;
cc.GL_TEXTURE_WRAP_T = 0x2803;
cc.GL_TEXTURE_MIN_FILTER = 0x2801;
cc.GL_TEXTURE_MAG_FILTER = 0x2800;

// Matrix modes
cc.GL_PROJECTION = 0x1701;
cc.GL_MODELVIEW = 0x1700;

// Depth testing
cc.GL_DEPTH_TEST = 0x0B71;
cc.GL_DEPTH_BUFFER_BIT = 0x00000100;

// Color buffer
cc.GL_COLOR_BUFFER_BIT = 0x00004000;

// Primitives
cc.GL_TRIANGLES = 0x0004;
cc.GL_TRIANGLE_STRIP = 0x0005;
cc.GL_TRIANGLE_FAN = 0x0006;
cc.GL_QUADS = 0x0007;

export {};
