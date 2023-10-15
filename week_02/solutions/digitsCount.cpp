#include <iostream>

int main() {
    unsigned int n, digitsCounter = 0;

    std::cin >> n;

    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }

    while(n != 0) {
        n /= 10;
        ++ digitsCounter;
    }

    std::cout << digitsCounter << std::endl;

    return 0;
}