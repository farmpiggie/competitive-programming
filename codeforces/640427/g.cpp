#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	vector<vector<ll>> dp(n + 1, vector<ll>(10, 0)); // dp[i][j] = # of staircase numbers with length i and first digit of j.
	for (int j = 0; j < 10; j++) dp[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			if (j + 1 <= 9) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans << '\n';
}

	