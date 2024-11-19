#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		bool works = true;
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) works = false;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}