/********************************************************************************
  * @file       bigIntegerTest.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-20
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
    //math::bigInteger i(std::string("10.034445"));
    auto  s = std::string("");
    //std::cout << s << std::endl;
    math::bigInteger j(s);
    math::bigInteger k(-109221);
    math::bigInteger kk;
    math::bigInteger l = kk = -102109412784012;
    
    //std::cout << j << std::endl;
    std::cout << j << "   " << k << std::endl;
    std::cout << l << "  " << kk << std::endl;
    std::cin >> j ;
    std::cout << j << std::endl;
    return 0;
}

#endif