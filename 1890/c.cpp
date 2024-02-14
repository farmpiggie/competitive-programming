#include <bits/stdc++.h>
using namespace std;
/*
1001
----
011001
*/

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	if (n % 2 == 1) {
		cout << "-1" << '\n';
		return;
	}

	int balance = 0;
	for (char c : s) {
		if (c == '0') balance--;
		else balance++;
	}

	if (balance != 0) {
		cout << "-1" << '\n';
		return;
	}

	vector<int> ans;
	for (int p = 0; p < 300; p++) {
		int i = 0;
		for (; i < (int)s.length() / 2; i++) {
			if (s[i] == s[s.length() - 1 - i]) break;
		}
		if (i == s.length() / 2) {
			cout << ans.size() << '\n';
			if (ans.size() > 0) {
				for (int idx : ans) cout << idx << " ";
				cout << '\n';
			}
			return;
		} else {
			if (s[i] == '1') { // in order to balance a 1 1, insert a 01 on the left side BEFORE the s[i]
				ans.push_back(i);
				s = s.substr(0, i) + "01" + s.substr(i);
			} else { // in order to balance a 0 x 0, insert a 01 on the RIGHT side after the s[s.length() - 1 - i]
				ans.push_back(s.length() - i);
				s = s.substr(0, s.length() - i) + "01" + s.substr(s.length() - i);
			}
		}
	}
	cout << "-1" << '\n';
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}