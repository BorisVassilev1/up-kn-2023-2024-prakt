#include <iostream>
#include <cstddef>

// s1 -> "aabcf"
// s2 -> "cd"

// a function that checks if s2 is a substring of s1
bool isSubstring(const char s1[], const char s2[]) {
    std::size_t i1 = 0, i2 = 0; // i1 - position in s1, i2 - position in s2

    while (s1[i1] != '\0') {
        // we will enter in the following while
        // ONLY IF s1[i1] == s2[0]
        while (
            s2[i2] != '\0' &&       // we are on valid symbol from s2
            s2[i2] == s1[i1 + i2]   // the current symbol from s2 is the same as those from s1
        ) {
            ++ i2;
        }

        if (s2[i2] == '\0') {   // we went to the end of s2 thus we have a substring
            return true;
        }

        ++ i1;
        i2 = 0;
    }

    return false; // we have not found a substring
}

std::size_t stringLength(const char s[]) {
    std::size_t length = 0;

    while(s[length] != '\0') {
        ++ length;
    }

    return length;
}
bool isSubstringLinear(const char s1[], const char s2[]) {
    std::size_t i1 = 0, i2 = 0;
    std::size_t lengthOfs2 = stringLength(s2), currLength = 0;

    while (s1[i1] != '\0') {
        if (s1[i1] == s2[i2]) {
            ++ i1; // move forward in s1
            ++ i2; // move forward in s2

            ++ currLength; // increase the length of the potential substring 
        } else {
            if (currLength == lengthOfs2) {
                return true; // s2 is a substring of s1
            }

            i1 = i1 - i2 + 1; // we want i1 to be right after the first equality
            i2 = 0; // reseting i2
            currLength = 0; // reseting currLength
        }
    }

    return currLength == lengthOfs2; // if s2 is suffix of s1
}
int main() {
    char s1[100], s2[100];

    std::cin.getline(s1, 100);
    std::cin.getline(s2, 100);

    std::cout << isSubstringLinear(s1, s2) << std::endl;

    return 0;
}