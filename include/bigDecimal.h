/********************************************************************************
  * @file    bigDecimal.h
  * @author  Xun Zeng
  * @date    2022/08/18
  * @brief   Floating point arithmetic for integrated circuit layouts.
  ******************************************************************************/

#ifndef _BIGDECIMAL_H_
#define _BIGDECIMAL_H_

#include <string>

class bigDecimal
{
private:
    /* data */
    std::string bigDecimal_;
public:
    bigDecimal(/* args */);
    ~bigDecimal();
};

bigDecimal::bigDecimal(/* args */)
{
}

bigDecimal::~bigDecimal()
{
}


#endif //_BIGDECIMAL_H_