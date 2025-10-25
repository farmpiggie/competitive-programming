#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n), b(n);
                for (int &x : a) cin >> x;
                for (int &x : b) cin >> x;

                vector<pair<int, int>> segments;

                ll ans = 0;
                for (int i = 0; i < n; i++) {
                        segments.push_back({min(a[i], b[i]), max(a[i], b[i])});
                        ans += abs(a[i] - b[i]);
                }

                bool overlap = false;
                ll mn = 2e9;
                sort(segments.begin(), segments.end());
                for (int i = 1; i < n; i++) {
                        auto [a, b] = segments[i - 1];
                        auto [c, d] = segments[i];
                        if (b >= c) {
                                overlap = true;
                                break;
                        } else {
                                mn = min(mn, 1ll * 2 * (c - b));
                        }
                }
                cout << ans + (overlap ? 0 : mn) << '\n';
        }
}





                        
