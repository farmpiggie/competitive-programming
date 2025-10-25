#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b, c; cin >> n >> a >> b >> c;
        int sum = a + b + c;
        int ans = n / sum * 3;
        n %= sum;
        if (n > 0) ans++;
        if (n > a) ans++;
        if (n > a + b) ans++;
        cout << ans << '\n';
    }
    return 0;
}
