#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
		x %= m;
	}

	if (n > m) {
		cout << "YES\n";
	} else {
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][a[0]] = 1;
		for (int i = 1; i < n; i++) {
			dp[i][a[i]] = 1;
			for (int j = 0; j < m; j++) {
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][(j + m - a[i]) % m]));
			}
		}
		cout << (dp[n - 1][0] ? "YES" : "NO") << '\n';
	}
	return 0;
}
