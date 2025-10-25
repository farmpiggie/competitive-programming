#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	map<char, int> mp;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (mp.count(c)) mp[c]++;
		else mp[c] = 1;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		char lower = (i + 'a');
		char upper = (i + 'A');
		if (mp.count(lower) || mp.count(upper)) {
			ans += min(mp[lower], mp[upper]);
			int diff = abs(mp[upper] - mp[lower]) / 2;
			if (diff > k) {
				diff = k;
			} 
			k -= diff;
			ans += diff;
		} 
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}