#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, n, k, a;

void solve() {
	cin >> n >> k;
	int change_to_two = 2;
	int even = 0;
	int change_to_five = 5;
	int change_to_three = 3;
	int change_to_four = 4;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0) {
			change_to_two = 0;
			even++;
			if (even >= 2) change_to_four = 0;
		} else change_to_two = min(change_to_two, 2 - (a % 2));
		if (a % 3 == 0) change_to_three = 0;
		else change_to_three = min(change_to_three, 3 - (a % 3));
		if (a % 4 == 0) change_to_four = 0;
		else change_to_four = min(change_to_four, 4 - (a % 4));
		if (a % 5 == 0) change_to_five = 0;
		else change_to_five = min(change_to_five, 5 - (a % 5));
	}

	if (k == 2) {
		cout << change_to_two << '\n';
	} else if (k == 3) {
		cout << change_to_three << '\n';
	} else if (k == 4) {
		if (even >= 2) cout << 0 << '\n';
		else cout << min(change_to_four, 2 - even) << '\n';
	} else {
		cout << change_to_five << '\n';
	}


}

int main() {
	cin >> t;
	while (t--) solve();

}