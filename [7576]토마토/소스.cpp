#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int m, n;

vector<vector <int> > box;
struct tomato {
	int x, y, date;
};

queue <tomato> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n;
	vector<int> temp(m);
	int ans = 0;
	bool flag = true; // 안 익은 토마토가 있는지 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tomato t;
			cin >> temp[j];
			if (temp[j] == 1) {
				t.x = i;
				t.y = j;
				t.date = 0;
				q.push(t);
			}
			else if (temp[j] == 0) {
				flag = false;
			}
		}
		box.push_back(temp);
	}
	if (flag) {
		cout << 0;
		return 0; 
	}
	while (!q.empty()) {
		tomato to = q.front(); q.pop();
		ans = to.date;
		for (int i = 0; i < 4; i++) {
			int nextX = to.x + dir[i][0], nextY = to.y + dir[i][1];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
			if (abs(box[nextX][nextY]) == 1) continue;
			else if (box[nextX][nextY] == 0) {
				q.push({ nextX, nextY, to.date + 1 });
				box[nextX][nextY] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
}