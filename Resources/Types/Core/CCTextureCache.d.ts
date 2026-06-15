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

declare namespace cc {
  let textureCache: TextureCache;
  /**
   * cc.textureCache is a singleton object, it's the global cache for cc.Texture2D
   * @class
   * @name cc.textureCache
   */
  class TextureCache {
    _textures: {};
    _textureColorsCache: {};
    _textureKeySeq: number;

    _loadedTexturesBefore: {};

    //handleLoadedTexture move to Canvas/WebGL

    /**
     * <p>
     *     Returns a Texture2D object given an PVR filename                                                              <br/>
     *     If the file image was not previously loaded, it will create a new CCTexture2D                                 <br/>
     *     object and it will return it. Otherwise it will return a reference of a previously loaded image              <br/>
     *     note: AddPVRTCImage does not support on HTML5
     * </p>
     * @param {String} filename
     * @return {cc.Texture2D}
     */
    addPVRTCImage(filename: string): Texture2D;

    /**
     * <p>
     *     Returns a Texture2D object given an ETC filename                                                               <br/>
     *     If the file image was not previously loaded, it will create a new CCTexture2D                                  <br/>
     *     object and it will return it. Otherwise it will return a reference of a previously loaded image                <br/>
     *    note:addETCImage does not support on HTML5
     * </p>
     * @param {String} filename
     * @return {cc.Texture2D}
     */
    addETCImage(filename: string): Texture2D;

    /**
     * Description
     * @return {String}
     */
    description(): string;

    /**
     * Returns an already created texture. Returns null if the texture doesn't exist.
     * @param {String} textureKeyName
     * @return {cc.Texture2D|Null}
     * @deprecated
     * @example
     * //example
     * var key = cc.textureCache.textureForKey("hello.png");
     */
    textureForKey(textureKeyName: string): Texture2D | null;

    /**
     * Returns an already created texture. Returns null if the texture doesn't exist.
     * @param {String} textureKeyName
     * @return {cc.Texture2D|Null}
     * @example
     * //example
     * var key = cc.textureCache.getTextureForKey("hello.png");
     */
    getTextureForKey(textureKeyName: string): Texture2D | null;

    /**
     * @param {Image} texture
     * @return {String|Null}
     * @example
     * //example
     * var key = cc.textureCache.getKeyByTexture(texture);
     */
    getKeyByTexture(texture: any): string | null;

    _generalTextureKey(id: number): string;

    /**
     * @param {Image} texture
     * @return {Array}
     * @example
     * //example
     * var cacheTextureForColor = cc.textureCache.getTextureColors(texture);
     */
    getTextureColors(texture: any): number[];

    /**
     * <p>Returns a Texture2D object given an PVR filename<br />
     * If the file image was not previously loaded, it will create a new Texture2D<br />
     *  object and it will return it. Otherwise it will return a reference of a previously loaded image </p>
     * @param {String} path
     * @return {cc.Texture2D}
     */
    addPVRImage(path: string): Texture2D;

    /**
     * <p>Purges the dictionary of loaded textures. <br />
     * Call this method if you receive the "Memory Warning"  <br />
     * In the short term: it will free some resources preventing your app from being killed  <br />
     * In the medium term: it will allocate more resources <br />
     * In the long term: it will be the same</p>
     * @example
     * //example
     * cc.textureCache.removeAllTextures();
     */
    removeAllTextures(): void;

    /**
     * Deletes a texture from the cache given a texture
     * @param {Image} texture
     * @example
     * //example
     * cc.textureCache.removeTexture(texture);
     */
    removeTexture(texture: any): void;

    /**
     * Deletes a texture from the cache given a its key name
     * @param {String} textureKeyName
     * @example
     * //example
     * cc.textureCache.removeTexture("hello.png");
     */
    removeTextureForKey(textureKeyName: string): void;

    //addImage move to Canvas/WebGL

    /**
     *  Cache the image data
     * @param {String} path
     * @param {Image|HTMLImageElement|HTMLCanvasElement} texture
     */
    cacheImage(path: string, texture: any): void;

    /**
     * <p>Returns a Texture2D object given an UIImage image<br />
     * If the image was not previously loaded, it will create a new Texture2D object and it will return it.<br />
     * Otherwise it will return a reference of a previously loaded image<br />
     * The "key" parameter will be used as the "key" for the cache.<br />
     * If "key" is null, then a new texture will be created each time.</p>
     * @param {HTMLImageElement|HTMLCanvasElement} image
     * @param {String} key
     * @return {cc.Texture2D}
     */
    // addUIImage: function (image, key)

    _addImageAsync: (url: string, cb: Function, target?: any) => any;
    addImageAsync(url: string, cb: Function, target?: any): any;
    _addImage: (url: string, cb?: Function) => any;
    addImage(url: string, cb?: Function, target?: any): any;

    /**
     * <p>Output to cc.log the current contents of this TextureCache <br />
     * This will attempt to calculate the size of each texture, and the total texture memory in use. </p>
     */
    // dumpCachedTextureInfo: function () {
    //   var count = 0;
    //   var totalBytes = 0,
    //     locTextures = this._textures;

    //   for (var key in locTextures) {
    //     var selTexture = locTextures[key];
    //     count++;
    //     if (selTexture.getHtmlElementObj() instanceof HTMLImageElement)
    //       cc.log(
    //         cc._LogInfos.textureCache_dumpCachedTextureInfo,
    //         key,
    //         selTexture.getHtmlElementObj().src,
    //         selTexture.getPixelsWide(),
    //         selTexture.getPixelsHigh(),
    //       );
    //     else {
    //       cc.log(
    //         cc._LogInfos.textureCache_dumpCachedTextureInfo_2,
    //         key,
    //         selTexture.getPixelsWide(),
    //         selTexture.getPixelsHigh(),
    //       );
    //     }
    //     totalBytes +=
    //       selTexture.getPixelsWide() * selTexture.getPixelsHigh() * 4;
    //   }

    //   var locTextureColorsCache = this._textureColorsCache;
    //   for (key in locTextureColorsCache) {
    //     var selCanvasColorsArr = locTextureColorsCache[key];
    //     for (var selCanvasKey in selCanvasColorsArr) {
    //       var selCanvas = selCanvasColorsArr[selCanvasKey];
    //       count++;
    //       cc.log(
    //         cc._LogInfos.textureCache_dumpCachedTextureInfo_2,
    //         key,
    //         selCanvas.width,
    //         selCanvas.height,
    //       );
    //       totalBytes += selCanvas.width * selCanvas.height * 4;
    //     }
    //   }
    //   cc.log(
    //     cc._LogInfos.textureCache_dumpCachedTextureInfo_3,
    //     count,
    //     totalBytes / 1024,
    //     (totalBytes / (1024.0 * 1024.0)).toFixed(2),
    //   );
    // },
  }
}
