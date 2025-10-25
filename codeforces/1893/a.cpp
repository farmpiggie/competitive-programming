#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, k, a[N];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	k = min(n, k);

	int s = 0;
	for (int i = 0; i < k; i++) {
		int last = (s + (n - 1)) % n;
		if (a[last] > n) return cout << "No\n", void();

		s = (s + n - a[last]) % n;
	}
	cout << "Yes\n";


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}