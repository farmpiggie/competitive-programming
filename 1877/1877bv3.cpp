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

	residents.push_back({p, n - 1});

	sort(residents.begin(), residents.end());

	ll ans = p;
	int sent = 0;
	for (pii& resident : residents) {
		int sendAmt = min(n - 1 - sent, resident.second);
		sent += sendAmt;
		ans += (ll) resident.first * sendAmt;

		if (sent == n - 1) break;
	}

	cout << ans << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}