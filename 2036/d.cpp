#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string> a(n); // n rows
		for (string& s : a) cin >> s;

		// first value we start at is a[i][i]
		// the "segment" of the horizontal layer is of length 
		auto layer = [&](int i) {
			// segment from top left going right
			int row_length = m - 1 - 2 * i;
			int col_length = n - 1 - 2 * i;
			string s = "";
			s = s + a[i].substr(i, row_length);
			// segment from top right going down of length: (n - 1 - 2 * i)
			// col value: m - 1 - i
			// row values: from a[i] down to a[i + (n - 1 - 2 * i - 1)]
			for (int r = i; r < i + (col_length); r++) {
				s = s + a[r][m - 1 - i];
			}
			// bottom right going left
			string temp = a[n - 1 - i].substr(i + 1, row_length);
			reverse(temp.begin(), temp.end());
			s = s + temp;
			// bottom left going up
			// col value: i
			// row value: go from n - 1 - i, up col_length values
			for (int r = n - 1 - i; r > n - 1 - i - col_length; r--) {
				s = s + a[r][i];
			}
			return s;
		};

		ll ans = 0;

		for (int i = 0; i < min(n / 2, m / 2); i++) {
			string s = layer(i);
			//cout << s << '\n';
			int orig_len = s.length();
			s = s + s; // double wrap
			vector<ll> psum(s.length(), 0);
			for (int i = 3; i < s.length(); i++) {
				psum[i] = psum[i - 1];
				if (s.substr(i - 3, 4) == "1543") psum[i]++; // add 1
			}
			ll actual = psum[orig_len - 1];
			for (int i = orig_len; i < s.length(); i++) actual = max(actual, psum[i] - psum[i - orig_len]);
			ans += actual;
		}
		cout << ans << '\n';
	}
	return 0;
}