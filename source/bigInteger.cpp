/********************************************************************************
  * @file       bigInteger.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-22
  * @brief      Big integer arithmetic.
  ******************************************************************************/

#include "bigInteger.h"
#include <iostream>

math::bigInteger::bigInteger() : sign_(IS_POSITIVE), value_(1, ZERO) {
}

math::bigInteger::bigInteger(const bigInteger& num) : sign_(num.sign_), value_(num.value_) {
}

math::bigInteger::bigInteger(const std::string& num) {
    init(num);      
}

math::bigInteger::bigInteger(const char* num) {
    std::string str_num = num;
    init(str_num); 
}

math::bigInteger::bigInteger(const int& num) {
    auto str_num = std::to_string(num);
    init(str_num); 
}

math::bigInteger::bigInteger(const uInt& num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(const long long& num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(const float& num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(const double& num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(const long double& num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}
    
math::bigInteger::~bigInteger() {
}

bool math::bigInteger::hasSign(const std::string& num) {
    return (*num.begin() == POSITIVE_SIGN) || (*num.begin() == NEGATIVE_SIGN);
}

bool math::bigInteger::isNegative(const std::string& num) {
    return *num.begin() == NEGATIVE_SIGN;
}

bool math::bigInteger::isDigit(const char& num) {
    return (MIN_DIGIT <= num) && (num <= MAX_DIGTI);
}

bool math::bigInteger::isLegal(const std::string& num) {
    if(!num.size()) { //check size
        std::cout << "Abnormal number of digits!" << std::endl;
        return false;
    }
    std::string check_num = hasSign(num) ? std::string(num.begin() + 1, num.end())
                                         : std::string(num.begin() + 0, num.end());
    if(!check_num.size()) { //check size
        std::cout << "Abnormal number of digits!" << std::endl;
        return false;
    }
    if((check_num.size() > 1) && (*check_num.begin() == ZERO)) { //check the first digit
        std::cout << "The leading position of a non-zero integer cannot be 0!" << std::endl;
        return false;
    }
    for(auto it = check_num.begin(); it != check_num.end(); it++) {
        if(!isDigit(*it)) {
            std::cout << "Integer must have all digits!" << std::endl;
            return false;
        }        
    }
    return true;
}

void math::bigInteger::init(const std::string& num) {
    if(!isLegal(num)) { 
        std::cout << "The Integer has been automatically set to 0!" << std::endl;
        this->sign_ = IS_POSITIVE;
        this->value_ = (1, ZERO);
        return;
    }
    if(isNegative(num)) {
        this->sign_ = IS_NEGATIVE;
        this->value_ = std::string(num.begin() + 1, num.end());
    }
    else {
        this->sign_ = IS_POSITIVE;
        this->value_ = num;
    }
}

std::ostream& math::operator<<(std::ostream& os, const math::bigInteger& num) {
    if(num.sign_ == math::IS_NEGATIVE) {
        os << NEGATIVE_SIGN << num.value_ ;
    }   
    else {
        os << num.value_ ; 
    }      
    return os;       
}

std::istream& math::operator>>(std::istream& is, math::bigInteger& num) {
    std::string str_num;
    is >> str_num;
    num.init(str_num);
    return is;    
}

math::bigInteger& math::bigInteger::operator=(const bigInteger& num) {
    this->sign_ = num.sign_;
    this->value_ = num.value_;
    return *this;
}

bool math::bigInteger::operator==(const bigInteger& num)  const {
    return (this->sign_ == num.sign_) && (this->value_ == num.value_);
}

bool math::bigInteger::operator!=(const bigInteger& num) const {
    return !(*this == num);
}

bool math::bigInteger::operator<(const bigInteger& num) const {
    if(this->sign_ != num.sign_) {
        return this->sign_;
    }
    if(this->value_.size() != num.value_.size()) {
        return (this->value_.size() > num.value_.size()) && (this->sign_);
    }
    for(auto i = 0; i < this->value_.size(); ++i) {
        if(this->value_.at(i) != num.value_.at(i)) {
            return this->value_.at(i) < num.value_.at(i);
        }
    }
    return false;
}

bool math::bigInteger::operator<=(const bigInteger& num) const {
    return (*this < num) || (*this == num);
}

bool math::bigInteger::operator>(const bigInteger& num) const {
    return !(*this <= num);
}

bool math::bigInteger::operator>=(const bigInteger& num) const {
    return !(*this < num);
}