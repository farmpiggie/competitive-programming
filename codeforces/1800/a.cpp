#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s;
	cin >> n >> s;
	string ns = "";
	ns += tolower(s[0]);

	for (int i = 1; i < n; i++) {
		if (tolower(s[i]) != ns[ns.length() - 1]) {
			ns += tolower(s[i]);
		}
	}

	if (ns == "meow") cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}