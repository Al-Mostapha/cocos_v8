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

// // Deprecated functions
// 
// var cc = cc || {};
// 
// (function() {
// 
//     var logW = function(old_name, new_name) {
//         cc.log("\n********** \n"+old_name +" was deprecated, please use "+ new_name +" instead.\n**********");
//     };

const logW = (oldName: string, newName: string): void => {
    cc.log(`\n********** \n${oldName} was deprecated, please use ${newName} instead.\n**********`);
};

// Deprecated static functions
cc.AnimationCache.purgeSharedAnimationCache = function(): void {
    logW("cc.AnimationCache.purgeSharedAnimationCache", "cc.AnimationCache.destroyInstance");
    cc.AnimationCache.destroyInstance();
};

cc.TextureCache.getInstance = function(): any {
    return cc.Director.getInstance().getTextureCache();
};

// Deprecated member functions
cc.Action.prototype.copy = function(): any {
    logW("cc.Action.copy", "cc.Action.clone");
    return cc.Action.prototype.clone.apply(this, arguments);
};

cc.Animation.prototype.copy = function(): any {
    logW("cc.Animation.copy", "cc.Animation.clone");
    return cc.Animation.prototype.clone.apply(this, arguments);
};

cc.Node.prototype.nodeToWorldTransform = function(): any {
    logW("cc.Node.nodeToWorldTransform", "cc.Node.getNodeToWorldTransform");
    return cc.Node.prototype.getNodeToWorldTransform.apply(this, arguments);
};

cc.Node.prototype.getZOrder = function(): any {
    logW("cc.Node.getZOrder", "cc.Node.getLocalZOrder");
    return cc.Node.prototype.getLocalZOrder.apply(this, arguments);
};

cc.Node.prototype.setZOrder = function(): void {
    logW("cc.Node.setZOrder", "cc.Node.setLocalZOrder");
    cc.Node.prototype.setLocalZOrder.apply(this, arguments);
};

// Not deprecated in the web engine yet, so no need to log
cc.Node.prototype.ignoreAnchorPointForPosition = cc.Node.prototype.setIgnoreAnchorPointForPosition;

cc.Node.prototype.nodeToParentTransform = function(): any {
    logW("cc.Node.nodeToParentTransform", "cc.Node.getNodeToParentTransform");
    return cc.Node.prototype.getNodeToParentTransform.apply(this, arguments);
};

cc.Node.prototype.worldToNodeTransform = function(): any {
    logW("cc.Node.worldToNodeTransform", "cc.Node.getWorldToNodeTransform");
    return cc.Node.prototype.getWorldToNodeTransform.apply(this, arguments);
};

cc.Node.prototype.parentToNodeTransform = function(): any {
    logW("cc.Node.parentToNodeTransform", "cc.Node.getParentToNodeTransform");
    return cc.Node.prototype.getParentToNodeTransform.apply(this, arguments);
};

cc.Node.prototype.numberOfRunningActions = function(): any {
    logW("cc.Node.numberOfRunningActions", "cc.Node.getNumberOfRunningActions");
    return cc.Node.prototype.getNumberOfRunningActions.apply(this, arguments);
};

cc.Node.prototype.numberOfRunningActionsInTarget = function(): any {
    logW("cc.Node.numberOfRunningActionsInTarget", "cc.Node.getNumberOfRunningActionsInTarget");
    return cc.Node.prototype.getNumberOfRunningActionsInTarget.apply(this, arguments);
};

cc.Menu.prototype.setHandlerPriority = function(): void {
    cc.log("cc.Menu.setHandlerPriority was deprecated, 3.0 uses new event dispatcher to dispatch touch event based on draw order, so setHandlerPriority is not needed now.");
};

// })();
