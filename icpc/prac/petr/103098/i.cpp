/*
 * info we are given:
 * max # of outdegrees for each node
 * requirements:
 * 1. total edges >= n - 1
 * 2. out[0] >= 1
 * 3. 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		vector<int> out(n);
		for (int i = 0; i < n; i++) {
			out[i] = b[i] - a[i];
		}
		if (n == 1) {
			cout << "YES\n";
		} else if (out[0] == 0 || (n == 2 && out[1] > 0)) {
			cout << "NO\n";
		} else {
			int sum = 0;
			for (int i = 1; i < n; i++) {
				sum += out[i];
				sum = min(sum, n - 2);
			}
			int need = n - 1 - sum;
			cout << (out[0] < need ? "NO" : "YES") << '\n';
		}
	}
}

		
