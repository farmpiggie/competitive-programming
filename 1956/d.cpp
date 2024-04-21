// obv 1: we can make any a_i zero (operation on l = i, r = i)
// what can we make with a_i = 0? we can make n^2
// what do we want to add and what do we want to remove?
// dp on 2^18 to see what we want to include and what we don't want to include

#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

// assume all #s in left, right are zeroed out
void helper(int left, int right, vector<pii>& operations) {
	if (left == right) {
		operations.push_back({left, right}); // from 0 to 1
	} else {
		for (int j = left; j < right; j++) {
			helper(j, right - 1, operations);
			for (int i = j + 1; i <= right - 1; i++) {
				operations.push_back({i, i}); // zero out
			}
		}
		operations.push_back({left, right});
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; t = 1;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		ll ans = 0;
		ll best = 0;
		for (int i = 0; i < (1 << n); i++) {
			ll curr = 0;
			vector<pii> segments;
			int left = -1;
			for (int j = 0; j < n; j++) {
				int bit = (i >> j) & 1;
				if (bit) {
					if (left == -1) {
						left = j;
					}
				} else {
					curr += a[j];
					if (left != -1) {
						int len = j - left;
						curr += len * len;
						left = -1;
					}
				}
			}
			if (left != -1) {
				int len = n - left;
				curr += len * len;
			}
			if (curr > ans) {
				ans = curr;
				best = i;
			}	
		}

		vector<pii> operations;
		vector<pii> segments;
		int left = -1;
		for (int i = 0; i < n; i++) {
			int bit = (best >> i) & 1;
			if (bit == 1) {
				if (left == -1) {
					left = i;
				}
			} else {
				if (left != -1) {
					segments.push_back({left, i - 1});
					left = -1;
				}
			}
		}
		if (left != -1) {
			segments.push_back({left, n - 1});
		}

		for (pii& p : segments) {
			for (int i = p.first; i <= p.second; i++) {
				if (a[i] != 0) operations.push_back({i, i});
			}
			helper(p.first, p.second, operations);
		}

		cout << ans << " " << operations.size() << '\n';
		for (pii& p : operations) cout << p.first + 1 << " " << p.second + 1 << '\n';

	}
	return 0;
}
