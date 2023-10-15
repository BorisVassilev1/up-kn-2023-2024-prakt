#include <iostream>

int main() {
    int a, b;

    std::cin >> a >> b;

    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }

    while(b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }

    std::cout << a << std::endl;

    return 0;
}