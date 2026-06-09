declare namespace cc {
  // var game: Game;

  type GameConfig = {
    project_type: string;
    width?: number;
    height?: number;
    engineDir?: string;
    modules?: Array<string> | string;
    debugMode?: number;
    exposeClassName?: "exposeClassName";
    showFPS?: boolean;
    frameRate?: number;
    id?: string;
    renderMode?: number;
    jsList?: Array<string>;
    noCache?: boolean;
  };

  class Container {}

  class Game {
    /**
     * Debug mode: No debugging. {@static}
     * @const {Number}
     * @static
     */
    DEBUG_MODE_NONE: 0;
    /**
     * Debug mode: Info, warning, error to console.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_INFO: 1;
    /**
     * Debug mode: Warning, error to console.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_WARN: 2;
    /**
     * Debug mode: Error to console.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_ERROR: 3;
    /**
     * Debug mode: Info, warning, error to web page.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_INFO_FOR_WEB_PAGE: 4;
    /**
     * Debug mode: Warning, error to web page.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_WARN_FOR_WEB_PAGE: 5;
    /**
     * Debug mode: Error to web page.
     * @const {Number}
     * @static
     */
    DEBUG_MODE_ERROR_FOR_WEB_PAGE: 6;

    /**
     * Event that is fired when the game is hidden.
     * @constant {String}
     */
    EVENT_HIDE: "game_on_hide";
    /**
     * Event that is fired when the game is shown.
     * @constant {String}
     */
    EVENT_SHOW: "game_on_show";
    /**
     * Event that is fired when the game is resized.
     * @constant {String}
     */
    EVENT_RESIZE: "game_on_resize";
    /**
     * Event that is fired when the renderer is done being initialized.
     * @constant {String}
     */
    EVENT_RENDERER_INITED: "renderer_inited";

    /** @constant {Number} */
    RENDER_TYPE_CANVAS: 0;
    /** @constant {Number} */
    RENDER_TYPE_WEBGL: 1;
    /** @constant {Number} */
    RENDER_TYPE_OPENGL: 2;

    /**
     * Keys found in project.json.
     *
     * @constant
     * @type {Object}
     *
     * @prop {String} engineDir         - In debug mode, if you use the whole engine to develop your game, you should specify its relative path with "engineDir".
     * @prop {String} modules           - Defines which modules you will need in your game, it's useful only on web
     * @prop {String} debugMode         - Debug mode, see DEBUG_MODE_XXX constant definitions.
     * @prop {String} exposeClassName   - Expose class name to chrome debug tools
     * @prop {String} showFPS           - Left bottom corner fps information will show when "showFPS" equals true, otherwise it will be hide.
     * @prop {String} frameRate         - Sets the wanted frame rate for your game, but the real fps depends on your game implementation and the running environment.
     * @prop {String} id                - Sets the id of your canvas element on the web page, it's useful only on web.
     * @prop {String} renderMode        - Sets the renderer type, only useful on web, 0: Automatic, 1: Canvas, 2: WebGL
     * @prop {String} jsList            - Sets the list of js files in your game.
     */
    CONFIG_KEY: GameConfig;

    frame: null;
    /**
     * The container of game canvas, equals to cc.container
     * @type {Object}
     */
    container: Container;
    /**
     * The canvas of the game, equals to cc._canvas
     * @type {Object}
     */
    canvas: null;

    /**
     * Config of game
     * @type {Object}
     */
    config: null;

    /**
     * Callback when the scripts of engine have been load.
     * @type {Function|null}
     */
    onStart: () => Promise<void> | void | null;

    /**
     * Callback when game exits.
     * @type {Function|null}
     */
    onStop: () => void | null;

    // //@Public Methods

    //  @Game play control
    /**
     * Set frameRate of game.
     * @param frameRate
     */
    setFrameRate(frameRate: number): void;

    /**
     * Run the game frame by frame.
     */
    step(): void;

    /**
     * Pause the game.
     */
    pause(): void;

    //   /**
    //    * Resume the game from pause.
    //    */
    resume(): void;

    /**
     * Check whether the game is paused.
     */
    isPaused(): boolean;

    /**
     * Restart game.
     */
    restart(): void;

    /**
     * End game, it will close the game window
     */
    end(): void;

    //  @Game loading
    /**
     * Prepare game.
     * @param cb
     */
    prepare(cb: () => void): void;

    /**
     * Run game with configuration object and onStart function.
     * @param {Object|Function} [config] Pass configuration object or onStart function
     * @param {onStart} [onStart] onStart function to be executed after game initialized
     */
    run(config?: GameConfig, onStart?: () => void): void;
  }

  let _engineLoaded: boolean;
}

declare const __restartVM: () => void;
declare const __getPlatform: () => number;

declare const __getOS: () => string;

declare const __cleanScript: (jsFile: string) => void;
declare const __isObjectValid: (obj: any) => boolean;
