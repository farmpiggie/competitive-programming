#include <bits/stdc++.h>
using namespace std;

// seg tree with lazy prop template
// increment modifier, max query

template <typename T>
struct segtree_lazy {
  int n, h;
  vector<T> t, d;

  segtree_lazy(int sz) {
    n = sz;
    h = sizeof(int) * 8 - __builtin_clz(n);
    t = vector<T>(2 * n);
    d = vector<T>(n);
  }

  segtree_lazy(int sz, vector<T>& a) {
    n = sz;
    h = sizeof(int) * 8 - __builtin_clz(n);
    t = vector<T>(2 * n);
    d = vector<T>(n);

    for (int i = 0; i < n; i++) {
      t[n + i] = a[i];
    }
    build();
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void apply(int p, const T& value) {
	t[p] += value;
	if (p < n) d[p] += value;
  }

	void build(int p) {
	  while (p > 1) p >>= 1, t[p] = combine(t[p<<1], t[p<<1|1]) + d[p];
	}

	void push(int p) {
	  for (int s = h; s > 0; --s) {
	    int i = p >> s;
	    if (d[i] != 0) {
	      apply(i<<1, d[i]);
	      apply(i<<1|1, d[i]);
	      d[i] = 0;
	    }
	  }
	}

	void inc(int l, int r, const T& value) {
		r++;
	  l += n, r += n;
	  int l0 = l, r0 = r;
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) apply(l++, value);
	    if (r&1) apply(--r, value);
	  }
	  build(l0);
	  build(r0 - 1);
	}

	T query(int l, int r) {
		r++;
	  l += n, r += n;
	  push(l);
	  push(r - 1);
	  T resl = -2e9, resr = -2e9; // TODO: init
	  for (; l < r; l >>= 1, r >>= 1) {
	    if (l&1) resl = combine(resl, t[l++]);
	    if (r&1) resr = combine(t[--r], resr);
	  }
	  return combine(resl, resr);
	}

  T combine(const T& a, const T& b) {
    return max(a, b); // TODO: init
  }
};

#include <bits/stdc++.h>
using namespace std;


int main() {
  int n = 20;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    arr.push_back(i + 1);
  }

  segtree_lazy<int> st(n, arr);
  for (int i = 0; i < n; i++) {
    cout << st.query(i, i) << ' ';
  }
  cout << '\n';

  st.inc(0, 2, 5);

  for (int i = 0; i < n; i++) {
    cout << st.query(i, i) << ' ';
  }
  cout << '\n';


  return 0;
}