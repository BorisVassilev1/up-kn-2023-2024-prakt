#include <iostream>

void cubes(int n) {
	unsigned int currentCube = 1;
	unsigned int i = 1;
	do {
		std::cout << currentCube << ' ';
		++ i;
		currentCube = i * i * i;
	} while(currentCube < n);
}

int main() {
	unsigned int param;
	std::cin >> param;
	
	cubes(param);

	std::cout << std::endl;
	return 0;
}
