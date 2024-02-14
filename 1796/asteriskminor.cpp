#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a, b; cin >> a >> b;
	// either cases: first check if first or last letters match (we can use *a or a*)
	if (a[0] == b[0]) { cout << "YES\n" << a[0] << "*\n"; return; }
	if (a[a.length() - 1] == b[b.length() - 1]) { cout << "YES\n" << "*" << a[a.length() - 1] << "\n"; return; }
	// check if any consecutive two elements match
	set<string> s1, s2;
	for (int i = 0; i < a.length() - 1; i++) {
		s1.insert(a.substr(i, 2));
	}
	for (int i = 0; i < b.length() - 1; i++) {
		s2.insert(b.substr(i, 2));
	}

	for (string s : s1) {
		if (s2.count(s)) {
			cout << "YES\n" << '*' << s << "*\n"; return;
		}
	}
	cout << "NO\n";

}

int main() {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int t; cin >> t;
  	while (t--) solve();

	return 0;
}