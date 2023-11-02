#include <ios>
#include <iostream>

bool isPrime(unsigned int n) {
	if(n <= 1) return false;
	for (int i = 2; i < n; ++ i) {
		if(n % i == 0)
			return false;
	}
	return true;
}

void printPrimes(unsigned int n) {
	unsigned int foundPrimes = 0;
	for(int i = 2; foundPrimes < n; ++ i) {
		if(isPrime(i)) {
			std::cout << i << ' ';
			++ foundPrimes;
		}
	}
}

void decompose(unsigned int n) {
	bool hasFoundFirstDivisor = false;
	unsigned int count = 0;
	for (unsigned int i = 2; i <= n; ++ i) {
		count = 0;
		while(n % i == 0) {
			n = n / i;	
			++ count;
		}
		if(count > 0) {
			if(hasFoundFirstDivisor) std::cout << '*';
			hasFoundFirstDivisor = true;
			std::cout << i << '^' << count;
		}
	}
	std::cout << std::endl;
}

int main() {
	std::cout << std::boolalpha << isPrime(79) << std::endl;
	std::cout << std::boolalpha << isPrime(1) << std::endl;
	std::cout << std::boolalpha << isPrime(12) << std::endl;

	decompose(182378912);
	
	printPrimes(100);

	return 0;
}
