#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const ll MOD = 998244353;

vector<ll> cat = {1};
ll catalan(ll n) {
    while (cat.size() <= n) {
        ll res = 0;
        for (int i = 0; i < cat.size(); i++) {
            res = (res + cat[i] * cat[cat.size() - 1 - i] % MOD) % MOD;
        }
        cat.push_back(res);
    }
    return cat[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; n *= 2;
        vector<int> a(n); 
        cout << catalan(n / 2) << ' ';
	    for (int _ = 0; _ < n / 2; _++) {
            int l, r; cin >> l >> r;
            --l; --r;
            a[l] = 1;
            a[r] = -1;

            ll res = 1;
            vector<int> stk;
            stk.push_back(0);

            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    stk.push_back(0);
                } else if (a[i] == -1) {
                    res = res * catalan(stk.back() / 2) % MOD;
                    stk.pop_back();
                } else {
                    stk[stk.size() - 1]++;
                }
            }

	    res = res * catalan(stk.back() / 2) % MOD;
            cout << res << ' ';
        }
        cout << '\n';
    }
}





