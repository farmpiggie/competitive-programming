#include <bits/stdc++.h>
using namespace std;

vector<string> ans[100];

void precompute() {
	ans[1] = {"1"};
	ans[3] = {"169", "196", "961"};
	for (int i = 5; i <= 99; i += 2) {
		for (string s : ans[i - 2]) {
			ans[i].push_back(s + "00");
		}

		string s2 = "1";
		for (int k = 0; k < (i - 3) / 2; k++) {
			s2 += "0";
		}
		s2 += "6";
		for (int k = 0; k < (i - 3) / 2; k++) {
			s2 += "0";
		}
		s2 += "9";
		ans[i].push_back(s2);

		s2 = "9";
		for (int k = 0; k < (i - 3) / 2; k++) {
			s2 += "0";
		}
		s2 += "6";
		for (int k = 0; k < (i - 3) / 2; k++) {
			s2 += "0";
		}
		s2 += "1";
		ans[i].push_back(s2);
	}
}

int t, n;

void solve() {
	cin >> n;
	for (string s : ans[n]) cout << s << '\n';
}

int main() {
	precompute();
	cin >> t;
	while (t--) solve();
	return 0;
}