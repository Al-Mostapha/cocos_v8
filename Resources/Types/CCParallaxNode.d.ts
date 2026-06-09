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
 * Parallax Object. <br />
 * Parallax required attributes are stored.
 * @class
 * @extends cc.Class
 */
declare module cc {
  // cc.PointObject = cc.Class.extend(/** @lends cc.PointObject# */{
  //     _ratio:null,
  //     _offset:null,
  //     _child:null,

  //     ctor: function(ratio, offset){
  //         this.initWithCCPoint(ratio, offset);
  //     },

  //     /**
  //      * Gets the ratio.
  //      * @return  {cc.Point} Not point, this is ratio.
  //      */
  //     getRatio:function () {
  //         return this._ratio;
  //     },

  //     /**
  //      * Set the ratio.
  //      * @param  {cc.Point} value
  //      */
  //     setRatio:function (value) {
  //         this._ratio = value;
  //     },

  //     /**
  //      * Gets the offset.
  //      * @return  {cc.Point}
  //      */
  //     getOffset:function () {
  //         return this._offset;
  //     },

  //     /**
  //      * Set the offset.
  //      * @param {cc.Point} value
  //      */
  //     setOffset:function (value) {
  //         this._offset = value;
  //     },

  //     /**
  //      * Gets the child.
  //      * @return {cc.Node}
  //      */
  //     getChild:function () {
  //         return this._child;
  //     },

  //     /**
  //      * Set the child.
  //      * @param  {cc.Node} value
  //      */
  //     setChild:function (value) {
  //         this._child = value;
  //     },

  //     /**
  //      * initializes cc.PointObject
  //      * @param  {cc.Point} ratio Not point, this is a ratio.
  //      * @param  {cc.Point} offset
  //      * @return {Boolean}
  //      */
  //     initWithCCPoint:function (ratio, offset) {
  //         this._ratio = ratio;
  //         this._offset = offset;
  //         this._child = null;
  //         return true;
  //     }
  // });

  // /**
  //  * Create a object to stored parallax data.
  //  * @param {cc.Point} ratio
  //  * @param {cc.Point} offset
  //  * @return {cc.PointObject}
  //  * @deprecated since v3.0 please use new cc.PointObject() instead.
  //  */
  // cc.PointObject.create = function (ratio, offset) {
  //     return new cc.PointObject(ratio, offset);
  // };

  // /**
  //  * <p>cc.ParallaxNode: A node that simulates a parallax scroller<br />
  //  * The children will be moved faster / slower than the parent according the the parallax ratio. </p>
  //  * @class
  //  * @extends cc.Node
  //  *
  //  * @property {Array}    parallaxArray   - Parallax nodes array
  //  */
  // cc.ParallaxNode = cc.Node.extend(/** @lends cc.ParallaxNode# */{
  class ParallaxNode extends Node {
    // 	parallaxArray:null,
    //     _lastPosition:null,
    //     _className:"ParallaxNode",
    //     /**
    //      * Gets the parallax array.
    //      * @return {Array}
    //      */
    //     getParallaxArray:function () {
    //         return this.parallaxArray;
    //     },
    //     /**
    //      * Set parallax array.
    //      * @param {Array} value
    //      */
    //     setParallaxArray:function (value) {
    //         this.parallaxArray = value;
    //     },
    /**
     * Constructor function, override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     */

    constructor();
    /**
     * Adds a child to the container with a z-order, a parallax ratio and a position offset
     * It returns self, so you can chain several addChilds.
     * @param {cc.Node} child
     * @param {Number} z
     * @param {cc.Point} ratio
     * @param {cc.Point} offset
     * @example
     * //example
     * voidNode.addChild(background, -1, cc.p(0.4, 0.5), cc.p(0,0));
     */
    addChild(child: cc.Node, localZOrder?: number, tag?: string | number): void;
    
    addChild(child: cc.Node, z: number, ratio: cc.Point, offset: cc.Point): void;
  }

  // /**
  //  * Create new parallax node.
  //  * @deprecated since v3.0 please use new cc.ParallaxNode() instead.
  //  * @return {cc.ParallaxNode}
  //  * @example
  //  * //exampleWA
  //  * var voidNode = new cc.ParallaxNode();
  //  */
  // cc.ParallaxNode.create = function () {
  //     return new cc.ParallaxNode();
  // };
}
