#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                int mx = 0;
                for (int i = 0; i < n; i++) {
                        mx = max(mx, a[i]);
                        if (i % 2 == 1) {
                                a[i] = mx;
                        }
                }


                ll ans = 0;
                for (int i = 1; i < n; i++) {
                        if (i % 2 == 1 && a[i - 1] >= a[i]) { // a[i - 1] should be < a[i]
                                ans += (1ll * a[i - 1] - a[i]) + 1;
                                a[i - 1] = a[i] - 1;
                        } else if (i % 2 == 0 && a[i - 1] <= a[i]) { // should be a[i - 1] > a[i]
                                ans += (1ll * a[i] - a[i - 1]) + 1;
                                a[i] = a[i - 1] - 1;
                        }
                }
                cout << ans << '\n';
        }
}




