declare namespace cc {
  /**
   * Base class of all kinds of events.
   * @class
   * @extends cc.Class
   */
  class Event extends Class {
    constructor(type: number);
    /**
     * Gets the event type
     * @function
     * @returns {Number}
     */
    getType(): number;

    /**
     * Stops propagation for current event
     * @function
     */
    stopPropagation(): void;
    /**
     * Checks whether the event has been stopped
     * @function
     * @returns {boolean}
     */
    isStopped(): boolean;

    /**
     * <p>
     *     Gets current target of the event                                                            <br/>
     *     note: It only be available when the event listener is associated with node.                <br/>
     *          It returns 0 when the listener is associated with fixed priority.
     * </p>
     * @function
     * @returns {cc.Node}  The target with which the event associates.
     */
    getCurrentTarget(): cc.Node;

    //event type
    /**
     * The type code of Touch event.
     * @constant
     * @type {number}
     */
    static readonly TOUCH = 0;
    /**
     * The type code of Keyboard event.
     * @constant
     * @type {number}
     */
    static readonly KEYBOARD = 1;
    /**
     * The type code of Acceleration event.
     * @constant
     * @type {number}
     */
    static readonly ACCELERATION = 2;
    /**
     * The type code of Mouse event.
     * @constant
     * @type {number}
     */
    static readonly MOUSE = 3;
    /**
     * The type code of UI focus event.
     * @constant
     * @type {number}
     */
    static readonly FOCUS = 4;
    /**
     * The type code of Custom event.
     * @constant
     * @type {number}
     */
    static readonly CUSTOM = 6;
  }

  /**
   * The touch event class
   * @class
   * @extends cc.Class
   *
   * @param {Number} x
   * @param {Number} y
   * @param {Number} id
   */
  class Touch extends Class {
    constructor(x: number, y: number, id: number);
    /**
     * Returns the current touch location in OpenGL coordinates
     * @return {cc.Point}
     */
    getLocation(): cc.Point;

    /**
     * Returns X axis location value
     * @returns {number}
     */
    getLocationX(): number;

    /**
     * Returns Y axis location value
     * @returns {number}
     */
    getLocationY(): number;

    /**
     * Returns the previous touch location in OpenGL coordinates
     * @return {cc.Point}
     */
    getPreviousLocation(): cc.Point;

    /**
     * Returns the start touch location in OpenGL coordinates
     * @returns {cc.Point}
     */
    getStartLocation(): cc.Point;

    /**
     * Returns the delta distance from the previous touche to the current one in screen coordinates
     * @return {cc.Point}
     */
    getDelta(): cc.Point;

    /**
     * Returns the current touch location in screen coordinates
     * @return {cc.Point}
     */
    getLocationInView(): cc.Point;

    /**
     * Returns the previous touch location in screen coordinates
     * @return {cc.Point}
     */
    getPreviousLocationInView(): cc.Point;

    /**
     * Returns the start touch location in screen coordinates
     * @return {cc.Point}
     */
    getStartLocationInView(): cc.Point;

    /**
     * Returns the id of cc.Touch
     * @return {Number}
     */
    getID(): number;

    /**
     * Returns the id of cc.Touch
     * @return {Number}
     * @deprecated since v3.0, please use getID() instead
     */
    getId(): number;

    /**
     * Sets information to touch
     * @param {Number} id
     * @param  {Number} x
     * @param  {Number} y
     */
    setTouchInfo(id: number, x: number, y: number): void;
  }

  /**
   * The mouse event
   * @class
   * @extends cc.Event
   */
  class EventMouse extends Event {
    constructor(eventType: number);
    /**
     * Sets scroll data
     * @param {number} scrollX
     * @param {number} scrollY
     */
    setScrollData(scrollX: number, scrollY: number): void;
    /**
     * Returns the x axis scroll value
     * @returns {number}
     */
    getScrollX(): number;
    /**
     * Returns the y axis scroll value
     * @returns {number}
     */
    getScrollY(): number;
    /**
     * Sets cursor location
     * @param {number} x
     * @param {number} y
     */
    setLocation(x: number, y: number): void;
    /**
     * Returns cursor location
     * @return {cc.Point} location
     */
    getLocation(): cc.Point;
    /**
     * Returns the current cursor location in screen coordinates
     * @return {cc.Point}
     */
    getLocationInView(): cc.Point;

