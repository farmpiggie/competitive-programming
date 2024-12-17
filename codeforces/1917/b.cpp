// can either remove first or second character of a string
// print # of distinct strings you can get by doing this operation as many times as you want
// all strings created are basically (one character) + (some suffix of the array)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		unordered_map<char, int> mp;
		int n; cin >> n;
		vector<char> a(n);
		for (char& x : a) {
			cin >> x;
			mp[x]++;
		}
		ll ans = (int) mp.size();
		for (int i = n - 1; i >= 0; i--) {
			mp[a[i]]--;
			if (mp[a[i]] == 0) mp.erase(a[i]);
			ans += (int) mp.size();
		}
		cout << ans << '\n';
	}
	return 0;
}
