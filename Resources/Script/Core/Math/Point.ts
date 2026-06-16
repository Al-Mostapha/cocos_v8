namespace cc {
  /**
   * Calculates dot product of two points.
   * @param {cc.Point} v1
   * @param {cc.Point} v2
   * @return {Number}
   */
  export const pDot = (v1: cc.Point, v2: cc.Point): number => {
    return v1.x * v2.x + v1.y * v2.y;
  };

  export const POINT_EPSILON = 1.192092896e-7;
  /**
   * normalizes the point (inplace)
   */
  export const pNormalizeIn = (v: cc.Point) => {
    pMultIn(v, 1.0 / Math.sqrt(v.x * v.x + v.y * v.y));
  };
  // Basic structure : Point
  //
  // cc.p = function (x, y) {
  //   if (x == undefined) return { x: 0, y: 0 };
  //   if (y == undefined) return { x: x.x, y: x.y };
  //   return { x: x, y: y };
  // };
  export const p = (x?: number | cc.Point, y?: number) => {
    if (x == undefined) return { x: 0, y: 0 };
    if (y == undefined) return { x: (x as cc.Point).x, y: (x as cc.Point).y };
    return { x: x as number, y: y };
  };
  // cc._p = function (x, y) {
  //   if (cc._reuse_p_index == cc._reuse_p.length) cc._reuse_p_index = 0;

  //   var p = cc._reuse_p[cc._reuse_p_index];
  //   cc._reuse_p_index++;
  //   p.x = x;
  //   p.y = y;
  //   return p;
  // };

  export const pointEqualToPoint = function (
    point1: cc.Point,
    point2: cc.Point,
  ) {
    return point1.x == point2.x && point1.y == point2.y;
  };

  // cc.PointZero = function () {
  //   return cc.p(0, 0);
  // };
  export const PointZero = () => {
    return cc.p(0, 0);
  };

  /**
   * Unrotates two points.
   * @param  {cc.Point} v1
   * @param  {cc.Point} v2
   * @return {cc.Point}
   */
  export const pUnrotate = (v1: cc.Point, v2: cc.Point) => {
    return cc.p(v1.x * v2.x + v1.y * v2.y, v1.y * v2.x - v1.x * v2.y);
  };

  /**
   * Converts radians to a normalized vector.
   * @param {Number} a
   * @return {cc.Point}
   */
  export const pForAngle = function (a: number) {
    return cc.p(Math.cos(a), Math.sin(a));
  };

  /**
   * Converts a vector to radians.
   * @param {cc.Point} v
   * @return {Number}
   */
  // cc.pToAngle = function (v) {
  //   return Math.atan2(v.y, v.x);
  // };
  export const pToAngle = (v: cc.Point) => {
    return Math.atan2(v.y, v.x);
  };
  /**
   * Quickly convert cc.Size to a cc.Point
   * @param {cc.Size} s
   * @return {cc.Point}
   */
  export const pFromSize = (s: cc.Size) => {
    return cc.p(s.width, s.height);
  };

  /**
   * Run a math operation function on each point component <br />
   * Math.abs, Math.floor, Math.ceil, Math.round.
   * @param {cc.Point} p
   * @param {Function} opFunc
   * @return {cc.Point}
   * @example
   * //For example: let's try to take the floor of x,y
   * var p = cc.pCompOp(cc.p(10,10),Math.abs);
   */
  export const pCompOp = function (p: cc.Point, opFunc: (n: number) => number) {
    return cc.p(opFunc(p.x), opFunc(p.y));
  };

  /**
   * Linear Interpolation between two points a and b
   * alpha == 0 ? a
   * alpha == 1 ? b
   * otherwise a value between a..b
   * @param {cc.Point} a
   * @param {cc.Point} b
   * @param {Number} alpha
   * @return {cc.Point}
   */
  export const pLerp = (a: cc.Point, b: cc.Point, alpha: number) => {
    return cc.pAdd(cc.pMult(a, 1 - alpha), cc.pMult(b, alpha));
  };

  /**
   * @param {cc.Point} a
   * @param {cc.Point} b
   * @param {Number} variance
   * @return {Boolean} if points have fuzzy equality which means equal with some degree of variance.
   */
  export const pFuzzyEqual = (a: cc.Point, b: cc.Point, variance: number) => {
    if (a.x - variance <= b.x && b.x <= a.x + variance) {
      if (a.y - variance <= b.y && b.y <= a.y + variance) return true;
    }
    return false;
  };

  /**
   * Multiplies a nd b components, a.x*b.x, a.y*b.y
   * @param {cc.Point} a
   * @param {cc.Point} b
   * @return {cc.Point}
   */
  export const pCompMult = (a: cc.Point, b: cc.Point) => {
    return cc.p(a.x * b.x, a.y * b.y);
  };

  /**
   * @param {cc.Point} a
   * @param {cc.Point} b
   * @return {Number} the signed angle in radians between two vector directions
   */
  export const pAngleSigned = (a: cc.Point, b: cc.Point) => {
    const a2 = cc.pNormalize(a);
    const b2 = cc.pNormalize(b);
    const angle = Math.atan2(a2.x * b2.y - a2.y * b2.x, cc.pDot(a2, b2));
    if (Math.abs(angle) < POINT_EPSILON) return 0.0;
    return angle;
  };

  /**
   * @param {cc.Point} a
   * @param {cc.Point} b
   * @return {Number} the angle in radians between two vector directions
   */
  export const pAngle = (a: cc.Point, b: cc.Point) => {
    const angle = Math.acos(cc.pDot(cc.pNormalize(a), cc.pNormalize(b)));
    if (Math.abs(angle) < POINT_EPSILON) return 0.0;
    return angle;
  };

  /**
   * Rotates a point counter clockwise by the angle around a pivot
   * @param {cc.Point} v v is the point to rotate
   * @param {cc.Point} pivot pivot is the pivot, naturally
   * @param {Number} angle angle is the angle of rotation cw in radians
   * @return {cc.Point} the rotated point
   */
  export const pRotateByAngle = (
    v: cc.Point,
    pivot: cc.Point,
    angle: number,
  ) => {
    var r = cc.pSub(v, pivot);
    var cosa = Math.cos(angle),
      sina = Math.sin(angle);
    var t = r.x;
    r.x = t * cosa - r.y * sina + pivot.x;
    r.y = t * sina + r.y * cosa + pivot.y;
    return r;
  };

  /**
   * A general line-line intersection test
   * @param {cc.Point} A A is the startpoint for the first line P1 = (p1 - p2).
   * @param {cc.Point} B B is the endpoint for the first line P1 = (p1 - p2).
   * @param {cc.Point} C C is the startpoint for the second line P2 = (p3 - p4).
   * @param {cc.Point} D D is the endpoint for the second line P2 = (p3 - p4).
   * @param {cc.Point} retP retP.x is the range for a hitpoint in P1 (pa = p1 + s*(p2 - p1)), <br />
   * retP.y is the range for a hitpoint in P3 (pa = p2 + t*(p4 - p3)).
   * @return {Boolean}
   * indicating successful intersection of a line<br />
   * note that to truly test intersection for segments we have to make<br />
   * sure that s & t lie within [0..1] and for rays, make sure s & t > 0<br />
   * the hit point is        p3 + t * (p4 - p3);<br />
   * the hit point also is    p1 + s * (p2 - p1);
   */
  export const pLineIntersect = (
    A: cc.Point,
    B: cc.Point,
    C: cc.Point,
    D: cc.Point,
    retP: cc.Point,
  ) => {
    if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y)) {
      return false;
    }
    const BAx = B.x - A.x;
    const BAy = B.y - A.y;
    const DCx = D.x - C.x;
    const DCy = D.y - C.y;
    const ACx = A.x - C.x;
    const ACy = A.y - C.y;

    const denom = DCy * BAx - DCx * BAy;

    retP.x = DCx * ACy - DCy * ACx;
    retP.y = BAx * ACy - BAy * ACx;

    if (denom == 0) {
      if (retP.x == 0 || retP.y == 0) {
        // Lines incident
        return true;
      }
      // Lines parallel and not incident
      return false;
    }

    retP.x = retP.x / denom;
    retP.y = retP.y / denom;

    return true;
  };

  /**
   * ccpSegmentIntersect return YES if Segment A-B intersects with segment C-D.
   * @param {cc.Point} A
   * @param {cc.Point} B
   * @param {cc.Point} C
   * @param {cc.Point} D
   * @return {Boolean}
   */
  export const pSegmentIntersect = (
    A: cc.Point,
    B: cc.Point,
    C: cc.Point,
    D: cc.Point,
  ) => {
    var retP = cc.p(0, 0);
    if (cc.pLineIntersect(A, B, C, D, retP))
      if (retP.x >= 0.0 && retP.x <= 1.0 && retP.y >= 0.0 && retP.y <= 1.0)
        return true;
    return false;
  };

  /**
   * ccpIntersectPoint return the intersection point of line A-B, C-D
   * @param {cc.Point} A
   * @param {cc.Point} B
   * @param {cc.Point} C
   * @param {cc.Point} D
   * @return {cc.Point}
   */
  export const pIntersectPoint = (
    A: cc.Point,
    B: cc.Point,
    C: cc.Point,
    D: cc.Point,
  ) => {
    const retP = cc.p(0, 0);

    if (cc.pLineIntersect(A, B, C, D, retP)) {
      // Point of intersection
      const P = cc.p(0, 0);
      P.x = A.x + retP.x * (B.x - A.x);
      P.y = A.y + retP.x * (B.y - A.y);
      return P;
    }

    return cc.p(0, 0);
  };

  /**
   * check to see if both points are equal
   * @param {cc.Point} A A ccp a
   * @param {cc.Point} B B ccp b to be compared
   * @return {Boolean} the true if both ccp are same
   */
  export const pSameAs = (A: cc.Point, B: cc.Point) => {
    if (A != null && B != null) {
      return A.x == B.x && A.y == B.y;
    }
    return false;
  };

  /**
   * sets the position of the point to 0
   */
  export const pZeroIn = (v: cc.Point) => {
    v.x = 0;
    v.y = 0;
  };

  /**
   * copies the position of one point to another
   */
  export const pIn = (v1: cc.Point, v2: cc.Point) => {
    v1.x = v2.x;
    v1.y = v2.y;
  };

  /**
   * multiplies the point with the given factor (inplace)
   */
  export const pMultIn = (point: cc.Point, floatVar: number) => {
    point.x *= floatVar;
    point.y *= floatVar;
  };

  /**
   * subtracts one point from another (inplace)
   */
  export const pSubIn = (v1: cc.Point, v2: cc.Point) => {
    v1.x -= v2.x;
    v1.y -= v2.y;
  };

  /**
   * adds one point to another (inplace)
   */
  export const pAddIn = (v1: cc.Point, v2: cc.Point) => {
    v1.x += v2.x;
    v1.y += v2.y;
  };
}
