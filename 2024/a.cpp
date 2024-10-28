#include <bits/stdc++.h>
using namespace std;

/*
if she starts with a coins, b cost to open min
if a >= b, ans = a
otherwise if a < b, then we want to spend min x s.t. a - x >= b - 2 * x 
a - x >= b - 2 * x
a + x >= b
x >= b - a
*/

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a >= b) cout << a << '\n';
		else cout << max(0, a - (b - a)) << '\n';
	}
	return 0;
}