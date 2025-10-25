// 1 3 2 -> 1 2 
// 1 5 4 3 2
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << 1 << ' ';
		for (int i = n; i > 1; i--) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}