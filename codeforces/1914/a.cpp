#include <bits/stdc++.h>
using namespace std;

#define MAXN 501

int t, n, b[26];

void solve() {
	cin >> n;
	int ans = 0;

	for (int i = 0; i < 26; i++) {
		b[i] = (i + 1);
	}

	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		b[(c - 'A')]--;
		if (b[(c - 'A')] == 0) {
			ans++;
		}
	}
	cout << ans << '\n';
}



int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}