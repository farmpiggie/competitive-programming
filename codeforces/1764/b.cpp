#include <bits/stdc++.h>

using namespace std;

int main() {
	// ifstream cin("doremymathclass.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int tmp = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tmp = gcd(tmp, a[i]);
		}
		cout << a[n - 1] / tmp + (a[0] == 0) << endl;
	}
	return 0;
}