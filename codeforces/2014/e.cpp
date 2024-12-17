#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m, h; cin >> n >> m >> h;
		vector<vector<pll>> adj(n, vector<pll>(0));
		vector<int> horse(n, 0);
		for (int i = 0; i < h; i++) {
			int x; cin >> x;
			--x;
			horse[x] = 1;
		}
		for (int i = 0; i < m; i++) {
			ll u, v, w; cin >> u >> v >> w;
			--u; --v;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
		vector<vector<ll>> dp1(n, vector<ll>(2, LLONG_MAX));
		vector<vector<ll>> dp2(n, vector<ll>(2, LLONG_MAX));

		// {weight, {node, hasHorse}}
		priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
		pq.push({0, {0, 0}});
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			ll weight = cur.first, node = cur.second.first, has_horse = cur.second.second;
			if (dp1[node][has_horse] != LLONG_MAX) continue;
			dp1[node][has_horse] = weight;
			// cout << node << " " << has_horse << " " << weight << '\n';
			if (!has_horse && horse[node]) pq.push({weight, {node, 1}}); // has horse now
			for (auto& [w, nei] : adj[node]) {
				// cout << "visiting: " << w << " " << nei << '\n';
				if (has_horse) {
					pq.push({weight + w / 2, {nei, 1}}); // traverse edges
				} else {
					pq.push({weight + w, {nei, 0}});
				}
			}
		}


		// {weight, {node, hasHorse}}
		priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq2;
		pq.push({0, {n - 1, 0}});
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			ll weight = cur.first, node = cur.second.first, has_horse = cur.second.second;
			if (dp2[node][has_horse] != LLONG_MAX) continue;
			dp2[node][has_horse] = weight;
			if (!has_horse && horse[node]) pq.push({weight, {node, 1}}); // has horse now
			for (auto& [w, nei] : adj[node]) {
				if (has_horse) {
					pq.push({weight + w / 2, {nei, 1}}); // traverse edges
				} else {
					pq.push({weight + w, {nei, 0}});
				}
			}
		}

		ll ans = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			ans = min(ans, max(min(dp1[i][0], dp1[i][1]), min(dp2[i][0], dp2[i][1])));
		}
		cout << ((ans == LLONG_MAX) ? -1 : ans) << '\n';

	}

	return 0;
}