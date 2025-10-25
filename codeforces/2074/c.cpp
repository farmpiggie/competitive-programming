/*
 * if bitcount is 1, doesnt work
 * if x is in form (1 << i) - 1, also doesnt work
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		if (__builtin_popcount(x) == 1) {
			cout << "-1\n";
			continue;
		}

		bool works = true;
		for (int i = 0; i < 31; i++) {
			ll tmp = (1ll << i) - 1;
			if (tmp > x) break;
			if (tmp == x) {
				works = false;
				break;
			}
		}

		if (works) {
			int msb = 31 - __builtin_clz(x); // should be > 0
			ll y = (1ll << msb) - 1;
			//ll z = x ^ y;
			cout << y << '\n';
			//cout << y << ' ' << z << '\n';
		} else {
			cout << "-1\n";
		}
	}
}

		
			

	