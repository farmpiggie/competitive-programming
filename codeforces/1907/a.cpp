#include <bits/stdc++.h>
using namespace std;

int t;
string s;

void solve() {
	cin >> s;
	for (char c = 'a'; c <= 'h'; c++) {
		if (c == s[0]) continue;
		else cout << c << s[1] << '\n';
	}
	for (char c = '1'; c <= '8'; c++) {
		if (c == s[1]) continue;
		else cout << s[0] << c << '\n';
	}
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}