// multiply all numbers together
// if answer is negative, we stay
// if answer is positive, make it zero by changing the first number to zero
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool zero = false;
		bool positive = true; 
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x == 0) zero = true;
			if (x < 0) positive = !positive;
		}
		if (zero) cout << "0\n";
		else if (positive) cout << "1\n1 0\n";
		else cout << "0\n";
	}
	return 0;
}
