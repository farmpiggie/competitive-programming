#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	string s, t; cin >> s >> t;

	if (s == t) { cout << "YES" << endl; return; }

	// check if characters are the same
	string ns = s, nt = t;
	sort(ns.begin(), ns.end());
	sort(nt.begin(), nt.end());
	if (ns != nt) { cout << "NO" << endl; return; }

	string m1 = "", m2 = "";

	for (int i = 0; i < n; i++) { 
		if (i - k < 0 && i + k >= n) {
			m1 += s[i];
			m2 += t[i];
		}

	}
	if (m1 == m2) cout << "YES" << endl;
	else cout << "NO" << endl;


}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}