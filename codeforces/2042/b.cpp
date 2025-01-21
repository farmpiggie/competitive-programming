// alice and bob will target balls with one color only, there are x of them
// alice therefore gets (x + 1) / 2 * 2 points from this, and x turns will be performed
// after this, alice and bob will fight over balls with 
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> mp; // mp[color] = cnt
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
		}
		
		int score = 0;
		int zeros = 0;
		for (auto& [_, y] : mp) {
			--y;
			if (y == 0) zeros++;
		}
		score = (zeros + 1) / 2 * 2 + (int) mp.size() - zeros; // take half the ones along with everything else
		cout << score << '\n';
	}
}
