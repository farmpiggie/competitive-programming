#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();
		bool works = false;
		for (int i = 1; i < n; i++) {
			if (s[0] != s[i]) {
				swap(s[0], s[i]);
				works = true;
				break;
			}
		}
		if (works) cout << "YES\n" << s << '\n';
		else cout << "NO\n";
	}
	return 0;
}
