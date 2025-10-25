#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        sort(a.begin(), a.end());

        vector<ll> pre(n, 0);
        for (int i = 0; i < n; i++) {
            pre[i] = a[i];
            if (i)
                pre[i] += pre[i - 1];
        }

        ll ans = 0;

        // the array ls 2 * len + 1
        auto calc = [&](int len, int i) {
            ll right =
                1ll * a[i] * len -
                (pre[i + len] - pre[i]); // replace these elements with len
            ll y = min(k, i / len);
            ll left;
            if (k > i / len) { // we can fill everything.
                left = 1ll * a[i] * i - pre[i - 1];
            } else {
                left = 1ll * a[i] * y * len - pre[y * len - 1];
            }
            return left + right;
        };

        // 0 1 2 3 4 5 6 7, can go to 4.
        // n = 8
        // 0 1 2 3 4 5 6, can go to 3, n = 7
        for (int i = n - 2; i >= 1; i--) {
            // bin search on optimal x.
            int l = 1, r = min(n - 1 - i, i);
            while (l + 2 < r) {
                int m1 = l + (r - l) / 3;
                int m2 = l + 2 * (r - l) / 3;

                ll m1_ans = calc(m1, i);
                ll m2_ans = calc(m2, i);
                ans = max(ans, max(m1_ans, m2_ans));

                if (m1_ans < m2_ans) {
                    l = m1;
                } else {
                    r = m2;
                }
            }

            // cout << "l and r: " << l << ' ' << r << '\n';
            for (int j = l; j <= r; j++) {
                ans = max(ans, calc(j, i));
            }
        }
        /*
        for (int i = 2; 2 * i - 1 <= n; i++) {
            int x = 2 * i - 1; // size of operation
            int y = min(k, (n - 2) / (i - 1));
            ans = max(ans, 1ll * a[n - i] * (i - 1) - pre[y * (i - 1) - 1]);
            if (i == 3) {
                cout << 1ll * a[n - i] * (i - 1) << " " << pre[y * (i - 1) - 1]
                     << '\n';
            }
        }
        */
        cout << pre[n - 1] + ans << '\n';
    }
}