#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string s; cin >> s;
                int n = stoi(s);
                pair<int, int> ans = {-1, -1};
                for (int a = 0; a <= 100; a++) {
                        for (int b = 0; b <= 100; b++) {
                                if (n == (a + b) * (a + b)) {
                                        ans = {a, b};
                                        break;
                                }
                        }
                }
                if (ans.first == -1) cout << "-1\n";
                else cout << ans.first << " " << ans.second << '\n';
        }
}