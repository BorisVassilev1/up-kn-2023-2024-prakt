#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int fact(int n) {
	if(n == 0) return 1;
	return n * fact(n-1);
}

int _fib[100000];

int fib(int n) {
	if(_fib[n] != -1) return _fib[n];
	if(n == 0) {
		_fib[0] = 0;
		return 0;
	}
	if(n == 1) {
		_fib[1] = 1;
		return 1;
	}
	_fib[n] = fib(n-1) + fib(n-2);
	return _fib[n];
}

int fib_iter_helper(int n, int i, int prev, int curr) {
	if(i == n) return curr;
	return fib_iter_helper(n, i + 1, curr, prev + curr);
}

int fib_iter(int n) {
	if(n < 2) return n;
	return fib_iter_helper(n, 1, 0, 1);
}

int max_arr(const int *const arr, const std::size_t len) {
	if(len == 1) return *arr;
	return std::max(*arr, max_arr(arr + 1, len - 1));
}


int main() {
	//for(int i = 0; i < 100000; ++ i) {
	//	_fib[i] = -1;
	//}

	//cout << fib( 50 )<< endl;


	//cout << fib_iter(0) << endl;
	//cout << fib_iter(1) << endl;
	//cout << fib_iter(2) << endl;
	//cout << fib_iter(3) << endl;
	//cout << fib_iter(4) << endl;
	//cout << fib_iter(5) << endl;
	//cout << fib_iter(6) << endl;
	//cout << fib_iter(50) << endl;

	int arr[] = {2, 5, 2, 1, 69, 7, -10, -420};
	cout << max_arr(arr, 8) << endl;
	

}
