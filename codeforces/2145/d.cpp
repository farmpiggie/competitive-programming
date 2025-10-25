#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;

                int maxk = n * (n - 1) / 2;

                vector<vector<int>> dp(n + 1, vector<int>(maxk + 1, 0));
                vector<vector<int>> p(n + 1, vector<int>(maxk + 1, -1));

                dp[0][0] = 1;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j <= maxk; j++) {
                                if (!dp[i][j]) continue;
                                for (int k = 1; k <= n - i; k++) {
                                        int add = k * (k - 1) / 2;
                                        dp[i + k][j + add] = 1;
                                        p[i + k][j + add] = k;
                                }
                        }
                }

                k = maxk - k;
                if (dp[n][k]) {
                        vector<int> ans;
                        int cur = n, curk = k;
                        while (cur != 0) {
                                int y = p[cur][curk];
                                ans.push_back(y);
                                curk -= y * (y - 1) / 2;
                                cur -= y;
                        }
                        vector<int> res;
                        cur = n + 1;
                        for (int i = 0; i < (int) ans.size(); i++) {
                                int y = ans[i];
                                for (int x = cur - y; x < cur; x++) {
                                        res.push_back(x);
                                }
                                cur -= y;
                        }

                        for (int x : res) cout << x << ' ';
                        cout << '\n';
                } else {
                        cout << "0\n";
                }
        }
}

