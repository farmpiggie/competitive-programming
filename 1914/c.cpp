#include <bits/stdc++.h>
using namespace std;

/*
 * ans = max(sum(a1...ai), (k - i) * max(b1...bi)) over all 1 <= i <= n
 */

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; 
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;

		int sum = 0;
		int mx = b[0];
		int ans = 0;
		for (int i = 0; i < min(n, k); i++) {
			sum += a[i];
			mx = max(mx, b[i]);
			ans = max(ans, sum + (k - i - 1) * mx);
		}	
		cout << ans << endl;
	}
	return 0;
}
