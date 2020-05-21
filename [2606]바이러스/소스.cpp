#include <iostream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;
int main() {
	int com, net;
	cin >> com >> net;
	pair<int, int> p;
	stack<int> s;
	vector<bool> inj(com + 1, false);
	bool adj[101][101] = { 0, };
	for (int i = 1; i <= net; i++) {
		cin >> p.first >> p.second;
		adj[p.first][p.second] = 1;
		adj[p.second][p.first] = 1;
	}
	s.push(1); inj[1] = true;
	while (!s.empty()) {
		for (int i = 1; i <= com; i++) {
			if (!inj[i] && adj[s.top()][i] == 1) {
				s.push(i);
				inj[i] = true;
				i = 1;
			}
		}
		s.pop();
	}
	int cnt = 0;
	for (int i = 2; i < inj.size(); i++) {
		if (inj[i]) {
			cnt++;
		}
	}
	cout << cnt;
}