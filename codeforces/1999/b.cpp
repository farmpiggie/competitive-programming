/*
a1 <= a2, b1 <= b2
*/
#include <bits/stdc++.h>
using namespace std;

bool win(int a1, int b1, int a2, int b2) {
	int cnt = 0;
	if (a1 > b1) cnt++;
	else if (a1 < b1) cnt--;
	if (a2 > b2) cnt++;
	else if (a2 < b2) cnt--;
	return cnt >= 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		int ans = 0;
		ans += win(a1, b1, a2, b2);
		ans += win(a1, b2, a2, b1);
		ans += win(a2, b1, a1, b2);
		ans += win(a2, b2, a1, b1);
		cout << ans << endl;
	}
	return 0;
}