declare module cc {
  /****************************************************************************
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011-2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 Copyright 2011 Jeff Lamarche
 Copyright 2012 Goffredo Marocchi

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

  /**
   * Class that implements a WebGL program
   * @class
   * @extends cc.Class
   */
  class GLProgram extends cc.Class {
    /**
     * Create a cc.GLProgram object
     * @param {String} vShaderFileName
     * @param {String} fShaderFileName
     * @returns {cc.GLProgram}
     */
    constructor(
      vShaderFileName?: string,
      fShaderFileName?: string,
      glContext?: any
    );

    static createWithByteArrays(
      vertShaderStr: string,
      fragShaderStr: string
    ): cc.GLProgram;

    static createWithFilenames(
      vertFileName: string,
      fragFileName: string
    ): cc.GLProgram;

    /**
     * destroy program
     */
    destroyProgram(): void;

    /**
     * Initializes the cc.GLProgram with a vertex and fragment with string
     * @param {String} vertShaderStr
     * @param {String} fragShaderStr
     * @return {Boolean}
     */
    initWithVertexShaderByteArray(
      vertShaderStr: string,
      fragShaderStr: string
    ): boolean;

    /**
     * Initializes the cc.GLProgram with a vertex and fragment with string
     * @param {String} vertShaderStr
     * @param {String} fragShaderStr
     * @return {Boolean}
     */
    initWithString(vertShaderStr: string, fragShaderStr: string): boolean;

    /**
     * Initializes the CCGLProgram with a vertex and fragment with contents of filenames
     * @param {String} vShaderFilename
     * @param {String} fShaderFileName
     * @return {Boolean}
     */
    initWithVertexShaderFilename(
      vShaderFilename: string,
      fShaderFileName: string
    ): boolean;

    /**
     * Initializes the CCGLProgram with a vertex and fragment with contents of filenames
     * @param {String} vShaderFilename
     * @param {String} fShaderFileName
     * @return {Boolean}
     */
    init(vShaderFilename: string, fShaderFileName: string): boolean;
    /**
     * It will add a new attribute to the shader
     * @param {String} attributeName
     * @param {Number} index
     */
    addAttribute(attributeName: string, index: number): void;

    /**
     * links the glProgram
     * @return {Boolean}
     */
    link(): boolean;

    /**
     * it will call glUseProgram()
     */
    use(): void;

    /**
     * It will create 4 uniforms:
     *  cc.UNIFORM_PMATRIX
     *  cc.UNIFORM_MVMATRIX
     *  cc.UNIFORM_MVPMATRIX
     *  cc.UNIFORM_SAMPLER
     */
    updateUniforms(): void;

    /**
     * calls retrieves the named uniform location for this shader program.
     * @param {String} name
     * @returns {Number}
     */
    getUniformLocationForName(name: string): number;

    /**
     * get uniform MVP matrix
     * @returns {WebGLUniformLocation}
     */
    getUniformMVPMatrix(): WebGLUniformLocation;

    /**
     * get uniform sampler
     * @returns {WebGLUniformLocation}
     */
    getUniformSampler(): WebGLUniformLocation;
    /**
     * calls glUniform1i only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} i1
     */
    setUniformLocationWith1i(
      location: WebGLUniformLocation | string,
      i1: number
    ): void;

    /**
     * calls glUniform2i only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} i1
     * @param {Number} i2
     */
    setUniformLocationWith2i(
      location: WebGLUniformLocation | string,
      i1: number,
      i2: number
    ): void;

    /**
     * calls glUniform3i only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} i1
     * @param {Number} i2
     * @param {Number} i3
     */
    setUniformLocationWith3i(
      location: WebGLUniformLocation | string,
      i1: number,
      i2: number,
      i3: number
    ): void;

    /**
     * calls glUniform4i only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} i1
     * @param {Number} i2
     * @param {Number} i3
     * @param {Number} i4
     */
    setUniformLocationWith4i(
      location: WebGLUniformLocation | string,
      i1: number,
      i2: number,
      i3: number,
      i4: number
    ): void;

    /**
     * calls glUniform2iv
     * @param {WebGLUniformLocation|String} location
     * @param {Int32Array} intArray
     * @param {Number} numberOfArrays
     */
    setUniformLocationWith2iv(
      location: WebGLUniformLocation | string,
      intArray: Int32Array
    ): void;

    /**
     * calls glUniform3iv
     * @param {WebGLUniformLocation|String} location
     * @param {Int32Array} intArray
     */
    setUniformLocationWith3iv(
      location: WebGLUniformLocation | string,
      intArray: Int32Array
    ): void;

