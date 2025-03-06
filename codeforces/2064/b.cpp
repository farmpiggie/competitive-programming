/*
 * value of a subarray = # of duplicates it has (len - unique)
 * pick some subarray to remove that maximizes value of new subarray, minimizing final length of a
 *
 * the # of duplicates never goes up, can only go down.
 * must remove some subarray with only unique elements.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		map<int, int> mp;
		for (int &x : a) {
			cin >> x;
			mp[x]++;
		}

		set<int> unique;
		for (auto [x, y] : mp) {
			if (y == 1) unique.insert(x);
		}

		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			if (unique.count(a[i])) b[i] = 1;
			else b[i] = 0;
		}

		bool flag = false;
		int cur_l = 0;
		int cur_len = 0;
		int best = 0;
		int best_l = 0;
		
		for (int i = 0; i < n; i++) {
			if (b[i] == 1) {
				if (!flag) {
					flag = true;
					cur_l = i;
				}
				cur_len++;
			} else {
				if (flag) {
					flag = false;
					if (best < cur_len) {
						best = cur_len;
						best_l = cur_l;
					}
				} 
				cur_l = -1;
				cur_len = 0;
			}
		}
		if (best < cur_len) {
			best = cur_len;
			best_l = cur_l;
		}

		if (best == 0) {
			cout << "0\n";
		} else {
			cout << best_l + 1 << " " << (best_l + 1 + best - 1) << '\n';
		}
	}
}




				




