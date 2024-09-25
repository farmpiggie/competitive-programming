#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_segtree {
  int n;
  vector<T> t;

  min_segtree(int sz) {
    n = sz;
    t = vector<T>(2 * n);
  }

  min_segtree(int sz, vector<T>& a) {
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
    T resl = INT_MAX, resr = INT_MAX; // TODO: initialize
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, t[l++]);
      if (r & 1) resr = combine(resr, t[--r]);
    }
    return combine(resl, resr);
  }

  T combine(const T& a, const T& b) {
    return min(a, b); // TODO: initialize
  }
};

template <typename T>
struct max_segtree {
  int n;
  vector<T> t;

  max_segtree(int sz) {
    n = sz;
    t = vector<T>(2 * n);
  }

  max_segtree(int sz, vector<T>& a) {
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
    return max(a, b); // TODO: initialize
  }
};





int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		set<int> s2;
		for (int& x : a) s2.insert(x);
		int len = (int) s2.size();

		min_segtree<int> min_st(n, a);
		max_segtree<int> max_st(n, a);

		// cout << "hello\n";

		vector<int> last_occ(n + 1, 0);
		map<int, vector<int>> mp; // mp[i] = list of indices of numbers that are i
		for (int i = 0; i < n; i++) {
			last_occ[a[i]] = i;
			mp[a[i]].push_back(i);
		}
		set<int> s; // stores last occurrences of all 1 <= x <= n

		for (int val : s2) {
			s.insert(last_occ[val]);
		}

			// for (int val : s) cout << val << '\n';
		
		// cout << "boop\n";
		vector<int> ans;
		int cur_index = -1;

		for (int i = 0; i < len; i++) {
			int num;
			if (ans.size() % 2 == 0) { // looking for max number
				num = max_st.query(cur_index + 1, *s.begin()); // biggest number here
			} else {
				// cout << cur_index + 1 << " " << *s.begin() << '\n';
				num = min_st.query(cur_index + 1, *s.begin()); // smallest number here
			}
			// cout << "chose value: " << num << '\n';
			s.erase(last_occ[num]);
			// delete values
			for (int index : mp[num]) {
				// cout << index << '\n';
				min_st.modify(index, INT_MAX);
				max_st.modify(index, 0);
			}
			// cout << "here\n";
			int dist = lower_bound(mp[num].begin(), mp[num].end(), cur_index + 1) - mp[num].begin();
			cur_index = *lower_bound(mp[num].begin(), mp[num].end(), cur_index + 1); // first value before the left hand side i think
			// cout << "current index: " << cur_index << '\n';
			ans.push_back(num);
		}
		cout << ans.size() << '\n';
		for (int val : ans) cout << val << " ";
		cout << '\n';\

	}
	return 0;
}