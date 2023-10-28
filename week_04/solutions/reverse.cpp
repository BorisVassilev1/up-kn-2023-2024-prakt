#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;

    int a[16] = { 0 };
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (unsigned int i = n; i >= 1; --i) {
        std::cout << a[i - 1] << ' ';
    }
    std::cout << std::endl;

    return 0;
}