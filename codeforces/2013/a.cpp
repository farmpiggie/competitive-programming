#include <bits/stdc++.h>
using namespace std;

// if y <= x, we can blend y fruits per min
// otherwise, we can blend x fruits per min

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		cout << n / min(x, y) + (n % min(x, y) != 0) << '\n';
	}
	return 0;
}