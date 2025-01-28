#include <bits/stdc++.h>
using namespace std;



int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        auto is_square = [&](int x) {
            for (int i = 1; i * i <= x; i+= 2) {
                if (i * i == x) return true;
            }
            return false;
        };
        
        int sum = 0;
        int ans = 0;
        for (int x : a) {
            sum += x;
            if (is_square(sum)) ans++;
        }
        cout << ans << '\n';
    }
}
