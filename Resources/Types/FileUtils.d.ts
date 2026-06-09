declare module cc {
  class FileUtils {
    /**
     * @method fullPathForFilename
     * @param {String} arg0
     * @return {String}
     */
    fullPathForFilename(str: string): string;

    /**
     * @method getStringFromFile
     * @param {String|String} str
     * @param {function} func
     * @return {String}
     */
    getStringFromFile(str: string, func?: Function): string;

    /**
     * @method removeFile
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    removeFile(str: string, func?: Function): boolean;

    /**
     * @method isAbsolutePath
     * @param {String} arg0
     * @return {bool}
     */
    isAbsolutePath(str: string): boolean;

    /**
     * @method renameFile
     * @param {String|String|String|String} str
     * @param {String|String|String|String} str
     * @param {String|String|function} str
     * @param {function} func
     * @return {bool|bool}
     */
    renameFile(
      str: string,
      str2: string,
      str3?: string | Function,
      func?: Function
    ): boolean;

    /**
     * @method getDefaultResourceRootPath
     * @return {String}
     */
    getDefaultResourceRootPath(): string;

    /**
     * @method loadFilenameLookupDictionaryFromFile
     * @param {String} arg0
     */
    loadFilenameLookupDictionaryFromFile(str: string): void;

    /**
     * @method isPopupNotify
     * @return {bool}
     */
    isPopupNotify(): boolean;

    /**
     * @method getValueVectorFromFile
     * @param {String} arg0
     * @return {Array}
     */
    getValueVectorFromFile(str: string): Array<any>;

    /**
     * @method getSearchPaths
     * @return {Array}
     */
    getSearchPaths(): string[];

    /**
     * @method writeToFile
     * @param {map_object} arg0
     * @param {String} arg1
     * @return {bool}
     */
    writeToFile(map: Record<string, any>, str: string): boolean;

    /**
     * @method getOriginalSearchPaths
     * @return {Array}
     */
    getOriginalSearchPaths(): string[];

    /**
     * @method getNewFilename
     * @param {String} arg0
     * @return {String}
     */
    getNewFilename(str: string): string;

    /**
     * @method listFiles
     * @param {String} arg0
     * @return {Array}
     */
    listFiles(str: string): string[];

    /**
     * @method getValueMapFromFile
     * @param {String} arg0
     * @return {map_object}
     */
    getValueMapFromFile(str: string): Record<string, any>;

    /**
     * @method getFileSize
     * @param {String|String} str
     * @param {function} func
     * @return {long}
     */
    getFileSize(str: string, func?: Function): boolean;

    /**
     * @method getValueMapFromData
     * @param {char} arg0
     * @param {int} arg1
     * @return {map_object}
     */
    getValueMapFromData(char: string, int: number): Record<string, any>;

    /**
     * @method removeDirectory
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    removeDirectory(str: string, func?: Function): boolean;

    /**
     * @method setSearchPaths
     * @param {Array} arg0
     */
    setSearchPaths(array: string[]): void;

    /**
     * @method writeStringToFile
     * @param {String|String} str
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    writeStringToFile(dataStr: string, path: string, func?: Function): boolean;

    /**
     * @method setSearchResolutionsOrder
     * @param {Array} arg0
     */
    setSearchResolutionsOrder(array: string[]): void;

    /**
     * @method addSearchResolutionsOrder
     * @param {String} arg0
     * @param {bool} arg1
     */
    addSearchResolutionsOrder(str: string, bool: boolean): void;

    /**
     * @method addSearchPath
     * @param {String} arg0
     * @param {bool} arg1
     */
    addSearchPath(str: string, bool?: boolean): void;

    /**
     * @method writeValueVectorToFile
     * @param {Array|Array} array
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    writeValueVectorToFile(array: any[], str: string, func?: Function): boolean;

    /**
     * @method isFileExist
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    isFileExist(str: string, func?: Function): boolean;

    /**
     * @method purgeCachedEntries
     */
    purgeCachedEntries(): void;

    /**
     * @method fullPathFromRelativeFile
     * @param {String} arg0
     * @param {String} arg1
     * @return {String}
     */
    fullPathFromRelativeFile(str: string, str1: string): string;

    /**
     * @method getSuitableFOpen
     * @param {String} arg0
     * @return {String}
     */
    getSuitableFOpen(str: string): string;

    /**
     * @method writeValueMapToFile
     * @param {map_object|map_object} map
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    writeValueMapToFile(
      map: Record<string, any>,
      str: string,
      func?: Function
    ): boolean;

    /**
     * @method getFileExtension
     * @param {String} arg0
     * @return {String}
     */
    getFileExtension(str: string): string;

    /**
     * @method setWritablePath
     * @param {String} arg0
     */
    setWritablePath(str: string): void;

    /**
     * @method setPopupNotify
     * @param {bool} arg0
     */
    setPopupNotify(bool: boolean): void;

    /**
     * @method isDirectoryExist
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    isDirectoryExist(str: string, func?: Function): boolean;

    /**
     * @method setDefaultResourceRootPath
     * @param {String} arg0
     */
    setDefaultResourceRootPath(str: string): void;

    /**
     * @method getSearchResolutionsOrder
     * @return {Array}
     */
    getSearchResolutionsOrder(): Array<string>;

    /**
     * @method createDirectory
     * @param {String|String} str
     * @param {function} func
     * @return {bool}
     */
    createDirectory(str: string, func?: Function): void;

    /**
     * @method getWritablePath
     * @return {String}
     */
    getWritablePath(): string;

    /**
     * @method listFilesRecursively
     * @param {String} arg0
     * @param {Array} arg1
     */
  listFilesRecursively(str: string): string[];
  }

  const fileUtils: FileUtils;
}

declare module jsb {
  const fileUtils: cc.FileUtils;
}
