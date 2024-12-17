#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int ans = n + 1, cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] != a[0]) {
				ans = min(ans, cnt);
				cnt = 0;
			} else {
				cnt++;
			}
		}
		if (ans == n + 1) cout << "-1\n";
		else cout << ans << '\n';
	}
}
