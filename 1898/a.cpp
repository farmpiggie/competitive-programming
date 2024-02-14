#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve() {
	cin >> n >> k;
	string s; cin >> s;

	int num_b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') num_b++;
	}

	if (num_b == k) return cout << "0\n", void();

	if (num_b > k) { 
		int diff = num_b - k;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') diff--;
			if (diff == 0) 
				return cout << "1\n" << (i + 1) << " A\n", void();
		}
	} else {
		int diff = k - num_b;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') diff--;
			if (diff == 0) 
				return cout << "1\n" << (i + 1) << " B\n", void();
		}
	}
}



int main() {
	cin >> t;
	while (t--) solve();
}