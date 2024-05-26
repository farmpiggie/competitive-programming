// can make the entire array x if the distance between two variables is at most 2
// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		set<int> s;
		for (int& x : a) s.insert(x);
		vector<int> possible;
		for (int x : s) possible.push_back(x);

		int lo = 0, hi = possible.size() - 1;
		int best = 0;
		for (int i = 0; i < n - 1; i++) {
			best = max(best, min(a[i], a[i + 1]));
		}
		while (lo <= hi) {
			int mi = lo + (hi - lo) / 2;
			int trial = possible[mi];
			vector<int> psum(n, 0);
			psum[0] = (a[0] >= trial ? 1 : -1);
			for (int i = 1; i < n; i++) {
				psum[i] = psum[i - 1] + (a[i] >= trial ? 1 : -1);
			}
			map<int, int> mp;
			mp[0] = -1;
			mp[psum[0]] = 0;
			//mp[psum[1]] = psum[1]; // cannot be equal to psum[0]
			// array must be of at least size 3 here
			bool works = false;
			for (int i = 2; i < n; i++) {
				if (psum[i] - mp.begin()->first > 0) {
					works = true;
				}	
				if (mp.find(psum[i - 1]) == mp.end()) mp[psum[i - 1]] = i - 1;
			}
			if (works) {
				best = possible[mi];
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
		cout << best << '\n';
	}
}
