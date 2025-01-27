/*
 * find connected components in G
 * cc[i] = connected component node i belongs to in G
 *
 * ans = 0 
 * consider edges (i, j) in F
 * if cc[i] != cc[j], add 1 to answer and do not consider this edge
 * otherwise merge these two nodes into connected components
 *
 * we now have a graph of CCs which we can then merge to form G
 * for all edges in G, if the two nodes are not in the same cc, merge them.
 */
#include <bits/stdc++.h>
using namespace std;

struct dsu {
	int n;
	vector<int> par, sz;

	dsu(int _n) {
		n = _n;
		sz.assign(n, 1);
		par.resize(n);
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		par[y] = x;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m1, m2; cin >> n >> m1 >> m2;
		vector<array<int, 2>> fe(m1), ge(m2);
		for (auto& [x, y] : fe) {
			cin >> x >> y;
			--x; --y;
		}
		for (auto& [x, y] : ge) {
			cin >> x >> y;
			--x; --y;
		}

		dsu g(n);
		for (auto [x, y] : ge) {
			g.merge(x, y);
		}
		
		int ans = 0;
		dsu f(n);
		for (auto [x, y] : fe) {
			if (g.find(x) != g.find(y)) {
				ans++;
			} else {
				f.merge(x, y);
			}
		}

		for (auto [x, y] : ge) {
			if (f.find(x) != f.find(y)) {
				f.merge(x, y);
				ans++;
			}
		}
		cout << ans << '\n';
	}
}



