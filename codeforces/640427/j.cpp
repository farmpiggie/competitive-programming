#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int MAXN = n;
	vector<int> sieve(MAXN, 0);
	vector<int> primes;
	for (int i = 2; i < MAXN; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i; j < MAXN; j += i) {
				sieve[j] = 1;
			}
		}
	}
	vector<pair<int, int>> ans;
	for (int p : primes) {
		for (int q : primes) {
			int cp_p = p;
			int cp_q = q;
			int sum_digits = 0;
			while (cp_p > 0) {
				sum_digits += (cp_p % 10);
				cp_p /= 10;
			}
			int product_digits = 1;
			while (cp_q > 0) {
				product_digits *= (cp_q % 10);
				cp_q /= 10;
			}
			if (sum_digits == product_digits) {
				ans.push_back(make_pair(p, q));
			}
		}
	}
	cout << (int) ans.size() << '\n';
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}
	
