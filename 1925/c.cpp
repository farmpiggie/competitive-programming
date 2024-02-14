#include <bits/stdc++.h>
using namespace std;

int t, n, k, m;
string s;

void solve() {
	cin >> n >> k >> m;
	cin >> s;

	vector<int> contains(26, 0);
	// vector<int> num(26, 0);
	int needs = k;
	int cnt = 0;
	string dne = "";
	for (int i = 0; i < m; i++) {
		// num[s[i] - 'a']++;
		if (!contains[s[i] - 'a'] && (int) (s[i] - 'a') < k) {
			needs--;
			contains[s[i] - 'a'] = true;
		}
		if (needs == 0) {
			cnt++;
			for (int j = 0; j < k; j++) {
				contains[j] = 0;
			}
			needs = k;
			dne += s[i];
		}
	}

	// cout << dne << '\n';
	// build string if not true
	if (cnt >= n) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
		for (int i = 0; i < k; i++) {
			if (!contains[i]) {
				dne += (char) ('a' + i);
				while (dne.length() < n) {
					dne += 'a';
				}
				break;
			}
		}
		cout << dne << '\n';
	}
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}