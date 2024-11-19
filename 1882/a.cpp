/*
choose (prev # + 1) each time
otherwise choose (prev # + 2)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int ans = 0;
		for (int& x : a) {
			if (ans + 1 == x) ans = ans + 2;
			else ans = ans + 1;
		}
		cout << ans << '\n';
		
	}
	return 0;
}
