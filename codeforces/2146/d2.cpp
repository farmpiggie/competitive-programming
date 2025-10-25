#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll l, r; cin >> l >> r;
		ll n = r - l + 1;
		ll offset = l;
		// offset by l;
		vector<ll> ans(n);
		ll sum = 0;
		ll bits = 0;
		while (l < r) {
			//cerr << "l and r and bits: " << l << " " << r << " " << bits << '\n';
//			cout << "sum: " << sum << '\n';
			int msb_r, msb_l;
			if (r == 0) msb_r = -1;
			else msb_r = 63 - __builtin_clzll(r);
			// msb of r
			if (l == 0) msb_l = -1;
			else msb_l = 63 - __builtin_clzll(l); // msb of l
			
			cerr << "msb_l and msb_r: " << msb_l << " " << msb_r << '\n';
			if (msb_l < msb_r) {
				// check which size is bigger
				ll l_sz = (1ll << msb_r) - l;
				ll r_sz = (r - l + 1) - l_sz;
				// take min(l_sz, r_sz) from either side

				for (ll i = 0; i < min(l_sz, r_sz); i++) { // match (1 << msb_r) to (1 << msb_r - 1), etc.
					ll x = (1ll << msb_r) + i, y = (1ll << msb_r) - 1 - i;
//					cout << "x and y: " << x << " " << y << '\n';
//					cout << (bits | x) - offset << " " << (bits | y) - offset << '\n';
					ans[(bits | x) - offset] = bits | y;
					ans[(bits | y) - offset] = bits | x;
//					cout << 2 * (x + y) << " " << bits << '\n';
					sum += 2 * (x + y + bits);
				}

				if (l_sz < r_sz) {
					l += 2 * min(l_sz, r_sz);
				} else {
					r -= 2 * min(l_sz, r_sz);
				}
			} else { // same
				bits |= (1ll << msb_l);
				l ^= (1ll << msb_l);
				r ^= (1ll << msb_l);
			}
		}
		if (l == r) {
			ans[(bits | l) - offset] = (bits | l);
			sum += (bits | l);
		}

		cout << sum << '\n';
		for (ll x : ans) cout << x << ' ';
		cout << '\n';
	}
}
		