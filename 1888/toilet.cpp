#include <bits/stdc++.h>
using namespace std;

// given n urinals, k people s.t. k <= n/2, return # of valid urinal combinations
const int MAXN = 1e3 + 5;
int t, n, k, dp[MAXN][MAXN];

// dp[i][j] = # of combos to use i urinals with j people

// prefix sum psum[x] = sum of all dp[k][j - 1] from 0 <= k <= x

// dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]
// ans = dp[n - 1][j] for all 0 <= j <= k

// O(nk)

/*
test cases:
4, 2

*/


void solve() {
	cin >> n >> k;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
			if (i - 2 >= 0 && j - 1 >= 0) dp[i][j] += dp[i - 2][j - 1];
		}
	}
	int ans = 0;
	for (int j = 0; j <= k; j++) {
		ans += dp[n - 1][j];
	}
	cout << ans << endl;
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}