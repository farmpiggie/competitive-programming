// node B always has to visit node A after it, so why don't we have node A find node B, then they both start painting
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> adj;
int a, b;
void dfs1(int node, int par, vector<int>& temp, vector<int>& path) {
	temp.push_back(node);
	if (node == b) {
		path = temp;
	}
	for (int& nei : adj[node]) if (nei != par) dfs1(nei, node, temp, path);
	temp.pop_back();
}

vector<int> depth;
ll dfs2(int node, int par, int d) {
	ll sum = 0;
	depth[node] = d;
	for (int& nei : adj[node]) if (nei != par) sum += dfs2(nei, node, d + 1) + 2;
	return sum;
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		adj.clear();
		depth.clear();
		adj.resize(n + 1, {});
		depth.resize(n + 1, 0);
		cin >> a >> b;
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<int> temp, path; // path stores path from a to b
		dfs1(a, -1, temp, path); // stops when hits b
		//cout << "dfs1 done\n";
		//for (int& x : path) cout << x << ' ';
		//cout << '\n';
		int start_node;
		int meetup_cost;
		if (path.size() == 1) {
			start_node = path[0];
			meetup_cost = 0;
		} else {
			start_node = path[(path.size() - 1) / 2];
			meetup_cost = (path.size() - 1) / 2;
		}
		//cout << "start node: " << start_node << '\n';
		ll ans = dfs2(start_node, -1, 0);
		//cout << "dfs2 done\n";
		int max_depth = -1;
		for (int& x : depth) max_depth = max(max_depth, x);
		//cout << ans << ' ' << max_depth << ' ' << meetup_cost << '\n';
	   	cout << ans - max_depth + meetup_cost + (path.size() % 2 == 0) << '\n';	
	}
}
