/*
dp[i][j] = solution for connected component rooted at i, with K = j
base case: dp[i][0] = 0, dp[i][1] = 0.

consider merging u and v
new_dp(size(u) + size(v) - 1)
if i == 0 && j == 0:
	new_dp[0] = 0

if i == 0 && j > 0:
	new_dp[j] = min(new_dp[j], dp[v][j] + w * (ll)(size(u) - 1));

if i > 0 && j == 0:
	new_dp[i] = min(new_dp[i], dp[u][i] + w * (ll)(size(v) - 1));

if i > 0 && j > 0:
	new_dp[i + j] = dp[u][i] + dp[v][j]
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define v2l vector<vl>

struct dsu {
	vector<int> par, sz;

	dsu(int n) {
		sz.assign(n, 1);
		par.resize(n, 0);
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		if (par[x] == x) return x;
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
	int t; cin >> t;
	while (t--) {
		int n, m, p; cin >> n >> m >> p;
		vector<int> wifi(n);
		for (int i = 0; i < p; i++) {
			int x; cin >> x;
			--x;
			wifi[x] = 1;
		}
		vector<array<int, 3>> edges;
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			--u; --v;
			edges.push_back({w, u, v});
		}
		sort(edges.begin(), edges.end());

		v2l dp(n);
		for (int i = 0; i < n; i++) {
			dp[i].assign(wifi[i] ? 2 : 1, 0);
		}

		dsu uf(n);
	
		for (auto [w, u, v] : edges) {
			u = uf.find(u), v = uf.find(v);
			if (u == v) continue;

			vector<ll> ndp(dp[u].size() + dp[v].size() - 1, 1e18);
			for (int i = 0; i < dp[u].size(); i++) {
				for (int j = 0; j < dp[v].size(); j++) {
					if (i == 0 && j == 0) ndp[0] = 0;
					if (i == 0 && j > 0) ndp[j] = min(ndp[j], dp[v][j] + 1ll * w * ((int) dp[u].size() - 1));
					if (i > 0 && j == 0) ndp[i] = min(ndp[i], dp[u][i] + 1ll * w * ((int) dp[v].size() - 1));
					if (i > 0 && j > 0) ndp[i + j] = min(ndp[i + j], dp[u][i] + dp[v][j]);
				}
			}

			uf.merge(u, v);
			int x = uf.find(u);
			swap(dp[x], ndp);
		}

		vector<ll> ans = dp[uf.find(0)];

		for (int i = 1; i <= n; i++) 
			cout << (i < p ? ans[i] : 0) << " ";
		
		cout << '\n';
	}
	return 0;
}
