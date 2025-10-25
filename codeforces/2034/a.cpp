/*
 * m >= min(a, b)
 * a % m == b % m
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
}