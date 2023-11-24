#include <iostream>
#include <cstddef>
void swap(int *ptr1, int *ptr2) {
    int z = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = z;

    return;
}
void printArray(int a[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++ i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return;
}

void reverse(int* begin, int* end) {
    -- end;
    while(begin < end) {
        swap(begin, end);
        ++ begin;
        -- end;
    }

    return;
}

int main() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    reverse(a, a + 10);

    printArray(a, 10);

    return 0;
}