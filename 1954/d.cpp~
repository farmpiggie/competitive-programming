#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n, 0);
	for (int& x : a) cin >> x;
	
	sort(a.begin(), a.end());	
	vector<vector<ll>> dp(n, vector<ll>(5001, 0));
	vector<ll> sum(5001, 0);
	dp[0][a[0]] = 1;
	dp[0][0] = 1;
	sum[a[0]] += 1;
	sum[0] += 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 5001; j++) {
			if (j - a[i] >= 0) dp[i][j] = sum[j - a[i]];
		}
		for (int j = 0; j < 5001; j++) {
			sum[j] = (sum[j] + dp[i][j]) % MOD;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5001; j++) {
			if (i == 0 && j == 0) continue;
			ll mult = max(a[i], (j + 1) / 2);
			ans = (ans + ((mult * dp[i][j]) % MOD)) % MOD;
		}
	}
	cout << ans << '\n';


	return 0;
}
