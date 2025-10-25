#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> dist(n, 0);
		auto dfs = [&](this auto dfs, int u, int p = -1, int d = 0) -> void {
			dist[u] = d;
			for (int v : adj[u]) if (v != p) dfs(v, u, d + 1);
		};

		dfs(0);

		int a = 0;
		int far = 0;
		for (int i = 0; i < n; i++) {
			if (dist[i] > far) {
				far = dist[i];
				a = i;
			}
		}

		dfs(a);
		int b = 0;
		far = 0;
		for (int i = 0; i < n; i++) {
			if (dist[i] > far) {
				far = dist[i];
				b = i;
			}
		}

		vector<int> cur, path;
		auto dfs2 = [&](this auto dfs2, int u, int p = -1) -> void {
			cur.push_back(u);
			if (u == b) path = cur;
			for (int v : adj[u]) if (v != p) dfs2(v, u);
			cur.pop_back();
		};
		
		dfs2(a);

		if (n <= 3 || path.size() < 3) {
			cout << "-1\n";
			continue;
		}

		bool printed = false;;
		// diameter is at least 3
		for (int i = 1; i < path.size() - 1; i++) {
			int u = path[i];
			if (adj[u].size() <= 2) continue;
			for (int v : adj[u]) {
				if (v != path[i + 1] && v != path[i - 1]) {
					cout << path[i + 1] + 1 << " " << path[i] + 1 << " " << v + 1 << '\n';
					printed = true;
					break;
				}
			}
			if (printed) break;
		}
		if (!printed) cout << "-1\n";
	}
}





	





