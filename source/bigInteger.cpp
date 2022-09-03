/********************************************************************************
  * @file       bigInteger.cpp
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-28
  * @brief      Big integer arithmetic.
  ******************************************************************************/

#include "bigInteger.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

bool 
math::bigInteger::hasSign(const std::string& num) {
    return (*num.begin() == POSITIVE_SIGN) || (*num.begin() == NEGATIVE_SIGN);
}

bool 
math::bigInteger::isNegative(const std::string& num) {
    return *num.begin() == NEGATIVE_SIGN;
}

bool 
math::bigInteger::isDigit(const char& num) {
    return (MIN_DIGIT <= num) && (num <= MAX_DIGTI);
}

bool 
math::bigInteger::isLegal(const std::string& num) {
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

void 
math::bigInteger::init(const std::string& num) {
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

bool 
math::bigInteger::isSmaller(const std::string& num_a, const std::string& num_b) {
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

std::string 
math::bigInteger::safeAdd(const std::string& num_a, const std::string& num_b) {
    //time complexity: O(max(num_a.size(), num_b.size()))
    //space complexity: O(1)
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

std::string 
math::bigInteger::unsafeSubtract(std::string num_a, std::string num_b) {
    //Algorithmic Time Complexity: O(max(num_a.size(), num_b.size()))
    //Algorithmic Space Complexity: O(1)
    int carrier = 0;
    int bitresult = 0;
    std::string fullResult;
    std::string finalResult;
    makeEqualSize(num_a,num_b);
    for(int i =0; i < num_a.size(); i++){
        bitresult = num_a[num_a.size()-i-1] -  num_b[num_b.size()-i-1] - carrier;
        carrier = 0;
        if(bitresult < 0){
            carrier = 1;
            bitresult = bitresult + 10;
        }
        fullResult.push_back(bitresult+ZERO);
    }
    for(int i = 0; i < fullResult.size(); i++){
        finalResult.push_back(fullResult[fullResult.size()-i-1]);
    }
    //finalResult.push_back('\0');
    int pos = finalResult.find_first_not_of(ZERO);
    if(pos!=std::string::npos)finalResult = finalResult.substr(pos, finalResult.size()-pos);
    else finalResult = "0";
    return finalResult;   
}

std::string 
math::bigInteger::safeSubtract(std::string num_a, std::string num_b) {   
    //time complexity: O(max(num_a.size(), num_b.size()))
    //space complexity: O(1)
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
    auto it_first_not_zero = dif.begin() + dif.find_first_not_of(ZERO);
    return std::string(it_first_not_zero, dif.end());
}

size_t 
math::bigInteger::makeEqualSize(std::string& num_a, std::string& num_b) {
    for(auto it_a = num_a.rbegin(), it_b = num_b.rbegin();
             it_a != num_a.rend() || it_b != num_b.rend();) {
        if(it_a == num_a.rend() && it_b != num_b.rend()) {
            num_a = ZERO + num_a;
        }
        else if(it_a != num_a.rend() && it_b == num_b.rend()) {
            num_b = ZERO + num_b;
        }
        if(it_a != num_a.rend()) {
            it_a++;
        }
        if(it_b != num_b.rend()) {
            it_b++;
        }
    }
    return num_a.size();
}

bool 
math::bigInteger::isEqual(const std::string& num_a, char num_b) {
    return num_a.size() == 1 && num_a.at(0) == num_b;
}

bool 
math::bigInteger::isEqual(const std::string& num_a, const std::string& num_b) {
    if(num_a.size() != num_b.size()) {
        return false;
    }
    for(auto it_a = num_a.begin(), it_b = num_b.begin();
             it_a != num_a.end() && it_b != num_b.end();
             it_a++, it_b++) {
        if(*it_a != *it_b) {
            return false;
        }
    }
    return true;
}

std::string 
math::bigInteger::multiply(std::string num_a, std::string num_b) {
    // Algorithmic Time Complexity : O(num_a.size() * num_b.size())
    // Algorithmic Space Complexity : O(num_a.size() + num_b.size())
    if(isEqual(num_a, ZERO) || isEqual(num_b, ZERO)) {
        return "0";//std::to_string(ZERO);
    }
    auto size_a = num_a.size(),
         size_b = num_b.size();
    auto ans_arr = std::vector<uInt>(size_a + size_b);
    for (int i = size_a - 1; i >= 0; --i) {
        uInt x = num_a.at(i) - ZERO;
        for (int j = size_b - 1; j >= 0; --j) {
            uInt y = num_b.at(j) - ZERO;
            ans_arr[i + j + 1] += x * y;
        }
    }
    for (auto i = size_a + size_b - 1; i > 0; --i) {
        ans_arr[i - 1] += ans_arr[i] / 10;
        ans_arr[i] %= 10;
    }
    uInt index = ans_arr.at(0) == 0 ? 1 : 0;
    std::string product;
    while (index < size_a + size_b) {
        product.push_back(ans_arr[index] + ZERO);
        index++;
    }
    return product; 
}
 
std::string 
math::bigInteger::karatsubaMultiply(std::string num_a, std::string num_b) {
    // fall back to traditional multiplication
    if(num_a.size() == 1 || num_b.size() ==1){
    return multiply(num_a, num_b);
    }
    // make same size
    auto size = makeEqualSize(num_a,num_b);
    auto half = ((size + 1) / 2);  
    // split num into left and rigth parts
    std::string a = num_a.substr(0, half);
    std::string b = num_a.substr(half);
    std::string c = num_b.substr(0, half);
    std::string d = num_b.substr(half);
    // caluate
    // p1 = a * c
    // p2 = b * d
    // p3 = (a + b) * (c + d)
    // temp = (p3 - p1 -2)
    std::string p1 = karatsubaMultiply(a,c);
    std::string p2 = karatsubaMultiply(b,d);
    std::string p3 = karatsubaMultiply(safeAdd(a,b),safeAdd(c,d));
    std::string temp = unsafeSubtract(p3, safeAdd(p1,p2));
    // product = p1 * 2^(32*2*half) + (p3 - p1 - p2) * 2^(32*half) + p2
    //         = p1 + temp + p2
    for(int i = 0; i < size / 2 * 2; i++){
        p1 = p1 + ZERO;
        if(i < size / 2) {
            temp = temp + ZERO;     
        }
    }
    auto prodruct =  safeAdd(safeAdd(p1,temp),p2);
    auto pos = prodruct.find_first_not_of(ZERO);
    return prodruct.substr(pos == std::string::npos ? 0 : pos);
}

std::string
math::bigInteger::max(const std::string& num_a, const std::string& num_b) {
    return isSmaller(num_a, num_b) ? num_b : num_a;
}

bool
math::bigInteger::is_strictlyMaximum(std::string str1, std::string str2) {    //checks if str1 > str2, numerically
    if(str1 == str2)
        return false;
    if(str1 == max(str1, str2))
        return true;
    return false;
}

std::string
math::bigInteger::pow(std::string str1, std::string str2) {                  // returns str1^str2, ^ -> power, numerically
    if(str2 == "0") {
        return "1";
    } else if(str1 == "0") {
        if(str2[0] == '-')
            return std::to_string((long long int)std::pow(0, -5));
        return "0";
    } else if(str1[0] == '-' && str2[0] == '-') {
        if(str1 == "-1" && str2 == "-1") {
            return "-1";
        } else if(str1 == "-1") {
            if((((int)str2[str2.length()-1])-48) & 1) {                
                return "-1";
            } else {
                return "1";
            }
        } else {
            return "0";
        }
    } else if(str1[0] == '-') {
        if((((int)str2[str2.length()-1])-48) & 1)
            return '-' + pow(str1.erase(0, 1), str2);
        return pow(str1.erase(0, 1), str2);
    } else if(str2[0] == '-') {
        if(str1 == "1") {
            return str1;
        } else {
            return "0";
        }
    } else {
        std::string init_str1 = str1;
        while(str2 != "1") {
            str1 = multiply(str1, init_str1);
            str2 = safeSubtract(str2, "1");
        }
        return str1;
    }
}

std::string
math::bigInteger::safeDiveide(std::string num_a, std::string num_b) {
     std::string ans = "";
    if(num_b == "0") {
        return "0";
    } else if(num_a == num_b) {
        return "1";
    } else if(num_a[0] == '-' && num_b[0] == '-') {
        ans = safeDiveide(num_a.erase(0, 1), num_b.erase(0, 1));
    } else if(num_a[0] == '-') {
        std::string temp = safeDiveide(num_a.erase(0, 1), num_b);
        if(temp == "0")
            ans = temp;
        else
            ans = '-' + temp;        
    } else if(num_b[0] == '-') {
        std::string temp = safeDiveide(num_a, num_b.erase(0, 1));
        if(temp == "0")
            ans = temp;
        else
            ans = '-' + temp; 
    } else { 
        if(num_b == "1")
            return num_a;
        if(is_strictlyMaximum(num_b, num_a)) {
            return "0";
        }
        // if(num_b.length() <= 19) {
        //     std::stringstream strstrm(num_b);
        //     unsigned long long int int_str2 = 0;
        //     strstrm >> int_str2;
        //     ans = shortDivide(num_a, int_str2);
        // }
        // else {
            std::string temp = num_b;
            ans = "0";
            std::string count = "0";
            while(num_a == max(num_a, num_b)) {
                int lenDiff = num_a.length() - num_b.length();
                if(lenDiff > 0 && num_a[0] > num_b[0]) {
                    count = safeAdd(count, pow("10", std::to_string(lenDiff)));
                    num_a = safeSubtract(num_a, multiply(num_b, pow("10", std::to_string(lenDiff))));
                } else if(lenDiff > 0) {
                    count = safeAdd(count, pow("10", std::to_string(lenDiff-1)));
                    num_a = safeSubtract(num_a, multiply(num_b, pow("10", std::to_string(lenDiff-1))));
                } else {
                    count = safeAdd(count, "1");
                    num_a = safeSubtract(num_a, num_b);
                }
            // }
            ans = count;
        }
    }
    return ans;
}

std::ostream& 
math::operator<<(std::ostream& os, const math::bigInteger& num) {
    if(num.sign_ == math::IS_NEGATIVE) {
        os << NEGATIVE_SIGN << num.value_ ;
    }   
    else {
        os << num.value_ ; 
    }      
    return os;       
}

std::istream& 
math::operator>>(std::istream& is, math::bigInteger& num) {
    std::string str_num;
    is >> str_num;
    num.init(str_num);
    return is;    
}

math::bigInteger& 
math::bigInteger::operator=(const bigInteger& num) {
    this->sign_ = num.sign_;
    this->value_ = num.value_;
    return *this;
}

bool 
math::bigInteger::operator==(const bigInteger& num)  const {
    return (this->sign_ == num.sign_) && (this->value_ == num.value_);
}

bool 
math::bigInteger::operator!=(const bigInteger& num) const {
    return !(*this == num);
}

bool 
math::bigInteger::operator<(const bigInteger& num) const {
    if(this->sign_ != num.sign_) {
        return this->sign_;
    }
    if(this->value_.size() != num.value_.size()) {
        return (this->value_.size() < num.value_.size()) && (!this->sign_);
    }
    for(auto it_a = this->value_.begin(), it_b = num.value_.begin();
             it_a != this->value_.end() && it_b != num.value_.end();
                                                     it_a++, it_b++) {
        if(*it_a != *it_b) {
            return *it_a < *it_b;
        }
    }
    return false;
}

bool 
math::bigInteger::operator<=(const bigInteger& num) const {
    return (*this < num) || (*this == num);
}

bool 
math::bigInteger::operator>(const bigInteger& num) const {
    return !(*this <= num);
}

bool 
math::bigInteger::operator>=(const bigInteger& num) const {
    return !(*this < num);
}

math::bigInteger 
math::bigInteger::operator+(const bigInteger& num) {
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

math::bigInteger 
math::bigInteger::operator-(const bigInteger& num) {
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

math::bigInteger 
math::bigInteger::operator-() {
    bigInteger temp(*this);
    temp.sign_ = !temp.sign_;
    return temp;
}

math::bigInteger& 
math::bigInteger::operator++() {
    return *this += static_cast<bigInteger>(1);
}

math::bigInteger& 
math::bigInteger::operator--() {
    return *this -= static_cast<bigInteger>(1);
}

math::bigInteger 
math::bigInteger::operator++(int num) {
    bigInteger temp(*this);
    *this += num ? static_cast<bigInteger>(num) : static_cast<bigInteger>(1);
    return temp;
}

math::bigInteger 
math::bigInteger::operator--(int num) {
    bigInteger temp(*this);
    *this -= num ? static_cast<bigInteger>(num) : static_cast<bigInteger>(1);
    return temp;
}

math::bigInteger& 
math::bigInteger::operator+=(const bigInteger& num) {
    return *this = *this + num;
}

math::bigInteger& 
math::bigInteger::operator-=(const bigInteger& num) {
    auto i = *this - num;
    return *this = (*this - num);
}

math::bigInteger 
math::bigInteger::operator*(const bigInteger& num) {
    //choose multiplication algorithm
    std::string (*multiply_fun)(std::string num_a, std::string num_b);
    multiply_fun = (this->value_.size() < KARATSUBA_THRESHOLD 
                 || num.value_.size() < KARATSUBA_THRESHOLD) 
                 ? multiply 
                 : karatsubaMultiply;
    bigInteger product;
    product.sign_ = this->sign_ == num.sign_ 
                  ? IS_POSITIVE : IS_NEGATIVE;
    product.value_ = multiply_fun(this->value_, num.value_);
    return product;
}   

math::bigInteger& 
math::bigInteger::operator*=(const bigInteger& num) {
    return *this = *this * num;
}

math::bigInteger 
math::bigInteger::operator/(const bigInteger& num) {
    bigInteger quotient;
    quotient.sign_ = this->sign_ == num.sign_ 
                  ? IS_POSITIVE : IS_NEGATIVE;
    quotient.value_ = safeDiveide(this->value_, num.value_);
    return quotient;
}   