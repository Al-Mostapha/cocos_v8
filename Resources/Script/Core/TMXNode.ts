// //
// // TMX classes JS API Wrapper
// //

// cc.TMXTiledMap.prototype.allLayers = function () {
//   var retArr = [],
//     locChildren = this.getChildren(),
//     length = locChildren.length;
//   for (var i = 0; i < length; i++) {
//     var layer = locChildren[i];
//     if (layer && layer instanceof cc.TMXLayer) retArr.push(layer);
//   }
//   return retArr;
// };
// cc.TMXLayer.prototype._getTileAt = cc.TMXLayer.prototype.getTileAt;
// cc.TMXLayer.prototype.getTileAt = function (x, y) {
//   var pos = y !== undefined ? cc.p(x, y) : x;
//   return this._getTileAt(pos);
// };
// cc.TMXLayer.prototype._getTileGIDAt = cc.TMXLayer.prototype.getTileGIDAt;
// cc.TMXLayer.prototype.getTileGIDAt = function (x, y) {
//   var pos = y !== undefined ? cc.p(x, y) : x;
//   return this._getTileGIDAt(pos);
// };
// cc.TMXLayer.prototype._setTileGID = cc.TMXLayer.prototype.setTileGID;
// cc.TMXLayer.prototype.setTileGID = function (gid, posOrX, flagsOrY, flags) {
//   var pos;
//   if (flags !== undefined) {
//     pos = cc.p(posOrX, flagsOrY);
//     this._setTileGID(gid, pos, flags);
//   } else if (flagsOrY != undefined) {
//     pos = posOrX;
//     flags = flagsOrY;
//     this._setTileGID(gid, pos, flags);
//   } else {
//     this._setTileGID(gid, posOrX);
//   }
// };
// cc.TMXLayer.prototype._removeTileAt = cc.TMXLayer.prototype.removeTileAt;
// cc.TMXLayer.prototype.removeTileAt = function (x, y) {
//   var pos = y !== undefined ? cc.p(x, y) : x;
//   this._removeTileAt(pos);
// };
// cc.TMXLayer.prototype._getPositionAt = cc.TMXLayer.prototype.getPositonAt;
// cc.TMXLayer.prototype.getPositonAt = function (x, y) {
//   var pos = y !== undefined ? cc.p(x, y) : x;
//   return this._getPositionAt(pos);
// };
