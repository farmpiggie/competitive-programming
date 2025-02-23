#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int x, y;
        for (int i = 0; i < n; i++) {
                if (a[i] == 1) x = i;
                else if (a[i] == n) y = i;
        }

        cout << max(x, max(n - 1 - x, max(y, n - 1 - y))) << '\n';
}
