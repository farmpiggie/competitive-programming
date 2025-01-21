/*
 * create array of length n such that:
 * 1 <= a[i] <= n
 * # of palindromic subsequences with maximal length > n
 * construction is 1 1 2 .... 1 2
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << "1 1 2 ";
		for (int i = 0; i < n - 5; i++) {
			cout << i + 3 << ' ';
		}
		cout << "1 2\n";
	}
}
