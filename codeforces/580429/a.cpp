// 1, 2, and 3
// 1 2 3 1 (4)
// 1, 2, 3, and 4
// 1 2 3 4 1 3 2 4 (8)
// 3 + 2 + 1
/*
 * construct complete graph with n nodes, each node representing one q_i value.
 * euler path only exists if n is odd.
 * length of sequence for odd n: (n * (n - 1)) / 2 + 1 <-- edges + 1
 * length of sequence for even n: (n * (n - 1)) / 2 + 1 + (n - 1) / 2 <-- (edges + 1) + (n - 1) / 2
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> w(m);
	for (int& x : w) {
		int q;
		cin >> q >> x;
	}
	sort(w.rbegin(), w.rend());

	// bin search on # of nodes
	// sqrt(2e6) = 1414
	int l = 1, r = 2000;
	int ans = 1; // we can always do at least one
	while (l <= r) {
		int m = (l + r) / 2;
		int res = m * (m - 1) / 2 + 1; 
		if (m % 2 == 0) { // even nodes, must construct euler path
			res += (m - 1) / 2; // whole number since m is odd
		}
		if (res <= n) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	ll sum = 0;
	for (int i = 0; i < min(m, ans); i++) {
		sum += w[i];
	}
	cout << sum << '\n';
	return 0;
}
	

