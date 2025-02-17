#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                bool works = false;
                for (int i = 1; i < n; i++) {
                        int x= a[i - 1], y = a[i];
                        if (x > y) swap(x, y);
                        if (2 * x > y) works = true;
                }
                cout << (works ? "YES" : "NO") << '\n';
        }
}
