#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<char> b(n);
                for (char& c : b) cin >> c;
                int k = sqrt(n);
                if (k * k != n) {
                        cout << "NO\n";
                        continue;
                }
                vector<vector<int>> a(k, vector<int>(k, 0));
                int idx = 0;
                for (auto& x : a) {
                        for (auto &y : x) {
                                y = (b[idx++] == '1');
                        }
                }

                bool works = true;
                for (int j = 0; j < k; j++) {
                        works &= (a[0][j] && a[k - 1][j]);
                }
                for (int i = 1; i < k - 1; i++) {
                        works &= (a[i][0] && a[i][k - 1]);
                }
                for (int i = 1; i < k - 1; i++) {
                        for (int j = 1; j < k - 1; j++) {
                                if (a[i][j]) {
                                        works = false;
                                        break;
                                }
                        }
                }
                cout << (works ? "YES" : "NO") << '\n';
        }
}
