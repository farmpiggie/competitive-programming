#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		string orig_s = s;
		s = "1" + s + "1";
		bool works = true;
		for (int i = 0; i <= (int) s.length() - 3; i++) {
			string t = s.substr(i, 3);
			if (t == "101") {
				works = false;
				break;
			}
		}
		if (works) {
			cout << "YES\n";
			vector<int> ans(n + 1, 0);
			vector<int> cur;
			int prev = 1;
			for (int i = 0; i < n; i++) {
				if (orig_s[i] == '1') {
					reverse(cur.begin(), cur.end());
					for (int j = 0; j < cur.size(); j++) {
						ans[prev + j] = cur[j];
					}
					ans[i + 1] = i + 1;
					cur = {};
					prev = -1;
				} else {
					if (prev == -1) prev = i + 1; // start filling from here
					cur.push_back(i + 1);
				}
			}
			reverse(cur.begin(), cur.end());
			for (int j = 0; j < cur.size(); j++) {
				ans[prev + j] = cur[j];
			}
			for (int i = 1; i <= n; i++) {
				cout << ans[i] << " ";
			}
			cout << '\n';
		} else cout << "NO\n";
	}
}