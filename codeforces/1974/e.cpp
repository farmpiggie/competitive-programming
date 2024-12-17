#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define v2l vector<vl>


int main() {
	int t; cin >> t;
	while (t--) {
		ll m, x; cin >> m >> x;
		vl c(m), h(m);
		for (int i = 0; i < m; i++) cin >> c[i] >> h[i];
		int MAXH = 0;
		for (int i = 0; i < m; i++) MAXH += h[i];
		MAXH++;
		v2l dp(m + 1, vl(MAXH, LLONG_MIN)); // 50 * 1e5 = 536?
		dp[0][0] = 0;
		if (c[0] == 0) dp[0][h[0]] = 0;
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < MAXH; j++) {
				dp[i][j] = max(dp[i - 1][j] + x, dp[i][j]);
				if (j - h[i] >= 0 && dp[i - 1][j - h[i]] >= c[i] - x) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + x - c[i]);
				}
			}
		}

//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= 15; j++) {
//				cout << (dp[i][j] == LLONG_MIN ? -1 : dp[i][j]) << "\t";
//			}
//			cout << '\n';
//		}

		int ans = 0;
		for (int j = 0; j < MAXH; j++) if (dp[m - 1][j] >= 0) ans = max(ans, j);
		cout << ans << '\n';
	}
	return 0;
}
