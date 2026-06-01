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
// JSB Property Implementations
//

declare const cc: any;

// // Property implementations for cocos2d nodes
// if (cc.Sprite) {
//     cc.Sprite.prototype._setAnchorPoint = function(point) {
//         // implementation
//     };
// }

/**
 * Sprite property implementations
 */
if (cc.Sprite) {
    // Anchor point implementation
    cc.Sprite.prototype._setAnchorPoint = function(point: any): void {
        const ap = cc.p(0.5, 0.5);
        if (point.x !== ap.x || point.y !== ap.y) {
            const size = this.getContentSize();
            const locOffsetX = size.width * (point.x - ap.x);
            const locOffsetY = size.height * (point.y - ap.y);
            this._positionX += locOffsetX;
            this._positionY += locOffsetY;
        }
    };
}

/**
 * Label property implementations
 */
if (cc.LabelTTF) {
    // Font size property
    Object.defineProperty(cc.LabelTTF.prototype, 'fontSize', {
        get(this: any): number {
            return this._fontSize || 0;
        },
        set(this: any, value: number): void {
            if (this.setFontSize) {
                this.setFontSize(value);
                this._fontSize = value;
            }
        }
    });
}

export {};
