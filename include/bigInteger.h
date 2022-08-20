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
namespace mb {  
    /**
     * @brief redefine type
     * 
     */
    using uInt = unsigned int;

    /**
     * @brief macro definition
     * 
     */
    constexpr char NEGATIVE_SIGN =  '-';
    constexpr bool NEGATIVE      = true;
    constexpr bool POSITIVE     = false;
    
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
             * @brief check if a num is negative
             * 
             * @param num a string type num
             * @return true is negative
             * @return false is positive
             */
            bool isNegative(const std::string& num);
            /**
             * @brief init a string num to bigInteger
             * 
             * @param num 
             */
            void init(const std::string& num);

        public:
            friend std::ostream& operator<<(std::ostream& os, const mb::bigInteger& num);
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
    std::ostream& operator<<(std::ostream& os, const mb::bigInteger& num);
}



#endif //_BIGINTEGER_H_