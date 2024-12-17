/*
 * n <= 1e18, k <= 1e5
 * how to compute nth fib # divisible by k?
 * 1 <- G(1, 1) = 1
 * 1 <- G(2, 1) = 2
 * 2 <- G(1, 2), G(3, 1) = 3
 * 3 <- G(1, 3), G(4, 1) = 4
 * 5 <- G(1, 5) = G(5, 1) = 5
 * 8 <- G(1, 8) = G(1, 4) = G(2, 2) = G(6, 1) = 6
 * 13 <- G(1, 13) = G(7, 1) = 7
 *
 * k = 2
 * 1 <- 1
 * 1 <- 1
 * 2 <- 0
 * 3 <- 1 // repeat x = 4
 * 5 <- 1 
 * 8
 * 13
 *
 * k = 3
 * 1 <- 1
 * 1 <- 1
 * 2 <- 2
 * 3 <- 0
 * 5 <- 2
 * 8 <- 2
 * 13 <- 1
 * 21 <- 0
 * 34 <- 1 // repeat x = 9
 * 55 <- 1 
 * 
 * k = 4
 * 1 <- 1
 * 1 <- 1
 * 2 <- 2
 * 3 <- 3
 * 5 <- 1
 * 8 <- 0
 * 13 <- 1 // repeat x = 7
 * 21 <- 1 
 *
 * k = 5
 * 1 <- 1
 * 1 <- 1
 * 2 <- 2
 * 3 <- 3
 * 0
 * 3
 * 3
 * 1
 * 4
 * 0
 * 4
 * 4
 * 3
 * 2
 * 0
 * 2
 * 2
 * 4
 * 1
 * 0
 * 1 // repeat at x = 21?
 *
 *
 * rem[i] = f(i) % k
 * rem[i] = (rem[i - 1] + rem[i]) % k;
 *
 * we can use fast exp to calculate nth fib # in O(log(n)) time.
 * 
 * f[i + 3] - f[i] = 2 * f[i + 1]
 * (rem[i + 3] - rem[i] + k) % k == (2 * rem[i + 1]) % k
 * (rem[i + 3]) % k == (2 * rem[i + 1] + rem[i]) % k
 * rem[i] % k == (2 * rem[i - 2] + rem[i - 3]) % k
 * perhaps there is some cyclical relationships between this?
 *
 * once f(i) % k == 0 && f(i + 1) % k == 1, then we get a repeat.
 * seems like it repeats once every k^2 numbers. this upper bound is a bit too slow for us.
 *
 * if f(i) % k == 0 && f(i + 1) % k == 1,
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;

		if (k == 1) {
			cout << (n % MOD) << '\n';
			continue;
		}

		vector<ll> pos;
		ll i = 1;
		ll prev = 1, curr = 1;
		while (!(prev == 0 && curr == 1)) {
			ll temp = curr;
			curr = (curr + prev) % k;
			prev = temp;
			i++;
			if (prev == 0) {
				pos.push_back(i);
			}
		}
		// breaks when f(i) % k == 0 && f(i + 1) % k == 1
		ll sz = pos.size();
		ll val = ((((((n - 1) / sz) % MOD) * i) % MOD) + pos[(n - 1) % sz]) % MOD;   
		cout << val << '\n';
	}
	return 0;
}
