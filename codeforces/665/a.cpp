#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int n = (int) s.length();
	vector<vector<int>> dp(n, vector<int>(26, 1e9)); // dp[i][j] = # of changes 0...i for s[i] = j
	for (int i = 0; i < 26; i++) {
		if (s[0] == (i + 'a')) {
			dp[0][i] = 0;
		} else dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				if (j == k) continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (s[i] != ('a' + j))); // add 1 if have to change char
			}
		}
	}
	int ans = 1e9;
	for (int j = 0; j < 26; j++) ans = min(ans, dp[n - 1][j]);
	cout << ans << '\n';
	return 0;
}

		
