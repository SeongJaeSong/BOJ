#include <iostream>
#include <vector>

using namespace std;
int main() {
	int temp;
	int min = 2001;
	int rst = 0;

	for (int i = 0; i < 3; i++) {
		cin >> temp;
		if (temp < min) {
			min = temp;
		}
	}
	rst += min;
	min = 2001;
	for (int i = 0; i < 2; i++) {
		cin >> temp;
		if (temp < min) {
			min = temp;
		}
	}
	rst += min;
	cout << rst-50;
}