
// https://codeforces.com/contest/1890/problem/A
#include <bits/stdc++.h>
using namespace std;

string solve() {
	int n, a; cin >> n;
	unordered_map<int, int> mp;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mp[a]++;
		s.insert(a);
	}

	if (s.size() > 2) return "No";
	if (s.size() == 1) return "Yes";

	// only two numbers in the set
	int x = *s.begin(), y = *(++s.begin());
	if (abs(mp[x] - mp[y]) <= 1) return "Yes";
	else return "No";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}