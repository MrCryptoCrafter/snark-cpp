#include "../include/bigint.hpp"
#include <vector>
#include <iostream>

struct Data {
    BigInt x, y;

    Data(const std::string& xStr, const std::string& yStr, const std::string& modStr) {
        x = BigInt(xStr, 10);
        y = BigInt(yStr, 10);
        // Assuming modulus is applied for each operation
        x %= BigInt(modStr, 10);
        y %= BigInt(modStr, 10);
    }
};

BigInt interpolate(const std::vector<Data>& f, const BigInt& xi, const std::string& modStr) {
    BigInt result("0", 10);
    BigInt mod(modStr, 10);

    for (size_t i = 0; i < f.size(); i++) {
        BigInt term = f[i].y;
        for (size_t j = 0; j < f.size(); j++) {
            if (j != i) {
                BigInt denom = f[i].x - f[j].x;
                denom %= mod; // Apply modulus
                // Ensure denom is invertible in mod
                term *= (xi - f[j].x) * denom.modInverse(mod);
                term %= mod;
            }
        }
        result += term;
        result %= mod;
    }
    return result;
}

int main() {
    std::vector<Data> points = {
        Data("1", "1", "101"),   // 1^2 = 1
        Data("2", "4", "101"),   // 2^2 = 4
        Data("3", "9", "101"),   // 3^2 = 9
        Data("4", "16", "101"),  // 4^2 = 16
        Data("5", "25", "101")   // 5^2 = 25
    };

    BigInt xi("6", 10);  // Expecting 6^2 = 36
    BigInt interpolatedValue = interpolate(points, xi, "101");
    std::cout << "Interpolated Value at x=6: ";
    interpolatedValue.print();

    return 0;
}
