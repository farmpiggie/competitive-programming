#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		if (n == 1) {
			cout << "-1\n";
			continue;
		} else if (n == 2) { // one person is always richest?
			cout << "-1\n";
			continue;
		}
		

		ll average = 0;
		for (ll& x : a) average += x;
		ll sum = average;
		average /= n;

		sort(a.begin(), a.end());
		int unhappy = n / 2; // index that must be greater than
		// a[unhappy] < (sum + x) / (n * 2)
		// a[unhappy] * n < sum + x
		// a[unhappy] * n - sum < x

		// cout << a[unhappy] << " " << n << " " << sum << '\n';
		ll ans = 1ll * a[unhappy] * 2 * n - sum + 1;
		// cout << "ans: " << ans << '\n';
		if (ans < 0) cout << "0\n";
		else cout << ans << '\n';

	}
	return 0;
}
