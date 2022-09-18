/********************************************************************************
  * @file       precisionMath.h
  * @author     Xun Zeng
  * @date       2022-09-12
  * @lastedit   2022-09-18
  * @brief      High precision arithmetic supported by GMP.
  ******************************************************************************/

#ifndef _PRECISION_MATH_H_
#define _PRECISION_MATH_H_

#include "gmpxx.h"

/**
 * @brief math base
 * 
 */
namespace math {  

    /**
     * @brief precisionMath class
     * 
     */ 
    template<typename T, typename U>
    class precisionMath : public __gmp_expr<T, U>{

        private:
            using uInt = unsigned int;
            using pmath_t = precisionMath<T, U>;
            using gmp_t = __gmp_expr<T, U>;
            using gmpInit = gmp_t;

        public:
            /**
             * @brief Construct a new big Integer object
             * 
             */
            precisionMath() : gmpInit() {}
            template<typename V>
            precisionMath(V num) : gmpInit(num) {}
            /**
             * @brief Destroy the big Integer object
             * 
             */
            ~precisionMath() {}
    };

    /**
     * @brief High precision types supported by GMP
     * @note: It is thus strongly recommended to avoid "auto" anywhere a GMP C++ expression may appear
     *        Because "auto" don’t mix well with expression templates
     * 
     */
    typedef precisionMath<mpf_t, mpf_t> pfloat_t;
    typedef precisionMath<mpz_t, mpz_t> pint_t;
    typedef precisionMath<mpq_t, mpq_t> pration_t;
    // typedef gmp_randclass prandom_t;
}

#endif // _PRECISION_MATH_H_