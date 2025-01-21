#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> l(n), r(n);
		vector<char> s(n);	
		for (char& c : s) cin >> c;
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
			--l[i]; --r[i];
		}

		auto dfs = [&](this auto dfs, int node, int weight = 0) -> int {
			if (l[node] == -1 && r[node] == -1) return weight; // leaf
			int lp = (l[node] == -1 ? INT_MAX : dfs(l[node], weight + (s[node] != 'L')));
			int rp = (r[node] == -1 ? INT_MAX : dfs(r[node], weight + (s[node] != 'R'))); // right edge cost
			return min(lp, rp);
		};

		cout << dfs(0) << '\n';
	}
}

		
