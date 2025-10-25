#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<char> a(n);
                for (char &x : a) cin >> x;
                int ans = 0;
                for (int i = 0; i < n; i++) {
                        if (a[i] == '0') continue;
                        bool has_one = false;
                        for (int j = 1; j < k; j++) {
                                if (i - j < 0) continue;
                                if (a[i - j] == '1') {
                                        has_one = true;
                                        break;
                                }
                        }
                        if (!has_one) ans++;
                }
                cout << ans << '\n';
        }
}
                                


