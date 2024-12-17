#include <bits/stdc++.h>
using namespace std;

int t;
string s;

void solve() {
	cin >> s;
	int n = s.length();
	int ones = 0, zeros = 0;
	for (char c : s) {
		if (c == '0') zeros++;
		else ones++;
	}
	int countones = 0, countzeros = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') countzeros++;
		else countones++;
		
		int extraones = ones - countzeros;
		int extrazeros = zeros - countones;
		if (extraones < 0 || extrazeros < 0) {
			cout << n - i << '\n';
			return;
		}
	}
	cout << "0\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0; 
}