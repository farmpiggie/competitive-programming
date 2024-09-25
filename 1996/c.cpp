#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<char> a(n), b(n);
		for (char& x : a) cin >> x;
		for (char& x : b) cin >> x;

		vector<vector<int>> c(n, vector<int>(26, 0));
		vector<vector<int>> d(n, vector<int>(26, 0));
		c[0][(a[0] - 'a')] = 1;
		d[0][(b[0] - 'a')] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				c[i][j] = c[i - 1][j] + ((a[i] - 'a') == j);
				d[i][j] = d[i - 1][j] + ((b[i] - 'a') == j);
			}
		}

		while (q--) {
			int l, r; cin >> l >> r;
			--l; --r;
			vector<int> cnt_a(26, 0), cnt_b(26, 0);
			for (int i = 0; i < 26; i++) {
				cnt_a[i] = c[r][i] - (l == 0 ? 0 : c[l - 1][i]);
				cnt_b[i] = d[r][i] - (l == 0 ? 0 : d[l - 1][i]);
			}

			int diff = 0;
			for (int i = 0; i < 26; i++) {
				diff += abs(cnt_a[i] - cnt_b[i]);
			}
			cout << (diff + 1) / 2 << '\n';
		}
	}
	return 0;
}
