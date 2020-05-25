#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[100002];
struct loc {
	int x, cnt;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	int temp;
	queue<loc> q;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		loc v = q.front(); q.pop();

		if (v.x == k) {
			cout << v.cnt;
			return 0;
		}

		if (v.x+1 <= 100000 && !visit[v.x + 1]) {
			q.push({ v.x + 1, v.cnt + 1 });
			visit[v.x + 1] = true;
		}
		if (v.x-1 >= 0 && !visit[v.x - 1]) {
			q.push({ v.x - 1, v.cnt + 1 });
			visit[v.x - 1] = true;
		}
		if (v.x*2<= 100000 && !visit[v.x * 2]) {
			q.push({ v.x * 2, v.cnt + 1 });
			visit[v.x * 2] = true;
		}
	}
}