declare module cc {
  /**
   * Default Node tag
   * @constant
   * @type Number
   */
  const NODE_TAG_INVALID = -1;

  /**
   * XXX: Yes, nodes might have a sort problem once every 15 days if the game runs at 60 FPS and each frame sprites are reordered.
   */
  const s_globalOrderOfArrival = 1;

  /**
   * <p>cc.Node is the root class of all node. Anything that gets drawn or contains things that get drawn is a cc.Node.<br/>
   * The most popular cc.Nodes are: cc.Scene, cc.Layer, cc.Sprite, cc.Menu.</p>
   *
   * <p>The main features of a cc.Node are: <br/>
   * - They can contain other cc.Node nodes (addChild, getChildByTag, removeChild, etc) <br/>
   * - They can schedule periodic callback (schedule, unschedule, etc) <br/>
   * - They can execute actions (runAction, stopAction, etc) <br/></p>
   *
   * <p>Some cc.Node nodes provide extra functionality for them or their children.</p>
   *
   * <p>Subclassing a cc.Node usually means (one/all) of: <br/>
   * - overriding constructor function "ctor" to initialize resources and schedule callbacks<br/>
   * - create callbacks to handle the advancement of time<br/></p>
   *
   * <p>Features of cc.Node: <br/>
   * - position  <br/>
   * - scale (x, y) <br/>
   * - rotation (in degrees, clockwise)<br/>
   * - anchor point<br/>
   * - size <br/>
   * - color <br/>
   * - opacity <br/>
   * - visible<br/>
   * - z-order<br/>
   * - WebGL z position<br/></P>
   *
   * <p> Default values: <br/>
   * - rotation: 0 <br/>
   * - position: (x=0,y=0) <br/>
   * - scale: (x=1,y=1) <br/>
   * - contentSize: (x=0,y=0)<br/>
   * - anchorPoint: (x=0,y=0)<br/>
   * - color: (r=255,g=255,b=255)<br/>
   * - opacity: 255</p>
   *
   * <p> Limitations:<br/>
   * - A cc.Node is a "void" object. It doesn't have a texture <br/></P>
   *
   * <p>Order in transformations with grid disabled <br/>
   * -# The node will be translated (position)  <br/>
   * -# The node will be rotated (rotation)<br/>
   * -# The node will be scaled (scale)  <br/>
   *
   * <p>Order in transformations with grid enabled<br/>
   * -# The node will be translated (position)<br/>
   * -# The node will be rotated (rotation) <br/>
   * -# The node will be scaled (scale) <br/>
   * -# The grid will capture the screen <br/>
   * -# The grid will render the captured screen <br/></P>
   *
   * @class
   * @extends cc.Class
   *
   * @property {Number}               x                   - x axis position of node
   * @property {Number}               y                   - y axis position of node
   * @property {Number}               width               - Width of node
   * @property {Number}               height              - Height of node
   * @property {Number}               anchorX             - Anchor point's position on x axis
   * @property {Number}               anchorY             - Anchor point's position on y axis
   * @property {Boolean}              ignoreAnchor        - Indicate whether ignore the anchor point property for positioning
   * @property {Number}               skewX               - Skew x
   * @property {Number}               skewY               - Skew y
   * @property {Number}               zIndex              - Z order in depth which stands for the drawing order
   * @property {Number}               vertexZ             - WebGL Z vertex of this node, z order works OK if all the nodes uses the same openGL Z vertex
   * @property {Number}               rotation            - Rotation of node
   * @property {Number}               rotationX           - Rotation on x axis
   * @property {Number}               rotationY           - Rotation on y axis
   * @property {Number}               scale               - Scale of node
   * @property {Number}               scaleX              - Scale on x axis
   * @property {Number}               scaleY              - Scale on y axis
   * @property {Boolean}              visible             - Indicate whether node is visible or not
   * @property {cc.Color}             color               - Color of node, default value is white: (255, 255, 255)
   * @property {Boolean}              cascadeColor        - Indicate whether node's color value affect its child nodes, default value is false
   * @property {Number}               opacity             - Opacity of node, default value is 255
   * @property {Boolean}              opacityModifyRGB    - Indicate whether opacity affect the color value, default value is false
   * @property {Boolean}              cascadeOpacity      - Indicate whether node's opacity value affect its child nodes, default value is false
   * @property {Array}                children            - <@readonly> All children nodes
   * @property {Number}               childrenCount       - <@readonly> Number of children
   * @property {cc.Node}              parent              - Parent node
   * @property {Boolean}              running             - <@readonly> Indicate whether node is running or not
   * @property {Number}               tag                 - Tag of node
   * @property {Object}               userData            - Custom user data
   * @property {Object}               userObject          - User assigned CCObject, similar to userData, but instead of holding a void* it holds an id
   * @property {Number}               arrivalOrder        - The arrival order, indicates which children is added previously
   * @property {cc.ActionManager}     actionManager       - The CCActionManager object that is used by all actions.
   * @property {cc.Scheduler}         scheduler           - cc.Scheduler used to schedule all "updates" and timers.
   * @property {cc.GridBase}          grid                - grid object that is used when applying effects
   * @property {cc.GLProgram}         shaderProgram       - The shader program currently used for this node
   * @property {Number}               glServerState       - The state of OpenGL server side
   */
  class Node extends cc.Class {
    static WebGLRenderCmd: any;
    _renderCmd: any;
    _className: string;
    _anchorPoint: cc.Point;
    _contentSize: cc.Size;
    __instanceId: number;
    _visible: boolean;
    _children: cc.Node[];
    _reorderChildDirty: boolean;
    ctor: any;
    /**
     * Constructor function, override it to extend the construction behavior, remember to call "this._super()" in the extended "ctor" function.
     * @function
     */
    constructor();

    /**
     * Initializes the instance of cc.Node
     * @function
     * @returns {boolean} Whether the initialization was successful.
     */
    init(): boolean;

    /**
     * <p>Properties configuration function </br>
     * All properties in attrs will be set to the node, </br>
     * when the setter of the node is available, </br>
     * the property will be set via setter function.</br>
     * </p>
     * @function
     * @param {Object} attrs Properties to be set to node
     */
    attr(attrs: object): void;

    /**
     * <p>Returns the skew degrees in X </br>
     * The X skew angle of the node in degrees.  <br/>
     * This angle describes the shear distortion in the X direction.<br/>
     * Thus, it is the angle between the Y axis and the left edge of the shape </br>
     * The default skewX angle is 0. Positive values distort the node in a CW direction.</br>
     * </p>
     * @function
     * @return {Number} The X skew angle of the node in degrees.
     */
    getSkewX(): number;
    /**
     * <p>
     * Changes the X skew angle of the node in degrees.                                                    <br/>
     * <br/>
     * This angle describes the shear distortion in the X direction.                                       <br/>
     * Thus, it is the angle between the Y axis and the left edge of the shape                             <br/>
     * The default skewX angle is 0. Positive values distort the node in a CW direction.
     * </p>
     * @function
     * @param {Number} newSkewX The X skew angle of the node in degrees.
     */
    setSkewX(newSkewX: number): void;

