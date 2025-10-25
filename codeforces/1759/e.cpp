#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
typedef long long ll;

ll dp[MAXN][3][2];

int main() {
	// ifstream cin("humanoid.in");
	int t; cin >> t;
	while (t--) {
		int n, h; cin >> n >> h;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());

		// dp[i][j][k] -> dp[# people eaten][green][blue] = max power
		int max_humans_consumed = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 2; k++) {
					dp[i][j][k] = -1;
				}
			}
		} 

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				ll power_level = h;
				if (j > 0) power_level *= (2 * j);
				if (k > 0) power_level *= (3 * k);
				dp[0][j][k] = power_level;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 2; k++) {
					// choose to eat human i at current power level
					if (dp[i - 1][j][k] > arr[i - 1]) {
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + arr[i - 1] / 2);
					} 
					if (k - 1 >= 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] * 3);
					}
					if (j - 1 >= 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] * 2);
					}
					if (j - 2 >= 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - 2][k] * 4);
					}
					if (j - 1 >= 0 && k - 1 >= 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] * 6);
					}
					if (j - 2 >= 0 && k - 1 >= 0) {
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - 2][k - 1] * 12);
					}
					if (dp[i][j][k] != -1) ans = max(ans, i);
				}
			}
		}
		cout << ans << endl;
		


	}
	return 0;
}