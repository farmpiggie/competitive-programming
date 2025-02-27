/* first # should be even if possible
 * every other subsequent # should be odd
 * # of points gained = (1 point if there is >= 1 even number) + (# of odd numbers)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x & 1) odd++;
			else even++;
		}
		cout << (even > 0 ? 1 : -1) + odd << '\n'; // if no evens, one of the odds cant count.
	}
}
