/*
 * easy version where k = 0
 * deconstruct each # into its prime factors (we only care about odd parity primes)
 * reduce each # to a product of odd parity primes
 * greedily extend each segment until we see a repeat #.
 *
 * how do you choose which #s to change? and what do you change the #s to?
 * we can change the #s into some super large prime. so it wont overlap with any #s.
 *
 * left[i][j] = min l s.t. a[l]...a[i] is distinct with j changes.
 * two pointer for this.
 *
 * dp[i][j] = min segments satisfying a[0]..a[i] with j changes.
 * dp[i][j] = min(k + dp[left[i][k]][j - k]) for all k
 * ans is dp[n - 1][k]
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3200; // sqrt(1e7)

int main() {
	vector<int> primes, marked(MAXN, 0);
	for (int i = 2; i < MAXN; i++) {
		if (!marked[i]) {
			primes.push_back(i);
			for (int j = i; j < MAXN; j += i) {
				marked[j] = 1;
			}
		}
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n, 1);
		set<int> unique;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			for (int p : primes) {
				int cnt = 0;
				while (x % p == 0) {
					x /= p;
					cnt++;
				}
				if (cnt & 1) {
					a[i] *= p;
				}
			}
			if (x > 1) a[i] *= x;
			unique.insert(a[i]);
		}

		map<int, int> compress;
		int tot = 0;
		for (int num : unique) {
			compress[num] = tot++;
		}
		for (int &x : a) {
			x = compress[x];
		}
		
		// left[i][j] = leftmost index l s.t. a[l]....a[i] is distinct with j changes.
		vector<vector<int>> left(n + 1, vector<int>(k + 1, 0));
		for (int j = 0; j <= k; j++) {
			vector<int> cnt(tot, 0);
			int repeat = 0;
			int l = 0, r = 0;
			while (r < n) {
				if (cnt[a[r]] > 0) {
					repeat++;
				}
				cnt[a[r]]++;
				while (repeat > j) {
					if (cnt[a[l]] > 1) repeat--;
					cnt[a[l++]]--;
				}

				left[++r][j] = l; // 1 indexed here
			}
		}

		
		// dp[i][j] = min segments for a[0]....a[i] with j changes used
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				for (int x = 0; x <= j; x++) {
					dp[i][j] = min(dp[i][j], 1 + dp[left[i][x]][j - x]);
				}
			}
		}
		int ans = 1e9;
		for (int j = 0; j <= k; j++) {
			ans = min(ans, dp[n][j]);
		}
		cout << ans << '\n';
	}
}

