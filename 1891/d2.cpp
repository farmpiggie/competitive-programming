#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	ll p = (ll) (1e9 + 7);
	while (t--) {
		ll l, r, c = 0;
		cin >> l >> r;
		for (int i = 2; (1ll << i) <= r; i++) {
			ll x = max(1ull << i, l), y = min((1ull << (i + 1)) - 1, r);
			if (x > y) continue;
			for (ll j = i; j <= y; j *= i) {
				(c += y - max(j, x) + 1) %= p;
			}
		}
		cout << c << '\n';
	}
	return 0;
}
