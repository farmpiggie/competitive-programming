#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        if (m >= 2 * n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ((i + j) % (2 * n)) / 2 + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
        
