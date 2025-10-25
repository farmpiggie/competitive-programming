/*
 * for k = 1 case, player must be one of largest value.
 * for k >= 2, you can always be second.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, j, k; cin >> n >> j >> k;
		map<int, int> mp;
		int player;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			mp[x]++;
			if (j == i) player = x;
		}

		if (k == 1 && mp.rbegin()->first != player) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}


		
