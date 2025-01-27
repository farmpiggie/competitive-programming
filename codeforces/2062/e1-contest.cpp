/* let x, y, z be the biggest 3 weights in a[i]
 * if i can choose some y such that it leaves some zs available, i win. 
 * however, there is a case where the subtree of every y contains all zs.\
 * in that case, if i pick y, i lose. if i pick z, i also lose.
 * therefore, i can try to pick some x s.t. x doesn't eliminate all ys.
 * so therefore i can pick the first value x s.t. it doesn't eliminate all the values beneath it. and i win?
 */
#include <bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par, sz, depth, top;
	int n;

	dsu(int _n, vector<int> _depth) {
		n = _n;
		sz.assign(n, 1);
		par.resize(n);
		top.resize(n);
		iota(par.begin(), par.end(), 0);
		depth = _depth; // depth of each node in the tree
		iota(top.begin(), top.end(), 0); // top of each is itself
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
		if (depth[x] > depth[y]) { // y is higher up
			depth[x] = depth[y];
			top[x] = top[y];
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<int> w(n);
		set<int> s;
		map<int, int> mp;
		for (int& x : w) {
			cin >> x;
			s.insert(x);
			mp[x]++;
		}
		
		int big = *s.rbegin();
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			--x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		vector<int> sz(n, 0);
		vector<int> depth(n, 0);
		vector<int> p(n, 0);
		auto dfs = [&](this auto dfs, int node, int par = -1, int d = 0) -> int {
			if (w[node] == big) sz[node]++;
			depth[node] = d;
			p[node] = par;
			for (int nei : adj[node]) if (nei != par) sz[node] += dfs(nei, node, d + 1);
			return sz[node];
		};
		

		cout << "hello\n";
		dfs(0);
		auto it = s.rbegin();
		if (s.size() == 1) {
			cout << "0\n";
			continue;
		} 
		it++;
		for (int i = 0; i < n; i++) {
			if (w[i] == *it && sz[i] != sz[0]) {
				cout << i + 1 << " ";
				continue;
			}
		}

		int lowest_depth = n + 1;
		int lowest = -1;
		for (int i = 0; i < n; i++) {
			if (w[i] == *it) {
				if (depth[i] < lowest_depth) {
					lowest_depth = depth[i];
					lowest = i;
				}
			}
		}
	
		int prev = p[lowest], cur = (prev == -1 ? -1 : p[prev]);
		int cnt = 1;
		vector<int> visited(n, 0);
		visited[cur] = 1;
		visited[prev] = 1;
		bool found = false;
		while (cur != -1 && !found) {
			if (w[prev] == w[cur]) {
				cnt++;
			} else {
				// check cnt
				if (cnt == mp[w[prev]]) {
					cnt = 0;
				} else {
					for (int i = 0; i < n; i++) {
						if (!visited[i] && w[i] == w[prev]) {
							cout << i + 1 << '\n';
							found = true;
							break;
						}
					}
				}
			}
			prev = cur;
			cur = p[cur];
			visited[cur] = 1;
		}

		cout << "0\n";	
	}
}
