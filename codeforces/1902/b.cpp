#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tc, n, p, l, t;

void solve() {
	cin >> n >> p >> l >> t;
	ll lo = 0, hi = n;

	ll num_tasks = (n - 1) / 7 + 1;

	ll ans = n;

	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;

		if (mid * l + min(num_tasks, 2 * mid) * t >= p) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << (n - ans) << '\n';
}

int main() {
	cin >> tc;
	while (tc--) solve();
	return 0;
}