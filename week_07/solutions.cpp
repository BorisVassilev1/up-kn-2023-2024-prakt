#include <iostream>
#include <iomanip>
#include <algorithm>

const int MAX_WIDTH	 = 50;
const int MAX_HEIGHT = 50;

// 1
void inputMatrix(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t &height, std::size_t &width) {
	std::cin >> width >> height;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	for (int i = 0; i < height; ++i) {
		std::cout << "|";
		for (int j = 0; j < width; ++j) {
			std::cout << std::setw(2) << matrix[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

// 2
void fillRows(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	int counter = 0;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			matrix[i][j] = ++counter;
		}
	}
}

// 3
void fillCols(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	int counter = 0;
	for (int j = 0; j < width; ++j) {
		for (int i = 0; i < height; ++i) {
			matrix[i][j] = ++counter;
		}
	}
}

void transpose(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	if (height >= width) {
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < i; ++j) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	} else {
		for (int i = 0; i < height; ++i) {
			for (int j = i; j < width; ++j) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
}

// 5
bool isSymetrical(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t size) {
	bool res = true;	 // equal 'till proven otherwise
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			res &= matrix[i][j] == matrix[j][i];
		}
	}
	return res;
}

// 6
float dot(int a[], int b[], std::size_t len) {
	float res = 0;
	for (int i = 0; i < len; ++i) {
		res += a[i] * b[i];
	}
	return res;
}
// съкращения с цел четимост
#define W MAX_WIDTH
#define H MAX_HEIGHT
using size_t = std::size_t;

void matmul(int A[H][W], size_t ha, size_t wa, int B[H][W], size_t hb, size_t wb, int C[H][W], size_t &h, size_t &w) {
	// ще имитираме метода "кебапчето в лютеницата",
	// кебапчето ще е ред от двумерния масив, а лютеницата
	// ще я завъртим настрани за да не въртим кебабчето
	if (wa != hb) {
		std::cout << "matmul: invalid matrix sizes";
		return;
	}
	size_t len = ha;
	w		   = wb;
	h		   = ha;
	transpose(B, wb, hb);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			C[i][j] = dot(A[i], B[j], len);
		}
	}
	transpose(B, wb, hb);
}

#undef W
#undef H

// 7

bool isValid(std::size_t y, std::size_t x, std::size_t h, std::size_t w) { return y < h && x < w; }

void fillDiag1(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	int counter = 0;
	for (int i = 0; i < height + width - 1; ++i) {
		int x, y;
		if (i < width) {
			x = i;
			y = 0;
		} else {
			x = width - 1;
			y = i - width + 1;
		}

		while (isValid(y, x, height, width)) {
			matrix[y][x] = ++counter;
			--x;
			++y;
		}
	}
}

// 8
void fillDiag2(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	int counter = 0;
	for (int i = 0; i < height + width - 1; ++i) {
		int x, y;
		if (i < width) {
			x = 0;
			y = height - i - 1;
		} else {
			x = i - height + 1;
			y = 0;
		}

		while (isValid(y, x, height, width)) {
			matrix[y][x] = ++counter;
			++x;
			++y;
		}
	}
}

// 9
void fillSnake(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	int counter	  = 0;
	int direction = 1;
	int x = 0, y = 0;

	for (int i = 0; i < height + width - 1; ++i) {
		while (isValid(y, x, height, width)) {
			matrix[y][x] = ++counter;
			x += direction;
			y -= direction;
		}
		direction = -direction;

		// ако излезем от матрицата, се преместваме на подходящо място
		if (x >= (int)width) {
			--x;
			y += 2;
		} else if (y < 0) {
			++y;
		} else if (y >= (int)height) {
			--y;
			x += 2;
		} else {	 // x < 0
			++x;
		}
	}
}

void sortColumns(int matrix[MAX_HEIGHT][MAX_WIDTH], std::size_t height, std::size_t width) {
	// по-трудно ще е да сортираме елементи, които не са последователни в паметта
	// за това обръщаме матрицата, така че да колоните да станат редове, които можем да сортираме като нормални масиви.
	transpose(matrix, height, width);
	for (int i = 0; i < width; ++i) {
		std::sort(matrix[i], matrix[i] + height);
		// или или използваме bubbleSort или selectionSort от предната седмица
	}
	transpose(matrix, height, width);
}

int main() {
	{ // 6
		int A[50][50] = {{0, 1}, {-1, 0}}, wa = 2, ha = 2;
		int B[50][50] = {{2}, {3}}, wb = 1, hb = 2;
		int C[50][50];

		std::size_t h, w;

		matmul(A, ha, wa, B, hb, wb, C, h, w);

		printMatrix(A, ha, wa);
		std::cout << std::endl;

		printMatrix(B, hb, wb);
		std::cout << std::endl;

		printMatrix(C, h, w);
		std::cout << std::endl;
	}

	{ // 7
		int A[50][50] = {0};
		fillDiag1(A, 5, 5);
		printMatrix(A, 5, 5);
		std::cout << std::endl;
	}

	{ // 8
		int A[50][50] = {0};
		fillDiag2(A, 5, 5);
		printMatrix(A, 5, 5);
		std::cout << std::endl;
	}

	{ // 9
		int A[50][50] = {0};
		fillSnake(A, 5, 5);
		printMatrix(A, 5, 5);
		std::cout << std::endl;
	}

	{ // 10
		int A[50][50] = {{4, 5, 2, 3}, {1, 2, 3, 4}, {0, 3, 1, 1}};
		sortColumns(A, 3, 4);
		printMatrix(A, 3, 4);
		std::cout << std::endl;
	}
}
