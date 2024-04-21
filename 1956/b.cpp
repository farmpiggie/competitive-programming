// if nene owns both copies of a card, she wants to place those first. this means that i have to place cards that don't match to hers, which means i can't gain points (yet)
// if you own both sets of cards, you automatically gain that
// if you don't own both sets of cards, you want to hold off as long as possible to see if the other person will play said card
// so nene and i will start off by placing cards that we own both of.
// after we run out, then we need to start playing cards which we don't own both of
// whoever has the most sets of pocket pairs wins (pocket pairs + remainders)
// whoever doesnt have the most set of pocket pairs wins (pocket pairs) only
// if tie, i only gain (pocket pairs)
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[x]++;
		}
		int pairs = 0;
		int loner = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt.find(i) != cnt.end()) {
				if (cnt[i] == 2) pairs++;
				else loner++;
			}
		}
		int o_pairs = n - pairs - loner;
		if (pairs <= o_pairs) cout << pairs << '\n';
		else cout << pairs + loner << '\n';
	}
	return 0;
}
