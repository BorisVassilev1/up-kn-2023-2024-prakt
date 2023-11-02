#include <iostream>

bool isCapitalLetter(char c) {
    return c >= 'A' && c <= 'Z';
}
bool isSmallLetter(char c) {
    return c >= 'a' && c <= 'z';
}
bool isLetter(char c) {
    return isCapitalLetter(c) ||
        isSmallLetter(c);
}
unsigned int alphabetPosition(char c) {
    return (isCapitalLetter(c) ? c - 'A' : c - 'a'); 
}

int main() {
    unsigned int letterCounter[26] = { 0 };
    char c;

    std::cin.get(c);
    while(c != '.' && c != '?' && c != '!') {
        if (isLetter(c)) {
            ++ letterCounter[alphabetPosition(c)];
        }

        std::cin.get(c);
    }

    unsigned int maxCounter = letterCounter[0], maxCounterIndex = 0;
    for (unsigned int i = 1; i < 26; ++i) {
        if (letterCounter[i] > maxCounter) {
            maxCounter = letterCounter[i];
            maxCounterIndex = i;
        }
    }

    std::cout << (char)('A' + maxCounterIndex) << " - " << maxCounter <<std::endl;
    return 0;
}