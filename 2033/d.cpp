#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		map<ll, int> mp;
		mp[0] = -1;
		int prev = -2;
		ll sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (mp.find(sum) != mp.end() && mp[sum] >= prev) {
				ans++;
				prev = i;
			}
			mp[sum] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}
