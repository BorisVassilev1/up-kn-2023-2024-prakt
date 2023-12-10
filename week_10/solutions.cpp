#include <iostream>
#include <cstddef>

using std::size_t;
/*
* size = 3
* 1 2 3
* 4 5 6
* 7 8 9
*
* 1 4 2 7 5 3 8 6 9
*
* 1 4 2 3 5 7 8 6 9
*/
const int maxSize = 10;

bool isInBounds(size_t x, size_t y, size_t w, size_t h) {
	return (x < w) && (y < h);
}

void traverseDiagonaly(int mat[maxSize][maxSize], size_t size) {
	for(size_t i = 0; i < 2 * size - 1; ++ i) {
		size_t x, y;
		if(i < size) { // vertikala
			x = 0;
			y = i;
		} else { // nai-dolen red
			x = i - size + 1;
			y = size - 1;
		}

		while(isInBounds(x, y, size, size)) { // obikalqne na diagonal
			std::cout << mat[y][x] << " ";
			-- y;
			++ x;
		}
	}
	std::cout << std::endl;
}

int main() {
	int mat[][maxSize] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	traverseDiagonaly(mat, 3);
}
