#include <bits/stdc++.h>
using namespace std;

#define ll long long

// cnt(x) = # of numbers with a factor of 2, 3, 5, or 7
ll cnt(ll x) {
        return x / 2 + x / 3 + x / 5 + x / 7 - x / 6 - x / 10 - x / 14 - x / 15 - x / 21 - x / 35 + x / 30 + x / 42 + x / 70 + x / 105 - x / 210;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll l, r; cin >> l >> r;
                cout << (r - cnt(r)) - (l - 1 - cnt(l - 1)) << '\n';
        }
}

