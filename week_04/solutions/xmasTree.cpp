#include <iostream>

void drawXmasTree(unsigned int height) {
    for (unsigned int i = 0; i < height; ++i) {
        // loop for spaces
        for (unsigned int j = height - i; j > 0; --j) {
            std::cout << ' ';
        }

        unsigned int stars = 2 * i + 1;
        // loop for stars
        for (unsigned int j = 1; j <= stars; ++j) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }

    return;
}

int main() {
    unsigned int height;
    std::cin >> height;

    drawXmasTree(height);

    return 0;
}