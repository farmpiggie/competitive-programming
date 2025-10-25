/* for values > mex(a), we can always "remove" them to not lose possibilities.
 * for values < mex(a), we care about what we can make the new mex.
 * let's say we want to make x < mex(a) the new mex. we must be able to remove x (and we can re-use the remainder of our removals on #s > x)
 * lets say numbers > x = y
 * there are a occurrences of x, and b values > x.
 * mex(arr) = x if possible of we are between [a, a + b] removals.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> mp;
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
			s.insert(x);
		}
		vector<pair<int, int>> a;
		for (auto [x, y] : mp) {
			a.push_back(make_pair(x, y));
		}

		map<int, int> bigger;
		map<int, int> smaller;
		int sum = 0;
		for (int i = 0; i < a.size(); i++) {
			smaller[a[i].first] = sum;
			sum += a[i].second - 1;
		}

		int sz = 0;

		for (auto it = mp.rbegin(); it != mp.rend(); it++) {
			bigger[it->first] = sz;
			sz += it->second;
		}
		int mex = 0;
		while (s.find(mex) != s.end()) {
			mex++;
		}
		vector<pair<int, int>> arr;
		for (auto [x, y] : mp) {
			if (x < mex) {
				arr.push_back(make_pair(y, 1)); // start at range y
				arr.push_back(make_pair(y + bigger[x] + smaller[x] + 1, -1)); // end at range y + bigger[x] + 1, exclusive
			}
		}
		arr.push_back(make_pair(0, 1));
		arr.push_back(make_pair(n - mex + 1, -1));
		sort(arr.begin(), arr.end());
		int ans = 0;
		int j = 0;
		for (int i = 0; i <= n; i++) {
			while (j < arr.size() && arr[j].first <= i) {
				ans += arr[j].second;
				j++;
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}


