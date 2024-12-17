#include <bits/stdc++.h>
using namespace std;

int arr[32] = {0};

void solve() {
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int t, v; cin >> t >> v;
		if (t == 1) {
			arr[v]++;
		} else {
			for (int j = 29; j >= 0; j--) {
				int val = (1 << j);
				if (v >= val) {
					int cnt = v / val;
					v -= (val * min(arr[j], cnt));
				}
			}
			if (v == 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() {
	solve();

	return 0;
}