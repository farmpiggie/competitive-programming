#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree {
  int n;
  vector<T> t;

  segtree(int sz) {
    n = sz;
    t = vector<T>(2 * n);
  }

  segtree(int sz, vector<T>& a) {
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

  void inc(int p, const T& value) {  // increment value at position p
    for (t[p += n] = combine(value, t[p]); p > 1; p >>= 1) t[p>>1] = combine(t[p], t[p^1]);
  }

  T query(int l, int r) {  // query on interval [l, r]
    r++;
    T resl = 0, resr = 0; // TODO: initialize
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, t[l++]);
      if (r & 1) resr = combine(resr, t[--r]);
    }
    return combine(resl, resr);
  }

  T combine(const T& a, const T& b) {
    return a + b; // TODO: initialize
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

  segtree<int> st(n, arr);
  for (int i = 0; i < n; i++) {
    cout << st.query(i, i) << ' ';
  }
  cout << '\n';

  st.modify(0, 2);

  for (int i = 0; i < n; i++) {
    cout << st.query(i, i) << ' ';
  }
  cout << '\n';


  return 0;
}