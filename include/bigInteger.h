/********************************************************************************
  * @file       bigInteger.h
  * @author     Xun Zeng
  * @date       2022-08-20
  * @lastedit   2022-08-20
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

    /**
     * @brief bigInter class
     * 
     */
    class bigInteger
    {
        public:
            std::string value_;
            bool         sign_;
        public:
            /**
             * @brief Construct a new big Integer object
             * 
             */
            bigInteger();
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num a bigInteger type num.
             */
            bigInteger(const bigInteger& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num a string type num .
             */
            bigInteger(const std::string& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num a char* type num.
             */
            bigInteger(const char* num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an int type num.
             */
            bigInteger(const int& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an unsigned int type num.
             */
            bigInteger(const uInt& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an long long type num.
             */
            bigInteger(const long long& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an float type num.
             */
            bigInteger(const float& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an double type num.
             */
            bigInteger(const double& num);
            /**
             * @brief Construct a new big Decimal object.
             * 
             * @param num an long double type num.
             */
            bigInteger(const long double& num);
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

        public:
            friend std::ostream& operator<<(std::ostream& os, const math::bigInteger& num);
            friend std::istream& operator>>(std::istream& is, math::bigInteger& num);
            /**
             * @brief override operator =
             * 
             * @param num a bigInteger num
             * @return bigInteger& 
             */
            bigInteger& operator=(const bigInteger& num);
    };

    /**
     * @brief override operator <<
     * 
     * @param os output
     * @param num a bigInteger num
     * @return std::ostream& 
     */
    std::ostream& operator<<(std::ostream& os, const math::bigInteger& num);
    /**
     * @brief override operator >>
     * 
     * @param is input
     * @param num a bigInteger num
     * @return std::istream& 
     */
    std::istream& operator>>(std::istream& is, math::bigInteger& num);
}



#endif //_BIGINTEGER_H_