#include <iostream>

using namespace std;

unsigned long long fibonacci[91] = { 0, };

unsigned long long fib(int n) {
	if (n == 0) return 0;
	else if (n < 2) return 1;
	if (fibonacci[n] != 0) {
		return fibonacci[n];
	}
	else {
		fibonacci[n] = fib(n - 2) + fib(n - 1);
		return fibonacci[n];
	}
		
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << fib(n);
}