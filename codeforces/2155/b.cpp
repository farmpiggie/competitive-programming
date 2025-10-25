#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                if (k + 1 == n * n) { // not possible
                        cout << "NO\n";
                        continue;
                }
                // we always have two squares that can point into each other
                vector<vector<char>> ans(n, vector<char>(n, 0));
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if (cnt < k) {
                                        ans[i][j] = 'U';
                                        cnt++;
                                }
                        }
                }

                bool seen = false;
                char dir = 'R';
                for (int i = 0; i < n; i++) {
                        if (ans[i][n - 1] == 'U') continue;
                        for (int j = 0; j < n; j++) {
                                if (ans[i][j] == 'U') continue;
                                if (i < n - 1) {
                                        ans[i][j] = 'D';
                                } else {
                                        if (!seen) {
                                                seen = true;
                                                ans[i][j] = dir;
                                                dir = 'L';
                                        } else if (j == n - 1) {
                                                ans[i][j] = 'L';
                                        } else {
                                                ans[i][j] = dir;
                                                if (dir == 'L') dir = 'R';
                                                else dir = 'L';
                                        }
                                }
                        }
                }
                cout << "YES\n";
                for (auto x : ans) {
                        for (char y : x) {
                                cout << y;
                        }
                        cout << '\n';
                }
        }
}
















