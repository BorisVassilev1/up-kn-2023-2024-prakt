#include <fstream>

struct Point {
	float x, y;
};

int main() {
	std::ofstream of("points.bin", std::ios::binary);

	Point arr[] = {{10, 20}, {30, 40}, {69, 315}, {42, 0.5}};
	std::size_t size = sizeof(arr) / sizeof(Point);

	of.write((char*) &size, sizeof(std::size_t));
	of.write((char*) arr, sizeof(arr));
}
