#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

void solve() {
	cin >> n >> s;
	map<char, int> mp;
	int mx = 0;
	for (char c : s) {
		mp[c]++;
		mx = max(mx, mp[c]);
	}

	cout << max(n % 2, 2 * mx - n) << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}