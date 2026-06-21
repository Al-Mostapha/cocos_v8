//
// cocos2d boot
//

namespace cc {
  // Define singleton objects
  export const director = cc.Director.getInstance();
  // TODO
  // director._actionManager = cc.director.getActionManager();
  // director._scheduler = cc.director.getScheduler();
  export const winSize = director.getWinSize();
  //+++++++++++++++++++++++++Engine initialization function begin+++++++++++++++++++++++++++

  export const view = director.getOpenGLView();
  const lWindowSize = view.getFrameSize();

  cc.sys.windowPixelResolution.width = lWindowSize.width;
  cc.sys.windowPixelResolution.height = lWindowSize.height;

  view.getDevicePixelRatio = view.getRetinaFactor;
  view.convertToLocationInView = function (
    tx: number,
    ty: number,
    relatedPos: {
      top: number;
      left: number;
      height: number;
    },
  ) {
    const _devicePixelRatio = view.getDevicePixelRatio();
    return {
      x: _devicePixelRatio * (tx - relatedPos.left),
      y: _devicePixelRatio * (relatedPos.top + relatedPos.height - ty),
    };
  };

  view.enableRetina = function (enabled: boolean) {};
  view.isRetinaEnabled = function () {
    const sys = cc.sys;
    return sys.os == sys.OS_IOS || sys.os == sys.OS_OSX ? true : false;
  };
  view.adjustViewPort = function () {};
  view.resizeWithBrowserSize = function () {
    return;
  };
  view.setResizeCallback = function () {
    return;
  };
  view.enableAutoFullScreen = function () {
    return;
  };
  view.isAutoFullScreenEnabled = function () {
    return true;
  };
  // TODO
  (<any>view)._setDesignResolutionSize = view.setDesignResolutionSize;
  cc.view.setDesignResolutionSize = function (
    width: number,
    height: number,
    resolutionPolicy: cc.ResolutionPolicy,
  ) {
    (<any>view)._setDesignResolutionSize(width, height, resolutionPolicy);
    cc.winSize.width = cc.director.getWinSize().width;
    cc.winSize.height = cc.director.getWinSize().height;
    cc.visibleRect.init();
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

  export class screen {
    static init() {}
    static fullScreen() {
      return true;
    }
    static requestFullScreen(element: any, onFullScreenChange: Function) {
      onFullScreenChange?.();
    }
    static exitFullScreen() {
      return false;
    }
    static autoFullScreen(element: any, onFullScreenChange: Function) {
      onFullScreenChange?.();
    }
  }

  export const DENSITYDPI_DEVICE = "device-dpi";
  export const DENSITYDPI_HIGH = "high-dpi";
  export const DENSITYDPI_MEDIUM = "medium-dpi";
  export const DENSITYDPI_LOW = "low-dpi";

  /**
   * Init Debug setting.
   * @function
   */
  export const _initDebugSetting = (mode: number) => {
    // TODO
    const bakLog = /*cc._cocosplayerLog ||*/ console.log || log;
    cc.log = cc.warn = cc.error = cc.assert = (() => {}) as any;
    if (mode > cc.game.DEBUG_MODE_NONE) {
      console.log = (...args: any[]) => {
        bakLog(cc.formatStr.apply(null, args));
      };
      console.error = (...args: any[]) => {
        bakLog("ERROR :  " + cc.formatStr.apply(cc, args));
      };
      console.warn = (...args: any[]) => {
        bakLog("WARN :  " + cc.formatStr.apply(cc, args));
      };

      cc.error = console.error;
      cc.assert = (cond, msg, ...args) => {
        if (!cond && msg) {
          console.log("Assert: " + cc.formatStr.apply(cc, [msg, ...args]));
        }
      };
      if (
        mode != cc.game.DEBUG_MODE_ERROR &&
        mode != cc.game.DEBUG_MODE_ERROR_FOR_WEB_PAGE
      ) {
        cc.warn = console.warn;
      }
      if (
        mode == cc.game.DEBUG_MODE_INFO ||
        mode == cc.game.DEBUG_MODE_INFO_FOR_WEB_PAGE
      ) {
        cc.log = console.log;
      }
    }
  };

  cc._engineLoaded = false;

  export const initEngine = (config: GameConfig, cb: Function) => {
    // TODO
    // require("script/jsb.js");
    cc._renderType = cc.game.RENDER_TYPE_OPENGL;
    cc._initDebugSetting(config.debugMode ?? 0);
    cc._engineLoaded = true;
    cc.log(cc.ENGINE_VERSION);
    if (cb) cb();
  };
}

cc.view.setTargetDensityDPI = function () {};
cc.view.getTargetDensityDPI = function () {
  return cc.DENSITYDPI_DEVICE;
};

// TODO
cc.eventManager = cc.director.getEventDispatcher() as any;

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
  let localTex = null;
  // TODO
  cc.loader.loadImg(url, function (err: any, tex: any) {
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

namespace jsb {
  /**
   * @type {Object}
   * @name jsb.fileUtils
   * jsb.fileUtils is the native file utils singleton object,
   * please refer to Cocos2d-x API to know how to use it.
   * Only available in JSB
   */
  export const fileUtils = cc.fileUtils;
  // TODO
  // delete cc.FileUtils;
  // delete cc.fileUtils;

  /**
   * @type {Object}
   * @name jsb.reflection
   * jsb.reflection is a bridge to let you invoke Java static functions.
   * please refer to this document to know how to use it: http://www.cocos2d-x.org/docs/manual/framework/html5/v3/reflection/en
   * Only available on Android platform
   */
  export class reflection {
    static callStaticMethod() {
      cc.log("not supported on current platform");
    }
  }

  export const urlRegExp = new RegExp(
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
}

//+++++++++++++++++++++++++something about CCGame end+++++++++++++++++++++++++++++

// Original bind in Spidermonkey v33 will trigger object life cycle track issue in our memory model and cause crash
// Function.prototype.bind = function (oThis) {
//   if (!cc.isFunction(this)) {
//     // closest thing possible to the ECMAScript 5
//     // internal IsCallable function
//     throw new TypeError(
//       "Function.prototype.bind - what is trying to be bound is not callable",
//     );
//   }

//   var aArgs = Array.prototype.slice.call(arguments, 1),
//     fToBind = this,
//     fNOP = function () {},
//     fBound = function () {
//       return fToBind.apply(
//         this instanceof fNOP && oThis ? this : oThis,
//         aArgs.concat(Array.prototype.slice.call(arguments)),
//       );
//     };

//   fNOP.prototype = this.prototype;
//   fBound.prototype = new fNOP();

//   return fBound;
// };
