// https://codeforces.com/contest/1759/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		bool works = (s[0] == 'Y' || s[0] == 'e' || s[0] == 's');
		for (int j = 1; j < s.length(); j++) {
			if ((s[j] != 'Y' && s[j] != 'e' && s[j] != 's') ||
				(s[j - 1] == 'Y' && s[j] != 'e') || 
				(s[j - 1] == 'e' && s[j] != 's') || 
				(s[j - 1] == 's' && s[j] != 'Y')) {
				works = false;
				break;
			}
		}
		if (works) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}