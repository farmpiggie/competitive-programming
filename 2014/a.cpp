#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int gold = 0;
		int ans = 0;
		// cout << "---\n";
		for (int& x : a) {
			if (x >= k) {
				gold += x;
			} else {
				if (x == 0 && gold > 0) {
					gold--;
					ans++;
				}
			}
			// cout << ans << " " << gold << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}