#include <bits/stdc++.h>
using namespace std;

#define ll long long

void run() {
	ll n, m; cin >> n >> m;

	ll a = 0, b = 0;
	for (ll i = (1ll << 62); i > 0; i >>= 1) {
		if (i & n) {
			if (!a) a = i;
			else if (!b) b = i;
		}
	}

	bool works = (b && ((m & a) || (m < b * 2)));
	if (!works) {
		cout << "-1\n";
		return;
	}


	vector<ll> ans;
	if (!(m & a) && !(m & b)) {
		ans = {n, m^b, m};
	} else {
		ans = {n, m};
	}

	cout << (int) ans.size() - 1 << '\n';
	for (ll &x : ans) cout << x << ' ';
	cout << '\n';

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while(t--) run();
	return 0;
}