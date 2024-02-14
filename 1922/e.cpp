#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int t;
ll x;

ll my_log2(ll x) {
	if (x <= 1) return 0;
	else return 1 + my_log2(x >> 1);
}

void solve() {
	cin >> x;
	ll total = 2;
	vector<int> ans;
	ans.push_back(1);
	while (total < x) {
		// cout << total << '\n';
		if (total * 2 <= x) {
			ans.push_back((int) ans.back() + 1);
			total *= 2;
		} else {
			// int val = ans.back();
			// int sz = (int) ans.size();
			ll diff = (ll) my_log2(x - total);
			ans.push_back((diff + 1));
			// cout << "diff: " << diff << '\n';
			total += (1ll << diff);
		}
	}

	cout << ans.size() << '\n';
	for (int val : ans) {
		cout << val << ' ';
	}
	cout << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}