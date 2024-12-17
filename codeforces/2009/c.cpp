#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll x, y, k; cin >> x >> y >> k;
		ll left = x / k + (x % k != 0), right = y / k + (y % k != 0);
		if (left > right) cout << 2 * left - 1 << endl;
		else cout << 2 * right << endl;

	}
	return 0;
}