// //
// // DrawNode JS API Wrapper
// //

// cc.cardinalSplineAt = function (p0, p1, p2, p3, tension, t) {
//   var t2 = t * t;
//   var t3 = t2 * t;

//   var s = (1 - tension) / 2;

//   var b1 = s * (-t3 + 2 * t2 - t); // s(-t3 + 2 t2 - t)P1
//   var b2 = s * (-t3 + t2) + (2 * t3 - 3 * t2 + 1); // s(-t3 + t2)P2 + (2 t3 - 3 t2 + 1)P2
//   var b3 = s * (t3 - 2 * t2 + t) + (-2 * t3 + 3 * t2); // s(t3 - 2 t2 + t)P3 + (-2 t3 + 3 t2)P3
//   var b4 = s * (t3 - t2); // s(t3 - t2)P4

//   var x = p0.x * b1 + p1.x * b2 + p2.x * b3 + p3.x * b4;
//   var y = p0.y * b1 + p1.y * b2 + p2.y * b3 + p3.y * b4;
//   return cc.p(x, y);
// };

// cc._DrawNode = cc.DrawNode;
// cc._DrawNode.prototype.drawPoly = function (
//   verts,
//   fillColor,
//   borderWidth,
//   borderColor,
// ) {
//   cc._DrawNode.prototype.drawPolygon.call(
//     this,
//     verts,
//     verts.length,
//     fillColor,
//     borderWidth,
//     borderColor,
//   );
// };
// cc.DrawNode = cc._DrawNode.extend({
//   _drawColor: cc.color(255, 255, 255, 255),
//   _lineWidth: 1,

//   release: function () {},

//   setLineWidth: function (width) {
//     this._lineWidth = width;
//   },

//   getLineWidth: function () {
//     return this._lineWidth;
//   },

//   setDrawColor: function (color) {
//     var locDrawColor = this._drawColor;
//     locDrawColor.r = color.r;
//     locDrawColor.g = color.g;
//     locDrawColor.b = color.b;
//     locDrawColor.a = color.a == null ? 255 : color.a;
//   },

//   getDrawColor: function () {
//     return cc.color(
//       this._drawColor.r,
//       this._drawColor.g,
//       this._drawColor.b,
//       this._drawColor.a,
//     );
//   },

//   drawRect: function (origin, destination, fillColor, lineWidth, lineColor) {
//     lineWidth = lineWidth || this._lineWidth;
//     lineColor = lineColor || this._drawColor;
//     var points = [
//       origin,
//       cc.p(origin.x, destination.y),
//       destination,
//       cc.p(destination.x, origin.y),
//     ];
//     if (fillColor)
//       cc._DrawNode.prototype.drawPoly.call(
//         this,
//         points,
//         fillColor,
//         lineWidth,
//         lineColor,
//       );
//     else {
//       points.push(origin);
//       var drawSeg = cc._DrawNode.prototype.drawSegment;
//       for (var i = 0, len = points.length; i < len - 1; i++)
//         drawSeg.call(this, points[i], points[i + 1], lineWidth, lineColor);
//     }
//   },

//   drawCircle: function (
//     center,
//     radius,
//     angle,
//     segments,
//     drawLineToCenter,
//     lineWidth,
//     color,
//   ) {
//     lineWidth = lineWidth || this._lineWidth;
//     color = color || this._drawColor;
//     if (color.a == null) color.a = 255;
//     var coef = (2.0 * Math.PI) / segments,
//       vertices = [],
//       i,
//       len;
//     for (i = 0; i <= segments; i++) {
//       var rads = i * coef;
//       var j = radius * Math.cos(rads + angle) + center.x;
//       var k = radius * Math.sin(rads + angle) + center.y;
//       vertices.push(cc.p(j, k));
//     }
//     if (drawLineToCenter) vertices.push(cc.p(center.x, center.y));

//     lineWidth *= 0.5;
//     var drawSeg = cc._DrawNode.prototype.drawSegment;
//     for (i = 0, len = vertices.length; i < len - 1; i++)
//       drawSeg.call(this, vertices[i], vertices[i + 1], lineWidth, color);
//   },

//   drawQuadBezier: function (
//     origin,
//     control,
//     destination,
//     segments,
//     lineWidth,
//     color,
//   ) {
//     lineWidth = lineWidth || this._lineWidth;
//     color = color || this._drawColor;
//     cc._DrawNode.prototype.drawQuadBezier.call(
//       this,
//       origin,
//       control,
//       destination,
//       segments,
//       color,
//     );
//   },

//   drawCubicBezier: function (
//     origin,
//     control1,
//     control2,
//     destination,
//     segments,
//     lineWidth,
//     color,
//   ) {
//     lineWidth = lineWidth || this._lineWidth;
//     color = color || this._drawColor;
//     cc._DrawNode.prototype.drawCubicBezier.call(
//       this,
//       origin,
//       control1,
//       control2,
//       destination,
//       segments,
//       color,
//     );
//   },

//   drawCatmullRom: function (points, segments, lineWidth, color) {
//     this.drawCardinalSpline(points, 0.5, segments, lineWidth, color);
//   },

//   drawCardinalSpline: function (config, tension, segments, lineWidth, color) {
//     lineWidth = lineWidth || this._lineWidth;
//     color = color || this._drawColor;
//     if (color.a == null) color.a = 255;
//     var vertices = [],
//       p,
//       lt,
//       deltaT = 1.0 / config.length,
//       m1len = config.length - 1;

//     for (var i = 0; i < segments + 1; i++) {
//       var dt = i / segments;

//       // border
//       if (dt == 1) {
//         p = m1len;
//         lt = 1;
//       } else {
//         p = 0 | (dt / deltaT);
//         lt = (dt - deltaT * p) / deltaT;
//       }

//       // Interpolate
//       var newPos = cc.cardinalSplineAt(
//         config[Math.min(m1len, Math.max(p - 1, 0))],
//         config[Math.min(m1len, Math.max(p + 0, 0))],
//         config[Math.min(m1len, Math.max(p + 1, 0))],
//         config[Math.min(m1len, Math.max(p + 2, 0))],
//         tension,
//         lt,
//       );
//       vertices.push(newPos);
//     }

//     lineWidth *= 0.5;
//     var drawSeg = cc._DrawNode.prototype.drawSegment;
//     for (var j = 0, len = vertices.length; j < len - 1; j++)
//       drawSeg.call(this, vertices[j], vertices[j + 1], lineWidth, color);
//   },

//   drawDot: function (pos, radius, color) {
//     color = color || this._drawColor;
//     cc._DrawNode.prototype.drawDot.call(this, pos, radius, color);
//   },

//   drawSegment: function (
//     from,
//     to,
//     lineWidth = this._lineWidth,
//     color = this._drawColor,
//   ) {
//     cc._DrawNode.prototype.drawSegment.call(this, from, to, lineWidth, color);
//   },

//   drawPoly: function (verts, fillColor, borderWidth, borderColor) {
//     borderColor = borderColor || this._drawColor;
//     if (fillColor)
//       cc._DrawNode.prototype.drawPoly.call(
//         this,
//         verts,
//         fillColor,
//         borderWidth,
//         borderColor,
//       );
//     else {
//       verts.push(verts[0]);
//       var drawSeg = cc._DrawNode.prototype.drawSegment;
//       for (var i = 0, len = verts.length; i < len - 1; i++)
//         drawSeg.call(this, verts[i], verts[i + 1], borderWidth, borderColor);
//     }
//   },
// });
// cc.DrawNode.create = function () {
//   return new cc.DrawNode();
// };
