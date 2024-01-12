#include <cstring>
#include <iomanip>
#include <iostream>

using std::size_t;

void printArray(const int a[], std::size_t size) {
	for (std::size_t i = 0; i < size; ++i) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	return;
}

char *_malloc(size_t size) { return new char[size]; }

int *sortCopy(int *arr, size_t size) {
	int *copy = new int[size];
	for (size_t i = 0; i < size; ++i)
		copy[i] = arr[i];
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size - i - 1; ++j)
			if (copy[j] > copy[j + 1]) std::swap(copy[j], copy[j + 1]);
	return copy;
}

int **makeMatrix(size_t y, size_t x) {
	int **arr = new int *[y];
	for (size_t i = 0; i < y; ++i) {
		arr[i] = new int[x]{0};
	}
	return arr;
}

char *toString(int n) {
	int size  = 0;
	int n_cpy = n;
	while (n_cpy != 0) {
		++size;
		n_cpy /= 10;
	}
	char *res = new char[size + 1];
	for (int i = 1; n != 0; ++i) {
		res[size - i] = '0' + (n % 10);
		n /= 10;
	}
	res[size] = '\0';
	return res;
}

void deleteMatrix(int **arr, size_t y) {
	for (size_t i = 0; i < y; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void printMatrix(int **matrix, std::size_t height, std::size_t width) {
	for (size_t i = 0; i < height; ++i) {
		std::cout << "|";
		for (size_t j = 0; j < width; ++j) {
			std::cout << std::setw(2) << matrix[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

char *getWord(const char *str, const std::size_t n) {
	std::size_t word_count = 0;
	std::size_t offset	   = 0;
	std::size_t len		   = strlen(str);
	while (word_count < n && offset < len) {
		if (str[offset] == ' ') ++word_count;
		++offset;
	}
	std::size_t word_size  = 0;
	std::size_t word_begin = offset;
	while (str[offset] != ' ' && offset < len) {
		++word_size;
		++offset;
	}
	char *res	   = new char[word_size + 1];
	res[word_size] = '\0';
	// std::memcpy(res, str + word_begin, word_size); // същото като долното
	for (std::size_t i = 0; i < word_size; ++i)
		res[i] = str[word_begin + i];
	return res;
}

void resize(int *&arr, const std::size_t size, const std::size_t newSize) {
	int *res = new int[newSize];

	for (std::size_t i = 0; i < std::min(size, newSize); ++i) {
		res[i] = arr[i];
	}

	delete[] arr;
	arr = res;
}

void reduce(int *&arr, const std::size_t n, const std::size_t groups) {
	std::size_t i = 0;
	for (; i * groups < n; ++i) {
		std::size_t offset = i * groups;
		arr[i]			   = arr[offset];
		for (std::size_t j = 1; j < groups && offset + j < n; ++j) {
			arr[i] += arr[offset + j];
		}
	}
	resize(arr, n, i);
}

int *merge(const int *arr1, std::size_t size1, const int *arr2, std::size_t size2) {
	std::size_t size = size1 + size2;
	int *merged = new int[size];
	std::size_t i1 = 0, i2 = 0, offset = 0;
	while(offset < size) {
		if(i1 < size1 && i2 < size2) {
			if(arr1[i1] < arr2[i2]) {
				merged[offset] = arr1[i1];
				++ i1;
			} else {
				merged[offset] = arr2[i2];
				++i2;
			}
		} else if(i1 < size1) {
				merged[offset] = arr1[i1];
				++ i1;
		} else {
			merged[offset] = arr2[i2];
			++i2;
		}
		++offset;
	}
	return merged;
}

int main() {
	// 2
	int *arr	= new int[]{2, 3, 1, 7, 2, 5};
	int *sorted = sortCopy(arr, 6);
	printArray(arr, 6);
	printArray(sorted, 6);

	delete[] arr;
	delete[] sorted;

	// 3
	int **mat = makeMatrix(5, 3);
	printMatrix(mat, 5, 3);

	deleteMatrix(mat, 5);
	
	// 4
	char *num = toString(1234);
	std::cout << num << std::endl;
	delete[] num;

	// 5
	char *word = getWord("Hello big world", 2);
	std::cout << word << std::endl;
	delete[] word;

	// 6
	int *arrr = new int[]{1, 2, 3, 4, 5};
	resize(arrr, 5, 7);
	arrr[5] = -5;
	arrr[6] = -7;
	printArray(arrr, 7);
	delete[] arrr;

	// 7
	int *grouping = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
	reduce(grouping, 9, 2);
	printArray(grouping, 5);
	delete[] grouping;

	// 8
	int *m1 = new int[]{1,3,5,7}, *m2 = new int[]{0,2,4,6,8,10};
	int *merged = merge(m1, 4, m2, 6);
	printArray(merged, 10);
	delete[] merged;
	delete[] m1;
	delete[] m2;

	return 0;
}
