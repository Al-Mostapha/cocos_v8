/*
 * Copyright (c) 2015-2016 Chukong Technologies Inc.
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
// cocos2d boot
//

namespace cc {
  // Define singleton objects
  export const director = cc.Director.getInstance();
  director._actionManager = cc.director.getActionManager();
  director._scheduler = cc.director.getScheduler();
  export const winSize = cc.director.getWinSize();
  //+++++++++++++++++++++++++Engine initialization function begin+++++++++++++++++++++++++++

  export const view = cc.director.getOpenGLView();
  cc.view.getDevicePixelRatio = cc.view.getRetinaFactor;
  cc.view.convertToLocationInView = function (
    tx: number,
    ty: number,
    relatedPos: {
      top: number;
      left: number;
      height: number;
    },
  ) {
    const _devicePixelRatio = cc.view.getDevicePixelRatio();
    return {
      x: _devicePixelRatio * (tx - relatedPos.left),
      y: _devicePixelRatio * (relatedPos.top + relatedPos.height - ty),
    };
  };

  cc.view.enableRetina = function (enabled: boolean) {};
  cc.view.isRetinaEnabled = function () {
    const sys = cc.sys;
    return sys.os == sys.OS_IOS || sys.os == sys.OS_OSX ? true : false;
  };
  cc.view.adjustViewPort = function () {};
  cc.view.resizeWithBrowserSize = function () {
    return;
  };
  cc.view.setResizeCallback = function () {
    return;
  };
  cc.view.enableAutoFullScreen = function () {
    return;
  };
  cc.view.isAutoFullScreenEnabled = function () {
    return true;
  };
  (<any>cc).view._setDesignResolutionSize = cc.view.setDesignResolutionSize;
  cc.view.setDesignResolutionSize = function (
    width: number,
    height: number,
    resolutionPolicy: cc.ResolutionPolicy,
  ) {
    (<any>cc).view._setDesignResolutionSize(width, height, resolutionPolicy);
    (<any>cc).winSize = cc.director.getWinSize();
    (<any>cc).visibleRect.init();
  };
  cc.view.setRealPixelResolution = cc.view.setDesignResolutionSize;
  cc.view.setResolutionPolicy = function (resolutionPolicy) {
    var size = cc.view.getDesignResolutionSize();
    cc.view.setDesignResolutionSize(size.width, size.height, resolutionPolicy);
  };
  cc.view.getCanvasSize = cc.view.getFrameSize;
  cc.view.getVisibleSizeInPixel = cc.view.getVisibleSize;
  cc.view.getVisibleOriginInPixel = cc.view.getVisibleOrigin;
  cc.view.setContentTranslateLeftTop = function () {
    return;
  };

  cc.view.getContentTranslateLeftTop = function () {
    return null as any;
  };

  cc.view.setFrameZoomFactor = function () {
    return;
  };

  cc.view.setOrientation = function () {};
}

cc.DENSITYDPI_DEVICE = "device-dpi";
cc.DENSITYDPI_HIGH = "high-dpi";
cc.DENSITYDPI_MEDIUM = "medium-dpi";
cc.DENSITYDPI_LOW = "low-dpi";
cc.view.setTargetDensityDPI = function () {};
cc.view.getTargetDensityDPI = function () {
  return cc.DENSITYDPI_DEVICE;
};

cc.eventManager = cc.director.getEventDispatcher();

cc.audioEngine = cc.AudioEngine.getInstance();
cc.audioEngine.end = function () {
  this.stopMusic();
  this.stopAllEffects();
};

cc.audioEngine.features = {
  MULTI_CHANNEL: true,
  AUTOPLAY: true,
};

cc.configuration = cc.Configuration.getInstance();

cc.textureCache = cc.director.getTextureCache();
cc.TextureCache.prototype._addImageAsync =
  cc.TextureCache.prototype.addImageAsync;
cc.TextureCache.prototype.addImageAsync = function (url, cb, target) {
  var localTex = null;
  cc.loader.loadImg(url, function (err, tex) {
    if (err) tex = null;
    if (cb) {
      cb.call(target, tex);
    }
    localTex = tex;
  });
  return localTex;
};
// Fix for compatibility with old APIs
cc.TextureCache.prototype._addImage = cc.TextureCache.prototype.addImage;
cc.TextureCache.prototype.addImage = function (url, cb, target) {
  if (typeof cb === "function") {
    return this.addImageAsync(url, cb, target);
  } else {
    if (cb) {
      return this._addImage(url, cb);
    } else {
      return this._addImage(url);
    }
  }
};

cc.shaderCache = cc.ShaderCache.getInstance();
cc.animationCache = cc.AnimationCache.getInstance();
cc.spriteFrameCache = cc.SpriteFrameCache.getInstance();

cc.plistParser = cc.PlistParser.getInstance();

// File utils (Temporary, won't be accessible)
cc.fileUtils = cc.FileUtils.getInstance();
cc.fileUtils.setPopupNotify(false);

cc.screen = {
  init: function () {},
  fullScreen: function () {
    return true;
  },
  requestFullScreen: function (element, onFullScreenChange) {
    onFullScreenChange.call();
  },
  exitFullScreen: function () {
    return false;
  },
  autoFullScreen: function (element, onFullScreenChange) {
    onFullScreenChange.call();
  },
};

/**
 * @type {Object}
 * @name jsb.fileUtils
 * jsb.fileUtils is the native file utils singleton object,
 * please refer to Cocos2d-x API to know how to use it.
 * Only available in JSB
 */
