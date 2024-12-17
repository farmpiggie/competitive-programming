#include <bits/stdc++.h>
using namespace std;

#define ll long long 
struct dsu {
	// cnt = # of wifi nodes in CC
	vector<int> par, sz;

	dsu(int n) {
		par = vector<int>(n);
		sz = vector<int>(n, 1);
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

	bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, p; cin >> n >> m >> p;
		vector<int> wifi(n, 0);
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
	
		dsu uf(n);
		
		vector<int> cnt(2 * n - 1, 0); // count of wifi nodes
		vector<int> weight(2 * n - 1, 0); // weight of each node
		vector<int> par(n, -1); // what value between [0..2n) does the CC of uf.find(i) correspond to?
		vector<vector<pair<ll, int>>> adj(2 * n - 1); // {weight, node}
		iota(par.begin(), par.end(), 0);
		for (int i = 0; i < n; i++) cnt[i] = wifi[i];
		int nxt = n;
		for (auto& [w, u, v] : edges) if (!uf.same(u, v)) {
			u = uf.find(u), v = uf.find(v);
			// add edges
			ll wu = (ll) (w - weight[par[u]]) * cnt[par[u]];
			ll wv = (ll) (w - weight[par[v]]) * cnt[par[v]]; 
			adj[par[u]].push_back(make_pair(wu, nxt));
			adj[par[v]].push_back(make_pair(wv, nxt));
			adj[nxt].push_back(make_pair(wu, par[u]));
			adj[nxt].push_back(make_pair(wv, par[v]));

			// update cnt + weight
			cnt[nxt] = cnt[par[u]] + cnt[par[v]];
			weight[nxt] = w;
			
			// update DSU
			uf.merge(u, v);
			// update parent of said component to point to nxt.
			par[uf.find(u)] = nxt; // point this new cc to nxt
			nxt++;
		}

		vector<ll> ans;

		auto dfs = [&](this auto dfs, int node, int par = -1) -> ll {
			if (adj[node].size() == 1) return 0; // leaf
			vector<ll> lengths;
			for (auto [w, nei] : adj[node]) if (nei != par) {
				ll res = dfs(nei, node);
				res += (ll) cnt[nei] * (weight[node] - weight[nei]);
				lengths.push_back(res);
			}
			assert(lengths.size() == 2);
			ans.push_back(min(lengths[0], lengths[1]));
			return max(lengths[0], lengths[1]);
		};

		ans.push_back(dfs(2 * n - 2));
		sort(ans.begin(), ans.end());
		for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
		for (int i = n - 2; i >= 0; i--) cout << ans[i] << " ";
		cout << 0 << '\n';
	}
	return 0;
}
