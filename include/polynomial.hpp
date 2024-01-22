/**
 * @file Polynomial.hpp
 * @brief Definition of the Polynomial class.
 *
 * Defines the structure and operations of polynomials over finite fields.
 */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include "bigint.hpp"
#include <vector>
#include <string>

/**
 * @class Polynomial
 * @brief A class representing a polynomial with BigInt coefficients.
 * 
 * This class allows operations on polynomials over finite fields using BigInt.
 */
class Polynomial {
public:
    /**
     * @brief Constructs a Polynomial object.
     * 
     * @param coeff_array A vector of string representations of coefficients.
     * @param modulusStr The modulus as a string for the finite field.
     */
    Polynomial(const std::vector<std::string>& coeff_array, const std::string& modulusStr);

    /**
     * @brief Prints the polynomial in a readable format.
     */
    void print() const;

    /**
     * @brief Returns the degree of the polynomial.
     * 
     * @return Degree of the polynomial.
     */
    int deg() const;

    /**
     * @brief Gets the coefficients of the polynomial.
     * 
     * @return Vector of BigInt representing the coefficients.
     */
    std::vector<BigInt> getCoefficients() const;

    /**
     * @brief Gets the modulus of the finite field.
     * 
     * @return Modulus as BigInt.
     */
    BigInt getMod() const;

    /**
     * @brief Adds two polynomials and stores the result in a third polynomial.
     * 
     * @param result Reference to Polynomial where the result will be stored.
     * @param a The first polynomial to add.
     * @param b The second polynomial to add.
     * @throw std::invalid_argument If the moduli of the polynomials are not the same.
     */
    friend void addPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b);

    /**
     * @brief Subtracts the second polynomial from the first and stores the result in a third polynomial.
     * 
     * @param result Reference to Polynomial where the result will be stored.
     * @param a The polynomial to subtract from.
     * @param b The polynomial to subtract.
     * @throw std::invalid_argument If the moduli of the polynomials are not the same.
     */
    friend void subtractPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b);

    /**
     * @brief Multiplies two polynomials and stores the result in a third polynomial.
     * 
     * @param result Reference to Polynomial where the result will be stored.
     * @param a The first polynomial to multiply.
     * @param b The second polynomial to multiply.
     * @throw std::invalid_argument If the moduli of the polynomials are not the same.
     */
    friend void multiplyPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b);

    /**
     * @brief Multiplies a polynomial by a scalar and stores the result in another polynomial.
     * 
     * @param result Reference to Polynomial where the result will be stored.
     * @param poly The polynomial to multiply.
     * @param scalar The scalar to multiply the polynomial by.
     */
    friend void multiplyPolynomialByScalar(Polynomial &result, const Polynomial &poly, const BigInt &scalar);

    /**
     * @brief Divides a polynomial by a scalar and stores the result in another polynomial.
     * 
     * @param result Reference to Polynomial where the result will be stored.
     * @param poly The polynomial to divide.
     * @param scalar The scalar to divide the polynomial by.
     * @throw std::invalid_argument If the scalar is zero or not invertible in the modulus.
     */
    friend void dividePolynomialByScalar(Polynomial &result, const Polynomial &poly, const BigInt &scalar);


private:
    std::vector<BigInt> coefficients; ///< Coefficients of the polynomial.
    BigInt mod; ///< Modulus of the finite field.
};

#endif // POLYNOMIAL_HPP
