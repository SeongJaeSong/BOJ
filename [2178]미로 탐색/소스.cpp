#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool visit[102][102];
int maze[102][102];
int dir[4][2] = { { 1, 0 },{ 0,1 },{ 0,-1 }, { -1,0 } }; //ÇÏ¿ìÁÂ»ó
int n, m;
struct node {
	int x, y, d;
};
queue<node> q;
int bfs(int startX, int startY) {
	q.push({startX, startY, 1}); visit[startX][startY] = 1;
	node p;
	while (1) {
		p = q.front(); q.pop();
		if (p.x == n && p.y == m) {
			return p.d;
		}
		for (int i = 0; i < 4; i++) {
			int nextX = p.x + dir[i][0], nextY = p.y + dir[i][1];
			if (!visit[nextX][nextY] && maze[nextX][nextY]) {
				q.push({ nextX, nextY, p.d+1 });
				visit[nextX][nextY] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp-'0';
		}
	}
	cout << bfs(1, 1);
}