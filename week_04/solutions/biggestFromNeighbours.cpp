#include <iostream>

int main() {
    unsigned int n, counter = 0;
    int array[100] = { 0 };

    std::cin >> n; // assume n >= 2
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> array[i]; 
    }

    if (array[0] > array[1]) {
        ++counter;
    }
    for (unsigned int i = 1; i < n - 1; ++i) {
        if (array[i] > array[i - 1] &&
            array[i] > array[i + 1]) {
            ++counter;
        }
    }
    if (array[n - 1] > array[n - 2]) {
        ++counter;
    }

    std::cout << counter << std::endl;

    return 0;
}