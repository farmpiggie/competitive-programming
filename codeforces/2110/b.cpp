#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string s; cin >> s;
                int n = (int) s.length();
                int cnt = 1;
                bool possible = false;
                for (int i = 1; i < n; i++) {
                        if (s[i] == '(') cnt++;
                        else cnt--;
                        if (cnt == 0 && i != n - 1) {
                                possible = true;
                        }
                }

                cout << (possible ? "YES" : "NO") << '\n';
        }
}
