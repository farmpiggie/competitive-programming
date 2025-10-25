#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t; cin >> s >> t;
	int start = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
	int end = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
	vector<int> times = {0, 1 * 60 + 10, 2 * 60 + 20, 3 * 60 + 30, 4 * 60 + 40, 5 * 60 + 50, 10 * 60 + 1, 11 * 60 + 11, 12 * 60 + 21, 13 * 60 + 31, 14 * 60 + 41, 15 * 60 + 51, 20 * 60 + 02, 21 * 60 + 12, 22 * 60 + 22, 23 * 60 + 32};
	int ans = 0;
	for (int time : times) {
		if (start <= time && time <= end) ans++;
	}
	cout << ans << '\n';



	
}
