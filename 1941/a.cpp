#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> b(n), c(m);
		for (int& x : b) cin >> x;
		for (int& x : c) cin >> x;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i] + c[j] <= k) ans++;
			}
		}
		cout << ans << '\n';
	}
}