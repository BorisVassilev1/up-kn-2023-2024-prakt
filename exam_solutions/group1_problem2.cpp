#include <cstddef>
#include <iostream>

using std::size_t;

/*
A8
4
E8 A4 C4 C1

-> 3
*/

const size_t BOARD_SIZE = 8;

// get coords from two chars chess notation
void getCoords(char a, char b, size_t &x, size_t &y) {
	x = a - 'A';
	y = b - '0';
}

// try to go in a direction
bool moveInDir(size_t &x, size_t &y, int dirX, int dirY, int board[BOARD_SIZE][BOARD_SIZE]) {
	do {
		x += dirX;
		y += dirY;
	} while(x < BOARD_SIZE && y < BOARD_SIZE && board[x][y] == 0);

	// returns true if it found a figure to take, 0 if it just got out of bounds
	return x < BOARD_SIZE && y < BOARD_SIZE;
}

size_t maxTurns(size_t x, size_t y, int board[BOARD_SIZE][BOARD_SIZE]) {
	size_t res = 0;
	size_t x_cpy, y_cpy;
	int curr_state = board[x][y];
	board[x][y] = 0;

	// try to go in all directions
	x_cpy = x; y_cpy = y;
	if(moveInDir(x_cpy, y_cpy,  1,  0, board)) res = std::max(res, 1 + maxTurns(x_cpy, y_cpy, board));
	x_cpy = x; y_cpy = y;
	if(moveInDir(x_cpy, y_cpy, -1,  0, board)) res = std::max(res, 1 + maxTurns(x_cpy, y_cpy, board));
	x_cpy = x; y_cpy = y;
	if(moveInDir(x_cpy, y_cpy,  0,  1, board)) res = std::max(res, 1 + maxTurns(x_cpy, y_cpy, board));
	x_cpy = x; y_cpy = y;
	if(moveInDir(x_cpy, y_cpy,  0, -1, board)) res = std::max(res, 1 + maxTurns(x_cpy, y_cpy, board));

	board[x][y] = curr_state;

	return res;
}

int main() {
	int	   board[BOARD_SIZE][BOARD_SIZE] = {0};
	size_t rookX, rookY;
	char   a, b;	 // temporary chars for input
	std::cin >> a >> b;
	getCoords(a, b, rookX, rookY);

	size_t n;	  // number of figures
	std::cin >> n;
	for (size_t i = 0; i < n; ++i) {
		std::cin >> a >> b;
		size_t x, y;
		getCoords(a, b, x, y);
		board[x][y] = 1;
	}
	
	std::cout << maxTurns(rookX, rookY, board);
	
}
