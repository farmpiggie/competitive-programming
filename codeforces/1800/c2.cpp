#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	map<ll, ll> mp; // store powerups
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll card; cin >> card;
		if (card == 0) {
			if (mp.size() == 0) continue;
			ll val = mp.rbegin()->first;
			ans += val;
			mp[val]--;
			if (mp[val] == 0) mp.erase(mp.find(val));
		} else {
			if (mp.count(card)) mp[card]++;
			else mp[card] = 1;
		}
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}