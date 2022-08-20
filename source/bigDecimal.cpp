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
mb::uInt mb::bigDecimal::scale_     = 0;
mb::uInt mb::bigDecimal::precision_ = 0;

mb::bigDecimal::bigDecimal() {
}

mb::bigDecimal::bigDecimal(const bigDecimal& num) : value_(num.value_) {
}

mb::bigDecimal::~bigDecimal() {
}
