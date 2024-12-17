#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
	   	string a, b; cin >> a >> b;
		int len = 0;
		for (int i = 0; i < m; i++) {
			if (len < n && a[len] == b[i]) {
				len++;
			}
		}
		cout << len << '\n';	
	}
	return 0;
}
