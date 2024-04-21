// result expression is odd = can we make it so that one clause is true only?
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<bool> arr(n + 1, 0);
		for (int i = 0; i < m; i++) {
			string s;
			getline(cin, s);
			stringstream ss; ss << s;
			int val;
			while (ss >> val) {
				if (!i) arr[val] = 1;
				
			}
		}
	}
}
