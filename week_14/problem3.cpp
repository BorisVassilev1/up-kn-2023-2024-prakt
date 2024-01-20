#include <fstream>
#include <iostream>

int main () {
	std::ifstream in("week_14/array.bin");
	if(!in) {
		std::cout << "file does not exist" << std::endl;
		return 1;
	}

	std::size_t size;
	
	in.read((char *)&size, sizeof(std::size_t));
	int *arr = new int[size];
	in.read((char*)arr, size * sizeof(int));

	// out.write();

	std::cout << size << std::endl;
	for(unsigned int i = 0; i < size; ++ i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	delete []arr;
	in.close();
}
