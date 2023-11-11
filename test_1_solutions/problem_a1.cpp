#include <iostream>

char getRelation(int a, int b) {
	if (a > b) return '>';
	if (a < b) return '<';
	else return '=';
}

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << a << getRelation(a, b) << b << getRelation(b, c) << c << getRelation(c, a) << a << std::endl;
}
