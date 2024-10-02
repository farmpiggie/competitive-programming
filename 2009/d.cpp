/*
0 <= x <= n
0 <= y <= 1

we can pair any three points (a, 0), (b, 0), (b, 1) or (a, 1), (b, 0), (b, 1)

ans = (# of indices with both y = 0 and y = 1) * (total # points - 2)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(n + 1, 0);
		vector<vector<int>> set(n + 1, vector<int>(2, 0));

		// one edge horizontal, one edge vertical
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			set[x][y] = 1;
			cnt[x]++;
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++) {
			if (cnt[i] == 2) ans += (n - 2);
		}

		// only one edge horizontal
		for (int i = 1; i < n; i++) {
			ans += (set[i - 1][0] && set[i][1] && set[i + 1][0]) + (set[i - 1][1] && set[i][0] && set[i + 1][1]);
		}
		cout << ans << endl;
	}
	return 0;
}