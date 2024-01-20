#include <iostream>

const int MAX_N = 50;

unsigned int countOnes(int mat[MAX_N][MAX_N], std::size_t N, std::size_t i, std::size_t j) {
	if (i >= N || j >= N) return 0;
	if (!mat[i][j]) return 0;
	mat[i][j] = 0;

	unsigned int ans = 1;
	ans += countOnes(mat, N, i + 1, j    );
	ans += countOnes(mat, N, i    , j + 1);
	ans += countOnes(mat, N, i - 1, j    );
	ans += countOnes(mat, N, i    , j - 1);
	return ans;
}

unsigned int countBiggestOnes(int mat[MAX_N][MAX_N], std::size_t N) {
	unsigned int max = 0;
	for (std::size_t i = 0; i < N; ++i)
		for (std::size_t j = 0; j < N; ++j)
			max = std::max(max, countOnes(mat, N, i, j));
	return max;
}

int main() {
	int			mat[MAX_N][MAX_N];
	std::size_t N;
	std::cin >> N;

	for (std::size_t i = 0; i < N; ++i)
		for (std::size_t j = 0; j < N; ++j)
			std::cin >> mat[i][j];

	std::cout << countBiggestOnes(mat, N) << std::endl;
	return 0;
}
