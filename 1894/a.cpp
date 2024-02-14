#include <bits/stdc++.h>
using namespace std;

int t, n; string s;

void solve() {
	cin >> n >> s;
	cout << s[(int) s.length() - 1] << '\n';
}

int main() {

	cin >> t;
	while (t--) solve();
}