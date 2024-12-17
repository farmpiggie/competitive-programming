#include <bits/stdc++.h>
using namespace std;

int t, n;

// if a[i] != b[i]
// 	if a[i] != c[i] or b[i] != c[i], we can make it upper(c[i]) and the value is true
// 	if a[i] == c[i] or b[i] == c[i], we are forced to make the letter upper(x) where x doesnt equal any of the three letters
// if a[i] == b[i], we need t[i] == a[i] == b[i] 
// 	if a[i] != c[i] here, we can set our value to true.


string a, b, c;
void solve() {
	cin >> n >> a >> b >> c;
	bool works = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			if (a[i] != c[i]) {
				works = true;
			}
		} else {
			if (a[i] != c[i] && b[i] != c[i]) {
				works = true;
			}
		}
	}
	if (works) cout << "YES\n";
	else cout << "NO\n"; 
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}