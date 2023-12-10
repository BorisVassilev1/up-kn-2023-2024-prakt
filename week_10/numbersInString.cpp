#include <iostream>

// we have a string and we want the numbers in it in array of numbers


int main() {
    char str[100] = { '\0' };

    std::cin.getline(str, 100);

    unsigned int numbers[100] = { 0 };
    unsigned int size = 0, i = 0;
    int tempNumber = 0; // how many numbers we have
    bool flag = false; // to check if we read number
    
    // "abc 100"
    // "a000 45" -> {0, 45}
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            if (flag == false) {
                flag = true;
            }
            
            tempNumber = tempNumber * 10 + (str[i] - '0');
            // tempNumber = 0, 10 * 0 + 1 = 1, 1 * 10 + 0 = 10,
        } else {
            if (flag == true) {
                numbers[size] = tempNumber;
                ++ size;
                tempNumber = 0;

                flag = false;
            }
        }

        ++ i;
    }
    // "s34a 523"
    if (flag == true) {
        numbers[size] = tempNumber;
        ++ size;
    }

    for (unsigned int j = 0; j < size; ++ j) {
        std::cout << numbers[j] << ' ';
    }
    std::cout << std::endl;


    return 0;
}