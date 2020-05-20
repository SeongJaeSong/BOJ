#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool desc(int a, int b) {
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), desc);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}
}