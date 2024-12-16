/*
run kruskal's?
everytime we merge two CCs together, we can recalculate the cost
consider c1 has cost a and c2 has cost b
if we add an edge of weight w between a node in c1 and a node in c2, the new cost of our (c1 + c2) cc is:
min(a + size(c2) * w, b + size(c1) * w) = x, where size(c1) = # of houses that require internet in CC c1.

at each step, we simply want to take the smallest edge s.t (x - (a + b)) is minimized.
this involves recomputing each edge O(m) everytime we merge O(n) times
thus, answer becomes:

O(n) * O(m) ?
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vp vector<pii>
#define v2p vector<vp>

struct edge {
	int u, v;
	ll w;
};

struct dsu {
	vector<int> par, sz, houses;
	vector<ll> cost;
	
	dsu(int n, vector<int>& is_house) {
		par = vector<int>(n, 0);
		sz = vector<int>(n, 1);
		houses = vector<int>(n, 0);
		cost = vector<ll>(n, 0);
		iota(par.begin(), par.end(), 0);
		for (int house : is_house) houses[house]++;
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void merge(int a, int b, ll w) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		if (houses[a] > 0 || houses[b] > 0) cost[a] = min(cost[a] + houses[b] * w, cost[b] + houses[a] * w); // min cost
		houses[a] += houses[b]; // update houses
	}
};

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, p; cin >> n >> m >> p;
		vector<int> s(p);
		for (int& x : s) {
			cin >> x; --x;
		}
		vector<edge> edges;
		for (int i = 0; i < m; i++) {
			int u, v; ll w; cin >> u >> v >> w;
			--u; --v;
			edges.push_back({u, v, w});
		}
		dsu uf(n, s);
		vector<ll> ans(n, 0);

		auto cmp = [&](const edge& a, const edge& b) {
			if (a.w != b.w) return a.w < b.w;
			else {
				int ax = a.u, ay = a.v, bx = b.u, by = b.v;
				ax = uf.find(ax), ay = uf.find(ay), bx = uf.find(bx), by = uf.find(by); 
				if (ax == ay) return false; // just use b
				if (bx == by) return true; // just use a
				ll acost = min(uf.cost[ax] + uf.houses[ay] * a.w, uf.cost[ay] + uf.houses[ax] * a.w);
				ll bcost = min(uf.cost[bx] + uf.houses[by] * b.w, uf.cost[by] + uf.houses[bx] * b.w);
				return acost - (uf.cost[ax] + uf.cost[ay]) < bcost - (uf.cost[bx] + uf.cost[by]); // adding edge a costs less than adding edge b.
			}
				
		};
		// we want to add (n - 1) edges
		int idx = p - 2;
		ll cur = 0;
		for (int i = 0; i < n - 1; i++) {
			sort(edges.begin(), edges.end(), cmp);
			for (const edge& e : edges) {
				int u = uf.find(e.u), v = uf.find(e.v);
				ll w = e.w;
				if (u != v) {
					bool recalc = (uf.houses[u] > 0 && uf.houses[v] > 0);
					if (recalc) {
//						cout << "w: " << w << '\n';
//						cout << "u and v: " << u << " " << v << '\n';
//						cout << "houses for u and v: " << uf.houses[u] << " " << uf.houses[v] << '\n';
//						cout << "uf.cost[v] and uf.cost[u]: " << uf.cost[v] << " " << uf.cost[u] << '\n';
						cur += min(uf.cost[u] + uf.houses[v] * w, uf.cost[v] + uf.houses[u] * w) - (uf.cost[v] + uf.cost[u]);
						assert(idx >= 0);
						ans[idx] = cu;
						idx--;
					} else {
//						cout << "nochange\n";	
//						cout << "w: " << w << '\n';
//						cout << "u and v: " << u << " " << v << '\n';
//						cout << "houses for u and v: " << uf.houses[u] << " " << uf.houses[v] << '\n';
//						cout << "uf.cost[v] and uf.cost[u]: " << uf.cost[v] << " " << uf.cost[u] << '\n';
					}
					uf.merge(u, v, w);
					break;
				}
			}
		}

		for (ll& x : ans) cout << x << " ";
		cout << '\n';
	}
	return 0;
}


