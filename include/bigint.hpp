#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <gmp.h>
#include <string>
#include <vector>

/**
 * @class BigInt
 * @brief A class for arbitrary-precision integers using the GMP library.
 */
class BigInt {
public:
    /**
     * @brief Default constructor. Creates a BigInt initialized to zero.
     */
    BigInt();

    /**
     * @brief Constructor to initialize a BigInt from an unsigned long int.
     * @param val The value to initialize the BigInt with.
     */
    BigInt(unsigned long int val);

    /**
     * @brief Constructor to initialize a BigInt from a signed long int.
     * @param val The value to initialize the BigInt with.
     */
    BigInt(signed long int val);

    /**
     * @brief Constructor to initialize a BigInt from a string representation.
     * @param val The string representation of the BigInt.
     * @param base The base of the string representation (default is 10).
     */
    BigInt(const std::string &val, int base = 10);

    /**
     * @brief Copy constructor.
     * @param other The BigInt to copy.
     */
    BigInt(const BigInt &other);

    /**
     * @brief Constructor to initialize a BigInt from a GMP mpz_t.
     * @param bi The GMP mpz_t to initialize from.
     */
    BigInt(mpz_t bi);

    /**
     * @brief Destructor for BigInt.
     */
    ~BigInt();

    /**
     * @brief Addition operator.
     * @param other The BigInt to add.
     * @return The result of the addition.
     */
    BigInt operator+(const BigInt &other) const;

    /**
     * @brief Subtraction operator.
     * @param other The BigInt to subtract.
     * @return The result of the subtraction.
     */
    BigInt operator-(const BigInt &other) const;

    /**
     * @brief Multiplication operator.
     * @param other The BigInt to multiply by.
     * @return The result of the multiplication.
     */
    BigInt operator*(const BigInt &other) const;

    /**
     * @brief Division operator.
     * @param other The BigInt to divide by.
     * @return The result of the division.
     */
    BigInt operator/(const BigInt &other) const;

    /**
     * @brief Modulus operator.
     * @param other The BigInt to take modulus with.
     * @return The result of the modulus operation.
     */
    BigInt operator%(const BigInt &other) const;

    /**
     * @brief Assignment operator.
     * @param other The BigInt to assign.
     * @return Reference to this BigInt after assignment.
     */
    BigInt& operator=(const BigInt &other);

    /**
     * @brief Addition assignment operator.
     * @param other The BigInt to add.
     * @return Reference to this BigInt after addition.
     */
    BigInt& operator+=(const BigInt &other);

    /**
     * @brief Subtraction assignment operator.
     * @param other The BigInt to subtract.
     * @return Reference to this BigInt after subtraction.
     */
    BigInt& operator-=(const BigInt &other);

    /**
     * @brief Multiplication assignment operator.
     * @param other The BigInt to multiply by.
     * @return Reference to this BigInt after multiplication.
     */
    BigInt& operator*=(const BigInt &other);

    /**
     * @brief Division assignment operator.
     * @param other The BigInt to divide by.
     * @return Reference to this BigInt after division.
     */
    BigInt& operator/=(const BigInt &other);

    /**
     * @brief Modulus assignment operator.
     * @param other The BigInt to take modulus with.
     * @return Reference to this BigInt after modulus operation.
     */
    BigInt& operator%=(const BigInt &other);

    /**
     * @brief Equality operator.
     * @param other The BigInt to compare with.
     * @return True if equal, false otherwise.
     */
    bool operator==(const BigInt &other) const;

    /**
     * @brief Inequality operator.
     * @param other The BigInt to compare with.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const BigInt &other) const;

    /**
     * @brief Less than operator.
     * @param other The BigInt to compare with.
     * @return True if less than, false otherwise.
     */
    bool operator<(const BigInt &other) const;

    /**
     * @brief Less than or equal to operator.
     * @param other The BigInt to compare with.
     * @return True if less than or equal to, false otherwise.
     */
    bool operator<=(const BigInt &other) const;

    /**
     * @brief Greater than operator.
     * @param other The BigInt to compare with.
     * @return True if greater than, false otherwise.
     */
    bool operator>(const BigInt &other) const;

    /**
     * @brief Greater than or equal to operator.
     * @param other The BigInt to compare with.
     * @return True if greater than or equal to, false otherwise.
     */
    bool operator>=(const BigInt &other) const;

    /**
     * @brief Convert BigInt to a string representation.
     * @param base The base of the string representation (default is 10).
     * @return String representation of BigInt.
     */
    std::string toString(int base = 10) const;

    /**
     * @brief Get the number of bits in the BigInt.
     * @return Number of bits.
     */
    size_t bitSize() const;

    /**
     * @brief Check if BigInt is zero.
     * @return True if zero, false otherwise.
     */
    bool isZero() const;

    /**
     * @brief Print the BigInt to standard output.
     */
    void print() const;

    /**
     * @brief Check if BigInt is negative.
     * @return True if negative, false otherwise.
     */
    bool isNegative() const;

    /**
     * @brief Negate the BigInt.
     */
    void negate();

    /**
     * @brief Invert the BigInt modulo a given modulus.
     * @param modulus The modulus to invert with.
     * @return True if inversion is successful, false otherwise.
     */
    bool invert(const BigInt& modulus);

    /**
     * @brief Calculate the modular inverse of the BigInt.
     * @param modulus The modulus for the modular inverse.
     * @return The modular inverse of the BigInt.
     */
    BigInt modInverse(const BigInt& modulus) const;

    /**
     * @brief Print the absolute value of the BigInt.
     */
    void printAbsolute() const;

    /**
     * @brief Check if the BigInt is a prime number.
     * @param provable Flag to indicate provable primality testing.
     * @return 2 if definitely prime, 1 if probably prime, 0 if not prime.
     */
    int isPrime(int provable) const;

    /**
     * @brief Find the next prime number greater than or equal to the given BigInt.
     * @param startAt The BigInt to start searching for the next prime.
     * @param provable Flag to indicate provable primality testing.
     * @return The next prime number.
     */
    static BigInt nextPrime(const BigInt& startAt, int provable);

    /**
     * @brief Bitwise AND operation with another BigInt.
     * @param other The BigInt to perform bitwise AND with.
     * @return The result of the bitwise AND operation.
     */
    BigInt bitwiseAnd(const BigInt& other) const;

    /**
     * @brief Bitwise OR operation with another BigInt.
     * @param other The BigInt to perform bitwise OR with.
     * @return The result of the bitwise OR operation.
     */
    BigInt bitwiseIor(const BigInt& other) const;

    /**
     * @brief Bitwise XOR operation with another BigInt.
     * @param other The BigInt to perform bitwise XOR with.
     * @return The result of the bitwise XOR operation.
     */
    BigInt bitwiseXor(const BigInt& other) const;

    /**
     * @brief Bitwise complement (NOT) operation.
     * @return The result of the bitwise complement operation.
     */
    BigInt bitwiseComplement() const;

    /**
     * @brief Left shift operation by a specified number of bits.
     * @param shiftBy The number of bits to shift left by.
     * @return The result of the left shift operation.
     */
    BigInt leftShift(unsigned long int shiftBy) const;

    /**
     * @brief Right shift operation by a specified number of bits.
     * @param shiftBy The number of bits to shift right by.
     * @return The result of the right shift operation.
     */
    BigInt rightShift(unsigned long int shiftBy) const;

private:
    mpz_t value; // The GMP mpz_t representing the BigInt.
};

#endif // BIGINT_HPP
