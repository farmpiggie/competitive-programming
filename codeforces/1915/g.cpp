#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll> 

int t, n, m;


struct entry {
	ll dist, speed, node;
};

auto cmp = [](entry a, entry b) {
	return a.dist > b.dist;
};


void solve() {
	cin >> n >> m;
	vector<vector<pii>> adjList(n + 1, vector<pii>(0));
	vector<ll> speed(n + 1);
	vector<vector<ll>> visited(n + 1, vector<ll>(1001, LLONG_MAX));

	for (int i = 0; i < m; i++) {
		int u, v;
		ll w; cin >> u >> v >> w;
		adjList[u].push_back({w, v});
		adjList[v].push_back({w, u});
	}
	for (int i = 1; i <= n; i++) {
		cin >> speed[i];
	}

	priority_queue<entry, vector<entry>, decltype(cmp)> pq(cmp);
	entry e;
	e.dist = 0;
	e.speed = speed[1];
	e.node = 1;
	pq.push(e);
	while (!pq.empty()) {
		e = pq.top(); pq.pop();

		// cout << e.node << ' ' << e.dist << ' ' << e.speed << '\n';

		if (visited[e.node][e.speed] != LLONG_MAX) {
			continue;
		}

		visited[e.node][e.speed] = e.dist;
		for (pii p : adjList[e.node]) {
			entry new_entry;
			new_entry.node = p.second;
			new_entry.dist = e.dist + p.first * e.speed;
			new_entry.speed = min(speed[p.second], e.speed);
			pq.push(new_entry);
		}
 	}
 	ll ans = LLONG_MAX;
 	for (int i = 1; i <= 1000; i++) {
 		ans = min(ans, visited[n][i]);
 	}
 	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}