#include <iostream>

void divisors(int a, int b, int x) {
	for(int i = a; i <= b; ++ i) {
		if(x % i == 0) std::cout << i << " ";
	}
}

// main-функцията не се изискваше
int main() {
	divisors(1, 20, 24);
}
