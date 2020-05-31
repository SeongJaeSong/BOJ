#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
struct point {
	int x, y;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k, ans=0;
		cin >> n >> m >> k;
		int field[50][50] = { 0, };
		bool visit[50][50] = { false, };
		for (int i = 0; i < k; i++) {
			point p;
			cin >> p.x >> p.y;
			field[p.x][p.y] = 1;
		}
		queue<point> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] == false && field[i][j] == 1) {
					ans++;
					q.push({ i, j });
					while (!q.empty()) {
						point p = q.front(); q.pop();
						for (int i = 0; i < 4; i++) {
							int nextX = p.x + dir[i][0], nextY = p.y + dir[i][1];
							if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
							if (field[nextX][nextY] == 1 && visit[nextX][nextY] == false) {
								q.push({ nextX, nextY });
								visit[nextX][nextY] = true;
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}