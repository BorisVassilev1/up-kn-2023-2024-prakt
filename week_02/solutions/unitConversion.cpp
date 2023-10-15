#include <iostream>

int main() {
    unsigned int l, ml, k, m;
    unsigned int bottleVolume, cupsVolume, surplusVolume;

    std::cin >> l >> ml >> k >> m;

    bottleVolume = l * 1000 + ml;
    cupsVolume = k * m;

    if (cupsVolume > bottleVolume) {
        std::cout << "Not enough liquid!" << std::endl;
        return 0;
    } 

    surplusVolume = bottleVolume - cupsVolume;

    std::cout << surplusVolume / 1000 << " "
        << surplusVolume % 1000 << std::endl;

    return 0;
}