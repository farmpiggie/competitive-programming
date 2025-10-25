#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// ifstream cin("twogroups.in");
	int t; cin >> t;
	while (t--) {
		int s1 = 0, s2 = 0;
		int n; cin >> n;
		ll ans = 0, a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			ans += a;
		}
		cout << abs(ans) << endl;
	}
	return 0;
}