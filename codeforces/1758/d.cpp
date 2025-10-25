#include <bits/stdc++.h>
using namespace std;
// can binary search if i know that sum i want
// how to determine this sum(?)
// binary search on sum, then binary search on min(??)
typedef long long ll;

/*
1. 1 -> 1
2. 1 3 -> 4
3. 3 6 7 -> 16 // 5 + 2 + 2 and 4 + 4 + 1 do not work
4. 2 3 5 6 -> 16


*/

int main() {
	// ifstream cin("rangesum.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 2 == 0) { // n even numbers, we can do 
			for (int i = n / 2; i <= 3 * n / 2; i++) {
				if (i == n) continue;
				cout << i << " ";
			}
			cout << endl;
		} else {
			vector<int> ans;
			for (int i = 0; i < n; i++) {
				ans.push_back(i + (n / 2 + 1) + 2);
			}
			ans[0]--;
			ans[n - 1]++;
			ans[n - 2]++;
			for (int i = 0; i <n; i++) cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}