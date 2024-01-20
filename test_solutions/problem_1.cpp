#include <iostream>

int ans(int a[], std::size_t size, int k) {
	size_t longest = 0;
	size_t current = 1;

	for(std::size_t i = 1; i < size; ++i) {
		if(a[i] == k * a[i-1]) {
			++current;
		} else {
			longest = std::max(current, longest);
			current = 1;
		}
	}
	return std::max(longest, current); // ако прогресията е в края на редицата
}

int main() {
	std::size_t N;
	int k;
	std::cin >> N >> k;
	int *arr = new int[N];
	
	for(std::size_t i = 0; i < N; ++i) {
		std::cin >> arr[i];
	}

	std::cout << ans(arr, N, k) << std::endl;

	delete [] arr;
	return 0;
}
