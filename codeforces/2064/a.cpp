/*
 * split block into 0s and 1s
 * ans = # of alternating blocks - 1 if we start with 0.
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (s[i - 1] != s[i]) ans++;
		}
		cout << ans - (s[0] == '0') << '\n';
	}
}

