/*
can flip a substring such that: 
1. # of ')' = # of '('
2. let # '(' - ')' in substring equal to x. the number of ')' - '(' in substring cannot exceed x

thought process:
OK, how can I define this using a data structure I know? aka an array or smth
use prefix sum of '(' - ')', we can check for two things
substring l, r is good if:
pre[r] = pre[l - 1] // same # of '(' and ')'
pre[l - 1] >= pre[i] - pre[l - 1] for all i, so when we flip it doesnt invert

store all of the same prefix in a map. to satisfy second condition, we can remove any keys s.t. key * 2 < b, so that we cant end up using it (as a substring from that key to a future r passes through this "hump" that is too high anyways cause it goes negative)

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		map<int, int> mp;
		int b = 0;
		mp[b] = 1;
		ll ans = 0;
		for (char& c : s) {
			b += (c == '(') ? 1 : -1;
			ans += mp[b];
			++mp[b];
			while (mp.begin()->first * 2 < b) mp.erase(mp.begin());
		}
		cout << ans << '\n';
	}
}
