#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mylog2(ll x) {
	if (x >= 2) return 1 + mylog2(x / 2);
	else return 0;
}

int main() {
	ll n, k; cin >> n >> k;
	ll ans = 0;
	ll layers = mylog2(n) - 1;
	// all but last layer
	for (ll i = 0; i <= layers; i++) {
		if (k < i + 1) continue;
		ll nodes_in_layer = 1ll << i;
		ll rem = n - (1ll << (i + 1)) + 1;
		ll empty = ((1ll << (layers + 1)) - (1ll << (i + 1))) / (1ll << i);
		ll leftover = rem - empty * (1ll << i);
//		cout << rem << " " << empty << " " << leftover << '\n';
		ll full = empty + (1ll << (layers + 1 - i));
		ll num_full = leftover / (1ll << (layers + 1 - i));
		ll partial = empty + (leftover % (full - empty));
//		cout << full << " " << num_full << '\n';
//		cout << partial << " " << 1 << '\n';
//		cout << empty << " " << (1 << i) - 1 - num_full << '\n';
//		cout << '\n';
		if (k <= n - full) ans += num_full;
		if (k <= n - partial) ans += 1;
		if (k <= n - empty) ans += (1ll << i) - 1 - num_full;		
	}
	ll num_leaf = n - (1ll << (layers + 1)) + 1;
//	cout << num_leaf << '\n';
	if (layers + 2 <= k && k <= n) ans += num_leaf;
	cout << ans << '\n';
	return 0;
}
