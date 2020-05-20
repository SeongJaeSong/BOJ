#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n * 2; i++) {
		if (flag) {
			for (int j = 0; j < n; j++) {
				if (j % 2 == 0) cout << "*";
				else cout << " ";
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j % 2 == 0) cout << " ";
				else cout << "*";
			}
		}
		cout << endl;
		flag = !flag;
	}
}