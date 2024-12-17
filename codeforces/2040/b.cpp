#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 1;
        int cur = 1;
        while (cur < n) {
            cur = (cur + 1) * 2;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
