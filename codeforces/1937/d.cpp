#include <bits/stdc++.h>
using namespace std;

#define ll long long

void run() {
	int n; string s; cin >> n >> s;
	// cout << "test case start\n";
	vector<ll> ans(n);
	vector<ll> l_psum(n, 0), r_psum(n, 0);
	int l_cnt = 0, r_cnt = 0;
	vector<ll> l_pos, r_pos;
	for (int i = 0; i < n; i++) {
		if (s[i] == '<') {
			r_cnt++; 
			r_pos.push_back(i);
		} else {
			l_pos.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		l_psum[i] = (s[i] == '>') ? i : 0;
		if (i) l_psum[i] += l_psum[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		r_psum[i] = (s[i] == '<') ? i : 0;
		if (i + 1 < n) r_psum[i] += r_psum[i + 1];
	}
	int cur_l = -1, cur_r = 0;

	for (int i = 0; i < n; i++) {
		// when moving, possibly need to increment cur_l or cur_r
		if (i && s[i - 1] == '>') {
			cur_l++; // previous i is a '>'
			l_cnt++;
		}
		if (cur_r < r_pos.size() && r_pos[cur_r] == i) {
			cur_r++; // current i is a '<'
			r_cnt--;
		}
		// cout << l_cnt << ' ' << r_cnt << '\n';


		// int num_left = (cur_l >= 0) ? l_psum[l_pos[cur_l]] : 0; // if cur_l is -1, means no '>'
		// int num_right = (cur_r < r_pos.length()) ? r_psum[r_pos[cur_r]] : 0; // if cur_r >= r_pos.length(), means no '<'

		ll right_sum = (cur_r < r_pos.size()) ? r_psum[r_pos[cur_r]] : 0;
		ll left_sum = (cur_l >= 0) ? l_psum[l_pos[cur_l]] : 0;
		// cout << left_sum << " " << right_sum << '\n';
		if (s[i] == '>') {
			if (l_cnt >= r_cnt) { // end right
				if (cur_l - r_cnt >= 0) {
					left_sum -= l_psum[l_pos[cur_l - r_cnt]];
				}
				ans[i] = 2 * (right_sum - left_sum) + n - i;
				// cout << "case1\n";
			} else { // end left
				if (cur_r + l_cnt < r_pos.size() && r_pos[cur_r + l_cnt] + 1 < n) {
					right_sum -= r_psum[r_pos[cur_r + l_cnt] + 1];
				}
				ans[i] = 2 * (right_sum - left_sum) - i + 1;
				// cout << "case2\n";

			}
		} else {
			if (l_cnt > r_cnt) { // end right
				if (cur_l - r_cnt >= 0 && l_pos[cur_l - r_cnt] - 1 >= 0) {
					left_sum -= l_psum[l_pos[cur_l - r_cnt] - 1];
				}
				ans[i] = 2 * (right_sum - left_sum) + n + i;
				// cout << "case3\n";

			} else { // end left
				if (cur_r + l_cnt < r_pos.size()) {
					right_sum -= r_psum[r_pos[cur_r + l_cnt]];
				}
				ans[i] = 2 * (right_sum - left_sum) + i + 1;
				// cout << "case4\n";

			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';



}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t; cin >> t; while (t--) run();
	return 0;
}