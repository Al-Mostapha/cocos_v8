declare namespace cc {
  export class Scheduler extends Class {
    /**
     * <p>
     *    Scheduler is responsible of triggering the scheduled callbacks.<br/>
     *    You should not use NSTimer. Instead use this class.<br/>
     *    <br/>
     *    There are 2 different types of callbacks (selectors):<br/>
     *       - update callback: the 'update' callback will be called every frame. You can customize the priority.<br/>
     *       - custom callback: A custom callback will be called every frame, or with a custom interval of time<br/>
     *       <br/>
     *    The 'custom selectors' should be avoided when possible. It is faster, and consumes less memory to use the 'update callback'. *
     * </p>
     * @class
     * @extends cc.Class
     *
     * @example
     * //register a schedule to scheduler
     * cc.director.getScheduler().schedule(callback, this, interval, !this._isRunning);
     */

    //       _timeScale:1.0,

    //       //_updates : null, //_updates[0] list of priority < 0, _updates[1] list of priority == 0, _updates[2] list of priority > 0,
    //       _updatesNegList: null,
    //       _updates0List: null,
    //       _updatesPosList: null,

    //       _hashForTimers:null, //Used for "selectors with interval"
    //       _arrayForTimers:null, //Speed up indexing
    //       _hashForUpdates:null, // hash used to fetch quickly the list entries for pause,delete,etc
    //       //_arrayForUpdates:null, //Speed up indexing

    //       _currentTarget:null,
    //       _currentTargetSalvaged:false,
    //       _updateHashLocked:false, //If true unschedule will not remove anything from a hash. Elements will only be marked for deletion.
    constructor();

    //-----------------------public method-------------------------
    /**
     * <p>
     *    Modifies the time of all scheduled callbacks.<br/>
     *    You can use this property to create a 'slow motion' or 'fast forward' effect.<br/>
     *    Default is 1.0. To create a 'slow motion' effect, use values below 1.0.<br/>
     *    To create a 'fast forward' effect, use values higher than 1.0.<br/>
     *    @warning It will affect EVERY scheduled selector / action.
     * </p>
     * @param {Number} timeScale
     */
    setTimeScale(timeScale: number): void;

    /**
     * Returns time scale of scheduler
     * @return {Number}
     */
    getTimeScale(): number;

    /**
     * 'update' the scheduler. (You should NEVER call this method, unless you know what you are doing.)
     * @param {Number} dt delta time
     */
    update(dt: number): void;

    /**
     * <p>
     *   The scheduled method will be called every 'interval' seconds.</br>
     *   If paused is YES, then it won't be called until it is resumed.<br/>
     *   If 'interval' is 0, it will be called every frame, but if so, it recommended to use 'scheduleUpdateForTarget:' instead.<br/>
     *   If the callback function is already scheduled, then only the interval parameter will be updated without re-scheduling it again.<br/>
     *   repeat let the action be repeated repeat + 1 times, use cc.REPEAT_FOREVER to let the action run continuously<br/>
     *   delay is the amount of time the action will wait before it'll start<br/>
     * </p>
     * @deprecated since v3.4 please use .schedule
     * @param {cc.Class} target
     * @param {function} callback_fn
     * @param {Number} interval
     * @param {Number} repeat
     * @param {Number} delay
     * @param {Boolean} paused
     * @example
     * //register a schedule to scheduler
     * cc.director.getScheduler().scheduleCallbackForTarget(this, function, interval, repeat, delay, !this._isRunning );
     */
    scheduleCallbackForTarget(
      target: cc.Class,
      callback_fn: Function,
      interval: number,
      repeat: number,
      delay: number,
      paused: boolean
    ): void;

    schedule(
      callback: Function,
      target: cc.Class,
      interval: number,
      repeat: number,
      delay: number,
      paused?: boolean,
      key?: string
    ): void;

    scheduleUpdate(target: cc.Class, priority: number, paused: boolean): void;

    unschedule(key: string, target: cc.Class): void;

    unscheduleUpdate(target: cc.Class): void;

    unscheduleAllForTarget(target: cc.Class): void;
    unscheduleAll(): void;
    unscheduleAllWithMinPriority(minPriority: number): void;

    isScheduled(callback: Function, target: cc.Class): boolean;

    /**
     * <p>
     *  Pause all selectors from all targets.<br/>
     *  You should NEVER call this method, unless you know what you are doing.
     * </p>
     */
    pauseAllTargets(): void;

    /**
     * Pause all selectors from all targets with a minimum priority. <br/>
     * You should only call this with kCCPriorityNonSystemMin or higher.
     * @param {Number} minPriority
     */
    pauseAllTargetsWithMinPriority(minPriority: number): void;

    /**
     * Resume selectors on a set of targets.<br/>
     * This can be useful for undoing a call to pauseAllCallbacks.
     * @param {Array} targetsToResume
     */
    resumeTargets(targetsToResume: cc.Class[]): void;

    /**
     * <p>
     *    Pauses the target.<br/>
     *    All scheduled selectors/update for a given target won't be 'ticked' until the target is resumed.<br/>
     *    If the target is not present, nothing happens.
     * </p>
     * @param {cc.Class} target
     */
    pauseTarget(target: cc.Class): void;

    /**
     * Resumes the target.<br/>
     * The 'target' will be unpaused, so all schedule selectors/update will be 'ticked' again.<br/>
     * If the target is not present, nothing happens.
     * @param {cc.Class} target
     */
    resumeTarget(target: cc.Class): void;

    /**
     * Returns whether or not the target is paused
     * @param {cc.Class} target
     * @return {Boolean}
     */
    isTargetPaused(target: cc.Class): boolean;

    /**
     * <p>
     *    Schedules the 'update' callback_fn for a given target with a given priority.<br/>
     *    The 'update' callback_fn will be called every frame.<br/>
     *    The lower the priority, the earlier it is called.
     * </p>
     * @deprecated since v3.4 please use .scheduleUpdate
     * @param {cc.Class} target
     * @param {Number} priority
     * @param {Boolean} paused
     * @example
     * //register this object to scheduler
     * cc.director.getScheduler().scheduleUpdateForTarget(this, priority, !this._isRunning );
     */
    scheduleUpdateForTarget(target: cc.Class, priority: number, paused: boolean): void;

    /**
     * <p>
     *   Unschedule a callback function for a given target.<br/>
     *   If you want to unschedule the "update", use unscheudleUpdateForTarget.
     * </p>
     * @deprecated since v3.4 please use .unschedule
     * @param {cc.Class} target
     * @param {function} callback callback[Function] or key[String]
     * @example
     * //unschedule a callback of target
     * cc.director.getScheduler().unscheduleCallbackForTarget(function, this);
     */
    unscheduleCallbackForTarget(target: cc.Class, callback: Function | string): void;

    /**
     * Unschedules the update callback function for a given target
     * @param {cc.Class} target
     * @deprecated since v3.4 please use .unschedule
     * @example
     * unschedules the "update" method.
     * cc.director.getScheduler().unscheduleUpdateForTarget(this);
     */
    unscheduleUpdateForTarget(target: cc.Class): void;

    /**
     * Unschedules all function callbacks for a given target. This also includes the "update" callback function.
     * @deprecated since v3.4 please use .unscheduleAll
     * @param {cc.Class} target
     */
    unscheduleAllCallbacksForTarget(target: cc.Class): void;

    /**
     *  <p>
     *      Unschedules all function callbacks from all targets. <br/>
     *      You should NEVER call this method, unless you know what you are doing.
     *  </p>
     * @deprecated since v3.4 please use .unscheduleAllWithMinPriority
     */
    unscheduleAllCallbacks(): void;

    /**
     * <p>
     *    Unschedules all function callbacks from all targets with a minimum priority.<br/>
     *    You should only call this with kCCPriorityNonSystemMin or higher.
     * </p>
     * @deprecated since v3.4 please use .unscheduleAllWithMinPriority
     * @param {Number} minPriority
     */
    unscheduleAllCallbacksWithMinPriority(minPriority: number): void;

    /**
     * Priority level reserved for system services.
     * @constant
     * @type Number
     */
    static readonly PRIORITY_SYSTEM: number;

    /**
     * Minimum priority level for user scheduling.
     * @constant
     * @type Number
     */
    static readonly PRIORITY_NON_SYSTEM: number;
  }
}
