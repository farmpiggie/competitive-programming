/*
sort a by occurrences
press all buttons a[0] times, gives you (a[0] * tot)
then you need to press empty ones (a[0]->second)



*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
		}

		ll ans = 0;
		ll tot = n;
		ll prev = 0;
		while (k > 0) {
			ll val = tot * (mp.begin()->first - prev); // number of presses i can get now.
			if (val >= k) {
				ans += k; // only need k presses 
				k = 0;
			} else {
				ans += val + (mp.begin()->second); // number of new zeroes
				k -= val; // i get this many cans
			}
			tot -= mp.begin()->second; // subtract by the # of zeroes that i've now made.
			prev = mp.begin()->first;
			mp.erase(mp.begin());
		}
		cout << ans << '\n';

	}
	return 0;
}