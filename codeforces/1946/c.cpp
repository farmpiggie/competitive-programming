#include <bits/stdc++.h>
using namespace std;


int dfs(int cur, int par, vector<vector<int>>& adj, int& components, int k) {
	int sz = 1;
	for (int nei : adj[cur]) {
		if (nei != par) {
			sz += dfs(nei, cur, adj, components, k);
		}
	}
	if (sz >= k) {
		components++;
		sz = 0;
	}
	return sz;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int v, u; cin >> v >> u;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		int ans = 1;
		int lo = 0, hi = n;
		while (lo <= hi) {
			int mi = lo + (hi - lo) / 2;
			
			int components = 0;
			dfs(0, -1, adj, components, mi);
			if (components >= k + 1) {
				ans = max(ans, mi);
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
		cout << ans << '\n';

	}
	return 0;
}
