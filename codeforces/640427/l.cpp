#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u;
	char c;
	double p;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	set<int> accepting;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		--x;
		accepting.insert(x);
	}

	vector<vector<edge>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		char c;
		double p;
		cin >> u >> v >> c >> p;
		--u; --v;
		adj[v].push_back({u, c, p});
	}


	string s; cin >> s;
	int len = (int) s.length();

	vector<vector<double>> dp(n, vector<double>(len + 1, 0.0));
	dp[0][0] = 1.0;
	for (int j = 1; j <= len; j++) { // length of string read
		for (int u = 0; u < n; u++) { // node
			for (auto [v, c, p] : adj[u]) {
				if (s[j - 1] != c) continue;
				dp[u][j] += dp[v][j - 1] * p;
			}
		}
	}
	double ans = 0;
	for (int u : accepting) {
		ans += dp[u][len];
	}
	cout << (ans >= 0.5 ? "YES" : "NO") << '\n';
}






	
