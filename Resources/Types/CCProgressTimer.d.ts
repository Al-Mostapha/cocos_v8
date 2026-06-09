declare module cc {
  class ProgressTimer extends Node{

    /**
     * cc.Progresstimer is a subclass of cc.Node.   <br/>
     * It renders the inner sprite according to the percentage.<br/>
     * The progress can be Radial, Horizontal or vertical.
     * @class
     * @extends cc.Node
     *
     * @property {cc.Point}     midPoint        <p>- Midpoint is used to modify the progress start position.<br/>
     *                                          If you're using radials type then the midpoint changes the center point<br/>
     *                                          If you're using bar type the the midpoint changes the bar growth<br/>
     *                                              it expands from the center but clamps to the sprites edge so:<br/>
     *                                              you want a left to right then set the midpoint all the way to cc.p(0,y)<br/>
     *                                              you want a right to left then set the midpoint all the way to cc.p(1,y)<br/>
     *                                              you want a bottom to top then set the midpoint all the way to cc.p(x,0)<br/>
     *                                              you want a top to bottom then set the midpoint all the way to cc.p(x,1)</p>
     * @property {cc.Point}     barChangeRate   - This allows the bar type to move the component at a specific rate.
     * @property {enum}         type            - Type of the progress timer: cc.ProgressTimer.TYPE_RADIAL|cc.ProgressTimer.TYPE_BAR.
     * @property {Number}       percentage      - Percentage to change progress, from 0 to 100.
     * @property {cc.Sprite}    sprite          - The sprite to show the progress percentage.
     * @property {Boolean}      reverseDir      - Indicate whether the direction is reversed.
     *
     */

      /**
       * constructor of cc.cc.ProgressTimer
       * @function
       * @param {cc.Sprite} sprite
       */
      constructor(sprite: cc.Sprite); 

      /**
       *    Midpoint is used to modify the progress start position.
       *    If you're using radials type then the midpoint changes the center point
       *    If you're using bar type the the midpoint changes the bar growth
       *        it expands from the center but clamps to the sprites edge so:
       *        you want a left to right then set the midpoint all the way to cc.p(0,y)
       *        you want a right to left then set the midpoint all the way to cc.p(1,y)
       *        you want a bottom to top then set the midpoint all the way to cc.p(x,0)
       *        you want a top to bottom then set the midpoint all the way to cc.p(x,1)
       *  @return {cc.Point}
       */
      getMidpoint(): cc.Point;

      /**
       * Midpoint setter
       * @param {cc.Point} mpoint
       */
      setMidpoint(mpoint: cc.Point): void;

      /**
       *    This allows the bar type to move the component at a specific rate
       *    Set the component to 0 to make sure it stays at 100%.
       *    For example you want a left to right bar but not have the height stay 100%
       *    Set the rate to be cc.p(0,1); and set the midpoint to = cc.p(0,.5f);
       *  @return {cc.Point}
       */
      getBarChangeRate() : cc.Point;

      /**
       * @param {cc.Point} barChangeRate
       */
      setBarChangeRate(barChangeRate: cc.Point): void;

      /**
       *  Change the percentage to change progress
       * @return {cc.ProgressTimer.TYPE_RADIAL|cc.ProgressTimer.TYPE_BAR}
       */
      getType() : number;

      /**
       * Percentages are from 0 to 100
       * @return {Number}
       */
      getPercentage(): number;

      /**
       * The image to show the progress percentage, retain
       * @return {cc.Sprite}
       */
      getSprite(): cc.Sprite;

      /**
       * from 0-100
       * @param {Number} percentage
       */
      setPercentage(percentage: number): void;

      /**
       * only use for jsbinding
       * @param bValue
       */
      setOpacityModifyRGB(bValue: boolean): void;

      /**
       * only use for jsbinding
       * @returns {boolean}
       */
      isOpacityModifyRGB(): boolean;

      /**
       * return if reverse direction
       * @returns {boolean}
       */
      isReverseDirection() : boolean;

      /**
       * set color of sprite
       * @param {cc.Color} color
       */
      setColor(color: cc.Color): void;

      /**
       *  set opacity of sprite
       * @param {Number} opacity
       */
      setOpacity(opacity: number):void;

      /**
       * return color of sprite
       * @return {cc.Color}
       */
      getColor() : cc.Color;

      /**
       * return Opacity of sprite
       * @return {Number}
       */
      getOpacity(): number;

      /**
       * set reverse cc.ProgressTimer
       * @function
       * @param {Boolean} reverse
       */
      setReverseProgress(reverse: boolean): void;

      /**
       * set sprite for cc.ProgressTimer
       * @function
       * @param {cc.Sprite} sprite
       */
      setSprite(sprite: cc.Sprite): void

      /**
       * set Progress type of cc.ProgressTimer
       * @function
       * @param {cc.ProgressTimer.TYPE_RADIAL|cc.ProgressTimer.TYPE_BAR} type
       */
      setType(type: number): void

      /**
       * Reverse Progress setter
       * @function
       * @param {Boolean} reverse
       */
      setReverseDirection(reverse:  boolean): void;


    /** @expose */
    get midPoint(): cc.Point;
    set midPoint(value: cc.Point);
    /** @expose */
    get barChangeRate(): cc.Point;
    set barChangeRate(value: cc.Point);
    /** @expose */
    get type(): number;
    set type(value: number);
    /** @expose */
    get percentage(): number;
    set percentage(value: number);
    /** @expose */
    get sprite(): cc.Sprite;
    set sprite(value: cc.Sprite);
    /** @expose */
    get reverseDir(): boolean;
    set reverseDir(value: boolean);

    /**
    * @constant
    * @type Number
    */
    static readonly TEXTURE_COORDS_COUNT = 4;

    /**
    * @constant
    * @type Number
    */
    static readonly TEXTURE_COORDS = 0x4b;

    /**
    * Radial Counter-Clockwise
    * @type Number
    * @constant
    */
    static readonly TYPE_RADIAL = 0;

    /**
    * Bar
    * @type Number
    * @constant
    */
    static readonly TYPE_BAR = 1;

  }
}