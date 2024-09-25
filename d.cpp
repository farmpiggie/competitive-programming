// len = n + nC2 + 1
// 7?
// 3 unique
// 1 1 2 2 3 3 1
// 4 unique
// 11?
// 1 1 2 2 5 3 3 5 5 1 3 
// 1 2 3 5 1 3
// 5 1 1 2 2 3 3 5 5 2
// 5 unique
// 5 1 1 2 2 7 3 3 5 5 7 7 1 3 2 5
// 6 unique = 6 + 15 + 1 = 22
// 1 1 2 2 3 3 4 4 5 5 6 6
// 1 1 -
// 2 2 -
// 3 3 -
// 5 5 - 
// 1 2 -
// 1 3 
// 1 5
// 2 3 -
// 2 5
// 3 5 -
#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	set<int> s;
	for (int i = 1; i < n; i++) {
		if (s.find(a[i] * a[i - 1]) != s.end()) {
			cout << "failed: (" << i - 1 << ", " << i << "): " << a[i] * a[i - 1] << '\n';
		}
		s.insert(a[i] * a[i - 1]);
	}
	cout << ((int) s.size() == n - 1) << '\n';
	return 0;
}
