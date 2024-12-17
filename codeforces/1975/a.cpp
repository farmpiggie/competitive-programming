#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		int i = 0;
		for (; i < n - 1; i++) {
			if (a[i] > a[i + 1]) break;
		}
		bool works = true;
		i++;
		for (int j = i; j < n - 1; j++) {
			if (a[j] > a[j + 1]) works = false;
		}
		for (int j = i; j < n; j++) {
			if (a[j] > a[0]) works = false;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";


	}
	return 0;
}
