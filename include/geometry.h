/********************************************************************************
  * @file       geometry.h
  * @author     Xun Zeng
  * @date       2022-10-21
  * @lastedit   2022-10-21
  * @brief      Polygon geometry operations supported by BOOST Geometry.
  ******************************************************************************/

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <boost/geometry.hpp>
#include "precisionMath.h"

/**
 * @brief geometry base
 * 
 */
namespace geo {
    using uint_t = unsigned int;
    namespace bg = boost::geometry;
    typedef bg::model::d2::point_xy<math::pfloat_t> point_t;
    typedef bg::model::segment<point_t>             linesegment_t;
    typedef bg::model::linestring<point_t>          linestring_t;
    typedef bg::model::box<point_t>                 rect_t;
    typedef bg::model::polygon<point_t>             polygon_t;

    class layer_t : public rect_t {
        private:
            uint64_t layer_;
        public:
            layer_t();
            ~layer_t();
        public:
            uint32_t layerNum() const;
            uint32_t layerType() const;
            void layerNum(uint32_t layer_num);
            void layerNum(uint32_t layer_num);
    };
    
    class polygonlayer_t : public layer_t {
        private:
            polygon_t polygon_;
        public:
            polygonlayer_t();
            ~polygonlayer_t();
    };
}

#endif // _GEOMETRY_H_