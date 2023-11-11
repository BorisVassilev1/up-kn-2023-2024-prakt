#include <iostream>

int main() {
	int N;
	std::cin >> N;
	
	int factorial = 1;
	int i = 1;
	while(factorial <= N) {
		++ i;
		factorial *= i;
	}
	std::cout << (i - 1) << std::endl;

	return 0;
}
