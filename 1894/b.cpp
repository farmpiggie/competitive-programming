#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int t, n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	map<int, vector<int>> mp; 
	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}

	int valid = 0;
	for (const pair<int, vector<int>>& p : mp) {
		if (p.second.size() >= 2) valid++;
	}

	if (valid < 2) 
		return cout << "-1\n", void();

	for (int i = 0; i < n; i++)
		b[i] = 1;

	int count = 0;
	for (const pair<int, vector<int>>& p : mp) {
		if (count == 2) break;
		if (p.second.size() < 2) continue;
		if (count == 0) {
			b[p.second[0]] = 1;
			for (int i = 1; i < (int) p.second.size(); i++)
				b[p.second[i]] = 2;
		} else if (count == 1) {
			b[p.second[0]] = 2;
			for (int i = 1; i < (int) p.second.size(); i++)
				b[p.second[i]] = 3;
		}
		count++;
	}

	for (int i = 0; i < n; i++) 
		cout << b[i] << " ";
	cout << '\n';



}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}