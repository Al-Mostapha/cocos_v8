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
// CocosBuilder definitions
//

declare const cc: any;

// cc.BuilderReader = cc.BuilderReader || {};
// cc.BuilderReader._resourcePath = "";
// cc.BuilderReader._controllerClassCache = {};

cc.BuilderReader = cc.BuilderReader || {};
cc.BuilderReader._resourcePath = "";
cc.BuilderReader._controllerClassCache = {};

/**
 * Register a controller class for CocosBuilder
 * @param controllerName
 * @param controller
 */
cc.BuilderReader.registerController = function(controllerName: string, controller: any): void {
    cc.BuilderReader._controllerClassCache[controllerName] = cc.Class.extend(controller);
};

/**
 * Set the resource path for CocosBuilder
 * @param rootPath
 */
cc.BuilderReader.setResourcePath = function(rootPath: string): void {
    cc.BuilderReader._resourcePath = rootPath;
};

/**
 * Load a CocosBuilder file
 * @param file
 * @param owner
 * @param parentSize
 */
cc.BuilderReader.load = function(file: string, owner?: any, parentSize?: any): any {
    // Load the node graph using the correct function
    const reader = cc._Reader.create();
    reader.setCCBRootPath(cc.BuilderReader._resourcePath);
    
    let node: any;

    if (parentSize) {
        node = reader.load(file, null, parentSize);
    } else {
        node = reader.load(file);
    }

    // Assign owner callbacks & member variables
    if (owner) {
        // Callbacks
        const ownerCallbackNames: string[] = reader.getOwnerCallbackNames();
        const ownerCallbackNodes: any[] = reader.getOwnerCallbackNodes();

        for (let i = 0; i < ownerCallbackNames.length; i++) {
            const callbackName: string = ownerCallbackNames[i];
            const callbackNode: any = ownerCallbackNodes[i];

            if (owner[callbackName] === undefined) {
                cc.log("Warning: " + "owner." + callbackName + " is undefined.");
            } else {
                if (callbackNode instanceof cc.ControlButton) {
                    const ownerCallbackControlEvents: any[] = reader.getOwnerCallbackControlEvents();
                    callbackNode.addTargetWithActionForControlEvents(owner, owner[callbackName], ownerCallbackControlEvents[i]);
                } else {
                    callbackNode.setCallback(owner[callbackName], owner);
                }
            }
        }

        // Variables
        const ownerOutletNames: string[] = reader.getOwnerOutletNames();
        const ownerOutletNodes: any[] = reader.getOwnerOutletNodes();

        for (let i = 0; i < ownerOutletNames.length; i++) {
            const outletName: string = ownerOutletNames[i];
            const outletNode: any = ownerOutletNodes[i];

            owner[outletName] = outletNode;
        }
    }

    const nodesWithAnimationManagers: any[] = reader.getNodesWithAnimationManagers();
    for (let i = 0; i < nodesWithAnimationManagers.length; i++) {
        const node: any = nodesWithAnimationManagers[i];
        const animationManager: any = reader.getAnimationManagerForNode(node);

        if (animationManager) {
            animationManager.runAnimationsForSequenceNamedTweenDuration(null, 0, 0);
        }
    }

    return node;
};
