#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> #
using namespace __gnu_pbds;
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define MOD 998244353
#define MAXFAC 2000005



int t, c[4];
ll fact[MAXFAC];

ll powmod(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}


// (zero_indexed) order goes like (3s) 0 (2s) 1 (3s) 0 (2s) ....

int main() {
    fact[0] = 1;
    for (int i = 1; i < MAXFAC; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

	send help
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++) {
            cin >> c[i];
        }
        if (abs(c[0] + c[1]) == 0) { // no 0s or 1s, valid can only have 2s or 3s (not both)
            if (c[2] == 0 || c[3] == 0) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
            continue;
        } 
        if (abs(c[0] - c[1]) > 1) { // diff betweens 0s and 1s is > 1
            cout << "0\n";
            continue;
        }

        ll ans = 0;
        
        if (c[0] != c[1]) { // more 0s than 1s
            int k = (c[0] + c[1] + 1) / 2;
            ll two_combos = nCk(c[2] + k - 1, k - 1, MOD);
            ll three_combos = nCk(c[3] + k - 1, k - 1, MOD);
            ans += (two_combos * three_combos) % MOD;
        } else {   // same # of 0s and 1s
            // start with 0
            int k = (c[0] + c[1] + 1) / 2;
            ll two_combos = nCk(c[2] + k, k, MOD);
            ll three_combos = nCk(c[3] + k - 1, k - 1, MOD);
            ans += (two_combos * three_combos) % MOD;
            two_combos = nCk(c[2] + k - 1, k - 1, MOD);
            three_combos = nCk(c[3] + k, k, MOD);
            ans = (ans + (two_combos * three_combos) % MOD) % MOD;
        }
        cout << ans << '\n';

    }
	return 0;
}