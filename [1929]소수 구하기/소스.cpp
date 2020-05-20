#include <iostream>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	vector<bool> isPrime(n+1, true);

	for (int i = 2; i*i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j <= n; j+=i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i < isPrime.size(); i++) {
		if (isPrime[i] && i >= m) {
			cout << i << '\n';
		}
	}
}