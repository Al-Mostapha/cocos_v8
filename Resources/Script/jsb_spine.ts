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
// Spine Runtime Support
//

declare const sp: any;
declare const cc: any;

// // Spine animation support
// if (window.sp) {
//     // Spine skeleton animations
// }

if (typeof sp !== 'undefined' && sp) {
    /**
     * Initialize Spine module if available
     */
    const initSpine = (): void => {
        try {
            if (sp.SkeletonAnimation) {
                // Register custom event listeners for spine animations
                Object.defineProperty(sp.SkeletonAnimation.prototype, 'animationName', {
                    get(this: any): string {
                        return this._animationName || '';
                    },
                    set(this: any, value: string): void {
                        if (this.setAnimation) {
                            this.setAnimation(0, value, false);
                            this._animationName = value;
                        }
                    }
                });
            }
        } catch (error) {
            console.warn('Spine initialization failed:', error);
        }
    };

    // Initialize when ready
    if (cc && cc.director) {
        initSpine();
    }
}

export {};
