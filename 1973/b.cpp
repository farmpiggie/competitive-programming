// find smallest value k s.t. bitwise OR of each subarray of size k is equal// means the bits set must be of some subset
// for each of 20 bits, keep track of largest distance between two elements with that bit set
// take max of all 20 bits (if bit is never set, mark as -1
#include <bits/stdc++.h>
using namespace std;

// 1 0 2

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		vector<int> last(20, -1);
		vector<int> dist(20, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 20; j++) {
				int bit = (a[i] >> j) & 1;
				if (bit) {
					dist[j] = max(dist[j], i - last[j]);
					last[j] = i;
				}
			}
		}
		int ans = 1;
		for (int i = 0; i < 20; i++) {
			//cout << dist[i] << " ";
			if (last[i] != -1) ans = max(ans, max(dist[i], n - last[i]));
		}
		//cout << '\n';
		cout << ans << '\n';

	}
	return 0;
}
