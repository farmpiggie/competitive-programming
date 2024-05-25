// if all the stones are the same size, alice wins
// if there are two different size piles a < b, then alice removes (a - 1) stones, bob must remove one stone, alice removes the rest
// if there are three different size piles a < b < c, alice removes (a - 1) stones, forcing bob to remove 1 stone, then alice just wins
// but if the smallest pile has 1 stone, then alice must remove it, which puts bob in the winning state
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		set<int> s;
		for (int x : a) s.insert(x);
		int cur = 0;
		for (int x : s) {
			if (x == cur + 1) {
				cur++;
			} else {
				break;
			}
		}
		if ((int) s.size() - cur > 0) { // numbers remaining
			if (cur % 2 == 0) cout << "Alice\n";
			else cout << "Bob\n";
		} else { // no numbers remaining
			if (cur % 2 == 0) cout << "Bob\n";
			else cout << "Alice\n";
		}

	}
	return 0;
}
