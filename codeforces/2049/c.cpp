/*\
 * if n is even and abs(x - y) is odd, we can just number 0, 1, 0, 1...
 * if n is odd, just do either x or y as 2 then do 0 1 0 1 etc.
 * if n is even and abs(x - y) is even, bump either x or y to 2, then do 1 0 1 0 1 etc.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		--x; --y;
		vector<int> ans(n);
		if (n % 2) { // odd
			ans[x] = 2;
			for (int i = 1; i < n; i++) {
				ans[(x + i) % n] = (i % 2);
			}
		} else {
			ans[x] = 2;
			bool odd = abs(x - y) % 2 == 1;
			if (odd) {
				for (int i = 0; i < n; i++) {
					ans[i] = i % 2;
				}
			} else {
				for (int i = 1; i < n; i++) {
					ans[(x + i) % n] = ((i + odd) % 2);
				}
			}
		}
		for (int x : ans) cout << x << " ";
		cout << '\n';
	}
}

