#include <fstream>
#include <cstring>

int main() {
	std::ofstream of("strings.bin", std::ios::binary);

	const char * strings [] = {"asd", "Hello there", "General Kenobi"};

	for(const char *str : strings) {
		for(size_t i = 0; i <= strlen(str); ++i) {
			if(str[i] == 0) of << (char)4;
			else of << str[i];
		}
	}
}
