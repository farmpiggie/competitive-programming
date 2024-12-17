#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segtree {
  int n;
  vector<T> t;

  segtree(int sz) {
    n = sz;
    t = vector<T>(2 * n);
    build();
  }

  segtree(int sz, vector<T> a) {
    n = sz;
    t = vector<T>(2 * n);
    for (int i = 0; i < n; i++) {
      t[n + i] = a[i];
    }
    build();
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modify(int p, const T& value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = combine(t[p], t[p^1]);
  }

  T query(int l, int r) {  // query on interval [l, r]
    if (l > r) return INT_MIN;
    r++;
    T resl = INT_MIN, resr = INT_MIN; // TODO: change based on what you want to query on
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, t[l++]);
      if (r & 1) resr = combine(resr, t[--r]);
    }
    return combine(resl, resr);
  }

  T combine(const T& a, const T& b) {
    return max(a, b); // TODO: change based on what you want to query on
  } 
};

#define pii pair<long long, long long>
#define ll long long
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n), pre(n);
		for (ll& x : a) cin >> x;
		for (int i = 0; i < n; i++) pre[i] = a[i] + (!i ? 0 : pre[i - 1]);
		
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&pre](const int& a, const int& b) {
			return pre[a] == pre[b] ? a > b : pre[a] < pre[b];	
		});
		vector<int> indexToOrder(n);
		for (int i = 0; i < n; i++) {
			indexToOrder[order[i]] = i;
		}
		
		segtree<ll> st(n, vector<ll>(n, LLONG_MIN));

		ll prev;

		if (a[0] < 0) prev = -1; 
		else if (a[0] > 0) prev = 1;
		else prev = 0; 

		st.modify(indexToOrder[0], prev);
//		cout << "orz\n";
//		cout << prev << '\n';
//		cout << st.query(indexToOrder[0], indexToOrder[0]) << '\n';

		for (int i = 1; i < n; i++) {
			ll cur = prev;
			if (a[i] < 0) cur--;
			else if (a[i] > 0) cur++;
//			cout << "checking for " << i << ": " << pre[i] << '\n';
			if (pre[i] > 0) cur = max(cur, 1ll * i + 1);
//			cout << "querying from: " << indexToOrder[i] + 1 << '\n';
//			cout << "output: " << st.query(0, indexToOrder[i] - 1) << '\n';
//			cout << "i: " << i << '\n';
			cur = max(cur, i + st.query(0, indexToOrder[i] - 1));

			st.modify(indexToOrder[i], cur - i);
			prev = cur;
//			cout << "i: " << i << '\n';
//			cout << cur << '\n';
		}

		cout << prev << '\n';

	}
	return 0;
}
