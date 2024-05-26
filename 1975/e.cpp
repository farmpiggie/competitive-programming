// EDITORIAL
// what are some features of a "chain"?
// there is no black vertex with three or more black child vertices
// at most one black vertex with two black child vertices
// if the black vertices form a chain, there is at most one black vertex whose parent vertex is white
// when flipping a vertex from black to white, this only changes its own value and its parents
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<int>> adj;
vector<int> par, color, cnt;

void dfs(int node, int p) {
	//cout << node << " " << p << '\n';
	par[node] = p;
	for (int nei : adj[node]) if (nei != p) {
		dfs(nei, node);
		if (color[nei] == 1) cnt[node]++; // counts # of children which are black vertices
	}
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		adj.clear();
		par.clear();
		color.clear();
		cnt.clear();
		adj.resize(n + 1, {});
		par.resize(n + 1, 0);
		color.resize(n + 1, 0);
		cnt.resize(n + 1, 0);

		for (int i = 1; i <= n; i++) cin >> color[i];
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		adj[0].push_back(1);

		vector<set<int>> num_vertices(max(3, n + 1), set<int>());
		// root tree at node 1
		dfs(0, -1);
		ll num_black_nodes = 0;
		int num_starters = 0;
		for (int i = 0; i <= n; i++) {
			if (color[i]) {
				num_black_nodes++;
				num_vertices[cnt[i]].insert(i);
				if (color[par[i]] == 0) num_starters++;
			}
		}
		while (q--) {
			int toggle; cin >> toggle;
			color[toggle] = 1 - color[toggle];
			if (color[toggle] == 0) { // blakc to white
				num_black_nodes--;
				num_vertices[cnt[toggle]].erase(toggle);
				if (color[par[toggle]] == 0) num_starters--;
				num_starters += cnt[toggle];
			} else { // white to black
				num_black_nodes++;
				num_vertices[cnt[toggle]].insert(toggle);
				if (color[par[toggle]] == 0) {
					num_starters++;
				}
				num_starters -= cnt[toggle];
			}

			if (color[par[toggle]] == 1) {
				num_vertices[cnt[par[toggle]]].erase(par[toggle]);
			}

			if (color[toggle] == 1) {
				cnt[par[toggle]]++;
			} else {
				cnt[par[toggle]]--;
			}

			if (color[par[toggle]] == 1) {
				num_vertices[cnt[par[toggle]]].insert(par[toggle]);
			}

		//	cout << num_vertices[0].size() << " " << num_vertices[1].size() << " " << num_vertices[2].size() << " " << num_black_nodes << " " << num_starters << '\n';
			ll yay = num_vertices[0].size();
			yay += num_vertices[1].size();
			yay += num_vertices[2].size();
			if (num_black_nodes > 0 && yay == num_black_nodes && num_starters == 1) {
				if (num_vertices[2].size() == 0) cout << "YES\n";
				else if (num_vertices[2].size() == 1)  {
					int node = *num_vertices[2].begin();
					if (color[par[node]] == 0) cout << "YES\n";
					else cout << "NO\n";
				} else {
					cout << "NO\n";
				}
			} else cout << "NO\n";
		}
	}
	return 0;
}
