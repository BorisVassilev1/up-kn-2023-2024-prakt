#include <iostream>

int main() {
	int N;
	std::cin >> N;

	int counter = 0;
	bool shouldCount = true;
	int prev = -1;

	for(int i = 0; i < N; ++ i) {
		int curr;
		std::cin >> curr;
		
		if(curr > prev && shouldCount) ++ counter;
		else shouldCount = false;

		prev = curr;
	}

	std::cout << counter << std::endl;
	return 0;
}
