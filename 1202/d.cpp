#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll l = 2, r = 1e5; // number of threes
		ll threes = 0, cnt = n;
		while (l <= r) {
			ll m = (l + r) / 2;
			ll res = m * (m - 1) / 2; // m choose 2
			if (res <= n) {
				threes = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		vector<int> ans;
		for (ll i = threes; i >= 2; i--) {
			ll amt = i * (i - 1) / 2;
			while (cnt >= amt) {
				cnt -= amt;
				ans.push_back(1);
			}
			ans.push_back(3);
		}
		ans.push_back(3);
		ans.push_back(7);
		
		for (int x : ans) cout << x;
		cout << '\n';
	}
	return 0;
}
