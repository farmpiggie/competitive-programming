#include <bits/stdc++.h>
using namespace std;

#define ll long long

// (a | b) must be a superset of flipped bits in d
// if b has set bits that both d and c do not have, this is IMPOSSIBLE

// otherwise, we can set bits for a such that:
// if the bit occurs in b and d, set that position to be zero for a
// if that bit does not occur in b and c but does in d, set that position to be one for a
// if the bit is set in b, c, and d, then set it to be zero in a
// 


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll b, c, d; cin >> b >> c >> d;
		ll ans = 0;
		// go through all 61 bits
		bool works = true;
		for (int i = 0; i < 61; i++) { // covers 61 bits only
			int bbit = (b >> i) & 1, cbit = (c >> i) & 1, dbit = (d >> i) & 1;
			if (bbit == 0) {
				if ((cbit == 0 && dbit == 1)) {
					ans |= (1ll << i);
				} else if (cbit == 1 && dbit == 1) {
					works = false;
					break;
				}
			} else {
				if (cbit == 1 && dbit == 0) {
					ans |= (1ll << i);
				} else if (cbit == 0 && dbit == 0) {
					works = false;
					break;
				}
			}
		}
		if (works) {
			cout << ans << endl;
		}
		else cout << -1 << endl;

	}
	return 0;
}