#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	long long dp[2][10] = { {0,1,1,1,1,1,1,1,1,1} };
	long long sum = 9;
	for (int i = 1; i < n; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i%2][j] = (dp[(i+1)%2][j + 1])%MOD;
			}
			else if (j == 9) {
				dp[i%2][j] = (dp[(i+1)%2][j - 1])%MOD;
			}
			else {
				dp[i%2][j] = (dp[(i+1)%2][j - 1] + dp[(i+1)%2][j + 1])%MOD;
			}
			sum += dp[i % 2][j];
		}
	}

	cout << sum % MOD;
}
