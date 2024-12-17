#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int k = 0; k < n; k++) { // a_0 through a_k
		int ans = 1;
		int left = 1, right = k + 1;
		while (left <= right) {
			int d = (left + right) / 2;
			if (d <= a[k - d + 1]) {
				ans = max(ans, d);
				left = d + 1;
			} else {
				right = d - 1;
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int t; cin >> t;
  	while (t--) solve();

	return 0;
}