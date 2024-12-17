#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 200005
#define K 25

ll t, n, a[MAXN], b[MAXN];

int t1[2 * MAXN], t2[2 * MAXN];

int aquery(int l, int r) {  // sum on interval [l, r)
	r++; // make it inclusive to r
  int res = INT_MIN;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t1[l++]);
    if (r&1) res = max(res, t1[--r]);
  }
  return res;
}

int bquery(int l, int r) {  // sum on interval [l, r)
	r++; // mak it inclusive to r
  int res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t2[l++]);
    if (r&1) res = min(res, t2[--r]);
  }
  return res;
}



void solve() {
	map<int, set<int>> apos;
	cin >> n;
	// read a
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		apos[a[i]].insert(i);
		t1[n + i] = a[i]; 
	}	

	// build t1
	for (int i = n - 1; i > 0; --i) {
	    t1[i] = max(t1[i<<1], t1[i<<1|1]);
	}

	// read b
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		t2[n + i] = b[i];
	}

	// build t2
	for (int i = n - 1; i > 0; --i) {
	    t2[i] = min(t2[i<<1], t2[i<<1|1]);
	}

	for (int i = 0; i < n; i++) {
		bool works = false;

		if (a[i] == b[i]) continue;

		// search for nearest b[i] target
		auto it = apos[b[i]].lower_bound(i);
		if (it != apos[b[i]].end()) { // right bound
			int j = *it;
			ll max_a = aquery(i, j);
			ll min_b = bquery(i, j);

			if (max_a <= a[j] && min_b >= a[j]) {
				works = true;
			}
		}
		if (it != apos[b[i]].begin()) { // left bound
			--it;
			int j = *it;
			ll max_a = aquery(j, i);
			ll min_b = bquery(j, i);
			if (max_a <= a[j] && min_b >= a[j]) {
				works = true;
			}
		}

		if (!works) return cout << "No\n", void();
	}
	return cout << "Yes\n", void();
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}