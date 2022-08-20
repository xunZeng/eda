/********************************************************************************
  * @file       bigDecimal.h
  * @author     Xun Zeng
  * @date       2022-08-18
  * @lastedit   2022-08-20
  * @brief      Floating point arithmetic for integrated circuit layouts.
  ******************************************************************************/

#ifndef _BIGDECIMAL_H_
#define _BIGDECIMAL_H_

#include <string>

namespace db{
  /**
   * @brief redefine type
   * 
   */
  using uInt = unsigned int;

  class bigDecimal{

    private:
        std::string     value_;
        static uInt     scale_;
        static uInt precision_;

    public:
        /**
         * @brief Construct a new big Decimal object
         * 
         */
        bigDecimal();
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num a bigDecimal type num.
         */
        bigDecimal(const bigDecimal& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num a string type num .
         */
        bigDecimal(const std::string& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num a char* type num.
         */
        bigDecimal(const char* num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an int type num.
         */
        bigDecimal(const int& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an unsigned int type num.
         */
        bigDecimal(const uInt& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an long long type num.
         */
        bigDecimal(const long long& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an float type num.
         */
        bigDecimal(const float& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an double type num.
         */
        bigDecimal(const double& num);
        /**
         * @brief Construct a new big Decimal object.
         * 
         * @param num an long double type num.
         */
        bigDecimal(const long double& num);
        /**
         * @brief Destroy the big Decimal object.
         * 
         */
        ~bigDecimal();

    public:

  };
};

#endif //_BIGDECIMAL_H_