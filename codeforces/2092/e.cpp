/*
 * how many ways to fill a nxn board with no restrictions?
 * start with a board of all white
 * add a black tile to center -> +4 to parity
 * add a black tile to side -> + 3 to parity
 * add a black tile to corner -> + 2 to parity
 *
 * can you say that the # of black tiles is independent based on the parities?
 * do this for the white tiles???
 *
 * when is this not possible?
 * number of black tiles/white tiles on sides are odd?
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll y) {
	if (y == 0) return 1;
	ll res = binpow(x, y / 2);
	res = res * res % MOD;
	if (y & 1) res = res * x % MOD;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n, m, k; cin >> n >> m >> k;
		int b_corner = 0, b_edge = 0, b_center = 0;
		int w_corner = 0, w_edge = 0, w_center = 0;
		for (int i = 0; i < k; i++) {
			int x, y, c; cin >> x >> y >> c;
			--x; --y;
			if ((x == 0 || x == n - 1) && (y == 0 || y == m - 1)) {
				if (c == 0) {
					b_corner++;
				} else {
					w_corner++;
				}
			} else if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
				if (c == 0) {
					b_edge++;
				} else {
					w_edge++;
				}
			} else {
				if (c == 0) {
					b_center++;
				} else {
					w_center++;
				}
			}
		}
		ll unset_edge = 2 * (n - 2 + m - 2) - b_edge - w_edge;
		if (unset_edge == 0 && (b_edge & 1)) { // odd edges
			cout << "0\n";
			continue;
		}
		ll ans = 1;
		if (unset_edge > 0) {
			ans = binpow(2, unset_edge - 1);
		}
		ll unset_center = (n - 2) * (m - 2) - b_center - w_center;
		ans = ans * binpow(2, unset_center) % MOD;
		ll unset_corner = 4 - b_corner - w_corner;
		ans = ans * binpow(2, unset_corner) % MOD;
		cout << ans << '\n';
	}
}



		

		

