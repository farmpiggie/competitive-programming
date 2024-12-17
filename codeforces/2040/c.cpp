#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; ll k;
        cin >> n >> k;
        if (n < 63 && k > (1ll << (n - 1))) {
            cout << "-1\n";
            continue;
        }
        k--;
        vector<bool> right(n + 1, 0);
        int idx = n - 1;
        while (k > 0 && idx >= 1) {
            if (k & 1) right[idx] = 1;
            k /= 2;
            idx--;
        }
        vector<int> ans(n);
        int l = 0, r = n - 1;
        for (int i = 1; i <= n; i++) {
            if (right[i]) {
                ans[r] = i;
                r--;
            } else {
                ans[l] = i;
                l++;
            }
        }
        for (int& x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
