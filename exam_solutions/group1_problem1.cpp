#include <iostream>

const int SIZE = 50;
using std::size_t;

// sorts the elements of an array
void sort(int *arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
		}
	}
}

// compares if two arrays are same
bool areSame(int *arr1, int *arr2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}


// the idea for the solution is that two rows of the matrix are similar
// if and only if after a sort the two rows contain the same numbers 
// in the same order
int main() {
	size_t n, m;
	std::cin >> n >> m;

	int mat[50][50];
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			std::cin >> mat[i][j];
		}
		sort(mat[i], m);
	}

	for (size_t i = 1; i < n; ++i) {
		for (size_t j = 0; j < i; ++j) {
			if(areSame(mat[i], mat[j], m)) 
				std::cout << i << " and " << j << " are similar!" << std::endl;
		}
	}
	return 0;
}
