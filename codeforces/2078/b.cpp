/*
 * all people should be between (n - 1) and n.
 * if k is odd, send everyone to n.
 * otherwise, send everyone to (n - 1).
 * point (n - 1) to n.
 * point n to n - 1.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n - 2; i++) {
			if (k & 1) cout << n << ' ';
			else cout << n - 1 << ' ';
		}
		cout << n << " " << n - 1 << '\n';
	}
}