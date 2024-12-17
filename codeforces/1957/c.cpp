// everytime you place a rook, you block out one row and one column
// the computer will also then block out one row or column
	// but if you place a rook on (r, r), this doesn't happen

// first movement, depending on the moves made, you have (num_remaining_rows * num_remaining_columns) to choose from
// if you choose a non-diagonal, now you have (num_remaining_rows - 2) * (num_remaining_columns - 2) to choose from
// if u choose a diagonal, your next choice is (num_rows - 1) * (num_columns - 1)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXFAC = 300005;
const int MOD = 1000000007;
// MATH UTILITY
ll fact[MAXFAC];

ll mygcd(ll a, ll b) {
    if (a == 0)
        return b;
    return mygcd(b % a, a);
}

// a ^ b mod p
ll powmod(ll a, ll b, ll p){
    if (b == 0) return 1;
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

// modular inverse
ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < MAXFAC; i++) fact[i] = (fact[i - 1] * i) % MOD;

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int lanes = n;
		for (int i = 0; i < k; i++) {
			int r, c; cin >> r >> c;
			if (r == c) lanes--;
			else lanes -= 2;
		}
		ll ans = 0;
		for (int i = 0; i <= lanes; i++) {
			if ((lanes - i) % 2 == 0) {
				ll cur = (nCk(lanes, i, MOD) * fact[(lanes - i)]) % MOD;
				cur = (cur * inv(fact[(lanes - i) / 2], MOD)) % MOD;
				//cout << cur << '\n';
				ans = (ans + cur) % MOD;
			}
		}
		cout << ans << '\n';

	}
	return 0;
}
