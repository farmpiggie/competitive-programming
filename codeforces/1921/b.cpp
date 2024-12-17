#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n;
	string s, f;

	cin >> n >> s >> f;

	int start = 0, end = 0;
	int correctPos = 0;

	for (int i = 0; i < n; i++) {

		if (s[i] == '1') {
			start++;
		}

		if (f[i] == '1') {
			end++;
		}

		if (s[i] == '1' && f[i] == '1') {
			correctPos++;
		}
	}

	if (start > end) { // remove extras and move those not into correct positions into correct positions
		cout << (start - end) + (end - correctPos) << '\n';
	} else { // add extras into correct positions and then move the rest in
		cout << (end - start) + (end - (correctPos + (end - start))) << '\n';
	}


}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}