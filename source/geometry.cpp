/********************************************************************************
  * @file       geometry.h
  * @author     Xun Zeng
  * @date       2022-10-21
  * @lastedit   2022-10-30
  * @brief      Polygon geometry operations supported by BOOST Geometry.
  ******************************************************************************/

#include <geometry.h>

geo::lppair_t makeLPPair(geo::lnum_t layer_num, geo::pnum_t purpose_num) {
    return (static_cast<geo::lppair_t>(layer_num) << 32) | static_cast<geo::lppair_t>(purpose_num);
}

geo::lnum_t getLayerNum(geo::lppair_t lppair) {
    return static_cast<geo::lnum_t>(lppair >> 32);
}

geo::pnum_t getPurposeNum(geo::lppair_t lppair) {
    return static_cast<geo::pnum_t>(lppair);
}

void setLayerNum(geo::lppair_t& lppair, geo::lnum_t layer_num) {
    lppair |= (static_cast<geo::lppair_t>(layer_num) << 32);
}

void setPurposeNum(geo::lppair_t& lppair, geo::pnum_t purpose_num) {
    lppair |= static_cast<geo::lppair_t>(purpose_num);
}


geo::lrect_t::lrect_t() : lppair_(static_cast<lppair_t>(0)) {
}

geo::lrect_t::lrect_t(const point_t& min_corner, const point_t& max_corner)
    : rect_t(min_corner, max_corner), lppair_(static_cast<lppair_t>(0)) {
}

geo::lrect_t::lrect_t(const point_t& min_corner,
                      const point_t& max_corner,
                      lppair_t lppair)
    : rect_t(min_corner, max_corner), lppair_(lppair){
}

geo::lrect_t::lrect_t(const point_t& min_corner,
                      const point_t& max_corner,
                      lnum_t layer_num,
                      pnum_t purpose_num)
    : rect_t(min_corner, max_corner) {
    lppair(layer_num, purpose_num);
}

geo::lrect_t::~lrect_t() {
}

geo::lnum_t
geo::lrect_t::layerNum() const {
    return getLayerNum(lppair_ >> 32);
}

geo::pnum_t
geo::lrect_t::purposeNum() const {
    return getPurposeNum(lppair_);
}

geo::lppair_t
geo::lrect_t::lppair() const {
    return lppair_;
}

void
geo::lrect_t::layerNum(lnum_t layer_num) {
    setLayerNum(lppair_, layer_num);
}

void
geo::lrect_t::purposeNum(pnum_t purpose_num) {
    setPurposeNum(lppair_, purpose_num);
}

void
geo::lrect_t::lppair(lppair_t lppair) {
    lppair_ = lppair;
}

void
geo::lrect_t::lppair(lnum_t layer_num, pnum_t purpose_num) {
    lppair_ = makeLPPair(layer_num, purpose_num);
}

geo::lpolygon_t::lpolygon_t() {
}

geo::lpolygon_t::lpolygon_t(polygon_t polygon)
    : polygon_(polygon) {
}

geo::lpolygon_t::~lpolygon_t() {
}