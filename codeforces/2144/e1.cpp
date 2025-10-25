#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;
const int MAXN = 5005;

int main() {
        vector<ll> pow2(MAXN);
        pow2[0] = 1;
        for (int i = 1; i < MAXN; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                if (n == 1) {
                        cout << 1 << '\n';
                        continue;
                }

                vector<int> l, r;

                int cur = 0;
                for (int x : a) {
                        if (x > cur) {
                                l.push_back(x);
                                cur = x;
                        }
                }

                cur = 0;
                for (int i = n - 1; i >= 0; i--) {
                        if (a[i] > cur) {
                                r.push_back(a[i]);
                                cur = a[i];
                        }
                }

                vector<vector<ll>> dp1(n, vector<ll>(l.size(), 0));
                vector<vector<ll>> dp2(n, vector<ll>(r.size(), 0));

                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < l.size(); j++) {
                                if (a[i] != l[j]) {
                                        if (i - 1 >= 0) {
                                                if (j + 1 < l.size() && a[i] > l[j]) dp1[i][j] = dp1[i - 1][j];
                                                else dp1[i][j] = dp1[i - 1][j] * 2 % MOD;
                                        }
                                } else {
                                        if (j == 0) dp1[i][0] = 1;
                                        if (i - 1 >= 0 && j - 1 >= 0) dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % MOD; // picking i

                                        if (i - 1 >= 0 && j < l.size() - 1) {
                                                dp1[i][j] = (dp1[i][j] + dp1[i - 1][j] * 2 % MOD) % MOD; // dont pick i, permute from before.
                                        }
                                }
                        }
                }

                for (int i = n - 1; i >= 0; i--) {
                        for (int j = 0; j < r.size(); j++) {
                                if (a[i] != r[j]) {
                                        if (i + 1 < n) {
                                                if (j + 1 < r.size() && a[i] > r[j]) dp2[i][j] = dp2[i + 1][j];
                                                else dp2[i][j] = dp2[i + 1][j] * 2 % MOD;
                                        }
                                } else {
                                        if (j == 0) dp2[i][0] = 1;
                                        if (i + 1 < n && j - 1 >= 0) dp2[i][j] = (dp2[i][j] + dp2[i + 1][j - 1]) % MOD;

                                        if (i + 1 < n && j < r.size() - 1) {
                                                dp2[i][j] = (dp2[i][j] + dp2[i + 1][j] * 2 % MOD) % MOD;
                                        }
                                }
                        }
                }


                ll ans = 0;

                for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                                if (a[i] == l.back() && a[j] == l.back()) {
                                        ans = (ans + dp1[i][l.size() - 1] * dp2[j][r.size() - 1] % MOD * pow2[j - i - 1] % MOD) % MOD;
                                }
                        }
                }

                for (int i = 0; i < n; i++) {
                        if (a[i] == l.back()) {
                                ll left = ((int) l.size() - 2 >= 0) ? dp1[i][l.size() - 2] : 1;
                                ll right = ((int) r.size() - 2 >= 0) ? dp2[i][r.size() - 2] : 1;
                                ans = (ans + left * right % MOD) % MOD;
                        }
                }

                cout << ans << '\n';
        }
}








