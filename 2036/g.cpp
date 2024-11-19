/*
define array a[i] = query(1, i)
we can split the problem into two cases:
1. a ^ b ^ c != 0
	if this is the case, our array a looks like: 
		0...a...a ^ b....a ^ c...
	in this case, we can binary search for value of a, then binary search for value of b. easy
2. a ^ b ^ c == 0
	if this is the case, our array a looks like:
		0....a...a ^ b....0
	think abt highest set bit of each number?
	suppose query(1, x) = y.
	if msb(y) < msb(x), y must equal a.
		why? if we assume y = a ^ b, this implies the existence of some c = y > x. 
		but since msb(y) < msb(x), y < x, so this is contradictory.
		then we can bin search on range (a + 1, n) to find smallest b s.t. query(a + 1, n) != 0.
	if msb(y) >= msb(x), y must equal a ^ b.
		we can bin search on range (1, x - 1) and find the smallest a s.t. query(1, a) != 0.

	hard part: how do we search to simply find a non-zero value in this array? 
	idea: query(1, 1 << i). it is impossible that all a, b, c can be within all three regions.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ask(ll l, ll r) {
	cout << "xor " << l << " " << r << '\n';
	ll ret; cin >> ret;
	return ret;
}

int msb(ll n) {
	return 63 - __builtin_clzll(n);
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll first, second, third;
		ll total = ask(1, n);

		if (total == 0) {
			// find some value that is not equal to 0.
			ll x = 1, y = 0;
			while (y == 0 && x <= n) {
				y = ask(1, x);
				x *= 2; 
			}
			x /= 2; // retrieve value of x
//			cout << "y and x: " << y << " " << x << '\n';
			if (msb(y) < msb(x) || (msb(y) == msb(x) && (x == 1 || ask(1, x - 1) == 0))) { // y = a
				first = y;
				ll l = first + 1, r = n;
				second = n + 1;
				while (l <= r) {
					ll m = l + (r - l) / 2;
					if (ask(first + 1, m) != 0) {
						r = m - 1;
						second = min(second, m);
					} else {
						l = m + 1;
					}
				}
				third = first ^ second;
			} else { // y = a ^ b
				ll l = 1, r = x - 1;
				first = n + 1;
				while (l <= r) {
					ll m = l + (r - l) / 2;
					if (ask(1, m) != 0) {
						r = m - 1;
						first = min(first, m);
					} else {
						l = m + 1;
					}
				}
				second = y ^ first;
				third = y;
			}
		} else {
			// binary search for first.
			first = n + 1, second = n + 1;
			ll lo = 1, hi = n;
			while (lo <= hi) {
				ll mi = lo + (hi - lo) / 2;
				if (ask(1, mi) != 0) {
					first = min(first, mi);
					hi = mi - 1;
				} else {
					lo = mi + 1;
				}
			}
			// binary search for second
			lo = first + 1, hi = n;
			while (lo <= hi) {
				ll mi = lo + (hi - lo) / 2;
				if (ask(first + 1, mi) != 0) {
					second = min(second, mi);
					hi = mi - 1;
				} else {
					lo = mi + 1;
				}
			}
			third = total ^ first ^ second;
		}
		cout << "ans " << first << " " << second << " " << third << '\n';
	}
	return 0;
}
