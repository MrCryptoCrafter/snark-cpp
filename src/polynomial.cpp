#include "../include/bigint.hpp"
#include "../include/polynomial.hpp"
#include <vector>
#include <iostream>
#include <sstream>

Polynomial::Polynomial(const std::vector<std::string>& coeff_array, const std::string& modulusStr) {
    mod = BigInt(modulusStr, 10);
    for (const auto& coeff : coeff_array) {
        coefficients.emplace_back(coeff, 10);
    }
}

void Polynomial::print() const {
    bool first = true;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        if (!first) {
            std::cout << (coefficients[i].isNegative() ? " - " : " + ");
        } else if (coefficients[i].isNegative()) {
            std::cout << "-";
        }
        first = false;

        coefficients[i].printAbsolute();

        if (i > 0) {
            std::cout << "*x^" << i;
        }
    }
    std::cout << std::endl;
}

int Polynomial::deg() const {
    return coefficients.size() - 1;
}

std::vector<BigInt> Polynomial::getCoefficients() const {
    return coefficients;
}

BigInt Polynomial::getMod() const {
    return mod;
}

void addPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b) {
    if (a.mod != b.mod) {
        throw std::invalid_argument("Moduli of the polynomials must be the same.");
    }

    size_t max_degree = std::max(a.coefficients.size(), b.coefficients.size());
    result.coefficients.resize(max_degree);
    result.mod = a.mod; 

    for (size_t i = 0; i < max_degree; ++i) {
        BigInt sum = (i < a.coefficients.size() ? a.coefficients[i] : BigInt(static_cast<unsigned long int>(0))) +
                     (i < b.coefficients.size() ? b.coefficients[i] : BigInt(static_cast<unsigned long int>(0)));
        sum %= a.mod;
        result.coefficients[i] = sum;
    }
}

void subtractPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b) {
    if (a.mod != b.mod) {
        throw std::invalid_argument("Moduli of the polynomials must be the same.");
    }

    size_t max_degree = std::max(a.coefficients.size(), b.coefficients.size());
    result.coefficients.resize(max_degree);
    result.mod = a.mod;  // Set the modulus for the result polynomial

    for (size_t i = 0; i < max_degree; ++i) {
        BigInt diff = (i < a.coefficients.size() ? a.coefficients[i] : BigInt(static_cast<unsigned long int>(0))) -
                      (i < b.coefficients.size() ? b.coefficients[i] : BigInt(static_cast<unsigned long int>(0)));
        diff %= a.mod;
        result.coefficients[i] = diff;
    }
}

void multiplyPolynomials(Polynomial &result, const Polynomial &a, const Polynomial &b) {
    if (a.mod != b.mod) {
        throw std::invalid_argument("Moduli of the polynomials must be the same.");
    }

    size_t result_degree = a.coefficients.size() + b.coefficients.size() - 1;
    result.coefficients.resize(result_degree, BigInt(static_cast<unsigned long int>(0)));
    result.mod = a.mod;

    for (size_t i = 0; i < a.coefficients.size(); ++i) {
        for (size_t j = 0; j < b.coefficients.size(); ++j) {
            result.coefficients[i + j] += a.coefficients[i] * b.coefficients[j];
            result.coefficients[i + j] %= a.mod;
        }
    }
}

void multiplyPolynomialByScalar(Polynomial &result, const Polynomial &poly, const BigInt &scalar) {
    result.coefficients.resize(poly.coefficients.size());
    result.mod = poly.mod;

    for (size_t i = 0; i < poly.coefficients.size(); ++i) {
        result.coefficients[i] = poly.coefficients[i] * scalar;
        result.coefficients[i] %= poly.mod;
    }
}

void dividePolynomialByScalar(Polynomial &result, const Polynomial &poly, const BigInt &scalar) {
    if (scalar.isZero()) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    result.coefficients.resize(poly.coefficients.size());
    result.mod = poly.mod;

    for (size_t i = 0; i < poly.coefficients.size(); ++i) {
        // Ensure scalar is invertible in mod before division
        result.coefficients[i] = poly.coefficients[i] * scalar.modInverse(poly.mod);
        result.coefficients[i] %= poly.mod;
    }
}

int main() {
    std::vector<std::string> coeffs1 = {"1", "-2", "3","15"};
    Polynomial poly1(coeffs1, "7");

    std::cout << "Polynomial 1: ";
    poly1.print();

    std::vector<std::string> coeffs2 = {"-3", "4", "2"};
    Polynomial poly2(coeffs2, "7");

    std::cout << "Polynomial 2: ";
    poly2.print();

    Polynomial result({}, "7");

    addPolynomials(result, poly1, poly2);

    std::cout << "Result of addition: ";
    result.print();

    subtractPolynomials(result, poly1, poly2);

    std::cout << "Result of substraction: ";
    result.print();

    Polynomial result1({}, "7");

    multiplyPolynomials(result1, poly1, poly2);

    std::cout << "Result of multiplication: ";
    result1.print();


    std::vector<std::string> coeffs = {"1", "2", "3"};
    Polynomial poly(coeffs, "7"); // Modulus is 7

    // Define scalars for multiplication and division
    BigInt scalarMult("2", 10);
    BigInt scalarDiv("3", 10);

    // Test multiplication by scalar
    Polynomial resultMult({}, "7");
    multiplyPolynomialByScalar(resultMult, poly, scalarMult);
    std::cout << "Result of multiplication by scalar: ";
    resultMult.print();

    // Test division by scalar
    Polynomial resultDiv({}, "7");
    dividePolynomialByScalar(resultDiv, poly, scalarDiv);
    std::cout << "Result of division by scalar: ";
    resultDiv.print();

    return 0;
}
