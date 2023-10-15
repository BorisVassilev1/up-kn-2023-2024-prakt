#include <iostream>

int main() {
    char letter;

    std::cin.get(letter);

    if (letter >= 'A' && letter <= 'Z') {
        std::cout << letter - 'A' + 1 << std::endl;
    } else if (letter >= 'a' && letter <= 'z') {
        std::cout << letter - 'a' + 1 << std::endl;
    } else {
        std::cout << "Not a letter" << std::endl;
    }

    return 0;
}