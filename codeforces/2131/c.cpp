#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<int, int> s, t;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			s[x % k]++; // reduce to this
		}
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			t[x % k]++; // reduce to this
		}

		bool works = true;

		for (auto &[x, cnt] : s) {
			for (int i = 0; i < cnt; i++) {
				int y = abs(x - k);
				if (t.find(x) != t.end() && t[x] > 0) {
					t[x]--;
				} else if (t.find(y) != t.end() && t[y] > 0) {
					t[y]--;
				} else {
					works = false;
					break;
				}
			}
		}

		cout << (works ? "YES" : "NO") << '\n';
	}
}
