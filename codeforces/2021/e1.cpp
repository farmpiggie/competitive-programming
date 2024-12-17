/*
run floyd-warshall to get pairwise cost
choose each station one by one, based on how much each selection lowers said cost.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define v2l vector<vl>

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, p; cin >> n >> m >> p;
		vector<int> s(n, 0);
		for (int i = 0; i < p; i++) {
			int x; cin >> x;
			--x;
			s[x] = 1;
		}
		
		v2l dist(n, vl(n, LLONG_MAX));
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int i = 0; i < m; i++) {
			int u, v; ll w; cin >> u >> v >> w;
			--u; --v;
			dist[u][v] = w;
			dist[v][u] = w;
		}

		// floyd warshall
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) 
					dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
		

		vector<ll> ans;
		vector<ll> cost(n, LLONG_MAX);
		ll best = 0;
		for (int i = 0; i < p - 1; i++) {
			ll best = LLONG_MAX;
			vector<ll> ncost;
			for (int j = 0; j < n; j++) {
				ll cur = 0;
				vector<ll> curcost(n, 0);
				for (int k = 0; k < n; k++) {
					if (s[k]) {
						curcost[k] = min(cost[k], dist[j][k]);
					 	cur += curcost[k];
					}
				}
				if (cur < best) {
					best = cur;
					ncost = curcost;
				}
			}
			ans.push_back(best);
			cost = ncost;
		}

		for (int i = p - 1; i < n; i++) ans.push_back(0);

		for (ll& x : ans) cout << x << " ";
		cout << '\n';
	}
	return 0;
}
