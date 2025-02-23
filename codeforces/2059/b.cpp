/*
 * we can choose the start of our series from a[1].....a[n - 1 - (k - 2)].
 * if any of these values don't equal 1, we can just win here.
 * otherwise, they all equal 1.
 * if we have more than 1 position to pick, we can pick a subarray with [1, 1] and insta win.
 * otherwise, we pick the only position (1) and continue onwards.
 *
 * the only time we only have one position to pick is if n = k.
 * so we can special case this.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                
                if (n == k) {
                        int cur = 0;
                        int ans = k / 2 + 1;
                        for (int i = 1; i < n; i += 2) {
                                if (cur + 1 == a[i]) {
                                        cur++;
                                } else {
                                        ans = cur + 1;
                                        break;
                                }
                        }
                        cout << ans << '\n';
                } else {
                        set<int> s;
                        for (int i = 1; i < n - (k - 2); i++) {
                                s.insert(a[i]);
                        }
                        if (s.size() == 1 && *s.begin() == 1) {
                                cout << "2\n";
                        } else {
                                cout << "1\n";
                        }
                }
        }
}


