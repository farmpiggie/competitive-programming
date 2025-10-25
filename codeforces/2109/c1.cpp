#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 1e18;

void digit() {
        cout << "digit" << endl;
        int res; cin >> res;
}

int add(ll x) {
        cout << "add " << x << endl;
        assert(x >= -MAX && x <= MAX);
        int res; cin >> res;
        return res;
}

void check() {
        cout << "!" << endl;
        int res; cin >> res;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n;
                cin >> n;
                for (int i = 0; i < 2; i++) {
                        digit();
                }
                for (int i = 3; i >= 0; i--) {
                        int res = add(-(1 << i));
                }
                // mystery # equals 1
                add(n - 1);
                check();
       }
}




 