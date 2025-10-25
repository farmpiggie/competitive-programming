// n, 0
// floor(n / 2) + 1, floor(n / 2)
//
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int wins = 0, loss = 0;
                cin >> wins;
                int ans = 0;
                while (wins > 1 || loss > 1) {
                        int move = wins / 2;
                        ans += wins / 2;
                        wins -= move;
                        if (loss > 1) {
                                ans += loss / 2;
                                loss = (loss + 1) / 2;
                        }
                        loss += move;
                }
                // wins = 1, loss = 1
                ans++;
                cout << ans << '\n';
        }
}