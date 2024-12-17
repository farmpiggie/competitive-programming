#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y; --x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		vector<int> len1(n, 0), len2(n, 0), par(n, -1), dist(n, 0);
		auto dfs = [&](this auto dfs, int node, int parent = -1) -> int {
			par[node] = parent;
			if (parent != -1) dist[node] = dist[parent] + 1;
			vector<int> values;
			for (int nei : adj[node]) if (nei != parent) values.push_back(dfs(nei, node) + 1);
			sort(values.begin(), values.end());
			if (values.size() > 0) {
				len1[node] = values.back();
//				cout << "len1[" << node + 1 << ": " << len1[node] << '\n';
				values.pop_back();
			}
			if (values.size() > 0) {
				len2[node] = values.back();
//				cout << "len2[" << node + 1 << ": " << len2[node] << '\n';
			} 
			return len1[node];
		};
		dfs(0);

		const int MAXLOG = (int) log2(n) + 1;
		v2i jp(MAXLOG, vi(n, -1)); // jp[i][j] = (1 << i)th ancestor of 
		for (int i = 0; i < n; i++) jp[0][i] = par[i];
	
		for (int i = 1; i < MAXLOG; i++) {
			for (int j = 0; j < n; j++) {
				if (jp[i - 1][j] != -1) jp[i][j] = jp[i - 1][jp[i - 1][j]];
			}
		}

		v2i mx(MAXLOG, vi(n, INT_MIN));
		for (int i = 0; i < n; i++) {
//			mx[0][i] = len1[i] - dist[i];
			if (par[i] != -1) {
				int val;
				if (len1[i] + 1 < len1[par[i]]) val = max(mx[0][i], len1[par[i]] - dist[par[i]]);
				else val = max(mx[0][i], len2[par[i]] - dist[par[i]]);
//				if (par[i] == 2) cout << "len1 and 2: " << len1[par[i]] << " " << len2[par[i]] << '\n';
				mx[0][i] = max(mx[0][i], val); 
			}
		}

		for (int i = 1; i < MAXLOG; i++) {
			for (int j = 0; j < n; j++) {
				if (jp[i - 1][j] != -1) mx[i][j] = max(mx[i - 1][j], mx[i - 1][jp[i - 1][j]]);
				else mx[i][j] = mx[i - 1][j];
			}
		}

		// assumption is that said ancestor exists.
		auto ancestor = [&](int v, int k) {
			if (k == 0) return v;
			int x = v;
			for (int i = 0; i < 32; i++) {
				if ((k >> i) & 1) {
					x = jp[i][x];
				}
			}
//			cout << k << "th ancestor of " << (v + 1) << " is: " << (x + 1) << '\n';
			return x;
		};

		auto query = [&](int v, int k) -> int {
			// query max from v to kth ancestor of v.
			k = min(k, dist[v]); // k = 6 will be an overlap between mx[2][v] and mx[2][ancestor(v, 3)]
//			k++; // k = 7
//			cout << "v and k: " << v << " " << k << '\n';
			if (k == 0) return len1[v];
//			cout << "k: " << k << '\n';
			int x = (int) log2(k);
//			cout << "x: " << x << '\n';
			// we will have some overlap.
//			cout << "mx[" << x << "][" << v + 1 << "]:" << mx[x][v] << '\n';
//			cout << "mx[" << x << "][" << ancestor(v, k - (1 << x)) + 1 << "]: " << mx[x][ancestor(v, k - (1 << x))] << '\n';
//			cout << "ans: " << dist[v] + max(mx[x][v], mx[x][ancestor(v, k - (1 << x))]) << '\n';
			return max(dist[v] + max(mx[x][v], mx[x][ancestor(v, k - (1 << x))]), len1[v]);
		};

		int q; cin >> q;
		while (q--) {
			int v, k; cin >> v >> k;
			--v;
//			cout << "v: " << v << '\n';
			//cout << query(v, k) << "\n";
			cout << query(v, k) << ' ';
		}
		cout << '\n';
	}
	return 0;
}

		

