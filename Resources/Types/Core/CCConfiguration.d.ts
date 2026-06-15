/**
 * cc.configuration is a singleton object which contains some openGL variables
 * @class
 * @name cc.configuration
 * @example
 * var textureSize = cc.configuration.getMaxTextureSize();
 */
declare namespace cc {
  let configuration: Configuration;
  class Configuration {
    static getInstance(): Configuration;
    // Type constants
    /*
     * ERROR type
     * @public
     * @const
     * @type {Number}
     */
    ERROR: number;

    /*
     * STRING type
     * @public
     * @const
     * @type {Number}
     */
    STRING: number;

    /*
     * INT type
     * @public
     * @const
     * @type {Number}
     */
    INT: number;

    /*
     * DOUBLE type
     * @public
     * @const
     * @type {Number}
     */
    DOUBLE: number;

    /*
     * BOOLEAN type
     * @public
     * @const
     * @type {Number}
     */
    BOOLEAN: number;

    _maxTextureSize: number;
    _maxModelviewStackDepth: number;
    _supportsPVRTC: boolean;
    _supportsNPOT: boolean;
    _supportsBGRA8888: boolean;
    _supportsDiscardFramebuffer: boolean;
    _supportsShareableVAO: boolean;
    _maxSamplesAllowed: number;
    _maxTextureUnits: number;
    _GlExtensions: string;
    _valueDict: { [key: string]: any };

    _inited: boolean;

    _init(): void;

    /**
     * OpenGL Max texture size.
     * @return {Number}
     */
    getMaxTextureSize(): number;

    /**
     * OpenGL Max Modelview Stack Depth.
     * @return {Number}
     */
    getMaxModelviewStackDepth(): number;

    /**
     * returns the maximum texture units
     * @return {Number}
     */
    getMaxTextureUnits(): number;

    /**
     * Whether or not the GPU supports NPOT (Non Power Of Two) textures.
     * OpenGL ES 2.0 already supports NPOT (iOS).
     * @return {Boolean}
     */
    supportsNPOT(): boolean;
    /**
     * Whether or not PVR Texture Compressed is supported
     * @return {Boolean}
     */
    supportsPVRTC(): boolean;

    /**
     * Whether or not ETC Texture Compressed is supported
     * @return {Boolean}
     */
    supportsETC(): boolean;

    /**
     * Whether or not S3TC Texture Compressed is supported
     * @return {Boolean}
     */
    supportsS3TC(): boolean;

    /**
     * Whether or not ATITC Texture Compressed is supported
     * @return {Boolean}
     */
    supportsATITC(): boolean;

    /**
     * Whether or not BGRA8888 textures are supported.
     * @return {Boolean}
     */
    supportsBGRA8888(): boolean;

    /**
     * Whether or not glDiscardFramebufferEXT is supported
     * @return {Boolean}
     */
    supportsDiscardFramebuffer(): boolean;

    /**
     * Whether or not shareable VAOs are supported.
     * @return {Boolean}
     */
    supportsShareableVAO(): boolean;

    /**
     * returns whether or not an OpenGL is supported
     * @param {String} searchName
     */
    checkForGLExtension(searchName: string): boolean;

    /**
     * Returns the value of a given key.  If the key is not found, it will return the default value
     * @param {String} key
     * @param {String|Bool|Number|Object} [default_value=null]
     * @returns {String|Bool|Number|Object}
     */
    getValue(
      key: string,
      default_value?: string | boolean | number | object,
    ): string | boolean | number | object;

    /**
     * Sets a new key/value pair  in the configuration dictionary
     * @param {string} key
     * @param {String|Bool|Number|Object} value
     */
    setValue(key: string, value: string | boolean | number | object): void;

    /**
     * Dumps the current configuration on the console
     */
    dumpInfo(): void;

    /**
     * gathers OpenGL / GPU information
     */
    gatherGPUInfo(): void;

    /**
     * Loads a config file. If the keys are already present, then they are going to be replaced. Otherwise the new keys are added.
     * @param {string} url
     */
    loadConfigFile(url: string): void;
  }
}
