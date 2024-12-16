#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        bool can = true;
        int cur = 0, num = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            if (!can) continue;
            if (cur + s.length() <= m) {
                cur += s.length();
                num++;
            } else {
                can = false;
            }
        }
        cout << num << '\n';
    }
    return 0;
}
