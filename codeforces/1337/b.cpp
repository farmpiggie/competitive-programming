#include <bits/stdc++.h>
using namespace std;
int T;
int x, n, m; // hitpoints, void absorption, lightning strikes
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> n >> m;
        while (n > 0 && x > 20) {
            x = (x / 2) + 10;
            n--;
        }
        while (m > 0 && x > 0) {
            x -= 10;
            m--;
        }
        if (x <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}