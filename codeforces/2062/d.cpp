/*
 * 1. assume we have given a[i]. how do we solve problem?
 * 	a. for any edge (u, v), if a[u] != a[v], we must apply an operation (u, v) or (v, u) exactly abs(a[v] - a[u]) times
 * 	b. if we root the tree arbitrarily and follow this process, the value of the balanced tree is:
 * 		a[0] + sum(max(0, a[v] - a[par[v]]))
 * 	c. notice that any way we root the tree, the answer is the same. if we root the tree arbitrarily at x and shift it over to y where par[y] = x, we have the following:
 * 		x. if par[y] > par[x], the sum of (a[y] - a[x]) is included in the summation and will be removed when the tree is re-rooted
 * 			a[x] + (summation) = a[y] + (summation) - (a[y] - a[x]) 
 * 					   = a[x] + summation
 * 		y. if par[y] < par[x], the sum of (a[x] - a[y]) will be added to the summation when the tree is re-routed
 * 			a[x] + summation = a[y] + summation + (a[x] - a[y])
 * 					 = a[x] + summation
 * 		therefore, we can root the tree arbitrarily.
 * 2. then how to minimize a[u]?
 * 	without bounds, we want to make it equal to LARGEST child (so we keep it small without having to add).
 * 	however, not always possible with bounds.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			--x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		if (n == 1) {
			cout << l[0] << '\n';
			continue;
		}
		
		long long ans = 0;	
		vector<int> a(n);	
		auto dfs = [&](this auto dfs, int node, int par = -1) -> void {
			int val = l[node];
			for (int nei : adj[node]) if (nei != par) {
				dfs(nei, node);
				val = max(val, a[nei]);
			}
			a[node] = min(val, r[node]);
			for (int nei : adj[node]) {
				ans += max(0, a[nei] - a[node]);
			}
		};
		dfs(0);
		cout << ans + a[0] << '\n';
	}
}



