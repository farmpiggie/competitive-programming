#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 2e5 + 100;

int ceil(int x, int y) { return (x + (y - 1)) / y; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll y;
        cin >> n >> y;
        vector<int> c(n);
        for (int &x : c)
            cin >> x;

        vector<int> cnt(MAXN, 0);
        int mx = 0;
        for (int x : c) {
            cnt[x]++;
            mx = max(mx, x);
        }

        vector<int> sum(MAXN, 0);
        for (int i = 1; i < MAXN; i++)
            sum[i] = sum[i - 1] + cnt[i];

        if (mx == 1) {
            cout << n << '\n';
            continue;
        }

        ll ans = LLONG_MIN;
        for (int x = 2; x <= mx; x++) {
            ll cur = 0;
            for (int i = 1; i <= ceil(mx, x); i++) {
                // sum [i * x, (i + 1) * x - 1]

                int need = sum[min(1ll * MAXN - 1, 1ll * i * x)] -
                           sum[min(1ll * MAXN - 1, 1ll * (i - 1) * x)];
                cur += 1ll * i * need - y * max(0, need - cnt[i]);
            }
            ans = max(cur, ans);
        }
        cout << ans << '\n';
    }
}