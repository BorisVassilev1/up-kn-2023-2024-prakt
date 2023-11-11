#include <iostream>
#include <cmath>

// едно добро решение имаме в решенията от седмица 2.
// Тук пиша доста подобно

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	int max = std::max(std::max(a, b), c);
	int min = std::min(std::min(a, b), c);

	std::cout << min << " " << (a + b + c - max - min) << " " << max << std::endl;
}
