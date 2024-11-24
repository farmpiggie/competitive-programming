/*
query (1, 2), (1, 3)...(1, n)

if (1, 2) is 1, then you know s[1...2] = 01
otherwise, s[1...2] can be 10, 00, or 11

query (1, 3)
if (1, 2) is 1, we can easily determine whether or not s[3] is 0 or 1 based on whether or not query(1, 3) > query(1, 2)
if (1, 2) is 0:
	if query(1, 3) is 2, we know that the string is [001]
	if query(1, 3) is 1, we know that the string is [101]
	if query(1, 3) is 0, the string could either be [000] or [111] or [110].

consider the case where the queries continue to be zero.
let us say that queries 2...x - 1 are zero, but x is non-zero.
say query(1, x) = y.
string must be [x - y - 1 ones][y zeros][1].

*/

#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
	cout << "? " << l << " " << r << '\n';
	int x; cin >> x;	
	return x;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s = "";
		int prev = ask(1, 2);
		if (prev) {
			s = "01";
		} 

		for (int i = 3; i <= n; i++) {
			int res = ask(1, i);
			if (res != 0) {
				if (prev == 0) {
					for (int j = 0; j < (i - res - 1); j++) s += "1";
					for (int j = 0; j < res; j++) s += "0";
					s += "1";
				} else if (prev == res) {
					s += "0";
				} else {
					s += "1";
				}
			}
			prev = res;
		}	

		cout << "! " <<  (prev == 0 ? "IMPOSSIBLE" : s) << '\n';
	}
	return 0;
}
