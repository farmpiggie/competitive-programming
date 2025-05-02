/*
 * sol for d1:
 * notice that after the first n terms, every two next elements in the series are equal.
 * so notice that the xth element = xor(a_1 through a_n) xor s_(x / 2) if (x / 2 - n) is odd.
 * for n = 5, s_15 = xor(a_1 through a_5) xor s_6 xor s_7
 * for n = 6, s_16 = xor(a_1 thorugh a_5) xor s_6 xor s_7 xor s_8, which is xor(a_1 through a_5) xor s_8
 * if (x / 2 <= n) we calculate directly
 *
 * for d2:
 * notice how after a_2n, the numbers follow a pattern: (define p as xor(a[1]...a[n])
 * also bump up (m % 4) == 1 for simplicity
 *
 * a_(2n) = a_(2n + 1) = p
 * a_(2n + 2) = a_(2n + 3) = p ^ a_(n + 1)
 * a_(2n + 4) = a_(2n + 5) = p
 * a_(2n + 6) = a_(2n + 7) = p ^ a_(n + 3)
 * ...
 * a_(m - 1) = a_m = p ^ a_(m / 2)
 *
 * define e = sum(a_(n + 1) + a_(n + 3) + ... + a_(m / 2))
 *          = even_sum(m / 2) - even_prefix(n)
 *
 * note the sums of even and odd indices are equal, depending on p:
 * sum of odd/even indices n < i <= m / 2 is:
 * both:
 *	e			if p = 0
 *	(m / 2 - n + 1)	- e	if p = 1
 * 
 * to add everything up:
 * even_sum(m) = even_prefix(2 * n - 1) + both
 * odd_sum(m) = even_prefix(2 * n - 1) + both
 *
 * so:
 * if n is even, add one entry to make it odd
 * precalculate a_1 through a_(2n - 1), and precalculate even and odd prefix sums
 *
 * even_sum(m):
 *	if (m % 4) != 1, increment to m until it is.
 *	ans = 0
 *
 *	if (m / 2 <= 2 * n - 1)
 *		ans = prefix_even(m / 2)
 *	else
 *		e = even_sum(m / 2) - prefix_even(n) 
 *		if p is 0:
 *			both = e
 *		else:
 *			both = (m / 2 - n + 1) - e
 *		ans = prefix_even(2 * n - 1) + both
 *
 *	adjust ans based on how much I incremented m (we can call our existing d1 solution to get a[m / 2])
 *
 * sum(m):
 *	if (m <= 2 * n - 1) return even_prefix[m] + odd_prefix[m];
 *
 *	x = even_sum(m)
 *	both = x - prefix[2 * n - 1]
 *	return x + prefix_odd[2 * n - 1] + both
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;
		ll l, r; 
		cin >> n >> l >> r;
		
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<int> p(n + 1, 0); // xor[i] = xor[a1...ai] (one indexed)
					 //
		for (int i = 1; i <= n; i++) {
			p[i] = a[i] ^ p[i - 1];
		}

		// create even parity
		if (n % 2 == 0) {
			a.push_back(p[n / 2]);
			p.push_back(p.back() ^ p[n / 2]);
			n++;
		}

		// calculate a_(n + 1) up to a_(2 * n - 1)
		int cur = 0;
		for (int i = 1; i <= n / 2; i++) {
			cur ^= a[i];
		}
		for (int i = n + 1; i < 2 * n - 1; i += 2) {
			cur ^= a[i / 2];
			a.push_back(cur); // a[i]
			a.push_back(cur); // a[i + 1]
		}

		// even and odd psums up to (2 * n - 1)
		vector<int> even(2 * n, 0);
		vector<int> odd(2 * n, 0);

		for (int i = 1; i < 2 * n; i++) {
			even[i] = even[i - 1];
			odd[i] = odd[i - 1];
			if (i & 1) odd[i] += a[i];
			else even[i] += a[i];
		}
	
		// return a[x]
		auto find = [&](this auto find, ll x) -> int {
			if (x <= n) {
				return a[x - 1];
			} else if (x / 2 <= n) {
				return p[x / 2];
			} else {
				return p[n] ^ (((x / 2 - n) & 1) ? find(x / 2) : 0);
			}
		};

		// return sum of even elements up to a[m]
		auto even_sum = [&](this auto even_sum, ll m) -> ll {
			//cout << "calling even_sum(" << m << ")" << endl;
			if (m < 2 * n) return even[m];

			ll e = even_sum(m / 2) - even[n];
			ll both;
			if (p[n]) {
				both = (m / 2 - n + 1) - e;
			} else {
				both = e;
			}

			return even[2 * n - 1] + both;
		};

		auto sum = [&](ll m) -> ll {
			//cout << "calling sum(" << m << ")" << endl;
			if (m < 2 * n) return even[m] + odd[m];
			ll orig = m;

			while (m % 4 != 1) {
				m++;
			}

			ll x = even_sum(m);
			ll both = x - even[2 * n - 1];
			ll ans = x + odd[2 * n - 1] + both;

			//cout << "readjusting" << endl;

			while (m > orig) {
				ans -= find(m--);
			}

			return ans;
		};
		
		cout << sum(r) - sum(l - 1) << '\n';
	}
}

