// any unique #s have to be in the last segment
// all other #s left are therefore either unique or 
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, vector<int>> mp;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			int x; 
			cin >> x;
			a[i] = x;
			mp[x].push_back(i);
		}
		int cnt = 1;
		set<int> s, s2;
		s.insert(a[0]);
		for (int i = 1; i < n; i++) {
			s2.insert(a[i]);
			if (s.find(a[i]) != s.end()) {
				s.erase(a[i]);
			}
			if (s.size() == 0) {
				cnt++;
				s = s2;
				s2 = {};
			}
		}
		cout << cnt << '\n';
	}
}