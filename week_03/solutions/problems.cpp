#include <ios>
#include <iostream>
#include <iterator>
#include <system_error>

// 2
bool isPrime(unsigned int n) {
	if(n <= 1) return false;
	for (int i = 2; i < n; ++ i) {
		if(n % i == 0)
			return false;
	}
	return true;
}

// 3
void printPrimes(unsigned int n) {
	unsigned int foundPrimes = 0;
	for(int i = 2; foundPrimes < n; ++ i) {
		if(isPrime(i)) {
			std::cout << i << ' ';
			++ foundPrimes;
		}
	}
	std::cout << std::endl;
}

// 4
void divisors(unsigned int n) {
	for(int i = 1; i <= n; ++ i) {
		if(n % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

// 5
void decompose(unsigned int n) {
	bool hasFoundFirstDivisor = false;
	unsigned int count = 0;
	for (int i = 2; i <= n; ++ i) {
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

// 6
int digitDifference(unsigned int n) {
	int min = 9;
	int max = 0;
	while(n != 0) {
		int current = n % 10;
		min = std::min(min, current);
		max = std::max(max, current);
		n /= 10;
	}
	return max - min;
}

// 7
void christmasTree(unsigned int n) {
	for(int i = 0; i < n; ++ i) { // row
		for(int j = 0; j < (n - i); ++ j) std::cout << " ";
		std::cout << "*";
		for(int j = 0; j < i; ++ j) std::cout << "**";
		std::cout << std::endl;
	}
	for(int i = 0; i < n; ++ i) std::cout << " ";
	std::cout << "|" << std::endl;
}

// 8 
int supermajority(unsigned int n) {
	int counter = 0;
	int current_supermajority = 0;
	for(int i = 0; i < n; ++ i) {
		int current;
		std::cin >> current;

		if(current == current_supermajority) ++ counter;
		else -- counter;
		
		if(counter < 0) {
			current_supermajority = current;
			counter = 1;
		}
	}
	return current_supermajority;
}

// 9
int pow(int a, unsigned int b) {
	int result = 1;
	for(int i = 0; i < b; ++ i) {
		result *= a;
	}
	return result;
}

// 9*
int fastPow(int a, unsigned int b) {
	int exp = a;
	int result = 1;
	while(b != 0) {
		if(b % 2 == 0) {
			exp *= exp;
			b /= 2;
		} else {
			result *= exp;
			-- b;
		}
	}
	return result;
}

int sumDivisors(unsigned int n) {
	int sum = 0;
	for(int i = 1; i < n; ++ i) {
		if(n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

bool isMagicNumber(unsigned int n) {
	return sumDivisors(n) == n;
}

// 10
void printMagicNumbers(unsigned int a, unsigned int b) {
	for(int i = a; i <= b; ++ i) {
		if(isMagicNumber(i)) std::cout << i << " ";
	}
	std::cout << std::endl;
}

// както се разбрахме, решаваме задачите до 10-та

int main() {
	// 2
	std::cout << std::boolalpha << isPrime(79) << std::endl;
	std::cout << std::boolalpha << isPrime(1) << std::endl;
	std::cout << std::boolalpha << isPrime(12) << std::endl;

	// 3
	printPrimes(5);

	// 4
	divisors(24);

	// 5
	decompose(182378912);
	
	// 6
	std::cout << digitDifference(1234) << std::endl;

	// 7
	christmasTree(5);

	// 8
	//std::cout << supermajority(5) << std::endl;

	// 9
	std::cout << pow(2, 10) << std::endl;
	std::cout << fastPow(2, 10) << std::endl;

	// 10
	printMagicNumbers(7, 500);

	return 0;
}
