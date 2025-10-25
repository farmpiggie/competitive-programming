#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

vector<ll> f = {1};

ll fac(int x) {
	while (f.size() <= x) {
		f.push_back(f.back() * f.size() % MOD);
	}
	return f[x];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> adj(n);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if (m != n - 1) {
			cout << "0\n";
			continue;
		}
		if (n == 2) {
			cout << "2\n";
			continue;
		}

		// find farthest node from 0
		vector<int> depth(n, 0);
		auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
			if (p != -1) depth[u] = depth[p] + 1;
			for (int v : adj[u]) if (v != p) dfs(v, u);
		};
		dfs(0);

		int start = -1, farthest = 0;
		for (int i = 0; i < n; i++) {
			if (farthest < depth[i]) {
				start = i;
				farthest = depth[i];
			}
		}

		// find farthest node from start
		depth.assign(n, 0);
		dfs(start);
		int end = -1;
		farthest = 0;
		for (int i = 0; i < n; i++) {
			if (farthest < depth[i]) {
				end = i;
				farthest = depth[i];
			}
		}

		// find path from start to end
	
		vector<int> path, cur;
		set<int> path_set, cur_set;
		auto dfs2 = [&](this auto dfs2, int u, int p = -1) -> void {
			cur.push_back(u);
			cur_set.insert(u);
			if (cur.back() == end) {
				path = cur;
				path_set = cur_set;
			}
			for (int v : adj[u]) if (v != p) dfs2(v, u);
			cur.pop_back();
			cur_set.erase(u);
		};

		dfs2(start); // find the end
/*
		cout << "path\n";
		for (int i : path) cout << i << ' ';
		cout << '\n';
*/

		bool works = true;
		for (int u = 0; u < n; u++) {
			if (path_set.find(u) != path_set.end()) continue;
			bool leaf = false;
			// is connected to main path with distance 1
			for (int v : adj[u]) {
				if (path_set.find(v) != path_set.end()) leaf = true;
			}
			if (!leaf) works = false;
		}

		if (!works) {
			cout << "0\n";
			continue;
		}

		deque<int> path2(path.begin(), path.end());
		if (adj[path[1]].size() > 2) { // split end
			path_set.erase(path[0]);
			path2.pop_front();
		}
		if (path2.size() >= 2 && adj[path[path.size() - 2]].size() > 2) { // split end on the other end
			path_set.erase(path.back());
			path2.pop_back();
		}
	
		vector<int> modifiedPath(path2.begin(), path2.end());
		ll ans = 2 * (modifiedPath.size() > 1 ? 2 : 1);
		for (int u : path) {
			int cnt = 0;
			for (int v : adj[u]) {
				if (path_set.find(v) == path_set.end()) {
					cnt++;
				}
			}
			ans = ans * fac(cnt) % MOD;
		}

		cout << ans << '\n';
	}
}






