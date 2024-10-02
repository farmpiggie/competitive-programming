/*
minimize: gcd(a1) + gcd(a1, a2) ... + gcd(a_1, a_2, ..., a_n)

note that a_i <= 1e5
gcd(a1) <= gcd(a1, a2) <= gcd(a1, a2, a3) ...
lower bound: gcd(a_1, a_2, ..., a_n) * (n - 1) + min(a_i)


can we greedily construct from the end?
choose largest # to remove s.t. gcd(a_1, a_2, ..., a_n) is minimized
this greedy algo will basically try to find coprimes, not sure if this is optimal


if we anchor the first starting value, can we choose an optimal second number?
say we choose our starting value as x
next value is y s.t. gcd(x, y) is minimized.
this should always be optimal, since we create a lower upper bound
finding this number is pretty hard... even if we could do this in O(1) somehow, this would take O(n^2)

can we use the fact that a_i <= 1e5 somehow?
we can generate all the factors of n <= 1e5 if we want to
we can use n^(1/3) for # of factors ~= 46??
seems like we might be able to do n * (# factors)^2



does it make sense to ever take y > min(a_x) first?
assume that optimal solution starts with y s.t. y > min(a_x)
ans = y + gcd(x, y) + gcd(x, y, z) + gcd(x, y, z, ...)

if (x, y) in a are coprime, we can do:
x, y, ....
which gives us x + 1 * (n - 1)


editorial:
!-- interesting trick?
if we divide all numbers by gcd(a_i), then gcd(a_1, a_2..., a_n) is now 1
therefore there must be two numbers that must be coprime. if no two numbers are coprime, then the gcd cannot be 1


> say we choose our starting value as x
> next value is y s.t. gcd(x, y) is minimized.
> this should always be optimal, since we create a lower upper bound
ok looks like my idea that choosing next value s.t. gcd(x, y) is minimized is correct.

> finding this number is pretty hard... even if we could do this in O(1) somehow, this would take O(n^2)
looks like we can prove that we dont need to take n^2 comparisons
gcd(x, y) decreases by at least 2 every time
therefore we can prove that gcd(x, y) -> 1 in around log2(1e5) operations ~= 16

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		ll _gcd = a[0];
		for (ll& x : a) _gcd = gcd(_gcd, x);
		for (ll& x : a) x /= _gcd;

		ll cur = 0;
		ll ans = 0;
		for (int t = 0; t < n; t++) {
			ll nc = 1e9;
			for (int i = 0; i < n; i++) {
				nc = min(nc, gcd(cur, a[i]));
			}
			cur = nc;
			ans += cur;
			if (cur == 1) {
				ans += n - t - 1;
				break;
			}
		}
		cout << ans * _gcd << endl;

	}
	return 0;
}