/*
dp[i][j][k] = who wins the game if the kth element chosen at (i, j)?
have it be 0 if tsovak wins, 1 if narek wins, -1 if not reachable

if k % 2 == 0: (tsovak moves)
dp[i][j][k] = 1 if any dp[x][y][k + 1] s.t. (x > i && y > j && b[x][y] == a[k + 1]) else 0

else: (narek moves)
dp[i][j][k] = 0 if any dp[x][y][k + 1] s.t. (x > i && y > j && b[x][y] == a[k + 1]) else 1

dp[i][j][l - 1] = ((l + 1) % 2) if b[i][j] == a[l - 1] else -1

we can depend dp[i][j][k] on dp[i + 1][j][k], dp[i][j + 1][k], and b[i + 1][j + 1] == a[k + 1]), making transitions O(1).

answer is just T if there exists a dp[i][j][0] == 0, otherwise N.

*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vi>
#define v3i vector<v2i>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l, n, m; cin >> l >> n >> m;
		vi a(l);
		for (int& x : a) cin >> x;
		v2i b(n, vi(m));
		for (auto& x : b) for (int& y : x) cin >> y;

		v3i dp(n, v2i(m, vi(l, -1)));
		// init
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				if (b[i][j] == a[l - 1]) {
					dp[i][j][l - 1] = (l + 1) % 2;
				}
			}
		
		
		for (int k = l - 2; k >= 0; k--) {
			v2i cur(n, vi(m, 0)); // keeps track if theres a choice in dp[x][y][k + 1] within this grid that causes us to lose.
			int target = 1 - (k % 2); // if we find any value of target, this contributes to our answer.
			// init rightmost column
			for (int i = 0; i < n; i++) {
				if (b[i][m - 1] == a[k]) {
					dp[i][m - 1][k] = (k % 2); // this player wins by selecting this.
				}
			}
			// init bottommost row
			for (int j = 0; j < m; j++) {
				if (b[n - 1][j] == a[k]) {
					dp[n - 1][j][k] = (k % 2); // this player wins by selecting this.
				}
			}

			// init cur


			// otherwise answer is contributed from above
			for (int i = n - 2; i >= 0; i--) {
				for (int j = m - 2; j >= 0; j--) {
					int x = cur[i][j + 1], y = cur[i + 1][j];
					cur[i][j] |= x || y || (dp[i + 1][j + 1][k + 1] == target); // just updating cur!
					if (b[i][j] != a[k]) continue; // check equivalence for setting DP
					if (cur[i][j]) dp[i][j][k] = target; // next guy can make a winning state.
					else dp[i][j][k] = (k % 2); // we can make a winning state.
				}
			}
		}
		int ans = 1;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (dp[i][j][0] == 0) ans = 0;
		/*
		cout << dp[5][5][5] << '\n';
		cout << dp[4][4][4] << '\n';
		cout << dp[3][3][3] << '\n';
		cout << dp[2][2][2] << '\n';
		cout << dp[1][1][1] << '\n';
		cout << dp[0][0][0] << '\n';
		*/
		cout << ((ans == 0) ? "T" : "N") << '\n';
	}
	return 0;
}
