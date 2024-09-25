#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		// if string has "mapie", remove the p
		// if string has "map", remove the a
		// if string has "pie", remove the i
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n - 2; i++) {
			if (s.substr(i, 3) == "map") {
				a++;
			}
		} 
		for (int i = 0; i < n - 2; i++) {
			if (s.substr(i, 3) == "pie") {
				b++;
			}
		} 
		for (int i = 0; i < n - 4; i++) {
			if (s.substr(i, 5) == "mapie") {
				c++;
			}
		}
		cout << a + b - c << '\n'; 
	}
}
