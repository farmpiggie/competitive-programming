#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        ll sum = 0;
        for (int j = 0; j < n; j++) {
            sum += max(a[0][j], a[1][j]);
        }

        ll ans = LLONG_MIN;
        for (int j = 0; j < n; j++) {
            ans = max(ans, sum - max(a[0][j], a[1][j]) + a[0][j] + a[1][j]);
        }
        cout << ans << '\n';
    }
}
    
