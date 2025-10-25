#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// ifstream fin("843b.in");


void solve() {
	int n; cin >> n;
	unordered_map<int, int> mp;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int bit; cin >> bit;
			v.push_back(bit);
			if (mp.count(bit)) mp[bit]++;
			else mp[bit] = 1;
		}
		arr.push_back(v);
	}

	bool works = false;

	for (vector<int>& v : arr) {
		bool ret = true;
		for (int bit : v) {
			if (mp[bit] == 1) ret = false;
		}
		works |= ret;
	}
	if (works) cout << "Yes" << endl;
	else cout << "No" << endl;

}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}

}