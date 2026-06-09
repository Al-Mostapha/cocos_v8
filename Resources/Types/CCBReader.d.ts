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



declare module cc {
  class NodeLoader extends Class{}
  class LayerLoader extends NodeLoader{}
  class LayerColorLoader extends NodeLoader{}
  class LayerGradientLoader extends NodeLoader{}
  class SpriteLoader extends NodeLoader{}
  class LabelBMFontLoader extends NodeLoader{}
  class LabelTTFLoader extends NodeLoader{}
  class Scale9SpriteLoader extends NodeLoader{}
  class ScrollViewLoader extends NodeLoader{}
  class BuilderFileLoader extends NodeLoader{}
  class MenuLoader extends NodeLoader{}
  class MenuItemImageLoader extends NodeLoader{}
  class ControlButtonLoader extends NodeLoader{}
  class ParticleSystemLoader extends NodeLoader{}

  class NodeLoaderLibrary extends Class{
    _ccNodeLoaders: any;

    constructor();

    registerDefaultCCNodeLoaders(): void;

    registerCCNodeLoader(className: string, ccNodeLoader: NodeLoader): void;

    unregisterCCNodeLoader(className: string): void;

    getCCNodeLoader(className: string): NodeLoader;

    purge(releaseCCNodeLoaders: boolean): void;
  }

  class BuilderReader extends Class{
    constructor(ccNodeLoaderLibrary: NodeLoaderLibrary, ccbMemberVariableAssigner: Node, ccbSelectorResolver: any, ccNodeLoaderListener: any);
    getCCBRootPath() : string;
    setCCBRootPath(rootPath: string) : void;
    initWithData(data: ArrayBuffer, owner: Node): boolean;
    readNodeGraphFromFile(ccbFileName: string, owner: Node, parentSize: Size, animationManager: any): Node;
    readNodeGraphFromData(data: ArrayBuffer, owner: Node, parentSize: Size): Node;
    createSceneWithNodeGraphFromFile(ccbFileName: string, owner: Node, parentSize: Size, animationManager: any): Scene;
    getCCBMemberVariableAssigner()  : Node;
    getCCBSelectorResolver() : any;
    getAnimationManager() : any;
    setAnimationManager(animationManager: any): void;
    getAnimatedProperties() : any;
    getLoadedSpriteSheet() : any;
    getOwner() : Node;
    isJSControlled() : boolean;
    getOwnerCallbackNames() : any;
    getOwnerCallbackNodes() : any;
    getOwnerCallbackControlEvents() : any;
    getOwnerOutletNames() : any;
    getOwnerOutletNodes() : any;
    getNodesWithAnimationManagers() : any;
    getAnimationManagersForNodes() : any;
    getAnimationManagers() : any;
    setAnimationManagers(animationManagers: any) : void;
    setResolutionScale(scale: number) : void;
    getResolutionScale() : number;
    static loadAsScene(ccbFilePath: string, owner?: Node, parentSize?: Size, ccbRootPath?: string) : Scene;
    static registerController(controllerName: string, controller: any) : void;
    static load(ccbFilePath: string, owner?: Node, parentSize?: Size, ccbRootPath?: string) : Node;
    static setResourcePath(rootPath: string) : void;
    static getResourcePath() : string;
    static lastPathComponent(pathStr: string) : string;
    static deletePathExtension(pathStr: string) : string;
    static toLowerCase(sourceStr: string) : string;
    static endsWith(sourceStr: string, ending: string) : boolean;
    static concat(stringA: string, stringB: string) : string;
  }
}