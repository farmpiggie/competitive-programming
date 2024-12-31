/*
 * sum of submatrix is: ∑_(x, y) (x * n + y + 1) * M(x, y)
 * split into ∑_(x) (x * n * M(x, y)) + ∑_(y) (y * M(x, y)) + ∑ M(x, y)
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define v2l vector<vl>

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        v2l a(n, vl(n, 0));
        for (auto& x : a) for (ll& y : x) cin >> y;
        
        v2l sum(n, vl(n, 0)); // sum[i][j] = ∑a[x][y] for 0 <= x <= i, 0 <= y <= j
        v2l xsum(n, vl(n, 0)); // xsum[i][j] = ∑x * a[x][y]
        v2l ysum(n, vl(n, 0)); // ysum[i][j] = ∑y * a[x][y]
                               
        auto query = [&](int x1, int y1, int x2, int y2, const v2l& arr) {
            ll ans = arr[x2][y2];
            if (x1 - 1 >= 0) ans -= arr[x1 - 1][y2];
            if (y1 - 1 >= 0) ans -= arr[x2][y1 - 1];
            if (x1 - 1 >= 0 && y1 - 1 >= 0) ans += arr[x1 - 1][y1 - 1];
            return ans;
        };

        sum[0][0] = a[0][0];
        for (int i = 1; i < n; i++) {
            sum[i][0] = sum[i - 1][0] + a[i][0];
            xsum[i][0] = xsum[i - 1][0] + i * a[i][0];
            // ysum[i][0] is always zero since y = 0
        }
        for (int j = 1; j < n; j++) {
            sum[0][j] = sum[0][j - 1] + a[0][j];
            ysum[0][j] = ysum[0][j - 1] + j * a[0][j];
            // xsum[0][j] is always zero since x = 0
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                xsum[i][j] = i * a[i][j] + xsum[i - 1][j] + xsum[i][j - 1] - xsum[i - 1][j - 1];
                ysum[i][j] = j * a[i][j] + ysum[i - 1][j] + ysum[i][j - 1] - ysum[i - 1][j - 1];
            }
        }

        while (q--) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            --x1; --y1; --x2; --y2;
            int w = y2 - y1 + 1;
            cout << w * (query(x1, y1, x2, y2, xsum) - query(x1, y1, x2, y2, sum) * x1) + (query(x1, y1, x2, y2, ysum) - query(x1, y1, x2, y2, sum) * y1) + query(x1, y1, x2, y2, sum) << ' ';
        }
        cout << '\n';
        
    }
    return 0;
}

