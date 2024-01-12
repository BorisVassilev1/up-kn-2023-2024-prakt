#include <iostream>

struct Array {
    int array[100];
    std::size_t size;
};

Array readArray() {
    Array arr;

    std::cin >> arr.size;
    for (std::size_t i = 0; i < arr.size; ++i) {
        std::cin >> arr.array[i];
    }

    return arr;
}
void printArray(const Array& arr) {
    std::cout << "Array of size: " << arr.size << std::endl;
    for (std::size_t i = 0; i < arr.size; ++i) {
        std::cout << arr.array[i] << ' ';
    }
    std::cout << std::endl;
}

void squareElements(Array& arr) {
    for (std::size_t i = 0; i < arr.size; ++i) {
        arr.array[i] = arr.array[i] * arr.array[i];
    }

    return;
}

void filterPositiveElements(Array& arr) {
    std::size_t newSize = arr.size, indexToWrite = 0;

    for (std::size_t i = 0; i < arr.size; ++i) {
        if (arr.array[i] > 0) {
            arr.array[indexToWrite] = arr.array[i];
            ++indexToWrite;
        } else {
            --newSize;
        }
    }
    arr.size = newSize;

    return;
}

int main() {
    Array arr = readArray();
    printArray(arr);

    filterPositiveElements(arr);
    printArray(arr);

    squareElements(arr);
    printArray(arr);

    return 0;
}