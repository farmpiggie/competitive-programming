#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll x, y; cin >> x >> y;
        vector<int> a(n);

        ll sum = 0;
        for (int& x : a) {
            cin >> x;
            sum += x;
        }
        sort(a.begin(), a.end());
        
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            // sum - a[i] - a[j] < x
            int l = 0, r = i - 1;
            int ans1 = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (sum - a[i] - a[m] >= x) {
                    ans1 = max(ans1, m);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            l = 0, r = i - 1;
            int ans2 = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (sum - a[i] - a[m] > y) {
                    ans2 = max(ans2, m);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans += ans1 - ans2;
        }
        cout << ans << '\n';
    }
}
