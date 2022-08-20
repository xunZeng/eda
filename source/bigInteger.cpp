/********************************************************************************
  * @file       bigInteger.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-20
  * @brief      Big integer arithmetic.
  ******************************************************************************/

#include "bigInteger.h"
#include <iostream>
mb::bigInteger::bigInteger() {
}

mb::bigInteger::bigInteger(const bigInteger& num) : value_(num.value_), sign_(num.sign_) {
}

mb::bigInteger::bigInteger(const std::string& num) {
   init(num);
}

mb::bigInteger::bigInteger(const char* num) {
    std::string string_num = num;
    init(string_num);
}

mb::bigInteger::bigInteger(const int& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}

mb::bigInteger::bigInteger(const uInt& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}

mb::bigInteger::bigInteger(const long long& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}

mb::bigInteger::bigInteger(const float& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}

mb::bigInteger::bigInteger(const double& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}

mb::bigInteger::bigInteger(const long double& num) {
    auto string_num = std::to_string(num);
    init(string_num);
}
    
mb::bigInteger::~bigInteger() {
}

bool mb::bigInteger::isNegative(const std::string& num) {
    return *num.begin() == NEGATIVE_SIGN;
}

void mb::bigInteger::init(const std::string& num) {
    if(isNegative(num)) {
        this->sign_ = NEGATIVE;
        this->value_ = std::string(num.begin() + 1, num.end());
    }
    else {
        this->sign_ = POSITIVE;
        this->value_ = num;
    }
}

std::ostream& mb::operator<<(std::ostream& os, const mb::bigInteger& num) {
        if(num.sign_ == mb::NEGATIVE)
            os << NEGATIVE_SIGN << num.value_ ;
        else   
            os << num.value_ ; 
        return os;       
}

mb::bigInteger& mb::bigInteger::operator=(const bigInteger& num) {
    this->sign_ = num.sign_;
    this->value_ = num.value_;
    return *this;
}

