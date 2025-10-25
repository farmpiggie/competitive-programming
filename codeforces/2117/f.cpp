/*
 * the graph can only have two leaves, otherwise the answer is zero.
 * therefore the structure of the graph is basically two disjoint paths that eventually meet up somewhere towards the root
 *
 * let us say 
 * 1. the path from leaf 1 has x nodes on it
 * 2. the path from leaf 2 has y nodes on it
 * 3. the path from from lca(leaf_1, leaf_2) up to root has z nodes on it.
 * we can use any value (1, 2) on path 3: binpow(2, len(path_3))
 *
 * given two paths of length x and y, how can we structure them s.t. we dont have equal subtree sum?
 *
 * one leaf must be 1, and the other is 2.
 * lets say leaf_1 = 1, leaf_2 = 2
 * p[leaf_1] can be either 1 or 2. if p[leaf_2] is 1, p[leaf_2] cannot be 1. otherwise we get 3 and 3
 *
 * so we can go:
 * 1 + 1, 2 + 1 <-- so is this
 * 1 + 2, 2 + 2 <-- this is always safe
 *
 * without loss of generality, assume x < y.
 * we can have y be the "slower" of the two (aka leaf w/ value 1) and it can "overtake" the value of x.
 * assume sum(x) = whatever value
 * then at node (x + 1) in path y, we must pick 2.
 * all nodes between (x + 2) and y can be whatever we want.
 *
 * so this leads us with the following for paths x and y:
 * assume len(x) <= len(y)
 * 
 * path x takes 1, path y takes 2, we always add 2 each time: * # of combos is 2 * binpow(y - x)
 *
 * path x takes 2, path y takes 1, we always add 2 each time. node (x + 1) in path y must be 2.
 * # of combos is 2 * binpow()
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll y) {
	if (y == 0) return 1;
	ll res = binpow(x, y / 2);
	res = res * res % MOD;
	if (y & 1) res = res * x % MOD;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
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

		int leaves = 0;
		int a = -1, b = -1; 
		// dont include root node
		for (int i = 1; i < n; i++) {
			if (adj[i].size() == 1) {
				leaves++;
				if (a == -1) a = i;
				else b = i;
			}
		}

		if (leaves > 2) {
			cout << "0\n";
			continue;
		} else if (leaves == 1) {
			cout << binpow(2, n) << '\n';
			continue;
		} 

		// a, b are our leaves

		vector<int> par(n);
		auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
			par[u] = p;
			for (int v : adj[u]) if (v != p) {
				dfs(v, u);
			}
		};

		dfs(0);

		vector<int> p1, p2;
		int cur = a;
		while (cur != -1) {
			p1.push_back(cur);
			cur = par[cur];
		}
		cur = b;
		while (cur != -1) {
			p2.push_back(cur);
			cur = par[cur];
		}

		reverse(p1.begin(), p1.end());
		reverse(p2.begin(), p2.end());

		int x = -1, y = -1, z = -1;
		for (int i = 0; i < min(p1.size(), p2.size()); i++) {
			if (p1[i] != p2[i]) { // guaranteed
				z = i; // length of upper path
				x = p1.size() - z;
				y = p2.size() - z;
				break;
			}
		}
		if (x > y) swap(x, y);
		assert(x != -1);
		assert(y != -1);
		assert(z != -1);

		ll ans = 0;
		// smaller path takes 1, it will always be smaller.
		// bigger path takes 1, it is defined for (x + 1) times
		ans = binpow(2, z) * (binpow(2, y - x) + binpow(2, max(0, y - (x + 1))) % MOD) % MOD;
		cout << ans << '\n';
	}
}
			

				





