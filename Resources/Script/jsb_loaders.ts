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

//
// cocos2d loader plugins.
//
// This helper file should be required after jsb_cocos2d.js
//

declare const cc: any;
declare const jsb: any;

// cc._emptyLoader = {
//     load : function(realUrl, url, res, cb){
//         cb && cb(null, null);
//         return null;
//     }
// };

interface Loader {
    load(realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): any;
}

const emptyLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): null => {
        cb && cb(null, null);
        return null;
    }
};

cc.loader.register(
    ["mp3", "ogg", "wav", "mp4", "m4a", "font", "eot", "ttf", "woff", "svg", "gaf"],
    emptyLoader
);

// cc._txtLoader = {
//     load : function(realUrl, url, res, cb){
//         var result = jsb.fileUtils.getStringFromFile(realUrl);
//         cb && cb(null, result);
//         return result;
//     }
// };

const txtLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): string => {
        const result = jsb.fileUtils.getStringFromFile(realUrl);
        cb && cb(null, result);
        return result;
    }
};

cc.loader.register(["txt", "xml", "vsh", "fsh", "tmx", "tsx"], txtLoader);

// cc._jsonLoader = {
//     load : function(realUrl, url, res, cb){
//         var data = jsb.fileUtils.getStringFromFile(realUrl), result;
//         try{
//             result = JSON.parse(data);
//         }catch(e){
//             cc.error(e);
//             result = null;
//         }
//         cb && cb(null, result);
//         return result;
//     }
// };

const jsonLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): any => {
        const data = jsb.fileUtils.getStringFromFile(realUrl);
        let result: any;
        try {
            result = JSON.parse(data);
        } catch (e) {
            cc.error(e);
            result = null;
        }
        cb && cb(null, result);
        return result;
    }
};

cc.loader.register(["json", "ExportJson"], jsonLoader);

// cc._imgLoader = {
//     load : function(realUrl, url, res, cb){
//         cc.loader.loadImg(realUrl, function(err, tex){
//             if(err) {
//                 cb && cb(err);
//                 return;
//             }
//             cc.loader.cache[url] = tex;
//             cb && cb(null, tex);
//         });
//     }
// };

const imgLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): void => {
        cc.loader.loadImg(realUrl, (err: any, tex: any): void => {
            if (err) {
                cb && cb(err);
                return;
            }
            cc.loader.cache[url] = tex;
            cb && cb(null, tex);
        });
    }
};

cc.loader.register(["png", "jpg", "bmp", "jpeg", "gif", "webp"], imgLoader);

// cc._plistLoader = {
//     load : function(realUrl, url, res, cb){
//         var content = jsb.fileUtils.getStringFromFile(realUrl);
//         var result = cc.plistParser.parse(content);
//         cb && cb(null, result);
//         return result;
//     }
// };

const plistLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): any => {
        const content = jsb.fileUtils.getStringFromFile(realUrl);
        const result = cc.plistParser.parse(content);
        cb && cb(null, result);
        return result;
    }
};

cc.loader.register(["plist"], plistLoader);

// cc._binaryLoader = {
//     load : function(realUrl, url, res, cb){
//         var result = cc.loader.loadBinarySync(realUrl);
//         cb && cb(null, result);
//         return result;
//     }
// };

const binaryLoader: Loader = {
    load: (realUrl: string, url: string, res: any, cb?: (err: any, data: any) => void): any => {
        const result = cc.loader.loadBinarySync(realUrl);
        cb && cb(null, result);
        return result;
    }
};

cc.loader.register(["ccbi"], binaryLoader);
