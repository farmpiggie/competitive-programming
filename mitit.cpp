#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();
		bool works = false;
		for (int j = 1; j * 2 < n; j++) {
			string b1 = s.substr(n - j, j);
			string b2 = s.substr(n - 2 * j, j);
			if (b1 == b2) works = true;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
