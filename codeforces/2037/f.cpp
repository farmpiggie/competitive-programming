/*
i guess the # of distinct positions you can try is bounded by: 
1e5 ^ (4/3) = 4.6 * 10^6 * log2(1e9) = 1.33 * 10^8 
which could work?

maybe for each position, we run binary search?
but this is also non-trivial

for every position: we basically shift binary search for each element
we have some segtree where

idea 2: binary search on answer.
can we easily shift through all positions??
for each shift, we add/subtract at most some set of values? but they change a lot so idk if we can support this update quickly

what if we create "intervals" for each position.
basically an interval for a position is the inclusive range in which we can put xilonen at for each "attack level" to guarantee that this particular place gets destroyed.

at each point, we can "gain" or "lose" particular attacks.
binary search: idea is that we have (x) attacks, we can use any interval from (1...x). 

we can bin search on answer! 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

int main() {
	ll t; cin >> t;
	while (t--) {
		ll n, m, k; cin >> n >> m >> k;	
		vector<ll> h(n), x(n);
		for (ll& y : h) cin >> y;
		for (ll& y : x) cin >> y;
		
		// given index of element, find positions that work. 
		auto find_pos = [&](ll i, ll power) -> pll {
			ll pos = x[i], health = h[i];
			ll diff = m - (h[i] / power + (h[i] % power != 0)); 
			if (diff < 0) return make_pair(-1ll, -1ll); 
			else return {pos - diff, pos + diff + 1}; // exclusive second element
		};

		ll lo = 1, hi = 1e9; // attacks
		ll ans = LLONG_MAX;
		while (lo <= hi) {
			ll mi = (lo + hi) / 2;
			vector<pll> a;
			for (int i = 0; i < n; i++) {
				pll range = find_pos(i, mi);
				if (range != make_pair(-1ll, -1ll)){
					a.push_back({range.first, 1});
					a.push_back({range.second, 0});
				}
			}
			sort(a.begin(), a.end());
			ll cur = 0;
			ll best = 0;
			for (const pll& p : a) {
				cur += (p.second ? 1 : -1);
				best = max(best, cur);
			}
			if (best >= k) {
				hi = mi - 1;
				ans = min(ans, mi);
			} else {
				lo = mi + 1;
			}
		}
		
		cout << ((ans == LLONG_MAX) ? -1 : ans) << '\n';
	}
	return 0;
}
