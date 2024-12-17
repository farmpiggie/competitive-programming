// all segments must be 0s or 1s except on segment, but one segment can contain a zero to a one
// answer is # of times 1 -> 0 or 0 -> 1 minus one time 0 -> 1
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();
		int zero_to_one = 0, one_to_zero = 0;
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == '0' && s[i] =='1') zero_to_one++;
			if (s[i - 1] == '1' && s[i] == '0') one_to_zero++;
		}
		cout << max(0, zero_to_one - 1) + one_to_zero + 1 << '\n';
	}
}
