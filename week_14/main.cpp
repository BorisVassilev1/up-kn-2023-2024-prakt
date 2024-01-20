#include <fstream>
#include <iostream>

int main() {
	std::ofstream out("test.txt");
	
	out << "Hello World!!" << std::endl;

	out.close();

	
	std::ifstream in("week_14/array.bin", std::ios::binary);
	if(!in) {
		std::cout << "file does not exist" << std::endl;
		return 1;
	}
	
	while(!in.eof()) {
		char c = in.get();
		if(in)
			std::cout << c;
	}

	in.close();

}
