#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	vector<vector <int> > house;
	int dp[1000][3];
	cin >> N;
	vector<int> RGB(3);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[j];
		}
		house.push_back(RGB);
	}
	dp[0][0] = house[0][0]; dp[0][1] = house[0][1]; dp[0][2] = house[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}
	cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
}