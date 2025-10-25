#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;

void solve() {
	int n, c; cin >> n >> c;
	vector<pii> costs(n);
	for (int i = 0; i < n; i++) {
		ll price; cin >> price;
		costs[i] = {price + min(i + 1, n - i), price + i + 1};
	}

	sort(costs.begin(), costs.end());
	vector<ll> psum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + costs[i - 1].first;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int nc = c - costs[i].second;
		int l = 0, r = n;
		int mx = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll price = psum[mid];
			int cur = mid + 1;
			if (mid > i) {
				price -= costs[i].first;
				cur--;
			}
			if (price <= nc) {
				mx = max(mx, cur);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		ans = max(mx, ans);
	}

	cout << ans << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}