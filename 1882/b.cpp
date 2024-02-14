#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<unordered_set<int>> sets;
	unordered_map<int, int> mp;

	int best = 0;

	for (int i = 0; i < n; i++) {
		int size; cin >> size;
		unordered_set<int> tempSet;
		for (int j = 0; j < size; j++) {
			int k; cin >> k;
			tempSet.insert(k);
			mp[k]++;
		}
		sets.push_back(tempSet);
	}
	int currMax = mp.size();

	for (int i = 0; i < n; i++) {
		for (int element : sets[i]) {
			mp[element]--;
			if (mp[element] == 0) mp.erase(element);
		}
		if (mp.size() != currMax)
			best = max(best, (int) mp.size());
		for (int element : sets[i]) {
			mp[element]++;
		}
	}
	cout << best << endl;

}


int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}