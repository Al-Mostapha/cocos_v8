declare module cc {
  /****************************************************************************
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011-2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.

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

  class UniformValue {
    constructor(uniform: any, glprogram: GLProgram);
    setFloat(value: number): void;

    // setInt: function setInt(value) {
    // this._value = value;
    // this._type = types.GL_INT;
    // },
    setInt(value: number): void;

    // setVec2: function setVec2(v1, v2) {
    // this._value = [v1, v2];
    // this._type = types.GL_FLOAT_VEC2;
    // },

    setVec2(v1: number, v2: number): void;

    // setVec2v: function setVec2v(value) {
    // this._value = value.slice(0);
    // this._type = types.GL_FLOAT_VEC2;
    // },
    setVec2v(value: number[]): void;

    // setVec3: function setVec3(v1, v2, v3) {
    // this._value = [v1, v2, v3];
    // this._type = types.GL_FLOAT_VEC3;
    // },
    setVec3(v1: number, v2: number, v3: number): void;

    // setVec3v: function setVec3v(value) {
    // this._value = value.slice(0);
    // this._type = types.GL_FLOAT_VEC3;
    // },
    setVec3v(value: number[]): void;
    // setVec4: function setVec4(v1, v2, v3, v4) {
    // this._value = [v1, v2, v3, v4];
    // this._type = types.GL_FLOAT_VEC4;
    // },
    setVec4(v1: number, v2: number, v3: number, v4: number): void;

    // setVec4v: function setVec4v(value) {
    // this._value = value.slice(0);
    // this._type = types.GL_FLOAT_VEC4;
    // },
    setVec4v(value: number[]): void;

    // setMat4: function setMat4(value) {
    // this._value = value.slice(0);
    // this._type = types.GL_FLOAT_MAT4;
    // },
    setMat4(value: number[]): void;

    // setCallback: function setCallback(fn) {
    // this._value = fn;
    // this._type = types.GL_CALLBACK;
    // },
    setCallback(fn: (glprogram: GLProgram, uniform: any) => void): void;

    // setTexture: function setTexture(textureId, textureUnit) {
    // this._value = textureUnit;
    // this._textureId = textureId;
    // this._type = types.GL_TEXTURE;
    // },
    setTexture(textureId: number, textureUnit: number): void;

    apply(): void;
  }

  // cc.GLProgramState = function (glprogram) {
  class GLProgramState {
    constructor(glprogram: GLProgram);
    apply(modelView: any /**matrix */): void;
    // setGLProgram: function setGLProgram(glprogram) {
    // this._glprogram = glprogram;
    // },
    setGLProgram(glprogram: GLProgram): void;
    // getGLProgram: function getGLProgram() {
    // return this._glprogram;
    // },
    getGLProgram(): GLProgram;
    // getUniformCount: function getUniformCount() {
    // return this._uniforms.length;
    // },
    getUniformCount(): number;
    // getUniformValue: function getUniformValue(uniform) {
    // return this._uniforms[uniform];
    // },
    getUniformValue(uniform: string): UniformValue;
    // setUniformInt: function setUniformInt(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setInt(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformInt(uniform: string, value: number): void;
    // setUniformFloat: function setUniformFloat(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setFloat(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformFloat(uniform: string, value: number): void;
    // setUniformVec2: function setUniformVec2(uniform, v1, v2) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec2(v1, v2);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec2(uniform: string, v1: number, v2: number): void;
    // setUniformVec2v: function setUniformVec2v(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec2v(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec2v(uniform: string, value: number[]): void;
    // setUniformVec3: function setUniformVec3(uniform, v1, v2, v3) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec3(v1, v2, v3);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec3(uniform: string, v1: number, v2: number, v3: number): void;
    // setUniformVec3v: function setUniformVec3v(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec3v(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec3v(uniform: string, value: number[]): void;
    // setUniformVec4: function setUniformVec4(uniform, v1, v2, v3, v4) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec4(v1, v2, v3, v4);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec4(
      uniform: string,
      v1: number,
      v2: number,
      v3: number,
      v4: number
    ): void;
    // setUniformVec4v: function setUniformVec4v(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setVec4v(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformVec4v(uniform: string, value: number[]): void;
    // setUniformMat4: function setUniformMat4(uniform, value) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setMat4(value);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformMat4(uniform: string, value: number[]): void;
    // setUniformCallback: function setUniformCallback(uniform, callback) {
    // var v = this.getUniformValue(uniform);
    // if (v) {
    //     v.setCallback(callback);
    // } else {
    //     cc.log("cocos2d: warning: Uniform not found: " + uniform);
    // }
    // },
    setUniformCallback(
      uniform: string,
      callback: (glprogram: GLProgram, uniform: any) => void
    ): void;
    // setUniformTexture: function setUniformTexture(uniform, texture) {
    // var uniformValue = this.getUniformValue(uniform);
    // if (uniformValue) {
    //     var textureUnit = this._boundTextureUnits[uniform];
    //     if (textureUnit) {
    //         uniformValue.setTexture(texture, textureUnit);
    //     } else {
    //         uniformValue.setTexture(texture, this._textureUnitIndex);
    //         this._boundTextureUnits[uniform] = this._textureUnitIndex++;
    //     }
    // }
    // }
    setUniformTexture(uniform: string, texture: Texture2D): void;
  }
}
