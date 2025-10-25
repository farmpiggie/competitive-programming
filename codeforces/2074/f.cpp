#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l1, r1, l2, r2;
		cin >> l1 >> l2 >> r1 >> r2;
		ll ans = 0;
		ll len = 1;
		while (l1 < l2 && r1 < r2) {
			if (l2 - l1 == len && r2 - r1 == len && l1 % len == 0 && r1 % len == 0) {
				ans++;
				break;
			}

			ll next_len = len * 2;

			ll diff = 2 * ((r2 - r1) / len - 1) + 2 * ((l2 - l1) / len - 1);
			//cout << "diff: " << diff << '\n';
		//	cout << (r2 - r1) / len - 2 << " " << (l2 - l1) / len - 2 << '\n';

			int nl1 = l1, nl2 = l2, nr1 = r1, nr2 = r2;
			if (l1 % next_len == 0) {
				diff -= ((r2 - r1) / len - 2);
			} else {
				nl1 = l1 + len;
			}

			if (l2 % next_len == 0) {
				diff -= ((r2 - r1) / len - 2);
			} else {
				nl2 = l2 - len;
			}
			if (r1 % next_len == 0) {
				diff -= (l2 - l1) / len - 2;
			} else {
				nr1 = r1 + len;
			}
			if (r2 % next_len == 0) {
				diff -= (l2 - l1) / len - 2;
			} else {
				nr2 = r2 - len;
			}

			if (l1 % next_len == 0 && r1 % next_len == 0) {
				diff--;
			}
			if (l1 % next_len == 0 && r2 % next_len == 0) {
				diff--;
			}
			if (l2 % next_len == 0 && r1 % next_len == 0) {
				diff--;
			}
			if (l2 % next_len == 0 && r2 % next_len == 0) {
				diff--;
			}
			//cout << "diff after: " << diff << '\n';
			ans += diff;
			len *= 2;
			l1 = nl1;
			l2 = nl2;
			r1 = nr1;
			r2 = nr2;
			//cout << "new dim: " << l1 << " " << l2 << " " << r1 << " " << r2 << '\n';
		}
		cout << ans << '\n';
	}
}

				

