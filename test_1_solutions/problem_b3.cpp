#include <iostream>

int main() {
	int S, N;
	std::cin >> S >> N;

	int counter = 0;
	bool shouldCount = true;
	int sum = 0;

	for(int i = 0; i < N; ++ i) {
		int curr;
		std::cin >> curr;
		
		sum += curr;
		if(sum <= S && shouldCount) ++ counter;
		else shouldCount = false;
	}

	std::cout << counter << std::endl;
	return 0;
}
