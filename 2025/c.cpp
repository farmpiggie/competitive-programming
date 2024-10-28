#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll> 

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<ll, ll> mp;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			mp[x]++;
		}
		vector<pii> arr;
		for (auto& [key, value] : mp) {
			arr.push_back({key, value});
		}
		int j = 0;
		ll cur = 0;
		ll ans = 0;
		int prev = arr[0].first - 1;
		for (int i = 0; i < arr.size(); i++) {
			if (i > 0) cur -= arr[i - 1].second;
			if (i == j) prev = arr[i].first - 1; // start from i...
			while (j < arr.size() && prev + 1 == arr[j].first && arr[j].first - arr[i].first < k) {
				cur += arr[j].second;
				prev = arr[j].first;
				j++;
			}
			ans = max(ans, cur);
		}

		cout << ans << '\n';
	}
	return 0;
}