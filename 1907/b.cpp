#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int t;
string s;

void solve() {
	cin >> s;
	int n = (int) s.length();
	vector<int> lower, upper, marked(n, 0);	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {
			marked[i] = 1;
			if (upper.size() > 0) {
				marked[upper.back()] = 1;
				upper.pop_back();
			}
		} else if (s[i] == 'b') {
			marked[i] = 1;
			if (lower.size() > 0) {
				marked[lower.back()] = 1;
				lower.pop_back();
			}
		} else if (islower(s[i])) {
			lower.push_back(i);
		} else {
			upper.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!marked[i]) {
			cout << s[i];
		}
	}
	cout << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}