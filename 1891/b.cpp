#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int Q = 2e5 + 5;

int t, n, q; ll a[N], x[Q];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++) 
		cin >> x[i];

	vector<int> v;
	v.push_back(x[0]);

	for (int i = 1; i < q; i++) {
		if (v.back() > x[i]) 
			v.push_back(x[i]);
	}

	reverse(v.begin(), v.end());

	map<int, ll> mp;
	mp[0] = 0;

	for (int u : v) {
		auto it = mp.lower_bound(-u + 1);
		mp[-u] = 1ll * (1 << (u - 1)) + it->second;
		// for (pair<int, ll> p : mp) {
		// 	cout << p.first << " " << p.second << endl;
		// }
		// cout << "----\n";
	}

	for (int i = 1; i <= n; i++) {
		int div = 0, tmp = a[i];
		while (tmp % 2 == 0) {
			div++;
			tmp /= 2;
		}
		// cout << div << endl;
		a[i] += mp.lower_bound(-div)->second;
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}