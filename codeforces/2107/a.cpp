#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                vector<int> ans(n);
                int mx = 0;
                set<int> unique;
                for (int &x : a) {
                        cin >> x;
                        mx = max(x, mx);
                        unique.insert(x);
                }
                if (unique.size() == 1) {
                        cout << "NO\n"; 
                        continue;
                }
                cout << "YES\n";
                for (int i = 0; i < n; i++) {
                        if (a[i] == mx) cout << "2 ";
                        else cout << "1 ";
                }
                cout << '\n';
        }
}
