#include <iostream>

void printArray(const int a[], const std::size_t size) {
    for (std::size_t i = 0; i < size; ++ i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return;
}

void mergeSorted(
    const int arr1[], const std::size_t size1,
    const int arr2[], const std::size_t size2,
    int res[]
) {
    std::size_t index1 = 0, index2 = 0;
    std::size_t i = 0;

    while (index1 < size1 && index2 < size2) {
        if (arr1[index1] <= arr2[index2]) {
            res[i] = arr1[index1];
            ++ index1;
        } else {
            res[i] = arr2[index2];
            ++ index2;
        }
        ++ i;
    }

    if (index1 < size1) {
        while (index1 < size1) {
            res[i] = arr1[index1];

            ++ index1;
            ++ i;
        }
    } else {
        while (index2 < size2) {
            res[i] = arr2[index2];

            ++ index2;
            ++ i;
        }
    }

    return;
} 

int main() {
    int arr1[] = { 5, 10, 15, 20, 25 };
    int arr2[] = { 9, 10, 20, 30, 40, 50 };
    int result[100] = { 0 };

    std::size_t length1 = sizeof(arr1) / sizeof(arr1[0]);
    std::size_t length2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSorted(arr1, length1, arr2, length2, result);
    printArray(result, length1 + length2);

    return 0;
}