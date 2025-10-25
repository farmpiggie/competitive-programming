#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		deque<char> dq;
		int num_zeros = 0;
		bool works = true;
		for (int i = 0; i < n; i++) {

			if (dq.empty() || dq.back() != s[i]) {
				dq.push_back(s[i]);
				if (s[i] == '0') num_zeros++;
			} else { // dq.back() == s[i]
				int len = dq.size();
				if (dq.size() % 2 == 1 && dq.back() == '1' && num_zeros % 2 == 1) {
					works = false;
					break;
				}
				num_zeros = (s[i] == '0');
				dq = {};
				dq.push_back(s[i]);
			}
		}
		int len = dq.size();
		if (dq.size() % 2 == 1 && dq.back() == '1' && num_zeros % 2 == 1) {
			works = false;
		}
		cout << (works ? "YES" : "NO") << '\n';

	}
}