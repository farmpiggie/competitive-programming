#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, q; cin >> n >> q;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                vector<array<int, 3>> b(q);
                for (auto &[x, y, z] : b) {
                        cin >> x >> y >> z;
                        --x; --y; --z;
                }

                vector<int> c = a;
                for (int i = q - 1; i >= 0; i--) {
                        int v = c[b[i][2]];
                        c[b[i][2]] = 0;

                        c[b[i][0]] = max(c[b[i][0]], v);
                        c[b[i][1]] = max(c[b[i][1]], v);
                }

                vector<int> d = c;
                for (int i = 0; i < q; i++) {
                        d[b[i][2]] = min(d[b[i][0]], d[b[i][1]]);
                }

                bool works = true;

                for (int i = 0; i < n; i++) {
                        if (a[i] != d[i]) {
                                works = false;
                                break;
                        }
                }

                if (works) {
                        for (int &x : c) cout << x << " ";
                        cout << '\n';
                } else cout << "-1\n";
        }
}





