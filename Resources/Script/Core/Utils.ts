namespace cc {
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
}
