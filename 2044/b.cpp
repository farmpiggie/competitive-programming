#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		reverse(s.begin(), s.end());
		for (char c : s) {
			if (c == 'p') cout << 'q';
			else if (c == 'q') cout << 'p';
			else cout << c;
		}
		cout << '\n';
	}
	return 0;
}
