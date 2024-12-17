#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void solve() {
	int n, p; cin >> n >> p;
	vector<int> amount(n), cost(n);
	vector<pii> residents;

	for (int i = 0; i < n; i++) {
		cin >> amount[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < n; i++) {
		residents.push_back({cost[i], amount[i]});
	}

	sort(residents.begin(), residents.end());

	ll ans = 0;
	map<int, int> mp;
	mp[p] = n;
	for (int i = 0; i < n; i++) {
		auto it = mp.begin();
		if (it->first <= p) {
			ans += it->first;
			mp[residents[i].first] += residents[i].second;
		}
		--it->second;
		if (it->second == 0) mp.erase(it);
	}

	cout << ans << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}