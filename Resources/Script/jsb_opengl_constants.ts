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
// OpenGL Constants
//

declare const cc: any;

// // Extended OpenGL constants
// cc.GL_VERTEX_ARRAY = 0x8074;
// cc.GL_NORMAL_ARRAY = 0x8075;
// ... (more OpenGL constants)

// Array enable constants
cc.GL_VERTEX_ARRAY = 0x8074;
cc.GL_NORMAL_ARRAY = 0x8075;
cc.GL_COLOR_ARRAY = 0x8076;
cc.GL_TEXTURE_COORD_ARRAY = 0x8078;

// Data types
cc.GL_BYTE = 0x1400;
cc.GL_UNSIGNED_BYTE = 0x1401;
cc.GL_SHORT = 0x1402;
cc.GL_UNSIGNED_SHORT = 0x1403;
cc.GL_INT = 0x1404;
cc.GL_UNSIGNED_INT = 0x1405;
cc.GL_FLOAT = 0x1406;
cc.GL_DOUBLE = 0x140A;

// Polygon mode
cc.GL_FRONT = 0x0404;
cc.GL_BACK = 0x0405;
cc.GL_FRONT_AND_BACK = 0x0408;

// Texture types
cc.GL_TEXTURE_2D = 0x0DE1;
cc.GL_TEXTURE_CUBE_MAP = 0x8513;

// Comparison functions
cc.GL_NEVER = 0x0200;
cc.GL_LESS = 0x0201;
cc.GL_EQUAL = 0x0202;
cc.GL_LEQUAL = 0x0203;
cc.GL_GREATER = 0x0204;
cc.GL_NOTEQUAL = 0x0205;
cc.GL_GEQUAL = 0x0206;
cc.GL_ALWAYS = 0x0207;

// Stencil operations
cc.GL_KEEP = 0x1E00;
cc.GL_ZERO_STENCIL = 0x0;
cc.GL_REPLACE = 0x1E01;
cc.GL_INCR = 0x1E02;
cc.GL_DECR = 0x1E03;
cc.GL_INVERT = 0x150A;
cc.GL_INCR_WRAP = 0x8507;
cc.GL_DECR_WRAP = 0x8508;

export {};
