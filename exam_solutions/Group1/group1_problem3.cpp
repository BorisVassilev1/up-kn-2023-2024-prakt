#include <iostream>
#include <cstddef>
#include <cstring>

const int MAX_SIZE = 100;

// copy-pasta from problem 1
// sorts the elements of an array
void sort(int *arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
		}
	}
}

bool isDigit(char a) { return a >= '0' && a <= '9'; }

size_t countDigits(const char str[MAX_SIZE]) {
	size_t count = 0;
	for(size_t i = 0; str[i] != '\0'; ++i) {
		if(isDigit(str[i])) ++count;
	}
	return count;
}

int intFromDigits(const int *digits, size_t size) {
	int res = 0;
	for(size_t i = 0; i < size; ++i) {
		res *= 10;
		res += digits[i];
	}
	return res;
}

int minNumber(const char str[MAX_SIZE]) {
	size_t digitsCount = countDigits(str);

	// separate digits in a new array
	int *digits	= new int[digitsCount];
	int digitIndex = 0;
	for(size_t i = 0; str[i] != '\0'; ++i) {
		if(isDigit(str[i])) digits[digitIndex++] = str[i] - '0';
	}
	
	// sort them in ascending order
	sort(digits, digitsCount);
	// account for the eventual 0 in the beginning
	if(digitsCount > 1 && digits[0] == 0) std::swap(digits[0], digits[1]);
	
	size_t res = intFromDigits(digits, digitsCount);
	delete [] digits;
	
	return res;
}

int main() {

	std::cout << minNumber("TiMe323MacHiNe0");
}
