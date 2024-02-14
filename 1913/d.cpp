#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define MOD 998244353

typedef long long ll;

int t, n, a[MAXN], st[2 * MAXN];

int query(int l, int r) {
	r++;
	int res = INT_MAX;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, st[l++]);
    	if (r&1) res = min(res, st[--r]);
	}
	return res;
}

ll recurse(int l, int r, int dir, map<int, int>& pos) {
	if (l > r) return 1; // empty set
	int idx = pos[query(l, r)]; // position of smallest element along range
	ll left = recurse(l, idx - 1, dir | 1, pos);
	ll right = recurse(idx + 1, r, dir | 2, pos);
	ll ret = (left * right) % MOD;
	if (dir & 1) ret = (ret + left) % MOD;
	if (dir & 2) ret = (ret + right) % MOD;
	if (dir == 3) ret = (ret - 1 + MOD) % MOD;
	return ret;
}



void solve() {
	cin >> n;
	map<int, int> pos;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
		st[n + i] = a[i];
	}
	// build seg tree
	for (int i = n - 1; i > 0; --i) {
    	st[i] = min(st[i<<1], st[i<<1|1]);
	}
	cout << recurse(0, n - 1, 0, pos) << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}