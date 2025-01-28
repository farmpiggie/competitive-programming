#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<int> in(n, 0);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			in[u]++;
			in[v]++;
		}


		// dp[i] = max(in[j]) for j in subtree of i, not including i itself.
		// consider we take a node in subtree of i, then i itself.
		// ans = in[u] + max(dp[v] - 1, inv[v] - 2) s.t. par[v] = u

		vector<int> dp(n, -1e9);
		int ans = 0;
		auto dfs = [&](this auto dfs, int u, int p = -1) -> void { // node, parent
			vector<int> a;
			for (int v : adj[u]) if (v != p) {
				dfs(v, u);
				a.push_back(max(in[v], dp[v]));
				dp[u] = max(dp[u], max(in[v], dp[v])); 
				ans = max(ans, in[u] + max(dp[v] - 1, in[v] - 2)); // not connected vs connected
			}
			if (a.size() >= 2) {
				sort(a.rbegin(), a.rend());
				ans = max(ans, 1 + (a[0] - 1) + (a[1] - 1));
			}	
		};

		dfs(0);
		cout << ans << '\n';
	}
}
			

