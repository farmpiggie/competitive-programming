#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pxor(ll x) {
	if (x % 4 == 0) return x;
	else if (x % 4 == 1) return 1;
	else if (x % 4 == 2) return x + 1;
	else return 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll l, r, i, k;
		cin >> l >> r >> i >> k;
		ll target = k % (1ll << i);
		ll mod = (1ll << i);
		ll big = r;
		ll big_r = big % mod;
		if (big_r > target) { 
			big -= (big_r - target);
		} else if (big_r < target) {
			big -= (mod - (target - big_r));
		}

		ll small = l;
		ll small_r = small % mod;
		if (small_r > target) {
			small += (mod - (small_r - target));
		} else if (small_r < target) {
			small += (target - small_r);
		}

		ll parity = (big - small) / mod + 1;

		ll ans = pxor(r) ^ pxor(l - 1);
		if (parity % 2 == 1) ans ^= target; // we remove these

		ll right_prefix = (big - target) / mod;
		ll left_prefix = (small - target) / mod;

		ans ^= ((pxor(right_prefix) ^ pxor(left_prefix - 1)) << i);
		cout << ans << '\n';
	}
	return 0;
}