    /**
     * <p>Returns the skew degrees in Y               <br/>
     * The Y skew angle of the node in degrees.                            <br/>
     * This angle describes the shear distortion in the Y direction.       <br/>
     * Thus, it is the angle between the X axis and the bottom edge of the shape       <br/>
     * The default skewY angle is 0. Positive values distort the node in a CCW direction.    <br/>
     * </p>
     * @function
     * @return {Number} The Y skew angle of the node in degrees.
     */
    getSkewY(): number;

    /**
     * <p>
     * Changes the Y skew angle of the node in degrees.                                                        <br/>
     *                                                                                                         <br/>
     * This angle describes the shear distortion in the Y direction.                                           <br/>
     * Thus, it is the angle between the X axis and the bottom edge of the shape                               <br/>
     * The default skewY angle is 0. Positive values distort the node in a CCW direction.                      <br/>
     * </p>
     * @function
     * @param {Number} newSkewY  The Y skew angle of the node in degrees.
     */
    setSkewY(newSkewY: number): void;

    /**
     * <p> LocalZOrder is the 'key' used to sort the node relative to its siblings.                                    <br/>
     *                                                                                                                 <br/>
     * The Node's parent will sort all its children based ont the LocalZOrder value.                                   <br/>
     * If two nodes have the same LocalZOrder, then the node that was added first to the children's array              <br/>
     * will be in front of the other node in the array.                                                                <br/>
     * <br/>
     * Also, the Scene Graph is traversed using the "In-Order" tree traversal algorithm ( http://en.wikipedia.org/wiki/Tree_traversal#In-order )
     * <br/>
     * And Nodes that have LocalZOder values < 0 are the "left" subtree                                                 <br/>
     * While Nodes with LocalZOder >=0 are the "right" subtree.    </p>
     * @function
     * @param {Number} localZOrder
     */
    setLocalZOrder(localZOrder: number): void;

    /**
     * Returns the local Z order of this node.
     * @function
     * @returns {Number} The local (relative to its siblings) Z order.
     */
    getLocalZOrder(): number;

    /**
     * Returns z order of this node
     * @function
     * @return {Number}
     * @deprecated since 3.0, please use getLocalZOrder instead
     */
    getZOrder(): number;

    /**
     * <p>
     *     Sets the Z order which stands for the drawing order, and reorder this node in its parent's children array.     <br/>
     *                                                                                                                    <br/>
     *      The Z order of node is relative to its "brothers": children of the same parent.                               <br/>
     *      It's nothing to do with OpenGL's z vertex. This one only affects the draw order of nodes in cocos2d.          <br/>
     *      The larger number it is, the later this node will be drawn in each message loop.                              <br/>
     *      Please refer to setVertexZ(float) for the difference.
     * </p>
     * @function
     * @param {Number} z Z order of this node.
     * @deprecated since 3.0, please use setLocalZOrder instead
     */
    setZOrder(z: number): void;

    /**
     * <p>Defines the oder in which the nodes are renderer.                                                                               <br/>
     * Nodes that have a Global Z Order lower, are renderer first.                                                                        <br/>
     *                                                                                                                                    <br/>
     * In case two or more nodes have the same Global Z Order, the oder is not guaranteed.                                                <br/>
     * The only exception if the Nodes have a Global Z Order == 0. In that case, the Scene Graph order is used.                           <br/>
     *                                                                                                                                    <br/>
     * By default, all nodes have a Global Z Order = 0. That means that by default, the Scene Graph order is used to render the nodes.    <br/>
     *                                                                                                                                    <br/>
     * Global Z Order is useful when you need to render nodes in an order different than the Scene Graph order.                           <br/>
     *                                                                                                                                    <br/>
     * Limitations: Global Z Order can't be used used by Nodes that have SpriteBatchNode as one of their ancestors.                       <br/>
     * And if ClippingNode is one of the ancestors, then "global Z order" will be relative to the ClippingNode.   </p>
     * @function
     * @param {Number} globalZOrder
     */
    setGlobalZOrder(globalZOrder: number): void;

    /**
     * Return the Node's Global Z Order.
     * @function
     * @returns {number} The node's global Z order
     */
    getGlobalZOrder(): number;

    /**
     * Returns WebGL Z vertex of this node.
     * @function
     * @return {Number} WebGL Z vertex of this node
     */
    getVertexZ(): number;

    /**
     * <p>
     *     Sets the real WebGL Z vertex.                                                                          <br/>
     *                                                                                                            <br/>
     *      Differences between openGL Z vertex and cocos2d Z order:                                              <br/>
     *      - WebGL Z modifies the Z vertex, and not the Z order in the relation between parent-children         <br/>
     *      - WebGL Z might require to set 2D projection                                                         <br/>
     *      - cocos2d Z order works OK if all the nodes uses the same WebGL Z vertex. eg: vertexZ = 0            <br/>
     *                                                                                                            <br/>
     *      @warning Use it at your own risk since it might break the cocos2d parent-children z order
     * </p>
     * @function
     * @param {Number} Var
     */
    setVertexZ(Var: number): void;

    /**
     * Returns the rotation (angle) of the node in degrees. 0 is the default rotation angle. Positive values rotate node clockwise.
     * @function
     * @return {Number} The rotation of the node in degrees.
     */
    getRotation(): number;

    /**
     * <p>
     *     Sets the rotation (angle) of the node in degrees.                                             <br/>
     *                                                                                                   <br/>
     *      0 is the default rotation angle.                                                             <br/>
     *      Positive values rotate node clockwise, and negative values for anti-clockwise.
     * </p>
     * @function
     * @param {Number} newRotation The rotation of the node in degrees.
     */
    setRotation(newRotation: number): void;

    /**
     * Returns the X axis rotation (angle) which represent a horizontal rotational skew of the node in degrees. <br/>
     * 0 is the default rotation angle. Positive values rotate node clockwise<br/>
     * (support only in WebGL rendering mode)
     * @function
     * @return {Number} The X rotation in degrees.
     */
    getRotationX(): number;

    /**
     * <p>
     *     Sets the X rotation (angle) of the node in degrees which performs a horizontal rotational skew.        <br/>
     *     (support only in WebGL rendering mode)                                                                 <br/>
     *     0 is the default rotation angle.                                                                       <br/>
     *     Positive values rotate node clockwise, and negative values for anti-clockwise.
     * </p>
     * @param {Number} rotationX The X rotation in degrees which performs a horizontal rotational skew.
     */
    setRotationX(rotationX: number): void;

