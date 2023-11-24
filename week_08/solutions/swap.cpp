#include <iostream>

void swap(int *ptr1, int *ptr2) {
    int z = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = z;

    return;
}

int main() {
    int a = 5, b = 6;

    swap(&a, &b);

    std::cout << a << ' ' << b << std::endl; // 6 5

    return 0;
}