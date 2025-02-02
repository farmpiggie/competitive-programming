/*
 * 1 -> 1
 * 2 -> 2
 * 3 -> 9
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		
		vector<int> dp(9, 0);
		dp[0] = 1;

		for (char c : s) {
			vector<int> ndp(9, 0);
			int digit = c - '0';
			for (int i = 0; i < 9; i++) {
				ndp[i] = dp[(i + digit) % 9];
			}
			if (digit == 2 || digit == 3) {
				for (int i = 0; i < 9; i++) {
					ndp[i] = max(ndp[i], dp[(i + digit * digit) % 9]);
				}
			}
			dp = ndp;
		}

		cout << (dp[0] == 1 ? "YES" : "NO") << '\n';
	}
}


		
