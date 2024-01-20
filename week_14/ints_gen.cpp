#include <fstream>
#include <iostream>

int main() {
	std::ofstream of("array.bin", std::ios::binary);

	int arr[] = {10, 20, 30, 40, 69, 315, 42};
	std::size_t size = sizeof(arr) / sizeof(int);

	of.write((char*) &size, sizeof(std::size_t));
	of.write((char*) arr, sizeof(arr));
}
