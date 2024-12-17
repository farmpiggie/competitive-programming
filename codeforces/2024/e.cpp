#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define v2i vector<vi>

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi out1(n), out2(n);
		v2i adj1(n), adj2(n);
		for (int& x : out1) cin >> x;
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			adj1[x].push_back(y);
		}
		for (int& x : out2) cin >> x;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			--x; --y;
			adj2[x].push_back(y);
		}

		// for all possible colorings, see if we can make n pairs?
		vi color1(n), color2(n);
		



	}
	return 0;
}