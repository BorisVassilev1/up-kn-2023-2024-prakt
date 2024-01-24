#include <iostream>

struct intarray {
	int	  *arr;
	size_t size;
};

// does an array contain a number
bool contains(const intarray &a, int num) {
	for (size_t i = 0; i < a.size; ++i) {
		if (num == a.arr[i]) return true;
	}
	return false;
}

// a criminally inefficient solution, but a simple one
intarray sub(const intarray &a, const intarray &b) {
	intarray res;
	int		 count = 0;
	for (size_t i = 0; i < a.size; ++i) {
		if (!contains(b, a.arr[i])) ++count;
	}

	res.arr	 = new int[count];
	res.size = count;

	size_t insertIndex = 0;
	for (size_t i = 0; i < a.size; ++i) {
		if (!contains(b, a.arr[i])) res.arr[insertIndex++] = a.arr[i];
	}

	return res;
}

int main() {
	intarray a;
	a.arr  = new int[]{1, 2, 3, 4, 5};
	a.size = 5;

	intarray b;
	b.arr  = new int[]{4, 5, 6, 7, 8};
	b.size = 5;

	intarray c = sub(a, b);
	for (size_t i = 0; i < c.size; ++i) {
		std::cout << c.arr[i] << " ";
	}
	std::cout << std::endl;

	delete[] a.arr;
	delete[] b.arr;
	delete[] c.arr;
}
