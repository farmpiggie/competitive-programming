#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(0);
#define help cin.tie(0);

void run() {
	int n; cin >> n;
	string c;

	int i = 0;
	for (int x = 1; x < n; x++) {
		cout << "? " << i << " " << i << " " << x << " " << x << '\n' << flush;
		cin >> c;
		if (c == "<") {
			i = x;
		}
	}

	int j = 0;
	for (int x = 1; x < n; x++) {
		cout << "? " << i << " " << j << " " << i << " " << x << '\n' << flush;
		cin >> c;

		if (c == "<") {
			j = x;
		} else if (c == "=") {
			cout << "? " << j << " " << j << " " << x << " " << x << '\n' << flush;
			cin >> c;
			if (c == ">") {
				j = x;
			}
		}
	}

	cout << "! " << i << " " << j << '\n';
}

int main() {
	// send help
	int t; cin >> t;
	while (t--) run();
}