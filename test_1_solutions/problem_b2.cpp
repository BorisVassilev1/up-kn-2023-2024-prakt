#include <iostream>

int multiples(int a, int b, int x) {
	int counter = 0;
	for (int i = a; i <= b; ++i) {
		if (i % x == 0) { ++counter; }
	}
	return counter;
}

// main-функцията не се изискваше
int main() {
	std::cout << multiples(10, 20, 2) << std::endl;
	return 0;
}
