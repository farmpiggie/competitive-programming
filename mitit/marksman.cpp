// even sum of A_i results in NO
// strategy: any lane can be represented as (1 or 2) for (a_i - 1) times and then a 1. 
// can we simply check if # lanes
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ones = 0;
		int odds = 0;
		vector<int> a(n);
		int sum = 0;
		int actual_lanes = 0;
		for (int& x : a) {
			cin >> x;
			if (x == 0) continue;
			sum += x - 1; 
			actual_lanes++;
		}
		// cout << "hi\n";
		// cout << (sum + n) << '\n';
		// cout << flush;
		if ((sum + actual_lanes) % 2 == 0) cout << "NO\n";
		else if (actual_lanes - 1 <= sum) {
			cout << "YES\n";
			queue<int> ones;
			queue<int> notones;
			for (int i = 0; i < n; i++) {
				if (a[i] == 0) continue;
				if (a[i] == 1) ones.push(i + 1);
				else notones.push(i + 1);
			}
			int odd = 1;
			for (int i = 0; i < (sum + actual_lanes); i++) {
				if (i % 2 == 0) {
					if (ones.size() > 0) {
						cout << ones.front() << ' ';
						ones.pop();
					} else {
						cout << notones.front() << ' '; 
						a[notones.front() - 1]--;
						if (a[notones.front() - 1] == 1) {
							ones.push(notones.front());
							notones.pop();
						}
					}
				} else {	
					cout << notones.front() << ' '; 
					a[notones.front() - 1]--;
					if (a[notones.front() - 1] == 1) {
						ones.push(notones.front());
						notones.pop();
					}
				}
			}
			cout << '\n';
		} else {
			cout << "NO\n";
		}
		//cout << "done\n";
		//cout << flush;
	}
	return 0;
}
