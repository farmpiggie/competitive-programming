#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 6000000;

int main() {
	vector<bool> sieve(MAXN);
	vector<int> primes;
	for (int i = 2; i < MAXN; i++) {
		if (sieve[i]) continue;
		primes.push_back(i);
		for (int j = i; j < MAXN; j += i) {
			sieve[j] = 1;
		}
	}
	vector<ll> psum(primes.size(), 0);
	for (int i = 0; i < (int) primes.size(); i++) {
		psum[i] = (i ? psum[i - 1] : 0) + primes[i];
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);

		for (int &x : a) {
			cin >> x;
		}

		sort(a.rbegin(), a.rend());
		int ans = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (sum >= psum[i]) {
				ans = i + 1;	
			}
		}
		cout << n - ans << '\n';
	}
}



