#include <bits/stdc++.h>
using namespace std;

int ask(string s) {
	cout << "? " << s << '\n' << flush;
	int ret = 0; cin >> ret;
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s = "";
		int guesses = 0;

		// one guess, for one character
		if (!ask("1")) {
			for (int i = 0; i < n; i++) s += "0";
			cout << "! " << s << '\n' << flush;
			continue;
		}

		// for if we guess x characters to our string, it means we would have done
		// (x + 1) * 2 guesses for x characters
		// we now have a total of 2x + 3 guesses for x + 1 characters 
		s = "1";
		while (s.length() < n) {
			string pluszero = s + "0";
			string plusone = s + "1";
			if (ask(pluszero)) {
				s = pluszero;
			} else if (ask(plusone)) {
				s = plusone;
			} else {
				// doesn't match on either end
				break;
			}
		}

		// for the remaining (n - x - 1) characters, there will be (n - x - 2) * 2 + 1 guesses (last guess only takes one via process of elim)
		// total # of guesses will be: (2x + 3) + (n - x - 2) * 2 + 1
		// 2x + 3 + 2n - 2x - 4 + 1
		// 3 + 2n - 4 + 1
		// should be 2n guesses?
		while (s.length() < n) {
			string pluszero = "0" + s;
			string plusone = "1" + s;
			if (ask(pluszero)) {
				s = pluszero;
			} else {
				if (s.length() == n - 1 || ask(plusone)) { // dont ask if we are at n - 1
					s = plusone;
				} else {
					break;
				}
			}
		}
		cout << "! " << s << '\n' << flush;
	}
	return 0;
}