#include <bits/stdc++.h>
using namespace std;

// basically find n - sqrt(n) = k

#define ll long long

// ll mysqrt(ll x) {
// 	ll lo = 1, hi = x + 1;
// 	ll ans = 0;
// 	while (lo <= hi) {
// 		ll mi = (lo + hi) / 2;
// 		if (mi * mi <= x) {
// 			ans = mi;
// 			lo = mi + 1;
// 		}  else {
// 			hi = mi - 1;
// 		}
// 	}
// 	return ans;
// }

int main() {
	int t; cin >> t;
	while (t--) {
		ll k; cin >> k;
		ll lo = 1, hi = LLONG_MAX;
		ll ans = 0;
		while (lo <= hi) {
			ll mi = lo + (hi - lo) / 2;
			// cout << "---\n";
			// cout << lo << " " << hi << endl;
			ll value = mi - (ll) sqrt(mi);
			// cout << "mi: " << mi << endl;
			// cout << "difference: " << mi - value << endl;
			if (value == k) {
				// cout << "equal\n";
				ans = mi;
				hi = mi - 1;
			} else if (value < k) { // n - (# of squares)
				lo = mi + 1;
				// cout << "lessthan\n";
			} else {
				// cout << "greater than\n";
				hi = mi - 1;
			}
		}
		// --ans;
		assert(ans - (ll) sqrt(ans) == k);
		cout << ans << endl;

	}
	return 0;
}