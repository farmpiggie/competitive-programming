#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll a, b, m; cin >> a >> b >> m;
        cout << (m / a + 1) + (m / b + 1) << '\n';
    }
    return 0;
}
