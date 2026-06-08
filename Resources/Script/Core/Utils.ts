namespace cc {
  export const log = (...args: any[]) => {
    console.log(...args);
  };
  /**
   * Iterate over an object or an array, executing a function for each matched element.
   * @param {object|array} obj
   * @param {function} iterator
   * @param {object} [context]
   */
  export function each<T extends number | string, V = any>(
    obj: Record<string, unknown> | any[],
    iterator: (value: V, key: T, context?: any) => boolean | undefined,
  ) {
    if (!obj) return;
    if (obj instanceof Array) {
      for (var i = 0, li = obj.length; i < li; i++) {
        if (iterator(obj[i], i as T) === false) return;
      }
    } else {
      for (var key in obj) {
        if (iterator(obj[key] as V, key as T) === false) return;
      }
    }
  }

  /**
   * A string tool to construct a string with format string.
   * for example:
   *      cc.formatStr("a: %d, b: %b", a, b);
   *      cc.formatStr(a, b, c);
   * @returns {String}
   */
  export const formatStr = (...args: any[]) => {
    const l = args.length;
    if (l < 1) return "";
    const REGEXP_NUM_OR_STR = /(%d)|(%s)/;

    let i = 1;
    let str = args[0];
    const hasSubstitution =
      typeof str === "string" && REGEXP_NUM_OR_STR.test(str);
    if (hasSubstitution) {
      const REGEXP_STR = /%s/;
      for (; i < l; ++i) {
        const arg = args[i];
        const regExpToTest =
          typeof arg === "number" ? REGEXP_NUM_OR_STR : REGEXP_STR;
        if (regExpToTest.test(str)) str = str.replace(regExpToTest, arg);
        else str += " " + arg;
      }
    } else {
      if (l > 1) {
        for (; i < l; ++i) {
          str += " " + args[i];
        }
      } else {
        str = "" + str;
      }
    }
    return str;
  };

  // Array utils

  /**
   * Verify Array's Type
   * @param {Array} arr
   * @param {function} type
   * @return {Boolean}
   * @function
   */
  export const arrayVerifyType = (arr: any[], type: Function): boolean => {
    if (arr && arr.length > 0) {
      for (var i = 0; i < arr.length; i++) {
        if (!(arr[i] instanceof type)) {
          cc.log("element type is wrong!");
          return false;
        }
      }
    }
    return true;
  };

  /**
   * Searches for the first occurrence of object and removes it. If object is not found the function has no effect.
   * @function
   * @param {Array} arr Source Array
   * @param {*} delObj  remove object
   */
  export const arrayRemoveObject = <T>(arr: T[], delObj: T) => {
    for (let i = 0, l = arr.length; i < l; i++) {
      if (arr[i] == delObj) {
        arr.splice(i, 1);
        break;
      }
    }
  };

  /**
   * Removes from arr all values in minusArr. For each Value in minusArr, the first matching instance in arr will be removed.
   * @function
   * @param {Array} arr Source Array
   * @param {Array} minusArr minus Array
   */
  export const arrayRemoveArray = <T>(arr: T[], minusArr: T[]) => {
    for (var i = 0, l = minusArr.length; i < l; i++) {
      cc.arrayRemoveObject(arr, minusArr[i]);
    }
  };

  /**
   * Inserts some objects at index
   * @function
   * @param {Array} arr
   * @param {Array} addObjs
   * @param {Number} index
   * @return {Array}
   */
  export const arrayAppendObjectsToIndex = <T>(
    arr: T[],
    addObjs: T[],
    index: number,
  ) => {
    arr.splice(index, 0, ...addObjs);
    return arr;
  };

  /**
   * Copy an array's item to a new array (its performance is better than Array.slice)
   * @param {Array} arr
   * @returns {Array}
   */
  export const copyArray = <T>(arr: T[]): T[] => {
    let i,
      len = arr.length,
      arr_clone = new Array(len);
    for (i = 0; i < len; i += 1) arr_clone[i] = arr[i];
    return arr_clone;
  };

    // Predefined font definition
  export class FontDefinition {
    fontName: string;
    fontSize: number;
    textAlign: number;
    verticalAlign: number;
    fillStyle: cc.Color;
    boundingWidth: number;
    boundingHeight: number;
    strokeEnabled: boolean;
    strokeStyle: cc.Color;
    lineWidth: number;
    shadowEnabled: boolean;
    shadowOffsetX: number;
    shadowOffsetY: number;
    shadowBlur: number;
    shadowOpacity: number;

    constructor() {
      this.fontName = "Arial";
      this.fontSize = 12;
      this.textAlign = cc.TEXT_ALIGNMENT_CENTER;
      this.verticalAlign = cc.VERTICAL_TEXT_ALIGNMENT_TOP;
      this.fillStyle = cc.color(255, 255, 255, 255);
      this.boundingWidth = 0;
      this.boundingHeight = 0;

      this.strokeEnabled = false;
      this.strokeStyle = cc.color(255, 255, 255, 255);
      this.lineWidth = 1;

      this.shadowEnabled = false;
      this.shadowOffsetX = 0;
      this.shadowOffsetY = 0;
      this.shadowBlur = 0;
      this.shadowOpacity = 1.0;
  };
}
