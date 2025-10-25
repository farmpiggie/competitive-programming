// 1 0 0 
// 1 1 0
// 1 1 2
// 2 2 1
// 2 2 4
// 2 4 4 
// 4 4 4
//
// 1 -> 3
// 2 -> 5
// 4 -> 7
//
// 0 -> 3
// 1 -> 5
// 2 -> 7
//
// y = ceil(log2(x))
// ans = y * 2 + 3
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		int y = 0;
		while (x >= 2) {
			y++;
			x /= 2;
		}
		cout << y * 2 + 3 << '\n';
	}
}