#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vector<int>>

int main() {
    int n, q; cin >> n >> q;
    vector<array<int, 2>> a(q);
    for (auto& [x, y] : a) {
        cin >> x; --x;
        char c; cin >> c;
        if (c == '+') y = 1;
        else y = 0;
    }
    
    v2i dist(n, vi(n, 1));
    vi l(n, 0), r(n, 0); // amt left/right endpt has moved

    for (auto& [x, y] : a) {
        if (y) r[x]++;
        else l[x]++;

        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            dist[i][x] = max(dist[i][x], 1 + max(0, r[i] - l[x]));
            dist[x][i] = max(dist[x][i], 1 + max(0, r[x] - l[i]));
        }
    }

    // dp[i][j] = min cost ending with element i, bitmask j
    // dp[i][j] = min(dp[k][j - (1 << k)] + cost(k, j)) for all k set bits in j
    v2i dp(n, vi(1ll << n, 1e9));
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
    }

    for (int j = 1; j < (1 << n); j++) {
        if (__builtin_popcount(j) == 1) continue; // base case skipped
        for (int i = 0; i < n; i++) {
            if (!(j >> i & 1)) continue;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                if (!(j >> k & 1)) continue;
                // i + k bits are set
                dp[i][j] = min(dp[i][j], dp[k][j - (1 << i)] + dist[k][i]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1] + r[i]);
    }
    cout << ans << '\n';
    return 0;
}

        


