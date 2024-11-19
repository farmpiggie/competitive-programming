#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<set<int>> a(n); 
		map<int, int> occ;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			for (int j = 0; j < k; j++) {
				int x; cin >> x;
				a[i].insert(x);
				occ[x]++;
			}
		}

		int ans = 0;
		// if i choose to remove a particular number, how many sets do i have left
		for (int i = 1; i <= 50; i++) {
			map<int, int> occ2;
			for (int j = 0; j < n; j++) {
				if (a[j].find(i) != a[j].end()) continue;
				for (int x : a[j]) occ2[x]++; 
			}
			if (occ2.size() < occ.size()) ans = max(ans, (int) occ2.size());
		}
		cout << ans << '\n';
		
	}
	return 0;
}
