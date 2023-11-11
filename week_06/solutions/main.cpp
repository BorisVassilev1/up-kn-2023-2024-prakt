#include <iostream>
#include <cstddef>
#include <algorithm>

void printArray(int a[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++ i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return;
}

void selectionSort(int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++ i) {
        int minEl = arr[i];
        std::size_t minElIndex = i;

        for (std::size_t j = i + 1; j < size; ++ j) {
            if (arr[j] < minEl) {
                minEl = arr[j];
                minElIndex = j;
            }
        }

        std::swap(arr[i], arr[minElIndex]);
    }

    return;
}

void bubbleSort(int arr[], std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++ i) {
        bool flag = false;

        for(std::size_t j = 0; j < size - 1 - i; ++ j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }

        if (flag == false) {
            return;
        }
    }

    return;
}



int main() {
    int arr[] = {5, 34, 87, -7, 3};
    std::size_t length = sizeof(arr) / sizeof(arr[0]); // 3
    
    printArray(arr, length);
    //selectionSort(arr, length);
    bubbleSort(arr, length);
    printArray(arr, length);
    
    return 0;
}