jsb.fileUtils = cc.fileUtils;
delete cc.FileUtils;
delete cc.fileUtils;

/**
 * @type {Object}
 * @name jsb.reflection
 * jsb.reflection is a bridge to let you invoke Java static functions.
 * please refer to this document to know how to use it: http://www.cocos2d-x.org/docs/manual/framework/html5/v3/reflection/en
 * Only available on Android platform
 */
jsb.reflection = {
  callStaticMethod: function () {
    cc.log("not supported on current platform");
  },
};



/**
 * Init Debug setting.
 * @function
 */
cc._initDebugSetting = function (mode) {
  var ccGame = cc.game;
  var bakLog = cc._cocosplayerLog || console.log || log;
  cc.log = cc.warn = cc.error = cc.assert = function () {};
  if (mode > ccGame.DEBUG_MODE_NONE) {
    console.log = function () {
      bakLog(cc.formatStr.apply(null, arguments));
    };
    console.error = function () {
      bakLog("ERROR :  " + cc.formatStr.apply(cc, arguments));
    };
    console.warn = function () {
      bakLog("WARN :  " + cc.formatStr.apply(cc, arguments));
    };

    cc.error = console.error;
    cc.assert = function (cond, msg) {
      if (!cond && msg) {
        var args = [];
        for (var i = 1; i < arguments.length; i++) args.push(arguments[i]);
        console.log("Assert: " + cc.formatStr.apply(cc, args));
      }
    };
    if (
      mode != ccGame.DEBUG_MODE_ERROR &&
      mode != ccGame.DEBUG_MODE_ERROR_FOR_WEB_PAGE
    ) {
      cc.warn = console.warn;
    }
    if (
      mode == ccGame.DEBUG_MODE_INFO ||
      mode == ccGame.DEBUG_MODE_INFO_FOR_WEB_PAGE
    ) {
      cc.log = console.log;
    }
  }
};

cc._engineLoaded = false;

cc.initEngine = function (config, cb) {
  require("script/jsb.js");
  cc._renderType = cc.game.RENDER_TYPE_OPENGL;
  cc._initDebugSetting(config[cc.game.CONFIG_KEY.debugMode]);
  cc._engineLoaded = true;
  cc.log(cc.ENGINE_VERSION);
  if (cb) cb();
};

//+++++++++++++++++++++++++something about CCGame end+++++++++++++++++++++++++++++

// Original bind in Spidermonkey v33 will trigger object life cycle track issue in our memory model and cause crash
Function.prototype.bind = function (oThis) {
  if (!cc.isFunction(this)) {
    // closest thing possible to the ECMAScript 5
    // internal IsCallable function
    throw new TypeError(
      "Function.prototype.bind - what is trying to be bound is not callable",
    );
  }

  var aArgs = Array.prototype.slice.call(arguments, 1),
    fToBind = this,
    fNOP = function () {},
    fBound = function () {
      return fToBind.apply(
        this instanceof fNOP && oThis ? this : oThis,
        aArgs.concat(Array.prototype.slice.call(arguments)),
      );
    };

  fNOP.prototype = this.prototype;
  fBound.prototype = new fNOP();

  return fBound;
};

jsb.urlRegExp = new RegExp(
  "^" +
    // protocol identifier
    "(?:(?:https?|ftp)://)" +
    // user:pass authentication
    "(?:\\S+(?::\\S*)?@)?" +
    "(?:" +
    // IP address dotted notation octets
    // excludes loopback network 0.0.0.0
    // excludes reserved space >= 224.0.0.0
    // excludes network & broacast addresses
    // (first & last IP address of each class)
    "(?:[1-9]\\d?|1\\d\\d|2[01]\\d|22[0-3])" +
    "(?:\\.(?:1?\\d{1,2}|2[0-4]\\d|25[0-5])){2}" +
    "(?:\\.(?:[1-9]\\d?|1\\d\\d|2[0-4]\\d|25[0-4]))" +
    "|" +
    // host name
    "(?:(?:[a-z\\u00a1-\\uffff0-9]-*)*[a-z\\u00a1-\\uffff0-9]+)" +
    // domain name
    "(?:\\.(?:[a-z\\u00a1-\\uffff0-9]-*)*[a-z\\u00a1-\\uffff0-9]+)*" +
    // TLD identifier
    "(?:\\.(?:[a-z\\u00a1-\\uffff]{2,}))" +
    "|" +
    "(?:localhost)" +
    ")" +
    // port number
    "(?::\\d{2,5})?" +
    // resource path
    "(?:/\\S*)?" +
    "$",
  "i",
);
