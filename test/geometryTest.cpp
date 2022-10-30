/********************************************************************************
  * @file       precisionMathTest.cpp
  * @author     Xun Zeng
  * @date       2022-09-17
  * @lastedit   2022-10-30
  * @brief      Function test for bigInteger.cpp.
  ******************************************************************************/
#include "testDef.h"

#ifdef GEOMETRY_TEST

#include <iostream>
#include "geometry.h"
// #include <boost/multiprecision/gmp.hpp>
// #include <boost/geometry.hpp>
#include <precisionMath.h>
template<typename T>
struct A {
    private:
    T x_;
    public:
    A(){}
    A(int x) : x_(x){}
    ~A(){}
    private:
    void setX(int x){x_ = x;}
    protected:
    void setXX(int x){x_ = x;}
    int getX(){return x_;}
};

template<typename T>
class B : public A<T> {
    using C = A<T>;
    public:
    B() : C(){}
    B(int x) : C(x){}
    void resetX(int x){C::setXX(x);}
    int getX(){return C::getX();}
    ~B(){}
};

class C {
    public:
    int x = 1;
    int z = 1;
    constexpr C() = default;
    C(int x_, int z_) : x(x_), z(z_) {}
    ~C() {}
};

class D : public C{
    public:
    int y = 1;
    D() :  y(0) {}
    ~D() {}
};

class E {
    public:
    int x = 1;
    int y = 1;
    constexpr E() = default;
    E(int x_, int y_) : x(x_), y(y_) {}
    ~E() {}
};
// using namespace boost::geometry;
// using namespace boost::multiprecision;
// using namespace math;
/*
 * @brief geometry main function
 * 
 * @return int: return 0 if sucess
 */
int main() {
    // geo::point_t p(2,1);
    // std::cout << p.x() << " " << p.y() << std::endl;
    // p.x(1);
    // p.y(2); 
    // std::cout << p.x() << " " << p.y() << std::endl;
    // geo::linesegment_t seg(p, p);
    // std::cout << seg.first.x() << " " << seg.second.x() << std::endl;
    geo::point_t p1(2.1, 2);
    std::cout << p1.x() << " " << p1.y() << std::endl;
    geo::point_t p2(-2, -4);
    
    // geo::linesegment_t seg{p1, p2};
    // std::cout << seg.second.x() << " " << seg.second.y() << std::endl;
    // geo::rect_t l2(p1, p2);
    // std::cout << l2.min_corner().x() << " " << l2.min_corner().y() << " " << l2.max_corner().x() << " " << l2.max_corner().y() << std::endl;
    // geo::rect_t r1;
    geo::lrect_t l1(p1, p2);
    std::cout << l1.lppair() << " " << l1.layerNum() << " " << l1.purposeNum() << std::endl;
    l1.lppair(100);
    std::cout << l1.lppair() << " " << l1.layerNum() << " " << l1.purposeNum() << std::endl;

    std::cout << l1.min_corner().x() << " " << l1.min_corner().y() << " " << l1.max_corner().x() << " " << l1.max_corner().y() << std::endl;
    geo::lrect_t l2(l1);
    std::cout << l2.lppair() << " " << l2.layerNum() << " " << l2.purposeNum() << std::endl;
    std::cout << l2.min_corner().x() << " " << l2.min_corner().y() << " " << l2.max_corner().x() << " " << l2.max_corner().y() << std::endl;
    geo::polygon_t pp1;
    geo::lpolygon_t lpp1(pp1);
    // p1.x(99);
    // p1.y(99);
    return 0;
}

#endif