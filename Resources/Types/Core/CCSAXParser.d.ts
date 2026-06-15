declare namespace cc {
  /**
   * A SAX Parser
   * @class
   * @name cc.saxParser
   * @extends cc.Class
   */
  class SAXParser extends cc.Class {
    _parser: null;
    _isSupportDOMParser: null;

    /**
     * Constructor of cc.SAXParser
     */

    /**
     * @function
     * @param {String} xmlTxt
     * @return {Document}
     */
  }
  /**
   *
   * cc.plistParser is a singleton object for parsing plist files
   * @class
   * @name cc.plistParser
   * @extends cc.SAXParser
   */
  class PlistParser extends cc.SAXParser {
    static getInstance(): cc.PlistParser;
    /**
     * parse a xml string as plist object.
     * @param {String} xmlTxt plist xml contents
     * @return {*} plist object
     */
    parse(xmlTxt: string): any;

    _parseNode(node: Node): any;
    _parseArray(node: Node): any[];
    _parseDict(node: Node): { [key: string]: any };
  }

  let saxParser: cc.SAXParser;
  /**
   * A Plist Parser
   * @type {cc.PlistParser}
   * @name plistParser
   * @memberof cc
   */
  let plistParser: cc.PlistParser;
}
