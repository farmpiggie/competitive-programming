#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m; cin >> n >> m;
                vector<vector<int>> a(n, vector<int>(m, 0));
                for (auto &x : a) {
                        for (int &y : x) {
                                cin >> y;
                        }
                }

                ll sum = 0;
                vector<ll> b;
                for (int i = 0; i < n; i++) {
                        ll cur = 0;
                        for (int j = 0; j < m; j++) {
                                sum += 1ll * a[i][j] * (m - j);
                                cur += a[i][j];
                        }
                        b.push_back(cur);
                }
                sort(b.rbegin(), b.rend());
                // 5 4 3 2 1 
                // 10 9 8 7 6
                for (int i = 0; i < n - 1; i++) {
                        sum += 1ll * b[i] * m * (n - 1 - i);
                }
                cout << sum << '\n';
        }
}

                
