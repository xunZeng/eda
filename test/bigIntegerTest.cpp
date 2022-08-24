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
    math::bigInteger a = 10, b = 111123, c = 111111;
    a = b - c;
    std::cout << a << std::endl;
    return 0;
}

#endif