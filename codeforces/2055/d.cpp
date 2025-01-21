#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k, l; cin >> n >> k >> l;
		k *= 2;
		l *= 2;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
			x *= 2;
		}

		int time = a[0];
		int pos = k;
		for (int i = 1; i < n; i++) {
			int x = a[i];
			if (x > pos) { // scarecrow move left
				x = max(pos, x - time); // try to move scarecrow onto crow if possible
				time += (x - pos) / 2; // this is how much time it takes
				x -= (x - pos) / 2; // this is how much scarecrow is moved to left.
			} else { // scarecrow move right
				x = min(pos, x + time); // either move into jump position (or as close as we can make it) 
			}
			pos = x + k;
		}
		time += max(0, l - pos);
		cout << time << '\n';
	}
	return 0;
}

