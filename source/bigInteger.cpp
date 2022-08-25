/********************************************************************************
  * @file       bigInteger.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-25
  * @brief      Big integer arithmetic.
  ******************************************************************************/

#include "bigInteger.h"
#include <iostream>
#include <algorithm>

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

math::bigInteger::bigInteger(int num) {
    auto str_num = std::to_string(num);
    init(str_num); 
}

math::bigInteger::bigInteger(uInt num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(long long num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(float num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(double num) {
    auto str_num = std::to_string(num);
    init(str_num);  
}

math::bigInteger::bigInteger(long double num) {
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
            std::cout << "Each digit of the integer must be a decimal digit!" << std::endl;
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

bool math::bigInteger::isSmaller(const std::string& num_a, const std::string& num_b) {
    if(num_a.size() != num_b.size()) {
        return (num_a.size() < num_b.size());
    }
    for(auto i = 0; i < num_a.size(); ++i) {
        if(num_a.at(i) != num_b.at(i)) {
            return num_a.at(i) < num_b.at(i);
        }
    }
    return false;
}

std::string math::bigInteger::safeAdd(const std::string& num_a, const std::string& num_b) {
    std::string sum = "";  
    sum.reserve(std::max(num_a.size(), num_b.size())); //reserve memory
    uInt carry = 0;
    for(auto it_a = num_a.rbegin(), it_b = num_b.rbegin(); 
             it_a != num_a.rend() || it_b != num_b.rend();) {
        carry += ((it_a != num_a.rend() ? (*it_a - ZERO) : 0)
                + (it_b != num_b.rend() ? (*it_b - ZERO) : 0));
        sum.push_back((carry % 10) + ZERO);
        carry /= 10;
        if(it_a != num_a.rend()) {
            it_a++;
        }
        if(it_b != num_b.rend()) {
            it_b++;
        }
    }
    if(carry) { //the final carry
        sum.push_back((carry % 10) + ZERO);
    }
    std::reverse(sum.begin(), sum.end());
    return sum;
}

std::string math::bigInteger::safeSubtract(const std::string& num_a, const std::string& num_b) {
    if(isSmaller(num_a, num_b)) {
        return safeSubtract(num_b, num_a);
    }
    std::string dif = "";  
    dif.reserve(std::max(num_a.size(), num_b.size())); //reserve memory
    uInt borrow = 0;
    for(auto it_a = num_a.rbegin(), it_b = num_b.rbegin(); 
             it_a != num_a.rend() || it_b != num_b.rend();) {
        if(it_b != num_b.rend()) {
            if(*it_a < (*it_b + borrow)) {
                dif.push_back(10 + *it_a - *it_b + ZERO - borrow);
                borrow = 1;
            }
            else {
                dif.push_back(*it_a - *it_b + ZERO - borrow);
                borrow = 0;
            }
        }
        else {
            if(*it_a < (ZERO + borrow)) {
                dif.push_back(10 + *it_a - borrow);
                borrow = 1;
            }
            else {
                dif.push_back(*it_a - borrow);
                borrow = 0;
            }
        }
        if(it_a != num_a.rend()) {
            it_a++;
        }
        if(it_b != num_b.rend()) {
            it_b++;
        }
    }
    std::reverse(dif.begin(), dif.end());
    auto it = dif.begin();
    while(it != dif.end() && *it == ZERO) {
        it++;
    }
    return std::string(it, dif.end());
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

math::bigInteger math::bigInteger::operator+(const bigInteger& num) {
    bigInteger sum;
    switch ((this->sign_ << 1) | num.sign_) {
    case (IS_POSITIVE << 1) | IS_POSITIVE:
        sum.sign_ = IS_POSITIVE;
        sum.value_ = safeAdd(this->value_, num.value_);   
        break;
    case (IS_POSITIVE << 1) | IS_NEGATIVE:
        sum.sign_ = isSmaller(this->value_, num.value_) ? IS_NEGATIVE : IS_POSITIVE; 
        sum.value_ = safeSubtract(this->value_, num.value_);
        break;
    case (IS_NEGATIVE << 1) | IS_POSITIVE:
        sum.sign_ = isSmaller(num.value_, this->value_) ? IS_NEGATIVE : IS_POSITIVE;
        sum.value_ = safeSubtract(this->value_, num.value_);
        break;
    case (IS_NEGATIVE << 1) | IS_NEGATIVE:
        sum.sign_ = IS_NEGATIVE;
        sum.value_ = safeAdd(this->value_, num.value_);
        break;
    default:
        std::cout << "Wrong number sign to be added!" << std::endl;
        break;
    }
    return sum;
}

math::bigInteger math::bigInteger::operator-(const bigInteger& num) {
    bigInteger dif;
    switch ((this->sign_ << 1) | num.sign_) {
    case (IS_POSITIVE << 1) | IS_POSITIVE:
        dif.sign_ = isSmaller(this->value_, num.value_) ? IS_NEGATIVE : IS_POSITIVE;
        dif.value_ = safeSubtract(this->value_, num.value_); 
        break;
    case (IS_POSITIVE << 1) | IS_NEGATIVE:
        dif.sign_ = IS_POSITIVE;
        dif.value_ = safeAdd(this->value_, num.value_);
        break;
    case (IS_NEGATIVE << 1) | IS_POSITIVE:
        dif.sign_ = IS_NEGATIVE;
        dif.value_ = safeAdd(this->value_, num.value_);
        break;
    case (IS_NEGATIVE << 1) | IS_NEGATIVE:
        dif.sign_ = isSmaller(num.value_, this->value_) ? IS_NEGATIVE : IS_POSITIVE;
        dif.value_ = safeSubtract(this->value_, num.value_);
        break;
    default:
        std::cout << "Wrong number sign to be subtracted!" << std::endl;
        break;
    }
    return dif;
}

math::bigInteger math::bigInteger::operator-() {
    bigInteger temp(*this);
    temp.sign_ = !temp.sign_;
    return temp;
}

math::bigInteger& math::bigInteger::operator++() {
    return *this += static_cast<bigInteger>(1);
}

math::bigInteger& math::bigInteger::operator--() {
    
    return *this -= static_cast<bigInteger>(1);
}

math::bigInteger math::bigInteger::operator++(int num) {
    bigInteger temp(*this);
    *this += num ? static_cast<bigInteger>(num) : static_cast<bigInteger>(1);
    return temp;
}

math::bigInteger math::bigInteger::operator--(int num) {
    bigInteger temp(*this);
    *this -= num ? static_cast<bigInteger>(num) : static_cast<bigInteger>(1);
    return temp;
}

math::bigInteger& math::bigInteger::operator+=(const bigInteger& num) {
    return *this = *this + num;
}

math::bigInteger& math::bigInteger::operator-=(const bigInteger& num) {
    auto i = *this - num;
    return *this = (*this - num);
}