    /**
     * Returns the Y axis rotation (angle) which represent a vertical rotational skew of the node in degrees. <br/>
     * 0 is the default rotation angle. Positive values rotate node clockwise<br/>
     * (support only in WebGL rendering mode)
     * @function
     * @return {Number} The Y rotation in degrees.
     */
    getRotationY(): number;
    /**
     * <p>
     *    Sets the Y rotation (angle) of the node in degrees which performs a vertical rotational skew.         <br/>
     *    (support only in WebGL rendering mode)                                                                <br/>
     *    0 is the default rotation angle.                                                                      <br/>
     *    Positive values rotate node clockwise, and negative values for anti-clockwise.
     * </p>
     * @param rotationY The Y rotation in degrees.
     */
    setRotationY(rotationY: number): void;

    /**
     * Returns the scale factor of the node.
     * @warning: Assertion will fail when _scaleX != _scaleY.
     * @function
     * @return {Number} The scale factor
     */
    getScale(): number;

    /**
     * Sets the scale factor of the node. 1.0 is the default scale factor. This function can modify the X and Y scale at the same time.
     * @function
     * @param {Number} scale or scaleX value
     * @param {Number} [scaleY=]
     */
    setScale(scale: number, scaleY?: number): void;

    /**
     * Returns the scale factor on X axis of this node
     * @function
     * @return {Number} The scale factor on X axis.
     */
    getScaleX(): number;

    /**
     * <p>
     *     Changes the scale factor on X axis of this node                                   <br/>
     *     The default value is 1.0 if you haven't changed it before
     * </p>
     * @function
     * @param {Number} newScaleX The scale factor on X axis.
     */
    setScaleX(newScaleX: number): void;

    /**
     * Returns the scale factor on Y axis of this node
     * @function
     * @return {Number} The scale factor on Y axis.
     */
    getScaleY(): number;

    /**
     * <p>
     *     Changes the scale factor on Y axis of this node                                            <br/>
     *     The Default value is 1.0 if you haven't changed it before.
     * </p>
     * @function
     * @param {Number} newScaleY The scale factor on Y axis.
     */
    setScaleY(newScaleY: number): void;
    /**
     * <p>
     *     Changes the position (x,y) of the node in cocos2d coordinates.<br/>
     *     The original point (0,0) is at the left-bottom corner of screen.<br/>
     *     Usually we use cc.p(x,y) to compose CCPoint object.<br/>
     *     and Passing two numbers (x,y) is more efficient than passing CCPoint object.
     * </p>
     * @function
     * @param {cc.Point|Number} newPosOrxValue The position (x,y) of the node in coordinates or the X coordinate for position
     * @param {Number} [yValue] Y coordinate for position
     * @example
     *    var size = cc.winSize;
     *    node.setPosition(size.width/2, size.height/2);
     */
    setPosition(newPosOrxValue: cc.Point | number, yValue?: number): void;

    /**
     * <p>
     * Sets the position (x,y) using values between 0 and 1.                                                <br/>
     * The positions in pixels is calculated like the following:                                            <br/>
     *   _position = _normalizedPosition * parent.getContentSize()
     * </p>
     * @param {cc.Point|Number} posOrX
     * @param {Number} [y]
     */
    setNormalizedPosition(posOrX: cc.Point | number, y: number): void;

    /**
     * <p>Returns a copy of the position (x,y) of the node in cocos2d coordinates. (0,0) is the left-bottom corner.</p>
     * @function
     * @return {cc.Point} The position (x,y) of the node in OpenGL coordinates
     */
    getPosition(): cc.Point;

    /**
     * returns the normalized position
     * @returns {cc.Point}
     */
    getNormalizedPosition(): cc.Point;

    /**
     * <p>Returns the x axis position of the node in cocos2d coordinates.</p>
     * @function
     * @return {Number}
     */
    getPositionX(): number;

    /**
     * <p>Sets the x axis position of the node in cocos2d coordinates.</p>
     * @function
     * @param {Number} x The new position in x axis
     */
    setPositionX(x: number): void;

    /**
     * <p>Returns the y axis position of the node in cocos2d coordinates.</p>
     * @function
     * @return {Number}
     */
    getPositionY(): number;

    /**
     * <p>Sets the y axis position of the node in cocos2d coordinates.</p>
     * @function
     * @param {Number} y The new position in y axis
     */
    setPositionY(y: number): void;

    /**
     * Returns the amount of children.
     * @function
     * @return {Number} The amount of children.
     */
    getChildrenCount(): number;

    /**
     * Returns an array of all children  <br/>
     * Composing a "tree" structure is a very important feature of CCNode
     * @function
     * @return {Array} An array of children
     * @example
     *  //This sample code traverses all children nodes, and set their position to (0,0)
     *  var allChildren = parent.getChildren();
     *  for(var i = 0; i< allChildren.length; i++) {
     *      allChildren[i].setPosition(0,0);
     *  }
     */
    getChildren<T = cc.Node>(): Array<T>;

    /**
     * Returns if the node is visible
     * @function
     * @see cc.Node#setVisible
     * @return {Boolean} true if the node is visible, false if the node is hidden.
     */
    isVisible(): boolean;

    /**
     * Sets whether the node is visible <br/>
     * The default value is true
     * @function
     * @param {Boolean} visible Pass true to make the node visible, false to hide the node.
     */
    setVisible(visible: boolean): void;

    /**
     *  <p>Returns a copy of the anchor point.<br/>
     *  Anchor point is the point around which all transformations and positioning manipulations take place.<br/>
     *  It's like a pin in the node where it is "attached" to its parent. <br/>
     *  The anchorPoint is normalized, like a percentage. (0,0) means the bottom-left corner and (1,1) means the top-right corner. <br/>
     *  But you can use values higher than (1,1) and lower than (0,0) too.  <br/>
     *  The default anchor point is (0.5,0.5), so it starts at the center of the node. <br/></p>
     * @function
     * @return {cc.Point}  The anchor point of node.
     */
    getAnchorPoint(): cc.Point;

    /**
     * <p>
     *     Sets the anchor point in percent.                                                                                              <br/>
     *                                                                                                                                    <br/>
     *     anchor point is the point around which all transformations and positioning manipulations take place.                            <br/>
     *     It's like a pin in the node where it is "attached" to its parent.                                                              <br/>
     *     The anchorPoint is normalized, like a percentage. (0,0) means the bottom-left corner and (1,1) means the top-right corner.     <br/>
     *     But you can use values higher than (1,1) and lower than (0,0) too.                                                             <br/>
     *     The default anchor point is (0.5,0.5), so it starts at the center of the node.
     * </p>
     * @function
     * @param {cc.Point|Number} point The anchor point of node or The x axis anchor of node.
     * @param {Number} [y] The y axis anchor of node.
     */
    setAnchorPoint(point: cc.Point | number, y?: number): void;
    /**
     * Returns a copy of the anchor point in absolute pixels.  <br/>
     * you can only read it. If you wish to modify it, use setAnchorPoint
     * @see cc.Node#getAnchorPoint
     * @function
     * @return {cc.Point} The anchor point in absolute pixels.
     */
    getAnchorPointInPoints(): cc.Point;

