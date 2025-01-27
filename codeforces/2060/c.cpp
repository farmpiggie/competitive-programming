#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> occ(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			occ[x]++;
		}
		// strat is that alice will choose values that DO NOT have a complement.
		int pairs = 0;
		for (int i = 1; i <= n; i++) {
			if (i * 2 == k) pairs += occ[i];	
			else if (k - i >= 1 && k - i <= n) pairs += min(occ[i], occ[k - i]);
		}

		cout << pairs / 2 << '\n';
	}
}


