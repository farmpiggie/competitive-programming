#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
	// ifstream cin("hossamcombinatorics.in");
	int t; cin >> t;
	ll a;
	while (t--) {
		ll n; cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		map<ll, ll> mp;
		for (int i = 0; i < n; i++) {
			if (mp.count(a[i])) mp[a[i]]++;
			else mp[a[i]] = 1;
		}
		if (a[0] == a[n - 1]) cout << n * (n - 1) << endl;
		else cout << mp[a[0]] * mp[a[n - 1]] * 2 << endl;
	}
}