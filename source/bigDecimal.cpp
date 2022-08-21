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
math::uInt math::bigDecimal::scale_     = 0;
math::uInt math::bigDecimal::precision_ = 0;

math::bigDecimal::bigDecimal() {
}

math::bigDecimal::bigDecimal(const bigDecimal& num) : value_(num.value_) {
}

math::bigDecimal::~bigDecimal() {
}
