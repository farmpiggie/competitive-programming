#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t, n;
string s;

void solve() {
	cin >> n >> s;
	string s2 = s;
	sort(s.begin(), s.end());
	swap(s, s2);

	char biggest = s2[n - 1]; // biggest char
	int num_biggest = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == biggest) num_biggest++;
	}
	// find all chars in the subsequence
	set<int> sequence;
	sequence.insert(n - 1); // last element is always part of largest sequence
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] >= s[*(sequence.begin())]) {
			sequence.insert(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] != s2[i] && sequence.find(i) == sequence.end()) {
			return cout << "-1\n", void();
		}
	}

	cout << (int) sequence.size() - num_biggest << '\n';

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}