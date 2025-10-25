#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>
#define v3i vector<v2i>

// array of size 5 million should be doable

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	v2i a(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int OFFSET = n * m * 100 + 4; // 100 / 2
	int MAX = OFFSET * 2 + 10;

	v3i dp(n, v2i(m, vi(MAX, 0)));
	dp[0][0][OFFSET + a[0][0]] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < MAX; k++) {
				int l = k - a[i][j];
				if (l >= 0 && l < MAX) {
					if (i - 1 >= 0) dp[i][j][k] += dp[i - 1][j][l];
					if (j - 1 >= 0) dp[i][j][k] += dp[i][j - 1][l];
				}
			}
		}
	}
	cout << dp[n - 1][m - 1][OFFSET] << '\n';
			

}