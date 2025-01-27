#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int cnt = 0;
		for (char c : s) {
			if (c == '1') {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}
