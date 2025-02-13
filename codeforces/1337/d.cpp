#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int nr, ng, nb; cin >> nr >> ng >> nb;
                vector<int> r(nr), g(ng), b(nb);
                for (int &x : r) cin >> x;
                for (int &x : g) cin >> x;
                for (int &x : b) cin >> x;
                sort(r.begin(), r.end());
                sort(g.begin(), g.end());
                sort(b.begin(), b.end());
                auto diff = [&](int x, int y, int z) {
                        return 1ll * (x - y) * (x - y) + 1ll * (y - z) * (y - z) + 1ll * (x - z) * (x - z);
                };
                auto compute = [&](const vector<int>& a, const vector<int>& b, const vector<int>& c) {
                        ll best = LLONG_MAX;
                        for (int y : b) {
                                int x = a.front();
                                int l = 0, r = a.size() - 1;
                                while (l <= r) {
                                        int m = (l + r) / 2;
                                        if (a[m] <= y) {
                                                x = max(x, a[m]);
                                                l = m + 1;
                                        } else {
                                                r = m - 1;
                                        }
                                }

                                int z = c.back();
                                l = 0, r = c.size() - 1;
                                while (l <= r) {
                                        int m = (l + r) / 2;
                                        if (c[m] >= y) {
                                                z = min(z, c[m]);
                                                r = m - 1;
                                        } else {
                                                l = m + 1;
                                        }
                                }
                                best = min(best, diff(x, y, z));
                        }
                        return best;
                };

                                                

                ll ans = LLONG_MAX;
                ans = min(ans, compute(r, g, b));
                ans = min(ans, compute(r, b, g));
                ans = min(ans, compute(g, r, b));
                ans = min(ans, compute(g, b, r));
                ans = min(ans, compute(b, r, g));
                ans = min(ans, compute(b, g, r));

                cout << ans << '\n';
        }
}
