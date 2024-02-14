#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t, n;

void solve() {
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mp[a]++;
	}
	int cur = 0;
	ll ans = 0;
	for (auto p : mp) {
		int x = p.second;
		if (x >= 2) {
			ans += cur * 1ll * p.second * (p.second - 1) / 2;
		}
		if (x >= 3) {
			ans += 1ll * p.second * (p.second - 1) * (p.second - 2) / 6;
		}
		cur += p.second;
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}