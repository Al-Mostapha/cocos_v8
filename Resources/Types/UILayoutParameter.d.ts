declare module ccui {
  /**
   * Base class for ccui.Margin
   * @class
   * @extends ccui.Class
   *
   * @property {Number}           left       - Left of margin
   * @property {Number}           top        - Top of margin
   * @property {Number}           right      - right of margin
   * @property {Number}           bottom     - bottom of margin
   */
  class Margin extends cc.Class {
    left: number;
    top: number;
    right: number;
    bottom: number;

    /**
     * Constructor of ccui.Margin.
     * @param {Number|ccui.Margin} margin a margin or left
     * @param {Number} [top]
     * @param {Number} [right]
     * @param {Number} [bottom]
     */
    constructor(
      margin?: ccui.Margin | number,
      top?: number,
      right?: number,
      bottom?: number
    );
    /**
     * Sets boundary of margin
     * @param {Number} l left
     * @param {Number} t top
     * @param {Number} r right
     * @param {Number} b bottom
     */
    setMargin(l: number, t: number, r: number, b: number): void;
    //   /**
    //    * Checks target whether equals itself.
    //    * @param {ccui.Margin} target
    //    * @returns {boolean}
    //    */
    //   equals: function (target) {
    //       return (this.left === target.left && this.top === target.top && this.right === target.right && this.bottom === target.bottom);
    //   }
  }

  /**
  * Gets a zero margin object
  * @function
  * @returns {ccui.Margin}
  */
  function MarginZero(): ccui.Margin;

  /**
   * Layout parameter contains a margin and layout parameter type. It uses for ccui.LayoutManager.
   * @class
   * @extends ccui.Class
   */

  class LayoutParameter extends cc.Class {
    /**
     * The constructor of ccui.LayoutParameter.
     * @function
     */
    constructor();

    /**
     * Sets Margin to LayoutParameter.
     * @param {ccui.Margin} margin
     */
    setMargin(margin: ccui.Margin): void;

    /**
     * Gets Margin of LayoutParameter.
     * @returns {ccui.Margin}
     */
    getMargin(): ccui.Margin;

    /**
     * Gets LayoutParameterType of LayoutParameter.
     * @returns {Number}
     */
    getLayoutType(): number;

    /**
     * Clones a ccui.LayoutParameter object from itself.
     * @returns {ccui.LayoutParameter}
     */
    clone(): ccui.LayoutParameter;
  }
  // /**
  // * allocates and initializes a LayoutParameter.
  // * @constructs
  // * @return {ccui.LayoutParameter}
  // */
  // ccui.LayoutParameter.create = function () {
  //   return new ccui.LayoutParameter();
  // };

  // // Constants
  // //layout parameter type
  // /**
  // * The none of ccui.LayoutParameter's type.
  // * @constant
  // * @type {number}
  // */
  // ccui.LayoutParameter.NONE = 0;
  // /**
  // * The linear of ccui.LayoutParameter's type.
  // * @constant
  // * @type {number}
  // */
  // ccui.LayoutParameter.LINEAR = 1;
  // /**
  // * The relative of ccui.LayoutParameter's type.
  // * @constant
  // * @type {number}
  // */
  // ccui.LayoutParameter.RELATIVE = 2;

  /**
   * The linear of Layout parameter. its parameter type is ccui.LayoutParameter.LINEAR.
   * @class
   * @extends ccui.LayoutParameter
   */
  class LinearLayoutParameter extends ccui.LayoutParameter {
    _linearGravity: number;
    /**
     * The constructor of ccui.LinearLayoutParameter.
     * @function
     */
    constructor();

    /**
     * Sets LinearGravity to LayoutParameter.
     * @param {Number} gravity
     */
    setGravity(gravity: number): void;

    /**
     * Gets LinearGravity of LayoutParameter.
     * @returns {Number}
     */
    getGravity(): number;
    // /**
    // * allocates and initializes a LinearLayoutParameter.
    // * @constructs
    // * @return {ccui.LinearLayoutParameter}
    // * @deprecated since v3.0, please use new construction instead
    // */
    // ccui.LinearLayoutParameter.create = function () {
    //   return new ccui.LinearLayoutParameter();
    // };

    // Constants
    //Linear layout parameter LinearGravity
    /**
    * The none of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly NONE = 0;

    /**
    * The left of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly LEFT = 1;
    /**
    * The top of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly TOP = 2;
    /**
    * The right of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly RIGHT = 3;
    /**
    * The bottom of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly BOTTOM = 4;
    /**
    * The center vertical of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly CENTER_VERTICAL = 5;
    /**
    * The center horizontal of ccui.LinearLayoutParameter's linear gravity.
    * @constant
    * @type {number}
    */
    static readonly CENTER_HORIZONTAL = 6;
  }

  // /**
  // * The relative of layout parameter. Its layout parameter type is ccui.LayoutParameter.RELATIVE.
  // * @class
  // * @extends ccui.LayoutParameter
  // */
  // ccui.RelativeLayoutParameter = ccui.LayoutParameter.extend(/** @lends ccui.RelativeLayoutParameter# */{
  //   _relativeAlign: null,
  //   _relativeWidgetName: "",
  //   _relativeLayoutName: "",
  //   _put:false,
  //   /**
  //    * The constructor of ccui.RelativeLayoutParameter
  //    * @function
  //    */
  //   ctor: function () {
  //       ccui.LayoutParameter.prototype.ctor.call(this);
  //       this._relativeAlign = ccui.RelativeLayoutParameter.NONE;
  //       this._relativeWidgetName = "";
  //       this._relativeLayoutName = "";
  //       this._put = false;
  //       this._layoutParameterType = ccui.LayoutParameter.RELATIVE;
  //   },

  //   /**
  //    * Sets RelativeAlign parameter for LayoutParameter.
  //    * @param {Number} align
  //    */
  //   setAlign: function (align) {
  //       this._relativeAlign = align;
  //   },

  //   /**
  //    * Gets RelativeAlign parameter for LayoutParameter.
  //    * @returns {Number}
  //    */
  //   getAlign: function () {
  //       return this._relativeAlign;
  //   },

  //   /**
  //    * Sets a key for LayoutParameter. Witch widget named this is relative to.
  //    * @param {String} name
  //    */
  //   setRelativeToWidgetName: function (name) {
  //       this._relativeWidgetName = name;
  //   },

  //   /**
  //    * Gets the key of LayoutParameter. Witch widget named this is relative to.
  //    * @returns {string}
  //    */
  //   getRelativeToWidgetName: function () {
  //       return this._relativeWidgetName;
  //   },

  //   /**
  //    * Sets a name in Relative Layout for LayoutParameter.
  //    * @param {String} name
  //    */
  //   setRelativeName: function (name) {
  //       this._relativeLayoutName = name;
  //   },

  //   /**
  //    * Gets a name in Relative Layout of LayoutParameter.
  //    * @returns {string}
  //    */
  //   getRelativeName: function () {
  //       return this._relativeLayoutName;
  //   },

  //   _createCloneInstance:function(){
  //       return new ccui.RelativeLayoutParameter();
  //   },

  //   _copyProperties:function(model){
  //       ccui.LayoutParameter.prototype._copyProperties.call(this, model);
  //       if (model instanceof ccui.RelativeLayoutParameter) {
  //           this.setAlign(model._relativeAlign);
  //           this.setRelativeToWidgetName(model._relativeWidgetName);
  //           this.setRelativeName(model._relativeLayoutName);
  //       }
  //   }
  // });

  // /**
  // * Allocates and initializes a RelativeLayoutParameter.
  // * @function
  // * @deprecated since v3.0, please use new ccui.RelativeLayoutParameter() instead.
  // * @return {ccui.RelativeLayoutParameter}
  // */
  // ccui.RelativeLayoutParameter.create = function () {
  //   return new ccui.RelativeLayoutParameter();
  // };

  // // Constants
  // //Relative layout parameter RelativeAlign
  // /**
  // * The none of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.NONE = 0;
  // /**
  // * The parent's top left of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_TOP_LEFT = 1;
  // /**
  // * The parent's top center horizontal of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_TOP_CENTER_HORIZONTAL = 2;
  // /**
  // * The parent's top right of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_TOP_RIGHT = 3;
  // /**
  // * The parent's left center vertical of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_LEFT_CENTER_VERTICAL = 4;

  // /**
  // * The center in parent of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.CENTER_IN_PARENT = 5;

  // /**
  // * The parent's right center vertical of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_RIGHT_CENTER_VERTICAL = 6;
  // /**
  // * The parent's left bottom of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_LEFT_BOTTOM = 7;
  // /**
  // * The parent's bottom center horizontal of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_BOTTOM_CENTER_HORIZONTAL = 8;
  // /**
  // * The parent's right bottom of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.PARENT_RIGHT_BOTTOM = 9;

  // /**
  // * The location above left align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_ABOVE_LEFTALIGN = 10;
  // /**
  // * The location above center of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_ABOVE_CENTER = 11;
  // /**
  // * The location above right align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_ABOVE_RIGHTALIGN = 12;
  // /**
  // * The location left of top align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_LEFT_OF_TOPALIGN = 13;
  // /**
  // * The location left of center of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_LEFT_OF_CENTER = 14;
  // /**
  // * The location left of bottom align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_LEFT_OF_BOTTOMALIGN = 15;
  // /**
  // * The location right of top align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_RIGHT_OF_TOPALIGN = 16;
  // /**
  // * The location right of center of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_RIGHT_OF_CENTER = 17;
  // /**
  // * The location right of bottom align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_RIGHT_OF_BOTTOMALIGN = 18;
  // /**
  // * The location below left align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_BELOW_LEFTALIGN = 19;
  // /**
  // * The location below center of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_BELOW_CENTER = 20;
  // /**
  // * The location below right align of ccui.RelativeLayoutParameter's relative align.
  // * @constant
  // * @type {number}
  // */
  // ccui.RelativeLayoutParameter.LOCATION_BELOW_RIGHTALIGN = 21;

  /**
  * @ignore
  */
  const LINEAR_GRAVITY_NONE = 0;
  const LINEAR_GRAVITY_LEFT = 1;
  const LINEAR_GRAVITY_TOP = 2;
  const LINEAR_GRAVITY_RIGHT = 3;
  const LINEAR_GRAVITY_BOTTOM = 4;
  const LINEAR_GRAVITY_CENTER_VERTICAL = 5;
  const LINEAR_GRAVITY_CENTER_HORIZONTAL = 6;

  //RelativeAlign
  const RELATIVE_ALIGN_NONE = 0;
  const RELATIVE_ALIGN_PARENT_TOP_LEFT = 1;
  const RELATIVE_ALIGN_PARENT_TOP_CENTER_HORIZONTAL = 2;
  const RELATIVE_ALIGN_PARENT_TOP_RIGHT = 3;
  const RELATIVE_ALIGN_PARENT_LEFT_CENTER_VERTICAL = 4;
  const RELATIVE_ALIGN_PARENT_CENTER = 5;
  const RELATIVE_ALIGN_PARENT_RIGHT_CENTER_VERTICAL = 6;
  const RELATIVE_ALIGN_PARENT_LEFT_BOTTOM = 7;
  const RELATIVE_ALIGN_PARENT_BOTTOM_CENTER_HORIZONTAL = 8;
  const RELATIVE_ALIGN_PARENT_RIGHT_BOTTOM = 9;

  const RELATIVE_ALIGN_LOCATION_ABOVE_LEFT = 10;
  const RELATIVE_ALIGN_LOCATION_ABOVE_CENTER = 11;
  const RELATIVE_ALIGN_LOCATION_ABOVE_RIGHT = 12;

  const RELATIVE_ALIGN_LOCATION_LEFT_TOP = 13;
  const RELATIVE_ALIGN_LOCATION_LEFT_CENTER = 14;
  const RELATIVE_ALIGN_LOCATION_LEFT_BOTTOM = 15;

  const RELATIVE_ALIGN_LOCATION_RIGHT_TOP = 16;
  const RELATIVE_ALIGN_LOCATION_RIGHT_CENTER = 17;
  const RELATIVE_ALIGN_LOCATION_RIGHT_BOTTOM = 18;

  const RELATIVE_ALIGN_LOCATION_BELOW_TOP = 19;
  const RELATIVE_ALIGN_LOCATION_BELOW_CENTER = 20;
  const RELATIVE_ALIGN_LOCATION_BELOW_BOTTOM = 21;
}