    /**
     * <p>Returns a copy the untransformed size of the node. <br/>
     * The contentSize remains the same no matter the node is scaled or rotated.<br/>
     * All nodes has a size. Layer and Scene has the same size of the screen by default. <br/></p>
     * @function
     * @return {cc.Size} The untransformed size of the node.
     */
    getContentSize(): cc.Size;

    /**
     * <p>
     *     Sets the untransformed size of the node.                                             <br/>
     *                                                                                          <br/>
     *     The contentSize remains the same no matter the node is scaled or rotated.            <br/>
     *     All nodes has a size. Layer and Scene has the same size of the screen.
     * </p>
     * @function
     * @param {cc.Size|Number} size The untransformed size of the node or The untransformed size's width of the node.
     * @param {Number} [height] The untransformed size's height of the node.
     */
    setContentSize(size: cc.Size | number, height?: number): void;

    /**
     * <p>
     *     Returns whether or not the node accepts event callbacks.                                     <br/>
     *     Running means the node accept event callbacks like onEnter(), onExit(), update()
     * </p>
     * @function
     * @return {Boolean} Whether or not the node is running.
     */
    isRunning(): boolean;

    /**
     * Returns a reference to the parent node
     * @function
     * @return {cc.Node} A reference to the parent node
     */
    getParent(): cc.Node;

    /**
     * Sets the parent node
     * @param {cc.Node} parent A reference to the parent node
     */
    setParent(parent: cc.Node): cc.Node;

    /**
     * Returns whether the anchor point will be ignored when you position this node.<br/>
     * When anchor point ignored, position will be calculated based on the origin point (0, 0) in parent's coordinates.
     * @function
     * @see cc.Node#ignoreAnchorPointForPosition
     * @return {Boolean} true if the anchor point will be ignored when you position this node.
     */
    isIgnoreAnchorPointForPosition(): boolean;

    /**
     * <p>
     *     Sets whether the anchor point will be ignored when you position this node.                              <br/>
     *     When anchor point ignored, position will be calculated based on the origin point (0, 0) in parent's coordinates.  <br/>
     *     This is an internal method, only used by CCLayer and CCScene. Don't call it outside framework.        <br/>
     *     The default value is false, while in CCLayer and CCScene are true
     * </p>
     * @function
     * @param {Boolean} newValue true if anchor point will be ignored when you position this node
     */
    ignoreAnchorPointForPosition(newValue: boolean): void;

    /**
     * Returns a tag that is used to identify the node easily.
     * @function
     * @return {Number} An integer that identifies the node.
     * @example
     *  //You can set tags to node then identify them easily.
     * // set tags
     * node1.setTag(TAG_PLAYER);
     * node2.setTag(TAG_MONSTER);
     * node3.setTag(TAG_BOSS);
     * parent.addChild(node1);
     * parent.addChild(node2);
     * parent.addChild(node3);
     * // identify by tags
     * var allChildren = parent.getChildren();
     * for(var i = 0; i < allChildren.length; i++){
     *     switch(node.getTag()) {
     *         case TAG_PLAYER:
     *             break;
     *         case TAG_MONSTER:
     *             break;
     *         case TAG_BOSS:
     *             break;
     *     }
     * }
     */
    getTag(): number;

    /**
     * Changes the tag that is used to identify the node easily. <br/>
     * Please refer to getTag for the sample code.
     * @function
     * @see cc.Node#getTag
     * @param {Number} tag A integer that identifies the node.
     */
    setTag(tag: number): void;

    /**
     * Changes the name that is used to identify the node easily.
     * @function
     * @param {String} name
     */
    setName(name: string): void;

    /**
     * Returns a string that is used to identify the node.
     * @function
     * @returns {string} A string that identifies the node.
     */
    getName(): string;

    /**
     * <p>
     *     Returns a custom user data pointer                                                               <br/>
     *     You can set everything in UserData pointer, a data block, a structure or an object.
     * </p>
     * @function
     * @return {object}  A custom user data pointer
     */
    getUserData(): any;

    /**
     * <p>
     *    Sets a custom user data reference                                                                   <br/>
     *    You can set everything in UserData reference, a data block, a structure or an object, etc.
     * </p>
     * @function
     * @warning Don't forget to release the memory manually in JSB, especially before you change this data pointer, and before this node is autoreleased.
     * @param {object} Var A custom user data
     */
    setUserData(Var: object): void;

    /**
     * Returns a user assigned cocos2d object.                             <br/>
     * Similar to userData, but instead of holding all kinds of data it can only hold a cocos2d object
     * @function
     * @return {object} A user assigned CCObject
     */
    getUserObject(): object;

    /**
     * <p>
     *      Sets a user assigned cocos2d object                                                                                       <br/>
     *      Similar to UserData, but instead of holding all kinds of data it can only hold a cocos2d object                        <br/>
     *      In JSB, the UserObject will be retained once in this method, and the previous UserObject (if existed) will be release. <br/>
     *      The UserObject will be released in CCNode's destruction.
     * </p>
     * @param {object} newValue A user cocos2d object
     */
    setUserObject(newValue: object): void;

    /**
     * Returns the arrival order, indicates which children should be added previously.
     * @function
     * @return {Number} The arrival order.
     */
    getOrderOfArrival(): number;
    /**
     * <p>
     *     Sets the arrival order when this node has a same ZOrder with other children.                             <br/>
     *                                                                                                              <br/>
     *     A node which called addChild subsequently will take a larger arrival order,                              <br/>
     *     If two children have the same Z order, the child with larger arrival order will be drawn later.
     * </p>
     * @function
     * @warning This method is used internally for zOrder sorting, don't change this manually
     * @param {Number} Var  The arrival order.
     */
    setOrderOfArrival(Var: number): number;

    /**
     * <p>Returns the CCActionManager object that is used by all actions.<br/>
     * (IMPORTANT: If you set a new cc.ActionManager, then previously created actions are going to be removed.)</p>
     * @function
     * @see cc.Node#setActionManager
     * @return {cc.ActionManager} A CCActionManager object.
     */
    getActionManager(): cc.ActionManager;

    clone<T = cc.Node>(): T;
    /**
     * <p>Sets the cc.ActionManager object that is used by all actions. </p>
     * @function
     * @warning If you set a new CCActionManager, then previously created actions will be removed.
     * @param {cc.ActionManager} actionManager A CCActionManager object that is used by all actions.
     */
    setActionManager(actionManager: cc.ActionManager): void;

    /**
     * <p>
     *   Returns the cc.Scheduler object used to schedule all "updates" and timers.
     * </p>
     * @function
     * @return {cc.Scheduler} A CCScheduler object.
     */
    getScheduler(): cc.Scheduler;

