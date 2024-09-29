#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> d(n, -1);

	queue<int> q;

	for (int i = 0; i < k; i++) {
		int u; cin >> u; u--;
		q.push(u);
		d[u] = 0;
	}

	vector<int> indegree(n, 0);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : adj[u]) {
			if (d[v] == -1) {
				indegree[v]++;
				if (indegree[v] == 2) {
					q.push(v);
					d[v] = d[u] + 1;
				}
			}
		}

		if (d[0] != -1) break;
	}

	cout << d[0] << '\n';

	return 0;
}
