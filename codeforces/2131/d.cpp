#include <bits/stdc++.h>
using namespace std;

int main() {
	//cin.tie(0)->sync_with_stdio(0);
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

		
		// for each node, count: 
		// # of leaves it contains
		// # of leaves that are not itself
		vector<pair<int, int>> dp(n);
		vector<int> par(n);
		auto dfs = [&](this auto dfs, int u, int p = -1) -> pair<int, int> {
			par[u] = p;
			pair<int, int> cur = {0, 0};
			for (int v : adj[u]) if (v != p) {
				pair<int, int> res = dfs(v, u);
				cur.first += res.first;
				cur.second += res.first;
			}
			if (cur.first == 0) { // leaf node
				cur.first = 1;
			}
			return dp[u] = cur;
		};

		int ans = n;

		auto dfs2 = [&](this auto dfs2, int u, int p = -1) -> void {
//			cout << "u: " << dp[u].second << " " << (dp[0].first - dp[u].first) << '\n';
			int cnt = 0;
			for (int v : adj[u]) if (v != p) {
				cnt += dp[v].second;	
				dfs2(v, u);
			}
			ans = min(ans, cnt + (dp[0].first + (adj[0].size() == 1 && par[u] != 0) - dp[u].first)); // all other subtrees
		};

		dfs(0);
		dfs2(0);

		cout << ans << '\n';
	}
}



					
