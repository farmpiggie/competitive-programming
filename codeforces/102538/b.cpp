/*
 * given a tree, you can find maximal matching by greedily attempting to match children to their parents.
 * is it best to root the tree as the node with highest degree, and then subsequently lower nodes will have lower indegrees?
 *
 * answer cannot be larger than n / 2 (otherwise two edges will share same node)
 * also cant be larger than the # of non-leaves (otherwise a non-leaf will be shared in an edge), call this x
 *
 * can we always make a tree as min(n / 2, x)?
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x = 0;
		for (int i = 0; i < n; i++) {
			int d; cin >> d;
			if (d > 1) x++;
		}
		if (n == 2) cout << 1 << '\n';
		else cout << min(n / 2, x) << '\n';
	}
}

