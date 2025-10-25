/*
 * dp[i][j] = # of ways to consider a[0]....a[i] with duplicate values = j
 *
 * transitions:
 * 1. all three values are same
 *	pre[i - 1], pre[i - 1], pre[i - 1]
 *	to
 *	pre[i], pre[i - 1], pre[i - 1].
 * 
 * 2. only two values are the same
 * 2a. x x y -> x y y
 *	pre[i], pre[i - 1], pre[i - 1] 
 *	to
 *	pre[i], pre[i], pre[i - 1]
 *
 * 2b. x x y -> x x z
 *	j, j, pre[i - 1]
 *	j, j, pre[i]
 *
 * dp[0][0] = 3;
 * dp[i - 1][j]
 * pushes out to dp[i][pre[i - 1]] (3x multiplier) if j == pre[i - 1]
 * pushes out to dp[i][j]
 * pushes out to dp[i][pre[i - 1]] (2x multiplier) if j == pre[i]
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9  + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<int> pre(n);
		for (int i = 0; i < n; i++) {
			pre[i] = a[i];
			if (i) pre[i] ^= pre[i - 1];
		}

		if (n == 1) {
			cout << "3\n";
			continue;
		}
		map<int, ll> dp;
		dp[0] = 3;

		auto compute = [&](int i, int j) {
			ll res = 0;
			// pre[i - 1], pre[i - 1], pre[i - 1] -> pre[i - 1], pre[i - 1], pre[i]
			// j, j, pre[i - 1] -> j, j, pre[i]
			res = (res + (j == pre[i - 1] ? 3 : 1) * dp[j] % MOD); 
			// pre[i], pre[i], pre[i - 1] -> pre[i - 1], pre[i - 1], pre[i]
			res = (res + (j == pre[i - 1] ? 2 : 0) * dp[pre[i]] % MOD);
			return res;
		};

		// problem naively doing this is that it stays consistent.
		// i think we can just choose to increase dp[j] by 3x if j == pre[i - 1]
		// 
		for (int i = 1; i < n; i++) {
			
			ll x = dp[pre[i - 1]];
			x = (3 * x) % MOD;
			x = (x + 2 * dp[pre[i]] % MOD);

			if (i + 1 < n) dp[pre[i + 1]] = compute(i, pre[i + 1]);

			dp[pre[i - 1]] = x;

			/*
			for (auto [j, val] : dp) {
				cout << "dp[" << i << "][" << j << "]: " << val << '\n';
			}
			*/
		}

		ll ans = 0;
		for (auto [_, val] : dp) ans = (ans + val) % MOD;
		cout << ans << '\n';
	}
}


