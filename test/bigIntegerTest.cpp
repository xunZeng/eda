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


/**
 * @brief bigInteger main function
 * 
 * @return int: return 0 if sucess
 */
int main() {
    // std::string t ="";
    // math::uInt half = t.size() / 2;
    // std::cout << t.substr(0, t.size() - half) <<std::endl;
    // std::cout << t.substr(t.size() - half) <<std::endl;
    // return 0;
    math::bigInteger a = -86578, b = 342, c = -111111;
    int i = 2;
    //c = (a*b);
    c *= a;
    auto d = a*b;
    std::cout << c << std::endl;
        std::cout << d << std::endl;

    return 0;
}

#endif