    /**
     * <p>
     *   Sets a CCScheduler object that is used to schedule all "updates" and timers.           <br/>
     *   IMPORTANT: If you set a new cc.Scheduler, then previously created timers/update are going to be removed.
     * </p>
     * @function
     * @warning If you set a new CCScheduler, then previously created timers/update are going to be removed.
     * @param scheduler A cc.Scheduler object that is used to schedule all "update" and timers.
     */
    setScheduler(scheduler: cc.Scheduler): void;

    /**
     * Returns a "local" axis aligned bounding box of the node. <br/>
     * The returned box is relative only to its parent.
     * @function
     * @return {cc.Rect} The calculated bounding box of the node
     */
    getBoundingBox(): cc.Rect;

    /**
     * Stops all running actions and schedulers
     * @function
     */
    cleanup(): void;

    // composition: GET
    /**
     * Returns a child from the container given its tag
     * @function
     * @param {Number} aTag An identifier to find the child node.
     * @return {cc.Node} a CCNode object whose tag equals to the input parameter
     */
    getChildByTag(aTag: number): cc.Node;

    /**
     * Returns a child from the container given its name
     * @function
     * @param {String} name A name to find the child node.
     * @return {cc.Node} a CCNode object whose name equals to the input parameter
     */
    getChildByName<T = cc.Node>(name: string): T | null;

    // composition: ADD

    /** <p>"add" logic MUST only be in this method <br/> </p>
     *
     * <p>If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.</p>
     * @function
     * @param {cc.Node} child  A child node
     * @param {Number} [localZOrder=]  Z order for drawing priority. Please refer to setZOrder(int)
     * @param {Number|String} [tag=]  An integer or a name to identify the node easily. Please refer to setTag(int) and setName(string)
     */
    addChild(child: cc.Node, localZOrder?: number, tag?: number | string): void;

    // composition: REMOVE
    /**
     * Remove itself from its parent node. If cleanup is true, then also remove all actions and callbacks. <br/>
     * If the cleanup parameter is not passed, it will force a cleanup. <br/>
     * If the node orphan, then nothing happens.
     * @function
     * @param {Boolean} [cleanup=true] true if all actions and callbacks on this node should be removed, false otherwise.
     * @see cc.Node#removeFromParentAndCleanup
     */
    removeFromParent(cleanup?: boolean): void;

    /**
     * Removes this node itself from its parent node.  <br/>
     * If the node orphan, then nothing happens.
     * @deprecated since v3.0, please use removeFromParent() instead
     * @param {Boolean} [cleanup=true] true if all actions and callbacks on this node should be removed, false otherwise.
     */
    removeFromParentAndCleanup(cleanup?: boolean): void;
    /** <p>Removes a child from the container. It will also cleanup all running actions depending on the cleanup parameter. </p>
     * If the cleanup parameter is not passed, it will force a cleanup. <br/>
     * <p> "remove" logic MUST only be on this method  <br/>
     * If a class wants to extend the 'removeChild' behavior it only needs <br/>
     * to override this method </p>
     * @function
     * @param {cc.Node} child  The child node which will be removed.
     * @param {Boolean} [cleanup=true]  true if all running actions and callbacks on the child node will be cleanup, false otherwise.
     */
    removeChild(child: cc.Node, cleanup?: boolean): void;

    removeChildByName(name: string, cleanup?: boolean): void;

    /**
     * Removes a child from the container by tag value. It will also cleanup all running actions depending on the cleanup parameter.
     * If the cleanup parameter is not passed, it will force a cleanup. <br/>
     * @function
     * @param {Number} tag An integer number that identifies a child node
     * @param {Boolean} [cleanup=true] true if all running actions and callbacks on the child node will be cleanup, false otherwise.
     * @see cc.Node#removeChildByTag
     */
    removeChildByTag(tag: number, cleanup?: boolean): void;

    /**
     * Removes all children from the container and do a cleanup all running actions depending on the cleanup parameter.
     * @param {Boolean} [cleanup=true]
     */
    removeAllChildrenWithCleanup(cleanup?: boolean): void;

    /**
     * Removes all children from the container and do a cleanup all running actions depending on the cleanup parameter. <br/>
     * If the cleanup parameter is not passed, it will force a cleanup. <br/>
     * @function
     * @param {Boolean} [cleanup=true] true if all running actions on all children nodes should be cleanup, false otherwise.
     */
    removeAllChildren(cleanup?: boolean): void;

    /** Reorders a child according to a new z value. <br/>
     * The child MUST be already added.
     * @function
     * @param {cc.Node} child An already added child node. It MUST be already added.
     * @param {Number} zOrder Z order for drawing priority. Please refer to setZOrder(int)
     */
    reorderChild(child: cc.Node, zOrder: number): void;

    /**
     * <p>
     *     Sorts the children array once before drawing, instead of every time when a child is added or reordered.    <br/>
     *     This approach can improves the performance massively.
     * </p>
     * @function
     * @note Don't call this manually unless a child added needs to be removed in the same frame
     */
    sortAllChildren(): void;

    //scene management
    /**
     * <p>
     *     Event callback that is invoked every time when CCNode enters the 'stage'.                                   <br/>
     *     If the CCNode enters the 'stage' with a transition, this event is called when the transition starts.        <br/>
     *     During onEnter you can't access a "sister/brother" node.                                                    <br/>
     *     If you override onEnter, you must call its parent's onEnter function with this._super().
     * </p>
     * @function
     */
    onEnter(): void;

    /**
     * <p>
     *     Event callback that is invoked when the CCNode enters in the 'stage'.                                                        <br/>
     *     If the CCNode enters the 'stage' with a transition, this event is called when the transition finishes.                       <br/>
     *     If you override onEnterTransitionDidFinish, you shall call its parent's onEnterTransitionDidFinish with this._super()
     * </p>
     * @function
     */
    onEnterTransitionDidFinish(): void;

    /**
     * <p>callback that is called every time the cc.Node leaves the 'stage'.  <br/>
     * If the cc.Node leaves the 'stage' with a transition, this callback is called when the transition starts. <br/>
     * If you override onExitTransitionDidStart, you shall call its parent's onExitTransitionDidStart with this._super()</p>
     * @function
     */
    onExitTransitionDidStart(): void;

    /**
     * <p>
     * callback that is called every time the cc.Node leaves the 'stage'.                                         <br/>
     * If the cc.Node leaves the 'stage' with a transition, this callback is called when the transition finishes. <br/>
     * During onExit you can't access a sibling node.                                                             <br/>
     * If you override onExit, you shall call its parent's onExit with this._super().
     * </p>
     * @function
     */
    onExit(): void;

    // actions
    /**
     * Executes an action, and returns the action that is executed.<br/>
     * The node becomes the action's target. Refer to cc.Action's getTarget()
     * @function
     * @warning Starting from v0.8 actions don't retain their target anymore.
     * @param {cc.Action} action
     * @return {cc.Action} An Action pointer
     */
    runAction(action: cc.Action): cc.Action;

