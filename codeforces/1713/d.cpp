#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int x; cin >> x;
	return x;
}

// solve for x = 2 with leaves a, b, c, d
int solve(int a, int b, int c, int d) {
	int x = query(b, c); // b and c must be in diff subtree
	int y;
	if (x == 0) {
		y = query(a, d);
		if (y == 1) return a;
		else return d;
	} else if (x == 1) {
		y = query(b, d);
		if (y == 1) return b;
		else return d;
	} else { // x == 2
		y = query(a, c);
		if (y == 1) return a;
		else return c;
	}
}

void print(int x) {
	cout << "! " << x << endl;
}



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> ans((1 << n));
		iota(ans.begin(), ans.end(), 1); // fill from 1...2^n
		while (ans.size() > 2) {
			vector<int> ans2;
			for (int i = 0; i < (int) ans.size(); i += 4) {
				int res = solve(ans[i], ans[i + 1], ans[i + 2], ans[i + 3]);
				ans2.push_back(res);
			}
			ans = ans2;
		}
		if (ans.size() == 2) {
			int res = query(ans[0], ans[1]);
			print((res == 1 ? ans[0] : ans[1]));
		} else {
			print(ans[0]);
		}
	}
	return 0;
}
			

