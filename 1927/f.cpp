#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> #
using namespace __gnu_pbds;
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct dsu {
	vector<int> par, sz;

	dsu(int n) {
		par = vector<int>(n + 1);
		sz = vector<int>(n + 1);

		for (int i = 0; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int a) {
		if (a == par[a]) return a;
		else return par[a] = find(par[a]);
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
	}
};


int t, n, m;

void dfs(int cur, int target, int par, vector<int>& route, vector<vector<int>>& adj, int cost) {
	route.push_back(cur);
	if (cur == target) {
		cout << cost << ' ' << route.size() << '\n';
		for (int node : route) cout << node + 1 << ' ';
		cout << '\n';
	}
	for (int nei : adj[cur]) {
		if (nei != par) dfs(nei, target, cur, route, adj, cost);
	}
	route.pop_back();
}

void solve() {

	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(0));
	vector<pair<int, pii>> edges;


	for (int i = 0; i < m; i++) {
		int u, v, w; 
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, {u, v}});
	}

	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());

	dsu ds(n);

	pair<int, pii> bestEdge;

	for (int i = 0; i < m; i++) {
		pair<int, pii> edge = edges[i];
		if (ds.find(edge.s.f) == ds.find(edge.s.s)) {
			bestEdge = edge;
		} else {
			ds.merge(edge.s.f, edge.s.s);
			adj[edge.s.f].push_back(edge.s.s);
			adj[edge.s.s].push_back(edge.s.f);
		}
	}

	vector<int> route;
	dfs(bestEdge.s.f, bestEdge.s.s, -1, route, adj, bestEdge.f);
}



int main() {
	send help
	cin >> t;
	while (t--) solve();
	return 0;
}