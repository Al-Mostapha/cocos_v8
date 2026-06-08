namespace cc {
  // // Basic structure : Color
  // cc.Color = function (r, g, b, a) {
  //   this.r = r || 0;
  //   this.g = g || 0;
  //   this.b = b || 0;
  //   this.a = a === undefined ? 255 : a;
  // };
  export class Color {
    r: number;
    g: number;
    b: number;
    a: number;
    constructor(r: number, g: number, b: number, a?: number) {
      this.r = r ?? 0;
      this.g = g ?? 0;
      this.b = b ?? 0;
      this.a = a === undefined ? 255 : a;
    }
  }

  /**
   * Generate a color object based on multiple forms of parameters
   * @example
   *
   * // 1. All channels separately as parameters
   * var color1 = cc.color(255, 255, 255, 255);
   *
   * // 2. Convert a hex string to a color
   * var color2 = cc.color("#000000");
   *
   * // 3. An color object as parameter
   * var color3 = cc.color({r: 255, g: 255, b: 255, a: 255});
   *
   * Alpha channel is optional. Default value is 255
   *
   * @param {Number|String|cc.Color} r
   * @param {Number} g
   * @param {Number} b
   * @param {Number} [a=255]
   * @returns {cc.Color}
   */
  export const color = (
    r: number | string | cc.Color,
    g?: number,
    b?: number,
    a?: number,
  ): cc.Color => {
    if (r === undefined) return new cc.Color(0, 0, 0, 255);
    if (typeof r === "string") return cc.hexToColor(r);
    if (typeof r === "object")
      return new cc.Color(r.r ?? 0, r.g ?? 0, r.b ?? 0, r.a ?? 255);
    return new cc.Color(r, g ?? 0, b ?? 0, a ?? 255);
  };

  /**
   * returns true if both ccColor3B are equal. Otherwise it returns false.
   * @param {cc.Color} color1
   * @param {cc.Color} color2
   * @return {Boolean}  true if both ccColor3B are equal. Otherwise it returns false.
   */
  export const colorEqual = function (
    color1: cc.Color,
    color2: cc.Color,
  ): boolean {
    return (
      color1.r === color2.r && color1.g === color2.g && color1.b === color2.b
    );
  };

  /**
   * convert a string of color for style to Color.
   * e.g. "#ff06ff"  to : cc.color(255,6,255)
   * @param {String} hex
   * @return {cc.Color}
   */
  export const hexToColor = (hex: string): cc.Color => {
    hex = hex.replace(/^#?/, "0x");
    const c = parseInt(hex);
    const r = c >> 16;
    const g = (c >> 8) % 256;
    const b = c % 256;
    return cc.color(r, g, b);
  };

  /**
   * convert Color to a string of color for style.
   * e.g.  cc.color(255,6,255)  to : "#ff06ff"
   * @param {cc.Color} color
   * @return {String}
   */
  export const colorToHex = (color: cc.Color): string => {
    var hR = color.r.toString(16);
    var hG = color.g.toString(16);
    var hB = color.b.toString(16);
    var hex =
      "#" +
      (color.r < 16 ? "0" + hR : hR) +
      (color.g < 16 ? "0" + hG : hG) +
      (color.b < 16 ? "0" + hB : hB);
    return hex;
  };

  /**
   * White color (255, 255, 255, 255)
   * @returns {cc.Color}
   * @private
   */
  color._getWhite = () => {
    return cc.color(255, 255, 255, 255);
  };

  /**
   *  Yellow color (255, 255, 0, 255)
   * @returns {cc.Color}
   * @private
   */
  color._getYellow = () => {
    return cc.color(255, 255, 0, 255);
  };

  /**
   *  Blue color (0, 0, 255, 255)
   * @type {cc.Color}
   * @private
   */
  color._getBlue = () => {
    return cc.color(0, 0, 255, 255);
  };
  /**
   *  Green Color (0, 255, 0, 255)
   * @type {cc.Color}
   * @private
   */
  color._getGreen = () => {
    return cc.color(0, 255, 0, 255);
  };
  /**
   *  Red Color (255, 0, 0, 255)
   * @type {cc.Color}
   * @private
   */
  color._getRed = () => {
    return cc.color(255, 0, 0, 255);
  };
  /**
   *  Magenta Color (255, 0, 255, 255)
   * @type {cc.Color}
   * @private
   */
  color._getMagenta = () => {
    return cc.color(255, 0, 255, 255);
  };
  /**
   *  Black Color (0, 0, 0, 255)
   * @type {cc.Color}
   * @private
   */
  color._getBlack = () => {
    return cc.color(0, 0, 0, 255);
  };
  /**
   *  Orange Color (255, 127, 0, 255)
   * @type {cc.Color}
   * @private
   */
  color._getOrange = () => {
    return cc.color(255, 127, 0, 255);
  };
  /**
   *  Gray Color (166, 166, 166, 255)
   * @type {cc.Color}
   * @private
   */
  color._getGray = () => {
    return cc.color(166, 166, 166, 255);
  };
  // var _proto = cc.color;
  // /** @expose */
  // _proto.WHITE;
  // cc.defineGetterSetter(_proto, "WHITE", _proto._getWhite);

  color.WHITE = color._getWhite();
  // /** @expose */
  // _proto.YELLOW;
  // cc.defineGetterSetter(_proto, "YELLOW", _proto._getYellow);
  color.YELLOW = color._getYellow();
  // /** @expose */
  // _proto.BLUE;
  // cc.defineGetterSetter(_proto, "BLUE", _proto._getBlue);
  color.BLUE = color._getBlue();
  // /** @expose */
  // _proto.GREEN;
  // cc.defineGetterSetter(_proto, "GREEN", _proto._getGreen);
  color.GREEN = color._getGreen();
  // /** @expose */
  // _proto.RED;
  // cc.defineGetterSetter(_proto, "RED", _proto._getRed);
  color.RED = color._getRed();
  // /** @expose */
  // _proto.MAGENTA;
  // cc.defineGetterSetter(_proto, "MAGENTA", _proto._getMagenta);
  color.MAGENTA = color._getMagenta();
  // /** @expose */
  // _proto.BLACK;
  // cc.defineGetterSetter(_proto, "BLACK", _proto._getBlack);
  color.BLACK = color._getBlack();
  // /** @expose */
  // _proto.ORANGE;
  // cc.defineGetterSetter(_proto, "ORANGE", _proto._getOrange);
  color.ORANGE = color._getOrange();
  // /** @expose */
  // _proto.GRAY;
  // cc.defineGetterSetter(_proto, "GRAY", _proto._getGray);
  color.GRAY = color._getGray();
}
