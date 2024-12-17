#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 200005;
const ll MOD = 1000000007;
ll fact[MAXN];

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
	// precompute factorial
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m1, m2;
		cin >> n >> m1 >> m2;
		vector<int> p(m1), s(m2);
		for (int& x : p) cin >> x;
		for (int& x : s) cin >> x;
		
		if (p[0] != 1 || s[m2 - 1] != n || p[m1 - 1] != s[0]) {
			cout << "0\n";
			continue;
		}

		ll ways = nCk(n - 1, p[m1 - 1] - 1, MOD);

		ll left = 1;
		for (int i = m1 - 2; i >= 0; i--) {
			left = (((left * nCk(p[i + 1] - 2, p[i + 1] - p[i] - 1, MOD)) % MOD) * fact[p[i + 1] - p[i] - 1]) % MOD;
		}
		ll right = 1;
		for (int i = 1; i < m2; i++) {
			right = (((right * nCk(n - s[i - 1] - 1, s[i] - s[i - 1] - 1, MOD)) % MOD) * fact[s[i] - s[i - 1] - 1]) % MOD;
		}
		ways = (ways * left) % MOD;
		ways = (ways * right) % MOD;
		cout << ways << '\n';
	}
	return 0;
}
