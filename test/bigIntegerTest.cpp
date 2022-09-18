/********************************************************************************
  * @file       bigIntegerTest.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-25
  * @brief      Function test for bigInteger.cpp.
  ******************************************************************************/
#include "testDef.h"

#ifdef BIGINTEGER_TEST

#include <iostream>
#include "bigInteger.h"
#include "gmp.h"
#include "precisionFloat.h"


/**
 * @brief bigInteger main function
 * 
 * @return int: return 0 if sucess
 */
int main() {
    mpf_t x,y,z;
    mpf_init2(x, 3);
    mpf_init2(y, 3);
    mpf_init2(z, 1);
    mpf_set_str(x, "24124.5555555555", 10);
    mpf_set_str(y, "2", 10);
    mpf_mul(z,x,y);
    gmp_printf("x = %Ff\n", x); 
    gmp_printf("y = %Ff\n", y); 
    gmp_printf("z = %Ff\n", z); 
    mpf_clear(x);
    mpf_clear(y);
    mpf_clear(z);
    // return 0;
    // std::string t ="";
    // math::uInt half = t.size() / 2;
    // std::cout << t.substr(0, t.size() - half) <<std::endl;
    // std::cout << t.substr(t.size() - half) <<std::endl;
    // return 0;
    math::bigInteger a = -86578, b = 1, c = -111111;
    int i = 2;
    //c = (a*b);
    c = b / a;
    //auto d = a*b;
    std::cout << c << std::endl;
    //std::cout << d << std::endl;

    return 0;
}

#endif