#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }

        for (int x : a)
            s.erase(x);

        if (s.size() == 0) { // a is permutation
            for (int i = 0; i < k; i++)
                cout << a[i] << ' ';
            cout << '\n';
        } else {
            cout << *s.begin() << ' ';
            if (k == 1) {
                cout << '\n';
                continue;
            }

            set<int> s2;
            for (int i = 1; i <= n; i++) {
                if (i != *s.begin() && i != a.back()) {
                    s2.insert(i);
                }
            }
            // between size 0 or n - 2.
            if (s2.size() > 0) {
                cout << *s2.begin() << ' ';
                s2.erase(s2.begin());
                s2.insert(a.back()); // we can use it again
            } else {                 // have to use it
                cout << a.back() << ' ';
            }
            vector<int> c(s2.begin(), s2.end());
            for (int i = 0; i < k - 2; i++) {
                cout << c[i] << ' ';
            }
            cout << '\n';
        }
    }
}