#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	int answer = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(dp[i], answer);
	}

	cout << answer;
}