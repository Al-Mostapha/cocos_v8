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

var _initSys = function () {
  /**
   * System variables
   * @namespace
   * @name cc.sys
   */
  cc.sys = window.sys || {};
  var sys = cc.sys;

  /**
   * English language code
   * @memberof cc.sys
   * @name LANGUAGE_ENGLISH
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_ENGLISH = "en";

  /**
   * Chinese language code
   * @memberof cc.sys
   * @name LANGUAGE_CHINESE
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_CHINESE = "zh";

  /**
   * French language code
   * @memberof cc.sys
   * @name LANGUAGE_FRENCH
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_FRENCH = "fr";

  /**
   * Italian language code
   * @memberof cc.sys
   * @name LANGUAGE_ITALIAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_ITALIAN = "it";

  /**
   * German language code
   * @memberof cc.sys
   * @name LANGUAGE_GERMAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_GERMAN = "de";

  /**
   * Spanish language code
   * @memberof cc.sys
   * @name LANGUAGE_SPANISH
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_SPANISH = "es";

  /**
   * Spanish language code
   * @memberof cc.sys
   * @name LANGUAGE_DUTCH
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_DUTCH = "du";

  /**
   * Russian language code
   * @memberof cc.sys
   * @name LANGUAGE_RUSSIAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_RUSSIAN = "ru";

  /**
   * Korean language code
   * @memberof cc.sys
   * @name LANGUAGE_KOREAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_KOREAN = "ko";

  /**
   * Japanese language code
   * @memberof cc.sys
   * @name LANGUAGE_JAPANESE
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_JAPANESE = "ja";

  /**
   * Hungarian language code
   * @memberof cc.sys
   * @name LANGUAGE_HUNGARIAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_HUNGARIAN = "hu";

  /**
   * Portuguese language code
   * @memberof cc.sys
   * @name LANGUAGE_PORTUGUESE
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_PORTUGUESE = "pt";

  /**
   * Arabic language code
   * @memberof cc.sys
   * @name LANGUAGE_ARABIC
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_ARABIC = "ar";

  /**
   * Norwegian language code
   * @memberof cc.sys
   * @name LANGUAGE_NORWEGIAN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_NORWEGIAN = "no";

  /**
   * Polish language code
   * @memberof cc.sys
   * @name LANGUAGE_POLISH
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_POLISH = "pl";

  /**
   * Turkish language code
   * @constant
   * @default
   * @type {Number}
   */
  sys.LANGUAGE_TURKISH = "tr";

  /**
   * Ukrainian language code
   * @constant
   * @default
   * @type {Number}
   */
  sys.LANGUAGE_UKRAINIAN = "uk";

  /**
   * Romanian language code
   * @constant
   * @default
   * @type {Number}
   */
  sys.LANGUAGE_ROMANIAN = "ro";

  /**
   * Bulgarian language code
   * @constant
   * @default
   * @type {Number}
   */
  sys.LANGUAGE_BULGARIAN = "bg";

  /**
   * Belarusian language code
   * @constant
   * @default
   * @type {Number}
   */
  sys.LANGUAGE_BELARUSIAN = "be";

  /**
   * Unknown language code
   * @memberof cc.sys
   * @name LANGUAGE_UNKNOWN
   * @constant
   * @type {Number}
   */
  sys.LANGUAGE_UNKNOWN = "unknown";

  /**
   * @memberof cc.sys
   * @name OS_IOS
   * @constant
   * @type {string}
   */
  sys.OS_IOS = "iOS";
  /**
   * @memberof cc.sys
   * @name OS_ANDROID
   * @constant
   * @type {string}
   */
  sys.OS_ANDROID = "Android";
  /**
   * @memberof cc.sys
   * @name OS_WINDOWS
   * @constant
   * @type {string}
   */
  sys.OS_WINDOWS = "Windows";
  /**
   * @memberof cc.sys
   * @name OS_MARMALADE
   * @constant
   * @type {string}
   */
  sys.OS_MARMALADE = "Marmalade";
  /**
   * @memberof cc.sys
   * @name OS_LINUX
   * @constant
   * @type {string}
   */
  sys.OS_LINUX = "Linux";
  /**
   * @memberof cc.sys
   * @name OS_BADA
   * @constant
   * @type {string}
   */
  sys.OS_BADA = "Bada";
  /**
   * @memberof cc.sys
   * @name OS_BLACKBERRY
   * @constant
   * @type {string}
   */
  sys.OS_BLACKBERRY = "Blackberry";
  /**
   * @memberof cc.sys
   * @name OS_OSX
   * @constant
   * @type {string}
   */
  sys.OS_OSX = "OS X";
  /**
   * @memberof cc.sys
   * @name OS_WP8
   * @constant
   * @type {string}
   */
  sys.OS_WP8 = "WP8";
  /**
   * @memberof cc.sys
   * @name OS_WINRT
   * @constant
   * @type {string}
   */
  sys.OS_WINRT = "WINRT";
  /**
   * @memberof cc.sys
   * @name OS_UNKNOWN
   * @constant
   * @type {string}
   */
  sys.OS_UNKNOWN = "Unknown";

  /**
   * @memberof cc.sys
   * @name UNKNOWN
   * @constant
   * @default
   * @type {Number}
   */
  sys.UNKNOWN = -1;
  /**
   * @memberof cc.sys
   * @name WIN32
   * @constant
   * @default
   * @type {Number}
   */
  sys.WIN32 = 0;
  /**
   * @memberof cc.sys
   * @name LINUX
   * @constant
   * @default
   * @type {Number}
   */
  sys.LINUX = 1;
  /**
   * @memberof cc.sys
   * @name MACOS
   * @constant
   * @default
   * @type {Number}
   */
  sys.MACOS = 2;
  /**
   * @memberof cc.sys
   * @name ANDROID
   * @constant
   * @default
   * @type {Number}
   */
  sys.ANDROID = 3;
  /**
   * @memberof cc.sys
   * @name IOS
   * @constant
   * @default
   * @type {Number}
   */
  sys.IPHONE = 4;
  /**
   * @memberof cc.sys
   * @name IOS
   * @constant
   * @default
   * @type {Number}
   */
  sys.IPAD = 5;
  /**
   * @memberof cc.sys
   * @name BLACKBERRY
   * @constant
   * @default
   * @type {Number}
   */
  sys.BLACKBERRY = 6;
  /**
   * @memberof cc.sys
   * @name NACL
   * @constant
   * @default
   * @type {Number}
   */
  sys.NACL = 7;
  /**
   * @memberof cc.sys
   * @name EMSCRIPTEN
   * @constant
   * @default
   * @type {Number}
   */
  sys.EMSCRIPTEN = 8;
  /**
   * @memberof cc.sys
   * @name TIZEN
   * @constant
   * @default
   * @type {Number}
   */
  sys.TIZEN = 9;
  /**
   * @memberof cc.sys
   * @name WINRT
   * @constant
   * @default
   * @type {Number}
   */
  sys.WINRT = 10;
  /**
   * @memberof cc.sys
   * @name WP8
   * @constant
   * @default
   * @type {Number}
   */
  sys.WP8 = 11;
  /**
   * @memberof cc.sys
   * @name MOBILE_BROWSER
   * @constant
   * @default
   * @type {Number}
   */
  sys.MOBILE_BROWSER = 100;
  /**
   * @memberof cc.sys
   * @name DESKTOP_BROWSER
   * @constant
   * @default
   * @type {Number}
   */
  sys.DESKTOP_BROWSER = 101;

  sys.BROWSER_TYPE_WECHAT = "wechat";
  sys.BROWSER_TYPE_ANDROID = "androidbrowser";
  sys.BROWSER_TYPE_IE = "ie";
  sys.BROWSER_TYPE_QQ = "qqbrowser";
  sys.BROWSER_TYPE_MOBILE_QQ = "mqqbrowser";
  sys.BROWSER_TYPE_UC = "ucbrowser";
  sys.BROWSER_TYPE_360 = "360browser";
  sys.BROWSER_TYPE_BAIDU_APP = "baiduboxapp";
  sys.BROWSER_TYPE_BAIDU = "baidubrowser";
  sys.BROWSER_TYPE_MAXTHON = "maxthon";
  sys.BROWSER_TYPE_OPERA = "opera";
  sys.BROWSER_TYPE_OUPENG = "oupeng";
  sys.BROWSER_TYPE_MIUI = "miuibrowser";
  sys.BROWSER_TYPE_FIREFOX = "firefox";
  sys.BROWSER_TYPE_SAFARI = "safari";
  sys.BROWSER_TYPE_CHROME = "chrome";
  sys.BROWSER_TYPE_LIEBAO = "liebao";
  sys.BROWSER_TYPE_QZONE = "qzone";
  sys.BROWSER_TYPE_SOUGOU = "sogou";
  sys.BROWSER_TYPE_UNKNOWN = "unknown";

  /**
   * Is native ? This is set to be true in jsb auto.
   * @memberof cc.sys
   * @name isNative
   * @type {Boolean}
   */
  sys.isNative = true;

  /**
   * Indicate the running platform
   * @memberof cc.sys
   * @name platform
   * @type {Number}
   */
  var platform = (sys.platform = __getPlatform());

  /**
   * Indicate whether system is mobile system
   * @memberof cc.sys
   * @name isMobile
   * @type {Boolean}
   */
  sys.isMobile =
    platform === sys.ANDROID ||
    platform === sys.IPAD ||
    platform === sys.IPHONE ||
    platform === sys.WP8 ||
    platform === sys.TIZEN ||
    platform === sys.BLACKBERRY
      ? true
      : false;

  sys._application = cc.Application.getInstance();

  /**
   * Indicate the current language of the running system
   * @memberof cc.sys
   * @name language
   * @type {String}
   */
  sys.language = (function () {
    var language = sys._application.getCurrentLanguage();
    switch (language) {
      case 0:
        return sys.LANGUAGE_ENGLISH;
      case 1:
        return sys.LANGUAGE_CHINESE;
      case 2:
        return sys.LANGUAGE_FRENCH;
      case 3:
        return sys.LANGUAGE_ITALIAN;
      case 4:
        return sys.LANGUAGE_GERMAN;
      case 5:
        return sys.LANGUAGE_SPANISH;
      case 6:
        return sys.LANGUAGE_DUTCH;
      case 7:
        return sys.LANGUAGE_RUSSIAN;
      case 8:
        return sys.LANGUAGE_KOREAN;
      case 9:
        return sys.LANGUAGE_JAPANESE;
      case 10:
        return sys.LANGUAGE_HUNGARIAN;
      case 11:
        return sys.LANGUAGE_PORTUGUESE;
      case 12:
        return sys.LANGUAGE_ARABIC;
      case 13:
        return sys.LANGUAGE_NORWEGIAN;
      case 14:
        return sys.LANGUAGE_POLISH;
      case 15:
        return sys.LANGUAGE_TURKISH;
      case 16:
        return sys.LANGUAGE_UKRAINIAN;
      case 17:
        return sys.LANGUAGE_ROMANIAN;
      case 18:
        return sys.LANGUAGE_BULGARIAN;
      case 19:
        return sys.LANGUAGE_BELARUSIAN;
      default:
        return sys.LANGUAGE_ENGLISH;
    }
  })();

  /**
   * Indicate the running os name
   * @memberof cc.sys
   * @name os
   * @type {String}
   */
  sys.os = __getOS();

  /**
   * Indicate the running browser type
   * @memberof cc.sys
   * @name browserType
   * @type {String}
   */
  sys.browserType = null; //null in jsb

  /**
   * Indicate the running browser version
   * @memberof cc.sys
   * @name browserVersion
   * @type {Number}
   */
  sys.browserVersion = null; //null in jsb

  /**
   * Indicate the real pixel resolution of the whole game window
   * @memberof cc.sys
   * @name windowPixelResolution
   * @type {Number}
   */
  sys.windowPixelResolution = cc.view.getFrameSize();

  /**
   * The capabilities of the current platform
   * @memberof cc.sys
   * @name capabilities
   * @type {Object}
   */
  var capabilities = (sys.capabilities = {
    canvas: false,
    opengl: true,
  });
  if (sys.isMobile) {
    capabilities["accelerometer"] = true;
    capabilities["touches"] = true;
    if (platform === sys.WINRT || platform === sys.WP8) {
      capabilities["keyboard"] = true;
    }
  } else {
    // desktop
    capabilities["keyboard"] = true;
    capabilities["mouse"] = true;
    // winrt can't suppot mouse in current version
    if (platform === sys.WINRT || platform === sys.WP8) {
      capabilities["touches"] = true;
      capabilities["mouse"] = false;
    }
  }

  /**
   * Forces the garbage collection, only available in JSB
   * @memberof cc.sys
   * @name garbageCollect
   * @function
   */
  sys.garbageCollect = function () {
    __jsc__.garbageCollect();
  };

  /**
   * Dumps rooted objects, only available in JSB
   * @memberof cc.sys
   * @name dumpRoot
   * @function
   */
  sys.dumpRoot = function () {
    __jsc__.dumpRoot();
  };

  /**
   * Restart the JS VM, only available in JSB
   * @memberof cc.sys
   * @name restartVM
   * @function
   */
  sys.restartVM = function () {
    __restartVM();
  };

  /**
   * Clean a script in the JS VM, only available in JSB
   * @memberof cc.sys
   * @name cleanScript
   * @param {String} jsfile
   * @function
   */
  sys.cleanScript = function (jsFile) {
    __cleanScript(jsFile);
  };

  /**
   * Check whether an object is valid,
   * In web engine, it will return true if the object exist
   * In native engine, it will return true if the JS object and the correspond native object are both valid
   * @memberof cc.sys
   * @name isObjectValid
   * @param {Object} obj
   * @return {boolean} Validity of the object
   * @function
   */
  sys.isObjectValid = function (obj) {
    return __isObjectValid(obj);
  };

  /**
   * Dump system informations
   * @memberof cc.sys
   * @name dump
   * @function
   */
  sys.dump = function () {
    var self = this;
    var str = "";
    str += "isMobile : " + self.isMobile + "\r\n";
    str += "language : " + self.language + "\r\n";
    str += "browserType : " + self.browserType + "\r\n";
    str += "capabilities : " + JSON.stringify(self.capabilities) + "\r\n";
    str += "os : " + self.os + "\r\n";
    str += "platform : " + self.platform + "\r\n";
    cc.log(str);
  };

  /**
   * Open a url in browser
   * @memberof cc.sys
   * @name openURL
   * @param {String} url
   */
  sys.openURL = function (url) {
    sys._application.openURL(url);
  };

  sys.now = function () {
    return Date.now();
  };

  // JS to Native bridges
  if (window.JavascriptJavaBridge && cc.sys.os == cc.sys.OS_ANDROID) {
    jsb.reflection = new JavascriptJavaBridge();
    cc.sys.capabilities["keyboard"] = true;
  } else if (
    window.JavaScriptObjCBridge &&
    (cc.sys.os == cc.sys.OS_IOS || cc.sys.os == cc.sys.OS_OSX)
  ) {
    jsb.reflection = new JavaScriptObjCBridge();
  }
};
_initSys();

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
