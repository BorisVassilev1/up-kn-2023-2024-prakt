#include <iostream>

int main() {
	int N, K;
	std::cin >> N >> K;

	int current = 1;
	int i = 0;
	while(current <= N) {
		current *= K;
		++ i;
	}
	
	std::cout << i << std::endl;
	return 0;
}
