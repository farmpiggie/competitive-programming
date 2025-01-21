#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> p(n), q(n);
	for (int& x : p) cin >> x;
	for (int& x : q) cin >> x;

	vector<int> a(n), b(n);
	ordered_set s;
	for (int i = 0; i < n; i++) s.insert(i);

	for (int i = 0; i < n; i++) {
		a[i] = s.order_of_key(p[i]);
		s.erase(p[i]);
	}

	for (int i = 0; i < n; i++) s.insert(i);

	for (int i = 0; i < n; i++) {
		b[i] = s.order_of_key(q[i]);
		s.erase(q[i]);
	}

	// addition
	vector<int> c(n);
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		c[i] = (a[i] + b[i] + carry) % (n - i);
		carry = (a[i] + b[i] + carry) / (n - i);
	}
	
	for (int i = 0; i < n; i++) s.insert(i);
	
	for (int i = 0; i < n; i++) {
		int x = *s.find_by_order(c[i]);
		cout << x << ' ';
		s.erase(x);
	}
	cout << '\n';
	return 0;
}	

