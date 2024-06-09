#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;
		string s; 
		cin >> n >> s;
		bool letter_time = false;
		int prev_digit = 0;
		int prev_letter = 'a';
		bool works = true;
		for (int i = 0; i < n; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (!letter_time && prev_digit <= (s[i] - '0')) {
					prev_digit = (s[i] - '0');
				} else {
					works = false;
					break;
				}
			} else {
				if (!letter_time) {
					letter_time = true;
					prev_letter = s[i];
				} else if (prev_letter <= s[i]) {
					prev_letter = s[i];
				} else {
					works = false;
					break;
				}
			}
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
		
	}
}
