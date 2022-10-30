/********************************************************************************
  * @file       precisionMathTest.cpp
  * @author     Xun Zeng
  * @date       2022-09-17
  * @lastedit   2022-09-18
  * @brief      Function test for bigInteger.cpp.
  ******************************************************************************/
#include "testDef.h"

#ifdef PRECISION_MATH_TEST

#include <iostream>
// #include "gmp.h"
// #include "gmpxx.h"
#include "precisionMath.h"

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
    C() : x(1) {}
};

class D : public C{
    public:
    int y = 1;
    D() :  y(0) {}
};


/*
 * @brief precisionMath main function
 * 
 * @return int: return 0 if sucess
 */
int main() {
    math::pmath_t a = 123456; 
    math::pmath_t b = 123456;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << (a * b / 1000000) << std::endl;
    // system("pause");
    // math::pfloat_t d(1);
    // mpf_class a = 1.511;
    // double t = 1.5;
    // mpf_class b = -2;
    // math::pFloat c(1);
    
    // --d;
    // std::cout << d << std::endl;
    // typedef mpf_class pfloat;
    // math::pFloat f = 12.123;
    // std::cout << (-d) <<std::endl;
    // auto d = -c;
    // d += 1;
    // mp_exp_t tt = 1000;
    // auto out = a.get_d();
    // std::string out = "hello";
    // std::cout << (a / -2) << std::endl;
    //gmp_printf("x = %Ff\n", mpf_class(b)); 
    //std::cout << b;
    //mpf_class c = a/b;
    //gmp_printf("x = %Ff\n", b); 
    
    return 0;
    // mpf_t x,y,z;
    // mpf_init_set_str(x, "24124.5555555555", 10);
    // mpf_init_set_str(y, "2", 10);
    // mpf_init(z);
    // mpf_mul(z,x,y);
    // gmp_printf("x = %Ff\n", x); 
    // gmp_printf("y = %Ff\n", y); 
    // gmp_printf("z = %Ff\n", z); 
    // mpf_clear(x);
    // mpf_clear(y);
    // mpf_clear(z);

    return 0;
}

#endif