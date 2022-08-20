/********************************************************************************
  * @file       bigDecimal.cpp
  * @author     Xun Zeng
  * @date       2022-08-18
  * @lastedit   2022-08-20
  * @brief      Floating point arithmetic for integrated circuit layouts.
  ******************************************************************************/

#include "bigDecimal.h"

/**
 * @brief global & static region
 * 
 */
db::uInt db::bigDecimal::scale_     = 0;
db::uInt db::bigDecimal::precision_ = 0;

db::bigDecimal::bigDecimal(){
}

db::bigDecimal::bigDecimal(const bigDecimal& num) : value_(num.value_){
}

db::bigDecimal::~bigDecimal(){
}
