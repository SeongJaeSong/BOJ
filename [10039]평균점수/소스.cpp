#include <iostream>
#include <vector>

using namespace std;
int main() {
	vector<int> v;
	int rst = 0;
	int temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 40) {
			rst += 40;
			continue;
		}
		rst += v[i];
	}
	cout << rst / 5;
}