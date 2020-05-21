#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, v;
bool visit_dfs[1001] = { false, };
void dfs(vector<vector<int>> adj,int start) {
	cout << start << ' ';
	visit_dfs[start] = true;
	for (int j = 0; j < adj[start].size(); j++) {
		int dst = adj[start][j];
		if (!visit_dfs[dst]) {
			dfs(adj, dst);
		}
	}
}

bool visit_bfs[1001] = { false, };
queue <int> q;
void bfs(vector<vector<int> > adj, int start) {
	q.push(start);
	visit_bfs[start] = true;
	while (!q.empty()) {
		for (int i = 0; i < adj[q.front()].size(); i++) {
			int dst = adj[q.front()][i];
			if (!visit_bfs[dst]) {
				q.push(dst);
				visit_bfs[dst] = true;
			}	
		}
		cout << q.front() << ' ';
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int start, end;
	cin >> n >> m >> v;
	vector<vector <int> > adj(n+1);
	
	for (int i = 1; i <= m; i++) {
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(adj, v);
	cout << '\n';
	bfs(adj, v);
}