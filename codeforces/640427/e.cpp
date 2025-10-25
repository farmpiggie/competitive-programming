#include <bits/stdc++.h>
using namespace std;

int main() {
	set<char> mirror = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	bool works = true;
	for (char c : s) if (mirror.find(c) == mirror.end()) works = false;
	string s2 = s;
	reverse(s.begin(), s.end());
	if (s != s2) works = false;
	cout << (works ? s : "INVALID") << '\n';
}

