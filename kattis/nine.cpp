#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

// calculates a ^ b quickly
// for mod exponentiation simply pass in a third parameter, m (mod), 
// and then mod after every time you multiply
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD; // for mod exponentiation add a mod m here
        a = (a * a) % MOD; // for mod exponentiation add a mod m here
        b >>= 1;
    }
    return res;
}

void run() {
	ll n; cin >> n;
	// first
	cout << (8 * binpow(9, n - 1)) % MOD << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) run();
	return 0;
}