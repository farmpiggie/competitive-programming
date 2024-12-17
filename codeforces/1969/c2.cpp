#include <bits/stdc++.h>
using namespace std;

#define ll long long

// dp[i][j] = min sum from 0...i where i is min number, with j values used.
// dp[i][j] = dp[i - x][j - x] + (a[i - x] * y), a[i] * (x - y) for all x <= j, y <= x
// choose what amount to extend previous, choose what amount to extend current
// choose to 
// or i can choose to extend j up to a certain point as well

const int MAXN = 300005;

int lg[MAXN+1];
int max_k = 25;

int calc_min(int left, int right, vector<vector<int>>& st) {
	int i = lg[right - left + 1];
	return min(st[i][left], st[i][right - (1 << i) + 1]);
}

int main() {

	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	lg[i] = lg[i/2] + 1;

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));

		vector<vector<int>> st(26, vector<int>(n + 1, 0));
		for (int i = 0; i <= n; i++) st[0][i] = a[i];
		for (int i = 1; i <= 25; i++) {
			for (int j = 0; j + (1 << i) <= n + 1; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}	
		dp[0][0] = 0;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			dp[i][0] = sum;
			for (int j = 1; j <= k; j++) {
				for (int b = 0; b <= j && i - b - 1 >= 0; b++) {
					if (b == 0 && dp[i - 1][j] != LLONG_MAX) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
					else if (dp[i - b - 1][j - b] != LLONG_MAX) dp[i][j] = min(dp[i][j], 1ll * calc_min(i - b, i, st) * (b + 1) + dp[i - b - 1][j - b]);
				}
			}
		}
		ll ans = LLONG_MAX;
		for (int j = 0; j <= k; j++) {
			ans = min(ans, dp[n][j]);
		}
		cout << ans << '\n';


	}
	return 0;
}