    /**
     * Stops and removes all actions from the running action list .
     * @function
     */
    stopAllActions(): void;
    /**
     * Stops and removes an action from the running action list.
     * @function
     * @param {cc.Action} action An action object to be removed.
     */
    stopAction(action: cc.Action): void;

    /**
     * Removes an action from the running action list by its tag.
     * @function
     * @param {Number} tag A tag that indicates the action to be removed.
     */
    stopActionByTag(tag: number): void;
    /**
     * Returns an action from the running action list by its tag.
     * @function
     * @see cc.Node#getTag and cc.Node#setTag
     * @param {Number} tag
     * @return {cc.Action} The action object with the given tag.
     */
    getActionByTag<T extends cc.Action>(tag: number): T;

    /** <p>Returns the numbers of actions that are running plus the ones that are schedule to run (actions in actionsToAdd and actions arrays).<br/>
     *    Composable actions are counted as 1 action. Example:<br/>
     *    If you are running 1 Sequence of 7 actions, it will return 1. <br/>
     *    If you are running 7 Sequences of 2 actions, it will return 7.</p>
     * @function
     * @return {Number} The number of actions that are running plus the ones that are schedule to run
     */
    getNumberOfRunningActions(): number;

    // cc.Node - Callbacks
    // timers
    /**
     * <p>schedules the "update" method.                                                                           <br/>
     * It will use the order number 0. This method will be called every frame.                                  <br/>
     * Scheduled methods with a lower order value will be called before the ones that have a higher order value.<br/>
     * Only one "update" method could be scheduled per node.</p>
     * @function
     */
    scheduleUpdate(): void;

    /**
     * <p>
     * schedules the "update" callback function with a custom priority.
     * This callback function will be called every frame.<br/>
     * Scheduled callback functions with a lower priority will be called before the ones that have a higher value.<br/>
     * Only one "update" callback function could be scheduled per node (You can't have 2 'update' callback functions).<br/>
     * </p>
     * @function
     * @param {Number} priority
     */
    scheduleUpdateWithPriority(priority: number): void;

    /**
     * Unschedules the "update" method.
     * @function
     * @see cc.Node#scheduleUpdate
     */
    unscheduleUpdate(): void;

    /**
     * <p>Schedules a custom selector.         <br/>
     * If the selector is already scheduled, then the interval parameter will be updated without scheduling it again.</p>
     * @function
     * @param {function} callback A function wrapped as a selector
     * @param {Number} interval  Tick interval in seconds. 0 means tick every frame. If interval = 0, it's recommended to use scheduleUpdate() instead.
     * @param {Number} repeat    The selector will be executed (repeat + 1) times, you can use kCCRepeatForever for tick infinitely.
     * @param {Number} delay     The amount of time that the first tick will wait before execution.
     * @param {String} key The only string identifying the callback
     */
    schedule(
      callback: Function,
      interval?: number,
      repeat?: number,
      delay?: number,
      key?: string
    ): void;

    /**
     * Schedules a callback function that runs only once, with a delay of 0 or larger
     * @function
     * @see cc.Node#schedule
     * @param {function} callback  A function wrapped as a selector
     * @param {Number} delay  The amount of time that the first tick will wait before execution.
     * @param {String} key The only string identifying the callback
     */
    scheduleOnce(callback: Function, delay: number, key: string): void;

    /**
     * unschedules a custom callback function.
     * @function
     * @see cc.Node#schedule
     * @param {function} callback_fn  A function wrapped as a selector
     */
    unschedule(callback_fn: Function): void;
    /**
     * <p>unschedule all scheduled callback functions: custom callback functions, and the 'update' callback function.<br/>
     * Actions are not affected by this method.</p>
     * @function
     */
    unscheduleAllCallbacks(): void;

    /**
     * Resumes all scheduled selectors and actions.<br/>
     * This method is called internally by onEnter
     * @function
     * @deprecated since v3.0, please use resume() instead
     */
    resumeSchedulerAndActions(): void;

    /**
     * <p>Resumes all scheduled selectors and actions.<br/>
     * This method is called internally by onEnter</p>
     */
    resume(): void;

    /**
     * <p>Pauses all scheduled selectors and actions.<br/>
     * This method is called internally by onExit</p>
     * @deprecated since v3.0, please use pause instead
     * @function
     */
    pauseSchedulerAndActions(): void;

    /**
     * <p>Pauses all scheduled selectors and actions.<br/>
     * This method is called internally by onExit</p>
     * @function
     */
    pause(): void;

    /**
     *<p>Sets the additional transform.<br/>
     *  The additional transform will be concatenated at the end of getNodeToParentTransform.<br/>
     *  It could be used to simulate `parent-child` relationship between two nodes (e.g. one is in BatchNode, another isn't).<br/>
     *  </p>
     *  @function
     *  @param {cc.AffineTransform} additionalTransform  The additional transform
     *  @example
     * // create a batchNode
     * var batch = new cc.SpriteBatchNode("Icon-114.png");
     * this.addChild(batch);
     *
     * // create two sprites, spriteA will be added to batchNode, they are using different textures.
     * var spriteA = new cc.Sprite(batch->getTexture());
     * var spriteB = new cc.Sprite("Icon-72.png");
     *
     * batch.addChild(spriteA);
     *
     * // We can't make spriteB as spriteA's child since they use different textures. So just add it to layer.
     * // But we want to simulate `parent-child` relationship for these two node.
     * this.addChild(spriteB);
     *
     * //position
     * spriteA.setPosition(ccp(200, 200));
     *
     * // Gets the spriteA's transform.
     * var t = spriteA.getNodeToParentTransform();
     *
     * // Sets the additional transform to spriteB, spriteB's position will based on its pseudo parent i.e. spriteA.
     * spriteB.setAdditionalTransform(t);
     *
     * //scale
     * spriteA.setScale(2);
     *
     * // Gets the spriteA's transform.
     * t = spriteA.getNodeToParentTransform();
     *
     * // Sets the additional transform to spriteB, spriteB's scale will based on its pseudo parent i.e. spriteA.
     * spriteB.setAdditionalTransform(t);
     *
     * //rotation
     * spriteA.setRotation(20);
     *
     * // Gets the spriteA's transform.
     * t = spriteA.getNodeToParentTransform();
     *
     * // Sets the additional transform to spriteB, spriteB's rotation will based on its pseudo parent i.e. spriteA.
     * spriteB.setAdditionalTransform(t);
     */
    setAdditionalTransform(additionalTransform: cc.AffineTransform): void;

    /**
     * Returns the matrix that transform parent's space coordinates to the node's (local) space coordinates.<br/>
     * The matrix is in Pixels.
     * @function
     * @return {cc.AffineTransform}
     */
    getParentToNodeTransform(): cc.AffineTransform;

