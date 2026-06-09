//+++++++++++++++++++++++++something about CCGame begin+++++++++++++++++++++++++++
namespace cc {
  export enum EDebugMode {
    DEBUG_MODE_NONE = 0,
    DEBUG_MODE_INFO,
    DEBUG_MODE_WARN,
    DEBUG_MODE_ERROR,
    DEBUG_MODE_INFO_FOR_WEB_PAGE,
    DEBUG_MODE_WARN_FOR_WEB_PAGE,
    DEBUG_MODE_ERROR_FOR_WEB_PAGE,
  }

  /**
   * An object to boot the game.
   * @class
   * @name cc.game
   */
  export class game {
    static readonly DEBUG_MODE_NONE = 0;
    static readonly DEBUG_MODE_INFO = 1;
    static readonly DEBUG_MODE_WARN = 2;
    static readonly DEBUG_MODE_ERROR: 3;
    static readonly DEBUG_MODE_INFO_FOR_WEB_PAGE: 4;
    static readonly DEBUG_MODE_WARN_FOR_WEB_PAGE: 5;
    static readonly DEBUG_MODE_ERROR_FOR_WEB_PAGE: 6;

    static readonly EVENT_HIDE: "game_on_hide";
    static readonly EVENT_SHOW: "game_on_show";
    static readonly EVENT_RESIZE: "game_on_resize";

    static readonly RENDER_TYPE_CANVAS: 0;
    static readonly RENDER_TYPE_WEBGL: 1;
    static readonly RENDER_TYPE_OPENGL: 2;

    static readonly _eventHide: null;
    static readonly _eventShow: null;

    /**
     * Key of config
     * @constant
     * @type {Object}
     */
    static readonly CONFIG_KEY = {
      width: "width",
      height: "height",
      engineDir: "engineDir",
      modules: "modules",
      debugMode: "debugMode",
      showFPS: "showFPS",
      frameRate: "frameRate",
      id: "id",
      renderMode: "renderMode",
      jsList: "jsList",
    };

    // states
    private static _paused = false; //whether the game is paused
    private static _prepareCalled = false; //whether the prepare function has been called
    private static _prepared = false; //whether the engine has prepared

    private static _intervalId: number | null = null; //interval target of main

    /**
     * Config of game
     * @type {Object}
     */
    static config: GameConfig;

    /**
     * Callback when the scripts of engine have been load.
     * @type {Function}
     */
    static onStart?: () => void;

    /**
     * Callback when game exits.
     * @type {Function}
     */
    static onStop?: () => void;

    //@Public Methods

    //  @Game play control
    /**
     * Set frameRate of game.
     * @param frameRate
     */
    static setFrameRate(frameRate: number) {
      const self = this,
        config = self.config,
        CONFIG_KEY = self.CONFIG_KEY;

      config.frameRate = frameRate;
      cc.director.setAnimationInterval(1.0 / frameRate);
    }

    /**
     * Run the game frame by frame.
     */
    static step() {
      cc.director.mainLoop();
    }

    /**
     * Pause the game.
     */
    static pause() {
      this._paused = true;
      cc.director.pause();
    }

    /**
     * Resume the game from pause.
     */
    static resume() {
      this._paused = false;
      cc.director.resume();
    }

    /**
     * Check whether the game is paused.
     */
    static isPaused() {
      return this._paused;
    }

    /**
     * Restart game.
     */
    static restart() {
      __restartVM();
    }

    /**
     * End game, it will close the game window
     */
    static end() {
      close();
    }

    //  @Game loading
    /**
     * Prepare game.
     * @param cb
     */
    static prepare(cb?: () => void) {
      const self = this,
        config = self.config;

      this._loadConfig();

      // Already prepared
      if (this._prepared) {
        cb?.();
        return;
      }
      // Prepare called, but not done yet
      if (this._prepareCalled) {
        return;
      }
      // Prepare never called and engine ready
      if (cc._engineLoaded) {
        this._prepareCalled = true;

        // Load game scripts
        const jsList = config.jsList;
        if (jsList) {
          cc.loader.loadJsWithImg("", jsList, function (err: string | null) {
            if (err) throw new Error(err);
            self._prepared = true;
            if (cb) cb();
          });
        } else {
          if (cb) cb();
        }

        return;
      }

      // Engine not loaded yet
      cc.initEngine(this.config, function () {
        self.prepare(cb);
      });
    }

    /**
     * Run game with configuration object and onStart function.
     * @param {Object|Function} [config] Pass configuration object or onStart function
     * @param {onStart} [onStart] onStart function to be executed after game initialized
     */
    static run(config: GameConfig, onStart: () => void) {
      if (typeof config === "function") {
        cc.game.onStart = config;
      } else {
        if (config) {
          cc.game.config = config;
        }
        if (typeof onStart === "function") {
          cc.game.onStart = onStart;
        }
      }

      this.prepare(cc.game.onStart?.bind(cc.game));
    }

    //@Private Methods

    private static _loadConfig() {
      // Load config
      // Already loaded
      if (this.config) {
        this._initConfig(this.config);
      }
      // Load from project.json
      else {
        try {
          const txt = jsb.fileUtils.getStringFromFile("project.json");
          const data = JSON.parse(txt) as GameConfig;
          this._initConfig(data || {});
        } catch (e) {
          console.log("Failed to read or parse project.json");
          this._initConfig({} as any);
        }
      }
    }

    private static _initConfig(config: GameConfig) {
      // Configs adjustment
      config.showFPS ??= true;
      config.engineDir ??= "frameworks/cocos2d-html5";
      config.debugMode ??= EDebugMode.DEBUG_MODE_NONE;
      config.frameRate ??= 60;
      config.renderMode ??= 0;

      this.config = config;

      cc.director.setDisplayStats(this.config.showFPS);
      cc.director.setAnimationInterval(1.0 / this.config.frameRate);
    }
  }
}
