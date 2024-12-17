#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;


#define MAXN 1000005

ll t, n, a[MAXN], mp[MAXN];


void solve() {
	// cout << "test case: " << t << '\n';
	cin >> n;
	set<pll> s;
	int zero = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) zero = i;
	}

	for (int i = 0; i < n; i++) {
		int j = (i + zero) % n;
		mp[a[j]] = i;
	}

	ll ans = n;
	s.insert(make_pair(0, 0));
	for (int j = 1; j < n; j++) {
		int i = (j + zero) % n;
		auto it = --s.end();
		while (it->first > a[i]) {
			s.erase(it);
			it = --s.end();
		}
		if (it->first < a[i]) {
			int idx = mp[it->first];
			s.insert(make_pair(a[i], it->second + (j - idx) * a[i]));
		} 
		// cout << "iteration: " << '\n';
		// for (pll p : s) {
		// 	cout << p.first << " " << p.second << '\n';
		// }
		ans = max(ans, (--s.end())->second + n);
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}