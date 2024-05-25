// every operation you lose 1 card
// need to have three of the same card
// either you can get down to k - 1 cards, or you're just left with that number of cards
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		map<int, int> mp;
		for (int& x : a) mp[x]++;

		int best = 0;
		for (auto& p : mp) best = max(best, p.second);
		if (best >= k) cout << k - 1 << '\n';
		else cout << n << '\n';
	}
	return 0;
}
