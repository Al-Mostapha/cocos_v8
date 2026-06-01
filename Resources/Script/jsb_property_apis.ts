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
// JSB Property APIs
//

declare const cc: any;

// // Property API implementations
// if (cc.Node) {
//     cc.Node.prototype.getContentSize = function() {
//         // implementation
//     };
//     cc.Node.prototype.setContentSize = function(size) {
//         // implementation
//     };
// }

/**
 * Node property APIs
 */
if (cc.Node) {
    // Content size property
    Object.defineProperty(cc.Node.prototype, 'width', {
        get(this: any): number {
            return this.getContentSize().width;
        },
        set(this: any, value: number): void {
            const size = this.getContentSize();
            this.setContentSize(cc.size(value, size.height));
        }
    });

    Object.defineProperty(cc.Node.prototype, 'height', {
        get(this: any): number {
            return this.getContentSize().height;
        },
        set(this: any, value: number): void {
            const size = this.getContentSize();
            this.setContentSize(cc.size(size.width, value));
        }
    });

    // Position property
    Object.defineProperty(cc.Node.prototype, 'x', {
        get(this: any): number {
            return this.getPosition().x;
        },
        set(this: any, value: number): void {
            const pos = this.getPosition();
            this.setPosition(cc.p(value, pos.y));
        }
    });

    Object.defineProperty(cc.Node.prototype, 'y', {
        get(this: any): number {
            return this.getPosition().y;
        },
        set(this: any, value: number): void {
            const pos = this.getPosition();
            this.setPosition(cc.p(pos.x, value));
        }
    });
}

export {};
