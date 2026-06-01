/*
 * Copyright (c) 2014-2016 Chukong Technologies Inc.
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

/************************************************************
 *
 * Constructors with built in init function
 *
 ************************************************************/

declare const cc: any;

// var _p;
// _p = cc.Layer.prototype;
// _p._ctor = function() {
//     cc.Layer.prototype.init.call(this);
// };

let _p: any;

// Layer constructors
_p = cc.Layer.prototype;
_p._ctor = function(): void {
    cc.Layer.prototype.init.call(this);
};

// LayerColor
_p = cc.LayerColor.prototype;
_p._ctor = function(color?: any, w?: number, h?: number): void {
    color = color || cc.color(0, 0, 0, 255);
    w = w === undefined ? cc.winSize.width : w;
    h = h === undefined ? cc.winSize.height : h;

    cc.LayerColor.prototype.init.call(this, color, w, h);
};

// LayerGradient
_p = cc.LayerGradient.prototype;
_p._ctor = function(start?: any, end?: any, v?: any, colorStops?: any): void {
    start = start || cc.color(0, 0, 0, 255);
    end = end || cc.color(0, 0, 0, 255);
    v = v || cc.p(0, -1);

    this.initWithColor(start, end, v);

    if (colorStops instanceof Array) {
        cc.log('Warning: Color stops parameter is not supported in JSB.');
    }
};

// LayerMultiplex
_p = cc.LayerMultiplex.prototype;
_p._ctor = function(layers?: any): void {
    if (layers !== undefined) {
        if (layers instanceof Array) {
            cc.LayerMultiplex.prototype.initWithArray.call(this, layers);
        } else {
            cc.LayerMultiplex.prototype.initWithArray.call(this, Array.prototype.slice.call(arguments));
        }
    } else {
        cc.LayerMultiplex.prototype.init.call(this);
    }
};

// Sprite
_p = cc.Sprite.prototype;
_p._ctor = function(fileName?: any, rect?: any): void {
    if (fileName === undefined) {
        cc.Sprite.prototype.init.call(this);
    } else if (typeof fileName === 'string') {
        if (fileName[0] === '#') {
            // init with a sprite frame name
            const frameName: string = fileName.substr(1, fileName.length - 1);
            this.initWithSpriteFrameName(frameName);
        } else {
            // Create with filename and rect
            rect ? this.initWithFile(fileName, rect) : this.initWithFile(fileName);
        }
    } else if (typeof fileName === 'object') {
        if (fileName instanceof cc.Texture2D) {
            // init with texture and rect
            rect ? this.initWithTexture(fileName, rect) : this.initWithTexture(fileName);
        } else {
            // init with spriteFrame
            this.initWithSpriteFrame(fileName);
        }
    }
};

export {};
