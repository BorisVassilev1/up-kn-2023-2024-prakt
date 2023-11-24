#include <iostream>

int sumElements(const int *begin, const int *end) {
    int sum = 0;

    while (begin != end) {
        sum += *begin;
        ++ begin;
    }

    return sum;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << sumElements(arr, arr + 10) << std::endl;

    return 0;
}