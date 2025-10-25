#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	// ifstream cin("banban.in");
	int t; cin >> t;
	while (t--) {
		// swap B with all the As in the back
		int n; cin >> n;
		string s = "";
		for (int i = 0; i < n; i++) {
			s += "BAN";
		}

		int count = 0;
		vector<pii> swaps;
		int curr_b = 0;
		for (int i = 3 * n - 1; count < n && i >= 0; i--) {
			if (s[i] == 'B') {
				count++;
			} else if (s[i] == 'A') { // swap with a B
				swap(s[i], s[curr_b]);
				swaps.push_back({curr_b + 1, i + 1});
				curr_b += 3;
				count++;
			}
		}
		cout << swaps.size() << endl;
		for (pii p : swaps) {
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}