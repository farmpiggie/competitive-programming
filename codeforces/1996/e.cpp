/* 
prefix sum: mark all 0s as 1, mark all 1s as -1
we know [i, j] has equal # of 0s or 1s if pre[j] - pre[i - 1] = 0
for a value j, we can store all instances of previous indices i in a hashmap

besides just finding the # of [i, j] that work, we also need to know how often it occurs
in a string of length n, we can calculate how often each occurs...

put in a vector all indices with the same pre[i] value...
{a, b, c}
answer would be: 
(1...a + 1) * (b.....n) + (1...(a + 1) + 1...(b + 1) + (c.....n))....
*/ 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();

		map<int, vector<int>> mp;
		vector<int> pre(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + (s[i - 1] == '0' ? 1 : -1);
			mp[pre[i]].push_back(i);
		}

		ll ans = 0;
		map<int, ll> dp;
		dp[0] = 1;
		for (auto &[_, arr] : mp) {
			for (int x : arr) {
				// cout << "x: " << x << endl;
				// cout << dp[pre[x]] << " " << (n - x + 1) << endl;
				// cout << "adding: " << (dp[pre[x]] * (n - x + 1)) << endl;
				ans = (ans + (dp[pre[x]] * (n - x + 1)) % MOD) % MOD;
				dp[pre[x]] += (x + 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}