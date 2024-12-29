#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x = n / 5, y = n % 5;
		vector<char> letters = {'a', 'e', 'i', 'o', 'u'};
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < x + (y > i); j++) {
				cout << letters[i];
			}
		}
		cout << '\n';
	}
	return 0;
}
