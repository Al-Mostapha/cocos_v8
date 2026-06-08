// //
// // Node API
// //

// cc.Node.prototype.setUserData = function (data) {
//   this.userData = data;
// };
// cc.Node.prototype.getUserData = function () {
//   return this.userData;
// };

// //for compatibility with html5
// cc.Node.prototype._setNormalizedPosition =
//   cc.Node.prototype.setNormalizedPosition;
// cc.Node.prototype.setNormalizedPosition = function (pos, y) {
//   if (y === undefined) cc.Node.prototype._setNormalizedPosition.call(this, pos);
//   else cc.Node.prototype._setNormalizedPosition.call(this, cc.p(pos, y));
// };

// /** returns a "world" axis aligned bounding box of the node. <br/>
//  * @return {cc.Rect}
//  */
// cc.Node.prototype.getBoundingBoxToWorld = function () {
//   var contentSize = this.getContentSize();
//   var rect = cc.rect(0, 0, contentSize.width, contentSize.height);
//   var trans = this.getNodeToWorldTransform();
//   rect = cc.rectApplyAffineTransform(rect, trans);

//   //query child's BoundingBox
//   if (!this.getChildren()) return rect;

//   var locChildren = this.getChildren();
//   for (var i = 0; i < locChildren.length; i++) {
//     var child = locChildren[i];
//     if (child && child.isVisible()) {
//       var childRect = child._getBoundingBoxToCurrentNode(trans);
//       if (childRect) rect = cc.rectUnion(rect, childRect);
//     }
//   }
//   return rect;
// };

// cc.Node.prototype._getBoundingBoxToCurrentNode = function (parentTransform) {
//   var contentSize = this.getContentSize();
//   var rect = cc.rect(0, 0, contentSize.width, contentSize.height);
//   var _trans = this.getNodeToParentTransform();
//   var trans =
//     parentTransform == null
//       ? _trans
//       : cc.affineTransformConcat(_trans, parentTransform);
//   rect = cc.rectApplyAffineTransform(rect, trans);

//   //query child's BoundingBox
//   if (!this.getChildren()) return rect;

//   var locChildren = this.getChildren();
//   for (var i = 0; i < locChildren.length; i++) {
//     var child = locChildren[i];
//     if (child && child.isVisible()) {
//       var childRect = child._getBoundingBoxToCurrentNode(trans);
//       if (childRect) rect = cc.rectUnion(rect, childRect);
//     }
//   }
//   return rect;
// };

// //
// // cc.Layer bake/unbake/isBaked
// //
// cc.Layer.prototype.bake = cc.Layer.prototype.unbake = function () {};
// cc.Layer.prototype.isBaked = function () {
//   return false;
// };

// //
// // RenderTexture beginWithClear
// //
// cc.RenderTexture.prototype._beginWithClear =
//   cc.RenderTexture.prototype.beginWithClear;
// cc.RenderTexture.prototype.beginWithClear = function (
//   r,
//   g,
//   b,
//   a,
//   depthValue,
//   stencilValue,
// ) {
//   r /= 255;
//   g /= 255;
//   b /= 255;
//   a /= 255;
//   this._beginWithClear(r, g, b, a, depthValue, stencilValue);
// };

// cc.RenderTexture.prototype._clear = cc.RenderTexture.prototype.clear;
// cc.RenderTexture.prototype.clear = function (r, g, b, a) {
//   r /= 255;
//   g /= 255;
//   b /= 255;
//   a /= 255;
//   this._clear(r, g, b, a);
// };

// //
// // Texture2D setTexParameters
// //
// cc.Texture2D.prototype._setTexParameters =
//   cc.Texture2D.prototype.setTexParameters;
// cc.Texture2D.prototype.setTexParameters = function (
//   texParams,
//   magFilter,
//   wrapS,
//   wrapT,
// ) {
//   var minFilter;
//   if (magFilter === undefined) {
//     minFilter = texParams.minFilter;
//     magFilter = texParams.magFilter;
//     wrapS = texParams.wrapS;
//     wrapT = texParams.wrapT;
//   } else minFilter = texParams;

//   this._setTexParameters(minFilter, magFilter, wrapS, wrapT);
// };

// cc.Texture2D.prototype.handleLoadedTexture = function (premultiplied) {};

// //
// // MenuItem setCallback support target
// //
// cc.MenuItem.prototype._setCallback = cc.MenuItem.prototype.setCallback;
// cc.MenuItem.prototype.setCallback = function (callback, target) {
//   this._setCallback(callback.bind(target));
// };

