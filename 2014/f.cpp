/*
consider saving all nodes: Σai - 2 * c * (n - 1)

let x[i] be the # of edges a node i shares with strengthened nodes

each node gives: a[i] - c * x[i] // node minus strengthening it
not using the node, changes the value into: c * x[i] - (a[i] - c * x[i]) // gained cost to strengthened nodes, but lost cost to this node's value...

save the node if:
c * x[i] - (a[i] - c * x[i]) < a[i] - c * x[i]
c * x[i] - a[i] + c * x[i] < a[i] - c * x[i]
c * x[i] <= 2 * a[i]

we can find an optimal value x[i] such that all nodes will still want to be strengthened
x[i] <= 2 * a[i] / c
x[i] = floor(2 * a[i] / c)

strengthen the nodes with the biggest x[i] values first? and work towards the smallest ones...


wait is this just dp?
dp[i][j] = max value given the subtree rooted at i, i is strengthened if j is 1, otherwise not strengthened

dp[i][0] = sum(max(dp[child][0], dp[child][1])) for all children in adj[i]
// if you have strengthened children, you have to subtract - c for their connection to you, and - c for your connection to them
// if you are strengthened and your child is not, you don't need to subtract anything :)
dp[i][1] = sum(max(dp[child][0], dp[child][1] - 2 * c))

ans = max(dp[root][0], dp[root][1])


*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<vector<int>> adj(n);
		vector<int> a(n);
		for (int& x : a) cin >> x;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<ll>> dp(n, vector<ll>(2, 0));

		auto dfs = [&a, &adj, &dp, &c](auto&& self, int node, int par) -> void {
			// cout << node + 1 << '\n';
			if (adj[node].size() == 1 && adj[node][0] == par) { // leaf node
				dp[node][0] = 0;
				dp[node][1] = a[node];
				return;
			}
			for (int nei : adj[node]) if (nei != par) self(self, nei, node);
			for (int nei : adj[node]) if (nei != par) dp[node][0] += max(dp[nei][0], dp[nei][1]);
			for (int nei : adj[node]) if (nei != par) dp[node][1] += max(dp[nei][0], dp[nei][1] - 2 * c);
			// cout << "dp[i][1] before: " << dp[node][1] << '\n';
			// cout << "node value: " << node << '\n';
			// cout << "adding: " << a[node] << '\n';
			dp[node][1] += a[node];
			// cout << "value of dp[" << node + 1 << "][0]: " << dp[node][0] << '\n';
			// cout << "value of dp[" << node + 1 << "][1]: " << dp[node][1] << '\n';

		};


		dfs(dfs, 0, -1);
		cout << max(dp[0][0], dp[0][1]) << '\n';
		

	}
	return 0;
}