#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	map<char, int> left, right;

	left[s[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (right.count(s[i])) right[s[i]]++;
		else right[s[i]] = 1;
	}

	int ans = left.size() + right.size();
	for (int i = 1; i < n - 1; i++) {
		if (left.count(s[i])) left[s[i]]++;
		else left[s[i]] = 1;

		right[s[i]]--;
		if (right[s[i]] == 0) right.erase(right.find(s[i]));

		ans = max(ans, (int) (left.size() + right.size()));
	}

	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}