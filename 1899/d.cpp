#include <bits/stdc++.h>
using namespace std;

int t, n;

typedef long long ll;

// pair(a, b) = pair(b, a)
// 2^b^(2^a) = 2^(b * 2^a)
// 2^a^(2^b) = 2^(a * 2^b)
// check if b * 2^a = a * 2^b
// 2^a/a = 2^b/b

// 2 ^ (a_i * 2^a_j) = 2 ^ (a_j * 2^a_i)
// a_i * 2^a_j = a_j * 2^a_i
// 1: 1 (0)
// 2: 4 (6)
// 3: 1 (0)
// 4: 3 (3)
// 5: 2 (1)
// 6: 2 (1)
// 7: 1 (0)
// 8: 2 (1)
// 9: 0
// 10: 3 (3)
// any 1 with any 2: 4
// 

// calculation for number count: n * (n - 1) / 2
void solve() {
	cin >> n;
	int a;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mp[a]++; 
	}	

	ll ans = 0;
	for (pair<int, int> p : mp) {
		if (p.second > 1) ans += 1ll * p.second * (p.second - 1) / 2;
	}


	if (mp.find(1) != mp.end() && mp.find(2) != mp.end()) {
		ans += 1ll * mp[1] * mp[2];
	}
	cout << ans << '\n';

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}