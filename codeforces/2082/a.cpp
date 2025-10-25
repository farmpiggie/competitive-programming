/*
 * each row and each column must have an even parity of 1s.
 * changing one number will flip the parity of one row and one column
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string> a(n);
		for (string& x : a) cin >> x;
		
		int x = 0;
		for (int i = 0; i < n; i++) {
			int parity = 0;
			for (int j = 0; j < m; j++) {
				parity += (a[i][j] - '0');
			}
			if (parity & 1) x++;
		}
		int y = 0;
		for (int j = 0; j < m; j++) {
			int parity = 0;
			for (int i = 0; i < n; i++) {
				parity += (a[i][j] - '0');
			}
			if (parity & 1) y++;
		}
		cout << max(x, y) << '\n';
	}
}
				
	