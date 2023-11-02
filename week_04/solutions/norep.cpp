#include <iostream>

int main() {
    unsigned int n, currentNum, addIndex = 0;
    int uniqueNumbers[32] = { 0 };
    std::cin >> n;

    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> currentNum;

        if (addIndex == 0 || uniqueNumbers[addIndex - 1] != currentNum) {
            uniqueNumbers[addIndex] = currentNum;
            ++ addIndex;
        } 
    }

    for (unsigned int i = 0; i < addIndex; ++i) {
        std::cout << uniqueNumbers[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}