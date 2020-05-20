#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	set<vector <int>> perm;
	vector<int> temp;
	do {
		temp.clear();
		for (int i = 0; i < m; i++) {
			temp.push_back(v[i]);
		}
		perm.insert(temp);
	}
	while (next_permutation(v.begin(), v.end()));

	set<vector <int> >::iterator iter;
	for (iter = perm.begin(); iter != perm.end(); iter++) {
		for (int i = 0; i < (*iter).size(); i++) {
			cout << (*iter)[i] << ' ';
		}
		cout << '\n';
	}
}