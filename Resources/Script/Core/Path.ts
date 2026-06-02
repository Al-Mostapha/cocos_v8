namespace cc {
  //+++++++++++++++++++++++++something about path begin++++++++++++++++++++++++++++++++
  /**
   * @class
   */
  export class path {
    static normalizeRE = /[^\.\/]+\/\.\.\//;

    /**
     * Join strings to be a path.
     * @example
     cc.path.join("a", "b.png");//-->"a/b.png"
     cc.path.join("a", "b", "c.png");//-->"a/b/c.png"
     cc.path.join("a", "b");//-->"a/b"
     cc.path.join("a", "b", "/");//-->"a/b/"
     cc.path.join("a", "b/", "/");//-->"a/b/"
     * @returns {string}
     */
    static join(...args: string[]) {
      const l = args.length;
      let result = "";
      for (let i = 0; i < l; i++) {
        result = (result + (result === "" ? "" : "/") + args[i]).replace(
          /(\/|\\\\)$/,
          "",
        );
      }
      return result;
    }

    /**
     * Get the ext name of a path.
     * @example
     cc.path.extname("a/b.png");//-->".png"
     cc.path.extname("a/b.png?a=1&b=2");//-->".png"
     cc.path.extname("a/b");//-->null
     cc.path.extname("a/b?a=1&b=2");//-->null
     * @param {string} pathStr
     * @returns {*}
     */
    static extname(pathStr: string) {
      const temp = /(\.[^\.\/\?\\]*)(\?.*)?$/.exec(pathStr);
      return temp ? temp[1] : null;
    }

    /**
     * Get the main name of a file name
     * @param {string} fileName
     * @returns {string}
     */
    static mainFileName(fileName: string) {
      if (fileName) {
        const idx = fileName.lastIndexOf(".");
        if (idx !== -1) return fileName.substring(0, idx);
      }
      return fileName;
    }

    /**
     * Get the file name of a file path.
     * @example
     cc.path.basename("a/b.png");//-->"b.png"
     cc.path.basename("a/b.png?a=1&b=2");//-->"b.png"
     cc.path.basename("a/b.png", ".png");//-->"b"
     cc.path.basename("a/b.png?a=1&b=2", ".png");//-->"b"
     cc.path.basename("a/b.png", ".txt");//-->"b.png"
     * @param {string} pathStr
     * @param {string} [extname]
     * @returns {*}
     */
    static basename(pathStr: string, extname?: string) {
      const index = pathStr.indexOf("?");
      if (index > 0) pathStr = pathStr.substring(0, index);
      const reg = /(\/|\\\\)([^(\/|\\\\)]+)$/g;
      const result = reg.exec(pathStr.replace(/(\/|\\\\)$/, ""));
      if (!result) return null;

      let baseName = result[2];
      if (
        extname &&
        pathStr.substring(pathStr.length - extname.length).toLowerCase() ===
          extname.toLowerCase()
      )
        return baseName.substring(0, baseName.length - extname.length);
      return baseName;
    }

    /**
     * Get dirname of a file path.
     * @example
     * unix
     cc.path.driname("a/b/c.png");//-->"a/b"
     cc.path.driname("a/b/c.png?a=1&b=2");//-->"a/b"
     cc.path.dirname("a/b/");//-->"a/b"
     cc.path.dirname("c.png");//-->""
     * windows
     cc.path.driname("a\\b\\c.png");//-->"a\b"
     cc.path.driname("a\\b\\c.png?a=1&b=2");//-->"a\b"
     * @param {string} pathStr
     * @returns {*}
     */
    static dirname(pathStr: string) {
      return pathStr.replace(/((.*)(\/|\\|\\\\))?(.*?\..*$)?/, "$2");
    }

    /**
     * Change extname of a file path.
     * @example
     cc.path.changeExtname("a/b.png", ".plist");//-->"a/b.plist"
     cc.path.changeExtname("a/b.png?a=1&b=2", ".plist");//-->"a/b.plist?a=1&b=2"
     * @param {string} pathStr
     * @param {string} [extname]
     * @returns {string}
     */
    static changeExtname(pathStr: string, extname: string) {
      extname = extname || "";
      let index = pathStr.indexOf("?");
      let tempStr = "";
      if (index > 0) {
        tempStr = pathStr.substring(index);
        pathStr = pathStr.substring(0, index);
      }
      index = pathStr.lastIndexOf(".");
      if (index < 0) return pathStr + extname + tempStr;
      return pathStr.substring(0, index) + extname + tempStr;
    }

    /**
     * Change file name of a file path.
     * @example
     cc.path.changeBasename("a/b/c.plist", "b.plist");//-->"a/b/b.plist"
     cc.path.changeBasename("a/b/c.plist?a=1&b=2", "b.plist");//-->"a/b/b.plist?a=1&b=2"
     cc.path.changeBasename("a/b/c.plist", ".png");//-->"a/b/c.png"
     cc.path.changeBasename("a/b/c.plist", "b");//-->"a/b/b"
     cc.path.changeBasename("a/b/c.plist", "b", true);//-->"a/b/b.plist"
     * @param {String} pathStr
     * @param {String} basename
     * @param {Boolean} [isSameExt]
     * @returns {string}
     */
    static changeBasename(
      pathStr: string,
      basename: string,
      isSameExt?: boolean,
    ) {
      if (basename.indexOf(".") === 0)
        return this.changeExtname(pathStr, basename);
      var index = pathStr.indexOf("?");
      var tempStr = "";
      var ext = isSameExt ? this.extname(pathStr) : "";
      if (index > 0) {
        tempStr = pathStr.substring(index);
        pathStr = pathStr.substring(0, index);
      }
      index = pathStr.lastIndexOf("/");
      index = index <= 0 ? 0 : index + 1;
      return pathStr.substring(0, index) + basename + ext + tempStr;
    }

    //todo make public after verification
    static _normalize(url: string) {
      let oldUrl = (url = String(url));

      //removing all ../
      do {
        oldUrl = url;
        url = url.replace(this.normalizeRE, "");
      } while (oldUrl.length !== url.length);
      return url;
    }
  }
}
