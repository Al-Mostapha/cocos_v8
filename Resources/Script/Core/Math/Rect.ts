namespace cc {
  const _reuse_size = { width: 0, height: 0 };
  const _reuse_rect = { x: 0, y: 0, width: 0, height: 0 };
  // //
  // // Basic structure : Size
  // //
  // cc.size = function (w, h) {
  //   return { width: w, height: h };
  // };
  export const size = (w: number, h: number) => ({ width: w, height: h });
  // cc._size = function (w, h) {
  //   cc._reuse_size.width = w;
  //   cc._reuse_size.height = h;
  //   return cc._reuse_size;
  // };
  export const _size = (w: number, h: number) => {
    _reuse_size.width = w;
    _reuse_size.height = h;
    return _reuse_size;
  };

  // cc.sizeEqualToSize = function (size1, size2) {
  //   return size1.width == size2.width && size1.height == size2.height;
  // };
  export const sizeEqualToSize = (size1: Size, size2: Size) =>
    size1.width == size2.width && size1.height == size2.height;
  // cc.SizeZero = function () {
  //   return cc.size(0, 0);
  // };
  export const SizeZero = () => size(0, 0);

  /**
   * create a cc.rect object
   * @param {Number|cc.point|cc.rect} [x] a Number value as x or a cc.point object as origin or a cc.rect clone object
   * @param {Number|cc.size} [y] x1 a Number value as y or a cc.size object as size
   * @param {Number} [w]
   * @param {Number} [h]
   * @return {Object} a cc.rect object
   */
  export interface Rect {
    x: number;
    y: number;
    width: number;
    height: number;
  }

  export function rect(
    x?: number | Rect | Point,
    y?: number | Size,
    w?: number,
    h?: number,
  ): Rect {
    const argLen = arguments.length;
    if (argLen === 0) return { x: 0, y: 0, width: 0, height: 0 };
    if (argLen === 1)
      return {
        x: (x as Rect).x,
        y: (x as Rect).y,
        width: (x as Rect).width,
        height: (x as Rect).height,
      };
    if (argLen === 2)
      return {
        x: (x as Point).x,
        y: (x as Point).y,
        width: (y as Size).width,
        height: (y as Size).height,
      };
    if (argLen === 4)
      return {
        x: x as number,
        y: y as number,
        width: w as number,
        height: h as number,
      };
    throw "unknown argument type";
  }

  // cc._rect = function (x, y, w, h) {
  //   cc._reuse_rect.x = x;
  //   cc._reuse_rect.y = y;
  //   cc._reuse_rect.width = w;
  //   cc._reuse_rect.height = h;
  //   return cc._reuse_rect;
  // };
  export const _rect = (x: number, y: number, w: number, h: number): Rect => {
    _reuse_rect.x = x;
    _reuse_rect.y = y;
    _reuse_rect.width = w;
    _reuse_rect.height = h;
    return _reuse_rect;
  };

  export function rectEqualToRect(rect1: Rect, rect2: Rect): boolean {
    return (
      rect1.x == rect2.x &&
      rect1.y == rect2.y &&
      rect1.width == rect2.width &&
      rect1.height == rect2.height
    );
  };

  export function rectContainsRect(rect1: Rect, rect2: Rect): boolean {
    if (
      rect1.x >= rect2.x ||
      rect1.y >= rect2.y ||
      rect1.x + rect1.width <= rect2.x + rect2.width ||
      rect1.y + rect1.height <= rect2.y + rect2.height
    )
      return false;
    return true;
  };
  export function rectGetMaxX(rect: Rect): number {
    return rect.x + rect.width;
  };
  export function rectGetMidX(rect: Rect): number {
    return rect.x + rect.width / 2.0;
  };
  export function rectGetMinX(rect: Rect): number {
    return rect.x;
  };
  export function rectGetMaxY(rect: Rect): number {
    return rect.y + rect.height;
  };
  export function rectGetMidY(rect: Rect): number {
    return rect.y + rect.height / 2.0;
  };
  export function rectGetMinY(rect: Rect): number {
    return rect.y;
  };

  export function rectContainsPoint(rect: Rect, point: Point): boolean {
    return (
      point.x >= rect.x &&
      point.x <= rect.x + rect.width &&
      point.y >= rect.y &&
      point.y <= rect.y + rect.height
    );
  };
  export function rectIntersectsRect(rectA: Rect, rectB: Rect): boolean {
    return !(
      rectA.x > rectB.x + rectB.width ||
      rectA.x + rectA.width < rectB.x ||
      rectA.y > rectB.y + rectB.height ||
      rectA.y + rectA.height < rectB.y
    );
  };
  export function rectOverlapsRect(rectA: Rect, rectB: Rect): boolean {
    return !(
      rectA.x + rectA.width < rectB.x ||
      rectB.x + rectB.width < rectA.x ||
      rectA.y + rectA.height < rectB.y ||
      rectB.y + rectB.height < rectA.y
    );
  };
  export function rectUnion(rectA: Rect, rectB: Rect): Rect {
    const lRect = rect(0, 0, 0, 0);
    lRect.x = Math.min(rectA.x, rectB.x);
    lRect.y = Math.min(rectA.y, rectB.y);
    lRect.width =
      Math.max(rectA.x + rectA.width, rectB.x + rectB.width) - lRect.x;
    lRect.height =
      Math.max(rectA.y + rectA.height, rectB.y + rectB.height) - lRect.y;
    return lRect;
  };

  export function rectIntersection(rectA: Rect, rectB: Rect): Rect {
    const intersection = rect(
      Math.max(rectA.x, rectB.x),
      Math.max(rectA.y, rectB.y),
      0,
      0,
    );
    intersection.width =
      Math.min(rectA.x + rectA.width, rectB.x + rectB.width) - intersection.x;
    intersection.height =
      Math.min(rectA.y + rectA.height, rectB.y + rectB.height) - intersection.y;
    return intersection;
  };

  export function RectZero(): Rect {
    return rect(0, 0, 0, 0);
  }

  //
  //AffineTransform API
  //

  /**
   * @memberOf cc
   * @function
   * @param {Number} a
   * @param {Number} b
   * @param {Number} c
   * @param {Number} d
   * @param {Number} tx
   * @param {Number} ty
   */
  export class AffineTransform {
    a: number;
    b: number;
    c: number;
    d: number;
    tx: number;
    ty: number;

    constructor(
      a: number,
      b: number,
      c: number,
      d: number,
      tx: number,
      ty: number,
    ) {
      this.a = a;
      this.b = b;
      this.c = c;
      this.d = d;
      this.tx = tx;
      this.ty = ty;
    }
  }

  /**
   * @memberOf cc
   * @function
   * @param {Number} a
   * @param {Number} b
   * @param {Number} c
   * @param {Number} d
   * @param {Number} tx
   * @param {Number} ty
   * @return {cc.AffineTransform}
   * Constructor
   */
  export function affineTransformMake(
    a: number,
    b: number,
    c: number,
    d: number,
    tx: number,
    ty: number,
  ): AffineTransform {
    return new AffineTransform(a, b, c, d, tx, ty);
  }

  /**
   * @memberOf cc
   * @function
   * @param {cc.Point} point
   * @param {cc.AffineTransform} t
   * @return {cc.Point}
   * Constructor
   */
  export const pointApplyAffineTransform = (
    point: Point,
    t: AffineTransform,
  ): Point => {
    return {
      x: t.a * point.x + t.c * point.y + t.tx,
      y: t.b * point.x + t.d * point.y + t.ty,
    };
  };

  export const _pointApplyAffineTransform = (
    x: number,
    y: number,
    t: AffineTransform,
  ): Point => {
    return { x: t.a * x + t.c * y + t.tx, y: t.b * x + t.d * y + t.ty };
  };

  /**
   * @memberOf cc
   * @function
   * @param {cc.Size} size
   * @param {cc.AffineTransform} t
   * @return {cc.Size}
   * Constructor
   */
  export const sizeApplyAffineTransform = (
    size: Size,
    t: AffineTransform,
  ): Size => {
    return {
      width: t.a * size.width + t.c * size.height,
      height: t.b * size.width + t.d * size.height,
    };
  };

  /**
   * @memberOf cc
   * @function
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformMakeIdentity = (): AffineTransform => {
    return { a: 1.0, b: 0.0, c: 0.0, d: 1.0, tx: 0.0, ty: 0.0 };
  };

  /**
   * @memberOf cc
   * @function
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformIdentity = (): AffineTransform => {
    return { a: 1.0, b: 0.0, c: 0.0, d: 1.0, tx: 0.0, ty: 0.0 };
  };

  /**
   * @memberOf cc
   * @function
   * @param {cc.Rect} rect
   * @param {cc.AffineTransform} anAffineTransform
   * @return {cc.Rect}
   * Constructor
   */
  export const rectApplyAffineTransform = (
    rect: Rect,
    anAffineTransform: AffineTransform,
  ): Rect => {
    const top = rect.y;
    const left = rect.x;
    const right = rect.x + rect.width;
    const bottom = rect.y + rect.height;

    const topLeft = cc._pointApplyAffineTransform(left, top, anAffineTransform);
    const topRight = cc._pointApplyAffineTransform(
      right,
      top,
      anAffineTransform,
    );
    const bottomLeft = cc._pointApplyAffineTransform(
      left,
      bottom,
      anAffineTransform,
    );
    const bottomRight = cc._pointApplyAffineTransform(
      right,
      bottom,
      anAffineTransform,
    );

    const minX = Math.min(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);
    const maxX = Math.max(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);
    const minY = Math.min(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);
    const maxY = Math.max(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);

    return cc.rect(minX, minY, maxX - minX, maxY - minY);
  };

  const _rectApplyAffineTransformIn = (
    rect: Rect,
    anAffineTransform: AffineTransform,
  ): Rect => {
    const top = cc.rectGetMinY(rect);
    const left = cc.rectGetMinX(rect);
    const right = cc.rectGetMaxX(rect);
    const bottom = cc.rectGetMaxY(rect);

    const topLeft = cc._pointApplyAffineTransform(left, top, anAffineTransform);
    const topRight = cc._pointApplyAffineTransform(
      right,
      top,
      anAffineTransform,
    );
    const bottomLeft = cc._pointApplyAffineTransform(
      left,
      bottom,
      anAffineTransform,
    );
    const bottomRight = cc._pointApplyAffineTransform(
      right,
      bottom,
      anAffineTransform,
    );

    const minX = Math.min(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);
    const maxX = Math.max(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);
    const minY = Math.min(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);
    const maxY = Math.max(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);

    rect.x = minX;
    rect.y = minY;
    rect.width = maxX - minX;
    rect.height = maxY - minY;
    return rect;
  };

  /**
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} t
   * @param {Number} tx
   * @param {Number}ty
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformTranslate = (
    t: AffineTransform,
    tx: number,
    ty: number,
  ): AffineTransform => {
    return {
      a: t.a,
      b: t.b,
      c: t.c,
      d: t.d,
      tx: t.tx + t.a * tx + t.c * ty,
      ty: t.ty + t.b * tx + t.d * ty,
    };
  };

  /**
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} t
   * @param {Number} sx
   * @param {Number} sy
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformScale = (
    t: AffineTransform,
    sx: number,
    sy: number,
  ): AffineTransform => {
    return {
      a: t.a * sx,
      b: t.b * sx,
      c: t.c * sy,
      d: t.d * sy,
      tx: t.tx,
      ty: t.ty,
    };
  };

  /**
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} aTransform
   * @param {Number} anAngle
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformRotate = (
    aTransform: AffineTransform,
    anAngle: number,
  ): AffineTransform => {
    const fSin = Math.sin(anAngle);
    const fCos = Math.cos(anAngle);

    return {
      a: aTransform.a * fCos + aTransform.c * fSin,
      b: aTransform.b * fCos + aTransform.d * fSin,
      c: aTransform.c * fCos - aTransform.a * fSin,
      d: aTransform.d * fCos - aTransform.b * fSin,
      tx: aTransform.tx,
      ty: aTransform.ty,
    };
  };

  /**
   * Concatenate `t2' to `t1' and return the result:<br/>
   * t' = t1 * t2
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} t1
   * @param {cc.AffineTransform} t2
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformConcat = (
    t1: AffineTransform,
    t2: AffineTransform,
  ): AffineTransform => {
    return {
      a: t1.a * t2.a + t1.b * t2.c, //a
      b: t1.a * t2.b + t1.b * t2.d, //b
      c: t1.c * t2.a + t1.d * t2.c, //c
      d: t1.c * t2.b + t1.d * t2.d, //d
      tx: t1.tx * t2.a + t1.ty * t2.c + t2.tx, //tx
      ty: t1.tx * t2.b + t1.ty * t2.d + t2.ty,
    }; //ty
  };

  /**
   * Concatenate a transform matrix to another<br/>
   * The results are reflected in the first matrix.<br/>
   * t' = t1 * t2
   * @function
   * @param {cc.AffineTransform} t1 The first transform object
   * @param {cc.AffineTransform} t2 The transform object to concatenate
   * @return {cc.AffineTransform} The result of concatenation
   */
  export const affineTransformConcatIn = (
    t1: AffineTransform,
    t2: AffineTransform,
  ): AffineTransform => {
    var a = t1.a,
      b = t1.b,
      c = t1.c,
      d = t1.d,
      tx = t1.tx,
      ty = t1.ty;
    t1.a = a * t2.a + b * t2.c;
    t1.b = a * t2.b + b * t2.d;
    t1.c = c * t2.a + d * t2.c;
    t1.d = c * t2.b + d * t2.d;
    t1.tx = tx * t2.a + ty * t2.c + t2.tx;
    t1.ty = tx * t2.b + ty * t2.d + t2.ty;
    return t1;
  };

  /**
   * Return true if `t1' and `t2' are equal, false otherwise.
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} t1
   * @param {cc.AffineTransform} t2
   * @return {Boolean}
   * Constructor
   */
  export const affineTransformEqualToTransform = (
    t1: AffineTransform,
    t2: AffineTransform,
  ): boolean => {
    return (
      t1.a === t2.a &&
      t1.b === t2.b &&
      t1.c === t2.c &&
      t1.d === t2.d &&
      t1.tx === t2.tx &&
      t1.ty === t2.ty
    );
  };

  /**
   * Get the invert value of an AffineTransform object
   * @memberOf cc
   * @function
   * @param {cc.AffineTransform} t
   * @return {cc.AffineTransform}
   * Constructor
   */
  export const affineTransformInvert = (
    t: AffineTransform,
  ): AffineTransform => {
    const determinant = 1 / (t.a * t.d - t.b * t.c);
    return {
      a: determinant * t.d,
      b: -determinant * t.b,
      c: -determinant * t.c,
      d: determinant * t.a,
      tx: determinant * (t.c * t.ty - t.d * t.tx),
      ty: determinant * (t.b * t.tx - t.a * t.ty),
    };
  };
}
