/*
given:
- a permutation from 1 to n.
- for each i, you can choose to change a_i to 2 * n - a_i
solve: 
- find lowest # of inversions

hint 1: 
- inversions containing i if a_i = 1 are # of indices to the left of i.
- inversions containing i if a_i = 2 * n - 1 are # of indices to the right of i.
- so we can uniquely determine whether or not a_i = 1 should be flipped or not.

- can we then do this for 2, and then 3, and so on?
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		map<int, int> pos;
		for (int i = 0; i < n; i++) {
			pos[a[i]] = i;
		}
		int ans = 0;
		set<int> taken;
		for (int i = 1; i <= n; i++) {
			int x = pos[i];
			int flip = 0, not_flip = 0;
			for (int j = 0; j < x; j++) {
				if (a[j] > i && !taken.count(j)) flip++;
			}
			for (int j = x + 1; j < n; j++) {
				if (a[j] > i && !taken.count(j)) not_flip++;
			}
			ans += min(flip, not_flip);
			taken.insert(x);
		}
		cout << ans << '\n';
	}
}





       

