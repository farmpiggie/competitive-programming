#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

void solve() {
	ll l, r, g; cin >> l >> r >> g;
	if (l % g != 0) {
		l += (g - (l % g));
	}
	if (r % g != 0) {
		r -= r % g;
	}
	ll diff = r - l; // starts off here
	while (diff >= 0) {
		for (ll i = l; i + diff <= r; i+= g) {
			if (gcd(i / g, (i + diff) / g) == 1) {
				cout << i << " " << i + diff << '\n';
				return;	
			}
		}
		diff -= g;
	}		
	cout << "-1 -1\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
