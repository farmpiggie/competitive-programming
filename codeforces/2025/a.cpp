#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s, t; cin >> s >> t;
		int match = 0;
		for (int i = 1; i <= min(s.length(), t.length()); i++) {
			if (s.substr(0, i) == t.substr(0, i)) match = i;
			else break;
		}
		cout << s.length() + t.length() - max(0, (match - 1)) << endl;
	}
	return 0;
}