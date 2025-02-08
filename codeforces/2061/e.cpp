/*
 * all transitions can be modeled as 2^10 = 1024 transitions, each with its own cost
 * dp[i][j] = min sum of first i elements given we have used j moves.
 * dp[i][j] = min(dp[i - 1][j - c[k]] + (a[i] & v[k])) for k in 2^10
 * unfortunately too slow. how to optimize?
 * we know the transition cost c[k] is at most 10. so we can bound for each a[i], the cheapest k moves <= 10 that results in min sum.
 * 
 * we can calculate for any # of moves <= 10, the best subset of b_i & a[i] -> n * 2^10 time
 * 
 *
 * let b[i][j] = min cost of a[i] given we use j operations
 * dp[i][j] = min(dp[i - 1][j - k] + c[i][k]) for k <= 10
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, k; cin >> n >> m >> k;
                vector<int> a(n), b(m);
                for (int &x : a) cin >> x;
                for (int &x : b) cin >> x;

                vector<vector<int>> operators(11);
                for (int i = 1; i < (1 << m); i++) {
                        int op = (1 << 30) - 1; // all 1s
                        int bits = 0;
                        for (int j = 0; j < m; j++) {
                                if ((i >> j) & 1) {
                                        bits++;
                                        op &= b[j];
                                }
                        }
                        operators[bits].push_back(op);
                }
                
                // c[0][0] >= c[0][1] >= c[0][2]
                // (c[0][0] - c[0][1]) > (c[0][1] - c[0][2])
                // 1: a
                // 2: b
                // 3: c
                vector<vector<int>> c(n, vector<int>(11, 0)); // c[i][j] = min value of ith number after j operations (monotonically decreasing)
                for (int i = 0; i < n; i++) {
                        c[i][0] = a[i];
                        for (int j = 1; j <= 10; j++) {
                                int best = a[i];
                                for (int x : operators[j]) {
                                        if ((a[i] & x) < best) {
                                                best = a[i] & x;
                                        }
                                }
                                c[i][j] = min(c[i][j - 1], best);
                        }
                }

                ll ans = 0;
                for (int x : a) ans += x;

                vector<int> arr;
                for (int i = 0; i < n; i++) {
                        for (int j = 1; j <= 10; j++) {
                                arr.push_back(c[i][j - 1] - c[i][j]);
                        }
                }

                sort(arr.rbegin(), arr.rend());
                for (int i = 0; i < k; i++) {
                        ans -= arr[i];
                }

                cout << ans << '\n';
        }
}



