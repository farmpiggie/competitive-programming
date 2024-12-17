#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tn; cin >> tn;
	while (tn--) {
		string s, t; cin >> s >> t;
		int m = (int) s.length(), n = (int) t.length();
		int m_idx = 0, n_idx = 0;
		while (n_idx < n && m_idx < m) {
			if (s[m_idx] == t[n_idx] || s[m_idx] == '?') {
				s[m_idx] = (s[m_idx] == '?') ? t[n_idx] : s[m_idx];
				n_idx++;
			}
			m_idx++;
		}
		for (char& c : s) if (c == '?') c = 'z';
		if (n_idx == n) {
			cout << "YES\n";
			cout << s << '\n';
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}