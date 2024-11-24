#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, L;
		cin >> n >> m >> L;
		vector<pii> a;
		for (int i = 0; i < n; i++) {
			int l, r; cin >> l >> r;
			a.push_back(make_pair(l, r));
		}

		for (int i = 0; i < m; i++) {
			int x, v; cin >> x >> v;
			a.push_back(make_pair(x, -v));
		}

		sort(a.begin(), a.end());
		
		map<int, int> mp;
		int ans = 0;
		int jump = 1;
		bool works = true;
		for (const pii& p : a) {
			if (p.second < 0) {
				mp[-p.second]++;
			} else {
				while (mp.size() > 0 && jump < (p.second - p.first + 2)) {
					jump += mp.rbegin()->first;
					ans++;
					mp.rbegin()->second--;
					if (mp.rbegin()->second == 0) mp.erase(--mp.end());
				}
				if (jump < (p.second - p.first + 2)) {
					works = false;
					break;
				}
			}
		}
		cout << (works ? ans : -1) << '\n';
	}
	return 0;
}
