#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int t, n;
vector<ll> c, cnt;
vector<vector<int>> g;
ll ans;

void dfs(int cur, int par = -1) {
	ans += cnt[c[cur]];
	ll prev = cnt[c[cur]];
	for (int nei : g[cur]) if (nei != par) {
		cnt[c[cur]] = 1;
		dfs(nei, cur);
	}
	cnt[c[cur]] = prev + 1;
}

int main() {
	send help
	cin >> t;
	while (t--) {
		cin >> n;
		c.resize(n);
		for (ll& x : c) {
			cin >> x;
			x--;
		}
		g.assign(n, {});
		for (int i = 0; i < n - 1; i++) {
			int v, u; cin >> v >> u; 
			v--; u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		cnt.assign(n, 0);
		ans = 0;
		dfs(0);
		cout << ans << '\n';
	}
	return 0;
}