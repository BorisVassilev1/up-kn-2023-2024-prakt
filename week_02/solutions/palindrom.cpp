#include <iostream>

int main() {
    unsigned int n;
    unsigned int ones, tens, hundreds, thousands;

    std::cin >> n;

    ones = n % 10;
    tens = (n / 10) % 10;
    hundreds = (n / 100) % 10;
    thousands = n / 1000;

    unsigned int result = (thousands == ones && hundreds == tens)
        ? n * n
        : 1000 * ones + 100 * tens + 10 * hundreds + thousands;
    
    std::cout << result << std::endl;

    return 0;
}