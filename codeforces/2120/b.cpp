#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, s; cin >> n >> s;
                int ans = 0;
                for (int i = 0; i < n; i++) {
                        int dx, dy, x, y;
                        cin >> dx >> dy >> x >> y;
                        if ((x == y && dx == dy) || (x + y == s && dx == -1 * dy)) {
                                ans++;
                        }
                }
                cout << ans << '\n';
        }
}