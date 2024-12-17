#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define v2i vector<vi>
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v2i adj(n, vi(0));
		vi a(n);
		for (ll& x : a) cin >> x;
		
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		ll cost = 0; // cost anchored at 0
		vector<ll> size(n, 0);
		auto dfs = [&](this auto dfs, int node, int par = -1) -> int {
			int sz = 1;
			for (int nei : adj[node]) if (nei != par) sz += dfs(nei, node);
			if (par != -1) cost += sz * (a[node] ^ a[par]);
//			if (par != -1) cout << "adding this to cost for node " << node << ": " << sz << " * " << (a[node] ^ a[par]) << '\n';
			size[node] = sz;
			return sz;
		};

		dfs(0);

		vector<ll> ans(n);
		ans[0] = cost;

		auto dfs2 = [&](this auto dfs2, int node, int par = -1) -> void {
			if (par != -1) {
				ans[node] = ans[par] + (n - 2 * size[node]) * (a[par] ^ a[node]);
			}
			for (int nei : adj[node]) if (nei != par) dfs2(nei, node);
		};
		dfs2(0);

		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}
