#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// a_i is even, a_i + 1 is odd
// a_i is greater than a_i + 1

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

 	// change all ones into twos
	for (int i = 0; i < n; i++) if (a[i] == 1) a[i] = 2;

	for (int i = 1; i < n; i++) {
		if (a[i] % a[i - 1] == 0) a[i]++;
	}

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}