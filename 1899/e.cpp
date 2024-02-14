#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	
	int small_index = 0;
	for (int i = 1; i < n; i++) {
		if (a[small_index] > a[i]) {
			small_index = i;
		}
	}

	for (int i = small_index + 1; i < n; i++) {
		if (a[i - 1] > a[i]) return cout << "-1\n", void();
	}
	cout << small_index << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}