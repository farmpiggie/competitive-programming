#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string a, b, c;
                cin >> a >> b >> c;
                int n = (int) a.size(), m = (int) b.size();
                vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
                dp[0][0] = 0;
                for (int i = 0; i <= n; i++) {
                        for (int j = 0; j <= m; j++) {
                                if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (c[i + j - 1] != a[i - 1]));
                                if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
                        }
                }
                cout << dp[n][m] << '\n';
        }
}
                                 
