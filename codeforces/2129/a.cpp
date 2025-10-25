#include <bits/stdc++.h>
using namespace std;

struct dsu {
        int n;
        vector<int> par, sz;
        
        dsu(int _n) {
                n = _n;
                par.resize(n);
                iota(par.begin(), par.end(), 0);
                sz = vector<int>(n, 1);
        }
        
        int find(int x) {
                if (par[x] == x) return x;
                else return par[x] = find(par[x]);
        }
        
        void merge(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) return;
                if (sz[x] < sz[y]) swap(x, y);
                sz[x] += sz[y];
                par[y] = x;
        }
};

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                dsu uf(2 * n + 2);
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                        int x, y; cin >> x >> y;
                        if (uf.find(x) != uf.find(y)) {
                                ans.push_back(i + 1);
                                uf.merge(x, y);
                        }
                }
                cout << (int) ans.size() << '\n';
                for (int x : ans) cout << x << ' ';
                cout << '\n';
        }
}