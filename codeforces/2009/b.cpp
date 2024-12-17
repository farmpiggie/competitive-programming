#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < 4; j++) {
				if (s[j] == '#') ans.push_back(j + 1);
			}
		}
		reverse(ans.begin(), ans.end());
		for (int& x : ans) cout << x << " ";
		cout << '\n';
	}
	return 0;
}