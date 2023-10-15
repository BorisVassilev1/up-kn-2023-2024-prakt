#include <iostream>
#include <cmath>

int main() {
    int k, n, closestToK;

    std::cin >> k;
    std::cin >> n;

    if (n == 0) {
        std::cout << "No entered numbers" << std::endl;
        return 0;
    }

    closestToK = n;

    while(n != 0) {
        closestToK = ((std::abs(n - k) < std::abs(closestToK - k))
            ? n 
            : closestToK);
        
        std::cin >> n;
    } // we do not want to check for the 0

    std::cout << closestToK << std::endl;
    
    return 0;
}