/********************************************************************************
  * @file       query.h
  * @author     Xun Zeng
  * @date       2022-10-30
  * @lastedit   2022-10-30
  * @brief      spatial query supported by BOOST Geometry.
  ******************************************************************************/

 #include <geometry.h>
 #include <boost/geometry/index/rtree.hpp>
 #include <map>

 namespace query {
    namespace bgi = boost::geometry::index;
    using uint_t = unsigned int;
    using id_t = uint_t;
    typedef std::pair<geo::lrect_t, id_t> value_t;
    typedef bgi::rtree<value_t, bgi::rstar<4>> rtree;

    class dataBase {

        private:
            std::map<geo::lnum_t, rtree*> database_;

        public:
            void layerCount(geo::lnum_t layer_count);
            geo::lnum_t layerCount();
            void init(geo::lnum_t begin_num, geo::lnum_t end_num);
            void insert(geo::lnum_t layer_num, rtree* tree);
    };
 }
