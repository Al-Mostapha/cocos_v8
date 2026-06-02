/// <reference path="Utils.ts" />
namespace cc {
  //+++++++++++++++++++++++++something about async begin+++++++++++++++++++++++++++++++
  /**
   * Async Pool class, a helper of cc.async
   * @param {Object|Array} srcObj
   * @param {Number} limit the limit of parallel number
   * @param {function} iterator
   * @param {function} onEnd
   * @param {object} target
   * @constructor
   */
  export class AsyncPool {
    //   cc.AsyncPool = function (srcObj, limit, iterator, onEnd, target) {
    //     self._srcObj = srcObj;
    _srcObj: any;
    //     self._limit = limit;
    _limit!: number;
    //     self._pool = [];
    _pool!: {
      index: number;
      value: any;
    }[];
    //     self._iterator = iterator;
    _iterator!: Function;
    //     self._iteratorTarget = target;
    _iteratorTarget!: any;
    //     self._onEnd = onEnd;
    _onEnd!: Function;
    //     self._onEndTarget = target;
    _onEndTarget!: any;
    //     self._results = srcObj instanceof Array ? [] : {};
    _results!: any;
    //     self._isErr = false;
    _isErr!: boolean;
    //     self.size = self._pool.length;
    size!: number;
    //     self.finishedSize = 0;
    finishedSize!: number;
    //     self._workingSize = 0;
    _workingSize!: number;
    //     self._limit = self._limit || self.size;

    constructor(
      srcObj: any,
      limit: number,
      iterator: Function,
      onEnd: Function,
      target?: any,
    ) {
      //     var self = this;
      const self = this;
      //     self._srcObj = srcObj;
      this._srcObj = srcObj;
      //     self._limit = limit;
      this._limit = limit;
      //     self._pool = [];
      this._pool = [];
      //     self._iterator = iterator;
      this._iterator = iterator;
      //     self._iteratorTarget = target;
      this._iteratorTarget = target;
      //     self._onEnd = onEnd;
      this._onEnd = onEnd;
      //     self._onEndTarget = target;
      this._onEndTarget = target;
      //     self._results = srcObj instanceof Array ? [] : {};
      this._results = srcObj instanceof Array ? [] : {};
      //     self._isErr = false;
      this._isErr = false;
      //     cc.each(srcObj, function (value, index) {
      //       self._pool.push({ index: index, value: value });
      //     });
      cc.each(srcObj, (value: any, index: number) => {
        this._pool.push({ index: index, value: value });
      });
      //     self.size = self._pool.length;
      this.size = this._pool.length;
      //     self.finishedSize = 0;
      this.finishedSize = 0;
      //     self._workingSize = 0;
      this._workingSize = 0;
      //     self._limit = self._limit || self.size;
      this._limit = this._limit ?? this.size;
    }

    onIterator(iterator: Function, target: any) {
      this._iterator = iterator;
      this._iteratorTarget = target;
    }

    onEnd(endCb: Function, endCbTarget: any) {
      this._onEnd = endCb;
      this._onEndTarget = endCbTarget;
    }

    _handleItem() {
      //       var self = this;
      //       if (self._pool.length == 0) return; //return directly if the array's length = 0
      if (this._pool.length == 0) {
        console.warn("AsyncPool: _handleItem failed, pool is empty!");
        return;
      }
      //       if (self._workingSize >= self._limit) return; //return directly if the working size great equal limit number
      if (this._workingSize >= this._limit) {
        console.warn("AsyncPool: _handleItem failed, workingSize >= limit!");
        return;
      }
      //       var item = self._pool.shift();
      const lItem = this._pool.shift()!;
      //       var value = item.value,
      //         index = item.index;
      const lValue = lItem.value;
      const lIndex = lItem.index;
      const lSelf = this;
      //       self._workingSize++;
      this._workingSize++;
      //       self._iterator.call(
      //         self._iteratorTarget,
      //         value,
      //         index,
      this._iterator?.(this._iteratorTarget, lValue, lIndex, (err: any) => {
        //           if (self._isErr) return;
        if (lSelf._isErr) return;
        //           self.finishedSize++;
        lSelf.finishedSize++;
        //           self._workingSize--;
        lSelf._workingSize--;
        //           if (err) {
        //             self._isErr = true;
        //             if (self._onEnd) self._onEnd.call(self._onEndTarget, err);
        //             return;
        //           }
        if (err) {
          lSelf._isErr = true;
          lSelf._onEnd?.(lSelf._onEndTarget, err);
        }
        //           var arr = Array.prototype.slice.call(arguments, 1);
        const lArr = Array.prototype.slice.call(arguments, 1);
        //           self._results[this.index] = arr[0];
        lSelf._results[lItem.index] = lArr[0];
        //           if (self.finishedSize === self.size) {
        //             if (self._onEnd)
        //               self._onEnd.call(self._onEndTarget, null, self._results);
        //             return;
        //           }
        if (lSelf.finishedSize === lSelf.size) {
          lSelf._onEnd?.(lSelf._onEndTarget, null, lSelf._results);
          return;
        }
        //           self._handleItem();
        lSelf._handleItem();
      });
      //         function (err) {

      //         }.bind(item),
      //         self,
      //       );
    }

