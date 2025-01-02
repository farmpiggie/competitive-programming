/*
 * ex: k: 2, (2, 6), (2, 12)
 * 2 -> 3
 * 3 -> 3
 * 4 -> 2
 * 5 -> 2
 * 6 -> 2
 * = 12
 *
 * check 2, we can add 3. (2, 4, 8)
 * now iterating from x = 2 until 0, find the corresponding x
 * (12 / 2 ^ 2) = 3
 * (12 / 2 ^ 1) = 6
 * (12 / 2 ^ 0) = 12
 *
 * then calculate answer
 *
 * add 3 from [2, 3]
 * add 2 from [4, 6]
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll k, l1, r1, l2, r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		ll kn = 1, ans = 0;
		for (int n = 0; r2 / kn >= l1; n++) {
			ans += max(0ll, min(r2 / kn, r1) - max((l2 - 1) / kn + 1, l1) + 1ll);
			kn *= k;
		}
		cout << ans << '\n';
	}
	return 0;
}

