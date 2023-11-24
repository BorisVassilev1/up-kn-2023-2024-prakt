#include <iostream>
// да върнем указател към х, ако той е в масива
// nullptr, ако не е
const int *binarySearch(const int *begin, const int *end, const int x) {
    -- end;

    while (begin <= end) {
        const int *middle = begin + (end - begin) / 2;

        if (*middle == x) {
            return middle;
        }
        if (*middle > x) {
            end = middle - 1;
        } else {
            begin = middle + 1;
        }
    }

    return nullptr;
}

int main() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    const int *ptr = binarySearch(a, a + 10, 10);

    if (ptr != nullptr) {
        std::cout << *ptr << std::endl;
    } else {
        std::cout << "Not in the array" << std::endl;
    }
    
    return 0;
}