#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> b(n);
		for (int &x : b) cin >> x;
		int ans = 1;
		for (int i = 1; i < n; i++) {
			ans = lcm(ans, b[i - 1] / gcd(b[i], b[i - 1]));
		}
		cout << ans << '\n';
	}
}