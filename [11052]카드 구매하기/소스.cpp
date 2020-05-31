#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	int n;
	double ans = 0;
	cin >> n;
	vector<int> v(n+1);
	vector<int> dp(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j]+v[j]);
		}
	}
	cout << dp[n];
}