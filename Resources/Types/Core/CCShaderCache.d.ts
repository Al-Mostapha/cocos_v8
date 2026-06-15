declare namespace cc {
  /**
   * cc.shaderCache is a singleton object that stores manages GL shaders
   * @class
   * @name cc.shaderCache
   */
  class ShaderCache {
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_TEXTURECOLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_TEXTURECOLOR_ALPHATEST: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_COLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_TEXTURE: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_TEXTURE_UCOLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_TEXTURE_A8COLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_UCOLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_POSITION_LENGTH_TEXTURECOLOR: number;
    /**
     * @public
     * @constant
     * @type {Number}
     */
    static TYPE_MAX: number;

    static getInstance(): ShaderCache;

    _programs: Record<string, cc.GLProgram>;

    // _loadDefaultShader: function (program, type) {
    //   switch (type) {
    //     case this.TYPE_POSITION_TEXTURECOLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_TEXTURE_COLOR_VERT,
    //         cc.SHADER_POSITION_TEXTURE_COLOR_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR);
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       break;
    //     case this.TYPE_POSITION_TEXTURECOLOR_ALPHATEST:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_TEXTURE_COLOR_VERT,
    //         cc.SHADER_POSITION_TEXTURE_COLOR_ALPHATEST_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR);
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       break;
    //     case this.TYPE_POSITION_COLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_COLOR_VERT,
    //         cc.SHADER_POSITION_COLOR_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR);
    //       break;
    //     case this.TYPE_POSITION_TEXTURE:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_TEXTURE_VERT,
    //         cc.SHADER_POSITION_TEXTURE_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       break;
    //     case this.TYPE_POSITION_TEXTURE_UCOLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_TEXTURE_UCOLOR_VERT,
    //         cc.SHADER_POSITION_TEXTURE_UCOLOR_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       break;
    //     case this.TYPE_POSITION_TEXTURE_A8COLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_TEXTURE_A8COLOR_VERT,
    //         cc.SHADER_POSITION_TEXTURE_A8COLOR_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR);
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       break;
    //     case this.TYPE_POSITION_UCOLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_UCOLOR_VERT,
    //         cc.SHADER_POSITION_UCOLOR_FRAG,
    //       );
    //       program.addAttribute("aVertex", cc.VERTEX_ATTRIB_POSITION);
    //       break;
    //     case this.TYPE_POSITION_LENGTH_TEXTURECOLOR:
    //       program.initWithVertexShaderByteArray(
    //         cc.SHADER_POSITION_COLOR_LENGTH_TEXTURE_VERT,
    //         cc.SHADER_POSITION_COLOR_LENGTH_TEXTURE_FRAG,
    //       );

    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_POSITION,
    //         cc.VERTEX_ATTRIB_POSITION,
    //       );
    //       program.addAttribute(
    //         cc.ATTRIBUTE_NAME_TEX_COORD,
    //         cc.VERTEX_ATTRIB_TEX_COORDS,
    //       );
    //       program.addAttribute(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR);
    //       break;
    //     default:
    //       cc.log(
    //         "cocos2d: cc.shaderCache._loadDefaultShader, error shader type",
    //       );
    //       return;
    //   }

    //   program.link();
    //   program.updateUniforms();

    //   //cc.checkGLErrorDebug();
    // },

    /**
     * loads the default shaders
     */
    loadDefaultShaders(): void;

    /**
     * reload the default shaders
     */
    reloadDefaultShaders(): void;

    /**
     * returns a GL program for a given key
     * @param {String} key
     */
    programForKey(key: string): cc.GLProgram;

    /**
     * returns a GL program for a shader name
     * @param {String} shaderName
     * @return {cc.GLProgram}
     */
    getProgram(shaderName: string): cc.GLProgram;

    /**
     * adds a CCGLProgram to the cache for a given name
     * @param {cc.GLProgram} program
     * @param {String} key
     */
    addProgram(program: cc.GLProgram, key: string): void;
  }
}
