#include <bits/stdc++.h>
using namespace std;

int t, n;
string s1, s2;

void solve() {
	cin >> s1;
	s2 = "";
	int n = (int) s1.length();
	for (int i = n - 1; i > 0; i--) {
		s2 = s1[i] + s2;
		s1 = s1.substr(0, (int) s1.length() - 1);
		if (s1[0] != '0' && s2[0] != '0') {
			int a = stoi(s1), b = stoi(s2);
			if (a > 0 && b > 0 && b > a) {
				cout << a << " " << b << '\n';
				return;
			}
		}
	}
	cout << "-1\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}