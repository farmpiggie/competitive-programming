#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool changed = true;
		while (changed) {
			changed = false;
			for (int i = 1; i < s.size(); i++) {
				if (s[i - 1] + 1 < s[i] && s[i] > '0') {
					s[i]--;
					swap(s[i - 1], s[i]);
					changed = true;
				}
			}
		}
		cout << s << '\n';
	}
}
