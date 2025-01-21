/*
 * each monster has a color (light or dark) and power level
 * if same color of monster, we would rather use the lowest color monster of a different color.
 * if not possible, we use the lowest color monster of diff color?
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<array<int, 2>> a(n), b(n); // my monsters, opposing monsters
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i][0] >> b[i][1];
        }
        // create edges between the two values
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][1] == b[j][1] && a[i][0] * 2 >= b[j][0]) g[i].push_back(j);
                if (a[i][1] != b[j][1] && a[i][0] >= b[j][0]) g[i].push_back(j);
            }
        }

        vector<int> mt;
        vector<bool> used;
        vector<bool> used1(n, false);
        mt.assign(n, -1);

        auto try_kuhn = [&](auto self, int v) -> bool {
            if (used[v]) return false;
            used[v] = true;
            for (int to : g[v]) {
                if (mt[to] == -1 || self(self, mt[to])) {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        };

        for (int v = 0; v < n; v++) {
            for (int to : g[v]) {
                if (mt[to] == -1) {
                    mt[to] = v;
                    used1[v] = true;
                    break;
                }
            }
        }

        for (int v = 0; v < n; v++) {
            if (used1[v]) continue;
            used.assign(n, false);
            try_kuhn(try_kuhn, v);
        }
        
        bool works = true; 
        for (int i = 0; i < n; i++) {
            if (mt[i] == -1) {
                works = false;
                break;
            }
        }
        cout << (works ? "YES" : "NO") << '\n';
    }
}
            


        

