#include <bits/stdc++.h>
using namespace std;

string solve() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	// insert t into s
	// t must satisfy condition a_i != a_(i + 1)
	// s: 11, t = 010
	// solved by: 10101 s[0] + t + s[1]
	// to resolve any discrepancy in s, insert one instance of t, if this does not fix the discrepancy, then it is not possible

	bool nworks = true;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			nworks = false;
			break;
		}
	}

	if (nworks) return "Yes";

	bool mworks = true;
	for (int i = 1; i < m; i++) {
		if (t[i] == t[i - 1]) {
			mworks = false;
			break;
		}
	}

	if (!mworks) return "No";

	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			if (s[i - 1] == t[0] || t[m - 1] == s[i]) return "No";
		}
	}
	return "Yes";

}

int main() {
	int t; cin >> t;
	while (t--) cout << solve() << '\n';
	return 0;
}