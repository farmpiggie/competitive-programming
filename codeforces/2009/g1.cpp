#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k, q; cin >> n >> k >> q;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		vector<int> groups(n);
		set<pair<int, int>> groupSizes; // {groupSize, groupIndex}
		map<int, int> group_count; // for counting group sizes

		for (int i = 0; i < n; i++) {
			groups[i] = a[i] - i;
			groupSizes.insert({0, a[i] - i});
			group_count[a[i] - i] = 0;
		}

		vector<int> ans(n - k + 1); // as[i] = answers for values starting at i

		for (int i = 0; i < k; i++) {
			groupSizes.erase(groupSizes.find({group_count[groups[i]], groups[i]}));
			group_count[groups[i]]++;
			groupSizes.insert({group_count[groups[i]], groups[i]});
		}
		ans[0] = k - groupSizes.rbegin()->first; // biggest value


		for (int i = k; i < n; i++) {
			groupSizes.erase(groupSizes.find({group_count[groups[i]], groups[i]}));
			group_count[groups[i]]++;
			groupSizes.insert({group_count[groups[i]], groups[i]});

			groupSizes.erase(groupSizes.find({group_count[groups[i - k]], groups[i - k]}));
			group_count[groups[i - k]]--;
			groupSizes.insert({group_count[groups[i - k]], groups[i - k]});

			ans[i - k + 1] = k - groupSizes.rbegin()->first; // biggest value
		}


		while (q--) {
			int l, r; cin >> l >> r;
			--l; --r;
			cout << ans[l] << '\n';
		}

	}
	return 0;
}