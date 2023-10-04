#include <iostream>
#include <math.h>

int main() {
	float a, b;
	std::cin >> a >> b;
	float ans = sqrt(a * a + b * b);
	std::cout << ans << std::endl;
	return 0;
}
