/*
 * small squares: 1, 4, 9, 16, 25, 36, 
 * if n is even: ans = (1, 1, 2, 2, ...) since all diffs are one.
 * if n is odd: ans = (1, 8x, 1, 2, (14x), 1, 2) for 27?
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 2 == 0) {
			for (int i = 1; i <= n / 2; i++) {
				cout << i << " " << i << " ";
			}
		} else if (n >= 27) {
			cout << 1 << " ";
			for (int i = 3; i <= 6; i++) 
				cout << i << " " << i << " ";
			cout << 1 << " " << 2 << " ";
			for (int i = 7; i <= 13; i++) 
				cout << i << " " << i << " ";
			cout << 1 << " " << 2 << " ";
			// printed out 27 values, from 1 to 13.
			int cur = 14;
			for (int i = 27; i < n; i += 2) {
				cout << cur << " " << cur << " ";
				cur++;
			}
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
