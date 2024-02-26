#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int& x : a) {
        cin >> x;
    }
    
    // compress
    int cur = a[0];
    vector<int> b;
    for (int& x : a) {
        if (x == cur) continue;
        b.push_back(cur);
        cur = x;
    }
    b.push_back(cur);
    
    // change a
    a.resize(0);
    if (b[0] != 0) {
        a.push_back(0); // padding
    }   
    for (int x : b) {
        a.push_back(x);
    }

    n = (int) a.size();
    
    // dp
    
    dp.assign(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) continue;
            dp[l][r] = min(dp[l][r], 1 + dp[l + 1][r]);
            // split across (l, m - 1) and 
            for (int m = l + 1; m <= r; m++) {
                if (a[m] == a[l]) {
                    dp[l][r] = min(dp[l][r], dp[l][m - 1] + dp[m][r]);
                }
            }
        }
    }
    
    cout << dp[0][n - 1] << '\n';
    
    
    return 0;
}