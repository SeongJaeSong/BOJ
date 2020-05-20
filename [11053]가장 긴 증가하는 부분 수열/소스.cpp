#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	lis.push_back(A[0]);
	for (int i = 1; i < A.size(); i++) {
		if (lis.back() < A[i]) lis.push_back(A[i]);
		else {
			lis[lower_bound(lis.begin(), lis.end(), A[i])-lis.begin()] = A[i];
		}
	}
	cout << lis.size() << '\n';
}