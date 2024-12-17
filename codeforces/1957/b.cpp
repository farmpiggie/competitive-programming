// first number should be 2^x - 1, biggest k s.t. 2^x - 1 <= k
// second number should be k - (2 ^ x - 1)
// rest is zero
#include <bits/stdc++.h>
using namespace std;

int log2(int x) {
	if (x == 1) return 0;
	else return 1 + log2(x / 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (n == 1) {
			cout << k << '\n';
			continue;
		}
		int x = log2(k + 1);
		cout << ((1 << x) - 1) << ' ' << (k - (1 << x) + 1) << ' ';
		for (int i = 2; i < n; i++) cout << 0 << ' ';
		cout << '\n';
		
	}
	return 0;
}
