#include <bits/stdc++.h>
using namespace std;

int t, h, w, xa, xb, ya, yb;

void solve() {
	cin >> h >> w >> xa >> xb >> ya >> yb;

	if (xa >= ya) { // alice is same row or row below bob
		cout << "DRAW\n";
		return;
	}

	int time = (ya - xa); // move in which alice will meet bob (or bob will meet alice)

	int alice_left = max(1, xb - (time + 1) / 2);
	int alice_right = min(w, xb + (time + 1) / 2);

	int bob_left = max(1, yb - time / 2);
	int bob_right = min(w, yb + time / 2);

	if (time % 2 == 1) { // alice's game to win
		if (alice_left <= bob_left && bob_right <= alice_right) {
			cout << "ALICE\n";
		} else {
			cout << "DRAW\n";
		}
	} else {
		if (bob_left <= alice_left && alice_right <= bob_right) {
			cout << "BOB\n";
		} else {
			cout << "DRAW\n";
		}
	}

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}