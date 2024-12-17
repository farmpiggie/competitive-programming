#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.size();
		int q; cin >> q;

		int cnt = 0;
		vector<bool> valid(n, 0);
		for (int i = 0; i + 3 < n; i++) {
			if (s.substr(i, 4) == "1100") {
				cnt++;
				valid[i] = 1;
			}
		}

		while (q--) {
			int i, v; cin >> i >> v;
			--i;
			s[i] = '0' + v;

			for (int idx = max(i - 3, 0); idx <= min(i, n - 4); idx++) {
				if (s.substr(idx, 4) == "1100") {
					if (!valid[idx]) {
						valid[idx] = 1;
						cnt++;
					} // else no change.
				} else {
					if (valid[idx]) {
						valid[idx] = 0;
						cnt--;
					}
				}
			} 
			if (cnt > 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}