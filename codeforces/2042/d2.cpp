#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		map<pii, vector<int>> dup;
		vector<int> start(n), end(n);
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			start[i] = x;
			end[i] = y;
			dup[make_pair(x, y)].push_back(i); 
		}

		vector<int> ans(n, 0);

		
		map<int, vector<int>> mp; // interval, all indices
		for (auto [x, y] : dup) {
			mp[x.first].push_back(y[0]);
			mp[x.second].push_back(y[0]); // index of the element
		}

		for (auto& [x, y] : mp) {
			sort(y.begin(), y.end(), [&](int a, int b) {
					return start[a] > start[b]; // if equal endpoints, return start greater.
					});
			cout << x << ": ";
			for (int z : y) cout << z << " ";
			cout << '\n';
		}


		map<int, int> s; // {interval, start index}
		map<int, set<int>> mp2; // start index -> intervals here

		map<int, int> b; // {interval, end index}

		for (auto& [x, intervals] : mp) {
			for (int interval : intervals) {
				if (s.find(interval) == s.end()) {
					s[interval] = x;
					mp2[x].insert(interval);
				} else {
					mp2[s[interval]].erase(interval);
					if (mp2[s[interval]].size() == 0) mp2.erase(s[interval]);
					s.erase(interval);
					
					int res = (mp2.size() > 0 ? max(0, start[interval] - mp2.rbegin()->first) : 0);
					cout << "adding " << res << " at beginning for interval " << interval << '\n';
					ans[interval] += (mp2.size() > 0 ? max(0, start[interval] - mp2.rbegin()->first) : 0); // add diff from largest starting value 
												   //
					for (auto& [c, d] : b) {
						cout << x << " " << d << '\n';
						cout << "adding " << max(0, x - d) << " for interval " << c << '\n';
						ans[c] += max(0, x - d);
					}

					b.clear();
					b[interval] = x; // ended
				}
				// if multiple r
			}
		}

		for (int x : ans) cout << x << '\n';

	}
}
