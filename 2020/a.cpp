#include <bits/stdc++.h>
using namespace std;

// 130, 5
// 5^3 + 5^1
// 130 / 5 = 26, equals 25 + 1

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		if (k == 1) {
			cout << n << '\n';
			continue;
		}

		vector<ll> multiples;
		for (ll i = 1; i <= 1e9; i *= k) { // at most log2(1e9) = 30? ish
			multiples.push_back(i);
		}

		// for (ll num : multiples) cout << num << " ";
		// cout << endl;

		ll ans = 0;
		ll divisors = n / k;
		while (divisors > 0) {
			auto it = upper_bound(multiples.begin(), multiples.end(), divisors); // first number > divisors
			--it; // first number <= divisors
			ll divides = divisors / (*it);
			divisors -= (divides * (*it));
			ans += divides;
		}
		ans += (n % k);
		cout << ans << endl;

	}
	return 0;
}