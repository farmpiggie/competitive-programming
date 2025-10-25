#include <bits/stdc++.h>
using namespace std;

// ifstream fin("843a2.in");


void solve() {
	string s;
	cin >> s;
	// if we can find an 'a' in the middle of s, follow rule 2
	int index = -1;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == 'a') {
			index = i;
			break;
		}
	}

	if (index != -1) {
		cout << s.substr(0, index) << " " << s[index] << " " << s.substr(index + 1) << "\n";
		return;
	}

	// otherwise try rule 1. look for the first b starting from index 1
	int start = -1, end = -1;
	for (int i = 1; i < s.length(); i++) {
		if (start == -1 && s[i] == 'b') {
			start = i;
		}
		if (start != -1 && s[i] == 'a') {
			end = i;
			break;
		}
	}

	// all Bs i guess
	if (end == -1) {
		cout << s[0] << " " << s.substr(1, s.length() - 2) << " " << s[s.length() - 1];
		cout << "\n";
 	} else {
 		cout << s.substr(0, start) << " " << s.substr(start, end - start) << " " << s.substr(end) << "\n";
 	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}