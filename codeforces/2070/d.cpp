#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<int> par(n, -1), d(n, 0);
		for (int i = 1; i < n; i++) {
			cin >> par[i];
			--par[i];
			adj[i].push_back(par[i]);
			adj[par[i]].push_back(i);
		}
		
		int max_depth = 0;
		auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
			if (p == -1) d[u] = 0;
			else d[u] = d[p] + 1;
			max_depth = max(max_depth, d[u]);

			for (int v : adj[u]) if (v != p) {
				dfs(v, u);
			}
		};

		dfs(0);

		vector<vector<int>> layers(max_depth + 1);
		for (int i = 0; i < n; i++) {
			layers[d[i]].push_back(i);
		}
		
		vector<ll> dp(n, 0);
		dp[0] = 1;
		for (int i = 1; i <= max_depth; i++) {
			ll prev = 0;
			for (int u : layers[i - 1]) {
				prev = (prev + dp[u]) % MOD;
			}
//			cout << "prev: " << prev << '\n';
			for (int u : layers[i]) {
//				cout << u << ' ';
				dp[u] = (prev - (par[u] ? dp[par[u]] : 0) + MOD) % MOD; // all previous layers but the parent
			}
//			cout << '\n';
	
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans + dp[i]) % MOD;
		}
		cout << ans << '\n';
	}
}











