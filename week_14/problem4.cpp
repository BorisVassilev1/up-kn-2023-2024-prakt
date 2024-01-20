#include <iostream>
#include <fstream>

int main() {
	std::ofstream out("week_14/array2.bin");
	
	int *arr = new int[]{1,2,3,4,5,6};
	std::size_t size = 6;
	
	out.write((char*)&size,sizeof(std::size_t));
	out.write((char*)arr,sizeof(int)*size);
	delete [] arr;
	out.close();
}
