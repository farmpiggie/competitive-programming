/*
 * each a_i represents number of liars to the left of i
 * 
 * dp[i][j][0/1] = # of combos considering 0....i with j total liars and ith person is/is not liar
 *
 * 
 * dp[i][j][0] = dp[i - 1][a[i]][0] + dp[i - 1][a[i]][1] 
 * dp[i][j][1] = dp[i - 1][j - 1][0] // there were a[i] - 1 liars
 *
 * ans is sum of all dp[n - 1][j][0/1] for all values
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		if (n == 1) {
			cout << (a[0] == 0 ? 2 : 1) << '\n';
			continue;
		}
		
		vector<int> dp(n, 0);
		if (a[0] == 0) dp[0] = 1;
		if (a[1] == 1) dp[1] = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) dp[i] = (dp[i] + dp[i - 1]) % MOD;
			if (i - 2 >= 0 && a[i] == a[i - 2] + 1) dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
		
		cout << (dp[n - 1] + dp[n - 2]) % MOD << '\n';
	}
}




