declare namespace cc {
  class DrawNode extends Node {
    constructor();
    // cc.DrawNode = cc.Node.extend(/** @lends cc.DrawNode# */{
    //   //TODO need refactor

    //       _buffer: null,
    //       _blendFunc: null,
    //       _lineWidth: 1,
    //       _drawColor: null,

    //       /**
    //        * Gets the blend func
    //        * @returns {Object}
    //        */
    //       getBlendFunc: function () {
    //           return this._blendFunc;
    //       },

    //       /**
    //        * Set the blend func
    //        * @param blendFunc
    //        * @param dst
    //        */
    //       setBlendFunc: function (blendFunc, dst) {
    //           if (dst === undefined) {
    //               this._blendFunc.src = blendFunc.src;
    //               this._blendFunc.dst = blendFunc.dst;
    //           } else {
    //               this._blendFunc.src = blendFunc;
    //               this._blendFunc.dst = dst;
    //           }
    //       },

    /**
     * line width setter
     * @param {Number} width
     */
    setLineWidth(w: number): void;

    //       /**
    //        * line width getter
    //        * @returns {Number}
    //        */
    //       getLineWidth: function () {
    //           return this._lineWidth;
    //       },

    //       /**
    //        * draw color setter
    //        * @param {cc.Color} color
    //        */
    //       setDrawColor: function (color) {
    //           var locDrawColor = this._drawColor;
    //           locDrawColor.r = color.r;
    //           locDrawColor.g = color.g;
    //           locDrawColor.b = color.b;
    //           locDrawColor.a = (color.a == null) ? 255 : color.a;
    //       },

    //       /**
    //        * draw color getter
    //        * @returns {cc.Color}
    //        */
    //       getDrawColor: function () {
    //           return cc.color(this._drawColor.r, this._drawColor.g, this._drawColor.b, this._drawColor.a);
    //       }
    //   });
    public drawRect(origin: Point, destination: Point, color: Color): void;
    /**
     * name
     */
    public drawPoly(
      vertices: Point[],
      fillColor?: Color,
      lineWidth?: number,
      lineColor?: Color
    ): void;
    /**
     * draw a segment with a radius and color
     * @param {cc.Point} from
     * @param {cc.Point} to
     * @param {Number} [lineWidth]
     * @param {cc.Color} [color]
     */
    drawSegment(
      from: cc.Point,
      to: cc.Point,
      lineWidth?: number,
      color?: cc.Color
    ): void;

    /**
     * draws a circle given the center, radius and number of segments.
     * @override
     * @param {cc.Point} center center of circle
     * @param {Number} radius
     * @param {Number} angle angle in radians
     * @param {Number} segments
     * @param {Boolean} drawLineToCenter
     * @param {Number} lineWidth
     * @param {cc.Color} color
     */
    drawCircle(
      center: cc.Point,
      radius: number,
      angle?: number,
      segments?: number,
      drawLineToCenter?: boolean,
      lineWidth?: number,
      color?: cc.Color
    ): void;

    clear(): void;
  }
}