// //
// // MenuItemImage support sprite frame name as parameter
// //
// var _p = cc.MenuItemImage.prototype;
// _p._setNormalSpriteFrame = _p.setNormalSpriteFrame;
// _p._setSelectedSpriteFrame = _p.setSelectedSpriteFrame;
// _p._setDisabledSpriteFrame = _p.setDisabledSpriteFrame;
// _p.setNormalSpriteFrame = function (frame) {
//   if (frame[0] == "#")
//     frame = cc.spriteFrameCache.getSpriteFrame(frame.substr(1));
//   this._setNormalSpriteFrame(frame);
// };
// _p.setSelectedSpriteFrame = function (frame) {
//   if (frame[0] == "#")
//     frame = cc.spriteFrameCache.getSpriteFrame(frame.substr(1));
//   this._setSelectedSpriteFrame(frame);
// };
// _p.setDisabledSpriteFrame = function (frame) {
//   if (frame[0] == "#")
//     frame = cc.spriteFrameCache.getSpriteFrame(frame.substr(1));
//   this._setDisabledSpriteFrame(frame);
// };

// cc.MenuItemToggle.prototype.selectedItem =
//   cc.MenuItemToggle.prototype.getSelectedItem;

// // playMusic searchPaths
// if (cc.sys.os === cc.sys.OS_ANDROID && cc.audioEngine) {
//   cc.audioEngine._playMusic = cc.audioEngine.playMusic;
//   cc.audioEngine.playMusic = function () {
//     var args = arguments;
//     var searchPaths = jsb.fileUtils.getSearchPaths();
//     var path = args[0];
//     searchPaths.some(function (item) {
//       var temp = item + "/" + path;
//       var exists = jsb.fileUtils.isFileExist(temp);
//       if (exists) {
//         path = temp;
//         return true;
//       }
//     });
//     args[0] = path;
//     cc.audioEngine._playMusic.apply(cc.audioEngine, args);
//   };
// }

// //
// // LabelTTF API wrappers
// //
// cc.LabelTTF.prototype._setDimensions = cc.LabelTTF.prototype.setDimensions;
// cc.LabelTTF.prototype.setDimensions = function (dim, height) {
//   if (!isNaN(height)) {
//     dim = { width: dim, height: height };
//   }
//   this._setDimensions(dim);
// };

// cc.LabelTTF.prototype._enableShadow = cc.LabelTTF.prototype.enableShadow;
// cc.LabelTTF.prototype.enableShadow = function (
//   shadowColor,
//   offset,
//   blurRadius,
// ) {
//   var opacity = 1;
//   this._enableShadow(offset, opacity, blurRadius);
// };

// cc.LabelTTF.prototype.setDrawMode = function () {};

// //
// // Label overflow
// //
// cc.Label.Overflow = {
//   NONE: 0,
//   CLAMP: 1,
//   SHRINK: 2,
//   RESIZE_HEIGHT: 3,
// };

// //
// // Label adaptation to LabelTTF/LabelBMFont/LabelAtlas
// //
// _p = cc.Label.prototype;
// _p.enableStroke = _p.enableOutline;
// _p.setBoundingWidth = _p.setWidth;
// _p.setBoundingHeight = _p.setHeight;

// //
// // cc.Scheduler scheduleCallbackForTarget
// //
// _p = cc.Scheduler.prototype;
// _p.unscheduleUpdateForTarget = _p.unscheduleUpdate;
// _p.unscheduleAllCallbacksForTarget = function (target) {
//   this.unschedule(target.__instanceId + "", target);
// };
// _p._schedule = _p.schedule;
// _p.schedule = function (
//   callback,
//   target,
//   interval,
//   repeat,
//   delay,
//   paused,
//   key,
// ) {
//   var isSelector = false;
//   if (typeof callback !== "function") {
//     var selector = callback;
//     isSelector = true;
//   }
//   if (isSelector === false) {
//     //callback, target, interval, repeat, delay, paused, key
//     //callback, target, interval, paused, key
//     if (arguments.length === 4 || arguments.length === 5) {
//       key = delay;
//       paused = repeat;
//       delay = 0;
//       repeat = cc.REPEAT_FOREVER;
//     }
//   } else {
//     //selector, target, interval, repeat, delay, paused
//     //selector, target, interval, paused
//     if (arguments.length === 4) {
//       paused = repeat;
//       repeat = cc.REPEAT_FOREVER;
//       delay = 0;
//     }
//   }
//   if (key === undefined) {
//     key = target.__instanceId + "";
//   }
//   this._schedule(callback, target, interval, repeat, delay, paused, key);
// };

// cc._NodeGrid = cc.NodeGrid;
// cc.NodeGrid = function (rect) {
//   if (!(this instanceof cc.NodeGrid)) {
//     cc.error(
//       "NodeGrid's constructor can not be called as a function, please use 'new cc.NodeGrid()'",
//     );
//     return;
//   }

//   if (rect) {
//     return cc._NodeGrid.create(rect);
//   } else {
//     return cc._NodeGrid.create();
//   }
// };

// cc.NodeGrid.create = function (rect) {
//   if (rect) {
//     return cc._NodeGrid.create(rect);
//   } else {
//     return cc._NodeGrid.create();
//   }
// };
