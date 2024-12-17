#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a = max(0, n - m), b = n + m;
		int ans = a | b;
		for (int i = 31; i >= 0; i--) {
			int a_bit = (a >> i) & 1;
			int b_bit = (b >> i) & 1;
			if (b_bit > a_bit) {
				ans |= (1 << i) - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
