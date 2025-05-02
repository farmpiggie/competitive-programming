#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		// l, l + 1, l + 3, l + 6, etc.
		// 0 -> 0
		// 1 -> 1 
		// 2 -> 3
		// 3 -> 6
		// 4 -> 10
		int diff = y - x;
		int l = 0, r = 1e5;
		int ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			ll res = 1ll * m * (m + 1) / 2;
			if (res <= diff) {
				ans = max(ans, m);
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		cout << ans + 1 << '\n';
	}
}

