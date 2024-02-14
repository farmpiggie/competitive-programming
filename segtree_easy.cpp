template <typename T>
struct segtree {
  int n;
  vector<T> t;

  // utility to build
  void build() {
    for (int i = n - 1; i > 0; --i) {
      t[i] = max(t[i<<1], t[i<<1|1]);
    }
  }

  segtree(int sz) {
    n = sz;
    t = vector<T>(2 * n + 2, 0);
  }

  segtree(int sz, vector<T>& init) {
    segtree(sz);
    for (int i = 0; i < (int) init.size(); i++) {
      t[n + i] = init[i];
    }
    build();
  }

  // sum on interval [l, r], caree for posible overflow using INT
  T query(int l, int r) {
    r++;
    T res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }

  // a[p] = value
  void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }
};
 


// build seg trees