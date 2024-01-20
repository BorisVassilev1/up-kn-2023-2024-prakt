#include <cstddef>
#include <iostream>

struct Vector { double x, y; };

double lengthSq(const Vector& v) {
	return v.x * v.x + v.y * v.y;
}

void sortVectors(Vector arr[], std::size_t size) {
	for(std::size_t i = 0; i < size; ++i) {
		for(std::size_t j = 1; j < size - i; ++j) {
			if(lengthSq(arr[j]) < lengthSq(arr[j-1])) {
				std::swap(arr[j], arr[j-1]);
			}
		}
	}
}

int main() {
	Vector arr[] = {5,4,2,3,3,4,1,2};
	sortVectors(arr, 4);
	for(std::size_t i = 0; i < 4; ++i) {
		std::cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
	}
	return 0;
}
