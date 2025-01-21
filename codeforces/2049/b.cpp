#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		map<int, array<int, 2>> mp;
		bool works = true;
		for (int i = 0; i < n; i++) {
			int l, r;
			if (s[i] == '.') continue;
			if (s[i] == 's') {
				l = i, r = n - 1;
			} else {
				l = 0, r = i;
			}

			if (mp.find(r - l) != mp.end() && (mp[r - l][0] != l || mp[r - l][1] != r)) {
				works = false;
				break;
			} else {
				mp[r - l] = {l, r};
			}
		}

		vector<array<int, 2>> a;
		for (auto [_, b] : mp) {
			a.push_back(b);
		}

		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (!(a[i][0] <= a[j][0] && a[j][1] <= a[i][1])) {
					works = false;
					break;
				}
			}
		}
		cout << (works ? "YES" : "NO") << '\n';
	}
}

