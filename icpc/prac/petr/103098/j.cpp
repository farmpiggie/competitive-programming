/*
 * perfect squares ending in 25
 * 225, 625, etc
 * f(k) = kth perfect #
 * f(1) = 2, f(2) = 6, f(3) = 12, f(4) = 20
 *
 * n^2 + n
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 31665; // sqrt(1e9)

int sieve[MAXN] = {0};
vector<int> primes;
int main() {
	for (int i = 2; i < MAXN; i++) {
		if (sieve[i] != 0) continue;
		sieve[i] = i;
		primes.push_back(i);
		for (int j = 2 * i; j < MAXN; j += i) {
			if (sieve[j] != 0) continue;
			sieve[j] = i;
		}
	}


	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		
		set<int> ans;
		// factorize k
		int temp = k;
		for (int p : primes) {
			while (temp % p == 0) {
				temp /= p;
				ans.insert(p);
			}
		}
		if (temp != 1) ans.insert(temp);
		temp = k + 1;
		for (int p : primes) {
			while (temp % p == 0) {
				temp /= p;
				ans.insert(p);
			}
		}
		if (temp != 1) ans.insert(temp);
	
		cout << ans.size() << '\n';
	}
}
			




