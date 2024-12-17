#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool can = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (abs(a[i] - a[j]) % k == 0) {
                    can = false;
                    break;
                }
            }
            if (can) {
                ans = i;
                break;
            }
        }
        if (ans == -1) cout << "NO\n";
        else cout << "YES\n" << ans + 1 << '\n';
    }
    return 0;
}
