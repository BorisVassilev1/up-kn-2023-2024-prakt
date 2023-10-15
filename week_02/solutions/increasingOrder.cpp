#include <iostream>

int main() {
    int a, b, c;

    std::cin >> a >> b >> c;

    int minNumber = (a <= b ? (a <= c ? a : c) : (b <= c ? b : c)),
        maxNumber = (a >= b ? (a >= c ? a : c) : (b >= c ? b : c));

    if (minNumber == a && maxNumber == c) {
        std::cout << c << ' ' << b << ' ' << a << std::endl;
        return 0;
    }

    std::cout << minNumber << ' ' << (a + b + c) - (minNumber + maxNumber)
        << ' ' << maxNumber << std::endl;

    return 0;
}