#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[x]++;
		}
		vector<pair<int, int>> a; // (cnt, number);
		for (auto &[x, y] : cnt) a.push_back({y, x});
		sort(a.begin(), a.end(), [&](pair<int, int> p1, pair<int, int> p2) {
				if (p1.second % 2 != p2.second % 2) { 
					return (p1.second % 2 == 1);
				} else {
					return p1.first > p2.first;
				}
			}); // sort by biggest cnt
		ll alice = 0, bob = 0;
		bool alice_turn = true;
		for (auto [cnt, val] : a) {
			if (alice_turn) {
				 alice += 1ll * ((val + 1) / 2) * cnt;
				 bob += 1ll * (val / 2) * cnt;
			} else {
				 bob += 1ll * ((val + 1) / 2) * cnt;
				 alice += 1ll * (val / 2) * cnt;
			}
			if (val % 2 == 1) alice_turn = !alice_turn;
		}
		cout << alice << " " << bob << '\n';
	}
}