    /**
     * Returns the world affine transform matrix. The matrix is in Pixels.
     * @function
     * @return {cc.AffineTransform}
     */
    getNodeToWorldTransform(): cc.AffineTransform;

    /**
     * Returns the inverse world affine transform matrix. The matrix is in Pixels.
     * @function
     * @return {cc.AffineTransform}
     */
    getWorldToNodeTransform(): cc.AffineTransform;

    /**
     * Converts a Point to node (local) space coordinates. The result is in Points.
     * @function
     * @param {cc.Point} worldPoint
     * @return {cc.Point}
     */
    convertToNodeSpace(worldPoint: cc.Point): cc.Point;

    /**
     * Converts a Point to world space coordinates. The result is in Points.
     * @function
     * @param {cc.Point} nodePoint
     * @return {cc.Point}
     */
    convertToWorldSpace(nodePoint: cc.Point): cc.Point;

    /**
     * Converts a Point to node (local) space coordinates. The result is in Points.<br/>
     * treating the returned/received node point as anchor relative.
     * @function
     * @param {cc.Point} worldPoint
     * @return {cc.Point}
     */
    convertToNodeSpaceAR(worldPoint: cc.Point): cc.Point;

    /**
     * Converts a local Point to world space coordinates.The result is in Points.<br/>
     * treating the returned/received node point as anchor relative.
     * @function
     * @param {cc.Point} nodePoint
     * @return {cc.Point}
     */
    convertToWorldSpaceAR(nodePoint: cc.Point): cc.Point;

    /** convenience methods which take a cc.Touch instead of cc.Point
     * @function
     * @param {cc.Touch} touch The touch object
     * @return {cc.Point}
     */
    convertTouchToNodeSpace(touch: cc.Touch): cc.Point;

    setNodeDirty(): void;

    /**
     * converts a cc.Touch (world coordinates) into a local coordinate. This method is AR (Anchor Relative).
     * @function
     * @param {cc.Touch} touch The touch object
     * @return {cc.Point}
     */
    convertTouchToNodeSpaceAR(touch: cc.Touch): cc.Point;

    /**
     * Update will be called automatically every frame if "scheduleUpdate" is called when the node is "live".<br/>
     * The default behavior is to invoke the visit function of node's componentContainer.<br/>
     * Override me to implement your own update logic.
     * @function
     * @param {Number} dt Delta time since last update
     */
    update(dt: number): void;

    /**
     * <p>
     * Calls children's updateTransform() method recursively.                                        <br/>
     *                                                                                               <br/>
     * This method is moved from CCSprite, so it's no longer specific to CCSprite.                   <br/>
     * As the result, you apply CCSpriteBatchNode's optimization on your customed CCNode.            <br/>
     * e.g., batchNode->addChild(myCustomNode), while you can only addChild(sprite) before.
     * </p>
     * @function
     */
    updateTransform(): void;

    /**
     * <p>Currently JavaScript Bindings (JSB), in some cases, needs to use retain and release. This is a bug in JSB,
     * and the ugly workaround is to use retain/release. So, these 2 methods were added to be compatible with JSB.
     * This is a hack, and should be removed once JSB fixes the retain/release bug<br/>
     * You will need to retain an object if you created an engine object and haven't added it into the scene graph during the same frame.<br/>
     * Otherwise, JSB's native autorelease pool will consider this object a useless one and release it directly,<br/>
     * when you want to use it later, a "Invalid Native Object" error will be raised.<br/>
     * The retain function can increase a reference count for the native object to avoid it being released,<br/>
     * you need to manually invoke release function when you think this object is no longer needed, otherwise, there will be memory learks.<br/>
     * retain and release function call should be paired in developer's game code.</p>
     * @function
     * @see cc.Node#release
     */
    retain(): void;
    /**
     * <p>Currently JavaScript Bindings (JSB), in some cases, needs to use retain and release. This is a bug in JSB,
     * and the ugly workaround is to use retain/release. So, these 2 methods were added to be compatible with JSB.
     * This is a hack, and should be removed once JSB fixes the retain/release bug<br/>
     * You will need to retain an object if you created an engine object and haven't added it into the scene graph during the same frame.<br/>
     * Otherwise, JSB's native autorelease pool will consider this object a useless one and release it directly,<br/>
     * when you want to use it later, a "Invalid Native Object" error will be raised.<br/>
     * The retain function can increase a reference count for the native object to avoid it being released,<br/>
     * you need to manually invoke release function when you think this object is no longer needed, otherwise, there will be memory learks.<br/>
     * retain and release function call should be paired in developer's game code.</p>
     * @function
     * @see cc.Node#retain
     */
    release(): void;

    /**
     * Returns a component identified by the name given.
     * @function
     * @param {String} name The name to search for
     * @return {cc.Component} The component found
     */
    // getComponent(name:string):cc.Component;

    /**
     * Adds a component to the node's component container.
     * @function
     * @param {cc.Component} component
     */
    addComponent(component: any): void;

    getReferenceCount(): number;

    /**
     * Removes a component identified by the given name or removes the component object given
     * @function
     * @param {String|cc.Component} component
     */
    //removeComponent(component:string|cc.Component):void;

    /**
     * Removes all components of cc.Node, it called when cc.Node is exiting from stage.
     * @function
     */
    removeAllComponents(): void;

    /**
     * Recursive method that visit its children and draw them
     * @function
     * @param {cc.Node} parent
     */
    visit(parent: cc.Node): void;

    /**
     * Performs view-matrix transformation based on position, scale, rotation and other attributes.
     * @function
     * @param {cc.Node.RenderCmd} parentCmd parent's render command
     * @param {boolean} recursive whether call its children's transform
     */
    transform(parentCmd: any, recursive: boolean): void;

    /**
     * Returns the matrix that transform the node's (local) space coordinates into the parent's space coordinates.<br/>
     * The matrix is in Pixels.
     * @function
     * @return {cc.AffineTransform} The affine transform object
     */
    getNodeToParentTransform(ancestor?: cc.Node): cc.AffineTransform;

    getNodeToParentAffineTransform(ancestor?: cc.Node): cc.AffineTransform;

    /**
     * Return the shader program currently used for this node
     * @function
     * @return {cc.GLProgram} The shader program currently used for this node
     */
    getShaderProgram(): cc.GLProgram;

    /**
     * <p>
     *     Sets the shader program for this node
     *
     *     Since v2.0, each rendering node must set its shader program.
     *     It should be set in initialize phase.
     * </p>
     * @function
     * @param {cc.GLProgram} newShaderProgram The shader program which fetches from CCShaderCache.
     * @example
     * node.setGLProgram(cc.shaderCache.programForKey(cc.SHADER_POSITION_TEXTURECOLOR));
     */
    setShaderProgram(newShaderProgram: cc.GLProgram): void;

    setGLProgramState(glProgramState: cc.GLProgramState): void;

