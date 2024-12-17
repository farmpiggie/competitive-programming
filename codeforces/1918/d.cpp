#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define pii pair<ll, int>

int t, n, a[MAXN] = {};

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll lo = 0, hi = (ll) (1e14 + 5);
	ll ans = (ll) (1e14 + 5);
	
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		vector<ll> dp(n + 1, 0);
		set<pii> s;

		int max_j = n;
		dp[n] = 0;
		s.insert({dp[n], n});
		ll sum = 0;
		for (int j = n - 1; j >= 0; j--) {
			while (sum > mid) {
				sum -= a[max_j - 1];
				s.erase({dp[max_j], max_j});
				max_j--;
			}
			dp[j] = s.begin()->first + a[j];
			s.insert({dp[j], j});
			sum += a[j];
		}

		bool works = false;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum <= mid && dp[i] <= mid) {
				works = true;
				break;
			}
			sum += a[i];
		}
		if (works) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}