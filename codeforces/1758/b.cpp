#include <bits/stdc++.h>
using namespace std;
// XOR: 1 + 0 = 1, 0 + 1 = 1, 1 + 1 = 0, 0 + 0 = 1
// XOR a number with itself = 0
// XOR powers of 2 = sums of powers of 2
// XOR a number n times = average
// multiplying by any number 
int main() {
	// ifstream cin("xoraverage.in");
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		// we can just do sum of the same number n times
		if (x % 2 == 1) {
			for (int i = 0; i < x; i++) cout << 1 << " ";
			cout << endl;
		} else { // value = 0?
			// choose a number to be the average(?)
			// choose numbers around it to XOR
			// we can XOR in whatever order we want
			cout << 1 << " " << 3 << " ";
			for (int i = 0; i < x - 2; i++) {
				cout << 2 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}