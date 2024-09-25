#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree {
	int n;
	vector<T> t;

	segtree(int sz) {
		n = sz;
		t = vector<T>(2 * n, 0);
		build();
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

#define ll long long



ll n;
vector<int> a, b, c;
vector<int> ta, tb, tc;

ll inversion_count(vector<int>& arr) {
	segtree<ll> st(n + 1);
	
	ll ans = 0;
	for (int i = 0; i < (int) arr.size(); i++) {
		ans += st.query(arr[i] + 1, n);
		st.modify(arr[i], 1);
	}
	return ans;
}

int main() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	ta.resize(n + 1);
	tb.resize(n + 1);
	tc.resize(n + 1);
	int i = 1;
	for (int &x : a) {
		cin >> x;
		ta[x] = i++;
	}

	i = 1;
	for (int &x : b) {
		cin >> x;
		tb[x] = i++;
	}

	i = 1;
	for (int &x : c) {
		cin >> x;
		tc[x] = i++;
	}

	ll ans = 0;
	// compare a and b
	vector<int> change_b(n);
	for (int i = 0; i < n; i++) {
		change_b[i] = ta[b[i]];
	}

	// for (int &x : change_b) cout << x << '\n';
	ll inv_b = inversion_count(change_b);
	ans += inv_b;
	// b and c

	vector<int> change_c(n);
	for (int i = 0; i < n; i++) {
		change_c[i] = tb[c[i]];
	}

	// for (int &x : change_c) cout << x << '\n';
	ll inv_c = inversion_count(change_c);
	ans += inv_c;
	// c and a



	vector<int> change_a(n);
	for (int i = 0; i < n; i++) {
		change_a[i] = tc[a[i]];
	}

	// for (int &x : change_a) cout << x << '\n';
	ll inv_a = inversion_count(change_a);
	ans += inv_a;


	cout << n * (n - 1) / 2 - ans / 2 << '\n';



	return 0;
}