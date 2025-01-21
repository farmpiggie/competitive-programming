#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		int zeros = 0;
		for (int x : a) if (x == 0) zeros++;
		bool ends_only = true;
		int l = 0; 
		for (; l < n; l++) {
			if (a[l] != 0) break;
		}

		int r = n - 1;
		for (; r >= 0; r--) {
			if (a[r] != 0) break;
		}

		for (int i = l; i <= r; i++) {
			if (a[i] == 0) ends_only = false;
		}

		if (zeros == n) {
			cout << "0\n";
		} else if (zeros == 0 || ends_only) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}
