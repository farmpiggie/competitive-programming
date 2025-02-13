/*
 * dp[i] = sum over all subarrays ending at i.
 * dp[0] = 1
 * dp[i] = dp[i - 1] + (a[i] == a[i - 1] ? i + 1 : 1);
 * ans = sum over all dp[i].
 *
 * we cannot recompute this for each query.
 * how can we do this quickly?
 *
 * maybe we can note that a "change" can occur in the middle or on the end of a "segment"
 *
 * if change is in the middle of a segment, it will create more sections.
 * if the change is connecting two segments, it does the opposite
 * lets say the change occurs at position i, for a split/connection
 * all ranges from (i, i + 1) to (i, n - 1) add/subtract 1 -> + (n - 1 - (i + 1) + 1) -> (n - 1 - i)
 * all ranges from (0, i) to (i - 1, i) add/subtract 1 -> (i - 1 - 0 + 1) -> i
 * all ranges including (i - 1, i + 1) add/subtract 2 (goes from 1 to 3): i * (n - 1 - i) (left endpt from 0...i - 1, right endpt from i + 1....n - 1)
 *
 * okay. lets say the change is on the right/left edge of a segment.
 * all ranges from (i, i + 1) to (i, n - 1) subtract/add +1 (n - 1 - i)
 * all ranges from (0, i) to (i - 1, i) add/subtract +1 (i)
 * ranges containing (i - 1, i + 1) stay the same!
 *
 * edges cases on the ends:
 * if we "unmatch":
 * ans += (n - 1)
 * otherwise
 * ans -= (n - 1)
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string s; cin >> s;
                int n = (int) s.length();
                vector<ll> dp(n, 0);
                dp[0] = 1;
                ll ans = 1;
                for (int i = 1; i < n; i++) {
                        dp[i] = (dp[i - 1] + (s[i] == s[i - 1] ? 1 : i + 1)) % MOD;
                        ans = (ans + dp[i]) % MOD;
                }

                int q; cin >> q;
                while (q--) {
                        int v; cin >> v;
                        --v;

                        if (n == 1) {
                                cout << "1\n";
                                continue;
                        }

                        if (s[v] == '0') s[v] = '1';
                        else s[v] = '0';

                        if (v == 0 || v == n - 1) {
                                char nxt;
                                if (v == 0) nxt = s[v + 1];
                                else nxt = s[v - 1];
                                if (s[v] == nxt) {
                                        ans = (ans - n + 1 + MOD) % MOD;
                                } else {
                                        ans = (ans + n - 1) % MOD;
                                }
                        } else {
                                if (s[v - 1] == s[v + 1]) { // middle of block
                                        ll diff = 0;
                                        diff = (diff + (n - 1 - v)) % MOD;
                                        diff = (diff + v) % MOD;
                                        diff = (diff + 2ll * (v * (n - 1 - v))) % MOD;
                                        if (s[v - 1] == s[v]) { // merge
                                                ans = (ans - diff + MOD) % MOD;
                                        } else {
                                                ans = (ans + diff) % MOD;
                                        }
                                } else {
                                        ll diff = 0;
                                        diff = (diff + (n - 1 - v)) % MOD;
                                        diff = (diff - v + MOD) % MOD;
                                        if (s[v - 1] == s[v]) { // prev left of a segment
                                                ans = (ans - diff + MOD) % MOD;
                                        } else {
                                                ans = (ans + diff) % MOD;
                                        }
                                }
                        }
                        cout << ans << '\n';

                }
        }
}

                        


