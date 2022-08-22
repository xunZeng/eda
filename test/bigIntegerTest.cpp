/********************************************************************************
  * @file       bigIntegerTest.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-22
  * @brief      Function test for bigInteger.cpp.
  ******************************************************************************/
#include "testDef.h"

#ifdef BIGINTEGER_TEST

#include <iostream>
#include "bigInteger.h"


/**
 * @brief bigInteger main function
 * 
 * @return int: return 0 if sucess
 */
int main() {
    math::bigInteger a = 10, b = -1, c = -1;
    math::bigInteger f = 0;
    math::bigInteger e;
    math::bigInteger d = e = 1;
    
    //std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f<< std::endl;
    std::cout << (b < c) << std::endl;
    return 0;
}

#endif