#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int y; cin >> y;
			sum += y;
		}
		
		cout << ((sum % x == 0 && sum / n == x) ? "YES" : "NO") << '\n';
	}
}
	