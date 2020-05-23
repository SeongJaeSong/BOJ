#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	vector<vector <int> > tri;
	for (int i = 0; i < n; i++) {
		vector<int> temp(i+1);
		for (int j = 0; j <= i; j++) {
			cin >> temp[j];
		}
		tri.push_back(temp);
	}
	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) dp[i][j] = tri[i][j];
			else if (j == 0) dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
		if (i == n - 1) {
			for (int j = 0; j <= i; j++) {
				if (dp[i][j] > maxSum) maxSum = dp[i][j];
			}
		}
	}
	cout << maxSum;
 	
}