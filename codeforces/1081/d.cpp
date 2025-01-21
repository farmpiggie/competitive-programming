/*
 * idea: use kruskal's to construct MST?
 * root the tree randomly. prune MST such that the only leaves in the tree are other special nodes.
 * answer should be the largest weight in the tree.
 */

#include <bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par, sz;

	dsu(int n) {
		sz.assign(n, 1);
		par.resize(n, 0);
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		if (x == par[x]) return x;
		else return par[x] = find(par[x]);
	}

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		par[y] = x;
	}
};

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<bool> special(n); // special nodes
	int root = -1;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		--x;
		if (root == -1) root = x;
		special[x] = 1;
	}
	
	vector<array<int, 3>> edges; // [weight, node1, node2]
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; 
		--u; --v;
		edges.push_back({w, u, v});
	}
	sort(edges.begin(), edges.end());

	dsu uf(n);	
	vector<vector<array<int, 2>>> adj(n);// [weight, node]
	for (auto [w, u, v] : edges) {
		if (uf.find(u) != uf.find(v)) {
			uf.merge(u, v);
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
	}
	
	int cost = 0;
	auto dfs = [&](this auto dfs, int node, int par = -1, int weight = 0) -> bool {
		bool valid = special[node];
		for (auto [w, nei] : adj[node]) if (nei != par) valid |= dfs(nei, node, w);
		if (valid) { // edge between node and parent is considered 
			cost = max(cost, weight);
		}
		return valid;
	};
	dfs(root);	
	for (int i = 0; i < k; i++) cout << cost << " ";
	cout << '\n';
	return 0;
}





