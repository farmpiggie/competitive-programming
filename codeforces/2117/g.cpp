// can we binary search twice?
// once on answer, then once again on the weight of largest edge
// have all edges sorted by weight
// when evaluating a largest edge, keep adding edges of descending weight until connectivity is established.
// if the graph is connected, can we not just always use the lowest edge?
// i guess we can, but its possible that path to lowest edge involves some really heavy path.
//
// perhaps we do this via dsu
// we start adding edges from smallest to largest and in each component, keep track of the smallest and largest edge weight
// everytime we add an edge, answer = min(answer, min + max of dsu with 1 and n)
// answer should just be this
#include <bits/stdc++.h>
using namespace std;

struct dsu {
	int n;
	vector<int> par, sz, low, high;

	dsu(int _n) {
		n = _n;
		par.resize(n);
		sz.assign(n, 1);
		iota(par.begin(), par.end(), 0);
		low.assign(n, INT_MAX);
		high.assign(n, INT_MIN);
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void merge(int w, int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			low[x] = min(low[x], w);
			high[x] = max(high[x], w);
			return;
		}
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		par[y] = x;
		low[x] = min(low[x], min(low[y], w)); // w can never be a low
		high[x] = max(high[x], max(high[y], w)); // w will always be max since we merge small -> large
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<array<int, 3>> edges(m);
		for (auto &[w, x, y] : edges) {
			cin >> x >> y >> w;
			--x; --y;
		}

		dsu uf(n);
		
		sort(edges.begin(), edges.end());

		int ans = INT_MAX;

		for (auto [w, x, y] : edges) {
			uf.merge(w, x, y);
			if (uf.find(0) == uf.find(n - 1)) {
				int cc = uf.find(0);
				ans = min(ans, uf.low[cc] + uf.high[cc]);
			}
		}

		cout << ans << '\n';
	}
}



