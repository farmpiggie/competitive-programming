#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int ans = INT_MAX, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != a[0]) {
				ans = min(ans, cnt);
				cnt = 0;
			} else {
				cnt++;
			}
		}
		ans = min(ans, cnt);
		if (ans == n) cout << "-1\n";
		else cout << ans << '\n';
	}
}
