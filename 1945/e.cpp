#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        int target;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == x) target = i;
        }
        int l = 0, r = n, m = 0;
        while (l + 1 < r) {
            m = (l + r) / 2;
            if (a[m] <= x) l = m;
            else r = m;
        }
        cout << "1\n" << l + 1 << " " << target + 1 << '\n';
        
        // test
    }
    return 0;
}
