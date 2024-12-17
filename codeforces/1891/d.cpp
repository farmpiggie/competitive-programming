#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define f first
#define s second

ll _exp(ll b, ll p) {
	if (p == 0) return 1;
	ll half = _exp(b, p/2);
	return half * half * ((p % 2 == 0) ? 1 : b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<pair<pair<ll, ll>, ll>> segments;
	int cur = 1;
	for (int i = 2; i <= 59; i++) {
		ll val1 = _exp(i, cur + 1);
		ll l = (1ull << i), r = ((1ull << (i + 1)) - 1);
		if (val1 < 0) val1 = ULLONG_MAX;
		int small = (val1 <= l) ? (cur + 1) : cur;
		ll val2 = _exp(i, small + 1);
		if (val2 < 0) val2 = ULLONG_MAX;
		cout << "i: " << i << " " << val1 << " " << val2 << '\n';
		int big = (val2 <= r) ? small + 1 : small;
		cur = big;
		if (i == 2) cur = 1;

		if (small == big) segments.push_back({{l, r}, small});
		else {
			segments.push_back({{l, _exp(i, big) - 1}, small});
			segments.push_back({{_exp(i, big), r}, big});
		}
	}

	for (auto& segment : segments) {
		cout << segment.f.f << " " << segment.f.s << " " << segment.s << '\n';
	}
	
	ll MOD = (1e9 + 7);
	int t; cin >> t;
	while (t--) {
		ll l, r; cin >> l >> r;
		ll ans = 0;
		for (auto& segment : segments) {
			if (r < segment.f.f || l > segment.f.s) continue;
			cout << min(segment.f.s, r) - max(segment.f.f, l) + 1 << " " << segment.s << '\n';
			ans = (ans + (((min(segment.f.s, r) - max(segment.f.f, l) + 1) * segment.s) % MOD)) % MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}
