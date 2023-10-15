#include <iostream>

int main() {
    int n, maxN;

    std::cin >> n;

    if (n == 0) {
        std::cout << "You did not entered numbers" << std::endl;
        return 0;
    }

    maxN = n;

    while (n != 0) {
        maxN = ((n > maxN) ? n : maxN);

        std::cin >> n;
    }; // we do not want to check if 0 is the biggest

    std::cout << maxN << std::endl;

    return 0;
}