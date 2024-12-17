#include <bits/stdc++.h>
using namespace std;

// smallest number is always chosen
// then the second smallest number not divisble

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		sort(a.begin(), a.end());

		vector<bool> works(n, 0);
		works[0] = 1;
		int start = -1;
		for (int i = 1; i < n; i++) {
			if (a[i] % a[0] == 0) works[i] = 1;
			else if (start == -1) start = i;
		}
		if (start == -1) { // all values are divisble by a[0]
			cout << "Yes\n";
			continue;
		}
		works[start] = true; // this is our second divisor
		for (int i = start + 1; i < n; i++) {
			if (a[i] % a[start] == 0) works[i] = 1; 
		}
		bool yes = true;
		for (int i = 0; i < n; i++) {
			if (!works[i]) yes = false;
		}
		if (yes) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
