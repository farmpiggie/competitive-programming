// for an anchored value of x, binary search for smallest and biggest valuesof y
#include <bits/stdc++.h>
using namespace std;

#define ll long long

// biggest value of y s.t. x^2 + y^2 < r^2
ll bin_search(ll r, ll x) {
	int lo = 0, hi = r;
	ll ans = 0;
	while (lo <= hi) {
		ll mi = lo + (hi - lo) / 2;
		if (x * x + mi * mi < r * r) {
			ans = max(ans, mi);
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll r; cin >> r;
		ll ans = 0;
		for (int x = 0; x <= r; x++) {
			ans += bin_search(r + 1, x) - bin_search(r, x);
		}
		cout << ans * 4 << '\n';
	}
	return 0;
}
