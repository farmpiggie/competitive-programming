#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> a(m);
        vector<vector<int>> b(n, vector<int>(m, 0));
        vector<int> sz(n, 0);
        // [x, y)
        int j = 0;
        for (auto &[x, y] : a) {
            cin >> x >> y;
            --x;
            for (int i = x; i < y; i++) {
                b[i][j] = 1;
                sz[i]++;
            }
            j++;
        }

        int max_overlap = 0;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if ((int)sz[i] > max_overlap) {
                max_overlap = sz[i];
                idx = i;
            }
        }
        if (max_overlap == m) {
            int cur = 1;
            for (int i = 0; i < n; i++) {
                if (idx != i) {
                    cout << cur << ' ';
                    cur++;
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << '\n';
        } else {
            bool works = false;
            vector<int> c(n, -1);
            // anchor 0 at i.
            for (int i = 0; i < n; i++) {
                if (i + 1 < n) {
                    bool contains = true;
                    for (int j = 0; j < m; j++) {
                        if (b[i][j] && !b[i + 1][j]) {
                            contains = false;
                            break;
                        }
                    }
                    if (contains) {
                        c[i] = 0;
                        c[i + 1] = 1;
                        works = true;
                        break;
                    }
                }
                if (i - 1 >= 0) {
                    bool contains = true;
                    for (int j = 0; j < m; j++) {
                        if (b[i][j] && !b[i - 1][j]) {
                            contains = false;
                            break;
                        }
                    }
                    if (contains) {
                        c[i] = 0;
                        c[i - 1] = 1;
                        works = true;
                        break;
                    }
                }
            }
            if (works) {
                int cur = 2;
                for (int i = 0; i < n; i++) {
                    if (c[i] == -1)
                        c[i] = cur++;
                }
            } else {
                c[0] = 0;
                c[1] = 2;
                c[2] = 1;
                for (int i = 3; i < n; i++)
                    c[i] = i;
            }
            for (int x : c)
                cout << x << ' ';
            cout << '\n';
        }
    }
}