// given an even length permutation p, find another permutation of same length q
// array a s.t. a_i = p_i + q_i
// create a_i to maximize local maximums, i.e. # of i s.t. a_(i - 1) < a_i and a_i > a_(i + 1)
// max # of peaks is (n - 2) / 2
// 1 2 4 5 7 6 8 3
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == n) idx = i;
		}
		if (idx % 2 == 1) reverse(a.begin(), a.end());

		vector<pii> odd;
		vector<pii> even;
		vector<int> ans(n);
		for (int i = 0; i < n; i+= 2) { // odd values not including first one
			odd.push_back({a[i], i});
		}
		for (int i = 1; i < n; i += 2) {
			// even values
			even.push_back({a[i], i});
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		for (int i = 0; i < odd.size(); i++) {
			ans[odd[i].second] = n - i;
		}
		for (int i = 0; i < even.size(); i++) {
			ans[even[i].second] = n / 2 - i;
		}
		if (idx % 2 == 1) reverse(ans.begin(), ans.end());
		for (int& x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
