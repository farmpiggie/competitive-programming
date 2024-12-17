#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << (int) log2(r) << '\n';
	}
}
