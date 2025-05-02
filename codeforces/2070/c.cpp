/*
 * all blocks start off red. we can only paint squares blue.
 * idea: binary search on answer
 * lets say we want to target ans = x.
 * therefore, we must satisfy condition for all a[i] > x.
 * we will color all:
 * 1. blue positions with a[i] > x
 * 2. red positions with a[i] <= x
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		/*char cur_color = s[0];
		int cur_max = a[0];
		vector<int> b;
		string t = "";
		for (int i = 0; i < n; i++) {
			if (cur_color == s[i]) {
				cur_max = max(cur_max, a[i]);
			} else {
				b.push_back(cur_max);
				t += cur_color;
				cur_max = a[i];
			}
			cur_color = s[i];
		}
		t += cur_color;
		b.push_back(cur_max);
		s = t;
		a = b;


		n = a.size();
		*/
		//cout << s << '\n';
		//for (int x : a) cout << x << ' ';
		//cout << '\n';

		int l = 0, r = 1e9;
		int ans = r;
		while (l <= r) {
			int m = (l + r) / 2;
			int cur = 0;
			vector<bool> color(n, 0);
			//cout << "m: " << m << '\n';
			for (int i = 0; i < n; i++) {
				if ((s[i] == 'B') || (s[i] == 'R' && a[i] <= m)) { // can color
					color[i] = 1;
				}
			}
			//for (bool b : color) cout << b << " ";
			//cout << '\n';
			int blue = 0;
			bool flag = false;
			for (int i = 0; i < n; i++) {
				if (color[i]) {
					if (s[i] == 'B' && a[i] > m) blue++;
					flag = true;
				} else {
//					cout << "checking blue zero: " << blue << '\n';
					if (blue > 0) cur++;
					blue = 0;
					flag = false;
				}
			}
			if (flag && blue > 0) cur++;
			//cout << m << " " << cur << '\n';
			if (cur <= k) {
				ans = min(ans, m);
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << ans << '\n';




		
	}
}




