#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a = 0, b = 0; // dash, underscore
		while (n--) {
			char c; cin >> c;
			if (c == '-') a++;
			else b++;
		}
		cout << 1ll * (a / 2) * b * (a / 2 + (a & 1)) << '\n';
	}
}
