#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[25][25];
bool visit[25][25];
int dir[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };
int houseNum[25*25];
struct point {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char temp;
			cin >> temp;
			matrix[i][j] = temp - '0';
		}
	}
	int complexNum=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && matrix[i][j]) {
				complexNum++;
				queue <point> q; q.push({ i, j });
				while (!q.empty()) {
					point p = q.front(); q.pop();
					matrix[p.x][p.y] = complexNum; 
					for (int k = 0; k < 4; k++) {
						int nextX = p.x + dir[k][0], nextY = p.y + dir[k][1];
						if (nextX < 0 || nextX > n - 1 || nextY < 0 || nextY > n - 1) continue;
						if (!visit[nextX][nextY] && matrix[nextX][nextY]) {
							q.push({ nextX, nextY });
							visit[p.x][p.y] = true;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= complexNum; k++) {
				if (matrix[i][j] == k) houseNum[k]++;
			}
		}
	}
	if(complexNum > 0) sort(houseNum + 1, houseNum + complexNum+1);
	cout << complexNum << '\n';
	for (int i = 1; i <= complexNum; i++) {
		cout << houseNum[i] << '\n';
	}
}