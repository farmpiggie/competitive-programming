#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m; cin >> n >> m;
                vector<int> a(n), b(m);
                for (int &x : a) cin >> x;
                for (int &x : b) cin >> x;

                sort(b.begin(), b.end());

                for (int x : b) {
                        a[0] = min(a[0], x - a[0]);
                }
                
                bool works = true;
                for (int i = 1; i < n; i++) {
                        // search for smallest b[j] s.t. b[j] - a[i] >= a[i - 1]
                        int l = 0, r = m - 1;
                        while (l < r) {
                                int m = (l + r) / 2;
                                if (b[m] - a[i] >= a[i - 1]) {
                                        r = m;
                                } else {
                                        l = m + 1;
                                }
                        }
                        if (b[r] - a[i] < a[i - 1] && a[i] < a[i - 1]) { // not satisfiable
                                works = false;
                                break;
                        }
                        int prev = a[i];
                        if (b[r] - a[i] >= a[i - 1]) {
                                a[i] = b[r] - a[i];
                        }
                        if (prev >= a[i - 1]) {
                                a[i] = min(a[i], prev);
                        }
                }

                cout << (works ? "YES" : "NO") << '\n';
        }
}

