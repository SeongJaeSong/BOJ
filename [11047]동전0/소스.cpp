#include <iostream>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cnt=0;
	while (k > 0) {
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] <= k) {
				k -= v[i];
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}