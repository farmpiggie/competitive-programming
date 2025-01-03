/*
 * dp[i][j] = # of ways to color the first i bricks such that we change colors k times.
 * we can either stay the same color, or switch to a different color.
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (m - 1)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
	dp[0][0] = m;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1) % MOD) % MOD;
		}
	}
	cout << dp[n - 1][k] << '\n';
	return 0;
}
