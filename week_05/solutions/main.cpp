#include <iostream>

void writeDigits(char str[], std::size_t n) {
	for(std::size_t i = 0; i < n; ++ i) {
		str[i] = '0' + (i % 10);
	}
	str[n] = '\0';
}

std::size_t strlen(const char str[]) {
	std::size_t size = 0;
	while(str[size] != '\0') {
		++ size;
	}
	return size;
}

void strcpy(char dest[], const char src[]) {
	std::size_t i = 0;
	while(src[i] != '\0') {
		dest[i] = src[i];
		++ i;
	}
	dest[i] = '\0';
}

void strcat(char dest[], const char src[]) {
	std::size_t destLen = strlen(dest);
	std::size_t srcLen = strlen(src) + 1;
	for(std::size_t i = 0; i < srcLen; ++ i) {
		dest[i + destLen] = src[i];
	}
}

void revsubstr(char str[], std::size_t begin, std::size_t end) {
	while(begin < end) {
		char tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		//std::swap(str[begin], str[end]);
		++ begin;
		-- end;
	}
}

int main() {
	char str[50] = "";
	writeDigits(str, 15); // str = "012345678901234"
	std::cout << str << std::endl;

	std::cout << strlen("Hello World") << std::endl; // -> 11
	
	{
		char str1[50] = "lmao          asd a d wadawd";
		char str2[] = "I laugned very laudly!";
		strcpy(str1, str2); // str1 = "I laugned very laudly!"
		std::cout << str1 << std::endl;
	}
	
	{
		char str1[50] = "All I want ";
		char str2[] = "for Christmas is YOUUUUU!";
		strcat(str1, str2); // str1 = "All I want for Christmas is YOUUUUU!" 
		std::cout << str1 << std::endl;
	}

	{
		char str[] = "I want to be a programmer!!!";
		revsubstr(str, 15, 24);
		// str = "I want to be a remmargorp!!!"
		std::cout << str << std::endl;
	}

	return 0;
}
