#include <bits/stdc++.h>
using namespace std;

/*
q: given three arrays a, b, c, choose i != j != k s.t. a[i] + b[j] + c[k] is maximized
dp[i][x][y][z] = max value given we have considered first i days, x means a[i] has been chosen, y means b[i] has been chosen, etc
dp[i][1][1][0] = 
*/


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		for (int& x : c) cin >> x;
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(2, -INT_MAX)));
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++) {
			vector<vector<vector<int>>> ndp(2, vector<vector<int>>(2, vector<int>(2, 0)));
			ndp[0][0][0] = dp[0][0][0];
			ndp[0][0][1] = max(dp[0][0][1], dp[0][0][0] + c[i - 1]);
			ndp[0][1][0] = max(dp[0][1][0], dp[0][0][0] + b[i - 1]);
			ndp[1][0][0] = max(dp[1][0][0], dp[0][0][0] + a[i - 1]);
			ndp[0][1][1] = max(dp[0][1][1], max(dp[0][1][0] + c[i - 1], dp[0][0][1] + b[i - 1]));
			ndp[1][1][0] = max(dp[1][1][0], max(dp[0][1][0] + a[i - 1], dp[1][0][0] + b[i - 1]));
			ndp[1][0][1] = max(dp[1][0][1], max(dp[1][0][0] + c[i - 1], dp[0][0][1] + a[i - 1]));
			ndp[1][1][1] = max(dp[1][1][1], max(dp[1][1][0] + c[i - 1], max(dp[1][0][1] + b[i - 1], dp[0][1][1] + a[i - 1])));
			dp = ndp;
		}
		cout << dp[1][1][1] << endl;
	}
	return 0;
}
