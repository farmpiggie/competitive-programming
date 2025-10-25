#include <bits/stdc++.h>
using namespace std;

// for any given n and a, the max distance bewteen any two working batteries is (n + 1) / a.
// go through all of these?
//
int ask(int u, int v) {
        cout << u << " " << v << endl;
        int x; cin >> x;
        return x;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                auto solve = [&]() {
                        for (int diff = 1; diff <= n; diff++) {
                                for (int i = 1; i + diff <= n; i++) {
                                        if (ask(i, i + diff) == 1) return;
                                }
                        }
                };
                solve();
        }
        return 0;
}



