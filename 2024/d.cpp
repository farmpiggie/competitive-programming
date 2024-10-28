#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, int>

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		vector<ll> psum(n);
		for (int& x : a) cin >> x;
		for (int& x : b) { cin >> x; --x; }
		for (int i = 0; i < n; i++) psum[i] = a[i] + (i ? psum[i - 1] : 0);


		vector<vector<pll>> adj(n); // weight, neighbor
		for (int i = 1; i < n; i++) adj[i].push_back({0, i - 1}); 
		for (int i = 0; i < n; i++) if (b[i] > i) adj[i].push_back({a[i], b[i]});

		vector<ll> dist(n, -1);
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push({0, 0});
		while (!pq.empty()) {
			pll p = pq.top(); pq.pop();
			ll w = p.first;
			int cur = p.second;
			if (dist[cur] != -1) continue;
			dist[cur] = w;
			for (auto& edge : adj[cur]) {
				pq.push({w + edge.first, edge.second});
			}
 		}
 		ll ans = 0;
 		for (int i = 0; i < n; i++) {
 			if (dist[i] != -1) ans = max(ans, psum[i] - dist[i]);
 		}
 		cout << ans << '\n';




	}
	return 0;
}