/*
maybe divide the biggest # and multiply the smallest # ?
summation of all #s delta is: 3 * min(ai) - 2/3 * max(ai)

idea: get one number to zero as fast as possible
then simply perform all operations where x = 0
the # we choose to make to zero should be some number at index i,
where it takes i operations to get the # from x to 0. this minimizes how big we can make the i previous numbers before it.

what if this isnt possible?


*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 1;

int main() {
	vector<ll> prefix(MAXN, 0);
	for (int i = 1; i < MAXN; i++) {
		int j = i; 
		while (j > 0) {
			j /= 3;
			prefix[i]++;
		}
		prefix[i] += prefix[i - 1];
	}
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		ll ans = 0;
		int temp = l;
		while (temp > 0) {
			temp /= 3;
			ans += 2;
		}
		ans += prefix[r] - prefix[l];
		cout << ans << '\n';
	}
	return 0;
}