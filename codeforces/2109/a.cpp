#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                bool works = true;
                bool has_zero = false;
                for (int i = 1; i < n; i++) {
                        if (a[i - 1] == 0 && a[i] == 0) {
                                works = false;
                                break;
                        }
                        if (a[i - 1] == 0 || a[i] == 0) {
                                has_zero = true;
                        }
                }
                if (!has_zero) works = false;

                cout << ((works) ? "NO" : "YES") << '\n';
        }
}

                