    /**
     * calls glUniform4iv
     * @param {WebGLUniformLocation|String} location
     * @param {Int32Array} intArray
     */
    setUniformLocationWith4iv(
      location: WebGLUniformLocation | string,
      intArray: Int32Array
    ): void;

    /**
     * calls glUniform1i only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} i1
     */
    setUniformLocationI32(
      location: WebGLUniformLocation | string,
      i1: number
    ): void;

    /**
     * calls glUniform1f only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} f1
     */
    setUniformLocationWith1f(
      location: WebGLUniformLocation | string,
      f1: number
    ): void;

    /**
     * calls glUniform2f only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} f1
     * @param {Number} f2
     */
    setUniformLocationWith2f(
      location: WebGLUniformLocation | string,
      f1: number,
      f2: number
    ): void;

    /**
     * calls glUniform3f only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} f1
     * @param {Number} f2
     * @param {Number} f3
     */
    setUniformLocationWith3f(
      location: WebGLUniformLocation | string,
      f1: number,
      f2: number,
      f3: number
    ): void;

    /**
     * calls glUniform4f only if the values are different than the previous call for this same shader program.
     * @param {WebGLUniformLocation|String} location
     * @param {Number} f1
     * @param {Number} f2
     * @param {Number} f3
     * @param {Number} f4
     */
    setUniformLocationWith4f(
      location: WebGLUniformLocation | string,
      f1: number,
      f2: number,
      f3: number,
      f4: number
    ): void;
    /**
     * calls glUniform2fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} floatArray
     */
    setUniformLocationWith2fv(
      location: WebGLUniformLocation | string,
      floatArray: Float32Array
    ): void;

    /**
     * calls glUniform3fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} floatArray
     */
    setUniformLocationWith3fv(
      location: WebGLUniformLocation | string,
      floatArray: Float32Array
    ): void;

    /**
     * calls glUniform4fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} floatArray
     */
    setUniformLocationWith4fv(
      location: WebGLUniformLocation | string,
      floatArray: Float32Array
    ): void;

    /**
     * calls glUniformMatrix2fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} matrixArray
     */
    setUniformLocationWithMatrix2fv(
      location: WebGLUniformLocation | string,
      matrixArray: Float32Array
    ): void;

    /**
     * calls glUniformMatrix3fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} matrixArray
     */
    setUniformLocationWithMatrix3fv(
      location: WebGLUniformLocation | string,
      matrixArray: Float32Array
    ): void;

    /**
     * calls glUniformMatrix4fv
     * @param {WebGLUniformLocation|String} location
     * @param {Float32Array} matrixArray
     */
    setUniformLocationWithMatrix4fv(
      location: WebGLUniformLocation | string,
      matrixArray: Float32Array
    ): void;

    setUniformLocationF32(): void;

    /**
     * will update the builtin uniforms if they are different than the previous call for this same shader program.
     */
    setUniformsForBuiltins(): void;

    /**
     * returns the vertexShader error log
     * @return {String}
     */
    vertexShaderLog(): string;

    /**
     * returns the vertexShader error log
     * @return {String}
     */
    getVertexShaderLog(): string;

    /**
     * returns the fragmentShader error log
     * @returns {String}
     */
    getFragmentShaderLog(): string;

    /**
     * returns the fragmentShader error log
     * @return {String}
     */
    fragmentShaderLog(): string;

    /**
     * returns the program error log
     * @return {String}
     */
    programLog(): string;

    /**
     * returns the program error log
     * @return {String}
     */
    getProgramLog(): string;

    /**
     *  reload all shaders, this function is designed for android  <br/>
     *  when opengl context lost, so don't call it.
     */
    reset(): void;

    /**
     * get WebGLProgram object
     * @return {WebGLProgram}
     */
    getProgram(): WebGLProgram;

    /**
     * Currently JavaScript Bindings (JSB), in some cases, needs to use retain and release. This is a bug in JSB,
     * and the ugly workaround is to use retain/release. So, these 2 methods were added to be compatible with JSB.
     * This is a hack, and should be removed once JSB fixes the retain/release bug
     */
    retain(): void;
    release(): void;
  }

  /**
   * <p>
   *     Sets the shader program for this node
   *
   *     Since v2.0, each rendering node must set its shader program.
   *     It should be set in initialize phase.
   * </p>
   * @function
   * @param {cc.Node} node
   * @param {cc.GLProgram} program The shader program which fetches from CCShaderCache.
   * @example
   * cc.setGLProgram(node, cc.shaderCache.programForKey(cc.SHADER_POSITION_TEXTURECOLOR));
   */
  function setProgram(node: cc.Node, program: cc.GLProgram): void;
}
