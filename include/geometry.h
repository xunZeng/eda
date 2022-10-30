/********************************************************************************
  * @file       geometry.h
  * @author     Xun Zeng
  * @date       2022-10-21
  * @lastedit   2022-10-30
  * @brief      Polygon geometry operations supported by BOOST Geometry.
  ******************************************************************************/

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <boost/geometry.hpp>
#include <precisionMath.h>
/**
 * @brief geometry base
 * 
 */
namespace geo {

    using uint_t   = unsigned int;
    using lppair_t = uint64_t; // layer purpose pair type
    using lnum_t   = uint32_t; // layer num type
    using pnum_t   = uint32_t; // purpose num type

    namespace bm = boost::multiprecision;
    namespace bg = boost::geometry;

    typedef bg::model::d2::point_xy<math::pint_t> point_t;
    typedef bg::model::d2::point_xy<math::pint_t> offset_t;
    typedef bg::model::segment<point_t>           linesegment_t;
    typedef bg::model::linestring<point_t>        linestring_t;
    typedef bg::model::box<point_t>               rect_t;
    typedef bg::model::polygon<point_t>           polygon_t;

    /**
     * @brief layer rect class
     * 
     */
    class lrect_t : public rect_t {
        private:
            lppair_t lppair_;
        public:
            lrect_t();
            lrect_t(const point_t& min_corner, const point_t& max_corner);
            lrect_t(const point_t& min_corner,
                    const point_t& max_corner,
                    lppair_t lppair);
            lrect_t(const point_t& min_corner,
                    const point_t& max_corner,
                    lnum_t layer_num,
                    pnum_t purpose_num);
            ~lrect_t();
        public:
            lnum_t layerNum() const;
            pnum_t purposeNum() const;
            lppair_t lppair() const;
            void layerNum(lnum_t layer_num);
            void purposeNum(pnum_t purpose_num);
            void lppair(lppair_t lppair);
            void lppair(lnum_t layer_num, pnum_t purpose_num);
    };
    
    /**
     * @brief layer polygon class
     * 
     */
    class lpolygon_t : public lrect_t {
        private:
            polygon_t polygon_;
        public:
            lpolygon_t();
            lpolygon_t(polygon_t polygon);
            ~lpolygon_t();
    };
}

#endif // _GEOMETRY_H_