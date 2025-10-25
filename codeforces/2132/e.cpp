#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, q; cin >> n >> m >> q;
                vector<int> a(n), b(m);
                for (int &x : a) cin >> x;
                for (int &x : b) cin >> x;

                sort(a.rbegin(), a.rend());
                sort(b.rbegin(), b.rend());

                vector<ll> asum(n + 1, 0), bsum(m + 1, 0);
                for (int i = 1; i <= n; i++) {
                        asum[i] = asum[i - 1] + a[i - 1];
                }
                for (int i = 1; i <= m; i++) {
                        bsum[i] = bsum[i - 1] + b[i - 1];
                }

                while (q--) {
                        int x, y, z; cin >> x >> y >> z;
                        int l = max(z - y, 0);
                        int r = min(x, z);
                        while (l + 2 < r) {
                                int m1 = l + (r - l) / 3;
                                int m2 = l + (r - l) * 2 / 3;
                                ll sum1 = asum[m1] + bsum[z - m1];
                                ll sum2 = asum[m2] + bsum[z - m2];
                                if (sum1 > sum2) {
                                        r = m2;
                                } else {
                                        l = m1;
                                }
                        }

                        ll ans = 0;
                        for (int i = l; i <= r; i++) {
                                ans = max(ans, asum[i] + bsum[z - i]);
                        }

                        cout << ans << '\n';
                }
        }
}


