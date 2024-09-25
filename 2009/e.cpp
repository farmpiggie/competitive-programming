#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll target = k * n + (n - 1) * n / 2;
		ll lo = 1, hi = n;
		// find biggest number < target
		ll ans = 0;
		while (lo <= hi) {
			ll mi = (lo + hi) / 2;
			ll value = 2 * k * mi + (mi - 1) * mi;
			if (value < target) {
				ans = max(ans, mi);
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
		ll left = 2 * k * ans + (ans - 1) * ans;
		ans++;
		ll right = 2 * k * ans + (ans - 1) * ans;
		cout << min(abs(left - target), abs(right - target)) << '\n';
	}
	return 0;
}