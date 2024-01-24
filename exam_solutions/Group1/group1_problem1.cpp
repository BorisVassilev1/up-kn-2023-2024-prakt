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

// compares if two sorted arrays contain the same elements
bool areSame(int *arr1, int *arr2, size_t size) {
	size_t ind1 = 0, ind2 = 0;
	while(ind1 < size || ind2 < size) {
		if(ind1 < size - 1 && arr1[ind1] == arr1[ind1+1]) {
			++ind1; continue;
		}
		if(ind2 < size - 1 && arr2[ind2] == arr2[ind2+1]) {
			++ind2; continue;
		}
		if(arr1[ind1] != arr2[ind2]) return false;
		++ind1; ++ind2;
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