    flow() {
      //       var self = this;

      //       if (self._pool.length === 0) {
      //         if (self._onEnd) self._onEnd.call(self._onEndTarget, null, []);
      //         return;
      //       }
      if (this._pool.length === 0) {
        this._onEnd?.(this._onEndTarget, null, []);
      }
      //       for (var i = 0; i < self._limit; i++) self._handleItem();
      for (var i = 0; i < this._limit; i++) this._handleItem();
    }
  }

  /**
   * @class
   */
  export class async /** @lends cc.async# */ {
    /**
     * Do tasks series.
     * @param {Array|Object} tasks
     * @param {function} [cb] callback
     * @param {Object} [target]
     * @return {cc.AsyncPool}
     */
    static series(tasks: Array<any> | Object, cb: Function, target: any) {
      var asyncPool = new cc.AsyncPool(
        tasks,
        1,
        function (func: Function, index: number, cb1: Function) {
          func.call(target, cb1);
        },
        cb,
        target,
      );
      asyncPool.flow();
      return asyncPool;
    }

    /**
     * Do tasks parallel.
     * @param {Array|Object} tasks
     * @param {function} cb callback
     * @param {Object} [target]
     * @return {cc.AsyncPool}
     */
    static parallel(tasks: Array<any> | Object, cb: Function, target: any) {
      var asyncPool = new cc.AsyncPool(
        tasks,
        0,
        function (func: Function, index: number, cb1: Function) {
          func.call(target, cb1);
        },
        cb,
        target,
      );
      asyncPool.flow();
      return asyncPool;
    }

    /**
     * Do tasks waterfall.
     * @param {Array|Object} tasks
     * @param {function} cb callback
     * @param {Object} [target]
     * @return {cc.AsyncPool}
     */
    static waterfall(tasks: Array<any> | Object, cb: Function, target: any) {
      var args: any[] = [];
      var lastResults = [null]; //the array to store the last results
      var asyncPool = new cc.AsyncPool(
        tasks,
        1,
        function (func: Function, index: number, cb1: Function) {
          args.push(function (err: Error | null) {
            args = Array.prototype.slice.call(arguments, 1);
            if ((tasks as any).length - 1 === index)
              lastResults = lastResults.concat(args); //while the last task
            cb1.apply(null, arguments);
          });
          func.apply(target, args);
        },
        function (err: Error | null) {
          if (!cb) return;
          if (err) return cb.call(target, err);
          cb.apply(target, lastResults);
        },
      );
      asyncPool.flow();
      return asyncPool;
    }

    /**
     * Do tasks by iterator.
     * @param {Array|Object} tasks
     * @param {function|Object} iterator
     * @param {function} [callback]
     * @param {Object} [target]
     * @return {cc.AsyncPool}
     */
    static map(
      tasks: Array<any> | Object,
      iterator:
        | Function
        | {
            cb: Function;
            iteratorTarget: any;
            iterator: Function;
          },
      callback: Function,
      target: any,
    ) {
      let locIterator;

      if (iterator instanceof Function) {
        locIterator = iterator;
      } else {
        callback = iterator.cb;
        target = iterator.iteratorTarget;
        locIterator = iterator.iterator;
      }

      const asyncPool = new cc.AsyncPool(
        tasks,
        0,
        locIterator,
        callback,
        target,
      );
      asyncPool.flow();
      return asyncPool;
    }

    /**
     * Do tasks by iterator limit.
     * @param {Array|Object} tasks
     * @param {Number} limit
     * @param {function} iterator
     * @param {function} cb callback
     * @param {Object} [target]
     */
    static mapLimit(
      tasks: Array<any> | Object,
      limit: number,
      iterator: Function,
      cb: Function,
      target: any,
    ) {
      const asyncPool = new cc.AsyncPool(tasks, limit, iterator, cb, target);
      asyncPool.flow();
      return asyncPool;
    }
  }
}
