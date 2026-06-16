/**
 * <p>
 *  cc.pool is a singleton object serves as an object cache pool.<br/>
 *  It can helps you to improve your game performance for objects which need frequent release and recreate operations<br/>
 *  Some common use case is :
 *      1. Bullets in game (die very soon, massive creation and recreation, no side effect on other objects)
 *      2. Blocks in candy crash (massive creation and recreation)
 *      etc...
 * </p>
 *
 * @example
 * var sp = new cc.Sprite("a.png");
 * this.addChild(sp);
 * cc.pool.putInPool(sp);
 *
 * cc.pool.getFromPool(cc.Sprite, "a.png");
 * @class
 * @name cc.pool
 */
namespace cc {
  export class pool {
    static _pool: Record<string, any[]> = {};

    private static _releaseCB() {
      // TODO
      // this.release();
    }

    private static _autoRelease(obj: any) {
      const running = obj._running === undefined ? false : !obj._running;
      cc.director
        .getScheduler()
        .scheduleCallbackForTarget(obj, this._releaseCB, 0, 0, 0, running);
    }

    /**
     * Put the obj in pool
     * @param obj
     */
    static putInPool(obj: any) {
      var pid = obj.constructor.prototype.__pid;
      if (!pid) {
        const desc = {
          writable: true,
          enumerable: false,
          configurable: true,
          value: 0,
        };
        desc.value = ClassManager.getNewID();
        Object.defineProperty(obj.constructor.prototype, "__pid", desc);
      }
      if (!this._pool[pid]) {
        this._pool[pid] = [];
      }
      // JSB retain to avoid being auto released
      obj.retain && obj.retain();
      // User implementation for disable the object
      obj.unuse && obj.unuse();
      this._pool[pid].push(obj);
    }

    /**
     * Check if this kind of obj has already in pool
     * @param objClass
     * @returns {boolean} if this kind of obj is already in pool return true,else return false;
     */
    static hasObject(objClass: any) {
      const pid = objClass.prototype.__pid;
      const list = this._pool[pid];
      if (!list || list.length == 0) {
        return false;
      }
      return true;
    }

    /**
     * Remove the obj if you want to delete it;
     * @param obj
     */
    static removeObject(obj: any) {
      const pid = obj.constructor.prototype.__pid;
      if (pid) {
        const list = this._pool[pid];
        if (list) {
          for (let i = 0; i < list.length; i++) {
            if (obj === list[i]) {
              // JSB release to avoid memory leak
              obj.release && obj.release();
              list.splice(i, 1);
            }
          }
        }
      }
    }

    /**
     * Get the obj from pool
     * @param args
     * @returns {*} call the reuse function an return the obj
     */
    static getFromPool(objClass: any /*,args*/) {
      if (this.hasObject(objClass)) {
        const pid = objClass.prototype.__pid;
        const list = this._pool[pid];
        const args = Array.prototype.slice.call(arguments);
        args.shift();
        const obj = list.pop();
        // User implementation for re-enable the object
        obj.reuse && obj.reuse.apply(obj, args);
        // JSB release to avoid memory leak
        cc.sys.isNative && obj.release && this._autoRelease(obj);
        return obj;
      }
    }

    /**
     *  remove all objs in pool and reset the pool
     */
    static drainAllPools() {
      for (const i in this._pool) {
        for (let j = 0; j < this._pool[i].length; j++) {
          const obj = this._pool[i][j];
          // JSB release to avoid memory leak
          obj.release && obj.release();
        }
      }
      this._pool = {};
    }
  }
}
