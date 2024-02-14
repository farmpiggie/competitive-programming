#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int> 

void solve() {
	pii pts[4];
	for (int i = 0; i < 4; i++) {
		cin >> pts[i].first >> pts[i].second;
	}
	int x, y;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (pts[i].first == pts[j].first) {
			x = abs(pts[i].second - pts[j].second);
			} else {
				y = abs(pts[i].first - pts[j].first);
			}
		}
	}
	cout << x * y << '\n';

}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}