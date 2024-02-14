#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int t, n, k; string s;

void solve() {
	cin >> n >> k >> s;
	unordered_map<char, int> mp;
	for (const char& c : s)
		mp[c]++;

	int odd = 0, even = 0;
	for (const pair<char, int>& p : mp)
		if (p.second % 2 == 1) odd++;
		else even++;

	if ((n - k) % 2 == 0) { // all even
		k -= odd;
	} else { // one odd, rest even
		if (odd == 0) k--; // change one even number to odd
		else if (odd > 1) k -= (odd - 1); // remove extra odd values
	}

	// cout << "k: " << k << endl;

	if (k < 0) cout << "No\n";
	else if (k % 2 == 0) cout << "Yes\n";
	else cout << "No\n";


}

int main() {
	cin >> t;
	while (t--) solve();

	return 0;
}