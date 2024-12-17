#include <bits/stdc++.h>
using namespace std;

// int powerOfTwo(int val) {
// 	if (val == 1) return 0;
// 	else if (val % 2 == 0) return 2 * powerOfTwo(val / 2);
// 	else return 2 * powerOfTwo(val / 2) + 1;
// }

// long long pow2(int val) {
// 	if (val == 0) return 1;
// 	else if (val % 2 == 0) return 
// }

void solve() {
	int n, m; cin >> n >> m;
	n %= m;
	int a = n / __gcd(n, m);
	int b = m / __gcd(n, m);

	if (__builtin_popcount(b) != 1) {
		cout << -1 << '\n';
		return;
	} else {
		cout << 1ll * __builtin_popcount(a) * m - n << '\n';
	}

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}