    /**
     * Returns the delta distance from the previous location to current location
     * @return {cc.Point}
     */
    getDelta(): cc.Point;
    /**
     * Returns the X axis delta distance from the previous location to current location
     * @return {Number}
     */
    getDeltaX(): number;
    /**
     * Returns the Y axis delta distance from the previous location to current location
     * @return {Number}
     */
    getDeltaY(): number;
    /**
     * Sets mouse button
     * @param {number} button
     */
    setButton(button: number): void;
    /**
     * Returns mouse button
     * @returns {number}
     */
    getButton(): number;
    /**
     * Returns location X axis data
     * @returns {number}
     */
    getLocationX(): number;
    /**
     * Returns location Y axis data
     * @returns {number}
     */
    getLocationY(): number;

    //Different types of MouseEvent
    /**
     * The none event code of  mouse event.
     * @constant
     * @type {number}
     */
    static readonly NONE = 0;
    /**
     * The event type code of mouse down event.
     * @constant
     * @type {number}
     */
    static readonly DOWN = 1;
    /**
     * The event type code of mouse up event.
     * @constant
     * @type {number}
     */
    static readonly UP = 2;
    /**
     * The event type code of mouse move event.
     * @constant
     * @type {number}
     */
    static readonly MOVE = 3;
    /**
     * The event type code of mouse scroll event.
     * @constant
     * @type {number}
     */
    static readonly SCROLL = 4;
    /**
     * The tag of Mouse left button
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_LEFT = 0;
    /**
     * The tag of Mouse right button  (The right button number is 2 on browser)
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_RIGHT = 2;
    /**
     * The tag of Mouse middle button  (The right button number is 1 on browser)
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_MIDDLE = 1;
    /**
     * The tag of Mouse button 4
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_4 = 3;
    /**
     * The tag of Mouse button 5
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_5 = 4;
    /**
     * The tag of Mouse button 6
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_6 = 5;
    /**
     * The tag of Mouse button 7
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_7 = 6;
    /**
     * The tag of Mouse button 8
     * @constant
     * @type {Number}
     */
    static readonly BUTTON_8 = 7;
  }

  /**
   * The Custom event
   * @class
   * @extends cc.Event
   */
  class EventCustom extends cc.Event {
    _eventName: string | null;
    _userData: any | null; // User data

    constructor(eventName: string | null);
    /**
     * Sets user data
     * @param {*} data
     */
    setUserData(data: Record<string, any> | null): void;

    /**
     * Gets user data
     * @returns {*}
     */
    getUserData(): Record<string, any> | null;
    /**
     * Gets event name
     * @returns {String}
     */
    getEventName(): string | null;
  }

  /**
   * The touch event
   * @class
   * @extends cc.Event
   */
  class EventTouch extends cc.Event {
    _eventCode: number;
    _touches: Touch[];

    constructor(arr: Touch[]);

    /**
     * Returns event code
     * @returns {number}
     */
    getEventCode(): number;

    /**
     * Returns touches of event
     * @returns {Array}
     */
    getTouches(): Touch[];

    /**
     * The maximum touch numbers
     * @constant
     * @type {Number}
     */
    static readonly MAX_TOUCHES = 5;

    static readonly EventCode: { BEGAN: 0; MOVED: 1; ENDED: 2; CANCELLED: 3 };
  }

  /**
   * Focus change event for UI widget
   * @class
   * @extends cc.Event
   */
  class EventFocus extends cc.Event {
    _widgetGetFocus: ccui.Widget | null;
    _widgetLoseFocus: ccui.Widget | null;
    /**
     * Constructor function.
     * @param {ccui.Widget} widgetLoseFocus
     * @param {ccui.Widget} widgetGetFocus
     */
    constructor(
      widgetLoseFocus: ccui.Widget | null,
      widgetGetFocus: ccui.Widget | null,
    );
  }
}
