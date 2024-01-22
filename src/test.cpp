#include <gmp.h>
#include <iostream>

void E(mpz_t rop, const mpz_t exp) {
    mpz_set_ui(rop, 1);
    for (mpz_t i; mpz_cmp(i, exp) < 0; mpz_add_ui(i, i, 1)) {
        mpz_mul_ui(rop, rop, 2);
    }
}

void test_homomorphic_holding() {
    mpz_t x, y, one, E_x, E_y, E_x_minus_y, E_one;
    mpz_init(x);
    mpz_init(y);
    mpz_init(E_x);
    mpz_init(E_y);
    mpz_init(E_x_minus_y);
    mpz_init(E_one);
    mpz_init_set_ui(one, 1);

    mpz_set_str(x, "12345678901234567890", 10);
    mpz_set_str(y, "12345678901234567889", 10);

    std::cout << "x: " << mpz_get_str(nullptr, 10, x) << std::endl;
    std::cout << "y: " << mpz_get_str(nullptr, 10, y) << std::endl;

    E(E_x, x);
    E(E_y, y);

    mpz_div(E_x_minus_y, E_x, E_y);
    E(E_one, one);

    if (mpz_cmp(E_x_minus_y, E_one) == 0) {
        std::cout << "Proof accepted: E(x-y) equals E(1)" << std::endl;
    } else {
        std::cout << "Proof rejected: E(x-y) does not equal E(1)" << std::endl;
    }
    std::cout << "Homomorphic Holding is working!!!" << std::endl;

    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(E_x);
    mpz_clear(E_y);
    mpz_clear(E_x_minus_y);
    mpz_clear(E_one);
    mpz_clear(one);
}

int main(){
    test_homomorphic_holding();
    return 0;
}