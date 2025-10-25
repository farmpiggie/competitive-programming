#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<ll> x(n), r(n);
		for (ll &y : x) cin >> y;
		for (ll &y : r) cin >> y;

		map<ll, ll> mp;
		for (int i = 0; i < n; i++) { // O(n)
			for (ll pos = 0; pos <= r[i]; pos++) { // O(m) amortized
				ll l = 0, h = r[i];
				ll ans = 0;
				while (l <= h) {
					ll m = (l + h) / 2;
					if (pos * pos + m * m <= r[i] * r[i]) {
						ans = m;
						l = m + 1;
					} else {
						h = m - 1;
					}
				}

				mp[x[i] + pos] = max(mp[x[i] + pos], ans);
				mp[x[i] - pos] = max(mp[x[i] - pos], ans);
			}
		}

		ll ans = 0;
		for (auto& [x, y] : mp) {
			ans += 2 * y + 1;
		}
		cout << ans << '\n';
	}
}
