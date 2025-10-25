#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	// ifstream cin("seeingdouble.in");
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string ans = "";
		unordered_map<char, int> mp;
		for (char c : s) {
			if (mp.find(c) == mp.end()) mp[c] = 2;
			else mp[c] += 2;
		}
		for (pair<char, int> p : mp) {
			string temp = "";
			for (int i = 0; i < p.second / 2; i++) {
				temp += p.first;
			}
			ans = temp + ans + temp;
		}
		cout << ans << endl;
	}
	return 0;
}