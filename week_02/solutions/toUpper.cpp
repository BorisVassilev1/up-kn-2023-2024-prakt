#include <iostream>

int main() {
    unsigned int N, diff = 'a' - 'A';
    char c;

    std::cin >> N;
    std::cin.ignore();

    for (unsigned int i = 0 ; i < N ; ++ i) {
        std::cin.get(c);

        if (c >= 'a' && c <= 'z') {
            c -= diff;
        }

        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}