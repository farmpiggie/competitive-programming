#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while (t--) {
        int n, c; cin >> n >> c;
        vector<int> s(n);
        for (int& x : s) cin >> x;
        int even = 0, odd = 0;

        ll ans = 0;
        for (int& x : s) {
            ans += (x / 2 + 1) + (c + 1 - x);

            if (x % 2 == 0) even++;
            else odd++;

            if (x % 2 == 0) ans -= even;
            else ans -= odd;

            
        }
        cout << (1ll * c * (c + 1) / 2 + c + 1) - ans << '\n';
    }
}
