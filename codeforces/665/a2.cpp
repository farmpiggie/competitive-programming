/*
 * intuition: if two letters are same, change the second letter. make sure it doesnt match the letter behind it
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = (int) s.length();
	auto change = [&](int i) {
		set<char> st = {'a', 'b', 'c'}; // one of these three always work
		st.erase(s[i - 1]);
		if (i + 1 < n) st.erase(s[i + 1]);
		s[i] = *st.begin();
	};

	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) {
			change(i);
		}
	}
	cout << s << '\n';
	return 0;
}
