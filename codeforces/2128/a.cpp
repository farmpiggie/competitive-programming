#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, c; cin >> n >> c;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                sort(a.rbegin(), a.rend());
                int ans = n;
                int mult = 1;
                for (int x : a) {
                        if (x * mult <= c) {
                                ans--;
                                mult *= 2;
                        }
                }
                cout << ans << '\n';
        }
}

