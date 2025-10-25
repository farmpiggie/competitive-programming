#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int n, q; cin >> n >> q;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; i++) {
                int x; cin >> x;
                mp[x]++;
        }

        while (q--) {
                int b; cin >> b;
                int ans = 0;
                for (auto [val, cnt] : mp) {
                        int used = min(b / val, cnt);
                        b -= val * used;
                        ans += used;
                }
                cout << (b == 0 ? ans : -1) << '\n';
        }
}


