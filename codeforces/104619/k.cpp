#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < (int) s.length() - 3; i++) {
		if (s.substr(i, 4) == "kick") ans++;
	}
	cout << ans << '\n';
	return 0;
}
