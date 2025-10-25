#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n, 0);
        int val = 1;
        for (int i = k - 1; i < n; i += k) {
            a[i] = val;
            val++;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                a[i] = val;
                val++;
            }
        }
        for (int x : a) cout << x << " ";
        cout << '\n';
    }
    return 0;
}
