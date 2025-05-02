/*
 * root tree at en.
 * process nodes in descending order of distance from en
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, st, en; cin >> n >> st >> en;
		--st; --en;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// dfs to find simple path from u to v
		vector<int> dist(n, 0);
		auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
			if (p == -1) dist[u] = 0;
			else dist[u] = dist[p] + 1;
			for (int v : adj[u]) if (v != p) {
				dfs(v, u);
			}
		};
		
		dfs(en);
		map<int, vector<int>, greater<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[dist[i]].push_back(i);
		}
		for (auto [_, nodes] : mp) {
			for (int u : nodes) {
				cout << u + 1 << ' ';
			}
		}
		cout << '\n';
	}
}





