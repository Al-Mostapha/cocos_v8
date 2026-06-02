namespace cc {
  //+++++++++++++++++++++++++something about loader start+++++++++++++++++++++++++++
  export class loader {
   static _resPath = "";
   static _audioPath = "";
   static _register: Record<string, any> = {}; //register of loaders
   static cache: Map<string, any> =  new Map(); //cache for data loaded
   static _langPathCache = {}; //cache for lang path
    //@MODE_BEGIN DEV
   static _jsCache =  {}; //cache for js

    /**
     * Get XMLHttpRequest.
     * @returns {XMLHttpRequest}
     */
    static  getXMLHttpRequest () {
      return new XMLHttpRequest();
    }



   private static _getArgs4Js(args: [string | string[], (string | Function | string[])?  ,Function? ]) {
      const a0 = args[0],
        a1 = args[1],
        a2 = args[2],
        results: any[] = ["", null, null];

      if (args.length === 1) {
        results[1] = a0 instanceof Array ? a0 : [a0];
      } else if (args.length === 2) {
        if (typeof a1 === "function") {
          results[1] = a0 instanceof Array ? a0 : [a0];
          results[2] = a1;
        } else {
          results[0] = a0 || "";
          results[1] = a1 instanceof Array ? a1 : [a1];
        }
      } else if (args.length === 3) {
        results[0] = a0 || "";
        results[1] = a1 instanceof Array ? a1 : [a1];
        results[2] = a2;
      } else throw new Error("arguments error to load js!");
      return results;
    }

    /**
     * Load js files.
     * @param {?string=} baseDir   The pre path for jsList.
     * @param {array.<string>} jsList    List of js path.
     * @param {function} cb        Callback function
     *
     *      If the arguments.length == 2, then the baseDir turns to be "".
     * @returns {*}
     */
    static loadJs(baseDir: string, jsList: string[], cb?: Function) {
      const self = this,
        localJsCache = self._jsCache;
      for (const jsFile of jsList) {
        cc.require(cc.path.join(baseDir, jsFile));
      }
     cb?.();
    }

    /**
     * Load js width loading image.
     *
     * @param {string} [baseDir]
     * @param {array} jsList
     * @param {function} [cb]
     */
    static loadJsWithImg(baseDir: string, jsList: string[], cb?: Function) {
      this.loadJs( baseDir, jsList, cb);
    }

    //@MODE_END DEV

    /**
     * Load a single resource as txt.
     * @param {!string} url
     * @param {function} cb arguments are : err, txt
     */
    loadTxt (url: string, cb?: Function) {
      cb?.(null, jsb.fileUtils.getStringFromFile(url));
    }

    loadJson(url: string, cb: Function) {
      this.loadTxt(url, (err: Error, txt: string) => {
        try {
          err ? cb(err) : cb(null, JSON.parse(txt));
        } catch (e) {
          throw e;
          cb("load json [" + url + "] failed : " + e);
        }
      });
    }

    /**
     * Load a single image.
     * @param {!string} url
     * @param {object} [option]
     * @param {function} cb
     * @returns {Image}
     */
    loadImg(url: string, option: any | Function, cb?: Function) {
      var l = arguments.length;
      if (l == 2) cb = option;

      var cachedTex = cc.textureCache.getTextureForKey(url);
      if (cachedTex) {
        cb && cb(null, cachedTex);
      } else if (url.match(jsb.urlRegExp)) {
        jsb.loadRemoteImg(url, function (succeed: boolean, tex: string) {
          if (succeed) {
            cb && cb(null, tex);
          } else {
            cb && cb("Load image failed");
          }
        });
      } else {
        cc.textureCache._addImageAsync(url, function (tex: any) {
          if (tex instanceof cc.Texture2D) cb && cb(null, tex);
          else cb && cb("Load image failed");
        });
      }
    }

    /**
     * Load binary data by url.
     * @param {String} url
     * @param {Function} cb
     */
    static loadBinary(url: string, cb: Function) {
      cb(null, jsb.fileUtils.getDataFromFile(url));
    }

    static loadBinarySync(url: string) {
      return jsb.fileUtils.getDataFromFile(url);
    }

    /**
     * Iterator function to load res
     * @param {object} item
     * @param {number} index
     * @param {function} [cb]
     * @returns {*}
     * @private
     */
    static _loadResIterator(item: any, index: number, cb: Function) {
      const self = this;
      let url: string  = null as any;
      let type = item.type;

      if (type) {
        type = "." + type.toLowerCase();
        url = item.src ? item.src : item.name + type;
      } else {
        url = item;
        type = cc.path.extname(url!);
      }

      const obj = this.cache.get(url!);
      if (obj) return cb(null, obj);
      var loader = null;
      if (type) {
        loader = self._register[type.toLowerCase()];
      }
      if (!loader) {
        cc.error("loader for [" + type + "] not exists!");
        return cb();
      }
      var basePath = loader.getBasePath ? loader.getBasePath() : self.resPath;
      var realUrl = self.getUrl(basePath, url);

      loader.load(realUrl, url, item, function (err: Error, data: any) {
        if (err) {
          cc.log(err);
          self.cache[url!] = null;
          delete self.cache[url!];
          cb();
        } else {
          self.cache[url!] = data;
          cb(null, data);
        }
      });
    }

    /**
     * Get url with basePath.
     * @param {string} basePath
     * @param {string} [url]
     * @returns {*}
     */
    getUrl: function (basePath: string, url: string) {
      var self = this,
        langPathCache = self._langPathCache,
        path = cc.path;
      if (basePath !== undefined && url === undefined) {
        url = basePath;
        var type = path.extname(url);
        type = type ? type.toLowerCase() : "";
        var loader = self._register[type];
        if (!loader) basePath = self.resPath;
        else
          basePath = loader.getBasePath ? loader.getBasePath() : self.resPath;
      }
      url = cc.path.join(basePath || "", url);
      if (url.match(/[\/(\\\\)]lang[\/(\\\\)]/i)) {
        if (langPathCache[url]) return langPathCache[url];
        var extname = path.extname(url) || "";
        url = langPathCache[url] =
          url.substring(0, url.length - extname.length) +
          "_" +
          cc.sys.language +
          extname;
      }
      return url;
    },

    /**
     * Load resources then call the callback.
     * @param {string} resources
     * @param {function} [option] callback or trigger
     * @param {function|Object} [loadCallback]
     * @return {cc.AsyncPool}
     */
    load: function (
      resources: string | string[],
      option: any,
      loadCallback: Function,
    ) {
      var self = this;
      var len = arguments.length;
      if (len === 0) throw new Error("arguments error!");

      if (len === 3) {
        if (typeof option === "function") {
          if (typeof loadCallback === "function")
            option = { trigger: option, cb: loadCallback };
          else option = { cb: option, cbTarget: loadCallback };
        }
      } else if (len === 2) {
        if (typeof option === "function") option = { cb: option };
      } else if (len === 1) {
        option = {};
      }

      if (!(resources instanceof Array)) resources = [resources];
      var asyncPool = new cc.AsyncPool(
        resources,
        0,
        function (
          value: any,
          index: number,
          AsyncPoolCallback: Function,
          aPool: any,
        ) {
          self._loadResIterator(
            value,
            index,
            function (err: Error | null, data: any) {
              var arr = Array.prototype.slice.call(arguments, 1);
              if (option.trigger)
                option.trigger.call(
                  option.triggerTarget,
                  arr[0],
                  aPool.size,
                  aPool.finishedSize,
                ); //call trigger
              AsyncPoolCallback(err, arr[0]);
            },
          );
        },
        option.cb,
        option.cbTarget,
      );
      asyncPool.flow();
      return asyncPool;
    },

    /**
     * <p>
     *     Loads alias map from the contents of a filename.                                        <br/>
     *                                                                                                                 <br/>
     *     @note The plist file name should follow the format below:                                                   <br/>
     *     <?xml version="1.0" encoding="UTF-8"?>                                                                      <br/>
     *         <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">  <br/>
     *             <plist version="1.0">                                                                               <br/>
     *                 <dict>                                                                                          <br/>
     *                     <key>filenames</key>                                                                        <br/>
     *                     <dict>                                                                                      <br/>
     *                         <key>sounds/click.wav</key>                                                             <br/>
     *                         <string>sounds/click.caf</string>                                                       <br/>
     *                         <key>sounds/endgame.wav</key>                                                           <br/>
     *                         <string>sounds/endgame.caf</string>                                                     <br/>
     *                         <key>sounds/gem-0.wav</key>                                                             <br/>
     *                         <string>sounds/gem-0.caf</string>                                                       <br/>
     *                     </dict>                                                                                     <br/>
     *                     <key>metadata</key>                                                                         <br/>
     *                     <dict>                                                                                      <br/>
     *                         <key>version</key>                                                                      <br/>
     *                         <integer>1</integer>                                                                    <br/>
     *                     </dict>                                                                                     <br/>
     *                 </dict>                                                                                         <br/>
     *              </plist>                                                                                           <br/>
     * </p>
     * @param {String} filename  The plist file name.
     * @param {Function} cb     callback
     */
    loadAliases: function (url: string, cb: Function) {
      jsb.fileUtils.loadFilenameLookup(url);
      if (cb) cb();
    },

    /**
     * Register a resource loader into loader.
     * @param {string} extNames
     * @param {function} loader
     */
    register: function (extNames: string | string[], loader: Function) {
      if (!extNames || !loader) return;
      var self = this;
      if (typeof extNames === "string")
        return (this._register[extNames.trim().toLowerCase()] = loader);
      for (var i = 0, li = extNames.length; i < li; i++) {
        self._register["." + extNames[i].trim().toLowerCase()] = loader;
      }
    },

    /**
     * Get resource data by url.
     * @param url
     * @returns {*}
     */
    getRes: function (url: string) {
      var cached = this.cache[url];
      if (cached) return cached;
      var type = cc.path.extname(url);
      if (!type) return cc.log("cc.loader.getRes: Invalid url");
      var loader = this._register[type.toLowerCase()];
      if (!loader)
        return cc.log(
          "cc.loader.getRes: loader for [" + type + "] not exists!",
        );
      var basePath = loader.getBasePath ? loader.getBasePath() : this.resPath;
      var realUrl = this.getUrl(basePath, url);
      return loader.load(realUrl, url);
    },

    /**
     * Release the cache of resource by url.
     * @param url
     */
    release: function (url: string) {
      var cache = this.cache;
      delete cache[url];
    },

    /**
     * Resource cache of all resources.
     */
    releaseAll: function () {
      var locCache = this.cache;
      for (var key in locCache) delete locCache[key];
    },
  };

  // TODO
  // cc.defineGetterSetter(
  //   cc.loader,
  //   "resPath",
  //   function () {
  //     return this._resPath;
  //   },
  //   function (resPath) {
  //     this._resPath = resPath || "";
  //     jsb.fileUtils.addSearchPath(this._resPath);
  //   },
  // );
  // cc.defineGetterSetter(
  //   cc.loader,
  //   "audioPath",
  //   function () {
  //     return this._audioPath;
  //   },
  //   function (audioPath) {
  //     this._audioPath = audioPath || "";
  //     jsb.fileUtils.addSearchPath(this._audioPath);
  //   },
  // );
}
