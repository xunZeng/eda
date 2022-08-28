/********************************************************************************
  * @file       bigInteger.h
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-28
  * @brief      Big integer arithmetic.
  ******************************************************************************/

#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_

#include <iostream>
#include <string>

/**
 * @brief math base
 * 
 */
namespace math {  
    /**
     * @brief redefine type
     * 
     */
    using uInt = unsigned int;

    /**
     * @brief macro definition
     * 
     */
    constexpr char POSITIVE_SIGN = 0X2B;
    constexpr char NEGATIVE_SIGN = 0X2D;
    constexpr bool IS_POSITIVE  = false;
    constexpr bool IS_NEGATIVE   = true;

    constexpr char ZERO  = 0X30;
    constexpr char ONE   = 0X31;
    constexpr char TWO   = 0X32;
    constexpr char THREE = 0X33;
    constexpr char FOUR  = 0X34;
    constexpr char FIVE  = 0X35;
    constexpr char SIX   = 0X36;
    constexpr char SEVEN = 0X37;
    constexpr char EIGHT = 0X38;
    constexpr char NINE  = 0X39;

    constexpr char MIN_DIGIT = ZERO;
    constexpr char MAX_DIGTI = NINE;

    constexpr uInt KARATSUBA_THRESHOLD = 36;

    /**
     * @brief bigInter class
     * 
     */
    class bigInteger
    {
        private:
            std::string value_;
            bool         sign_;
        public:
            /**
             * @brief Construct a new big Integer object
             * 
             */
            bigInteger();
            bigInteger(const bigInteger& num);
            bigInteger(const std::string& num);
            bigInteger(const char* num);
            bigInteger(int num);
            bigInteger(uInt num);
            bigInteger(long long num);
            bigInteger(float num);
            bigInteger(double num);
            bigInteger(long double num);
            /**
             * @brief Destroy the big Integer object
             * 
             */
            ~bigInteger();
        
        private:
            /**
             * @brief check if a num has sign
             * 
             * @param num a string type num
             * @return true has sign
             * @return false no sign
             */
            static bool hasSign(const std::string& num);
            /**
             * @brief check if a num is IS_NEGATIVE
             * 
             * @param num a string type num
             * @return true is IS_NEGATIVE
             * @return false is IS_POSITIVE
             */
            static bool isNegative(const std::string& num);
            /**
             * @brief check if a num is digit
             * 
             * @param num a char(ASCII) type num
             * @return true is a digit
             * @return false isnt a digit
             */
            static bool isDigit(const char& num);
            /**
             * @brief check if a num is legal
             * 
             * @param num a string tyep num
             * @return true is legal
             * @return false isnt legal
             */
            static bool isLegal(const std::string& num);
            /**
             * @brief init a string num to bigInteger
             * 
             * @param num 
             */
            void init(const std::string& num);
            /**
             * @brief check if num_a < num_b
             * 
             * @param num_a a string type positive num
             * @param num_b a string type positive num
             * @return true <
             * @return false >=
             */
            static bool isSmaller(const std::string& num_a, const std::string& num_b);
            /**
             * @brief sum of tow positive numbers
             * 
             * @param num_a a string type positive num
             * @param num_b a string type positive num
             * @return bigInteger a string type positive num
             */
            static std::string safeAdd(const std::string& num_a, const std::string& num_b);
            /**
             * @brief absolute value of the subtraction of two numbers
             * 
             * @param num_a a string type positive num
             * @param num_b a string type positive num
             * @return bigInteger a string type positive num
             */
            static std::string safeSubtract(std::string num_a, std::string num_b);
            /**
             * @brief value of the subtraction of two numbers
             *        note that it's unsafe when num_a < num_b
             * 
             * @param num_a a string type positive num
             * @param num_b a string type positive num
             * @return bigInteger a string type positive num
             */
            static std::string unsafeSubtract(std::string num_a, std::string num_b);
            /**
             * @brief make num_a.size() == num_b.size()
             * 
             * @param num_a a string type num
             * @param num_b a string type num
             * @return size_t num_a.size() or num_b.size()
             */
            static size_t makeEqualSize(std::string& num_a, std::string& num_b);
            /**
             * @brief check if num_a == num_b
             * 
             * @param num_a a string type num
             * @param num_b a string type num
             * @return true ==
             * @return false !=
             */
            static bool isEqual(const std::string& num_a, char num_b);
            /**
             * @brief check if num_a == num_b
             * 
             * @param num_a a string type num
             * @param num_b a string type num
             * @return true ==
             * @return false !=
             */
            static bool isEqual(const std::string& num_a, const std::string& num_b);
            /**
             * @brief a optimized algorithm for multiplication
             * 
             * @param num_a a string type num
             * @param num_b a string type num
             * @return std::string product
             */
            static std::string multiply(std::string num_a, std::string num_b);
            /**
             * @brief multiply use karatsuba algorithm
             * 
             * @param num_a a string type positive num
             * @param num_b a string type positive num
             * @return std::string product
             */
            static std::string karatsubaMultiply(std::string num_a, std::string num_b);

        public:
            friend std::ostream& operator<<(std::ostream& os, const math::bigInteger& num);
            friend std::istream& operator>>(std::istream& is, math::bigInteger& num);
        
        public:
            /**
             * @brief override operator =
             * 
             * @param num a bigInteger num
             * @return bigInteger& 
             */
            bigInteger& operator=(const bigInteger& num);
            /**
             * @brief override relationship related operators
             * 
             */
            bool operator==(const bigInteger& num) const;
            bool operator!=(const bigInteger& num) const;
            bool operator<(const bigInteger& num)  const;
            bool operator<=(const bigInteger& num) const;
            bool operator>(const bigInteger& num)  const;
            bool operator>=(const bigInteger& num) const;
            /**
             * @brief override add/subtract related operators
             * 
             */
            bigInteger operator+(const bigInteger& num);
            bigInteger operator-(const bigInteger& num);
            bigInteger operator-();
            bigInteger& operator++();
            bigInteger& operator--();
            bigInteger operator++(int num);
            bigInteger operator--(int num);
            bigInteger& operator+=(const bigInteger& num);
            bigInteger& operator-=(const bigInteger& num);
            
            bigInteger operator*(const bigInteger& num);
            bigInteger& operator*=(const bigInteger& num);
    };

    /**
     * @brief override input/output operators
     * 
     */
    std::ostream& operator<<(std::ostream& os, const math::bigInteger& num);
    std::istream& operator>>(std::istream& is, math::bigInteger& num);
}



#endif //_BIGINTEGER_H_