#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

#define MAXN 200005

int t, n;
pii a[MAXN] = {};

void update(int x, int val, vector<int>& BIT) { 
	++x;  
	while (x <= 2 * n) {  
		BIT[x]+=val;  
		x+=(x&-x);  
	} 
}

int query(int x, vector<int>& BIT) {  
	++x;  
	int res=0;  
	while(x > 0)  {  
		res += BIT[x]; 
		x -= (x & -x);  
	} 
	return res; 
} 

void solve() {
	cin >> n;

	vector<int> BIT(2 * n + 2, 0);

	set<int> coords;
	map<int, int> compress;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		coords.insert(a[i].first);
		coords.insert(a[i].second);
	}
	int cnt = 0;
	for (int x : coords) {
		compress[x] = cnt++;
	}
	for (int i = 0; i < n; i++) {
		a[i].first = compress[a[i].first];
		a[i].second = compress[a[i].second];
	}
	sort(a, a + n);

	// cout << "list:\n";

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].first << " " << a[i].second << '\n';
	// }

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pii p = a[i];
		// cout << 2 * n << " " << p.second << '\n';
		ans += query(2 * n, BIT) - query(p.second, BIT);
		// cout << '\n';

		update(p.second, 1, BIT);
	}
	cout << ans << '\n';






}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}