#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(m); 
        for (int& x : a) cin >> x;
        set<int> s;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        
        if (k < n - 1) {
            for (int i = 0; i < m; i++) cout << "0";
            cout << '\n';
        } else if (k == n) {
            for (int i = 0; i < m; i++) cout << "1";
            cout << '\n';
        } else {
            for (int x : a) cout << ((s.find(x) == s.end()) ? 1 : 0);
            cout << '\n';
        }
    }
    return 0;
}
