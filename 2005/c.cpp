#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vi>
#define v3i vector<v2i>

/*
P = (n, a, r, e, k) 
used[i][j] = # of chars used given starting char is j.
wasted[i][j] = (# of chars in set P in a[i]) - used[i][j]

dp[i][j] = max(score_n - score_c) considering first i words, next char needed is p[j]
// 4 + 11 -> 15
// means we created 3 new words, subtract 15
dp[i][j] = min(dp[i - 1][j], (dp[i - 1][x] - (wasted[i][j] + j) + ((x + used[i][x]) / 5) * 5 + (x + used[i][x] >= 5 ? x : 0) if (used[i][x] + x) % p == j)
*/

int main() {
	string narek = "narek";
	set<char> crs(narek.begin(), narek.end());

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string> a(n);
		for (string& s : a) cin >> s;
		vi dp(5, -1e9);
		dp[0] = 0;

		vi cur;
		for (string& s : a) {
			cur = dp;
			for (int j = 0; j < 5; j++) {
				int c = dp[j];
				int k = j;
				for (char x : s) {
					if (crs.count(x)) c--;
					if (narek[k] == x) k++;
					if (k == 5) {
						c += 10;
						k = 0;
					}
				}
				cur[k] = max(cur[k], c);
			}
			dp = cur;
		}

		int ans = 0;
		for (int x : dp) ans = max(ans, x);
		cout << ans << '\n';
	}
	return 0;
}