    getGLProgramState(): cc.GLProgram;

    /**
     * Returns a "world" axis aligned bounding box of the node.
     * @function
     * @return {cc.Rect}
     */
    getBoundingBoxToWorld(): cc.Rect;

    /**
     * Returns the opacity of Node
     * @function
     * @returns {number} opacity
     */
    getOpacity(): number;

    /**
     * Returns the displayed opacity of Node,
     * the difference between displayed opacity and opacity is that displayed opacity is calculated based on opacity and parent node's opacity when cascade opacity enabled.
     * @function
     * @returns {number} displayed opacity
     */
    getDisplayedOpacity(): number;

    /**
     * Sets the opacity of Node
     * @function
     * @param {Number} opacity
     */
    setOpacity(opacity: number): void;

    /**
     * Update displayed opacity
     * @function
     * @param {Number} parentOpacity
     */
    updateDisplayedOpacity(parentOpacity: number): number;
    /**
     * Returns whether node's opacity value affect its child nodes.
     * @function
     * @returns {boolean}
     */
    isCascadeOpacityEnabled(): boolean;

    /**
     * Enable or disable cascade opacity, if cascade enabled, child nodes' opacity will be the multiplication of parent opacity and its own opacity.
     * @function
     * @param {boolean} cascadeOpacityEnabled
     */
    setCascadeOpacityEnabled(cascadeOpacityEnabled: boolean): void;
    /**
     * Returns the color of Node
     * @function
     * @returns {cc.Color}
     */
    getColor(): cc.Color;

    /**
     * Returns the displayed color of Node,
     * the difference between displayed color and color is that displayed color is calculated based on color and parent node's color when cascade color enabled.
     * @function
     * @returns {cc.Color}
     */
    getDisplayedColor(): cc.Color;

    /**
     * <p>Sets the color of Node.<br/>
     * When color doesn't include opacity value like cc.color(128,128,128), this function only change the color. <br/>
     * When color include opacity like cc.color(128,128,128,100), then this function will change the color and the opacity.</p>
     * @function
     * @param {cc.Color} color The new color given
     */
    setColor(color: cc.Color): void;

    /**
     * Update the displayed color of Node
     * @function
     * @param {cc.Color} parentColor
     */
    updateDisplayedColor(parentColor: cc.Color): void;

    /**
     * Returns whether node's color value affect its child nodes.
     * @function
     * @returns {boolean}
     */
    isCascadeColorEnabled(): boolean;

    /**
     * Enable or disable cascade color, if cascade enabled, child nodes' opacity will be the cascade value of parent color and its own color.
     * @param {boolean} cascadeColorEnabled
     */
    setCascadeColorEnabled(cascadeColorEnabled: boolean): void;

    /**
     * Set whether color should be changed with the opacity value,
     * useless in cc.Node, but this function is override in some class to have such behavior.
     * @function
     * @param {Boolean} opacityValue
     */
    setOpacityModifyRGB(opacityValue: boolean): void;

    /**
     * Get whether color should be changed with the opacity value
     * @function
     * @return {Boolean}
     */
    isOpacityModifyRGB(): boolean;

    /** Search the children of the receiving node to perform processing for nodes which share a name.
     *
     * @param name The name to search for, supports c++11 regular expression.
     * Search syntax options:
     * `//`: Can only be placed at the begin of the search string. This indicates that it will search recursively.
     * `..`: The search should move up to the node's parent. Can only be placed at the end of string.
     * `/` : When placed anywhere but the start of the search string, this indicates that the search should move to the node's children.
     *
     * @code
     * enumerateChildren("//MyName", ...): This searches the children recursively and matches any node with the name `MyName`.
     * enumerateChildren("[[:alnum:]]+", ...): This search string matches every node of its children.
     * enumerateChildren("A[[:digit:]]", ...): This searches the node's children and returns any child named `A0`, `A1`, ..., `A9`.
     * enumerateChildren("Abby/Normal", ...): This searches the node's grandchildren and returns any node whose name is `Normal`
     * and whose parent is named `Abby`.
     * enumerateChildren("//Abby/Normal", ...): This searches recursively and returns any node whose name is `Normal` and whose
     * parent is named `Abby`.
     * @endcode
     *
     * @warning Only support alpha or number for name, and not support unicode.
     *
     * @param callback A callback function to execute on nodes that match the `name` parameter. The function takes the following arguments:
     *  `node`
     *      A node that matches the name
     *  And returns a boolean result. Your callback can return `true` to terminate the enumeration.
     *
     */
    enumerateChildren(name: string, callback: (v: cc.Node) => boolean): void;

    doEnumerateRecursive(
      node: cc.Node,
      name: string,
      callback: (v: cc.Node) => boolean
    ): void;

    doEnumerate(name: string, callback: (v: cc.Node) => boolean): void;

    _setWidth(width: number): void;

    _setHeight(height: number): void;

    _parent: cc.Node | null;

    get x(): number;
    set x(value: number);
    get y(): number;
    set y(value: number);
    get width(): number;
    set width(value: number);
    get height(): number;
    set height(value: number);
    get anchorX(): number;
    set anchorX(value: number);
    get anchorY(): number;
    set anchorY(value: number);
    get skewX(): number;
    set skewX(value: number);
    get skewY(): number;
    set skewY(value: number);
    get zIndex(): number;
    set zIndex(value: number);
    get vertexZ(): number;
    set vertexZ(value: number);
    get rotation(): cc.Point;
    set rotation(value: number);
    get rotationX(): number;
    set rotationX(value: number);
    get rotationY(): number;
    set rotationY(value: number);
    get scale(): number;
    set scale(value: number);
    get scaleX(): number;
    set scaleX(value: number);
    get scaleY(): number;
    set scaleY(value: number);
    get children(): cc.Node[];
    get childrenCount(): number;
    get parent(): cc.Node;
    set parent(value: cc.Node);
    get visible(): boolean;
    set visible(value: boolean);
    get running(): boolean;
    set running(value: boolean);
    get ignoreAnchor(): boolean;
    set ignoreAnchor(value: boolean);
    tag: number;
    userData: any;
    userObject: any;
    arrivalOrder: number;

    get actionManager(): cc.ActionManager;
    set actionManager(value: cc.ActionManager);
    get scheduler(): cc.Scheduler;
    set scheduler(value: cc.Scheduler);
    get boundingBox(): cc.Rect;
    set boundingBox(value: cc.Rect);
    get shaderProgram(): cc.GLProgram;
    set shaderProgram(value: cc.GLProgram);
    get opacity(): number;
    set opacity(value: number);
    get opacityModifyRGB(): boolean;
    set opacityModifyRGB(value: boolean);
    get cascadeOpacity(): boolean;
    set cascadeOpacity(value: boolean);
    get color(): cc.Color;
    set color(value: cc.Color);
    get cascadeColor(): boolean;
    set cascadeColor(value: boolean);
  }
}
