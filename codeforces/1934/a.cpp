#include <bits/stdc++.h>
using namespace std;

void run() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	cout << (a[n - 1] - a[0]) + (a[n - 2] - a[0]) + (a[n - 2] - a[1]) + (a[n - 1] - a[1]) << '\n';	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
	return 0;
}