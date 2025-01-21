#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
//		vector<vector<int>> adj(n, vector<int>(n, 0));
		vector<int> bigger(n); // check how many are before i
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == '1') { // p_i < p_j
					bigger[j]++; // another comes before j
				} else {
					bigger[i]++; // another comes before i
				}
			}
		}
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			ans[bigger[i]] = i + 1;
		}
		for (int x : ans) cout << x << " ";

		cout << '\n';
	}
}

		

