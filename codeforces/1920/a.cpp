#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	int smallest = 0, biggest = INT_MAX;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int a, x; cin >> a >> x;
		if (a == 1) {
			smallest = max(smallest, x);
		} 
		if (a == 2) {
			biggest = min(biggest, x);
		}
		if (a == 3) {
			s.insert(x);
		}
	}
	int ans = (biggest - smallest + 1);
	for (int num : s) {
		if (smallest <= num && num <= biggest) {
			ans--;
		}
	}
	// cout << smallest << " " << biggest << '\n';
	cout << max(0, ans) << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}