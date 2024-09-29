// the bounds look a little strange
// most time taken is 50 * 10^5
// dp[i][j] = first i tasks, j is alice time = bob time
// dp[i][j] = min(dp[i - 1][j] + b[i], dp[i - 1][j - a[i]]);
// ans = min(j, dp[n - 1][j]) for all 0 <= j < n
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN = 50 * 100001;
const int INF = MAXN;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(MAXN, INF));
	dp[0][a[0]] = 0;
	dp[0][0] = b[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i]);
			if (j - a[i] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
		}
	}
	ll ans = LLONG_MAX;
	for (int j = 0; j < MAXN; j++) {
		ans = min(ans, max(1ll * j, dp[n - 1][j]));
	}
	cout << ans << '\n';
	return 0;
}
