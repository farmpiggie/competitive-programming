/*
 * lets say a and b play, c is spectator
 *
 * lets say a wins game 1
 * game 1: a -> b
 * game 2: a -> c 
 * game 3: b -> c
 * game 4: a -> b
 * etc.
 *
 * lets say b wins game 1:
 * game 1: a -> b
 * game 2: b -> c
 * game 3: a -> c
 * game 4: a -> b
 * 
 * c is a spectator for game 1, 4, 7, etc.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		cout << (k % 3 == 1 ? "YES" : "NO") << '\n';
	}
}
