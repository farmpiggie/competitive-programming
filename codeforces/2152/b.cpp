#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int rk, ck, rd, cd;
		cin >> rk >> ck >> rd >> cd;
		int ans = 0;
		if (rd > rk) ans = max(ans, rd);
		else if (rd < rk) ans = max(ans, n - rd);
		if (cd > ck) ans = max(ans, cd);
		else if (cd < ck) ans = max(ans, n - cd);
		cout << ans << '\n';
	}
}


