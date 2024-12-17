#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        ll sum = 0;
        ll ans = LLONG_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (i < m) {
                ans = min(ans, sum + a[i]);
            } 
            sum += min(a[i], b[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
