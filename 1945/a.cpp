#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;

        int extra = (3 - (b % 3)) % 3;

        if (extra > c) {
            cout << "-1\n";
            continue;
        }

        cout << a + b / 3 + (b % 3 ? 1 : 0) + (c - extra) / 3 + ((c - extra) % 3 ? 1 : 0) << '\n';
    }
    return 0;
}
